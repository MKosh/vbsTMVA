#ifndef VBS_SAMPLES_H
#define VBS_SAMPLES_H

void getSamples(std::vector<Sample*>& dataSamples, std::vector<Sample*>& sglSamples, std::vector<Sample*>& bkgSamples){
//==============================
//Generated by the dsw.sh script
//==============================
dataSamples.push_back( new Sample("2016", "data", "Data", 1, 1, gid_data, gid_data, 1, 1, 0) );
sglSamples.push_back( new Sample("2016", "VBS_EWK", "WminusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 0.02982, 1, gid_sgl, 100, 910, 200000.0, 0) );
sglSamples.push_back( new Sample("2016", "VBS_EWK", "WminusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 0.03259, 1, gid_sgl, 101, 910, 198300.0, 0) );
sglSamples.push_back( new Sample("2016", "VBS_EWK", "WminusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 0.1, 1, gid_sgl, 102, 910, 200000.0, 0) );
sglSamples.push_back( new Sample("2016", "VBS_EWK", "WplusTo2JWminusToLNuJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 0.9107, 1, gid_sgl, 103, 910, 1985200.0, 0) );
sglSamples.push_back( new Sample("2016", "VBS_EWK", "WplusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 0.05401, 1, gid_sgl, 104, 910, 178000.0, 0) );
sglSamples.push_back( new Sample("2016", "VBS_EWK", "WplusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 0.9114, 1, gid_sgl, 105, 910, 1998400.0, 0) );
sglSamples.push_back( new Sample("2016", "VBS_EWK", "WplusToLNuWplusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 0.08793, 1, gid_sgl, 106, 910, 200000.0, 0) );
sglSamples.push_back( new Sample("2016", "VBS_EWK", "WplusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 0.1825, 1, gid_sgl, 107, 910, 390100.0, 0) );
sglSamples.push_back( new Sample("2016", "VBS_EWK", "ZTo2LZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 0.01589, 1, gid_sgl, 108, 910, 100000.0, 0) );
bkgSamples.push_back( new Sample("2016", "Diboson", "WminusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 0.3488, 1, gid_Diboson, 1100, 400, 500000.0, 0) );
bkgSamples.push_back( new Sample("2016", "Diboson", "WminusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 0.03203, 1, gid_Diboson, 1100, 400, 100000.0, 0) );
bkgSamples.push_back( new Sample("2016", "Diboson", "WminusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 1.166, 1, gid_Diboson, 1100, 400, 997400.0, 0) );
bkgSamples.push_back( new Sample("2016", "Diboson", "WplusTo2JWminusToLNuJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 5.568, 1, gid_Diboson, 1100, 400, 3823400.0, 0) );
bkgSamples.push_back( new Sample("2016", "Diboson", "WplusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 0.575, 1, gid_Diboson, 1100, 400, 500000.0, 0) );
bkgSamples.push_back( new Sample("2016", "Diboson", "WplusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 5.546, 1, gid_Diboson, 1100, 400, 4000000.0, 0) );
bkgSamples.push_back( new Sample("2016", "Diboson", "WplusToLNuWplusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 0.07584, 1, gid_Diboson, 1100, 400, 100000.0, 0) );
bkgSamples.push_back( new Sample("2016", "Diboson", "WplusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 1.938, 1, gid_Diboson, 1100, 400, 1971200.0, 0) );
bkgSamples.push_back( new Sample("2016", "Diboson", "ZTo2LZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8", 0.3449, 1, gid_Diboson, 1100, 400, 100000.0, 0) );
bkgSamples.push_back( new Sample("2016", "top", "ST_tW_antitop_5f_NoFullyHadronicDecays_13TeV_PSweights-powheg-pythia8", 38.06, 1, gid_top, 1100, 592, 2710849.25, 0) );
bkgSamples.push_back( new Sample("2016", "top", "ST_tW_antitop_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8", 34.97, 1, gid_top, 1100, 592, 174109584.0, 0) );
bkgSamples.push_back( new Sample("2016", "top", "ST_tW_top_5f_NoFullyHadronicDecays_13TeV_PSweights-powheg-pythia8", 38.09, 1, gid_top, 1100, 592, 3213335.0, 0) );
bkgSamples.push_back( new Sample("2016", "top", "ST_tW_top_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8", 34.91, 1, gid_top, 1100, 592, 173908704.0, 0) );
bkgSamples.push_back( new Sample("2016", "top", "ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8", 67.91, 1, gid_top, 1100, 592, 17771480.0, 0) );
bkgSamples.push_back( new Sample("2016", "top", "ST_t-channel_top_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8", 113.3, 1, gid_top, 1100, 592, 31835782.0, 0) );
bkgSamples.push_back( new Sample("2016", "top", "ST_s-channel_4f_leptonDecays_13TeV_PSweights-amcatnlo-pythia8", 3.365, 1, gid_top, 1100, 592, 33572360.0, 0) );
bkgSamples.push_back( new Sample("2016", "top", "ST_s-channel_4f_hadronicDecays_TuneCP5_PSweights_13TeV-amcatnlo-pythia8", 11.24, 1, gid_top, 1100, 592, 54761756.0, 0) );
bkgSamples.push_back( new Sample("2016", "top", "ST_s-channel_4f_InclusiveDecays_13TeV-amcatnlo-pythia8", 10.12, 1, gid_top, 1100, 592, 29561764.0, 0) );
bkgSamples.push_back( new Sample("2016", "top", "TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8", 377.96, 1, gid_top, 1100, 592, 21432309760.0, 0) );
bkgSamples.push_back( new Sample("2016", "top", "TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8", 365.34, 1, gid_top, 1100, 592, 32366942208.0, 0) );
bkgSamples.push_back( new Sample("2016", "top", "TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8", 88.29, 1, gid_top, 1100, 592, 4891619840.0, 0) );
bkgSamples.push_back( new Sample("2016", "Wjets", "WJetsToLNu_HT-70To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8", 1353.0, 1, gid_Wjets, 1100, 924, 10020533.0, 0) );
bkgSamples.push_back( new Sample("2016", "Wjets", "WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8", 1346.0, 1, gid_Wjets, 1100, 924, 78043024.0, 0) );
bkgSamples.push_back( new Sample("2016", "Wjets", "WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8", 360.1, 1, gid_Wjets, 1100, 924, 38984320.0, 0) );
bkgSamples.push_back( new Sample("2016", "Wjets", "WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8", 48.8, 1, gid_Wjets, 1100, 924, 7687800.0, 0) );
bkgSamples.push_back( new Sample("2016", "Wjets", "WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8", 12.07, 1, gid_Wjets, 1100, 924, 18687480.0, 0) );
bkgSamples.push_back( new Sample("2016", "Wjets", "WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8", 5.497, 1, gid_Wjets, 1100, 924, 7830536.0, 0) );
bkgSamples.push_back( new Sample("2016", "Wjets", "WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8", 1.329, 1, gid_Wjets, 1100, 924, 6872441.0, 0) );
bkgSamples.push_back( new Sample("2016", "Wjets", "WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8", 0.03209, 1, gid_Wjets, 1100, 924, 2637821.0, 0) );
bkgSamples.push_back( new Sample("2016", "Zjets", "DYJetsToLL_M-50_HT-70to100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8", 169.9, 1, gid_Zjets, 1100, 4, 9691660.0, 0) );
bkgSamples.push_back( new Sample("2016", "Zjets", "DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8", 147.4, 1, gid_Zjets, 1100, 4, 11017086.0, 0) );
bkgSamples.push_back( new Sample("2016", "Zjets", "DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8", 41.04, 1, gid_Zjets, 1100, 4, 9609137.0, 0) );
bkgSamples.push_back( new Sample("2016", "Zjets", "DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8", 5.674, 1, gid_Zjets, 1100, 4, 9725661.0, 0) );
bkgSamples.push_back( new Sample("2016", "Zjets", "DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8", 1.358, 1, gid_Zjets, 1100, 4, 8292957.0, 0) );
bkgSamples.push_back( new Sample("2016", "Zjets", "DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8", 0.6229, 1, gid_Zjets, 1100, 4, 2673066.0, 0) );
bkgSamples.push_back( new Sample("2016", "Zjets", "DYJetsToLL_M-50_HT-1200to2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8", 0.1512, 1, gid_Zjets, 1100, 4, 596079.0, 0) );
bkgSamples.push_back( new Sample("2016", "Zjets", "DYJetsToLL_M-50_HT-2500toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8", 0.003659, 1, gid_Zjets, 1100, 4, 399492.0, 0) );
dataSamples.push_back( new Sample("2017", "data", "Data", 1, 1, gid_data, gid_data, 1, 1, 0) );
sglSamples.push_back( new Sample("2017", "VBS_EWK", "WminusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.02982, 1, gid_sgl, 109, 910, 592774.0, 0) );
sglSamples.push_back( new Sample("2017", "VBS_EWK", "WminusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.03259, 1, gid_sgl, 110, 910, 568778.0, 0) );
sglSamples.push_back( new Sample("2017", "VBS_EWK", "WminusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.1, 1, gid_sgl, 111, 910, 592964.0, 0) );
sglSamples.push_back( new Sample("2017", "VBS_EWK", "WplusTo2JWminusToLNuJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.9107, 1, gid_sgl, 112, 910, 5539710.0, 0) );
sglSamples.push_back( new Sample("2017", "VBS_EWK", "WplusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.05401, 1, gid_sgl, 113, 910, 596742.0, 0) );
sglSamples.push_back( new Sample("2017", "VBS_EWK", "WplusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.9114, 1, gid_sgl, 114, 910, 5970516.0, 0) );
sglSamples.push_back( new Sample("2017", "VBS_EWK", "WplusToLNuWplusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.08793, 1, gid_sgl, 115, 910, 592724.0, 0) );
sglSamples.push_back( new Sample("2017", "VBS_EWK", "WplusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.1825, 1, gid_sgl, 116, 910, 1183046.0, 0) );
sglSamples.push_back( new Sample("2017", "VBS_EWK", "ZTo2LZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.01589, 1, gid_sgl, 117, 910, 284048.0, 0) );
bkgSamples.push_back( new Sample("2017", "Diboson", "WminusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.3488, 1, gid_Diboson, 1100, 400, 1476120.0, 0) );
bkgSamples.push_back( new Sample("2017", "Diboson", "WminusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.03203, 1, gid_Diboson, 1100, 400, 296398.0, 0) );
bkgSamples.push_back( new Sample("2017", "Diboson", "WminusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 1.166, 1, gid_Diboson, 1100, 400, 2875730.0, 0) );
bkgSamples.push_back( new Sample("2017", "Diboson", "WplusTo2JWminusToLNuJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV", 5.568, 1, gid_Diboson, 1100, 400, 10668784.0, 0) );
bkgSamples.push_back( new Sample("2017", "Diboson", "WplusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.575, 1, gid_Diboson, 1100, 400, 1428816.0, 0) );
bkgSamples.push_back( new Sample("2017", "Diboson", "WplusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV", 5.546, 1, gid_Diboson, 1100, 400, 11267850.0, 0) );
bkgSamples.push_back( new Sample("2017", "Diboson", "WplusToLNuWplusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.07584, 1, gid_Diboson, 1100, 400, 296730.0, 0) );
bkgSamples.push_back( new Sample("2017", "Diboson", "WplusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 1.938, 1, gid_Diboson, 1100, 400, 5919374.0, 0) );
bkgSamples.push_back( new Sample("2017", "Diboson", "ZTo2LZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.3449, 1, gid_Diboson, 1100, 400, 149536.0, 0) );
bkgSamples.push_back( new Sample("2017", "top", "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8", 365.34, 1, gid_top, 1100, 592, 72526299136.0, 0) );
bkgSamples.push_back( new Sample("2017", "top", "TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8", 86.99, 1, gid_top, 1100, 592, 648729856.0, 0) );
bkgSamples.push_back( new Sample("2017", "top", "TTToHadronic_TuneCP5_13TeV-powheg-pythia8", 377.96, 1, gid_top, 1100, 592, 61926825984.0, 0) );
bkgSamples.push_back( new Sample("2017", "top", "ST_s-channel_antitop_leptonDecays_13TeV-PSweights_powheg-pythia", 1.33, 1, gid_top, 1100, 592, 3422897.0, 0) );
bkgSamples.push_back( new Sample("2017", "top", "ST_s-channel_top_leptonDecays_13TeV-PSweights_powheg-pythia", 2.13, 1, gid_top, 1100, 592, 12862777.0, 0) );
bkgSamples.push_back( new Sample("2017", "top", "ST_t-channel_antitop_5f_TuneCP5_PSweights_13TeV-powheg-pythia8", 27.19, 1, gid_top, 1100, 592, 557503744.0, 0) );
bkgSamples.push_back( new Sample("2017", "top", "ST_t-channel_top_5f_TuneCP5_13TeV-powheg-pythia8", 45.7, 1, gid_top, 1100, 592, 1418556928.0, 0) );
bkgSamples.push_back( new Sample("2017", "top", "ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8", 12.04, 1, gid_top, 1100, 592, 279005344.0, 0) );
bkgSamples.push_back( new Sample("2017", "top", "ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8", 12.04, 1, gid_top, 1100, 592, 272081088.0, 0) );
bkgSamples.push_back( new Sample("2017", "Wjets", "WJetsToLNu_HT-70To100_TuneCP5_13TeV-madgraphMLM-pythia8", 1292.0, 1, gid_Wjets, 1100, 924, 22201316.0, 0) );
bkgSamples.push_back( new Sample("2017", "Wjets", "WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8", 1395.0, 1, gid_Wjets, 1100, 924, 35804624.0, 0) );
bkgSamples.push_back( new Sample("2017", "Wjets", "WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8", 407.9, 1, gid_Wjets, 1100, 924, 21192212.0, 0) );
bkgSamples.push_back( new Sample("2017", "Wjets", "WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8", 57.48, 1, gid_Wjets, 1100, 924, 14250114.0, 0) );
bkgSamples.push_back( new Sample("2017", "Wjets", "WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8", 12.87, 1, gid_Wjets, 1100, 924, 21582308.0, 0) );
bkgSamples.push_back( new Sample("2017", "Wjets", "WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8", 5.366, 1, gid_Wjets, 1100, 924, 20272990.0, 0) );
bkgSamples.push_back( new Sample("2017", "Wjets", "WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8", 1.074, 1, gid_Wjets, 1100, 924, 19991892.0, 0) );
bkgSamples.push_back( new Sample("2017", "Wjets", "WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8", 0.008001, 1, gid_Wjets, 1100, 924, 20629584.0, 0) );
bkgSamples.push_back( new Sample("2017", "Zjets", "DYJetsToLL_M-50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8", 167.33, 1, gid_Zjets, 1100, 4, 9333543.0, 0) );
bkgSamples.push_back( new Sample("2017", "Zjets", "DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8", 161.1, 1, gid_Zjets, 1100, 4, 15124171.0, 0) );
bkgSamples.push_back( new Sample("2017", "Zjets", "DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8", 48.66, 1, gid_Zjets, 1100, 4, 11896758.0, 0) );
bkgSamples.push_back( new Sample("2017", "Zjets", "DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8", 6.968, 1, gid_Zjets, 1100, 4, 11294006.0, 0) );
bkgSamples.push_back( new Sample("2017", "Zjets", "DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8", 1.743, 1, gid_Zjets, 1100, 4, 8691608.0, 0) );
bkgSamples.push_back( new Sample("2017", "Zjets", "DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8", 0.8052, 1, gid_Zjets, 1100, 4, 3089712.0, 0) );
bkgSamples.push_back( new Sample("2017", "Zjets", "DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8", 0.1933, 1, gid_Zjets, 1100, 4, 616923.0, 0) );
bkgSamples.push_back( new Sample("2017", "Zjets", "DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8", 0.003468, 1, gid_Zjets, 1100, 4, 401334.0, 0) );
dataSamples.push_back( new Sample("2018", "data", "Data", 1, 1, gid_data, gid_data, 1, 1, 0) );
sglSamples.push_back( new Sample("2018", "VBS_EWK", "WminusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.02982, 1, gid_sgl, 118, 910, 584787.0, 0) );
sglSamples.push_back( new Sample("2018", "VBS_EWK", "WminusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.03259, 1, gid_sgl, 119, 910, 565831.5, 0) );
sglSamples.push_back( new Sample("2018", "VBS_EWK", "WminusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.1, 1, gid_sgl, 120, 910, 566998.5625, 0) );
sglSamples.push_back( new Sample("2018", "VBS_EWK", "WplusTo2JWminusToLNuJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.9107, 1, gid_sgl, 121, 910, 5742718.0, 0) );
sglSamples.push_back( new Sample("2018", "VBS_EWK", "WplusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.05401, 1, gid_sgl, 122, 910, 566355.8125, 0) );
sglSamples.push_back( new Sample("2018", "VBS_EWK", "WplusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.9114, 1, gid_sgl, 123, 910, 5744633.5, 0) );
sglSamples.push_back( new Sample("2018", "VBS_EWK", "WplusToLNuWplusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.08793, 1, gid_sgl, 124, 910, 588277.125, 0) );
sglSamples.push_back( new Sample("2018", "VBS_EWK", "WplusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.1825, 1, gid_sgl, 125, 910, 1156414.625, 0) );
sglSamples.push_back( new Sample("2018", "VBS_EWK", "ZTo2LZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.01589, 1, gid_sgl, 126, 910, 297179.84375, 0) );
bkgSamples.push_back( new Sample("2018", "Diboson", "WminusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.3488, 1, gid_Diboson, 1100, 400, 1479242.875, 0) );
bkgSamples.push_back( new Sample("2018", "Diboson", "WminusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.03203, 1, gid_Diboson, 1100, 400, 296655.78125, 0) );
bkgSamples.push_back( new Sample("2018", "Diboson", "WminusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 1.166, 1, gid_Diboson, 1100, 400, 2906207.5, 0) );
bkgSamples.push_back( new Sample("2018", "Diboson", "WplusTo2JWminusToLNuJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV", 5.568, 1, gid_Diboson, 1100, 400, 11275069.0, 0) );
bkgSamples.push_back( new Sample("2018", "Diboson", "WplusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.575, 1, gid_Diboson, 1100, 400, 1451346.625, 0) );
bkgSamples.push_back( new Sample("2018", "Diboson", "WplusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV", 5.546, 1, gid_Diboson, 1100, 400, 11385983.0, 0) );
bkgSamples.push_back( new Sample("2018", "Diboson", "WplusToLNuWplusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.07584, 1, gid_Diboson, 1100, 400, 295939.40625, 0) );
bkgSamples.push_back( new Sample("2018", "Diboson", "WplusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 1.938, 1, gid_Diboson, 1100, 400, 5706507.5, 0) );
bkgSamples.push_back( new Sample("2018", "Diboson", "ZTo2LZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8", 0.3449, 1, gid_Diboson, 1100, 400, 143152.015625, 0) );
bkgSamples.push_back( new Sample("2018", "top", "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8", 365.34, 1, gid_top, 1100, 592, 90424811520.0, 0) );
bkgSamples.push_back( new Sample("2018", "top", "TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8", 86.99, 1, gid_top, 1100, 592, 4635769344.0, 0) );
bkgSamples.push_back( new Sample("2018", "top", "TTToHadronic_TuneCP5_13TeV-powheg-pythia8", 377.96, 1, gid_top, 1100, 592, 102734004224.0, 0) );
bkgSamples.push_back( new Sample("2018", "top", "ST_s-channel_antitop_leptonDecays_13TeV-PSweights_powheg-pythia", 1.33, 1, gid_top, 1100, 592, 3476320.0, 0) );
bkgSamples.push_back( new Sample("2018", "top", "ST_s-channel_top_leptonDecays_13TeV-PSweights_powheg-pythia", 2.13, 1, gid_top, 1100, 592, 12929918.0, 0) );
bkgSamples.push_back( new Sample("2018", "top", "ST_t-channel_antitop_5f_TuneCP5_13TeV-powheg-pythia8", 27.19, 1, gid_top, 1100, 592, 326172576.0, 0) );
bkgSamples.push_back( new Sample("2018", "top", "ST_t-channel_top_5f_TuneCP5_13TeV-powheg-pythia8", 45.7, 1, gid_top, 1100, 592, 815051136.0, 0) );
bkgSamples.push_back( new Sample("2018", "top", "ST_tW_DS_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8", 12.04, 1, gid_top, 1100, 592, 170525440.0, 0) );
bkgSamples.push_back( new Sample("2018", "top", "ST_tW_DS_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8", 12.04, 1, gid_top, 1100, 592, 170711072.0, 0) );
bkgSamples.push_back( new Sample("2018", "Wjets", "WJetsToLNu_HT-70To100_TuneCP5_13TeV-madgraphMLM-pythia8", 1292.0, 1, gid_Wjets, 1100, 924, 28054964.0, 0) );
bkgSamples.push_back( new Sample("2018", "Wjets", "WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8", 1395.0, 1, gid_Wjets, 1100, 924, 29385684.0, 0) );
bkgSamples.push_back( new Sample("2018", "Wjets", "WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8", 407.9, 1, gid_Wjets, 1100, 924, 25415130.0, 0) );
bkgSamples.push_back( new Sample("2018", "Wjets", "WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8", 57.48, 1, gid_Wjets, 1100, 924, 5913598.0, 0) );
bkgSamples.push_back( new Sample("2018", "Wjets", "WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8", 12.87, 1, gid_Wjets, 1100, 924, 19690764.0, 0) );
bkgSamples.push_back( new Sample("2018", "Wjets", "WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8", 5.366, 1, gid_Wjets, 1100, 924, 8357922.5, 0) );
bkgSamples.push_back( new Sample("2018", "Wjets", "WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8", 1.074, 1, gid_Wjets, 1100, 924, 7567070.5, 0) );
bkgSamples.push_back( new Sample("2018", "Wjets", "WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8", 0.008001, 1, gid_Wjets, 1100, 924, 3189396.0, 0) );
bkgSamples.push_back( new Sample("2018", "Zjets", "DYJetsToLL_M-50_HT-70to100_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8", 167.33, 1, gid_Zjets, 1100, 4, 10010341.0, 0) );
bkgSamples.push_back( new Sample("2018", "Zjets", "DYJetsToLL_M-50_HT-100to200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8", 161.1, 1, gid_Zjets, 1100, 4, 11516746.0, 0) );
bkgSamples.push_back( new Sample("2018", "Zjets", "DYJetsToLL_M-50_HT-200to400_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8", 48.66, 1, gid_Zjets, 1100, 4, 10840079.0, 0) );
bkgSamples.push_back( new Sample("2018", "Zjets", "DYJetsToLL_M-50_HT-400to600_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8", 6.968, 1, gid_Zjets, 1100, 4, 46027504.0, 0) );
bkgSamples.push_back( new Sample("2018", "Zjets", "DYJetsToLL_M-50_HT-600to800_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8", 1.743, 1, gid_Zjets, 1100, 4, 8826238.0, 0) );
bkgSamples.push_back( new Sample("2018", "Zjets", "DYJetsToLL_M-50_HT-800to1200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8", 0.8052, 1, gid_Zjets, 1100, 4, 3120982.0, 0) );
bkgSamples.push_back( new Sample("2018", "Zjets", "DYJetsToLL_M-50_HT-1200to2500_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8", 0.1933, 1, gid_Zjets, 1100, 4, 531566.875, 0) );
bkgSamples.push_back( new Sample("2018", "Zjets", "DYJetsToLL_M-50_HT-2500toInf_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8", 0.003468, 1, gid_Zjets, 1100, 4, 415517.0, 0) );
}
#endif