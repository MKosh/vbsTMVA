#!/bin/bash

#cd ../

make train loc="" year="2016" vars="Boosted" methods="BDT,BDTG,MLPBFGS,DNN_GPU" saveFile="2016_region" dataset="dataset_2016.xml" | tee docs/logs/2016_region.txt

make train loc="" year="2017" vars="Boosted" methods="BDT,BDTG,MLPBFGS,DNN_GPU" saveFile="2017_region" dataset="dataset_2017.xml" | tee docs/logs/2017_region.txt

make train loc="" year="2018" vars="Boosted" methods="BDT,BDTG,MLPBFGS,DNN_GPU" saveFile="2018_region" dataset="dataset_2018.xml" | tee docs/logs/2018_region.txt

#make train loc="" year="1111" vars="Boosted" methods="BDT,BDTG,MLPBFGS,DNN_GPU" saveFile="Run2_region" dataset="dataset.xml" | tee docs/logs/Run2_region.txt