# Need to specify bash in order for conda activate to work.
SHELL=/bin/bash
# Note that the extra activate is needed to ensure that the activate floats env to the front of PATH
CONDA_ACTIVATE=source $$(conda info --base)/etc/profile.d/conda.sh ; conda activate ; conda activate

loc ?= "g/Research/ntuples/NEW/2016/haddedFiles"
year ?= "2016"
vars ?= "set1"
methods ?= "BDT"
lumi ?= 35.867
cut ?= "dummy"
cutName ?= "test"
pltVar ?= "lep1_pt"
saveFile ?= "$(year)"

help:
	@echo ""
	@echo "-------------------------------------------------------- Makefile Arguments --------------------------------------------------------"
	@echo ""
	@echo "loc ----- location of the .root data files			 |	methods - TMVA methods (Fisher, BDT, DNN_GPU, MLPBFGS, etc.)"
	@echo "vars ---- variable set (set1, etc., old)			 |	lumi ---- (2016 -> 35.867) | (2017 -> 41.53) | (2018 -> 59.74)"
	@echo "year ---- (2016, 2017, 2018)					 |	varName - The name of the variable to be plotted"
	@echo "cut ----- the cut you want to apply for the plots		 |	cutName - Used for labeling the plots in the saved PDF"
	@echo ""
	@echo "--------------------------------------------------------- Makefile targets ---------------------------------------------------------"
	@echo ""
	@echo "If you want to train and output plots:				 |	If you want to train but not create plots:"
	@echo "---- trainAndPlot - loc, year, vars, methods, lumi, cut, cutName |	---- train - loc, year, vars, methods, saveFile"
	@echo "								 |	"
	@echo "If you just want to make and save the cplots			 |	If you just want to run the tmvaMon program and make individual plots"
	@echo "---- plots - year, lumi, cut, cutName, saveFile		 	 |	---- mon - year, lumi, cut, cutName, saveFile"
	@echo " 								 |"
	@echo "If you want to plot a single var at a time 			 |	If you just want to train without applying"
	@echo "---- singlePlot - year, lumi, cut, cutName, varName		 |	---- classify - loc, year, vars, methods, cutName, saveFile"
	@echo " 								 |	"
	@echo "NOTE: Add _wsl to each of these target names if running using ROOT in a CONDA environment" 
	@echo ""

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

init:
	-@rm -r skims/vbs_ww
	@./dsw.sh "$(loc)" "$(year)"
	@./write_vbsDL.sh "$(loc)" "$(vars)" "$(year)"
	@echo "Done!"

classify: update_$(year)
	-@rm -r skims/vbs_ww
	@./dsw.sh "$(loc)" "$(year)"
	@./write_vbsDL.sh "$(loc)" "$(vars)" "$(year)"
