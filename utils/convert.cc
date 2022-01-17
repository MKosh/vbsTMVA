void convert() {
    #include <fstream>
    #include <vector>
    #include <string>
    #include <iostream>

    /////////////////////////////////////////////////////
    // Copied from write_list_macro.sh
    // Purpose: Add a new branch for nJet30 as a Float_t
    // instead of as an Int_t because TMVA::Reader::AddVariable
	// doesn't like ints
    // Mon Jul 26 10:52:52 AM EDT 2021
    /////////////////////////////////////////////////////

    std::vector<std::string> ntuples = {
		"DoubleMuon_Run2018.root",
		"DYJetsToLL_M-50_HT-100to200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_01.root",
		"DYJetsToLL_M-50_HT-1200to2500_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_01.root",
		"DYJetsToLL_M-50_HT-200to400_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_01.root",
		"DYJetsToLL_M-50_HT-2500toInf_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_01.root",
		"DYJetsToLL_M-50_HT-400to600_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8.root",
		"DYJetsToLL_M-50_HT-600to800_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_01.root",
		"DYJetsToLL_M-50_HT-70to100_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_01.root",
		"DYJetsToLL_M-50_HT-800to1200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_01.root",
		"EGamma_Run2018.root",
		"SingleMuon_Run2018.root",
		"ST_s-channel_antitop_leptonDecays_13TeV-PSweights_powheg-pythia_01.root",
		"ST_s-channel_top_leptonDecays_13TeV-PSweights_powheg-pythia_01.root",
		"ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8.root",
		"ST_t-channel_antitop_5f_TuneCP5_13TeV-powheg-pythia8_01.root",
		"ST_t-channel_top_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8.root",
		"ST_t-channel_top_5f_TuneCP5_13TeV-powheg-pythia8_01.root",
		"ST_tW_DS_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_01.root",
		"ST_tW_DS_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_01.root",
		"TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8.root",
		"TTToHadronic_TuneCP5_13TeV-powheg-pythia8.root",
		"TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8.root",
		"WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8.root",
		"WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8_01.root",
		"WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8.root",
		"WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8_01.root",
		"WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_01.root",
		"WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8.root",
		"WJetsToLNu_HT-70To100_TuneCP5_13TeV-madgraphMLM-pythia8.root",
		"WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_01.root",
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
		"WplusTo2JZTo2LJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WplusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WplusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WplusTo2LWminusTo2JJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WplusTo2LWplusTo2JJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
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
		"ZTo2LZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"ZZZJetsTo4L2Nu_4f_TuneCP5_13TeV_amcatnloFXFX_pythia8_01.root",
    };

// string location="/mnt/e/Research/ntuples/NEW/2018/haddedFiles/"; // in WSL on Desktop
//  string location="/mnt/d/ntuples/2016/haddedFiles/"; // in WSL on Laptop
// string location="/mnt/Storage/Research/ntuples/NEW/2016/haddedFiles/"; // in Linux
//   string location="/mnt/Volume/ntuples/2016/haddedFiles/";
	string location = "/run/media/markm/WD_Drive/Masters/ntuples/2018/haddedFiles/";
    for (int i = 0; i<ntuples.size(); i++) {
        Bool_t isAntiIso;
        Int_t AntiIsoInt;

        string infile = location+ntuples[i];
        TFile *input = new TFile(infile.c_str(), "update");

        if ((!input) || input->IsZombie()) {
            std::cout << "Failed to open file!" << std::endl;
            return;
        }
		std::cout << "File - " << infile << " opened for processing." << std::endl;
        auto Events_tree = input->Get<TTree>("Events");
        Events_tree->SetBranchAddress("isAntiIso", &isAntiIso);
        auto newBranch = Events_tree->Branch("AntiIsoInt", &AntiIsoInt, "AntiIsoInt/I");
		std::cout << "Tree opened and new branch address is set." << std::endl;
		std::cout << "Looping over " << Events_tree->GetEntries() << " events" << std::endl;
        for (Long64_t iter = 0; iter <Events_tree->GetEntries(); ++iter) {
            Events_tree->GetEntry(iter);
			//if (TMath::IsNaN(nJet30)) {
			//	nJet30f = -999.0;
			//	newBranch->Fill();
			//} else {
            	AntiIsoInt = (Int_t) isAntiIso;
           		newBranch->Fill();
			//}
			if (iter%100000 == 0) std::cout << "Processing event : " << iter << std::endl;
        }
		std::cout << "Writing " << infile << std::endl;
        Events_tree->Write("", TObject::kOverwrite);
        input->Close();
    }

}