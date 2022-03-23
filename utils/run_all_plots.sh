#!/bin/bash

# 2016
#make cutFlow year="2016" saveFile="2016_wv_boosted" lumi="35.87" cut="BDT_cut_2016_wv" plot_name="2016_wv_boosted_BDT_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2016_wv_boosted.log
#make cutFlow year="2016" saveFile="2016_wv_boosted" lumi="35.87" cut="DNN_GPU_cut_2016_wv" plot_name="2016_wv_boosted_DNN_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2016_wv_boosted.log
#make mon loc="" year="2016" saveFile="2016_wv_boosted" lumi="35.87" cut="full_wv_sr+tau21_cut+qgid_cut+BDT_cut_2016_wv" mon_function="cplots" plot_type=r plot_name="2016_wv_boosted_BDT" | tee -a docs/logs/2016_wv_boosted.log
#make mon loc="" year="2016" saveFile="2016_wv_boosted" lumi="35.87" cut="full_wv_sr+tau21_cut+qgid_cut+DNN_GPU_cut_2016_wv" mon_function="cplots" plot_type=r plot_name="2016_wv_boosted_DNN" | tee -a docs/logs/2016_wv_boosted.log

# Cutflows in the SR don't really make sense to do so they can be skipped
#make cutFlow year="2016" saveFile="2016_wv_SR" lumi="35.87" cut="BDT_cut_2016_sr" plot_name="2016_wv_sr_BDT_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2016_wv_SR.log
#make cutFlow year="2016" saveFile="2016_wv_SR" lumi="35.87" cut="DNN_GPU_cut_2016_sr" plot_name="2016_wv_sr_DNN_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2016_wv_SR.log
make mon loc="" year="2016" saveFile="2016_wv_SR" lumi="35.87" cut="full_wv_sr+tau21_cut+qgid_cut+BDT_cut_2016_sr" mon_function="cplots" plot_type=r plot_name="wv_SR_BDT" | tee -a docs/logs/2016_wv_SR.log
make mon loc="" year="2016" saveFile="2016_wv_SR" lumi="35.87" cut="full_wv_sr+tau21_cut+qgid_cut+DNN_GPU_cut_2016_sr" mon_function="cplots" plot_type=r plot_name="wv_SR_DNN" | tee -a docs/logs/2016_wv_SR.log

# 2017
#make cutFlow year="2017" saveFile="2017_wv_boosted" lumi="41.53" cut="BDT_cut_2017_wv" plot_name="2017_wv_boosted_BDT_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2017_wv_boosted.log
#make cutFlow year="2017" saveFile="2017_wv_boosted" lumi="41.53" cut="DNN_GPU_cut_2017_wv" plot_name="2017_wv_boosted_DNN_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2017_wv_boosted.log
#make mon loc="" year="2017" saveFile="2017_wv_boosted" lumi="41.53" cut="full_wv_sr+tau21_cut+qgid_cut+BDT_cut_2017_wv" mon_function="cplots" plot_type=r plot_name="2017_wv_boosted_BDT" | tee -a docs/logs/2017_wv_boosted.log
#make mon loc="" year="2017" saveFile="2017_wv_boosted" lumi="41.53" cut="full_wv_sr+tau21_cut+qgid_cut+DNN_GPU_cut_2017_wv" mon_function="cplots" plot_type=r plot_name="2017_wv_boosted_DNN" | tee -a docs/logs/2017_wv_boosted.log

#make cutFlow year="2017" saveFile="2017_wv_SR" lumi="41.53" cut="BDT_cut_2017_sr" plot_name="2017_wv_sr_BDT_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2017_wv_SR.log
#make cutFlow year="2017" saveFile="2017_wv_SR" lumi="41.53" cut="DNN_GPU_cut_2017_sr" plot_name="2017_wv_sr_DNN_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2017_wv_SR.log
make mon loc="" year="2017" saveFile="2017_wv_SR" lumi="41.53" cut="full_wv_sr+tau21_cut+qgid_cut+BDT_cut_2017_sr" mon_function="cplots" plot_type=r plot_name="wv_SR_BDT" | tee -a docs/logs/2017_wv_SR.log
make mon loc="" year="2017" saveFile="2017_wv_SR" lumi="41.53" cut="full_wv_sr+tau21_cut+qgid_cut+DNN_GPU_cut_2017_sr" mon_function="cplots" plot_type=r plot_name="wv_SR_DNN" | tee -a docs/logs/2017_wv_SR.log

