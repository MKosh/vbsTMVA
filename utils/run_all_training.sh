#!/bin/bash

#cd ../

make train loc="" year="2016" vars="boosted24" methods="BDT,BDTG,DNN_GPU" saveFile="2016_boosted24" dataset="dataset_2016.xml" | tee docs/logs/num_variables_tests/2016_boosted24.log
make mon loc="" year="2016" saveFile="2016_boosted24" lumi="35.87" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="sgf1" plot_name="boosted24_optCut" | tee -a docs/logs/num_variables_tests/2016_boosted24.log
make cutFlow year="2016" saveFile="2016_boosted24" lumi="35.87" cut="full_wv_sr" plot_name="boosted24_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_function="" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/num_variables_tests/2016_boosted24.log

#make train loc="" year="2017" vars="Boosted" methods="BDT,BDTG,MLPBFGS,DNN_GPU" saveFile="2017_region" dataset="dataset_2017.xml" | tee docs/logs/2017_region.txt

#make train loc="" year="2018" vars="Boosted" methods="BDT,BDTG,MLPBFGS,DNN_GPU" saveFile="2018_region" dataset="dataset_2018.xml" | tee docs/logs/2018_region.txt

#make train loc="" year="1111" vars="Boosted" methods="BDT,BDTG,MLPBFGS,DNN_GPU" saveFile="Run2_region" dataset="dataset.xml" | tee docs/logs/Run2_region.txt