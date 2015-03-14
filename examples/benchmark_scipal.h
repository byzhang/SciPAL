#ifndef SCIPAL_BENCHMARK_SCIPAL_H__
#define SCIPAL_BENCHMARK_SCIPAL_H__

#include <chrono>
#include <iostream>
#include <string>

#include "base/CudaComplex.h"
#include "lac/blas++.h"
#include "lac/development/cublas_Matrix.h"
#include "lac/development/cublas_Vector.h"
#include "lac/release/blas_wrapper.hh"
#include "lac/release/cublas_wrapper.hh"
#include "numerics/RNDwrapper.h"

#include <cuda_runtime_api.h>

typedef std::chrono::high_resolution_clock timer_clock;
typedef std::chrono::milliseconds milliseconds;
typedef std::chrono::microseconds microseconds;
using namespace SciPAL;
using namespace std;

std::string clean_duration(std::string value) {
  while(value.size() > 1 && value.back() == '0') {
    value.pop_back();
  }

  return value;
}

std::string duration_str(std::size_t duration_us) {
  if(duration_us > 1000 * 1000) {
    return clean_duration(std::to_string(duration_us / 1000.0 / 1000.0)) + "s";
  } else if(duration_us > 1000) {
    return clean_duration(std::to_string(duration_us / 1000.0)) + "ms";
  } else {
    return clean_duration(std::to_string(duration_us)) + "us";
  }
}

template <typename N>
class CUDADriver {
 private:
  typedef N Number;
  typedef SciPAL::CudaComplex<Number> cplxNumber;
  typedef cublas BW;

 public:
  CUDADriver() {
    BW::Init();
  }
  ~CUDADriver() {
    BW::Shutdown();
  }

  // compute the loss function ||(hi - w'hiw) + d - (ti - w'tiw)||
  // and the gradient on hi, ti, w, and d
  void transh(int dim, int num_data) {
    auto start_time = timer_clock::now();
    CUDARND<Number, cpu> cpu_rnd(0);
    CUDARND<Number, gpu_cuda> rnd(0);
    // create num_data of random vectors h and t in host
    std::vector<Vector<Number, blas>> hs(num_data, Vector<Number, blas>(num_data));
    std::vector<Vector<Number, blas>> ts(num_data, Vector<Number, blas>(num_data));
    for (auto& h : hs) {
      cpu_rnd(h);
    }
    for (auto& t : ts) {
      cpu_rnd(t);
    }
    // create the random vectors w and d in device
    SciPAL::Vector<Number, BW> w(dim), d(dim);
    rnd(w);
    rnd(d);
    // create the zero vectors dh, dw, dd, l, avg_l in device
    SciPAL::Vector<Number, BW> dw(dim), dd(dim), dh(dim), l(dim), avg_l(dim);
    dw = dd = dh = l = avg_l = 0;
    // create the tmp vectors h1, h2, t1, t2 in device
    SciPAL::Vector<Number, BW> h1(dim), h2(dim), t1(dim), t2(dim);
    auto end_time = timer_clock::now();
    auto duration = std::chrono::duration_cast<microseconds>(end_time - start_time);
    std::cout << "Initialization took " << duration_str(duration.count()) << std::endl;

    start_time = timer_clock::now();
    h1 = hs[0];
    t1 = ts[0];
    // create pointer h and t, switching between h1, h2, t1, t2;
    SciPAL::Vector<Number, BW> *h, *t;
    bool first_tmp = true;
    // loop
    for (int i = 1; i < num_data; ++i) {
      // initiate h and t, and copy to another set of h/s
      if (first_tmp) {
        // wait for h1 and t1 copy done if async
        h = &h1;
        t = &t1;
        h2 = hs[i];  // better to be async
        t2 = ts[i];  // better to be async
      } else {
        // wait for h2 and t2 copy done if async
        h = &h2;
        t = &t2;
        h1 = hs[i];  // better to be async
        t1 = ts[i];  // better to be async
      }
      first_tmp = !first_tmp;
      // compute l
      l = *h - w.dot(*h) * w + d - (*t - w.dot(*h) * w);
      avg_l += l;
      // update gradients
      dd = dd + 2.0 * l;
      dh = dh + 2.0 * l - 2.0 * l * w * w;
      dw = dw + 2.0 * l * w * (*t - *h);
    }
    // for the last data
    // compute l
    l = *h - w.dot(*h) * w + d - (*t - w.dot(*h) * w);
    avg_l += l;
    // update gradients
    dd = dd + 2.0 * l;
    dh = dh + 2.0 * l - 2.0 * l * w * w;
    dw = dw + 2.0 * l * w * (*t - *h);
    // average
    avg_l /= num_data;
    dd /= num_data;
    dh /= num_data;
    dw /= num_data;
    // create result vectors in host
    std::vector<Number> r_l(dim), r_dd(dim), r_dh(dim), r_dw(dim);
    avg_l.push_to(r_l);
    dd.push_to(r_dd);
    dh.push_to(r_dh);
    dw.push_to(r_dw);
    end_time = timer_clock::now();
    duration = std::chrono::duration_cast<microseconds>(end_time - start_time);
    std::cout << "Computation and IO took " << duration_str(duration.count()) << std::endl;
  }
};

#endif
