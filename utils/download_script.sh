#!/bin/bash

# arg1 = location on lpc # something like "vbs/2016"
# arg2 = year # Whatever year you used above

dl_from="/uscms_data/d1/mmekosh/$1" # vbs/<2016, 2017, 2018> just pick one
dl_to=./$2 # Same as year above
list=$(cat ./lists/files_$2.txt)

for filename in $2/*.root; do 
    file=$(echo $filename | sed "s|$2/||g")
    newlist=$(echo $list | sed "s|$file||g")
    list="$newlist"
done

download="$(echo $list | sed "s| |,|g" | sed "s|,,|,|g" | sed "s|^|\\{|g" | sed "s|$|\\}|g")"

scp mmekosh@cmslpc-sl7.fnal.gov:$dl_from/$download $dl_to/
