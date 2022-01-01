# Need to specify bash in order for conda activate to work.
#SHELL=/bin/bash
# Note that the extra activate is needed to ensure that the activate floats env to the front of PATH
#CONDA_ACTIVATE=source $$(conda info --base)/etc/profile.d/conda.sh ; conda activate ; conda activate

loc ?= "g/Research/ntuples/NEW/2016/haddedFiles"
year ?= "2016"
vars ?= "set1"
methods ?= "BDT"
lumi ?= 35.867
cut ?= "dummy"
cutName ?= "test"
pltVar ?= "lep1_pt"
saveFile ?= "$(year)"
dataset ?= "dataset.xml"
dataset_dir ?= "datasets/plot_args"
plot_type ?= "r"

help:
	@echo ""
	@echo "-------------------------------------------------------- Makefile Arguments --------------------------------------------------------"
	@echo ""
	@echo "loc ------- location of the .root data files			 |	methods - TMVA methods (Fisher, BDT, DNN_GPU, MLPBFGS, etc.)"
	@echo "vars ------ variable set (set1, Boosted, Resolved, old)		 |	lumi ---- (2016 -> 35.867) | (2017 -> 41.53) | (2018 -> 59.74)"
	@echo "year ------ (2016, 2017, 2018, 1111)				 |	varName - The name of the variable to be plotted"
	@echo "cut ------- the cut you want to apply for the plots		 |	cutName - Used for labeling the plots in the saved PDF"
	@echo "dataset --- Data selection file					 |  dataset_dir - Directory where the dataset file is located"
	@echo "plot_type - single char (r: ratio plot, s: shape plots)"
	@echo ""
	@echo "--------------------------------------------------------- Makefile targets ---------------------------------------------------------"
	@echo ""
	@echo "trainAndPlot : If you want to train and output plots"
	@echo "	Arguments - loc, year, vars, methods, lumi, cut, cutName"
	@echo ""
	@echo "train: If you want to train but not create plots"
	@echo "	Arguments - loc, year, vars, methods, cutName, saveFile, dataset"
	@echo ""
	@echo "controlPlots: If you just want to make and save the cplots"
	@echo "	Arguments - year, lumi, cut, cutName, saveFile"
	@echo ""
	@echo "mon: If you just want to run the tmvaMon program and make individual plots"
	@echo "	Arguments - year, lumi, cut, cutName, saveFile"
	@echo ""
	@echo "genPlots: If you want to plot a single var at a time from a file"
	@echo "	Arguments - year, lumi, cut, cutName, dataset_dir, dataset, plot_type, saveFile"
	@echo ""
	@echo "classify: Run the classification algorithms without applying them to the data trees"
	@echo "	Arguments - loc, year, vars, methods, cutName, saveFile"
	@echo ""
	@echo "apply: Apply the classification algorithms to the data trees"
	@echo "	Arguments - saveFile, methods"


test:
	@echo "loc = $(loc)"
	@echo "vars = $(vars)"
	@echo "year = $(year)"
	@echo "methods = $(methods)"
	@echo "lumi = $(lumi)"
	@echo "cut = $(cut)"
	@echo "cutName = $(cutName)"
	@echo "pltVar = $(pltVar)"
	@echo "saveFile = $(saveFile)"
	@echo "dataset = $(dataset)"
	@echo "dataset_dir = $(dataset_dir)"
	@echo "plot_type = $(plot_type)" 

#///////////////////////////////////////////////////////////////////////////////
#
init:
	-@rm -r skims/vbs_ww
	@./dsw.sh "$(loc)" "$(year)" "$(dataset)"
	@./write_vbsDL.sh "$(loc)" "$(vars)" "$(year)"
	@echo "Done!"

