#!/bin/bash


make controlPlots year="2016" lumi="35.87" cut="full_wv_sr" plot_name="SR" saveFile="2016" 
make controlPlots year="2016" lumi="35.87" cut="full_top_cr" plot_name="Top_CR" saveFile="2016"
make controlPlots year="2016" lumi="35.87" cut="full_wjets_cr" plot_name="Wjets_CR" saveFile="2016"

make controlPlots year="2017" lumi="41.53" cut="full_wv_sr" plot_name="SR" saveFile="2017" 
make controlPlots year="2017" lumi="41.53" cut="full_top_cr" plot_name="Top_CR" saveFile="2017"
make controlPlots year="2017" lumi="41.53" cut="full_wjets_cr" plot_name="Wjets_CR" saveFile="2017"

make controlPlots year="2018" lumi="59.74" cut="full_wv_sr" plot_name="SR" saveFile="2018" 
make controlPlots year="2018" lumi="59.74" cut="full_top_cr" plot_name="Top_CR" saveFile="2018"
make controlPlots year="2018" lumi="59.74" cut="full_wjets_cr" plot_name="Wjets_CR" saveFile="2018"

make controlPlots year="1111" lumi="137" cut="full_wv_sr" plot_name="SR" saveFile="Run2"
make controlPlots year="1111" lumi="137" cut="full_top_cr" plot_name="Top_CR" saveFile="Run2"
make controlPlots year="1111" lumi="137" cut="full_wjets_cr" plot_name="Wjets_CR" saveFile="Run2"
