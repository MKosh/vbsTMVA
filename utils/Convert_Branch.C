{
    #include <fstream>
    #include <vector>
    #include <string>
    #include <iostream>

    /////////////////////////////////////////////////////
    // Copied from write_list_macro.sh
    // Purpose: Add a new branch for nJet30 as a Float_t
    // instead of as an Int_t
    // Mon Jul 26 10:52:52 AM EDT 2021
    /////////////////////////////////////////////////////

    std::vector<std::string> ntuples = {
		"Data.root",
		"DoubleEG_Run2016.root",
		"DoubleMuon_Run2016.root",
		"DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root",
		"DYJetsToLL_M-50_HT-1200to2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root",
		"DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root",
		"DYJetsToLL_M-50_HT-2500toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root",
		"DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root",
		"DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root",
		"DYJetsToLL_M-50_HT-70to100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root",
		"DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root",
		"MuonEG_Run2016.root",
		"SingleElectron_Run2016.root",
		"SingleMuon_Run2016.root",
		"ST_s-channel_4f_hadronicDecays_TuneCP5_PSweights_13TeV-amcatnlo-pythia8.root",
		"ST_s-channel_4f_InclusiveDecays_13TeV-amcatnlo-pythia8.root",
		"ST_s-channel_4f_leptonDecays_13TeV_PSweights-amcatnlo-pythia8.root",
		"ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8.root",
		"ST_t-channel_top_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8.root",
		"ST_tW_antitop_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8.root",
		"ST_tW_antitop_5f_NoFullyHadronicDecays_13TeV_PSweights-powheg-pythia8.root",
		"ST_tW_top_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8.root",
		"ST_tW_top_5f_NoFullyHadronicDecays_13TeV_PSweights-powheg-pythia8.root",
		"TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8.root",
		"TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8.root",
		"TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8.root",
		"WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root",
		"WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root",
		"WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root",
		"WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root",
		"WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root",
		"WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root",
		"WJetsToLNu_HT-70To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root",
		"WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root",
		"WminusTo2JZTo2LJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WminusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WminusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WminusTo2LWminusTo2JJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WminusTo2LZTo2JJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WminusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WminusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WminusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WminusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WplusTo2JWminusTo2LJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WplusTo2JWminusToLNuJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WplusTo2JWminusToLNuJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WplusTo2JZTo2LJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WplusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WplusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WplusTo2LWminusTo2JJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WplusTo2LWplusTo2JJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WplusTo2LZTo2JJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WplusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WplusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WplusToLNuWplusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WplusToLNuWplusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WplusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WplusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"WWW_4F_DiLeptonFilter_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root",
		"WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root",
		"WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root",
		"ZTo2LZTo2JJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"ZTo2LZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"ZTo2LZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8.root",
		"ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root",
    };

    string location="/mnt/Storage/Research/ntuples/NEW/2016/haddedFiles/"; // on my personal desktop

    std::cout << '-' << std::flush;
    for (int i = 0; i<ntuples.size(); i++) {
        if (i%4 == 0) {
            std::cout << "\b\\" << std::flush;
        } else if (i%4 == 1) {
            std::cout << "\b|" << std::flush;
        } else if (i%4 == 2) {
            std::cout << "\b/" << std::flush;
        } else if (i%4 == 3) {
            std::cout << "\b-" << std::flush;
        }

        Int_t nJet30;
        Float_t nJet30f;

        string infile = location+ntuples[i];
        TFile *input = new TFile(infile.c_str(), "update");
        auto Events_tree = input->Get<TTree>("Events");
        Events_tree->SetBranchAddress("nJet30", &nJet30);
        auto newBranch = Events_tree->Branch("nJet30f", &nJet30f, "nJet30f/F");

        for (int iter = 0; iter <Events_tree->GetEntries(); iter++) {
            Events_tree->GetEntry(iter);
            nJet30f = (Float_t) nJet30;
            newBranch->Fill();
        }

        Events_tree->Write("", TObject::kOverwrite);
        input->Close();
    }
    std::cout << "\b" << std::flush;

}