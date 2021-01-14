#!/bin/bash
# Purpose: to generate vbsDL.hpp file
# Usage ::  Edit *VARS* lists; ./write_vbsDL.sh  
#
#Variable description
#   plotvar	MINRange  MAXRange  NBINS  slog xlabel outfile AMINRange  AMAXRange ANBINS drawleg
#plotvar( anl, var,        cut,   scale=1.0, debug=0, istyle=0,   xmin,xmax, binwdth, flogy=0, flogx=0, hTitle[], xTitle[]="test", yTitle[]);

#------------   VERTICES  	-------------------

#plotvar(anl, "nPV", tmvasel+allCuts,  1.0, 1, 0,  0, 50, 1,       1, 0,  "VBS (WV), 35.9 fb^{-1}", "Number of primary vertices", "Events/bin")
#------------    LEPTONS  	-------------------

# { "l_pt1",		0, 390, 26, 3,		"Lepton p_{T} (GeV)",     "lepton_pt",       0,  390, 26, 1 },
# plotvar(anl, "l_pt1",  tmvasel+allCuts,  1.0, 1, 0,   0., 600., 10,      1, 0,  "VBS (WV), 35.9 fb^{-1}", "Lepton_1 p_{T} (GeV)", "Events/bin")
# plotvar(anl, "l_eta1", tmvasel+allCuts,  1.0, 1, 0,  -3.5,  6.5, .5,   1, 0,  "VBS (WV), 35.9 fb^{-1}", "Lepton_1 #eta", "Events/bin")
# plotvar(anl, "l_phi1", tmvasel+allCuts,  1.0, 1, 0,  0., 1.8*TMath::Pi(), 0.125*TMath::Pi(),   1, 0,  "VBS (WV), 35.9 fb^{-1}", "Lepton_1 #phi", "Events/bin")
# plotvar(anl, "l_charge1", tmvasel+allCuts,  1.0, 1, 0,  -2.5, 5.5, 1,     1, 0,  "VBS (WV), 35.9 fb^{-1}", "Lepton_1 charge", "Events/bin")
# plotvar(anl, "l_e1",    tmvasel+allCuts,  1.0, 1, 0,   0., 600., 10,       1, 0,  "VBS (WV), 35.9 fb^{-1}", "Lepton_1 energy", "Events/bin")
# plotvar(anl, "l_iso1",  tmvasel+allCuts,  1.0, 1, 0,   0., 0.5, 0.02,       1, 0,  "VBS (WV), 35.9 fb^{-1}", "Lepton_1 isolation", "Events/bin")

