#!/bin/bash

# Run after new plots are generated
#	Purpose:
#       Moves the plots with the highest number and a cut that's not currently in the plots/####/ folder
#       This needs to be run otherwise the only plots that will get included in the plots.pdf file will
#       be the 3 plots with the most recent cut applied, not all of the most recent ones
#
#	Usage:
#		./plot_resort.sh "year"

if [[ $1 == 2016 || $1 == 2017 || $1 == 2018 || $1 == 0000 ]]; then

	echo "Starting plot re-sort"
	pdfs=()
	pngs=()
	for file in plots/$1/archive/c1_$1_*.pdf; do
		cut=$(echo $file | sed 's|^.*\([0-9]\{4\}_\)||g' | sed 's|[0-9]\+.pdf||g') # 'cut' pulls out the end of the file name which corresponds to the cutName used
		if [[ ! "${pdfs[@]}" =~ "$cut" ]]; then
			pdfs+=("$cut")
		fi
	done
	
	for cuts in ${pdfs[@]}; do
		current=$(find plots/$1/archive/c1_$1_$cuts*.pdf | sed "s|^.*\($cuts\)||g" | sed 's|.pdf||g' | sort -rn | head -n 1) # Current highest number for the plots using the same cut
		plot_count=$(find plots/$1/c1_$1_$cuts.pdf | wc -l) # Check if the plots/####/ folder has a plot with that particular cut (0 if no, 1 if yes, shouldn't be any other number)
		if [[ $plot_count == "0" ]]; then
			#echo "cut = $cuts"
			#echo "plot_count = $plot_count"
			#echo "current = $current"
			mv plots/$1/archive/c1_$1_$cuts$current.pdf plots/$1/c1_$1_$cuts.pdf
			mv plots/$1/archive/c2_$1_$cuts$current.pdf plots/$1/c2_$1_$cuts.pdf
			mv plots/$1/archive/c3_$1_$cuts$current.pdf plots/$1/c3_$1_$cuts.pdf
			mv plots/$1/archive/c4_$1_$cuts$current.pdf plots/$1/c4_$1_$cuts.pdf
		elif [[ $plot_count == "1" ]]; then
			echo ".pdf plots with cut: $cuts already exist in the plots/$1 folder, skipping these."
		else
			echo "Somehow I counted more than one .pdf per cut type, plot_sort.sh should have fixed that"
		fi
	done

	echo "Done sorting .pdf's, next is .png's"

#	for cuts in ${pngs[@]}; do
#		current=$(find plots/$1/archive/c1_$1_$cuts*.png | sed "s|^.*\($cuts\)||g" | sed 's|.png||g' | sort -rn | head -n 1) # Current highest number for the plots using the same cut
#		plot_count=$(find plots/$1/c1_$1_$cuts.png | wc -l) # Check if the plots/####/ folder has a plot with that particular cut (0 if no, 1 if yes, shouldn't be any other number)
#		if [[ $plot_count == "0" ]]; then
#			#echo "cut = $cuts"
#			#echo "plot_count = $plot_count"
#			#echo "current = $current"
#			mv plots/$1/archive/c1_$1_$cuts$current.png plots/$1/c1_$1_$cuts.png
#			mv plots/$1/archive/c2_$1_$cuts$current.png plots/$1/c2_$1_$cuts.png
#			mv plots/$1/archive/c3_$1_$cuts$current.png plots/$1/c3_$1_$cuts.png
#		elif [[ $plot_count == "1" ]]; then
#			echo ".png plots with cut: $cuts already exist in the plots/$1 folder, skipping these."
#		else
#			echo "Somehow I counted more than one .png per cut type, plot_sort.sh should have fixed that"
#		fi
#	done
#
fi
