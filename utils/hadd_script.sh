#!/bin/bash

# arg 1 = input file locations # somthing like "2017"
# arg 2 = output file locations # something like "haddedFiles"

echo ""
echo "Step 1"
echo ""

start_time=$(date +%s)
for filename in $1/*_01.root; do
    target_file=$(echo $filename | sed "s|$1/||g" | sed "s|_01.root||g")
    num=$(cat lists/files_$1.txt | grep $target_file | wc -l)
    echo ""

    if [ $num == 1 ]; then
        file=$(echo $filename | sed "s|$1/||g")
        echo "-------- Copying single file --------"
        cp $1/$file $1/$2/$file
    elif [ $num == 0 ]; then
        echo "There's an issue with the number of files"
    elif [[ $num -gt 9 ]]; then
        echo "---------- Hadding $num files ----------"
        input_file_low=$(echo $target_file | sed "s|$|_0|g")
        input_file_high=$(echo $target_file | sed "s|$|_|g")
        eval hadd $1/$2/$target_file.root $1/$input_file_low\{1..9}.root $1/$input_file_high{10..$num}.root

    else
        echo "---------- Hadding $num files ----------"
        input_file=$(echo $target_file | sed "s|$|_0|g")
        eval hadd $1/$2/$target_file.root $1/$input_file{1..$num}.root
    fi
done

echo ""
echo "Step 2"
echo ""

for filename_letter in $1/*B.root; do
    echo ""
    target_file_letter=$(echo $filename_letter | sed "s|$1/||g" | sed "s|B.root||g")
    list=$(cat lists/files_$1.txt | grep $target_file_letter)
    letter=$(echo ${list: -6} | sed "s|.root||g")
    if [ "$letter" == "B" ]; then
        echo "Only one File in this category"
    else
        echo "------- H-adding letter files -------"
        eval hadd $1/$2/$target_file_letter.root $1/$target_file_letter\{B..$letter}.root
    fi
done

echo ""
end_time=$(date +%s)
diff=$(echo "$end_time-$start_time" | bc)
minutes=$(echo "scale=2; $diff/60" | bc)
echo "Done! Finished in about $minutes minutes!"

# If you want you can add a step to remove the _01 for the files that get copied, but I just use PowerRename from Windows PowerToys to remove it