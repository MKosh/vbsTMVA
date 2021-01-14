#!/bin/bash
if [ "0$ROOTSYS"  == "0" ]; then module load root/root-6.10.08-SL7-x64-cuda-7.5  ; fi
#suv if [ ! -L data ]; then ln -s /work/cmsdata/vbs_reduced_2016/vbs_ww data; fi
if [ ! -L data ]; then ln -s /cdata/cms/archive/vbs_reduced_2016/vbs_ww  data; fi
if [ ! -d OutDir ]; then /bin/mkdir -p OutDir; fi
#
