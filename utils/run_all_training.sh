#!/bin/bash

#cd ../
# 2016 Training
make train loc="" year="2016" vars="boosted2" methods="BDT,DNN_GPU" saveFile="2016_wv_boosted" dataset="dataset_2016.xml" training_cut=wv_boosted | tee docs/logs/2016_wv_boosted.log
make train loc="" year="2016" vars="boosted2" methods="BDT,DNN_GPU" saveFile="2016_wv_SR" dataset="dataset_2016.xml" training_cut=full_wv_sr | tee docs/logs/2016_wv_SR.log

#2016 wv_boosted optCutScan, cutflow, and control plots
make mon loc="" year="2016" saveFile="2016_wv_boosted" lumi="35.87" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="BDT" plot_name="2016_wv_boosted_optCut_BDT" | tee -a docs/logs/2016_wv_boosted.log
make mon loc="" year="2016" saveFile="2016_wv_boosted" lumi="35.87" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="DNN_GPU" plot_name="2016_wv_boosted_optCut_DNN" | tee -a docs/logs/2016_wv_boosted.log
#make cutFlow year="2016" saveFile="2016_wv_boosted" lumi="35.87" cut="full_wv_sr" plot_name="2016_wv_boosted_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_function="" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2016_wv_boosted.log
make mon loc="" year="2016" saveFile="2016_wv_boosted" lumi="35.87" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="cplots" plot_type=r plot_name="2016_wv_boosted" | tee -a docs/logs/2016_wv_boosted.log

#2016 wv_SR optCutScan, cutflow, and control plots
make mon loc="" year="2016" saveFile="2016_wv_SR" lumi="35.87" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="BDT" plot_name="2016_wv_SR_optCut_BDT" | tee -a docs/logs/2016_wv_SR.log
make mon loc="" year="2016" saveFile="2016_wv_SR" lumi="35.87" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="DNN_GPU" plot_name="2016_wv_SR_optCut_DNN" | tee -a docs/logs/2016_wv_SR.log
#make cutFlow year="2016"    saveFile="2016_wv_SR" lumi="35.87" cut="full_wv_sr" plot_name="2016_wv_SR_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_function="" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2016_wv_SR.log
make mon loc="" year="2016" saveFile="2016_wv_SR" lumi="35.87" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="cplots" plot_type=r plot_name="2016_wv_SR" | tee -a docs/logs/2016_wv_SR.log

#2017 Training
make train loc="" year="2017" vars="boosted2" methods="BDT,DNN_GPU" saveFile="2017_wv_boosted" dataset="dataset_2017.xml" training_cut=wv_boosted | tee docs/logs/2017_wv_boosted.log
make train loc="" year="2017" vars="boosted2" methods="BDT,DNN_GPU" saveFile="2017_wv_SR" dataset="dataset_2017.xml" training_cut=full_wv_sr | tee docs/logs/2017_wv_SR.log

#2017 wv_boosted optCutScan, cutflow, and control plots
make mon loc="" year="2017" saveFile="2017_wv_boosted" lumi="41.53" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="BDT" plot_name="2017_wv_boosted_optCut_BDT" | tee -a docs/logs/2017_wv_boosted.log
make mon loc="" year="2017" saveFile="2017_wv_boosted" lumi="41.53" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="DNN_GPU" plot_name="2017_wv_boosted_optCut_DNN" | tee -a docs/logs/2017_wv_boosted.log
#make cutFlow year="2017" saveFile="2017_wv_boosted" lumi="41.53" cut="full_wv_sr" plot_name="2017_wv_boosted_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_function="" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2017_wv_boosted.log
make mon loc="" year="2017" saveFile="2017_wv_boosted" lumi="41.53" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="cplots" plot_type=r plot_name="2017_wv_boosted" | tee -a docs/logs/2017_wv_boosted.log

#2017 wv_SR optCutScan, cutflow, and control plots
make mon loc="" year="2017" saveFile="2017_wv_SR" lumi="41.53" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="BDT" plot_name="2017_wv_SR_optCut_BDT" | tee -a docs/logs/2017_wv_SR.log
make mon loc="" year="2017" saveFile="2017_wv_SR" lumi="41.53" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="DNN_GPU" plot_name="2017_wv_SR_optCut_DNN" | tee -a docs/logs/2017_wv_SR.log
#make cutFlow year="2017" saveFile="2017_wv_SR" lumi="41.53" cut="full_wv_sr" plot_name="2017_wv_SR_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_function="" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2017_wv_SR.log
make mon loc="" year="2017" saveFile="2017_wv_SR" lumi="41.53" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="cplots" plot_type=r plot_name="2017_wv_SR" | tee -a docs/logs/2017_wv_SR.log

