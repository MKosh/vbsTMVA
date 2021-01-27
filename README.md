# VBS Analysis
## Notes
This is still very much a work in progress. It is an update for an existing analysis framework. Filenames are a bit screwy because it's at the in between phase where I'm finding all of the things that need to be updated.

The framework was already very automated, hopefully I can extend that so the user needs to do minimal updates for new runs and different data sets.

### Current tasks
   * Getting the TMVA step to run on my local machine with older ntuples.
   
### Upcoming tasks
   * Determining Spectators/Variables in the newer ntuples
   * Updating the TMVA step to run on the CMS LPC with the newer ntuples
   * Examining the actual analysis steps and making updates

## Things to update for future analysis
One of the first steps is to run the "write_list_macro.sh"

   * Update variables
        * rootFiles - Point it to the folder where the files are held
        * subFolders - If the data is seperated (in this case by year)
        * Check all file locations used in the block that writes to the macroFile variables
            * locations

After that script run *this particular file*

   * Here's what you need to update in that file
   
## Running the analysis on CMS LPC
For this particular analysis the ntuples are stored at **/eos/uscms/store/user/rsingh/wv_vbs_ntuples/WVJJTree_2020_Dec_12/** in three sub folders **<2016, 2017, 2018>**

Things should be run from your workspace or data folder, running root directly in the EOS system is frowned upon.
