#This file is part of SciPAL.

#    SciPAL is free software: you can redistribute it and/or modify
#    it under the terms of the GNU Lesser General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.

#    SciPAL is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU Lesser General Public License for more details.

#    You should have received a copy of the GNU Lesser General Public License
#    along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.

#Copyright  S. C. Kramer , J. Hagemann  2010 - 2014

# helper file for cleaning up the qmake config
# this files contains standard libs / includs and compiler config
# !--->>the PRAK variable used inside this file must be defined in the pro file which
# !--->>includes cuda.qmake

# Eliminate the QT-config for c-files
#MACOSX_DEPLOYMENT_TARGET =10.9

QMAKE_MAC_SDK=macosx10.9

QMAKE_CFLAGS =
QMAKE_CFLAGS_DEBUG =

QMAKE_CFLAGS_X86 =
QMAKE_CFLAGS_X86_64 =
QMAKE_CFLAGS_DWARF2 =
QMAKE_CFLAGS_DEPS =
QMAKE_CFLAGS_WARN_ON =
QMAKE_CFLAGS_WARN_OFF =
QMAKE_CFLAGS_RELEASE =
QMAKE_CFLAGS_DEBUG =
QMAKE_CFLAGS_SHLIB =
QMAKE_CFLAGS_STATIC_LIB =
QMAKE_CFLAGS_YACC =
QMAKE_CFLAGS_HIDESYMS =
QMAKE_CFLAGS_PRECOMPILE =
QMAKE_CFLAGS_USE_PRECOMPILE =
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.9

    macx {
    }
    else {
QMAKE_CXXFLAGS += -fopenmp
QMAKE_LDFLAGS += -fopenmp
}

# CUDA path
CUDA_DIR = /usr/local/cuda
#-5.5
CUDA_CC = $$CUDA_DIR/bin/nvcc


# if nvcc was on the path its homedir could be found in a similar way
CXX_HOME_DIR = $$system(which g++ | sed 's,g++$,,')
message("g++ resides in :" $$CXX_HOME_DIR)
message("PATH :" $$(PATH))
message("nvcc resides in :" $$CUDA_CC)

#the compilation process is divided in two steps:
# first we compile the CUDA part with nvcc
# then we compile the host part of the programm with gcc. This is necessary because nvcc doesn´t \
# understand some compiler intrinsic commands which could be used in some libaries e.g. deal.II

#Take care of the CUDA stuff

CUDA_INCLUDES += -I$$CUDA_DIR/include

# Actually, these are the nvcc flags
CUDA_CFLAGS = -arch sm_35 -G\ #cuda debugging
             -ccbin $${QMAKE_CXX} # /usr/bin/clang++

    macx {
CUDA_CFLAGS += --compiler-options -fPIC,-stdlib=libstdc++,-DDONT_USE_CUDATIMER
    }
    else {
        unix {
# Thanks to clang there is no OpenMP on OSX. Thus we add it only or Unix/Linux.
CUDA_CFLAGS += --compiler-options -fPIC,-fopenmp
        }
    }

CUDA_CFLAGS += --ptxas-options=-v # some information about the compiled kernels
            #-prec-sqrt=true \
            #-prec-div=true
            #--maxrregcount=28
            #-use_fast_math \
CUDA_INCLUDES += -I$$CUDA_DIR/sdk/shared/inc \
                 -I$$CUDA_DIR/include \
                 -I$$CUDA_DIR/samples/common/inc/ \
                 -I$$CUDA_DIR/sdk/CUDALibraries/common/inc/ \
                 -I$$SciPAL_DIR/include \
                 -I$$SciPAL_DIR/
#                 -I$$DEALHOME/include

#now for the host
#these are the includes seen by the gcc

#for CUDA
INCLUDEPATH += $$CUDA_DIR/sdk/C/common/inc \
            $$CUDA_DIR/sdk/shared/inc/ \
            $$CUDA_DIR/samples/common/inc/ \
            $$CUDA_DIR/sdk/CUDALibraries/common/inc/ \
            $$CUDA_DIR/include \
            $$SciPAL_DIR/include \ #SciPal include also on the host side
            $$SciPAL_DIR



#here come the Libs to link against.
# Strange errors like "skipping incompatible /usr/local/cuda/lib/libcudart.so when searching for -lcudart"
# may be due to 32/64bit compilation issues.
    macx {
QMAKE_LIBDIR += $$CUDA_DIR/lib
    }
    else {
        unix {
QMAKE_LIBDIR += $$CUDA_DIR/lib64
        }
    }

#CUDA, threading and fft libs
LIBS += -L$$QMAKE_LIBDIR \
        -lcudart \
        -lcublas \
        -lcufft \
        -lcurand \
-L/usr/lib

# DO NOT REMOVE the BRACES!!!
    macx {
    }
    else {
        unix {
LIBS += -lgomp
        }
    }


LIBS += -lpthread  #\
#-L$$PRAK/fftw/lib \
#        -lfftw3_omp \
#        -lfftw3 \
#        -lfftw3f_omp \
#        -lfftw3f

# blas, lapack
# these are listed in the deal.II_mpi_conf.pro
#LIBS += -lblas -llapack -lz -ldl




#some standard headers for SciPAL
HEADERS += $$SciPAL_DIR/include/lac/*.h* \
           $$SciPAL_DIR/include/lac/release/* \
           $$SciPAL_DIR/include/lac/development/* \
           $$SciPAL_DIR/include/base/* \
           $$SciPAL_DIR/include/numerics/* \

#compiler config
# have plain c-files compiled by g++
QMAKE_EXT_CXX += .c

# consider cu-files as ordinary c-files ...
QMAKE_EXT_C = .cu

# and define NVidia's cuda-compiler as C-compiler
QMAKE_CC = $$CUDA_CC

# We do not want to qmake to compile .cu files with QT-support.
# Thus, we have to set the compilation rules by ourselves.
QMAKE_RUN_CC = $(CC) \
    -m64 -c \
    $$MY_QMAKE_CFLAGS \
    $$CUDA_CFLAGS \
    $$CUDA_INCLUDES \
    -o \
    $obj \
    $src
QMAKE_RUN_CC_IMP = $(CC) \
    -m64 -c \
    $$MY_QMAKE_CFLAGS \
    $$CUDA_CFLAGS \
    $$CUDA_INCLUDES \
    -o \
    "$@" \
    "$<"

CONFIG(debug, debug|release) {
    QMAKE_PRE_LINK = "$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)" 2>&1 |\
    python $$SciPAL_DIR/scripts/createInst.py Debug >> $$_PRO_FILE_PWD_/autoInstantiations.h;
}

CONFIG(release, debug|release) {
    QMAKE_PRE_LINK = "$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)" 2>&1 |\
    python $$SciPAL_DIR/scripts/createInst.py Release >> $$_PRO_FILE_PWD_/autoInstantiations.h;
}

TEMPLATE =




