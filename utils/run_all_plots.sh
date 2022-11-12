#!/bin/bash

# Run2 WV Boosted
##################

# Optimal Cut Scan
Boosted_optCutScan() {
# BDT
    make mon loc="" year="1111" saveFile="TMVAoutput_${3}" lumi="137" cut="full_wv_sr+cleanNAN_tau+cleanNAN_qgid" mon_function="optCutScan" region=boosted plot_type=r var_to_plot="${1}" plot_name="Run2_${3}_optCut_BDT" #| tee -a docs/logs/boosted/boosted_plots.log
# DNN
    make mon loc="" year="1111" saveFile="TMVAoutput_${3}" lumi="137" cut="full_wv_sr+cleanNAN_tau+cleanNAN_qgid" mon_function="optCutScan" region=boosted plot_type=r var_to_plot="${2}" plot_name="Run2_${3}_optCut_DNN" #| tee -a docs/logs/boosted/boosted_plots.log
}

Boosted_genPlots() {
    make mon loc="" year="1111" saveFile="TMVAoutput_${4}" lumi="137" cut="${5}+cleanNAN_tau+cleanNAN_qgid" region=boosted mon_function="genPlots" plot_type=r plot_name="${1}" plot_args="datasets/plot_args/${3}.xml" #| tee -a docs/logs/boosted/boosted_plots.log
    make mon loc="" year="1111" saveFile="TMVAoutput_${4}" lumi="137" cut="${6}+cleanNAN_tau+cleanNAN_qgid" region=boosted mon_function="genPlots" plot_type=r plot_name="${2}" plot_args="datasets/plot_args/${3}.xml" #| tee -a docs/logs/boosted/boosted_plots.log
}

Boosted_cPlots() {
    make mon loc="" year="1111" saveFile="TMVAoutput_${4}" lumi="137" cut="${5}+cleanNAN_tau+cleanNAN_qgid" region=boosted mon_function="cplots" plot_type=r plot_name="${1}" plot_args="datasets/plot_args/${3}.xml" #| tee -a docs/logs/boosted/boosted_plots.log
    make mon loc="" year="1111" saveFile="TMVAoutput_${4}" lumi="137" cut="${6}+cleanNAN_tau+cleanNAN_qgid" region=boosted mon_function="cplots" plot_type=r plot_name="${2}" plot_args="datasets/plot_args/${3}.xml" #| tee -a docs/logs/boosted/boosted_plots.log
}

Boosted_shapePlots() {
    make mon loc="" year="1111" saveFile="TMVAoutput_${4}" lumi="137" cut="${5}+cleanNAN_tau+cleanNAN_qgid" region=boosted mon_function="genPlots" plot_type=s plot_name="${1}" plot_args="datasets/plot_args/${3}.xml" #| tee -a docs/logs/boosted/boosted_plots.log
    make mon loc="" year="1111" saveFile="TMVAoutput_${4}" lumi="137" cut="${6}+cleanNAN_tau+cleanNAN_qgid" region=boosted mon_function="genPlots" plot_type=s plot_name="${2}" plot_args="datasets/plot_args/${3}.xml" #| tee -a docs/logs/boosted/boosted_plots.log
}

