#!/bin/bash
/bin/rm -rf ./limit_calc
echo g++ -I$ROOTSYS/include `root-config --cflags` -o limit_calc limit_calc.C CL95.C Significance.C  `root-config --libs` -ltbb
g++ -I$ROOTSYS/include `root-config --cflags` -o limit_calc limit_calc.C CL95.C Significance.C  `root-config --libs` -ltbb
#
