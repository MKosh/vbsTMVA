#!/bin/bash

# Run2 Full

# WV boosted
#make cutFlow year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="BDT_cut_Run2_wv" plot_name="Run2_wv_boosted_BDT_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_m"  | tee -a docs/logs/Run2_wv_boosted.log
#make cutFlow year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="DNN_GPU_cut_Run2_wv" plot_name="Run2_wv_boosted_DNN_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_m"  | tee -a docs/logs/Run2_wv_boosted.log

#make cutFlow year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="BDT_cut_Run2_wv" plot_name="Run2_wv_boosted_BDT_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/Run2_wv_boosted.log
#make cutFlow year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="DNN_GPU_cut_Run2_wv" plot_name="Run2_wv_boosted_DNN_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/Run2_wv_boosted.log

# SR
#make mon loc="" year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+BDT_cut_Run2_wv" mon_function="cplots" plot_type=r plot_name="Run2_wv_boosted_BDT" | tee -a docs/logs/Run2_wv_boosted.log
#make mon loc="" year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+DNN_GPU_cut_Run2_wv" mon_function="cplots" plot_type=r plot_name="Run2_wv_boosted_DNN" | tee -a docs/logs/Run2_wv_boosted.log

# Top and Wjets CRs
## genPlots
###make mon loc="" year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="full_top_cr+tau21_cut+qgid_cut" mon_function="genPlots" plot_type=r plot_name="Run2_Top_CR_S_MVA" plot_args="datasets/plot_args/Kinematic_variables.xml"| tee -a docs/logs/Run2_wv_boosted.log
###make mon loc="" year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="full_wjets_cr+tau21_cut+qgid_cut" mon_function="genPlots" plot_type=r plot_name="Run2_Wjets_CR_S_MVA" plot_args="datasets/plot_args/Kinematic_variables.xml"| tee -a docs/logs/Run2_wv_boosted.log

## cplots
#make mon loc="" year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="full_top_cr+tau21_cut+qgid_cut" mon_function="cplots" plot_type=r plot_name="Run2_Top_CR_G_MVA" plot_args="datasets/plot_args/MVA_variables.xml"
#make mon loc="" year="1111" saveFile="Run2_wv_boosted" lumi="137" cut="full_wjets_cr+tau21_cut+qgid_cut" mon_function="cplots" plot_type=r plot_name="Run2_Wjets_CR_G_MVA" plot_args="datasets/plot_args/MVA_variables.xml"

##############

# SR
##make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="BDT" plot_name="Run2_wv_SR_optCut_BDT_BDT" | tee -a docs/logs/Run2_wv_SR.log
##make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="DNN_GPU" plot_name="Run2_wv_SR_optCut_DNN_DNN" | tee -a docs/logs/Run2_wv_SR.log

#make cutFlow year="1111" saveFile="Run2_wv_SR" lumi="137" cut="BDT_cut_Run2_sr" plot_name="Run2_wv_sr_BDT_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/Run2_wv_SR.log
#make cutFlow year="1111" saveFile="Run2_wv_SR" lumi="137" cut="DNN_GPU_cut_Run2_sr" plot_name="Run2_wv_sr_DNN_cutflow" plot_args="datasets/plot_args/MVA_variables.xml" plot_type=r var_to_plot="vbf_deta"  | tee -a docs/logs/Run2_wv_SR.log

# MVA cplots RATIO
#make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+BDT_cut_Run2_sr" mon_function="cplots" plot_type=r plot_name="SR_BDT_G_MVA" plot_args="datasets/plot_args/MVA_variables.xml"
#make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+DNN_GPU_cut_Run2_sr" mon_function="cplots" plot_type=r plot_name="SR_DNN_G_MVA"  plot_args="datasets/plot_args/MVA_variables.xml"

# MVA cplots SHAPE
#make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+BDT_cut_Run2_sr" mon_function="cplots" plot_type=s plot_name="SR_BDT_shape_G_MVA" plot_args="datasets/plot_args/MVA_variables.xml"
#make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+DNN_GPU_cut_Run2_sr" mon_function="cplots" plot_type=s plot_name="wv_SR_DNN_shape_G_MVA"  plot_args="datasets/plot_args/MVA_variables.xml"

# MVA genPlots RATIO
###make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+BDT_cut_Run2_sr" mon_function="genPlots" plot_type=r plot_name="SR_BDT_S_AllVars" plot_args="datasets/plot_args/Kinematic_variables.xml"
###make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+DNN_GPU_cut_Run2_sr" mon_function="genPlots" plot_type=r plot_name="SR_DNN_S_AllVars"  plot_args="datasets/plot_args/Kinematic_variables.xml"

# MVA genPlots SHAPE
###make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+BDT_cut_Run2_sr" mon_function="genPlots" plot_type=s plot_name="SR_BDT_shape_S_MVA" plot_args="datasets/plot_args/Kinematic_variables.xml"
###make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+DNN_GPU_cut_Run2_sr" mon_function="genPlots" plot_type=s plot_name="wv_SR_DNN_shape_S_MVA"  plot_args="datasets/plot_args/Kinematic_variables.xml"

# cplots Kinematic
#make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+BDT_cut_Run2_sr" mon_function="cplots" plot_type=r plot_name="wv_SR_BDT" plot_args="datasets/plot_args/Kinematic_variables.xml" | tee -a docs/logs/Run2_wv_SR.log
#make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+DNN_GPU_cut_Run2_sr" mon_function="cplots" plot_type=r plot_name="wv_SR_DNN"  plot_args="datasets/plot_args/Kinematic_variables.xml"| tee -a docs/logs/Run2_wv_SR.log

# genPlots Kinematic
#make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+BDT_cut_Run2_sr" mon_function="genPlots" plot_type=r plot_name="wv_SR_BDT_plots" plot_args="datasets/plot_args/Kinematic_variables.xml" | tee -a docs/logs/Run2_wv_SR.log
#make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut+DNN_GPU_cut_Run2_sr" mon_function="genPlots" plot_type=r plot_name="wv_SR_DNN_plots" plot_args="datasets/plot_args/Kinematic_variables.xml" | tee -a docs/logs/Run2_wv_SR.log
make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="genPlots" plot_type=r plot_name="wv_SR_BDT_plots" plot_args="datasets/plot_args/Kinematic_variables.xml"

# ML models genPlots
#make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="genPlots" plot_type=r plot_name="SR_ML_S" plot_args="datasets/plot_args/ML_models.xml"
###make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="genPlots" plot_type=s plot_name="SR_ML_shape_S" plot_args="datasets/plot_args/ML_models.xml"