#
##-------------- 	MET	-------------------
# plotvar(anl, "pfMET_Corr",  tmvasel+allCuts,  1.0, 1, 0,   0., 600., 10,      1, 0,  "VBS (WV), 35.9 fb^{-1}", "pfMET_Corr (GeV)", "Events/bin")
# plotvar(anl, "pfMET_Corr_phi",  tmvasel+allCuts,  1.0, 1, 0,   0., 1.8*TMath::Pi(), 0.125*TMath::Pi(),      1, 0,  "VBS (WV), 35.9 fb^{-1}", "pfMET_Corr_phi", "Events/bin")
# plotvar(anl, "nu_pz_type0",  tmvasel+allCuts,  1.0, 1, 0,   -500., 500., 20,      1, 0,  "VBS (WV), 35.9 fb^{-1}", "Reconstructed Neutrino p_{Z}", "Events/bin")
#
##--------------	AK8 Jet		------------
# plotvar(anl, "nGoodPuppiAK8jets",  tmvasel+allCuts,  1.0, 1, 0,  0., 10., 1,      1, 0,  "VBS (WV), 35.9 fb^{-1}", "Number of Good AK8 jets", "Events/bin")
# plotvar(anl, "ungroomed_PuppiAK8_jet_pt",  tmvasel+allCuts,  1.0, 1, 0,   0., 1400., 20,      1, 0,  "VBS (WV), 35.9 fb^{-1}", "AK8 p_{T} (GeV)", "Events/bin")
# plotvar(anl, "ungroomed_PuppiAK8_jet_eta", tmvasel+allCuts,  1.0, 1, 0,  -3.5,  6.5, .5,   1, 0,  "VBS (WV), 35.9 fb^{-1}", "AK8 #eta", "Events/bin")
# plotvar(anl, "ungroomed_PuppiAK8_jet_phi", tmvasel+allCuts,  1.0, 1, 0,  0., 1.8*TMath::Pi(), 0.125*TMath::Pi(),   1, 0,  "VBS (WV), 35.9 fb^{-1}", "AK8 #phi", "Events/bin")
# plotvar(anl, "ungroomed_PuppiAK8_jet_charge", tmvasel+allCuts,  1.0, 1, 0,  -2.5, 5.5, 0.1,     1, 0,  "VBS (WV), 35.9 fb^{-1}", "AK8 charge", "Events/bin")
# plotvar(anl, "ungroomed_PuppiAK8_jet_e",    tmvasel+allCuts,  1.0, 1, 0,   0., 1400., 20,       1, 0,  "VBS (WV), 35.9 fb^{-1}", "AK8  energy", "Events/bin")
#
# plotvar(anl, "PuppiAK8_jet_mass",         tmvasel+allCuts,  1.0, 1, 0,  20., 220., 10,       1, 0,  "VBS (WV), 35.9 fb^{-1}",    "AK8 mass (GeV)",           "Events/bin")
# plotvar(anl, "PuppiAK8_jet_mass_pr",      tmvasel+allCuts,  1.0, 1, 0,  20., 220., 10,       1, 0,  "VBS (WV), 35.9 fb^{-1}",    "AK8 pruned mass (GeV)",    "Events/bin")
# plotvar(anl, "PuppiAK8_jet_mass_so_corr", tmvasel+allCuts,  1.0, 1, 0,  20., 220., 10,       1, 0,  "VBS (WV), 35.9 fb^{-1}",    "AK8 Softdrop mass (GeV)",  "Events/bin")
# plotvar(anl, "PuppiAK8_jet_mass_tr",      tmvasel+allCuts,  1.0, 1, 0,  20., 220., 10,       1, 0,  "VBS (WV), 35.9 fb^{-1}",    "AK8 tr mass (GeV)",        "Events/bin")
# plotvar(anl, "PuppiAK8_jet_tau2tau1",     tmvasel+allCuts,  1.0, 1, 0,  0., 1., 0.1,          1, 0,  "VBS (WV), 35.9 fb^{-1}",   "AK8 #tau_{2}/#tau_{1}",      "Events/bin")
# plotvar(anl, "PuppiAK8jet_qjet",          tmvasel+allCuts,  1.0, 1, 0,  0., 3., 0.1,          1, 0,  "VBS (WV), 35.9 fb^{-1}",   "PuppiAK8jet_qjet",      "Events/bin")

#####	Leptonic & Hadronic W-boson 
# plotvar(anl, "v_pt_type0",     tmvasel+allCuts,  1.0, 1, 0,  0., 1000., 20,          1, 0,  "VBS (WV), 35.9 fb^{-1}",   "W p_{T} (GeV)",      "Events/bin")
# plotvar(anl, "v_mt_type0",     tmvasel+allCuts,  1.0, 1, 0,  0., 500.,  20,     1, 0,  "VBS (WV), 35.9 fb^{-1}",   "W Transverse Mass (GeV)",      "Events/bin")

##--------------	VBF Jet		------------
# plotvar(anl, "njets",  tmvasel+allCuts,  1.0, 1, 0,  0., 10., 1,      1, 0,  "VBS (WV), 35.9 fb^{-1}", "Number of VBF jets", "Events/bin")
# plotvar(anl, "nBTagJet_loose",    tmvasel+allCuts,  1.0, 1, 0,  0., 10., 1,      1, 0,  "VBS (WV), 35.9 fb^{-1}", "Number of VBF jets (Loose b-tag)", "Events/bin")
# plotvar(anl, "nBTagJet_medium",   tmvasel+allCuts,  1.0, 1, 0,  0., 10., 1,      1, 0,  "VBS (WV), 35.9 fb^{-1}", "Number of VBF jets (Medium b-tag)", "Events/bin")
# plotvar(anl, "vbf_maxpt_j1_eta",  tmvasel+allCuts,  1.0, 1, 0,  -6,  10, .5,   1, 0,  "VBS (WV), 35.9 fb^{-1}", "Leading VBF Jet #eta", "Events/bin")
# plotvar(anl, "vbf_maxpt_j2_eta",  tmvasel+allCuts,  1.0, 1, 0,  -6,  10, .5,   1, 0,  "VBS (WV), 35.9 fb^{-1}", "Sub-Leading VBF Jet #eta", "Events/bin")
# plotvar(anl, "vbf_maxpt_j1_pt",   tmvasel+allCuts,  1.0, 1, 0,  20,  720, 20,   1, 0,  "VBS (WV), 35.9 fb^{-1}", "Leading VBF Jet  p_{T}", "Events/bin")
# plotvar(anl, "vbf_maxpt_j2_pt",   tmvasel+allCuts,  1.0, 1, 0,  20,  720, 20,    1, 0,  "VBS (WV), 35.9 fb^{-1}", "Sub-Leading VBF Jet p_{T}", "Events/bin")
# plotvar(anl, "vbf_maxpt_jj_m",    tmvasel+allCuts,  1.0, 1, 0,  200,  4200, 100,    1, 0,  "VBS (WV), 35.9 fb^{-1}", "VBF M_{jj} GeV", "Events/bin")
# plotvar(anl, "vbf_maxpt_jj_Deta", tmvasel+allCuts,  1.0, 1, 0,  0.0,  20.0, 0.5,    1, 0,  "VBS (WV), 35.9 fb^{-1}", "VBF #Delta #eta", "Events/bin")