#2018 training
make train loc="" year="2018" vars="boosted2" methods="BDT,DNN_GPU" saveFile="2018_wv_boosted" dataset="dataset_2018.xml" training_cut=wv_boosted | tee docs/logs/2018_wv_boosted.log
make train loc="" year="2018" vars="boosted2" methods="BDT,DNN_GPU" saveFile="2018_wv_SR" dataset="dataset_2018.xml" training_cut=full_wv_sr | tee docs/logs/2018_wv_SR.log

#2018 wv_boosted optCutScan, cutflow, and control plots
make mon loc="" year="2018" saveFile="2018_wv_boosted" lumi="59.74" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="BDT" plot_name="2018_wv_boosted_optCut_BDT" | tee -a docs/logs/2018_wv_boosted.log
make mon loc="" year="2018" saveFile="2018_wv_boosted" lumi="59.74" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="DNN_GPU" plot_name="2018_wv_boosted_optCutDNN" | tee -a docs/logs/2018_wv_boosted.log
#make cutFlow year="2018" saveFile="2018_wv_boosted" lumi="59.74" cut="full_wv_sr" plot_name="2018_wv_boosted_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_function="" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2018_wv_boosted.log
make mon loc="" year="2018" saveFile="2018_wv_boosted" lumi="59.74" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="cplots" plot_type=r plot_name="2018_wv_boosted" | tee -a docs/logs/2018_wv_boosted.log

#2018 wv_SR optCutScan, cutflow, and control plots
make mon loc="" year="2018" saveFile="2018_wv_SR" lumi="59.74" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="BDT" plot_name="2018_wv_SR_optCut_BDT" | tee -a docs/logs/2018_wv_SR.log
make mon loc="" year="2018" saveFile="2018_wv_SR" lumi="59.74" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="DNN_GPU" plot_name="2018_wv_SR_optCut_DNN" | tee -a docs/logs/2018_wv_SR.log
#make cutFlow year="2018" saveFile="2018_wv_SR" lumi="59.74" cut="full_wv_sr" plot_name="2018_wv_SR_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_function="" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2018_wv_SR.log
make mon loc="" year="2018" saveFile="2018_wv_SR" lumi="59.74" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="cplots" plot_type=r plot_name="2018_wv_SR" | tee -a docs/logs/2018_wv_SR.log

#Run2 training
make train loc="" year="1111" vars="boosted2" methods="BDT,DNN_GPU" saveFile="Run2_wv_boosted" dataset="dataset.xml" training_cut=wv_boosted | tee docs/logs/Run2_wv_boosted.log
make train loc="" year="1111" vars="boosted2" methods="BDT,DNN_GPU" saveFile="Run2_wv_SR" dataset="dataset.xml" training_cut=full_wv_sr | tee docs/logs/Run2_wv_SR.log

#Run2 wv_boosted optCutScan, cutflow, and control plots
make mon loc="" year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="BDT" plot_name="Run2_wv_boosted_optCut_BDT" | tee -a docs/logs/Run2_wv_boosted.log
make mon loc="" year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="DNN_GPU" plot_name="Run2_wv_boosted_optCut_DNN" | tee -a docs/logs/Run2_wv_boosted.log
#make cutFlow year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="full_wv_sr" plot_name="Run2_wv_boosted_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_function="" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/Run2_wv_boosted.log
make mon loc="" year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="cplots" plot_type=r plot_name="Run2_wv_boosted" | tee -a docs/logs/Run2_wv_boosted.log

#Run2 wv_SR optCutScan, cutflow, and control plots
make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="BDT" plot_name="Run2_wv_SR_optCut_BDT_BDT" | tee -a docs/logs/Run2_wv_SR.log
make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="DNN_GPU" plot_name="Run2_wv_SR_optCut_DNN_DNN" | tee -a docs/logs/Run2_wv_SR.log
#make cutFlow year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr" plot_name="Run2_wv_SR_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_function="" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/Run2_wv_SR.log
make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="cplots" plot_type=r plot_name="Run2_wv_SR" | tee -a docs/logs/Run2_wv_SR.log
