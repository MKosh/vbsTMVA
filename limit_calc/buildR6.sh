#!/bin/bash
if [ "0$ROOTSYS" == "0" ]; then
  echo "Please setup ROOT v6.xx"
return 0;
fi
/bin/rm -rf r6_limit_calc
g++ -I$ROOTSYS/include `root-config --cflags` -o r6_limit_calc limit_calc.C CL95_ROOTv6.C Significance.C  `root-config --libs`
#