#
##----------------	4 body mass	---------------
# plotvar(anl, "mass_lvj_type0_PuppiAK8",    tmvasel+allCuts,  1.0, 1, 0,  0.0,  2500., 50,    1, 0,  "VBS (WV), 35.9 fb^{-1}", "mass_lvj_type0_PuppiAK8_4bin ( M_{WW} ) (GeV)", "Events/bin")
# plotvar(anl, "mt_lvj_type0_PuppiAK8",      tmvasel+allCuts,  1.0, 1, 0,  0.0,  2500., 50,    1, 0,  "VBS (WV), 35.9 fb^{-1}", "mt_lvj_type0_PuppiAK8_4bin ( MT_{WW} )  (GeV)", "Events/bin")
#======================================================================================================================================================================
##--------------	AK8 Jet		------------

### { "PuppiAK8_jet_mass", 	40, 150, 11, 3, "AK8 mass (GeV)",		"AK8_mass",    40.0, 150, 11, 1},
### { "PuppiAK8_jet_mass_pr", 	40, 150, 11, 3, "AK8 pruned mass (GeV)",	"AK8_mass_pr", 40.0, 150, 11, 1},
# #{ "PuppiAK8_jet_mass_so_corr", 	65, 105, 13, 3, "AK8 Softdrop mass (GeV)",	"AK8_mass_so_LSB", 65, 105, 13, 1},
# { "PuppiAK8_jet_mass_so_corr", 	40, 150, 22, 3, "AK8 Softdrop mass (GeV)",	"AK8_mass_so_22bin", 40.0, 150, 22, 1},
# { "PuppiAK8_jet_mass_so_corr", 	40, 150, 11, 3, "AK8 Softdrop mass (GeV)",	"AK8_mass_so_11bin", 40.0, 150, 11, 1},
### { "PuppiAK8_jet_mass_tr", 	40, 150, 11, 3, "AK8 tr mass (GeV)", 		"AK8_mass_tr", 40.0, 150, 11, 1},
### { "PuppiAK8_jet_mass", 	65, 105, 5, 3, "AK8 mass (GeV)",		"AK8_mass",    65, 105, 5, 1},
### { "PuppiAK8_jet_mass_pr", 	65, 105, 5, 3, "AK8 pruned mass (GeV)",		"AK8_mass_pr", 65, 105, 5, 1},
### { "PuppiAK8_jet_mass_tr", 	65, 105, 5, 3, "AK8 tr mass (GeV)", 		"AK8_mass_tr", 65, 105, 5, 1},
## { "PuppiAK8_jet_sj1_pt",	0, 800, 25, 3, "AK8 SJ1 pT (GeV)",	"PuppiAK8_jet_sj1_pt", 0, 800, 25, 1},
## { "PuppiAK8_jet_sj1_eta",	-2.4, 2.4, 25, 1, "AK8 SJ1 #eta",	"PuppiAK8_jet_sj1_eta", -2.4, 2.4, 25, 1},
## { "PuppiAK8_jet_sj1_phi",	-3, 3, 25, 6, "AK8 SJ1 #phi",	"PuppiAK8_jet_sj1_phi", -3, 3, 25, 1},
## { "PuppiAK8_jet_sj1_m",	0, 90, 25, 3, "AK8 SJ1 mass (GeV)",	"PuppiAK8_jet_sj1_m", 0, 90, 25, 1},
## { "PuppiAK8_jet_sj1_q",	-1, 1, 25, 1, "AK8 SJ1 charge",	"PuppiAK8_jet_sj1_q", -1, 1, 25, 1},
## { "PuppiAK8_jet_sj2_pt",	0, 400, 25, 3, "AK8 SJ2 pT (GeV)",	"PuppiAK8_jet_sj2_pt", 0, 400, 25, 1},
## { "PuppiAK8_jet_sj2_eta",	-2.4, 2.4, 25, 1, "AK8 SJ2 #eta",	"PuppiAK8_jet_sj2_eta", -2.4, 2.4, 25, 1},
## { "PuppiAK8_jet_sj2_phi",	-3, 3, 25, 6, "AK8 SJ2 #phi",	"PuppiAK8_jet_sj2_phi", -3, 3, 25, 1},
## { "PuppiAK8_jet_sj2_m",	0, 150, 25, 3, "AK8 SJ2 mass (GeV)",	"PuppiAK8_jet_sj2_m", 0, 150, 25, 1},
## { "PuppiAK8_jet_sj2_q",	-1, 1, 25, 1, "AK8 SJ2 charge",	"PuppiAK8_jet_sj2_q", -1, 1, 25, 1},
## { "PuppiAK8_jet_sj1_q*PuppiAK8_jet_sj2_q",	-20, 20, 25, 1, "AK8 (SJ1_q #times SJ2_q)",	"PuppiAK8_SJ1J2_chargeMultiplication", -20, 20, 25, 1},
### { "PuppiAK8jet_qjet",		0, 2, 20, 1, "PuppiAK8jet_qjet", 	"PuppiAK8jet_qjet", 0, 2, 20, 1},
# { "PuppiAK8_jet_tau2tau1", 		0, 0.55, 10, 1, "AK8 #tau_{2}/#tau_{1}", 		"Puppi_AK8_jet_tau2tau1",0,0.55,10,0},
#
#
##--------------	VBF Jet		------------
# { "njets",  0, 10, 10, 1, "Number of VBF jets",	"njets", 0, 10, 10, 1},
# { "nBTagJet_loose", 0, 6, 6, 1, "number of VBF jets (Loose b-tag)", "nBTagJet_loose", 0, 6, 6, 1},
# { "nBTagJet_medium", 0, 6, 6, 1, "number of VBF jets (medium b-tag)", "nBTagJet_medium", 0, 6, 6, 1},
# { "vbf_maxpt_j1_eta", -5.0, 5.0, 20, 1,	"Leading VBF Jet #eta",	"vbf_maxpt_j1_eta", 	-5.0, 5.0, 20, 0},
# { "vbf_maxpt_j2_eta", -5.0, 5.0, 20, 1,	"Sub-Leading VBF Jet #eta", "vbf_maxpt_j2_eta", -5.0, 5.0, 20, 0},
# { "vbf_maxpt_j2_pt", 30,330, 12, 3,		"Sub-Leading VBF Jet p_{T}", "vbf_maxpt_j2_pt", 30,330,12,0 },
# { "vbf_maxpt_j1_pt", 30, 630, 24, 3,		"Leading VBF Jet p_{T}",	"vbf_maxpt_j1_pt", 30,630,24,1 },
# { "vbf_maxpt_jj_m", 	500, 2500, 20, 3,		"VBF M_{jj} GeV",	"vbf_maxpt_jj_m",  500, 2500, 20, 1},
# { "vbf_maxpt_jj_Deta",	0.0, 9, 18, 1,	"VBF #Delta #eta",	"vbf_maxpt_jj_Deta", 0.0,9, 18, 1 },
#
#
##----------------	4 body mass	---------------
#
#{ "mass_lvj_type0_PuppiAK8", 	600, 2500, 4, 3, "M_{WW} (GeV)",		"mass_lvj_type0_PuppiAK8_4bin",    600, 2500, 4, 1},
# #{ "mt_lvj_type0_PuppiAK8", 	600, 2500, 4, 3, "MT_{WW} (GeV)",		"mt_lvj_type0_PuppiAK8_4bin",    600, 2500, 4, 1},
# #{ "mass_lvj_type0_PuppiAK8", 	600, 2500, 38, 3, "M_{WW} (GeV)",		"mass_lvj_type0_PuppiAK8_38bin",    600, 2500, 38, 1},
# #{ "mt_lvj_type0_PuppiAK8", 	600, 2500, 38, 3, "MT_{WW} (GeV)",		"mt_lvj_type0_PuppiAK8_38bin",    600, 2500, 38, 1},
# { "mass_lvj_type0_PuppiAK8", 	600, 2500, 19, 3, "M_{WW} (GeV)",		"mass_lvj_type0_PuppiAK8_19bin",    600, 2500, 19, 1},
# { "mt_lvj_type0_PuppiAK8", 	600, 2500, 19, 3, "MT_{WW} (GeV)",		"mt_lvj_type0_PuppiAK8_19bin",    600, 2500, 19, 1},
# { "mass_lvj_type0_PuppiAK8", 	600, 2500, 38, 3, "M_{WW} (GeV)",		"mass_lvj_type0_PuppiAK8_38bin",    600, 2500, 38, 1},
# { "mass_lvj_type0_PuppiAK8", 	0.0, 2500, 50, 3, "M_{WW} (GeV)",		"mass_lvj_type0_PuppiAK8_38bin",    0.0, 2500, 50, 1},
##
#####	Leptonic & Hadronic W-boson 
# { "v_pt_type0",		0, 800, 16, 3,	"W p_{T} (GeV)",		"v_pt", 	 0, 800, 16, 1 },
# { "v_mt_type0",		0, 400, 8, 3,	"W Transverse Mass (GeV)",	"v_mt", 	 0, 400, 8, 0 },
##
###----------	Other Variables	------------------------
##
# { "deltaR_lPuppiak8jet", 0, 7.0, 20, 1, "#Delta R(l,AK8 jet)", "deltaR_lPuppiak8jet", 0, 7.0, 20, 1},
# { "deltaphi_METPuppiak8jet", 0, 3.14, 15, 1, "#Delta #phi(pfMET,AK8 jet)", "deltaphi_METPuppiak8jet", 0, 3.14, 15, 1},
# { "deltaphi_METvbfJ1", 0, 3.14, 15, 1, "#Delta #phi(pfMET,jet1)", "deltaphi_METvbfJ1", 0, 3.14, 15, 1},
# { "deltaphi_METvbfJ2", 0, 3.14, 15, 1, "#Delta #phi(pfMET,jet2)", "deltaphi_METvbfJ2", 0, 3.14, 15, 1},
# { "deltaphi_METmin", 0, 3.14, 15, 1, "#Delta #phi(pfMET,jets)_{min}", "deltaphi_METmin", 0, 3.14, 15, 1},
# { "deltaphi_VPuppiak8jet",0, 3.14, 15, 1, "#Delta #phi(Leptonic W,AK8 jet)", "deltaphi_VPuppiak8jet", 0, 3.14, 15, 1},
# { "(ungroomed_PuppiAK8_jet_pt-l_pt1)/pfMET_Corr",	0, 10, 40, 1, "(AK8 p_{T} - Lepton p_{T})/pfMET",		"AK8minusLeptonptByMet",  0, 10, 40, 1 },
# { "vbf_maxpt_j2_pt/pfMET_Corr",	0, 5, 20, 1, "Sub-leading VBF p_{T}/pfMET",		"SubLeadingVBFptByMet",  0, 5, 20, 1 },
# { "vbf_maxpt_j1_pt/pfMET_Corr",	0, 15, 20, 1, "Leading VBF p_{T}/pfMET",		"LeadingVBFptByMet",  0, 15, 20, 1 },
# { "(vbf_maxpt_j1_pt+vbf_maxpt_j2_pt+ungroomed_PuppiAK8_jet_pt+l_pt1)/pfMET_Corr",	0, 30, 20, 1, "H_{T}/pfMET",		"HTByMET",  0, 30, 20, 1 },
#  { "BDT_response", -1.0,1.0,20,1, "BDT Response",  "BDT_response", -1.0, 1.0, 20, 1},
# { "PuppiAK8jet_e3_sdb1/(PuppiAK8jet_e2_sdb1*PuppiAK8jet_e2_sdb1*PuppiAK8jet_e2_sdb1)", 	0.05,3.5,25, 1, "D2",	"d2_ECF", 0.05,3.5,25, 1},
# { "PuppiAK8jet_e3_v2_sdb1/(PuppiAK8jet_e2_sdb1*PuppiAK8jet_e2_sdb1)", 	0.00,0.5,25, 1, "N2",	"n2_ECF", 0.00,0.5,25, 1},
# { "l_pt1+ungroomed_PuppiAK8_jet_pt+vbf_maxpt_j1_pt+vbf_maxpt_j2_pt",	0, 1500, 15, 3, "HT", "ht", 0, 1500, 15, 1},
#
#
# { "PtBalance_type0",		0, 1.0, 10, 1,	"p_{T} Balance",	"PtBalance_type0",	0, 1.0, 10, 1 },
# { "BosonCentrality_type0",	1, 4.0, 10, 1, 	"Boson Centrality",	"BosonCentrality_type0",1, 4.0, 10, 1 },
##
### Angular variables
## #{ "LeptonProjection_run2", 	0, 2, 10, 1, "LeptonProjection_run2"  , "LeptonProjection_run2" ,0, 2, 10, 1}, 
## #{ "LeptonProjection_type2", 	0, 2, 10, 1, "LeptonProjection_type2"  , "LeptonProjection_type2" ,0, 2, 10, 1}, 
## { "LeptonProjection_type0", 	0, 2, 10, 1, "Lepton Projection"  , "LeptonProjection_type0" ,0, 2, 10, 1}, 
## #{ "ZeppenfeldWL_run2", 	-5, 5, 10, 1, "ZeppenfeldWL_run2"  , "ZeppenfeldWL_run2" , -5, 5, 10, 0}, 
## #{ "ZeppenfeldWL_type2", 	-5, 5, 10, 1, "ZeppenfeldWL_type2"  , "ZeppenfeldWL_type2" , -5, 5, 10, 0}, 
## { "ZeppenfeldWL_type0", 	-4, 4, 10, 1, "Zeppenfeld (with leptonic W)"  , "ZeppenfeldWL_type0" , -4, 4, 10, 0}, 
## { "ZeppenfeldWH", 	-4, 4, 10, 1, 		"Zeppenfeld (with hadronic W)"  , "ZeppenfeldWH" , -4, 4, 10, 0}, 
# { "ZeppenfeldWL_type0/vbf_maxpt_jj_Deta", 	-0.3, 0.3, 10, 1, "ZeppenfeldWL/#Delta #eta jj"  , "ZeppenfeldWL_type0_new" , -0.3, 0.3, 10, 1},  
# { "ZeppenfeldWH/vbf_maxpt_jj_Deta", 	-0.3, 0.3, 10, 1, 		"ZeppenfeldWH/#Delta #eta jj"  , "ZeppenfeldWH_new" , -0.3, 0.3, 10, 1}, 
## #{ "RpT_run2", 		0, 80, 10, 1, 		"RpT_run2"  , "RpT_run2" ,	0, 80, 10, 1}, 
## #{ "RpT_type2", 	0, 80, 10, 1, 		"RpT_type2"  , "RpT_type2",	0, 80, 10, 1}, 
## { "RpT_type0", 	0, 80, 10, 1, 		"RpT"  , "RpT_type0",	0, 80, 10, 1}, 
## { "WWRapidity", 	-2.5, 2.5, 10, 1, 	"WW Rapidity"  , "TempWWRapidity" , -2.5, 2.5, 10, 0}, 
# #{ "VBSCentrality_run2", 	0, 3, 10, 1, 	"VBSCentrality_run2"  , "VBSCentrality_run2" , 0, 3, 10, 1}, 
# #{ "VBSCentrality_type2", 	0, 3, 10, 1, 	"VBSCentrality_type2"  , "VBSCentrality_type2" , 0, 3, 10, 1}, 
# { "VBSCentrality_type0", 	0, 3, 10, 1, 	"VBSCentrality"  , "VBSCentrality_type0" , 0, 3, 10, 1}, 
# #{ "costhetastar_run2", 	-1,1, 10, 1, 	"costhetastar_run2"  , "costhetastar_run2" ,-1,1, 10, 1}, 
# #{ "costhetastar_type2", 	-1,1, 10, 1, 	"costhetastar_type2"  , "costhetastar_type2" ,-1,1, 10, 1}, 
# { "costhetastar_type0", 	-1,1, 10, 6, 	"costhetastar"  , "costhetastar_type0" ,-1,1, 10, 1}, 
# #{ "costheta1_run2", 	-1,1, 10, 1, 	"costheta1_run2"  , "costheta1_run2" ,-1,1, 10, 0}, 
# #{ "costheta1_type2", 	-1,1, 10, 1, 	"costheta1_type2"  , "costheta1_type2" ,-1,1, 10, 0}, 
# { "costheta1_type0", 	-1,1, 10, 6, 	"costheta1"  , "costheta1_type0" ,-1,1, 10, 0}, 
# #{ "costheta2_run2", 	-1,1, 10, 6, 	"costheta2_run2"  , "costheta2_run2" ,-1,1, 10, 0}, 
# #{ "costheta2_type2", 	-1,1, 10, 6, 	"costheta2_type2"  , "costheta2_type2" ,-1,1, 10, 0}, 
# { "costheta2_type0", 	-1,1, 10, 6, 	"costheta2"  , "costheta2_type0" ,-1,1, 10, 0}, 
# #{ "phi_run2", 	-3.5, 3.5, 20, 6, 	"phi_run2"  ,  "phi_run2" ,  -3.5, 3.5, 20, 0}, 
# #{ "phi_type2", 	-3.5, 3.5, 20, 6,	"phi_type2"  , "phi_type2" , -3.5, 3.5, 20, 0}, 
# { "phi_type0", 	-3.5, 3.5, 20, 6, 	"phi"  , "phi_type0" , -3.5, 3.5, 20, 0}, 
# #{ "phi1_run2", 	-3.5, 3.5, 20, 6, 	"phi1_run2"  ,  "phi1_run2" ,  -3.5, 3.5, 20, 0}, 
# #{ "phi1_type2", 	-3.5, 3.5, 20, 6,	"phi1_type2"  , "phi1_type2" , -3.5, 3.5, 20, 0}, 
# { "phi1_type0", 	-3.5, 3.5, 20, 6, 	"phi1"  , "phi1_type0" , -3.5, 3.5, 20, 0}, 
# { "ungroomed_PuppiAK8_jet_pt/pfMET_Corr",	0, 15, 15, 3, "AK8 p_{T}/pfMET",		"AK8ptByMet",  0, 15, 15, 1 },
# { "l_pt1/pfMET_Corr",	0, 10, 20, 1, "Lepton p_{T}/pfMET",		"LeptonptByMet",  0, 10, 20, 1 },
# { "pfMET_Corr/(sqrt(vbf_maxpt_j1_pt+vbf_maxpt_j2_pt+ungroomed_PuppiAK8_jet_pt+l_pt1))",		0, 24, 12, 3,		"s = E_{T}^{miss}/#sqrt{#sum E_{T}}",     "s_dist",       0,  24, 12, 1 },