Boosted_MLplots() {
    make mon loc="" year="1111" saveFile="TMVAoutput_${1}" lumi="137" cut="full_wv_sr+cleanNAN_tau+cleanNAN_qgid" region=boosted mon_function="genPlots" plot_type=r plot_name="SR_ML_g" plot_args="datasets/plot_args/ML_models_boosted.xml"  #| tee -a docs/logs/boosted/boosted_plots.log
    make mon loc="" year="1111" saveFile="TMVAoutput_${1}" lumi="137" cut="full_wv_sr+cleanNAN_tau+cleanNAN_qgid" region=boosted mon_function="genPlots" plot_type=s plot_name="SR_ML_Shape" plot_args="datasets/plot_args/ML_models_boosted.xml"  #| tee -a docs/logs/boosted/boosted_plots.log
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

Resolved_genPlots() {
    make mon loc="" year="1111" saveFile="TMVAoutput_resolved" lumi="137" cut="resolved_bdt_cut+cleanNAN_tau+cleanNAN_qgid" region=resolved mon_function="genPlots" plot_type=r plot_name="${1}" plot_args="datasets/plot_args/${3}.xml" #| tee -a docs/logs/resolved/resolved_plots.log
    make mon loc="" year="1111" saveFile="TMVAoutput_resolved" lumi="137" cut="resolved_dnn_cut+cleanNAN_tau+cleanNAN_qgid" region=resolved mon_function="genPlots" plot_type=r plot_name="${2}" plot_args="datasets/plot_args/${3}.xml" #| tee -a docs/logs/resolved/resolved_plots.log
}

Resolved_cPlots() {
    make mon loc="" year="1111" saveFile="TMVAoutput_resolved" lumi="137" cut="resolvedd_bdt_cut+cleanNAN_tau+cleanNAN_qgid" region=resolved mon_function="cplots" plot_type=r plot_name="${1}" plot_args="datasets/plot_args/${3}.xml" #| tee -a docs/logs/resolved/resolved_plots.log
    make mon loc="" year="1111" saveFile="TMVAoutput_resolved" lumi="137" cut="resolvedd_dnn_cut+cleanNAN_tau+cleanNAN_qgid" region=resolved mon_function="cplots" plot_type=r plot_name="${2}" plot_args="datasets/plot_args/${3}.xml" #| tee -a docs/logs/resolved/resolved_plots.log
}

Resolved_shapePlots() {
    make mon loc="" year="1111" saveFile="TMVAoutput_resolved" lumi="137" cut="resolved_bdt_cut+cleanNAN_tau+cleanNAN_qgid" region=resolved mon_function="genPlots" plot_type=s plot_name="${1}" plot_args="datasets/plot_args/${3}.xml" #| tee -a docs/logs/resolved/resolved_plots.log
    make mon loc="" year="1111" saveFile="TMVAoutput_resolved" lumi="137" cut="resolved_dnn_cut+cleanNAN_tau+cleanNAN_qgid" region=resolved mon_function="genPlots" plot_type=s plot_name="${2}" plot_args="datasets/plot_args/${3}.xml" #| tee -a docs/logs/resolved/resolved_plots.log
}

Resolved_MLplots() {
    make mon loc="" year="1111" saveFile="TMVAoutput_resolved" lumi="137" cut="full_resolved_sr+cleanNAN_tau+cleanNAN_qgid" region=resolved mon_function="genPlots" plot_type=r plot_name="SR_ML_g" plot_args="datasets/plot_args/ML_models_resolved.xml"  #| tee -a docs/logs/resolved/resolved_plots.log
    make mon loc="" year="1111" saveFile="TMVAoutput_resolved" lumi="137" cut="full_resolved_sr+cleanNAN_tau+cleanNAN_qgid" region=resolved mon_function="genPlots" plot_type=s plot_name="SR_ML_Shape" plot_args="datasets/plot_args/ML_models_resolved.xml"  #| tee -a docs/logs/resolved/resolved_plots.log
}



#Resolved_optCutScan BDT2 DNN_GPU1
Boosted_genPlots 2016_kin_BDT_gen 2016_kin_DNN_gen kinematic_variables_boosted 2016 bdt_2016 dnn_2016
Boosted_genPlots 2017_kin_BDT_gen 2017_kin_DNN_gen kinematic_variables_boosted 2017 bdt_2017 dnn_2017
Boosted_genPlots 2018_kin_BDT_gen 2018_kin_DNN_gen kinematic_variables_boosted 2018 bdt_2018 dnn_2018

Run_Boosted_plots() {
    Boosted_genPlots Run2_boosted_G_kin_BDT Run2_boosted_G_kin_DNN kinematic_variables_boosted
    Boosted_cPlots Run2_boosted_kin_BDT Run2_boosted_kin_DNN kinematic_variables_boosted
    Boosted_shapePlots Run2_boosted_kin_BDT Run2_boosted_kin_DNN kinematic_variables_boosted
    Boosted_MLplots
}

Run_Resolved_plots() {
    Resolved_genPlots Run2_resolved_G_kin_BDT Run2_resolved_G_kin_DNN kinematic_variables_resolved
    Resolved_cPlots Run2_resolved_kin_BDT Run2_resolved_kin_DNN kinematic_variables_resolved
    Resolved_shapePlots Run2_resolved_kin_BDT Run2_resolved_kin_DNN kinematic_variables_resolved
    Resolved_MLplots
}


#Run_Boosted_plots
#Run_Resolved_plots
