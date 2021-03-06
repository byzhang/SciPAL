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



# rules for host part
# Remove any QT-dependency
# QT =
# Due to QThread we need at least
# QT = core
# thread-safe console application with rules for debug and release version



CONFIG += console \
    thread \
    debug_and_release# \
    #qt

# The following keeps the compiler from messing up the different signals&slots implementations from QT and boost.
CONFIG += no_keywords

# For the time being we have to disable the usage of the CUDATimer class on Mac OSX as it leads to linker errors.
# This also shows how to configure different compilation behaviors on different OSes.
    macx {
         DEFINES += DONT_USE_CUDATIMER
           }
    else {
        unix {

        }
    }
    win32 {

    }

# the following disables the complex number type provided by CUDA.
DEFINES += nUSE_CUDA_COMPLEX_VERSION

    HOME = $$(HOME) # your home directory
    SciPAL_DIR = $$_PRO_FILE_PWD_/../../
    STEP_PARENT_DIR = $$_PRO_FILE_PWD_/../

message("SciPALs home :" $$SciPAL_DIR)
message("step home :" $$STEP_DIR)

# Qt considers OSX as a unix.
    macx {
         DEALHOME = /usr/local #
           }
    else {
        unix {
         DEALHOME = /usr/local/deal.II-7.2.0 # path to deal II in NAM
        }
    }


     #put here some non standard header includes for cuda
     # which are specific to your project.
     # This has to be done before the generic part of the configuration is added.
     # -I. is needed if you compiled within your source directory.
     # The argument -I../../.. is needed to go from the shadow-build directory
     # to the source directory of your project and assumes that the shadow build has three levels, e.g.
     #
     # build-step-2/Debug/Desktop_Qt_5_2_1_clang64/
     #
        CUDA_INCLUDES = -I$$STEP_PARENT_DIR


        CUDA_INCLUDES +=-I$$SciPAL_DIR/include


    # and here for the gcc
INCLUDEPATH += ..

#put here your non-standard libs
LIBS +=

   # The PRAK variable is used inside scipal_conf.pro.
   # This file provides a basic configuration for compiling
   # a cuda project which depends on CUDA, deal.II and SciPAL.
   # It defines the rules for compiling the CUDA part. In this definition
   # the variable CUDA_INCLUDES is evaluated. Therefore, we have to add project-specific
   # includes BEFORE we include the general configuration.
include($$SciPAL_DIR/config/scipal_conf.pro)

# Depending an what is needed from deal.II we either have to include a full MPI-capable installation or the quick-and-easy default version
# which only provides mltithreading for shared memory machines.
    macx {
message("Load deal.II simple config")
         include($$SciPAL_DIR/config/dealii_simple_conf.pro) #
           }
    else {
        unix {
message("Load deal.II MPI config")
         include($$SciPAL_DIR/config/dealii_mpi_conf.pro)
        }
    }

# Enter project specific source and header files here
SOURCES = \
    cuda_kernel_step-template.cu step-template.cpp \
    SimParams.cpp

HEADERS = \
    cuda_driver_step-template.h \
    cuda_driver_step-template.hh \
    cuda_kernel_wrapper_step-template.cu.h \
    cuda_kernel_step-template.cu.c \
    SimParams.h \
    step-template.hh

   # the following variable contains files which should appear in the Projects view on the left of QtCreator
   # which are not subject to compilation.
OTHER_FILES = doxygen_filelist \
                doc/*.dox \
                prm/*.prm

