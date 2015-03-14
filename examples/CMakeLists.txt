include_directories(.)

cuda_add_executable(
  benchmark
  benchmark_scipal.cu
  benchmark.cpp
)
CUDA_ADD_CUBLAS_TO_TARGET(benchmark)

target_link_libraries(benchmark Qt4::QtCore deal_II ${OPENBLAS_LIBRARY} ${CUDA_curand_LIBRARY})
