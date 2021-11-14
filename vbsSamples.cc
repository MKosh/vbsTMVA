#ifndef VBS_SAMPLES_H
#define VBS_SAMPLES_H
void getSamples(std::vector<Sample*>& dataSamples, std::vector<Sample*>& sglSamples, std::vector<Sample*>& bkgSamples){
//==============================
//Generated by the dsw.sh script
//==============================
dataSamples.push_back( new Sample("data",	 "Data" ,	 1,	 1,	 gid_data, gid_data,	1,	1.0,	0) );
sglSamples.push_back( new Sample("WV_EWK",	 "WminusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.02982,	  1, gid_sgl,  100,	910,	200000.0,	0) );
sglSamples.push_back( new Sample("WV_EWK",	 "WminusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.03259,	  1, gid_sgl,  101,	910,	198300.0,	0) );
sglSamples.push_back( new Sample("WV_EWK",	 "WminusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.1,	  1, gid_sgl,  102,	910,	200000.0,	0) );
sglSamples.push_back( new Sample("WV_EWK",	 "WplusTo2JWminusToLNuJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.9107,	  1, gid_sgl,  103,	910,	1985200.0,	0) );
sglSamples.push_back( new Sample("WV_EWK",	 "WplusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.05401,	  1, gid_sgl,  104,	910,	178000.0,	0) );
sglSamples.push_back( new Sample("WV_EWK",	 "WplusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.9114,	  1, gid_sgl,  105,	910,	1998400.0,	0) );
sglSamples.push_back( new Sample("WV_EWK",	 "WplusToLNuWplusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.08793,	  1, gid_sgl,  106,	910,	200000.0,	0) );
sglSamples.push_back( new Sample("WV_EWK",	 "WplusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.1825,	  1, gid_sgl,  107,	910,	390100.0,	0) );
sglSamples.push_back( new Sample("WV_EWK",	 "ZTo2LZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.01589,	  1, gid_sgl,  108,	910,	100000.0,	0) );
bkgSamples.push_back( new Sample("Diboson",	  "WminusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.3488,	  1,  gid_Diboson,  1100,   400,	 500000.0,	  0) );
bkgSamples.push_back( new Sample("Diboson",	  "WminusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.03203,	  1,  gid_Diboson,  1100,   400,	 100000.0,	  0) );
bkgSamples.push_back( new Sample("Diboson",	  "WminusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	1.166,	  1,  gid_Diboson,  1100,   400,	 997400.0,	  0) );
bkgSamples.push_back( new Sample("Diboson",	  "WplusTo2JWminusToLNuJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	5.568,	  1,  gid_Diboson,  1100,   400,	 3823400.0,	  0) );
bkgSamples.push_back( new Sample("Diboson",	  "WplusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.575,	  1,  gid_Diboson,  1100,   400,	 500000.0,	  0) );
bkgSamples.push_back( new Sample("Diboson",	  "WplusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	5.546,	  1,  gid_Diboson,  1100,   400,	 4000000.0,	  0) );
bkgSamples.push_back( new Sample("Diboson",	  "WplusToLNuWplusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.07584,	  1,  gid_Diboson,  1100,   400,	 100000.0,	  0) );
bkgSamples.push_back( new Sample("Diboson",	  "WplusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	1.938,	  1,  gid_Diboson,  1100,   400,	 1971200.0,	  0) );
bkgSamples.push_back( new Sample("Diboson",	  "ZTo2LZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.3449,	  1,  gid_Diboson,  1100,   400,	 100000.0,	  0) );
bkgSamples.push_back( new Sample("top",	  "ST_tW_antitop_5f_NoFullyHadronicDecays_13TeV_PSweights-powheg-pythia8",	38.06,	  1,  gid_top,  1100,   592,	 2710849.25,	  0) );
bkgSamples.push_back( new Sample("top",	  "ST_tW_antitop_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",	34.97,	  1,  gid_top,  1100,   592,	 174109584.0,	  0) );
bkgSamples.push_back( new Sample("top",	  "ST_tW_top_5f_NoFullyHadronicDecays_13TeV_PSweights-powheg-pythia8",	38.09,	  1,  gid_top,  1100,   592,	 3213335.0,	  0) );
bkgSamples.push_back( new Sample("top",	  "ST_tW_top_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",	34.91,	  1,  gid_top,  1100,   592,	 173908704.0,	  0) );
bkgSamples.push_back( new Sample("top",	  "ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",	67.91,	  1,  gid_top,  1100,   592,	 17771480.0,	  0) );
bkgSamples.push_back( new Sample("top",	  "ST_t-channel_top_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",	113.3,	  1,  gid_top,  1100,   592,	 31835782.0,	  0) );
bkgSamples.push_back( new Sample("top",	  "ST_s-channel_4f_leptonDecays_13TeV_PSweights-amcatnlo-pythia8",	3.365,	  1,  gid_top,  1100,   592,	 33572360.0,	  0) );
bkgSamples.push_back( new Sample("top",	  "ST_s-channel_4f_hadronicDecays_TuneCP5_PSweights_13TeV-amcatnlo-pythia8",	11.24,	  1,  gid_top,  1100,   592,	 54761756.0,	  0) );
bkgSamples.push_back( new Sample("top",	  "ST_s-channel_4f_InclusiveDecays_13TeV-amcatnlo-pythia8",	10.12,	  1,  gid_top,  1100,   592,	 29561764.0,	  0) );
bkgSamples.push_back( new Sample("top",	  "TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8",	377.96,	  1,  gid_top,  1100,   592,	 21432309760.0,	  0) );
bkgSamples.push_back( new Sample("top",	  "TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8",	365.34,	  1,  gid_top,  1100,   592,	 32366942208.0,	  0) );
bkgSamples.push_back( new Sample("top",	  "TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8",	88.29,	  1,  gid_top,  1100,   592,	 4891619840.0,	  0) );
bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-70To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	1353.0,	  1,  gid_Wjets,  1100,   924,	 10020533.0,	  0) );
bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	1346.0,	  1,  gid_Wjets,  1100,   924,	 78043024.0,	  0) );
bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	360.1,	  1,  gid_Wjets,  1100,   924,	 38984320.0,	  0) );
bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	48.8,	  1,  gid_Wjets,  1100,   924,	 7687800.0,	  0) );
bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	12.07,	  1,  gid_Wjets,  1100,   924,	 18687480.0,	  0) );
bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	5.497,	  1,  gid_Wjets,  1100,   924,	 7830536.0,	  0) );
bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	1.329,	  1,  gid_Wjets,  1100,   924,	 6872441.0,	  0) );
bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	0.03209,	  1,  gid_Wjets,  1100,   924,	 2637821.0,	  0) );
bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-70to100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	169.9,	  1,  gid_Zjets,  1100,   4,	 9691660.0,	  0) );
bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	147.4,	  1,  gid_Zjets,  1100,   4,	 11017086.0,	  0) );
bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	41.04,	  1,  gid_Zjets,  1100,   4,	 9609137.0,	  0) );
bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	5.674,	  1,  gid_Zjets,  1100,   4,	 9725661.0,	  0) );
bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	1.358,	  1,  gid_Zjets,  1100,   4,	 8292957.0,	  0) );
bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	0.6229,	  1,  gid_Zjets,  1100,   4,	 2673066.0,	  0) );
bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-1200to2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	0.1512,	  1,  gid_Zjets,  1100,   4,	 596079.0,	  0) );
bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-2500toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	0.003659,	  1,  gid_Zjets,  1100,   4,	 399492.0,	  0) );
}
#endif