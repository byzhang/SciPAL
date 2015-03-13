include_directories(.)

cuda_add_executable(
  benchmark
  ../src/cuda/scipal_kernels.cu
  benchmark.cpp
)
CUDA_ADD_CUBLAS_TO_TARGET(benchmark)

target_link_libraries(benchmark Qt4::QtCore deal_II ${OPENBLAS_LIBRARY})
