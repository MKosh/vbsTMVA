#!/bin/bash

#cd ../

make train loc="" year="2016" vars="boosted2" methods="BDT,DNN_GPU" saveFile="2016_wv_boosted" dataset="dataset_2016.xml" | tee docs/logs/2016_wv_boosted.log
#make mon loc="" year="2016" saveFile="2016_boosted24" lumi="35.87" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="sgf1" plot_name="boosted24_optCut" | tee -a docs/logs/num_variables_tests/2016_boosted24.log
#make cutFlow year="2016" saveFile="2016_boosted24" lumi="35.87" cut="full_wv_sr" plot_name="boosted24_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_function="" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/num_variables_tests/2016_boosted24.log

make train loc="" year="2017" vars="boosted2" methods="BDT,DNN_GPU" saveFile="2017_wv_boosted" dataset="dataset_2017.xml" | tee docs/logs/2017_wv_boosted.log

make train loc="" year="2018" vars="boosted2" methods="BDT,DNN_GPU" saveFile="2018_wv_boosted" dataset="dataset_2018.xml" | tee docs/logs/2018_wv_boosted.log

make train loc="" year="1111" vars="boosted2" methods="BDT,DNN_GPU" saveFile="Run2_wv_boosted" dataset="dataset.xml" | tee docs/logs/Run2_wv_boosted.log