TMVAVARS=" l_pt1  l_eta1 pfMET_Corr ungroomed_PuppiAK8_jet_pt PuppiAK8_jet_tau2tau1 PuppiAK8_jet_mass_so_corr vbf_maxpt_jj_m vbf_maxpt_j2_eta vbf_maxpt_j1_eta vbf_maxpt_j1_pt  vbf_maxpt_j2_pt mass_lvj_type0_PuppiAK8 BosonCentrality_type0 ZeppenfeldWL_type0 ZeppenfeldWH"
activeVARS="gid sid mcWeight run event nTotEvents lumi  L1_Prefweight totalEventWeight type isVBF nBTagJet_loose btag0Wgt genWeight trig_eff_Weight id_eff_Weight pu_Weight l_pt2  ungroomed_PuppiAK8_jet_eta $TMVAVARS"

#from controlplotvars
plotVARS="nPV l_pt1 l_eta1 l_iso1 l_phi1 l_e1 l_charge1    pfMET_Corr pfMET_Corr_phi nu_pz_type0   mass_lvj_type0_PuppiAK8 mt_lvj_type0_PuppiAK8  v_pt_type0 v_mt_type0"
plotVARS_AK8jet="nGoodPuppiAK8jets ungroomed_PuppiAK8_jet_pt  ungroomed_PuppiAK8_jet_pt ungroomed_PuppiAK8_jet_eta ungroomed_PuppiAK8_jet_phi ungroomed_PuppiAK8_jet_e ungroomed_PuppiAK8_jet_charge PuppiAK8_jet_mass PuppiAK8_jet_mass_pr PuppiAK8_jet_mass_so_corr PuppiAK8_jet_mass_tr PuppiAK8_jet_sj1_pt PuppiAK8_jet_sj1_eta PuppiAK8_jet_sj1_phi PuppiAK8_jet_sj1_m  PuppiAK8_jet_sj1_q PuppiAK8_jet_sj2_pt PuppiAK8_jet_sj2_eta PuppiAK8_jet_sj2_phi PuppiAK8_jet_sj2_m PuppiAK8_jet_sj2_q PuppiAK8jet_qjet PuppiAK8_jet_tau2tau1"

