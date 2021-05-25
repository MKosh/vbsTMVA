#!/bin/bash
if [[ $1 == 2016 || $1 == 2017 || $1 == 2018 || $1 == old ]]; then

	echo "Starting plot sort"
	for file in ../plots/$1/*.pdf; do
		end=$(echo $file | sed 's|^.*\([0-9]\{4\}_\)||g' | sed 's|.pdf||g')
		canvas=$(echo $file | sed 's|_\([0-9]\{4\}\).*$||g' | sed 's|^.*\([0-9]\{4\}/\)||g')
		current=$(find ../plots/$1/archive/*$end*.pdf | grep $canvas | sed "s|^.*\($end\)||g" | sed 's|.pdf||g' | sort -rn | head -n 1)
		new=$((current+1))
		newFile=$(echo $file | sed "s|.pdf|$new.pdf|g" | sed "s|../plots/$1/||g")
		mv $file ../plots/$1/archive/$newFile
	done

	echo "Done sorting .pdf's, next is .png's"

	for file in ../plots/$1/*.png; do
                end=$(echo $file | sed 's|^.*\([0-9]\{4\}_\)||g' | sed 's|.pdf||g')
                canvas=$(echo $file | sed 's|_\([0-9]\{4\}\).*$||g' | sed 's|^.*\([0-9]\{4\}/\)||g')
                current=$(find ../plots/$1/archive/*$end*.pdf | grep $canvas | sed "s|^.*\($end\)||g" | sed 's|.pdf||g' | sort -rn | head -n 1)
                new=$((current+1))
                newFile=$(echo $file | sed "s|.pdf|$new.pdf|g" | sed "s|../plots/$1/||g")
                mv $file ../plots/$1/archive/$newFile
        done
else	
	echo "I'm terribly confused, please check the plot_sort.sh script"
fi
