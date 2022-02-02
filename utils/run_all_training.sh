#!/bin/bash

#cd ../

make train loc="" year="2016" vars="Boosted" methods="BDT,BDTG,MLPBFGS" saveFile="2016" dataset="dataset_2016.xml" | tee docs/logs/2016_output.txt

make train loc="" year="2017" vars="Boosted" methods="BDT,BDTG,MLPBFGS" saveFile="2017" dataset="dataset_2017.xml" | tee docs/logs/2017_output.txt

make train loc="" year="2018" vars="Boosted" methods="BDT,BDTG,MLPBFGS" saveFile="2018" dataset="dataset_2018.xml" | tee docs/logs/2018_output.txt

make train loc="" year="1111" vars="Boosted" methods="BDT,BDTG,MLPBFGS" saveFile="Run2" dataset="dataset.xml" | tee docs/logs/run2_output.txt