plotVARS_VBFJet="njets nBTagJet_loose nBTagJet_medium vbf_maxpt_j1_eta vbf_maxpt_j2_eta vbf_maxpt_j2_pt vbf_maxpt_j1_pt vbf_maxpt_jj_m vbf_maxpt_jj_Deta"

#Paper set (minimum)
#plotVARS_Other="deltaR_lPuppiak8jet deltaphi_METPuppiak8jet deltaphi_METvbfJ1 deltaphi_METvbfJ2 deltaphi_METmin deltaphi_VPuppiak8jet PtBalance_type0 BosonCentrality_type0"

#Angle studies
plotVARS_Other="deltaR_lPuppiak8jet deltaphi_METPuppiak8jet deltaphi_METvbfJ1 deltaphi_METvbfJ2 deltaphi_METmin deltaphi_VPuppiak8jet PtBalance_type0 BosonCentrality_type0  costheta1_type0 costheta2_type0 costhetastar_type0  phi_type0 phi1_type0  PtBalance_type2 costheta1_type2 costheta2_type2 costhetastar_type2 phi_type2 phi1_type2"


SUanlVARS="$(echo $activeVARS $plotVARS ${plotVARS_AK8jet} ${plotVARS_VBFJet}  ${plotVARS_Other} | sort | tr -s '\ '  '\n'  | sort | uniq )"
#SUanlVARS="$(echo $activeVARS $plotVARS ${plotVARS_AK8jet} ${plotVARS_VBFJet}  ${plotVARS_Other} | sort | uniq -u)"

