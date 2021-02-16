#include "vbsSamples.hpp"
//
void getSamples(std::vector<Sample*>& dataSamples, std::vector<Sample*>& sglSamples, std::vector<Sample*>& bkgSamples){
//==============================
//Generated by the dsw.sh script
//==============================
bkgSamples.push_back( new Sample("ZJets",	  "DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	147.4,	  1,  gid_ZJets,  1100,   4,	 11017086.0,	  0) );
dataSamples.push_back( new Sample("data",	 "Data" ,	 1,	 1,	 gid_data, gid_data,	1,	1.0,	0) );
bkgSamples.push_back( new Sample("Top",	  "TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8",	377.96,	  1,  gid_Top,  1100,   592,	 21432309760.0,	  0) );
bkgSamples.push_back( new Sample("WJets",	  "WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	1346.0,	  1,  gid_WJets,  1100,   924,	 78043024.0,	  0) );
sglSamples.push_back( new Sample("WV_EWK",	 "WplusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.9114,	  1, gid_sgl,  100,	910,	1998400.0,	0) );
bkgSamples.push_back( new Sample("Diboson",	  "WplusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	5.546,	  1,  gid_Diboson,  1100,   400,	 4000000.0,	  0) );
}
