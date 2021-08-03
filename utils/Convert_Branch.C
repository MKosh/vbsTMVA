{
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
		"DYJetsToLL_M-50_HT-100to200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_01.root",
		"DYJetsToLL_M-50_HT-1200to2500_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_01.root",
		"DYJetsToLL_M-50_HT-200to400_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_01.root",
		"DYJetsToLL_M-50_HT-2500toInf_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_01.root",
		"DYJetsToLL_M-50_HT-400to600_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8.root",
		"DYJetsToLL_M-50_HT-600to800_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_01.root",
		"DYJetsToLL_M-50_HT-70to100_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_01.root",
		"DYJetsToLL_M-50_HT-800to1200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_01.root",
		"Data_noDup_.root",
		"DoubleMuon_Run2018.root",
		"EGamma_Run2018.root",
		"ST_s-channel_antitop_leptonDecays_13TeV-PSweights_powheg-pythia_01.root",
		"ST_s-channel_top_leptonDecays_13TeV-PSweights_powheg-pythia_01.root",
		"ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8.root",
		"ST_t-channel_antitop_5f_TuneCP5_13TeV-powheg-pythia8_01.root",
		"ST_t-channel_top_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8.root",
		"ST_t-channel_top_5f_TuneCP5_13TeV-powheg-pythia8_01.root",
		"ST_tW_DS_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_01.root",
		"ST_tW_DS_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_01.root",
		"SingleMuon_Run2018.root",
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
		"WWW_4F_DiLeptonFilter_TuneCP5_13TeV-amcatnlo-pythia8_01.root",
		"WWZJetsTo4L2Nu_4f_TuneCP5_13TeV_amcatnloFXFX_pythia8_01.root",
		"WminusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WminusTo2JZTo2LJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8_01.root",
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
		"WplusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"WplusTo2JZTo2LJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
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
		"ZTo2LZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"ZTo2LZTo2JJJ_EWK_LO_aQGC_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8_01.root",
		"ZTo2LZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
		"ZZZJetsTo4L2Nu_4f_TuneCP5_13TeV_amcatnloFXFX_pythia8_01.root",
    };

  	string location="/mnt/e/Research/ntuples/NEW/2018/haddedFiles/"; // in WSL
//    string location="/mnt/Storage/Research/ntuples/NEW/2016/haddedFiles/"; // in Linux

    std::cout << '-' << std::flush;
    for (int i = 0; i<ntuples.size(); i++) {
        //if (i%4 == 0) {
        //    std::cout << "\b\\" << std::flush;
        //} else if (i%4 == 1) {
        //    std::cout << "\b|" << std::flush;
        //} else if (i%4 == 2) {
        //    std::cout << "\b/" << std::flush;
        //} else if (i%4 == 3) {
        //    std::cout << "\b-" << std::flush;
        //}

        Int_t nJet30;
        Float_t nJet30f;

        string infile = location+ntuples[i];
        TFile *input = new TFile(infile.c_str(), "update");
        auto Events_tree = input->Get<TTree>("Events");
        Events_tree->SetBranchAddress("nJet30", &nJet30);
        auto newBranch = Events_tree->Branch("nJet30f", &nJet30f, "nJet30f/F");

        for (Long64_t iter = 0; iter <Events_tree->GetEntries(); iter++) {
            Events_tree->GetEntry(iter);
			//if (TMath::IsNaN(nJet30)) {
			//	nJet30f = -999.0;
			//	newBranch->Fill();
			//} else {
            	nJet30f = (Float_t) nJet30;
           		newBranch->Fill();
			//}
        }
		std::cout << "Writing " << infile << std::endl;
        Events_tree->Write("", TObject::kOverwrite);
        input->Close();
    }
    std::cout << "\b" << std::flush;

}