#echo $SUanlVARS

#return 0;

outfile="vbsDL.hpp"
ActiveBranchesOutfile="vbsActiveBranches.hpp"
if [ -f $outfile ]; then /bin/rm -f vbsDL.hpp; fi
echo "Creating $outfile"
cat >>$outfile <<EOF
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
//
allVARS="$(cat vbsReducedTree.hpp | grep SetBranchAddress | awk '{print $2}' | sed 's/\"//g'| sed 's/,//g')"

for var in $SUanlVARS; do
  isVarArray="$(cat vbsReducedTree.hpp | grep $var | grep '\[')"
  typevar="$(cat vbsReducedTree.hpp | grep -v SetBranchAddress |  grep -v Branch | grep -v typedef |  grep $var  | awk '{print $1}'| sort | uniq | awk '{print $1}')"
  nw="$(echo $typevar | wc -w)"
  if [ $nw != "1" ]; then  echo $typevar   $var; fi
  if   [ "$typevar " == "Float_t " ]; then
   typevar="F"
  else 
   #echo $typevar
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
       echo "//TMVA variable" >> $outfile
       echo "if(dataloader) dataloader->AddVariable(\"$var\",    \"$var\",   \"\",      '$typevar');" >> $outfile
       if [ "0$isVarArray" == "0" ]; then 
         echo "if(datareader) datareader->AddVariable(\"$var\",    &vbsEvent.$var        );" >> $outfile
       else
         echo "///if(datareader) datareader->AddVariable(\"$var\",    &vbsEvent.${var}[0]     );" >> $outfile
       fi
       echo " " >> $outfile
       echo "Variable::" $var 

       else 
       echo "//TMVA spectator " >> $outfile
       echo "if(dataloader) dataloader->AddSpectator(\"$var\",    \"$var\",   \"\",      '$typevar');" >> $outfile
       if [ "0$isVarArray" == "0" ]; then 
         echo "if(datareader) datareader->AddSpectator(\"$var\",    &vbsEvent.$var        );" >> $outfile
       else
         echo "//if(datareader) datareader->AddSpectator(\"$var\",    &vbsEvent.${var}[0]   );" >> $outfile
       fi
       echo " " >> $outfile
       echo "Spectator::" $var  
 fi


done
cat >>$outfile <<EOF
}
//=======================================
//========================================
void setChainBranches (TChain* inpChain){
//
   inpChain->SetBranchStatus("*", 0);   // disable all branches
// switch on required  branches
EOF
for var in $SUanlVARS; do
echo "inpChain->SetBranchStatus(\"$var\", 1);" >>  $outfile
done
cat >> $outfile <<EOF
}
//=======================================
#endif
EOF



#===Write ActiveBranchesOutfile
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
