#!/bin/bash

# Run2 WV Boosted
##################

# Optimal Cut Scan
Boosted_optCutScan() {
# BDT
    make mon loc="" year="1111" saveFile="TMVAoutput_boosted" lumi="137" cut="full_wv_sr+cleanNAN_tau+cleanNAN_qgid" mon_function="optCutScan" region=boosted plot_type=r var_to_plot="${1}" plot_name="Run2_boosted_optCut_BDT" | tee -a docs/logs/boosted/boosted_plots.log
# DNN
    make mon loc="" year="1111" saveFile="TMVAoutput_boosted" lumi="137" cut="full_wv_sr+cleanNAN_tau+cleanNAN_qgid" mon_function="optCutScan" region=boosted plot_type=r var_to_plot="${2}" plot_name="Run2_boosted_optCut_DNN" | tee -a docs/logs/boosted/boosted_plots.log
}

Boosted_genPlots() {
    make mon loc="" year="1111" saveFile="TMVAoutput_boosted" lumi="137" cut="boosted_bdt_cut+cleanNAN_tau+cleanNAN_qgid" region=boosted mon_function="genPlots" plot_type=r plot_name="${1}" plot_args="datasets/plot_args/${3}.xml" | tee -a docs/logs/boosted/boosted_plots.log
    make mon loc="" year="1111" saveFile="TMVAoutput_boosted" lumi="137" cut="boosted_dnn_cut+cleanNAN_tau+cleanNAN_qgid" region=boosted mon_function="genPlots" plot_type=r plot_name="${2}" plot_args="datasets/plot_args/${3}.xml" | tee -a docs/logs/boosted/boosted_plots.log
}

Boosted_cPlots() {
    make mon loc="" year="1111" saveFile="TMVAoutput_boosted" lumi="137" cut="boosted_bdt_cut+cleanNAN_tau+cleanNAN_qgid" region=boosted mon_function="cplots" plot_type=r plot_name="${1}" plot_args="datasets/plot_args/${3}.xml" | tee -a docs/logs/boosted/boosted_plots.log
    make mon loc="" year="1111" saveFile="TMVAoutput_boosted" lumi="137" cut="boosted_dnn_cut+cleanNAN_tau+cleanNAN_qgid" region=boosted mon_function="cplots" plot_type=r plot_name="${2}" plot_args="datasets/plot_args/${3}.xml" | tee -a docs/logs/boosted/boosted_plots.log
}

Boosted_shapePlots() {
    make mon loc="" year="1111" saveFile="TMVAoutput_boosted" lumi="137" cut="boosted_bdt_cut+cleanNAN_tau+cleanNAN_qgid" region=boosted mon_function="genPlots" plot_type=s plot_name="${1}" plot_args="datasets/plot_args/${3}.xml" | tee -a docs/logs/boosted/boosted_plots.log
    make mon loc="" year="1111" saveFile="TMVAoutput_boosted" lumi="137" cut="boosted_dnn_cut+cleanNAN_tau+cleanNAN_qgid" region=boosted mon_function="genPlots" plot_type=s plot_name="${2}" plot_args="datasets/plot_args/${3}.xml" | tee -a docs/logs/boosted/boosted_plots.log
}

Boosted_MLplots() {
    make mon loc="" year="1111" saveFile="TMVAoutput_boosted" lumi="137" cut="full_wv_sr+cleanNAN_tau+cleanNAN_qgid" mon_function="genPlots" plot_type=r plot_name="SR_ML_g" plot_args="datasets/plot_args/ML_models_boosted.xml"  | tee -a docs/logs/boosted/boosted_plots.log
    make mon loc="" year="1111" saveFile="TMVAoutput_boosted" lumi="137" cut="full_wv_sr+cleanNAN_tau+cleanNAN_qgid" mon_function="genPlots" plot_type=s plot_name="SR_ML_Shape" plot_args="datasets/plot_args/ML_models_boosted.xml"  | tee -a docs/logs/boosted/boosted_plots.log
}

# Run2 WV Resolved
##################

# Optimal Cut Scan
Resolved_optCutScan() {
# BDT
make mon loc="" year="1111" saveFile="TMVAoutput_resolved" lumi="137" cut="full_resolved_sr+cleanNAN_tau+cleanNAN_qgid" mon_function="optCutScan" region=resolved plot_type=r var_to_plot="${1}" plot_name="Run2_resolved_optCut_BDT" | tee -a docs/logs/resolved/resolved_plots.log
# DNN
make mon loc="" year="1111" saveFile="TMVAoutput_resolved" lumi="137" cut="full_resolved_sr+cleanNAN_tau+cleanNAN_qgid" mon_function="optCutScan" region=resolved plot_type=r var_to_plot="${2}" plot_name="Run2_resolved_optCut_DNN" | tee -a docs/logs/resolved/resolved_plots.log
}
 
# SR
##make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="BDT" plot_name="Run2_wv_SR_optCut_BDT_BDT" | tee -a docs/logs/Run2_wv_SR.log
##make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="optCutScan" plot_type=r var_to_plot="DNN_GPU" plot_name="Run2_wv_SR_optCut_DNN_DNN" | tee -a docs/logs/Run2_wv_SR.log

#make mon year="1111" saveFile="TMVAoutput_resolved_full" lumi="137" cut="dummy" plot_name="Run2_resolved_cutflow" region=resolved mon_function="printCutflow" plot_args="datasets/plot_args/single_plot.xml" plot_type=r var_to_plot="vbf_m"  | tee -a docs/logs/Resolved_cutflows.log
#make mon year="1111" saveFile="TMVAoutput_boosted_full" lumi="137" cut="dummy" plot_name="Run2_boosted_cutflow" region=boosted mon_function="printCutflow" plot_args="datasets/plot_args/single_plot.xml" plot_type=r var_to_plot="vbf_m"  | tee -a docs/logs/Boosted_cutflows.log
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

# ML models genPlots
#make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="genPlots" plot_type=r plot_name="SR_ML_S" plot_args="datasets/plot_args/ML_models.xml"
###make mon loc="" year="1111" saveFile="Run2_wv_SR" lumi="137" cut="full_wv_sr+tau21_cut+qgid_cut" mon_function="genPlots" plot_type=s plot_name="SR_ML_shape_S" plot_args="datasets/plot_args/ML_models.xml"

#### Full

#make mon loc="" year="1111" saveFile="TMVAoutput_boosted_full" lumi="137" cut="year_2016+full_top_cr+cleanNAN_tau+cleanNAN_qgid" region=boosted mon_function="genPlots" plot_type=r plot_name="vbf_m_Top_CR_2016" plot_args="datasets/plot_args/single_plot.xml"

#make mon loc="" year="1111" saveFile="TMVAoutput_resolved_full" lumi="137" cut="full_resolved_sr+cleanNAN_tau+qgid_cut" region=resolved mon_function="genPlots" plot_type=r plot_name="vbf_m_SR" plot_args="datasets/plot_args/single_plot.xml"

#Boosted_optCutScan BDT4 DNN_GPU1
#Resolved_optCutScan BDT2 DNN_GPU1

Boosted_genPlots Run2_boosted_G_kin_BDT Run2_boosted_G_kin_DNN Boosted_kinematic_variables
Boosted_cPlots Run2_boosted_kin_BDT Run2_boosted_kin_DNN Boosted_kinematic_variables
Boosted_shapePlots Run2_boosted_kin_BDT Run2_boosted_kin_DNN Boosted_kinematic_variables
Boosted_MLplots 
