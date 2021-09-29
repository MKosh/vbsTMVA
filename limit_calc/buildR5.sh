#!/bin/bash
if [ "0$ROOTSYS" == "0" ]; then
  echo "Please setup ROOT v5.xx"
return 0;
fi
/bin/rm -rf r5_limit_calc
g++ -I$ROOTSYS/include `root-config --cflags` -o r5_limit_calc limit_calc.C CL95_ROOTv5.C Significance.C  `root-config --libs`
#