#	@sed -i 's|^.*\(.txt"; // AUCoutfile\)|  ssAUCoutfile << "ROC/" << std::to_string(selector) << "_$(cutName).txt"; // AUCoutfile|g' vbsTMVAClassification.C
	@sed -i 's|^.*\(.txt"; // AUCoutfile\)|  ssAUCoutfile << "ROC/" << "$(saveFile).txt"; // AUCoutfile|g' vbsTMVAClassification.C
	@root ./vbsTMVAClassification.C\(\"vbs_ww_$(saveFile)\",\"$(methods)\"\)

train: update_$(year)
	-@rm -r skims/vbs_ww
	@./dsw.sh "$(loc)" "$(year)"
	@./write_vbsDL.sh "$(loc)" "$(vars)" "$(year)"
	@sed -i 's|^.*\(.txt"; // AUCoutfile\)|  ssAUCoutfile << "ROC/" << "$(saveFile).txt"; // AUCoutfile|g' vbsTMVAClassification.C
#	@sed -i 's|^.*\("; // cut_name - keep this comment\)|  TString cut_name = "$(cutName)"; // cut_name - keep this comment|g' vbsTMVAClassification.C
	@root -b -q ./vbsTMVAClassification.C\(\"vbs_ww_$(saveFile)\",\"$(methods)\"\)
	@root -b -q ./vbsTMVAClassificationApplication.C\(\"vbs_ww_$(saveFile)\",\"$(methods)\"\)
	@sed -i 's|^.*\(cplots(anl, cut, cutName); // XXX\)|//cplots(anl, cut, cutName); // XXX|g' tmvaMon.cpp

trainAndPlot: update_$(year)
	-@rm -r skims/vbs_ww
	@./dsw.sh "$(loc)" "$(year)"
	@./write_vbsDL.sh "$(loc)" "$(vars)" "$(year)"
	@sed -i 's|^.*\(cplots(anl, cut, cutName); // XXX\)|cplots(anl, cut, cutName); // XXX|g' tmvaMon.cpp    
	@sed -i 's|^.*\(shapePlots(anl, cut, cutName); // XXX\)|//shapePlots(anl, cut, cutName); // XXX|g' tmvaMon.cpp
	@sed -i 's|^.*\(.txt"; // AUCoutfile\)|  ssAUCoutfile << "ROC/" << "$(saveFile).txt"; // AUCoutfile|g' vbsTMVAClassification.C
	@root -b -q ./vbsTMVAClassification.C\(\"vbs_ww_$(saveFile)\",\"$(methods)\"\)
	@root -b -q ./vbsTMVAClassificationApplication.C\(\"vbs_ww_$(saveFile)\",\"$(methods)\"\)
	@root -q tmvaMon.cpp\(\"vbs_ww_$(saveFile)\",$(lumi),$(cut),\"$(cutName)\"\)
	-@./utils/plot_resort.sh "$(year)"
	@./utils/gen_plots.sh

plots: update_$(year)
	@sed -i 's|^.*\(cplots(anl, cut, cutName); // XXX\)|cplots(anl, cut, cutName); // XXX|g' tmvaMon.cpp
	@sed -i 's|^.*\(shapePlots(anl, cut, cutName); // XXX\)|//shapePlots(anl, cut, cutName); // XXX|g' tmvaMon.cpp
	-@./utils/plot_sort.sh "$(year)"
	@root -q tmvaMon.cpp\(\"vbs_ww_$(saveFile)\",$(lumi),$(cut),\"$(cutName)\"\)
	-@./utils/plot_resort.sh "$(year)"
	@./utils/gen_plots.sh

shapePlots: update_$(year)
	@sed -i 's|^.*\(cplots(anl, cut, cutName); // XXX\)|//cplots(anl, cut, cutName); // XXX|g' tmvaMon.cpp
	@sed -i 's|^.*\(shapePlots(anl, cut, cutName); // XXX\)|shapePlots(anl, cut, cutName); // XXX|g' tmvaMon.cpp
	-@./utils/plot_sort.sh "$(year)"
	@root -q tmvaMon.cpp\(\"vbs_ww_$(saveFile)\",$(lumi),$(cut),\"$(cutName)\"\)
	-@./utils/plot_resort.sh "$(year)"
	@./utils/gen_shape_plots.sh

mon: update_$(year)
	@sed -i 's|^.*\(cplots(anl, cut, cutName); // XXX\)|//cplots(anl, cut, cutName); // XXX|g' tmvaMon.cpp
	@sed -i 's|^.*\(shapePlots(anl, cut, cutName); // XXX\)|//shapePlots(anl, cut, cutName); // XXX|g' tmvaMon.cpp
	-@./utils/plot_sort.sh "$(year)"
	@echo "Don't forget to run the plot_resort.sh script after generating new plots"
	@root tmvaMon.cpp\(\"vbs_ww_$(saveFile)\",$(lumi),$(cut),\"$(cutName)\"\)
	

genPlots:
	@./utils/gen_plots.sh

# ----------------------------------------------------------------------------------------------------------------------------------------
# These makefile targets are for when make is run in a conda environment. They need the special CONDA_ACTIVATE command so root can be used
# vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

classify_wsl: update_$(year)
	-@rm -r skims/vbs_ww
	@./dsw.sh "$(loc)" "$(year)"
	@($(CONDA_ACTIVATE) root_env ; ./write_vbsDL.sh "$(loc)" "$(vars)" "$(year)")
	@sed -i 's|^.*\(.txt"; // AUCoutfile\)|  ssAUCoutfile << "ROC/" << "$(saveFile).txt"; // AUCoutfile|g' vbsTMVAClassification.C
	@($(CONDA_ACTIVATE) root_env ; root -b -q ./vbsTMVAClassification.C\(\"vbs_ww_$(saveFile)\",\"$(methods)\"\))

trainNoPlot_wsl: update_$(year)
	@rm -r skims/vbs_ww
	@./dsw.sh "$(loc)" "$(year)"
	@sed -i 's|^.*\(.txt"; // AUCoutfile\)|  ssAUCoutfile << "ROC/" << "$(saveFile).txt"; // AUCoutfile|g' vbsTMVAClassification.C
	@($(CONDA_ACTIVATE) root_env ; ./write_vbsDL.sh "$(loc)" "$(vars)" "$(year)")
	@($(CONDA_ACTIVATE) root_env ; root -b -q ./vbsTMVAClassification.C\(\"vbs_ww_$(saveFile)\",\"$(methods)\"\))
	@($(CONDA_ACTIVATE) root_env ; root -b -q ./vbsTMVAClassificationApplication.C\(\"vbs_ww_$(saveFile)\",\"$(methods)\"\))
	@sed -i 's|^.*\(cplots(anl, cut, cutName); // XXX\)|//cplots(anl, cut, cutName); // XXX|g' tmvaMon.cpp

trainAndPlot_wsl: update_$(year)
	@rm -r skims/vbs_ww
	@./dsw.sh "$(loc)" "$(year)"
	@sed -i 's|^.*\(.txt"; // AUCoutfile\)|  ssAUCoutfile << "ROC/" << "$(saveFile).txt"; // AUCoutfile|g' vbsTMVAClassification.C
	@($(CONDA_ACTIVATE) root_env ; ./write_vbsDL.sh "$(loc)" "$(vars)" "$(year)")
	@($(CONDA_ACTIVATE) root_env ; root -b -q ./vbsTMVAClassification.C\(\"vbs_ww_$(saveFile)\",\"$(methods)\"\))
	@($(CONDA_ACTIVATE) root_env ; root -b -q ./vbsTMVAClassificationApplication.C\(\"vbs_ww_$(saveFile)\",\"$(methods)\"\))
	@sed -i 's|^.*\(cplots(anl, cut, cutName); // XXX\)|cplots(anl, cut, cutName); // XXX|g' tmvaMon.cpp
	-@./utils/plot_sort.sh "$(year)"
	@($(CONDA_ACTIVATE) root_env ; root -q tmvaMon.cpp\(\"vbs_ww_$(saveFile)\",$(lumi),$(cut),\"$(cutName)\"\))
	-@./utils/plot_resort.sh "$(year)"
	@./utils/gen_plots.sh

plots_wsl: update_$(year)
	@sed -i 's|^.*\(cplots(anl, cut, cutName); // XXX\)|cplots(anl, cut, cutName); // XXX|g' tmvaMon.cpp
	-@./utils/plot_sort.sh "$(year)"
	@($(CONDA_ACTIVATE) root_env ; root -q tmvaMon.cpp\(\"vbs_ww_$(saveFile)\",$(lumi),$(cut),\"$(cutName)\"\))
	-@./utils/plot_resort.sh "$(year)"
	@./utils/gen_plots.sh

shapePlots_wsl: update_$(year)
	@sed -i 's|^.*\(cplots(anl, cut, cutName); // XXX\)|//cplots(anl, cut, cutName); // XXX|g' tmvaMon.cpp
	@sed -i 's|^.*\(shapePlots(anl, cut, cutName); // XXX\)|shapePlots(anl, cut, cutName); // XXX|g' tmvaMon.cpp
	-@./utils/plot_sort.sh "$(year)"
	@($(CONDA_ACTIVATE) root_env ; root -q tmvaMon.cpp\(\"vbs_ww_$(saveFile)\",$(lumi),$(cut),\"$(cutName)\"\)
	-@./utils/plot_resort.sh "$(year)"
	@./utils/gen_shape_plots.sh

mon_wsl: update_$(year)
	@sed -i 's|^.*\(cplots(anl, cut, cutName); // XXX\)|//cplots(anl, cut, cutName); // XXX|g' tmvaMon.cpp
	-@./utils/plot_sort.sh "$(year)"
	@echo "Don't forget to run the plot_resort.sh script after generating new plots"
	@($(CONDA_ACTIVATE) root_env ; root tmvaMon.cpp\(\"vbs_ww_$(saveFile)\",$(lumi),$(cut),\"$(cutName)\"\))

# ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
# These makefile targets are for when make is run in a conda environment. They need the special CONDA_ACTIVATE command so root can be used
# ----------------------------------------------------------------------------------------------------------------------------------------

# --------------------------------------------------------------------------------------------------------------------------
#                 These makefile targets update the different files for whichever year specified
#                 vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

update_2016: 
	@sed -i 's|chain2tree("otree",|chain2tree("Events",|g' vbsTMVAClassification.C
	@sed -i 's|TCut mycuts = [A-z]\++[A-z]\+;|TCut mycuts = cleanNAN_qgid+cleanNAN_tau;|g' vbsTMVAClassification.C
	@sed -i 's|int selector = [0-9]\{4\}|int selector = 2016|g' vbsTMVAClassification.C
	@sed -i 's|int year = [0-9]\{4\}|int year = 2016|g' tmvaMon.cpp
	@sed -i 's|std::string year = "[0-9]\{4\}"|std::string year = "2016"|g' tmvaMon.cpp
	@sed -i 's|string selector = .*\(;\)|string selector = "new";|g' tmvaMon.cpp
	@sed -i 's|^.*\(vbs_jets_pt));\)|    TCut allCuts         ("allCuts",     (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' tmvaMon.cpp
	@sed -i 's|^.*\(ZeppWHlt3));\)|//    TCut allCuts        ("allCuts",    (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' tmvaMon.cpp
	@sed -i 's|^.*\(vbs_jets_pt));\)|TCut allCuts            ("allCuts",                (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' vbsTMVA.hpp
	@sed -i 's|^.*\(ZeppWHlt3));\)|//TCut allCuts                ("allCuts",             (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' vbsTMVA.hpp
	@sed -i 's|wtot.*\(\*\)|wtot_2016*|g' tmvaMon.cpp
	@sed -i 's|wtot.*\(,stats\)|wtot_2016,stats|g' vbsTMVA.hpp



update_2017:
	@sed -i 's|chain2tree("otree",|chain2tree("Events",|g' vbsTMVAClassification.C
	@sed -i 's|TCut mycuts = [A-z]\++[A-z]\+;|TCut mycuts = cleanNAN_qgid+cleanNAN_tau;|g' vbsTMVAClassification.C
	@sed -i 's|int selector = [0-9]\{4\}|int selector = 2017|g' vbsTMVAClassification.C
	@sed -i 's|int year = [0-9]\{4\}|int year = 2017|g' tmvaMon.cpp
	@sed -i 's|std::string year = "[0-9]\{4\}"|std::string year = "2017"|g' tmvaMon.cpp
	@sed -i 's|string selector = .*\(;\)|string selector = "new";|g' tmvaMon.cpp
	@sed -i 's|^.*\(vbs_jets_pt));\)|    TCut allCuts         ("allCuts",     (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' tmvaMon.cpp
	@sed -i 's|^.*\(ZeppWHlt3));\)|//    TCut allCuts        ("allCuts",    (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' tmvaMon.cpp
	@sed -i 's|^.*\(vbs_jets_pt));\)|TCut allCuts            ("allCuts",                (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' vbsTMVA.hpp
	@sed -i 's|^.*\(ZeppWHlt3));\)|//TCut allCuts                ("allCuts",             (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' vbsTMVA.hpp
	@sed -i 's|wtot.*\(\*\)|wtot_2017*|g' tmvaMon.cpp
	@sed -i 's|wtot.*\(,stats\)|wtot_2017,stats|g' vbsTMVA.hpp


update_2018:
	@sed -i 's|chain2tree("otree",|chain2tree("Events",|g' vbsTMVAClassification.C
	@sed -i 's|TCut mycuts = [A-z]\++[A-z]\+;|TCut mycuts = cleanNAN_qgid+cleanNAN_tau;|g' vbsTMVAClassification.C
	@sed -i 's|int selector = [0-9]\{4\}|int selector = 2018|g' vbsTMVAClassification.C
	@sed -i 's|int year = [0-9]\{4\}|int year = "2018"|g' tmvaMon.cpp
	@sed -i 's|std::string year = "[0-9]\{4\}"|std::string year = 2018|g' tmvaMon.cpp
	@sed -i 's|string selector = .*\(;\)|string selector = "new";|g' tmvaMon.cpp
	@sed -i 's|^.*\(vbs_jets_pt));\)|    TCut allCuts         ("allCuts",     (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' tmvaMon.cpp
	@sed -i 's|^.*\(ZeppWHlt3));\)|//    TCut allCuts        ("allCuts",    (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' tmvaMon.cpp
	@sed -i 's|^.*\(vbs_jets_pt));\)|TCut allCuts            ("allCuts",                (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' vbsTMVA.hpp
	@sed -i 's|^.*\(ZeppWHlt3));\)|//TCut allCuts                ("allCuts",             (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' vbsTMVA.hpp
	@sed -i 's|wtot.*\(\*\)|wtot_2018*|g' tmvaMon.cpp
	@sed -i 's|wtot.*\(,stats\)|wtot_2018,stats|g' vbsTMVA.hpp


update_0000:
	@sed -i 's|chain2tree("Events",|chain2tree("otree",|g' vbsTMVAClassification.C
	@sed -i 's|TCut mycuts = [A-z]\+;|TCut mycuts = cleanNAN+cleanNAN_phi;|g' vbsTMVAClassification.C
	@sed -i 's|int selector = [0-9]\{4\}|int selector = 0000|g' vbsTMVAClassification.C
	@sed -i 's|int year = [0-9]\{4\}|int year = 0000|g' tmvaMon.cpp
	@sed -i 's|plots/[0-9]\{4\}/c1_[0-9]\{4\}|plots/0000/c1_0000|g' tmvaMon.cpp
	@sed -i 's|plots/[0-9]\{4\}/c2_[0-9]\{4\}|plots/0000/c2_0000|g' tmvaMon.cpp
	@sed -i 's|plots/[0-9]\{4\}/c3_[0-9]\{4\}|plots/0000/c3_0000|g' tmvaMon.cpp
	@sed -i 's|string selector = .*\(;\)|string selector = "old";|g' tmvaMon.cpp	
	@sed -i 's|^.*\(vbs_jets_pt));\)|//    TCut allCuts         ("allCuts",     (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' tmvaMon.cpp
	@sed -i 's|^.*\(ZeppWHlt3));\)|    TCut allCuts        ("allCuts",    (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' tmvaMon.cpp
	@sed -i 's|^.*\(vbs_jets_pt));\)|//TCut allCuts            ("allCuts",                (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));|g' vbsTMVA.hpp
	@sed -i 's|^.*\(ZeppWHlt3));\)|TCut allCuts                ("allCuts",             (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));|g' vbsTMVA.hpp
	@sed -i 's|wtot.*\(\*\)|wtot_old*|g' tmvaMon.cpp
	@sed -i 's|wtot.*\(,stats\)|wtot_old,stats|g' vbsTMVA.hpp

#                 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#                 These makefile targets update the different files for whichever year specified
# -----------------------------------------------------------------------------------------------------------------

# -----------------------------------------------------------------------------------------------------------------
#                                                This is junk
#                                                vvvvvvvvvvvv

# 	@sed -i 's|//cplots(anl, cut, cutName); // XXX|cplots(anl, cut, cutName); // XXX|g' tmvaMon.cpp
#    newhist = (TH1F*) hframe->Clone(histname); TCut allCuts         ("allCuts",     (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));
#    newhist = (TH1F*) hframe->Clone(histname); TCut allCuts        ("allCuts",    (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));
#	@pdflatex docs/plots.text >/dev/null
# 	@sed -i 's|string smpselector = .*\(;\)|string smpselector = "new";|g' tmvaMon.cpp

# Not sure what happened with this line here v it was somehow in the first sed in trainAndPlot
# //cout << "Deleted old hist " <<  newhist->GetName() << endl;'
#	@sed -i 's|plots/[0-9]\{4\}/c1_[0-9]\{4\}|plots/2016/c1_2016|g' tmvaMon.cpp
#	@sed -i 's|plots/[0-9]\{4\}/c2_[0-9]\{4\}|plots/2016/c2_2016|g' tmvaMon.cpp
#	@sed -i 's|plots/[0-9]\{4\}/c3_[0-9]\{4\}|plots/2016/c3_2016|g' tmvaMon.cpp
#	@sed -i 's|plots/[0-9]\{4\}/c4_[0-9]\{4\}|plots/2016/c4_2016|g' tmvaMon.cpp
#	@sed -i 's|plots/[0-9]\{4\}/s1_[0-9]\{4\}|plots/2016/s1_2016|g' tmvaMon.cpp
#	@sed -i 's|plots/[0-9]\{4\}/s2_[0-9]\{4\}|plots/2016/s2_2016|g' tmvaMon.cpp
#	@sed -i 's|plots/[0-9]\{4\}/s3_[0-9]\{4\}|plots/2016/s3_2016|g' tmvaMon.cpp
#	@sed -i 's|plots/[0-9]\{4\}/s4_[0-9]\{4\}|plots/2016/s4_2016|g' tmvaMon.cpp
