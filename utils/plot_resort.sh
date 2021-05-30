#!/bin/bash

# Run after new plots are generated
#	Purpose:
#       Moves the plots with the highest number and a cut that's not currently in the plots/####/ folder
#       This needs to be run otherwise the only plots that will get included in the plots.pdf file will
#       be the 3 plots with the most recent cut applied, not all of the most recent ones
#
#	Usage:
#		./plot_resort.sh "year"

if [[ $1 == 2016 || $1 == 2017 || $1 == 2018 || $1 == old ]]; then

	echo "Starting plot sort"
	for file in plots/$1/*.pdf; do
		cut=$(echo $file | sed 's|^.*\([0-9]\{4\}_\)||g' | sed 's|.pdf||g') # 'cut' pulls out the end of the file name which corresponds to the cutName used
		canvas=$(echo $file | sed 's|_\([0-9]\{4\}\).*$||g' | sed 's|^.*\([0-9]\{4\}/\)||g') # canvas c1, c2, or c3
		current=$(find plots/$1/archive/*$cut*.pdf | grep $canvas | sed "s|^.*\($cut\)||g" | sed 's|.pdf||g' | sort -rn | head -n 1) # Current highest number for the plots using the same cut
		#new=$((current+1)) # Increment the 'current' highest number on a plot for the new ones
        mv 
		newFile=$(echo $file | sed "s|.pdf|$new.pdf|g" | sed "s|plots/$1/||g") # rename the plot with the new number appended to the end
		mv $file plots/$1/archive/$newFile # move the file to the appropriate archive folder
	done

	echo "Done sorting .pdf's, next is .png's"

	for file in plots/$1/*.png; do
        cut=$(echo $file | sed 's|^.*\([0-9]\{4\}_\)||g' | sed 's|.png||g')
        canvas=$(echo $file | sed 's|_\([0-9]\{4\}\).*$||g' | sed 's|^.*\([0-9]\{4\}/\)||g')
        current=$(find plots/$1/archive/*$cut*.png | grep $canvas | sed "s|^.*\($cut\)||g" | sed 's|.png||g' | sort -rn | head -n 1)
        #new=$((current+1))
        newFile=$(echo $file | sed "s|.png|$new.png|g" | sed "s|plots/$1/||g")
        mv $file plots/$1/archive/$newFile
        done
else	
	echo "I'm terribly confused, please check the plot_sort.sh script"
fi
