#!/bin/bash
# script to run the macro for reading and writing the 
# list_of_branches.txt file
# Then uses that file to write the vbsReducedTree.hpp file
# and the vbsDL.hpp file

# --------------------------------------------------------- Start - Create write_list macro - Start -------------------------------------------------------------------

# Writes a macro file that reads in all of the root files in the folder
# rootFiles/subFolders, then writes a list of all of the names of the branches and their types

rootFiles="/mnt/e/Research/ntuples/" # Location of the ntuples 3 subfolders <2016, 2017, 2018>
subFolders=("2016" "2017" "2018") # For work on my local machine just use 2018

macroFile="write_list.C"
if [ -f $macroFile ]; then rm -f $macroFile; fi
touch $macroFile

echo "Creating $macroFile"
cat >> $macroFile << EOF
{
    #include <fstream>
    #include <vector>
    #include <string>

    std::vector<std::string> ntuples = {
EOF

# This block reads the names off all the files in the folder and adds them to the ntuples vector in $macroFile
for file in "$rootFiles"/2018/*; do # Only using 2018 for my local machine
    echo $file | sed "s@$rootFiles\/2018\/@@g" | sed 's/^/\"/g' | sed 's/$/\",/g' | cat >> $macroFile 
done

# Don't forget to update the string "location" to the correct folder
cat >> $macroFile << EOF
    };

    // string location="~/documents/ntuples/"; // on my personal laptop
    string location="/mnt/e/Research/ntuples/2018/"; // on my personal desktop
    //TFile *outfile = new TFile("var_list.txt", "RECREATE");
    std::ofstream ofs ("var_list.txt", std::ofstream::out);

    for (int i = 0; i<ntuples.size(); i++) {
        string infile = location+ntuples[i];
        TFile *input = new TFile(infile.c_str());
        TObjArray* brches = Events->GetListOfBranches();
        for (int iter = 0; iter <brches->GetEntries(); iter++) {
            ofs << brches->At(iter)->GetTitle() <<'\t' << brches->At(iter)->GetName() << ";" << std::endl;
        }
        input->Close();
    }
    
    ofs.close();

}
EOF

# --------------------------------------------------------- End - Create write_list macro - End -------------------------------------------------------------------

root -q .x write_list_branches.C

sort -u var_list.txt > branches.txt

rm var_list.txt

cat branches.txt | sed 's/[0-z]*\/I/Int_t/g' | sed 's/[0-z]*\/F/Float_t/g' | sed 's/[0-z]*\/O/Bool_t/g' > list_of_branches.txt

rm branches.txt



# --------------------------------------------------------- Start - Create the vbsReducedTree.hpp file - Start ----------------------------------------------------
outfile="vbsReducedTreeNew.hpp"

if [ -f $outfile ]; then rm -f $outfile; fi
echo "Creating $outfile"

# cat boiler plate things
cat >> $outfile << EOF
#ifndef vbsReducedTree_hpp
#define vbsReducedTree_hpp
//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Dec 18, 2020 by ROOT version 6.10/08
// from TTree otree/otree
// found on file: WWTree_ChargedHiggsToWZToLLQQ_M600_13TeV.root
//////////////////////////////////////////////////////////
//VbsReducedEvent structure (keeps variables of the VbsAnalysisReduced ntuple)
typedef struct {
//Additional branches - to be added
   Int_t           gid;                  // - group  ID
   Int_t           sid;                  // - sample ID
   Float_t         mcWeight;             //== xsect/ngen 
//
   // Declaration of leaf types

EOF

# cat all of the names of branches previously automatically generated
cat list_of_branches.txt >> $outfile

cat >> $outfile << EOF
} VbsReducedEvent;
//
//===================================================================================
void addBranches_vbsReducedTree(TTree* vbsTree, VbsReducedEvent& vbsEvent){
  // if(vbsTree->GetBranch( "gid")){
   cout << "Adding branches" << endl;
   vbsTree->Branch( "gid",                &vbsEvent.gid,              "gid/I");
   vbsTree->Branch( "sid",                &vbsEvent.sid,              "sid/I");
   vbsTree->Branch( "mcWeight",           &vbsEvent.mcWeight,         "mcWeight/F");
  //}
}
//=================================================================================== 
void arrange_vbsReducedTree(TTree* vbsTree, VbsReducedEvent& vbsEvent){
//Maps the vbsTree branches to members of local  vbsEvent structure
//Extra Branhes
//if(vbsTree->GetBranch( "gid") ) {
   cout << " Set extra branches" << endl;
      
    vbsTree->SetBranchAddress( "gid",                                      &vbsEvent.gid    );
    vbsTree->SetBranchAddress( "sid",                                      &vbsEvent.sid    );
    vbsTree->SetBranchAddress( "mcWeight",                                 &vbsEvent.mcWeight );
    cout << " Done Set extra branches" << endl;
EOF

while read line; do
two=$(echo $line | awk '{print $2}' | sed 's/;//g')
echo -e "\t vbsTree->SetBranchAddress( \"$two\", \t vbsEvent.$two );" >> $outfile
done < list_of_branches.txt

cat >> $outfile << EOF
 // }
}
//=======================================
#endif
EOF

# --------------------------------------------------------- End - Create vbsReducedTree.hpp file - End -------------------------------------------------------------

# --------------------------------------------------------- Start - Create vbsDL.hpp file - Start -----------------------------------------------------------------
TMVAVARS="lep1_pt lep1_eta"
activeVARS=""
plotVARS=""
plotVARS_AK8jet=""
plotVARS_VBFJet=""
plotVARS_Other=""
SUanlVARS="$(echo $activeVARS $plotVARS ${plotVARS_AK8jet} ${plotVARS_VBFJet} ${plotVARS_Other} | sort | tr -s '\ ' '\n' | sort | uniq )"

outfile_DL="vbsDL_new.hpp"
ActiveBranchesOutfile="vbsActiveBranches.hpp"

if [ -f $outfile_DL ]; then rm -f $outfile_DL; fi
echo "Creating $outfile_DL"

cat >> $outfile_DL << EOF
#ifndef vbsDL_hpp
#define vbsDL_hpp
//
//Note::Autogenerated with writeDL.sh
//Please check vbsDL*.hpp for available configurations.
//TMVA vars:
//$TMVAVARS
#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/TMVAGui.h"
#include "vbsReducedTree.hpp"
//
void   setChainBranches (TChain* inpChain);
//
void setVbsDLorReaderVarsAndSpectators(TMVA::DataLoader* dataloader, TMVA::Reader* datareader, VbsReducedEvent& vbsEvent){

EOF

allVARS="$(cat vbsReducedTreeNew.hpp | grep SetBranchAddress | awk '{print $2}' | sed 's/\"//g' | sed 's/,//g')"

for var in $SUanlVARS; do
    isVarArray="$(cat vbsReducedTreeNew.hpp | grep $var | grep '\['])"
    typevar="$(cat vbsReducedTreeNew.hpp | grep -v SetBranchAddress | grep -v Branch | grep -v typedef | grep $var | awk '{print $1}' | sort | uniq | awk '{print $1}')"

    nw="$(echo $typevar | wc -w)"
    if [ $nw != "1" ]; then echo $typevar $var; fi
    if [ "$typevar " == "Float_t " ]; then
        typevar="F"
    else
        typevar="I"
    fi
    isVariable="0"
    for tmvavar in $TMVAVARS; do
        if [ $var == $tmvavar ]; then
            isVariable="1";
            break;
        fi
    done

    if [ $isVariable == "1" ]; then
        isVariable="0";
        echo "//TMVA variable" >> $outfile_DL
        echo "if(dataloader) dataloader->AddVariable(\"$var\", \"$var\", \"\", '$typevar');" >> $outfile_DL
        if [ "0$isVarArray" == "0" ]; then
            echo "if(datareader) datareader->AddVariable(\"$var\",    &vbsEvent.$var        );" >> $outfile
        else
            echo "//if(datareader) datareader->AddVariable(\"$var\",    &vbsEvent.${var}[0]     );" >> $outfile
        fi
        echo " " >> $outfile_DL
        echo "Variable::" $var

    else
        echo "//TMVA spectator " >> $outfile_DL
        echo "if(dataloader) dataloader->AddSpectator(\"$var\",    \"$var\",   \"\",      '$typevar');" >> $outfile
        if [ "0$isVarArray" == "0" ]; then
            echo "if(datareader) datareader->AddSpectator(\"$var\",    &vbsEvent.$var        );" >> $outfile
        else
            echo "//if(datareader) datareader->AddSpectator(\"$var\",    &vbsEvent.${var}[0]   );" >> $outfile
        fi
        echo " " >> $outfile_DL
        echo "Spectator::" $var
    fi
done

cat >> $outfile_DL << EOF
}
//=======================================
//========================================
void setChainBranches (TChain* inpChain){
//
   inpChain->SetBranchStatus("*", 0);   // disable all branches
// switch on required  branches
EOF

for var in $SUanlVARS; do
    echo "inpChain->SetBranchStatus(\"$var\", 1);" >> $outfile_DL
done

cat >> $outfile_DL << EOF
}
//=============================
#endif
EOF
# --------------------------------------------------------- End - Create vbsDL.hpp file - End ----------------------------------------------------------------------

# --------------------------------------------------------- Start - Create vbsActiveBranches.hpp - Start ------------------------------------------------------------
echo "Creating $ActiveBranchesOutfile"

if [ -f $ActiveBranchesOutfile ]; then /bin/mv -f  ${ActiveBranchesOutfile} ${ActiveBranchesOutfile}.save; fi
cat >> $ActiveBranchesOutfile <<EOF
#ifndef vbsActiveBranches_hpp
#define vbsActiveBranches_hpp
////////////////////////////////////////////////////////////////////////
// $Id: vbsActiveBranches.hpp
// 
// File:    vbsActiveBranches.hpp
// Purpose: set active Branches for VBS analysis interface to TMVA 
// (works with VBS4LeptonsAnalysisReduced trees)   
// Autogenerated using writeDL.sh
////////////////////////////////////////////////////////////////////////
#include "TROOT.h"
#include "TChain.h"

void   setChainBranches (TChain* inpChain);
//========================================
void setChainBranches (TChain* inpChain){
//
   inpChain->SetBranchStatus("", kFALSE);   // disable all branches
// switch on required  branches
EOF

for var in $SUanlVARS; do
echo "inpChain->SetBranchStatus(\"$var\", 1);" >>  $ActiveBranchesOutfile
done
cat >> $ActiveBranchesOutfile <<EOF
}
//=======================================
#endif
EOF

# --------------------------------------------------------- End - Create vbsActiveBranches.hpp - End ---------------------------------------------------------------

echo "Done!"