# 2018
#make cutFlow year="2018" saveFile="2018_wv_boosted" lumi="59.74" cut="BDT_cut_2018_wv" plot_name="2018_wv_boosted_BDT_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2018_wv_boosted.log
#make cutFlow year="2018" saveFile="2018_wv_boosted" lumi="59.74" cut="DNN_GPU_cut_2018_wv" plot_name="2018_wv_boosted_DNN_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2018_wv_boosted.log
#make mon loc="" year="2018" saveFile="2018_wv_boosted" lumi="59.74" cut="full_wv_sr+tau21_cut+qgid_cut+BDT_cut_2018_wv" mon_function="cplots" plot_type=r plot_name="2018_wv_boosted_BDT" | tee -a docs/logs/2018_wv_boosted.log
#make mon loc="" year="2018" saveFile="2018_wv_boosted" lumi="59.74" cut="full_wv_sr+tau21_cut+qgid_cut+DNN_GPU_cut_2018_wv" mon_function="cplots" plot_type=r plot_name="2018_wv_boosted_DNN" | tee -a docs/logs/2018_wv_boosted.log

#make cutFlow year="2018" saveFile="2018_wv_SR" lumi="59.74" cut="BDT_cut_2018_sr" plot_name="2018_wv_sr_BDT_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2018_wv_SR.log
#make cutFlow year="2018" saveFile="2018_wv_SR" lumi="59.74" cut="DNN_GPU_cut_2018_sr" plot_name="2018_wv_sr_DNN_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/2018_wv_SR.log
make mon loc="" year="2018" saveFile="2018_wv_SR" lumi="59.74" cut="full_wv_sr+tau21_cut+qgid_cut+BDT_cut_2018_sr" mon_function="cplots" plot_type=r plot_name="wv_SR_BDT" | tee -a docs/logs/2018_wv_SR.log
make mon loc="" year="2018" saveFile="2018_wv_SR" lumi="59.74" cut="full_wv_sr+tau21_cut+qgid_cut+DNN_GPU_cut_2018_sr" mon_function="cplots" plot_type=r plot_name="wv_SR_DNN" | tee -a docs/logs/2018_wv_SR.log

# Run2 Full
#make cutFlow year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="BDT_cut_Run2_wv" plot_name="Run2_wv_boosted_BDT_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/Run2_wv_boosted.log
#make cutFlow year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="DNN_GPU_cut_Run2_wv" plot_name="Run2_wv_boosted_DNN_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/Run2_wv_boosted.log
#make mon loc="" year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+BDT_cut_Run2_wv" mon_function="cplots" plot_type=r plot_name="Run2_wv_boosted_BDT" | tee -a docs/logs/Run2_wv_boosted.log
#make mon loc="" year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+DNN_GPU_cut_Run2_wv" mon_function="cplots" plot_type=r plot_name="Run2_wv_boosted_DNN" | tee -a docs/logs/Run2_wv_boosted.log

#make cutFlow year="1111" saveFile="Run2_wv_SR" lumi="137" cut="BDT_cut_Run2_sr" plot_name="Run2_wv_sr_BDT_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/Run2_wv_SR.log
#make cutFlow year="1111" saveFile="Run2_wv_SR" lumi="137" cut="DNN_GPU_cut_Run2_sr" plot_name="Run2_wv_sr_DNN_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/Run2_wv_SR.log
make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+BDT_cut_Run2_sr" mon_function="cplots" plot_type=r plot_name="wv_SR_BDT" | tee -a docs/logs/Run2_wv_SR.log
make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+DNN_GPU_cut_Run2_sr" mon_function="cplots" plot_type=r plot_name="wv_SR_DNN" | tee -a docs/logs/Run2_wv_SR.log

# Run2 Combined
#make cutFlow year="1111" saveFile="Run2_Summed" lumi="137" cut="BDT_cut_Run2_Summed" plot_name="Run2_Summed_BDT_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/Run2_Summed.log
#make cutFlow year="1111" saveFile="Run2_Summed" lumi="137" cut="DNN_GPU_cut_Run2_Summed" plot_name="Run2_Summed_DNN_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/Run2_Summed.log
make mon loc="" year="1111" saveFile="Run2_Summed" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+BDT_cut_Run2_Summed" mon_function="cplots" plot_type=r plot_name="Summed_BDT" | tee -a docs/logs/Run2_Summed.log
make mon loc="" year="1111" saveFile="Run2_Summed" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+DNN_GPU_cut_Run2_Summed" mon_function="cplots" plot_type=r plot_name="Summed_DNN" | tee -a docs/logs/Run2_Summed.log
