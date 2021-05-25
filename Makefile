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

init:
	@echo "-------------------------------------------------------- Makefile Arguments --------------------------------------------------------"
	@echo "loc ----- location of the .root data files				methods - TMVA methods (Fisher, BDT, DNN_GPU, etc.)"
	@echo "vars ---- variable set (set1, etc., old)				lumi ---- 2016 -> 35.867 | 2017 -> 41.53 | 2018 -> 59.74"
	@echo "year ---- (2016, 2017, 2018)"
	@echo "cut ----- the cut you want to apply for the plots			cutName - The name of the cut applied (used for labeling)"
	@echo "--------------------------------------------------------- Makefile targets ---------------------------------------------------------"
	@echo "If you want plots:"
	@echo "	trainAndPlot - loc, year, vars, methods, lumi, cut, cutName"
	@echo "If you don't want plots:"
	@echo "	trainNoPlot - loc, year, vars, methods, lumi, cut, cutName"

trainNoPlot: update_$(year)
	@cd skims/
	@rm -r vbs_ww
	@cd ..
	@./dsw.sh "$(loc)" "$(year)"
	@./write_vbsDL.sh "$(loc)" "$(vars)"
	@($(CONDA_ACTIVATE) root_env ; root -b -q ./vbsTMVAClassification.C\(\"vbs_ww_$(year)\",\"$(methods)\"\)
	@($(CONDA_ACTIVATE) root_env ; root -b -q ./vbsTMVAClassificationApplication.C\(\"vbs_ww_$(year)\",\"$(methods)\"\)
	@sed -i 's|cplots(anl, cut, cutName); // XXX|//cplots(anl, cut, cutName); // XXX|g' tmvaMon.cpp
	@($(CONDA_ACTIVATE) root_env ; root -q tmvaMon.cpp\(\"vbs_ww_$(year)\",$(lumi),$(cut),\"$(cutName)\"\)

trainAndPlot: update_$(year)
	@cd skims/
	@rm -r vbs_ww
	@cd ..
	@./dsw.sh "$(loc)" "$(year)"
	@./write_vbsDL.sh "$(loc)" "$(vars)"
	@($(CONDA_ACTIVATE) root_env ; root -b -q ./vbsTMVAClassification.C\(\"vbs_ww_$(year)\",\"$(methods)\"\)
	@($(CONDA_ACTIVATE) root_env ; root -b -q ./vbsTMVAClassificationApplication.C\(\"vbs_ww_$(year)\",\"$(methods)\"\)
	@sed -i 's|//cplots(anl, cut, cutName); // XXX|cplots(anl, cut, cutName); // XXX|g' tmvaMon.cpp
	@($(CONDA_ACTIVATE) root_env ; root -q tmvMon.cpp\(\"vbs_ww_$(year)\",$(lumi),$(cut),\"$(cutName)\"\)
	
tmvaMon.cpp: vbsTMVAClassificationApplication.C
	@($(CONDA_ACTIVATE) root_env ; root -b -q ./vbsTMVAClassificationApplication.C\(\"vbs_ww_$(year)\",\"$(methods)\"\)
	
vbsTMVAClassificationApplication.C: vbsTMVAClassification.C
	@($(CONDA_ACTIVATE) root_env ; root -b -q ./vbsTMVAClassification.C\(\"vbs_ww_$(year)\",\"$(methods)\"\)

vbsTMVAClassification.C: write_vbsDL.sh
	@./write_vbsDL.sh "$(loc)" "$(vars)"

write_vbsDL.sh: dsw.sh
	cd skims/
	rm -r vbs_ww
	cd ..
	@./dsw.sh "$(loc)" "$(year)"

update_2016: 
	@sed -i 's|chain2tree("otree",|chain2tree("Events",|g' vbsTMVAClassification.C
	@sed -i 's|int selector = [0-9]\{4\}|int selector = 2016|g' vbsTMVAClassification.C
	@sed -i 's|plots/[0-9]\{4\}/c1_[0-9]\{4\}|plots/2016/c1_2016|g' tmvaMon.cpp
	@sed -i 's|plots/[0-9]\{4\}/c2_[0-9]\{4\}|plots/2016/c1_2016|g' tmvaMon.cpp
	@sed -i 's|plots/[0-9]\{4\}/c3_[0-9]\{4\}|plots/2016/c1_2016|g' tmvaMon.cpp

update_2017:
	@sed -i 's|chain2tree("otree",|chain2tree("Events",|g' vbsTMVAClassification.C
	@sed -i 's|int selector = [0-9]\{4\}|int selector = 2017|g' vbsTMVAClassification.C
	@sed -i 's|plots/[0-9]\{4\}/c1_[0-9]\{4\}|plots/2017/c1_2017|g' tmvaMon.cpp
	@sed -i 's|plots/[0-9]\{4\}/c2_[0-9]\{4\}|plots/2017/c1_2017|g' tmvaMon.cpp
	@sed -i 's|plots/[0-9]\{4\}/c3_[0-9]\{4\}|plots/2017/c1_2017|g' tmvaMon.cpp

update_2018:
	@sed -i 's|chain2tree("otree",|chain2tree("Events",|g' vbsTMVAClassification.C
	@sed -i 's|int selector = [0-9]\{4\}|int selector = 2018|g' vbsTMVAClassification.C
	@sed -i 's|plots/[0-9]\{4\}/c1_[0-9]\{4\}|plots/2018/c1_2018|g' tmvaMon.cpp
	@sed -i 's|plots/[0-9]\{4\}/c2_[0-9]\{4\}|plots/2018/c1_2018|g' tmvaMon.cpp
	@sed -i 's|plots/[0-9]\{4\}/c3_[0-9]\{4\}|plots/2018/c1_2018|g' tmvaMon.cpp

update_0000:
	@sed -i 's|chain2tree("Events",|chain2tree("otree",|g' vbsTMVAClassification.C
	@sed -i 's|int selector = [0-9]\{4\}|int selector = 0|g' vbsTMVAClassification.C
	@sed -i 's|plots/[0-9]\{4\}/c1_[0-9]\{4\}|plots/0000/c1_old|g' tmvaMon.cpp
	@sed -i 's|plots/[0-9]\{4\}/c2_[0-9]\{4\}|plots/0000/c1_old|g' tmvaMon.cpp
	@sed -i 's|plots/[0-9]\{4\}/c3_[0-9]\{4\}|plots/0000/c1_old|g' tmvaMon.cpp