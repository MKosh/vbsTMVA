#!/bin/bash

# 	Used to write the .tex file containing all of the plots. Run after new plots get generated.
# Purpose:
#       Reads the contents of the plots/####/ folders and adds an \includegraphics 
#       command and a caption for each plot found

if [[ $1 == 2016 || $1 == 2017 || $1 == 2018 || $1 == old ]]; then

    for file in plots/$1/*.pdf; do
		cut=$(echo $file | sed 's|^.*\([0-9]\{4\}_\)||g' | sed 's|.pdf||g') # 'cut' pulls out the end of the file name which corresponds to the cutName used
        yr_count=$(cat docs/plots.tex | grep "section\*{$1}" | wc -l)
        for iter in {1..3}; do
            graphics_count=$(cat docs/plots.tex | grep includegraphics{$1/c$iter\_$1\_$cut.pdf} | wc -l)
            if [ graphics_count == 0]; then
                
        echo "file = $file"
    done
else
    echo "gen_plot.sh - ERROR - Year selection incorrect. Select from: 0000, 2016, 2017, 2018"
fi