#ifndef VBS_SAMPLES_H
#define VBS_SAMPLES_H

void getSamples(std::vector<Sample*>& dataSamples, std::vector<Sample*>& sglSamples, std::vector<Sample*>& bkgSamples){
//==============================
//Generated by the dsw.sh script
//==============================
dataSamples.push_back( new Sample(2017, 1.0, "data", "Data", 1, 1, gid_data, gid_data, 1, 1, 0) );
sglSamples.push_back( new Sample(2017, 41530.0, "VBS_EWK", "WminusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.02982, 1, gid_sgl, 100, 910, 592774.0, 0) );
sglSamples.push_back( new Sample(2017, 41530.0, "VBS_EWK", "WminusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.03259, 1, gid_sgl, 101, 910, 568778.0, 0) );
sglSamples.push_back( new Sample(2017, 41530.0, "VBS_EWK", "WminusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.1, 1, gid_sgl, 102, 910, 592964.0, 0) );
sglSamples.push_back( new Sample(2017, 41530.0, "VBS_EWK", "WplusTo2JWminusToLNuJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.9107, 1, gid_sgl, 103, 910, 5539710.0, 0) );
sglSamples.push_back( new Sample(2017, 41530.0, "VBS_EWK", "WplusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.05401, 1, gid_sgl, 104, 910, 596742.0, 0) );
sglSamples.push_back( new Sample(2017, 41530.0, "VBS_EWK", "WplusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.9114, 1, gid_sgl, 105, 910, 5970516.0, 0) );
sglSamples.push_back( new Sample(2017, 41530.0, "VBS_EWK", "WplusToLNuWplusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.08793, 1, gid_sgl, 106, 910, 592724.0, 0) );
sglSamples.push_back( new Sample(2017, 41530.0, "VBS_EWK", "WplusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.1825, 1, gid_sgl, 107, 910, 1183046.0, 0) );
sglSamples.push_back( new Sample(2017, 41530.0, "VBS_EWK", "ZTo2LZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.01589, 1, gid_sgl, 108, 910, 284048.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "Diboson", "WminusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.3488, 1, gid_Diboson, 1100, 400, 1476120.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "Diboson", "WminusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.03203, 1, gid_Diboson, 1100, 400, 296398.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "Diboson", "WminusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 1.166, 1, gid_Diboson, 1100, 400, 2875730.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "Diboson", "WplusTo2JWminusToLNuJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV", 5.568, 1, gid_Diboson, 1100, 400, 10668784.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "Diboson", "WplusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.575, 1, gid_Diboson, 1100, 400, 1428816.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "Diboson", "WplusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV", 5.546, 1, gid_Diboson, 1100, 400, 11267850.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "Diboson", "WplusToLNuWplusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.07584, 1, gid_Diboson, 1100, 400, 296730.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "Diboson", "WplusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 1.938, 1, gid_Diboson, 1100, 400, 5919374.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "Diboson", "ZTo2LZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.3449, 1, gid_Diboson, 1100, 400, 149536.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "top", "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8", 365.34, 1, gid_top, 1100, 592, 72526299136.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "top", "TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8", 86.99, 1, gid_top, 1100, 592, 648729856.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "top", "TTToHadronic_TuneCP5_13TeV-powheg-pythia8", 377.96, 1, gid_top, 1100, 592, 61926825984.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "top", "ST_s-channel_antitop_leptonDecays_13TeV-PSweights_powheg-pythia", 1.33, 1, gid_top, 1100, 592, 3422897.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "top", "ST_s-channel_top_leptonDecays_13TeV-PSweights_powheg-pythia", 2.13, 1, gid_top, 1100, 592, 12862777.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "top", "ST_t-channel_antitop_5f_TuneCP5_PSweights_13TeV-powheg-pythia8", 27.19, 1, gid_top, 1100, 592, 557503744.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "top", "ST_t-channel_top_5f_TuneCP5_13TeV-powheg-pythia8", 45.7, 1, gid_top, 1100, 592, 1418556928.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "top", "ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8", 12.04, 1, gid_top, 1100, 592, 279005344.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "top", "ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8", 12.04, 1, gid_top, 1100, 592, 272081088.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "Wjets", "WJetsToLNu_HT-70To100_TuneCP5_13TeV-madgraphMLM-pythia8", 1292.0, 1, gid_Wjets, 1100, 924, 22201316.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "Wjets", "WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8", 1395.0, 1, gid_Wjets, 1100, 924, 35804624.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "Wjets", "WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8", 407.9, 1, gid_Wjets, 1100, 924, 21192212.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "Wjets", "WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8", 57.48, 1, gid_Wjets, 1100, 924, 14250114.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "Wjets", "WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8", 12.87, 1, gid_Wjets, 1100, 924, 21582308.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "Wjets", "WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8", 5.366, 1, gid_Wjets, 1100, 924, 20272990.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "Wjets", "WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8", 1.074, 1, gid_Wjets, 1100, 924, 19991892.0, 0) );
bkgSamples.push_back( new Sample(2017, 41530.0, "Wjets", "WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8", 0.008001, 1, gid_Wjets, 1100, 924, 20629584.0, 0) );
bkgSamples.push_back( new Sample(2017, 59740.0, "Zjets", "DYJetsToLL_M-50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8", 167.33, 1, gid_Zjets, 1100, 4, 9333543.0, 0) );
bkgSamples.push_back( new Sample(2017, 59740.0, "Zjets", "DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8", 161.1, 1, gid_Zjets, 1100, 4, 15124171.0, 0) );
bkgSamples.push_back( new Sample(2017, 59740.0, "Zjets", "DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8", 48.66, 1, gid_Zjets, 1100, 4, 11896758.0, 0) );
bkgSamples.push_back( new Sample(2017, 59740.0, "Zjets", "DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8", 6.968, 1, gid_Zjets, 1100, 4, 11294006.0, 0) );
bkgSamples.push_back( new Sample(2017, 59740.0, "Zjets", "DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8", 1.743, 1, gid_Zjets, 1100, 4, 8691608.0, 0) );
bkgSamples.push_back( new Sample(2017, 59740.0, "Zjets", "DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8", 0.8052, 1, gid_Zjets, 1100, 4, 3089712.0, 0) );
bkgSamples.push_back( new Sample(2017, 59740.0, "Zjets", "DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8", 0.1933, 1, gid_Zjets, 1100, 4, 616923.0, 0) );
bkgSamples.push_back( new Sample(2017, 59740.0, "Zjets", "DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8", 0.003468, 1, gid_Zjets, 1100, 4, 401334.0, 0) );
}
#endif