#///////////////////////////////////////////////////////////////////////////////
#
classify: update_$(year)
	-@rm -r skims/vbs_ww
	@./dsw.sh "$(loc)" "$(year)" "$(dataset)"
	@./write_vbsDL.sh "$(loc)" "$(vars)" "$(year)"
	@sed -i 's|^.*\(.txt"; // AUCoutfile\)|    ssAUCoutfile << "ROC/" << "$(saveFile).txt"; // AUCoutfile|g' vbsTMVAClassification.cc
	@root ./vbsTMVAClassification.cc\(\"vbs_ww_$(saveFile)\",\"$(methods)\"\)

#///////////////////////////////////////////////////////////////////////////////
#
apply:
	root -b -q ./vbsTMVAClassificationApplication.cc\(\"vbs_ww_$(saveFile)\",\"$(methods)\"\)

#///////////////////////////////////////////////////////////////////////////////
#
train: update_$(year)
	-@rm -r skims/vbs_ww
	@./dsw.sh "$(loc)" "$(year)" "$(dataset)"
	@./write_vbsDL.sh "$(loc)" "$(vars)" "$(year)"
	@sed -i 's|^.*\(.txt"; // AUCoutfile\)|    ssAUCoutfile << "ROC/" << "$(saveFile).txt"; // AUCoutfile|g' vbsTMVAClassification.cc
	@root -b -q ./vbsTMVAClassification.cc\(\"vbs_ww_$(saveFile)\",\"$(methods)\"\)
	@root -b -q ./vbsTMVAClassificationApplication.cc\(\"vbs_ww_$(saveFile)\",\"$(methods)\"\)
	@sed -i 's|^.*\(cplots(anl, cut, cutName); // XXX\)|//cplots(anl, cut, cutName); // XXX|g' tmvaMon.cc

#///////////////////////////////////////////////////////////////////////////////
#
trainAndPlot: update_$(year)
	-@rm -r skims/vbs_ww
	@./dsw.sh "$(loc)" "$(year)" "$(dataset)"
	@./write_vbsDL.sh "$(loc)" "$(vars)" "$(year)"
	@sed -i 's|^.*\(.txt"; // AUCoutfile\)|    ssAUCoutfile << "ROC/" << "$(saveFile).txt"; // AUCoutfile|g' vbsTMVAClassification.cc
	@root -b -q ./vbsTMVAClassification.cc\(\"vbs_ww_$(saveFile)\",\"$(methods)\"\)
	@root -b -q ./vbsTMVAClassificationApplication.cc\(\"vbs_ww_$(saveFile)\",\"$(methods)\"\)
	@sed -i 's|^.*\(cplots(anl, cut, cutName); // XXX\)|cplots(anl, cut, cutName); // XXX|g' tmvaMon.cc    
	@sed -i 's|^.*\(shapePlots(anl, cut, cutName); // XXX\)|//shapePlots(anl, cut, cutName); // XXX|g' tmvaMon.cc
	@root -q tmvaMon.cc\(\"vbs_ww_$(saveFile)\",$(lumi),$(cut),\"$(cutName)\"\)
	-@./utils/plot_resort.sh "$(year)"
	@./utils/gen_plots.sh

#///////////////////////////////////////////////////////////////////////////////
#
controlPlots: update_$(year)
	@sed -i 's|^.*\(cplots(anl, cut, cutName); // XXX\)|cplots(anl, cut, cutName); // XXX|g' tmvaMon.cc
	@sed -i 's|^.*\(shapePlots(anl, cut, cutName); // XXX\)|//shapePlots(anl, cut, cutName); // XXX|g' tmvaMon.cc
	@sed -i 's|^.*\(genPlots(anl, cut, cutName\)'|  //genPlots(anl, cut, cutName)|g' tmvaMon.cc
#	-@./utils/plot_sort.sh "$(year)"
	@root -q tmvaMon.cc\(\"vbs_ww_$(saveFile)\",$(lumi),$(cut),\"$(cutName)\"\)
#	-@./utils/plot_resort.sh "$(year)"
# @./utils/gen_plots.sh

#///////////////////////////////////////////////////////////////////////////////
#
shapePlots: update_$(year)
	@sed -i 's|^.*\(cplots(anl, cut, cutName); // XXX\)|//cplots(anl, cut, cutName); // XXX|g' tmvaMon.cc
	@sed -i 's|^.*\(shapePlots(anl, cut, cutName); // XXX\)|shapePlots(anl, cut, cutName); // XXX|g' tmvaMon.cc
	@sed -i 's|^.*\(genPlots(anl, cut, cutName\)'|  //genPlots(anl, cut, cutName)|g' tmvaMon.cc
#-@./utils/plot_sort.sh "$(year)"
	@root -q tmvaMon.cc\(\"vbs_ww_$(saveFile)\",$(lumi),$(cut),\"$(cutName)\"\)
#	-@./utils/plot_resort.sh "$(year)"
#	@./utils/gen_shape_plots.sh

#///////////////////////////////////////////////////////////////////////////////
#
genPlots: update_$(year)
	@sed -i 's|^.*\(cplots(anl, cut, cutName); // XXX\)|  //cplots(anl, cut, cutName); // XXX|g' tmvaMon.cc
	@sed -i 's|^.*\(shapePlots(anl, cut, cutName); // XXX\)|  //shapePlots(anl, cut, cutName); // XXX|g' tmvaMon.cc
	@sed -i 's|^.*\(; // XXX genPlots\)|  genPlots(anl, cut, cutName, \"$(dataset_dir)\", \"$(dataset)\", '\''$(plot_type)'\''); // XXX genPlots|g' tmvaMon.cc
#	-@./utils/plot_sort.sh "$(year)"
	@root -q tmvaMon.cc\(\"vbs_ww_$(saveFile)\",$(lumi),$(cut),\"$(cutName)\"\)
#	-@./utils/plot_resort.sh "$(year)"

#///////////////////////////////////////////////////////////////////////////////
#
mon: update_$(year)
	@sed -i 's|^.*\(cplots(anl, cut, cutName); // XXX\)|//cplots(anl, cut, cutName); // XXX|g' tmvaMon.cc
	@sed -i 's|^.*\(shapePlots(anl, cut, cutName); // XXX\)|//shapePlots(anl, cut, cutName); // XXX|g' tmvaMon.cc
	@sed -i 's|^.*\(genPlots(anl, \)|  //genPlots(anl, |g' tmvaMon.cc
#-@./utils/plot_sort.sh "$(year)"
#@echo "Don't forget to run the plot_resort.sh script after generating new plots"
	@root tmvaMon.cc\(\"vbs_ww_$(saveFile)\",$(lumi),$(cut),\"$(cutName)\"\)
	

#-------------------------------------------------------------------------------
# These makefile targets update the different files for whichever year specified
update_1111: 
	@sed -i 's|chain2tree("otree",|chain2tree("Events",|g' vbsTMVAClassification.cc
	@sed -i 's|int year = [0-9]\{4\}|int year = 1111|g' tmvaMon.cc
	@sed -i 's|std::string year2 = "[0-9]\{4\}"|std::string year2 = "1111"|g' tmvaMon.cc
	@sed -i 's|^.*\(vbs_jets_pt));\)|    TCut allCuts         ("allCuts",     (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' tmvaMon.cc
	@sed -i 's|^.*\(ZeppWHlt3));\)|//    TCut allCuts        ("allCuts",    (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' tmvaMon.cc
	@sed -i 's|^.*\(vbs_jets_pt));\)|TCut allCuts            ("allCuts",                (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' vbsTMVA.hpp
	@sed -i 's|^.*\(ZeppWHlt3));\)|//TCut allCuts                ("allCuts",             (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' vbsTMVA.hpp

update_2016: 
	@sed -i 's|chain2tree("otree",|chain2tree("Events",|g' vbsTMVAClassification.cc
	@sed -i 's|int year = [0-9]\{4\}|int year = 2016|g' tmvaMon.cc
	@sed -i 's|std::string year2 = "[0-9]\{4\}"|std::string year2 = "2016"|g' tmvaMon.cc
	@sed -i 's|^.*\(vbs_jets_pt));\)|    TCut allCuts         ("allCuts",     (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' tmvaMon.cc
	@sed -i 's|^.*\(ZeppWHlt3));\)|//    TCut allCuts        ("allCuts",    (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' tmvaMon.cc
	@sed -i 's|^.*\(vbs_jets_pt));\)|TCut allCuts            ("allCuts",                (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' vbsTMVA.hpp
	@sed -i 's|^.*\(ZeppWHlt3));\)|//TCut allCuts                ("allCuts",             (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' vbsTMVA.hpp

update_2017:
	@sed -i 's|chain2tree("otree",|chain2tree("Events",|g' vbsTMVAClassification.cc
	@sed -i 's|int year = [0-9]\{4\}|int year = 2017|g' tmvaMon.cc
	@sed -i 's|std::string year2 = "[0-9]\{4\}"|std::string year2 = "2017"|g' tmvaMon.cc
	@sed -i 's|^.*\(vbs_jets_pt));\)|    TCut allCuts         ("allCuts",     (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' tmvaMon.cc
	@sed -i 's|^.*\(ZeppWHlt3));\)|//    TCut allCuts        ("allCuts",    (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' tmvaMon.cc
	@sed -i 's|^.*\(vbs_jets_pt));\)|TCut allCuts            ("allCuts",                (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' vbsTMVA.hpp
	@sed -i 's|^.*\(ZeppWHlt3));\)|//TCut allCuts                ("allCuts",             (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' vbsTMVA.hpp

update_2018:
	@sed -i 's|chain2tree("otree",|chain2tree("Events",|g' vbsTMVAClassification.cc
	@sed -i 's|int year = [0-9]\{4\}|int year = 2018|g' tmvaMon.cc
	@sed -i 's|std::string year2 = "[0-9]\{4\}"|std::string year2 = "2018"|g' tmvaMon.cc
	@sed -i 's|^.*\(vbs_jets_pt));\)|    TCut allCuts         ("allCuts",     (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' tmvaMon.cc
	@sed -i 's|^.*\(ZeppWHlt3));\)|//    TCut allCuts        ("allCuts",    (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' tmvaMon.cc
	@sed -i 's|^.*\(vbs_jets_pt));\)|TCut allCuts            ("allCuts",                (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' vbsTMVA.hpp
	@sed -i 's|^.*\(ZeppWHlt3));\)|//TCut allCuts                ("allCuts",             (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' vbsTMVA.hpp

update_0000:
	@sed -i 's|chain2tree("Events",|chain2tree("otree",|g' vbsTMVAClassification.cc
	@sed -i 's|int selector = [0-9]\{4\}|int selector = 0000|g' vbsTMVAClassification.cc
	@sed -i 's|int year = [0-9]\{4\}|int year = 0000|g' tmvaMon.cc
	@sed -i 's|plots/[0-9]\{4\}/c1_[0-9]\{4\}|plots/0000/c1_0000|g' tmvaMon.cc
	@sed -i 's|plots/[0-9]\{4\}/c2_[0-9]\{4\}|plots/0000/c2_0000|g' tmvaMon.cc
	@sed -i 's|plots/[0-9]\{4\}/c3_[0-9]\{4\}|plots/0000/c3_0000|g' tmvaMon.cc
	@sed -i 's|string selector = .*\(;\)|string selector = "old";|g' tmvaMon.cc	
	@sed -i 's|^.*\(vbs_jets_pt));\)|//    TCut allCuts         ("allCuts",     (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' tmvaMon.cc
	@sed -i 's|^.*\(ZeppWHlt3));\)|    TCut allCuts        ("allCuts",    (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' tmvaMon.cc
	@sed -i 's|^.*\(vbs_jets_pt));\)|//TCut allCuts            ("allCuts",                (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' vbsTMVA.hpp
	@sed -i 's|^.*\(ZeppWHlt3));\)|TCut allCuts                ("allCuts",             (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' vbsTMVA.hpp


