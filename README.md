# VBS Analysis
## Notes
This is still very much a work in progress.

### Current tasks
   * Improve results for the 2016-2018 ntuples
   * Improve the selection of TMVA variables for the 2016-2018 ntuples
### Upcoming tasks
   * Expanding the TMVA methods used on the analysis

## How to use the framework
There's a Makefile that should hopefully take care of setting everything up and running it properly. I run the framework on Windows 10 WSL2 using Ubuntu 20.04 with ROOT installed in a virtual environment called "root_env". You'll need to update the Makefile according to your system to get it to work properly. There's two ways to run things: either using the Makefile, or manually run each piece of code one after another. The Makefile is handy because the ````update_year```` target will update all of the files automatically. Instrustions for both methods are provided.

### The Makefile way
The first thing to do when using the Makefile is to run the init target

>`make help`

This will give you a list of the variables you can use in the Makefile, as well as the targets you can run. Once you know what you want to do with the framework you can run the target with the appropriate variables. To run the whole thing from start to finish over, for example, the 2016 ntuples

>`make trainAndPlot loc="location/of/ntuples year="2016" vars="set2016" methods="BDT" lumi="35.867" cut="dummy" cutName="test"`

Assuming everything is set up properly the first thing it will do is run the `update_year` target. This target will automatically rewrite certain lines of code in the framework so that it works on the files you want. It then will run `dsw.sh` which does a system check and steps up all of the links to the data. Then `write_vbsDL.sh` will run which will read all of the branches from one of the ntuples and write their names all to a file. It will also write a few more files that the framework will need. Next it will run the `vbsTMVAClassification.cc` macro which trains the model, followed by the `vbsTMVAClassificationApplication.cc` macro which applies the model. Then it makes sure `tmvaMon.cc` is able to run the `cplots()` command in the `tmvaMon()` function, by making sure it's not commented out. Next it runs the `tmvaMon.cc` macro which takes a while and generates 3 sets of 3x3 plots that get saved in the plots folder. Then it sorts all of the plots that have been made so that all of the most recent plots are in one folder and writes a .tex file that includes all of the plots in the plots folder. Finally the .tex file gets built and you have a .pdf full of the plots that were just made.

### The manual way
  * First make sure everything that needs to be updated is updated. There's a lot of awkward spots where switching can take place. Be careful of that. It might help to check the ````update_year```` section of the Makefile to see what needs to be altered by hand.
  * Check the "skims" folder for a linked folder called "vbs_ww" if it's there delete it. It's set to do that in one of the scripts, but it doesn't always work, best bet is to manually do this everytime you make changes to the dsw script and rerun it. 
  * If you're on windows WSL make sure your conda root environment is active. If you're on native linux you should be fine.
  * Run the following code
  >````./dsw.sh "location/of/ntuples" "year"````
  
  where the year is one of the following (0000, 2016, 2017, 2018)
  >`./write_vbsDL.sh "location/of/ntuples" "TMVAvars"` 
  
  where the TMVAvars is which set of variables TMVA will look at (Currently options are set2016-set2018 and old, but you can add more sets if needed) 
  >`root -b -q ./vbsTMVAClassification.cc\(\"vbs_ww_year\",\"BDT\"\)` 
  
  trains the model - where year is the dataset year (same as above), and BDT is whichever MVA method you want to use (can just be BDT or more can be added) 
  >`root -b -q ./vbsTMVAClassificationApplication.cc\(\"vbs_ww_year\",\"BDT\"\)` 
  
  Applies the model
  >`root -l tmvaMon.cc\(\"vbs_ww_year\",lumi,cut,\"cutName\"\)` 

  Analyze the output root file - year is same as above, lumi is the Luminosity (in fb^-1) for that year's dataset (0000 & 2016: 35.867, 2017: 41.530, 2018: 59.740), cut is the cut you want to apply to the plots, and cutName is the name as a string for labeling the plots as they get saved.
  >`tmgui()` 
  
  Check the results of the TMVA plots
  >`plotvar(anl, "lep1_pt", tmvasel+allCuts,  1.0, 1, 1,  -1., 1.3, 0.05,   1, 0, "VBS (WV), 35.9 fb^{-1}", "lep1_pt", "Events/bin");` 
  
  example command to make a plot with particular cuts and make it look nice. Check tmvaMon.cc for what each argument is
  >`cplots(anl)` or `cplots(anl, cut, cutName)` 
  
  if instead of one single plot like `plotvar()` gives you want to plot 27 variables across 3 canvases in a 3x3 grid. Make sure the `cplots()` command is commented out in the `tmvaMon()` function in the tmvaMon.cc file otherwise you'll be getting these plots whether you want them or not. 

### General things to update for your analysis

   * The old framework pulled things like luminosity and cross sections from a text file that had that information. The newer version pulls that data from a .json file. The .json file is much easier for a human to read, but a lot more tedious to pull data from in bash. You have to add the exactly correct number of columns so that anytime you pull data using `awk` you get the correct column. The update only happened beacuse .json files were provided so instead of writing 3 .txt files with the data I rewrote the old .txt as a .json. You can use whatever file and method you prefer, it's needed to implement the cross section data in the dsw script


## Running the analysis on CMS LPC
For this particular analysis the ntuples are stored at **/eos/uscms/store/user/rsingh/wv_vbs_ntuples/WVJJTree_2020_Dec_12/** in three sub folders **<2016, 2017, 2018>**

Things should be run from your workspace or data folder, running root directly in the EOS system is frowned upon.
