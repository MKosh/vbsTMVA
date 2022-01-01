#!/bin/bash

if [[ $1 == "1111" ]]; then
    year="Run2"
else
    year=$1
fi

today=$(date '+%m-%d-%Y')

if [[ $2 != "" ]]; then
    today="$2"
fi

folder="plots/$year/$today/"
#echo "$folder" #>> ../.gitignore
git rm -r --cached "$folder"
