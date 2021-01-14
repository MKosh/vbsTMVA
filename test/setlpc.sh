#!/bin/bash
export ROOTSYS="/uscms_data/d1/lpchzz4leptons/contrib/root/root_v6.10.08-gcc4.8-x64-cuda9.1-sl7"
export ROOT_DIR=$ROOTSYS
export PATH=$ROOTSYS/bin:$PATH
export LD_LIBRARY_PATH=$ROOTSYS/lib:$LD_LIBRARY_PATH
export LIBRARY_PATH=$ROOTSYS/lib:$LIBRARY_PATH
export PYTHONPATH=$ROOTSYS/lib:$PYTHONPATH
export CPATH=$ROOTSYS/include:$CPATH
#cuda
#export CUDA_ROOT="/uscms_data/d1/lpchzz4leptons/archive/cuda/7.5"
export CUDA_ROOT="/usr/local/cuda-9.1"
export CUDA_INSTALL_PATH=$CUDA_ROOT
export CUBLAS_INSTALL_PATH=$CUDA_ROOT
export CUBLAS_LIBRARIES=$CUDA_ROOT/lib64 
export CUBLAS_INCLUDES=$CUDA_ROOT/include
export PATH=$CUDA_ROOT/bin:$PATH
export LD_LIBRARY_PATH=$CUDA_ROOT/lib64:$LD_LIBRARY_PATH
#local_libs
export HZZ_LOCAL_LIBS="/uscms_data/d1/lpchzz4leptons/contrib/lib64"
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HZZ_LOCAL_LIBS
#


