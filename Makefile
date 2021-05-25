# Need to specify bash in order for conda activate to work.
SHELL=/bin/bash
# Note that the extra activate is needed to ensure that the activate floats env to the front of PATH
CONDA_ACTIVATE=source $$(conda info --base)/etc/profile.d/conda.sh ; conda activate ; conda activate

init:
	@echo "--- Arguments for the framework ---"
	@echo "loc ----- location of the .root data files"
	@echo "vars ---- variable set (old or new)"
	@echo "year ---- (2016, 2017, 2018)"
	@echo "methods - TMVA methods (Fisher, BDT, DNN_GPU, etc.)"
	@echo "lumi ---- 2016 -> 35.867 | 2017 -> 41.53 | 2018 -> 59.74" # integrated luminocity of the sample
	@echo "cut ----- the cut you want to apply for the plots"
	@echo "cutName - The name of the cut applied (used for labeling)"

all:
	@cd skims/
	@rm -r vbs_ww
	@cd ..
	@./dsw.sh "$(loc)" "$(vars)" "$(year)"
	@./write_vbsDL.sh "$(loc)" "$(vars)"
	@($(CONDA_ACTIVATE) root_env ; root -b -q ./vbsTMVAClassification.C\(\"vbs_ww_$(year)\",\"$(methods)\"\)
	@($(CONDA_ACTIVATE) root_env ; root -b -q ./vbsTMVAClassificationApplication.C\(\"vbs_ww_$(year)\",\"$(methods)\"\)
	@($(CONDA_ACTIVATE) root_env ; root -l tmvaMon.cpp\(\"vbs_ww_$(year)\",$(lumi),$(cut),\"$(cutName)\"\)

plots: update_$(year) tmvaMon.cpp
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
	@./dsw.sh "$(loc)" "$(vars)" "$(year)"

update_2016: 
	@cat vbsTMVAClassification.C | grep chain2tree | sed 's/"otree"/"Events"/g'
	@cat vbsTMVAClassification.C | grep "int selector = " | sed -e 's/[0-9][0-9][0-9][0-9];/2016/g'
	@cat tmvaMon.cpp | grep "outfname << \"plots" | sed 's/[0-9][0-9][0-9][0-9]/2016/g'

update_2017:
	@cat vbsTMVAClassification.C | grep chain2tree | sed 's/"otree"/"Events"/g'
	@cat vbsTMVAClassification.C | grep "int selector = " | sed -e 's/[0-9][0-9][0-9][0-9];/2017/g'
	@cat tmvaMon.cpp | grep "outfname << \"plots" | sed 's/[0-9][0-9][0-9][0-9]/2017/g'

update_2018:
	@cat vbsTMVAClassification.C | grep chain2tree | sed 's/"otree"/"Events"/g'
	@cat vbsTMVAClassification.C | grep "int selector = " | sed -e 's/[0-9][0-9][0-9][0-9];/2018/g'
	@cat tmvaMon.cpp | grep "outfname << \"plots" | sed 's/[0-9][0-9][0-9][0-9]/2018/g'

update_old:
	@cat vbsTMVAClassification.C | grep chain2tree | sed 's/"Events"/"otree"/g'
	@cat vbsTMVAClassification.C | grep "int selector = " | sed -e 's/[0-9][0-9][0-9][0-9];/0/g'
	@cat tmvaMon.cpp | grep "outfname << \"plots" | sed 's/[0-9][0-9][0-9][0-9]/old/g'
