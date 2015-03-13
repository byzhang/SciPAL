// @sect3{Class: GPUInfo}
//
// This an auxiliary structure which collects data related to the GPUs
// available in the computer on which this program gets executed.
// For details about the cuda<something> functions have a look at
// the CUDA reference manual.
#include "benchmark_scipal.h"

struct GPUInfo {

  int n_CUDA_devices;

  int current_device_id;

  cudaDeviceProp prop;

  GPUInfo(int DevNo) : current_device_id(DevNo) {
  }

  // @sect4{Function: get}
  //
  // this function must be called to retrieve the
  // GPU-related information.
  void get() {
    static const int KB = 1024;
    static const int MB = KB*KB;

    // At the beginning we figure out
    // how many CUDA devices are available.
    cudaGetDeviceCount(&n_CUDA_devices);
    std::cout << "N available CUDA devices : " <<  n_CUDA_devices << std::endl;

    // Retrieve information about the currently selected GPU.
    std::cout << "current device ID : " << this->current_device_id << std::endl;

    cudaGetDeviceProperties(&prop, this->current_device_id);

    printf("Currently used GPU: %s \n",prop.name);
    printf("Compute Capability: %d.%d \n",prop.major,prop.minor);
    printf("ClockRate: %uMHz \n",prop.clockRate/1000);
    printf("Warpsize: %d \n",prop.warpSize);
    printf("Number of Multiprocessors: %d \n",prop.multiProcessorCount);

    printf("Shared Memory: %luKB\n",prop.sharedMemPerBlock/KB);
    printf("Constant Memory: %luKB \n",prop.totalConstMem/KB);
    printf("Global Memory: %luMB \n",prop.totalGlobalMem/MB);
    printf("the device %s concurrently copy memory between host and device while executing a kernel\n",
           (prop.deviceOverlap? "can": "cannot"));
  }

  // To keep the compiler from automatically generating
  // a copy constructor and an assignment operator we provide
  // dummy implementations and declare them as private.
  // In case one of them is needed the compiler will complain at compile-time
  // and one can think about whether they are really needed, i.e. one has to
  // review one's software design.
 private:
  GPUInfo (const GPUInfo & /*other*/) {}

  GPUInfo & operator = (const GPUInfo & /*other*/) {
    return *this;
  }

};

// @sect3{Function: main}
//
// As usual, the main function is pretty boring.
int main(int argc, char *argv[]) {
  // This command is used to set the GPU on which we want to run our computations.
  // For a list of GPUs execute nvidia-smi.
  int DevNo = 0;
  GPUInfo gpu_info(DevNo);

  // Before we can benchmark SciPAL we have to get the GPU info.
  gpu_info.get();

  CUDADriver<double> double_drive;
  double_drive.transh(128, 128);

  return 0;
}
