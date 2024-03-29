
    #include <fstream>
    #include <vector>
    #include <string>
    #include "TFile.h"
    #include "TObjArray.h"
    #include "TTree.h"
    /////////////////////////////////////////////////////
    // Autogenerated by write_list_macro.sh
    // Purpose: Store all of the root file names in a vector and print
    // the branch names and types to a text file.
    // Sun Sep 18 01:52:02 PM EDT 2022
    /////////////////////////////////////////////////////
void write_list() {
    std::vector<std::string> ntuples = {
		"Data_noDup_.root",
		"DoubleEG_Run2017.root",
		"DoubleMuon_Run2017.root",
		"DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8.root",
		"DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8_01.root",
		"DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8_01.root",
		"DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8_01.root",
		"DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8_01.root",
		"DYJetsToLL_M-50_HT-40to70_TuneCP5_13TeV-madgraphMLM-pythia8.root",
		"DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8_01.root",
		"DYJetsToLL_M-50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8.root",
		"DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8_01.root",
		"MuonEG_Run2017.root",
		"SingleElectron_Run2017.root",
		"SingleMuon_Run2017.root",
		"ST_s-channel_antitop_leptonDecays_13TeV-PSweights_powheg-pythia_01.root",
		"ST_s-channel_top_leptonDecays_13TeV-PSweights_powheg-pythia_01.root",
		"ST_t-channel_antitop_5f_TuneCP5_PSweights_13TeV-powheg-pythia8.root",
		"ST_t-channel_top_5f_TuneCP5_13TeV-powheg-pythia8_01.root",
		"ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_01.root",
		"ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_01.root",
		"TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8_01.root",
		"TTToHadronic_TuneCP5_13TeV-powheg-pythia8.root",
		"TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8.root",
		"WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8.root",
		"WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8.root",
		"WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_01.root",
		"WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8.root",
		"WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_01.root",
		"WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8.root",
		"WJetsToLNu_HT-70To100_TuneCP5_13TeV-madgraphMLM-pythia8_01.root",
		"WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8.root",
		"WminusTo2JZTo2LJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8_01.root",
		"WminusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WminusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WminusTo2LWminusTo2JJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WminusTo2LZTo2JJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8_01.root",
		"WminusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WminusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WminusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WminusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WplusTo2JWminusTo2LJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WplusTo2JWminusToLNuJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WplusTo2JWminusToLNuJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV.root",
		"WplusTo2JZTo2LJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8_01.root",
		"WplusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WplusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WplusTo2LWminusTo2JJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WplusTo2LWplusTo2JJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8_01.root",
		"WplusTo2LZTo2JJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8_01.root",
		"WplusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WplusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV.root",
		"WplusToLNuWplusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WplusToLNuWplusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WplusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WplusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WWW_4F_DiLeptonFilter_TuneCP5_13TeV-amcatnlo-pythia8_01.root",
		"WWZJetsTo4L2Nu_4f_TuneCP5_13TeV_amcatnloFXFX_pythia8_01.root",
		"ZTo2LZTo2JJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8_01.root",
		"ZTo2LZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"ZTo2LZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8_01.root",
		"ZZZJetsTo4L2Nu_4f_TuneCP5_13TeV_amcatnloFXFX_pythia8_01.root",
    };

    std::string location="/mnt/Storage/ntuples/2017/haddedFiles/"; // on my personal desktop
    //TFile *outfile = new TFile("var_list.txt", "RECREATE");
    std::ofstream ofs ("var_list.txt", std::ofstream::out);

    // Change the 1 in the loop to ntuples.size() if the ntuples have different sets of branches
    for (int i = 0; i<1; i++) {
        std::string infile = location+ntuples[i];
        TFile *input = new TFile(infile.c_str());
        TTree* Events = input->Get<TTree>("Events");
        TObjArray* brches = Events->GetListOfBranches();
        for (int iter = 0; iter <brches->GetEntries(); iter++) {
            ofs << brches->At(iter)->GetTitle() << '\t' << '\t' << brches->At(iter)->GetName() << ";" << std::endl;
        }
        input->Close();
    }
    
    ofs.close();
}
