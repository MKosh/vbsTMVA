{
    #include <fstream>
    #include <vector>
    #include <string>

    std::vector<std::string> ntuples = {"DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8.root",
        "DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8.root",
        "DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8.root",
        "DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8.root",
        "DYJetsToLL_0J_TuneCP5_13TeV-amcatnloFXFX-pythia8.root",
        "DYJetsToLL_1J_TuneCP5_13TeV-amcatnloFXFX-pythia8.root",
        "DYJetsToLL_2J_TuneCP5_13TeV-amcatnloFXFX-pythia8.root",
        "DYJetsToLL_M-50_HT-100to200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8.root",
        "DYJetsToLL_M-50_HT-1200to2500_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8.root",
        "DYJetsToLL_M-50_HT-200to400_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8.root",
        "DYJetsToLL_M-50_HT-2500toInf_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8.root",
        "DYJetsToLL_M-50_HT-400to600_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8.root",
        "DYJetsToLL_M-50_HT-600to800_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8.root",
        "DYJetsToLL_M-50_HT-70to100_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8.root",
        "DYJetsToLL_M-50_HT-800to1200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8.root",
        "Data_noDup.root",
        "ST_s-channel_antitop_leptonDecays_13TeV-PSweights_powheg-pythia.root",
        "ST_s-channel_top_leptonDecays_13TeV-PSweights_powheg-pythia.root",
        "ST_t-channel_antitop_5f_TuneCP5_13TeV-powheg-pythia8.root",
        "ST_t-channel_top_5f_TuneCP5_13TeV-powheg-pythia8.root",
        "ST_tW_DS_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8.root",
        "ST_tW_DS_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8.root",
        "TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8.root",
        "TTToHadronic_TuneCP5_13TeV-powheg-pythia8.root",
        "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8.root",
        "WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8.root",
        "WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8.root",
        "WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8.root",
        "WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8.root",
        "WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8.root",
        "WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8.root",
        "WJetsToLNu_HT-70To100_TuneCP5_13TeV-madgraphMLM-pythia8.root",
        "WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8.root",
        "WminusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
        "WminusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
        "WminusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
        "WminusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
        "WminusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
        "WminusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
        "WplusTo2JWminusToLNuJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
        "WplusTo2JWminusToLNuJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV.root",
        "WplusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
        "WplusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
        "WplusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
        "WplusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV.root",
        "WplusToLNuWplusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
        "WplusToLNuWplusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
        "WplusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
        "WplusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
        "ZTo2LZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root",
        "ZTo2LZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8.root"
    };

    string location="~/documents/ntuples/";
    //TFile *outfile = new TFile("var_list.txt", "RECREATE");
    std::ofstream ofs ("var_list.txt", std::ofstream::out);

    for (int i = 0; i<ntuples.size(); i++) {
        string infile = location+ntuples[i];
        TFile *input = new TFile(infile.c_str());
        TObjArray* brches = Events->GetListOfBranches();
        for (int iter = 0; iter <brches->GetEntries(); iter++) {
            ofs << brches->At(iter)->GetTitle() <<'\t' << brches->At(iter)->GetName() << std::endl;
        }
        input->Close();
    }
    
    ofs.close();

    
}