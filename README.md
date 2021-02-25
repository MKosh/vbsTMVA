# VBS Analysis
## Notes
This is still very much a work in progress. It is an update for an existing analysis framework. The framework was already very automated, hopefully I can extend that so the user needs to do minimal updates for new runs and different data sets.

### Current tasks
   * Getting the TMVA step to run on my local machine with older ntuples.
   * Getting TMVA plot outputs
   
### Upcoming tasks
   * Determining Spectators/Variables in the newer ntuples
   * Updating the TMVA step to run on the CMS LPC with the newer ntuples
   * Examining the actual analysis steps and making updates

## Things to update for future analysis
The first thing to update is the dsw.sh script
   * It's set to check the system you're running things on. Either CMS-LPC, NICADD, or a personal machine. Make sure to look over that section and point the script to the proper places for the root files.

The next thing to update is to run the "write_vbsDL.sh"

   * Update variables
        * rootFiles - Point it to the folder where the files are held
        * subFolders - If the data is seperated (in this case by year)
        * As of now you can select between old and new files by adding arguments "old" or "new"

 vbsTMVAClassification.C
   * `Samples.push_back( new Sample(...))`
     * The proper ones need to be commented out/included. Check *vbsSamples.cpp* for which is which 

General things to update

   * The old framework pulled things like luminosity and cross sections from a text file that had that information. The newer version pulls that data from a .json file. The .json file is much easier to read, but a lot more tedious to pull data from in bash. The update only happened beacuse .json files were provided that were almost complete, but some manual manipulation was needed to get them to have all the needed information and to be able to pull the data from. You can use whatever file and method you prefer, it's needed to implement the cross section data in the dsw script

## How to use the framework
  * First make sure everything that needs to be updated is updated. As of right now the framework is at an in between stage where I need to switch between the old data and the new, so there's a lot of awkward spots where switching can take place. Be careful of that.
  * Check the "skims" folder for a linked folder called "vbs_ww" if it's there delete it. Currently you'll need to do this everytime you make changes to the dsw script and rerun it. 
  * If you're on windows WSL make sure your conda root environment is active. If you're on native linux you should be fine.
  * Run the following code
  *  ````./dsw.sh "new"```` or `./dsw.sh "old"`
  * `./write_vbsDL.sh "new"` or `./write_vbsDL.sh "old"`
  * `root -b -q ./vbsTMVAClassification.C\(\"vbs_ww\",\"BDT\"\)` trains the model
  * `root -b -q ./vbsTMVAClassificationApplication.C\(\"vbs_ww\",\"BDT\"\)` Applies the model
  * `root -l tmvaMon.cpp\(\"vbs_ww\"\)` Analyze the output root file
  * `tmgui()` Check the results of the TMVA plots
  * `plotvar(anl, "BDT", tmvasel+allCuts,  1.0, 1, 1,  -1., 1.3, 0.05,   1, 0, "VBS (WV), 35.9 fb^{-1}", "BDT", "Events/bin");` example command to make a plot with particular cuts and make it look nice. Currently these plots don't quite work with the new ntuples.

## Running the analysis on CMS LPC
For this particular analysis the ntuples are stored at **/eos/uscms/store/user/rsingh/wv_vbs_ntuples/WVJJTree_2020_Dec_12/** in three sub folders **<2016, 2017, 2018>**

Things should be run from your workspace or data folder, running root directly in the EOS system is frowned upon.
