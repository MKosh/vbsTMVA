#!/bin/tcsh 
./dsw.sh
set SNAME=`(uname -a )`
set atFNAL=`(echo  $SNAME | grep fnal)`
#
if ( ! ($?ROOTSYS) ) then
#setting root
if ( "0$atFNAL" != "0" ) then
#ROOT with cuda compled at cmslpcgpu1
setenv SUREPO "/uscms/home/serguei/lpchzz4leptons/serguei/contrib"
setenv ROOT_DIR $SUREPO//root/root_v6.10.08-gcc4.8-x64-cuda9.0-cmslpc-sl7
setenv ROOTSYS $SUREPO/root/root_v6.10.08-gcc4.8-x64-cuda9.0-cmslpc-sl7
setenv CPATH $ROOTSYS/include:$CPATH
setenv LD_LIBRARY_PATH $ROOTSYS/lib64:${LD_LIBRARY_PATH}
setenv LIBRARY_PATH $ROOTSYS/lib:${LIBRARY_PATH}
setenv PATH $ROOTSYS/bin:${PATH}
else
#change for favorit root
 module load root/root-6.10.08-SL7-x64-cvmfs
endif

endif
echo "done dsw"
#
