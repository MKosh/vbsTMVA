#ifndef vbsReducedTree_hpp
#define vbsReducedTree_hpp
//////////////////////////////////////////////////////////
// This class has been automatically generated by write_vbsDL.sh on
// Tue Nov 16 09:08:59 PM EST 2021
// from TTree Events
// found on file: DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_01.root
//////////////////////////////////////////////////////////
//VbsReducedEvent structure (keeps variables of the VbsAnalysisReduced ntuple)
typedef struct {
//Additional branches - to be added
   Int_t           gid;                  // - group  ID
   Int_t           sid;                  // - sample ID
   Float_t         mcWeight;             //== xsect/ngen 
//
   // Declaration of leaf types

Int_t		evt;
Int_t		ls;
Int_t		nAqgcWeight;
Int_t		nBtag_loose;
Int_t		nBtag_medium;
Int_t		nBtag_tight;
Int_t		nJet30;
Int_t		nJet50;
Int_t		nPdfWeight;
Int_t		nScaleWeight;
Int_t		run;
Float_t		aqgcWeight;
Float_t		bos_AK4AK4_eta;
Float_t		bos_AK4AK4_m;
Float_t		bos_AK4AK4_m_jesAbsoluteDown;
Float_t		bos_AK4AK4_m_jesAbsoluteUp;
Float_t		bos_AK4AK4_m_jesAbsolute_YearDown;
Float_t		bos_AK4AK4_m_jesAbsolute_YearUp;
Float_t		bos_AK4AK4_m_jesBBEC1Down;
Float_t		bos_AK4AK4_m_jesBBEC1Up;
Float_t		bos_AK4AK4_m_jesBBEC1_YearDown;
Float_t		bos_AK4AK4_m_jesBBEC1_YearUp;
Float_t		bos_AK4AK4_m_jesEC2Down;
Float_t		bos_AK4AK4_m_jesEC2Up;
Float_t		bos_AK4AK4_m_jesEC2_YearDown;
Float_t		bos_AK4AK4_m_jesEC2_YearUp;
Float_t		bos_AK4AK4_m_jesFlavorQCDDown;
Float_t		bos_AK4AK4_m_jesFlavorQCDUp;
Float_t		bos_AK4AK4_m_jesHFDown;
Float_t		bos_AK4AK4_m_jesHFUp;
Float_t		bos_AK4AK4_m_jesHF_YearDown;
Float_t		bos_AK4AK4_m_jesHF_YearUp;
Float_t		bos_AK4AK4_m_jesRelativeBalDown;
Float_t		bos_AK4AK4_m_jesRelativeBalUp;
Float_t		bos_AK4AK4_m_jesRelativeSample_YearDown;
Float_t		bos_AK4AK4_m_jesRelativeSample_YearUp;
Float_t		bos_AK4AK4_m_jesTotalDown;
Float_t		bos_AK4AK4_m_jesTotalUp;
Float_t		bos_AK4AK4_phi;
Float_t		bos_AK4AK4_pt;
Float_t		bos_AK4AK4_pt_jesAbsoluteDown;
Float_t		bos_AK4AK4_pt_jesAbsoluteUp;
Float_t		bos_AK4AK4_pt_jesAbsolute_YearDown;
Float_t		bos_AK4AK4_pt_jesAbsolute_YearUp;
Float_t		bos_AK4AK4_pt_jesBBEC1Down;
Float_t		bos_AK4AK4_pt_jesBBEC1Up;
Float_t		bos_AK4AK4_pt_jesBBEC1_YearDown;
Float_t		bos_AK4AK4_pt_jesBBEC1_YearUp;
Float_t		bos_AK4AK4_pt_jesEC2Down;
Float_t		bos_AK4AK4_pt_jesEC2Up;
Float_t		bos_AK4AK4_pt_jesEC2_YearDown;
Float_t		bos_AK4AK4_pt_jesEC2_YearUp;
Float_t		bos_AK4AK4_pt_jesFlavorQCDDown;
Float_t		bos_AK4AK4_pt_jesFlavorQCDUp;
Float_t		bos_AK4AK4_pt_jesHFDown;
Float_t		bos_AK4AK4_pt_jesHFUp;
Float_t		bos_AK4AK4_pt_jesHF_YearDown;
Float_t		bos_AK4AK4_pt_jesHF_YearUp;
Float_t		bos_AK4AK4_pt_jesRelativeBalDown;
Float_t		bos_AK4AK4_pt_jesRelativeBalUp;
Float_t		bos_AK4AK4_pt_jesRelativeSample_YearDown;
Float_t		bos_AK4AK4_pt_jesRelativeSample_YearUp;
Float_t		bos_AK4AK4_pt_jesTotalDown;
Float_t		bos_AK4AK4_pt_jesTotalUp;
Float_t		bosCent;
Float_t		bos_j1_AK4_eta;
Float_t		bos_j1_AK4_m;
Float_t		bos_j1_AK4_m_jesAbsoluteDown;
Float_t		bos_j1_AK4_m_jesAbsoluteUp;
Float_t		bos_j1_AK4_m_jesAbsolute_YearDown;
Float_t		bos_j1_AK4_m_jesAbsolute_YearUp;
Float_t		bos_j1_AK4_m_jesBBEC1Down;
Float_t		bos_j1_AK4_m_jesBBEC1Up;
Float_t		bos_j1_AK4_m_jesBBEC1_YearDown;
Float_t		bos_j1_AK4_m_jesBBEC1_YearUp;
Float_t		bos_j1_AK4_m_jesEC2Down;
Float_t		bos_j1_AK4_m_jesEC2Up;
Float_t		bos_j1_AK4_m_jesEC2_YearDown;
Float_t		bos_j1_AK4_m_jesEC2_YearUp;
Float_t		bos_j1_AK4_m_jesFlavorQCDDown;
Float_t		bos_j1_AK4_m_jesFlavorQCDUp;
Float_t		bos_j1_AK4_m_jesHFDown;
Float_t		bos_j1_AK4_m_jesHFUp;
Float_t		bos_j1_AK4_m_jesHF_YearDown;
Float_t		bos_j1_AK4_m_jesHF_YearUp;
Float_t		bos_j1_AK4_m_jesRelativeBalDown;
Float_t		bos_j1_AK4_m_jesRelativeBalUp;
Float_t		bos_j1_AK4_m_jesRelativeSample_YearDown;
Float_t		bos_j1_AK4_m_jesRelativeSample_YearUp;
Float_t		bos_j1_AK4_m_jesTotalDown;
Float_t		bos_j1_AK4_m_jesTotalUp;
Float_t		bos_j1_AK4_phi;
Float_t		bos_j1_AK4_pt;
Float_t		bos_j1_AK4_pt_jesAbsoluteDown;
Float_t		bos_j1_AK4_pt_jesAbsoluteUp;
Float_t		bos_j1_AK4_pt_jesAbsolute_YearDown;
Float_t		bos_j1_AK4_pt_jesAbsolute_YearUp;
Float_t		bos_j1_AK4_pt_jesBBEC1Down;
Float_t		bos_j1_AK4_pt_jesBBEC1Up;
Float_t		bos_j1_AK4_pt_jesBBEC1_YearDown;
Float_t		bos_j1_AK4_pt_jesBBEC1_YearUp;
Float_t		bos_j1_AK4_pt_jesEC2Down;
Float_t		bos_j1_AK4_pt_jesEC2Up;
Float_t		bos_j1_AK4_pt_jesEC2_YearDown;
Float_t		bos_j1_AK4_pt_jesEC2_YearUp;
Float_t		bos_j1_AK4_pt_jesFlavorQCDDown;
Float_t		bos_j1_AK4_pt_jesFlavorQCDUp;
Float_t		bos_j1_AK4_pt_jesHFDown;
Float_t		bos_j1_AK4_pt_jesHFUp;
Float_t		bos_j1_AK4_pt_jesHF_YearDown;
Float_t		bos_j1_AK4_pt_jesHF_YearUp;
Float_t		bos_j1_AK4_pt_jesRelativeBalDown;
Float_t		bos_j1_AK4_pt_jesRelativeBalUp;
Float_t		bos_j1_AK4_pt_jesRelativeSample_YearDown;
Float_t		bos_j1_AK4_pt_jesRelativeSample_YearUp;
Float_t		bos_j1_AK4_pt_jesTotalDown;
Float_t		bos_j1_AK4_pt_jesTotalUp;
Float_t		bos_j1_AK4_puidSF_tight_Down;
Float_t		bos_j1_AK4_puidSF_tight;
Float_t		bos_j1_AK4_puidSF_tight_Up;
Float_t		bos_j2_AK4_eta;
Float_t		bos_j2_AK4_m;
Float_t		bos_j2_AK4_m_jesAbsoluteDown;
Float_t		bos_j2_AK4_m_jesAbsoluteUp;
Float_t		bos_j2_AK4_m_jesAbsolute_YearDown;
Float_t		bos_j2_AK4_m_jesAbsolute_YearUp;
Float_t		bos_j2_AK4_m_jesBBEC1Down;
Float_t		bos_j2_AK4_m_jesBBEC1Up;
Float_t		bos_j2_AK4_m_jesBBEC1_YearDown;
Float_t		bos_j2_AK4_m_jesBBEC1_YearUp;
Float_t		bos_j2_AK4_m_jesEC2Down;
Float_t		bos_j2_AK4_m_jesEC2Up;
Float_t		bos_j2_AK4_m_jesEC2_YearDown;
Float_t		bos_j2_AK4_m_jesEC2_YearUp;
Float_t		bos_j2_AK4_m_jesFlavorQCDDown;
Float_t		bos_j2_AK4_m_jesFlavorQCDUp;
Float_t		bos_j2_AK4_m_jesHFDown;
Float_t		bos_j2_AK4_m_jesHFUp;
Float_t		bos_j2_AK4_m_jesHF_YearDown;
Float_t		bos_j2_AK4_m_jesHF_YearUp;
Float_t		bos_j2_AK4_m_jesRelativeBalDown;
Float_t		bos_j2_AK4_m_jesRelativeBalUp;
Float_t		bos_j2_AK4_m_jesRelativeSample_YearDown;
Float_t		bos_j2_AK4_m_jesRelativeSample_YearUp;
Float_t		bos_j2_AK4_m_jesTotalDown;
Float_t		bos_j2_AK4_m_jesTotalUp;
Float_t		bos_j2_AK4_phi;
Float_t		bos_j2_AK4_pt;
Float_t		bos_j2_AK4_pt_jesAbsoluteDown;
Float_t		bos_j2_AK4_pt_jesAbsoluteUp;
Float_t		bos_j2_AK4_pt_jesAbsolute_YearDown;
Float_t		bos_j2_AK4_pt_jesAbsolute_YearUp;
Float_t		bos_j2_AK4_pt_jesBBEC1Down;
Float_t		bos_j2_AK4_pt_jesBBEC1Up;
Float_t		bos_j2_AK4_pt_jesBBEC1_YearDown;
Float_t		bos_j2_AK4_pt_jesBBEC1_YearUp;
Float_t		bos_j2_AK4_pt_jesEC2Down;
Float_t		bos_j2_AK4_pt_jesEC2Up;
Float_t		bos_j2_AK4_pt_jesEC2_YearDown;
Float_t		bos_j2_AK4_pt_jesEC2_YearUp;
Float_t		bos_j2_AK4_pt_jesFlavorQCDDown;
Float_t		bos_j2_AK4_pt_jesFlavorQCDUp;
Float_t		bos_j2_AK4_pt_jesHFDown;
Float_t		bos_j2_AK4_pt_jesHFUp;
Float_t		bos_j2_AK4_pt_jesHF_YearDown;
Float_t		bos_j2_AK4_pt_jesHF_YearUp;
Float_t		bos_j2_AK4_pt_jesRelativeBalDown;
Float_t		bos_j2_AK4_pt_jesRelativeBalUp;
Float_t		bos_j2_AK4_pt_jesRelativeSample_YearDown;
Float_t		bos_j2_AK4_pt_jesRelativeSample_YearUp;
Float_t		bos_j2_AK4_pt_jesTotalDown;
Float_t		bos_j2_AK4_pt_jesTotalUp;
Float_t		bos_j2_AK4_puidSF_tight_Down;
Float_t		bos_j2_AK4_puidSF_tight;
Float_t		bos_j2_AK4_puidSF_tight_Up;
Float_t		bos_PuppiAK8_eta;
Float_t		bos_PuppiAK8_m_sd0_corr;
Float_t		bos_PuppiAK8_m_sd0;
Float_t		bos_PuppiAK8_phi;
Float_t		bos_PuppiAK8_pt;
Float_t		bos_PuppiAK8_pt_jesAbsoluteDown;
Float_t		bos_PuppiAK8_pt_jesAbsoluteUp;
Float_t		bos_PuppiAK8_pt_jesAbsolute_YearDown;
Float_t		bos_PuppiAK8_pt_jesAbsolute_YearUp;
Float_t		bos_PuppiAK8_pt_jesBBEC1Down;
Float_t		bos_PuppiAK8_pt_jesBBEC1Up;
Float_t		bos_PuppiAK8_pt_jesBBEC1_YearDown;
Float_t		bos_PuppiAK8_pt_jesBBEC1_YearUp;
Float_t		bos_PuppiAK8_pt_jesEC2Down;
Float_t		bos_PuppiAK8_pt_jesEC2Up;
Float_t		bos_PuppiAK8_pt_jesEC2_YearDown;
Float_t		bos_PuppiAK8_pt_jesEC2_YearUp;
Float_t		bos_PuppiAK8_pt_jesFlavorQCDDown;
Float_t		bos_PuppiAK8_pt_jesFlavorQCDUp;
Float_t		bos_PuppiAK8_pt_jesHFDown;
Float_t		bos_PuppiAK8_pt_jesHFUp;
Float_t		bos_PuppiAK8_pt_jesHF_YearDown;
Float_t		bos_PuppiAK8_pt_jesHF_YearUp;
Float_t		bos_PuppiAK8_pt_jesRelativeBalDown;
Float_t		bos_PuppiAK8_pt_jesRelativeBalUp;
Float_t		bos_PuppiAK8_pt_jesRelativeSample_YearDown;
Float_t		bos_PuppiAK8_pt_jesRelativeSample_YearUp;
Float_t		bos_PuppiAK8_pt_jesTotalDown;
Float_t		bos_PuppiAK8_pt_jesTotalUp;
Float_t		bos_PuppiAK8_tau2tau1;
Float_t		btagWeight_loose_Down;
Float_t		btagWeight_loose;
Float_t		btagWeight_loose_Up;
Float_t		btagWeight_medium_Down;
Float_t		btagWeight_medium;
Float_t		btagWeight_medium_Up;
Float_t		btagWeight_tight_Down;
Float_t		btagWeight_tight;
Float_t		btagWeight_tight_Up;
Float_t		dibos_eta;
Float_t		dibos_m;
Float_t		dibos_m_jesAbsoluteDown;
Float_t		dibos_m_jesAbsoluteUp;
Float_t		dibos_m_jesAbsolute_YearDown;
Float_t		dibos_m_jesAbsolute_YearUp;
Float_t		dibos_m_jesBBEC1Down;
Float_t		dibos_m_jesBBEC1Up;
Float_t		dibos_m_jesBBEC1_YearDown;
Float_t		dibos_m_jesBBEC1_YearUp;
Float_t		dibos_m_jesEC2Down;
Float_t		dibos_m_jesEC2Up;
Float_t		dibos_m_jesEC2_YearDown;
Float_t		dibos_m_jesEC2_YearUp;
Float_t		dibos_m_jesFlavorQCDDown;
Float_t		dibos_m_jesFlavorQCDUp;
Float_t		dibos_m_jesHFDown;
Float_t		dibos_m_jesHFUp;
Float_t		dibos_m_jesHF_YearDown;
Float_t		dibos_m_jesHF_YearUp;
Float_t		dibos_m_jesRelativeBalDown;
Float_t		dibos_m_jesRelativeBalUp;
Float_t		dibos_m_jesRelativeSample_YearDown;
Float_t		dibos_m_jesRelativeSample_YearUp;
Float_t		dibos_m_jesTotalDown;
Float_t		dibos_m_jesTotalUp;
Float_t		dibos_m_scaleDown;
Float_t		dibos_m_scaleUp;
Float_t		dibos_mt;
Float_t		dibos_mt_jesAbsoluteDown;
Float_t		dibos_mt_jesAbsoluteUp;
Float_t		dibos_mt_jesAbsolute_YearDown;
Float_t		dibos_mt_jesAbsolute_YearUp;
Float_t		dibos_mt_jesBBEC1Down;
Float_t		dibos_mt_jesBBEC1Up;
Float_t		dibos_mt_jesBBEC1_YearDown;
Float_t		dibos_mt_jesBBEC1_YearUp;
Float_t		dibos_mt_jesEC2Down;
Float_t		dibos_mt_jesEC2Up;
Float_t		dibos_mt_jesEC2_YearDown;
Float_t		dibos_mt_jesEC2_YearUp;
Float_t		dibos_mt_jesFlavorQCDDown;
Float_t		dibos_mt_jesFlavorQCDUp;
Float_t		dibos_mt_jesHFDown;
Float_t		dibos_mt_jesHFUp;
Float_t		dibos_mt_jesHF_YearDown;
Float_t		dibos_mt_jesHF_YearUp;
Float_t		dibos_mt_jesRelativeBalDown;
Float_t		dibos_mt_jesRelativeBalUp;
Float_t		dibos_mt_jesRelativeSample_YearDown;
Float_t		dibos_mt_jesRelativeSample_YearUp;
Float_t		dibos_mt_jesTotalDown;
Float_t		dibos_mt_jesTotalUp;
Float_t		dibos_mt_scaleDown;
Float_t		dibos_mt_scaleUp;
Float_t		dibos_phi;
Float_t		dibos_pt;
Float_t		dibos_pt_jesAbsoluteDown;
Float_t		dibos_pt_jesAbsoluteUp;
Float_t		dibos_pt_jesAbsolute_YearDown;
Float_t		dibos_pt_jesAbsolute_YearUp;
Float_t		dibos_pt_jesBBEC1Down;
Float_t		dibos_pt_jesBBEC1Up;
Float_t		dibos_pt_jesBBEC1_YearDown;
Float_t		dibos_pt_jesBBEC1_YearUp;
Float_t		dibos_pt_jesEC2Down;
Float_t		dibos_pt_jesEC2Up;
Float_t		dibos_pt_jesEC2_YearDown;
Float_t		dibos_pt_jesEC2_YearUp;
Float_t		dibos_pt_jesFlavorQCDDown;
Float_t		dibos_pt_jesFlavorQCDUp;
Float_t		dibos_pt_jesHFDown;
Float_t		dibos_pt_jesHFUp;
Float_t		dibos_pt_jesHF_YearDown;
Float_t		dibos_pt_jesHF_YearUp;
Float_t		dibos_pt_jesRelativeBalDown;
Float_t		dibos_pt_jesRelativeBalUp;
Float_t		dibos_pt_jesRelativeSample_YearDown;
Float_t		dibos_pt_jesRelativeSample_YearUp;
Float_t		dibos_pt_jesTotalDown;
Float_t		dibos_pt_jesTotalUp;
Float_t		dibos_pt_scaleDown;
Float_t		dibos_pt_scaleUp;
Float_t		dilep_eta;
Float_t		dilep_m;
Float_t		dilep_m_jesAbsoluteDown;
Float_t		dilep_m_jesAbsoluteUp;
Float_t		dilep_m_jesAbsolute_YearDown;
Float_t		dilep_m_jesAbsolute_YearUp;
Float_t		dilep_m_jesBBEC1Down;
Float_t		dilep_m_jesBBEC1Up;
Float_t		dilep_m_jesBBEC1_YearDown;
Float_t		dilep_m_jesBBEC1_YearUp;
Float_t		dilep_m_jesEC2Down;
Float_t		dilep_m_jesEC2Up;
Float_t		dilep_m_jesEC2_YearDown;
Float_t		dilep_m_jesEC2_YearUp;
Float_t		dilep_m_jesFlavorQCDDown;
Float_t		dilep_m_jesFlavorQCDUp;
Float_t		dilep_m_jesHFDown;
Float_t		dilep_m_jesHFUp;
Float_t		dilep_m_jesHF_YearDown;
Float_t		dilep_m_jesHF_YearUp;
Float_t		dilep_m_jesRelativeBalDown;
Float_t		dilep_m_jesRelativeBalUp;
Float_t		dilep_m_jesRelativeSample_YearDown;
Float_t		dilep_m_jesRelativeSample_YearUp;
Float_t		dilep_m_jesTotalDown;
Float_t		dilep_m_jesTotalUp;
Float_t		dilep_m_scaleDown;
Float_t		dilep_m_scaleUp;
Float_t		dilep_mt;
Float_t		dilep_mt_jesAbsoluteDown;
Float_t		dilep_mt_jesAbsoluteUp;
Float_t		dilep_mt_jesAbsolute_YearDown;
Float_t		dilep_mt_jesAbsolute_YearUp;
Float_t		dilep_mt_jesBBEC1Down;
Float_t		dilep_mt_jesBBEC1Up;
Float_t		dilep_mt_jesBBEC1_YearDown;
Float_t		dilep_mt_jesBBEC1_YearUp;
Float_t		dilep_mt_jesEC2Down;
Float_t		dilep_mt_jesEC2Up;
Float_t		dilep_mt_jesEC2_YearDown;
Float_t		dilep_mt_jesEC2_YearUp;
Float_t		dilep_mt_jesFlavorQCDDown;
Float_t		dilep_mt_jesFlavorQCDUp;
Float_t		dilep_mt_jesHFDown;
Float_t		dilep_mt_jesHFUp;
Float_t		dilep_mt_jesHF_YearDown;
Float_t		dilep_mt_jesHF_YearUp;
Float_t		dilep_mt_jesRelativeBalDown;
Float_t		dilep_mt_jesRelativeBalUp;
Float_t		dilep_mt_jesRelativeSample_YearDown;
Float_t		dilep_mt_jesRelativeSample_YearUp;
Float_t		dilep_mt_jesTotalDown;
Float_t		dilep_mt_jesTotalUp;
Float_t		dilep_mt_scaleDown;
Float_t		dilep_mt_scaleUp;
Float_t		dilep_phi;
Float_t		dilep_pt;
Float_t		dilep_pt_jesAbsoluteDown;
Float_t		dilep_pt_jesAbsoluteUp;
Float_t		dilep_pt_jesAbsolute_YearDown;
Float_t		dilep_pt_jesAbsolute_YearUp;
Float_t		dilep_pt_jesBBEC1Down;
Float_t		dilep_pt_jesBBEC1Up;
Float_t		dilep_pt_jesBBEC1_YearDown;
Float_t		dilep_pt_jesBBEC1_YearUp;
Float_t		dilep_pt_jesEC2Down;
Float_t		dilep_pt_jesEC2Up;
Float_t		dilep_pt_jesEC2_YearDown;
Float_t		dilep_pt_jesEC2_YearUp;
Float_t		dilep_pt_jesFlavorQCDDown;
Float_t		dilep_pt_jesFlavorQCDUp;
Float_t		dilep_pt_jesHFDown;
Float_t		dilep_pt_jesHFUp;
Float_t		dilep_pt_jesHF_YearDown;
Float_t		dilep_pt_jesHF_YearUp;
Float_t		dilep_pt_jesRelativeBalDown;
Float_t		dilep_pt_jesRelativeBalUp;
Float_t		dilep_pt_jesRelativeSample_YearDown;
Float_t		dilep_pt_jesRelativeSample_YearUp;
Float_t		dilep_pt_jesTotalDown;
Float_t		dilep_pt_jesTotalUp;
Float_t		dilep_pt_scaleDown;
Float_t		dilep_pt_scaleUp;
Float_t		genWeight;
Float_t		L1PFWeight_Down;
Float_t		L1PFWeight;
Float_t		L1PFWeight_Up;
Float_t		lep1_dxy;
Float_t		lep1_dz;
Float_t		lep1_eta;
Float_t		lep1_idEffWeight;
Float_t		lep1_iso;
Float_t		lep1_m;
Float_t		lep1_phi;
Float_t		lep1_pt;
Float_t		lep1_pt_scaleDown;
Float_t		lep1_pt_scaleUp;
Float_t		lep1_q;
Float_t		lep1_trigEffWeight;
Float_t		lep2_dxy;
Float_t		lep2_dz;
Float_t		lep2_eta;
Float_t		lep2_idEffWeight;
Float_t		lep2_iso;
Float_t		lep2_m;
Float_t		lep2_phi;
Float_t		lep2_pt;
Float_t		lep2_pt_scaleDown;
Float_t		lep2_pt_scaleUp;
Float_t		lep2_q;
Float_t		lep2_trigEffWeight;
Float_t		lepFakeRate;
Float_t		LHEWeight;
Float_t		MET_2017;
Float_t		MET;
Float_t		MET_jesAbsoluteDown;
Float_t		MET_jesAbsoluteUp;
Float_t		MET_jesAbsolute_YearDown;
Float_t		MET_jesAbsolute_YearUp;
Float_t		MET_jesBBEC1Down;
Float_t		MET_jesBBEC1Up;
Float_t		MET_jesBBEC1_YearDown;
Float_t		MET_jesBBEC1_YearUp;
Float_t		MET_jesEC2Down;
Float_t		MET_jesEC2Up;
Float_t		MET_jesEC2_YearDown;
Float_t		MET_jesEC2_YearUp;
Float_t		MET_jesFlavorQCDDown;
Float_t		MET_jesFlavorQCDUp;
Float_t		MET_jesHFDown;
Float_t		MET_jesHFUp;
Float_t		MET_jesHF_YearDown;
Float_t		MET_jesHF_YearUp;
Float_t		MET_jesRelativeBalDown;
Float_t		MET_jesRelativeBalUp;
Float_t		MET_jesRelativeSample_YearDown;
Float_t		MET_jesRelativeSample_YearUp;
Float_t		MET_jesTotalDown;
Float_t		MET_jesTotalUp;
Float_t		MET_phi;
Float_t		MET_phi_jesAbsoluteDown;
Float_t		MET_phi_jesAbsoluteUp;
Float_t		MET_phi_jesAbsolute_YearDown;
Float_t		MET_phi_jesAbsolute_YearUp;
Float_t		MET_phi_jesBBEC1Down;
Float_t		MET_phi_jesBBEC1Up;
Float_t		MET_phi_jesBBEC1_YearDown;
Float_t		MET_phi_jesBBEC1_YearUp;
Float_t		MET_phi_jesEC2Down;
Float_t		MET_phi_jesEC2Up;
Float_t		MET_phi_jesEC2_YearDown;
Float_t		MET_phi_jesEC2_YearUp;
Float_t		MET_phi_jesFlavorQCDDown;
Float_t		MET_phi_jesFlavorQCDUp;
Float_t		MET_phi_jesHFDown;
Float_t		MET_phi_jesHFUp;
Float_t		MET_phi_jesHF_YearDown;
Float_t		MET_phi_jesHF_YearUp;
Float_t		MET_phi_jesRelativeBalDown;
Float_t		MET_phi_jesRelativeBalUp;
Float_t		MET_phi_jesRelativeSample_YearDown;
Float_t		MET_phi_jesRelativeSample_YearUp;
Float_t		MET_phi_jesTotalDown;
Float_t		MET_phi_jesTotalUp;
Float_t		neu_pz_type0;
Float_t		nJet30f;
Float_t		nPU_mean;
Float_t		nPV;
Float_t		pdfWeight;
Float_t		puWeight_Down;
Float_t		puWeight;
Float_t		puWeight_Up;
Float_t		scaleWeight;
Float_t		vbf1_AK4_axis2;
Float_t		vbf1_AK4_eta;
Float_t		vbf1_AK4_m;
Float_t		vbf1_AK4_m_jesAbsoluteDown;
Float_t		vbf1_AK4_m_jesAbsoluteUp;
Float_t		vbf1_AK4_m_jesAbsolute_YearDown;
Float_t		vbf1_AK4_m_jesAbsolute_YearUp;
Float_t		vbf1_AK4_m_jesBBEC1Down;
Float_t		vbf1_AK4_m_jesBBEC1Up;
Float_t		vbf1_AK4_m_jesBBEC1_YearDown;
Float_t		vbf1_AK4_m_jesBBEC1_YearUp;
Float_t		vbf1_AK4_m_jesEC2Down;
Float_t		vbf1_AK4_m_jesEC2Up;
Float_t		vbf1_AK4_m_jesEC2_YearDown;
Float_t		vbf1_AK4_m_jesEC2_YearUp;
Float_t		vbf1_AK4_m_jesFlavorQCDDown;
Float_t		vbf1_AK4_m_jesFlavorQCDUp;
Float_t		vbf1_AK4_m_jesHFDown;
Float_t		vbf1_AK4_m_jesHFUp;
Float_t		vbf1_AK4_m_jesHF_YearDown;
Float_t		vbf1_AK4_m_jesHF_YearUp;
Float_t		vbf1_AK4_m_jesRelativeBalDown;
Float_t		vbf1_AK4_m_jesRelativeBalUp;
Float_t		vbf1_AK4_m_jesRelativeSample_YearDown;
Float_t		vbf1_AK4_m_jesRelativeSample_YearUp;
Float_t		vbf1_AK4_m_jesTotalDown;
Float_t		vbf1_AK4_m_jesTotalUp;
Float_t		vbf1_AK4_phi;
Float_t		vbf1_AK4_ptD;
Float_t		vbf1_AK4_pt;
Float_t		vbf1_AK4_pt_jesAbsoluteDown;
Float_t		vbf1_AK4_pt_jesAbsoluteUp;
Float_t		vbf1_AK4_pt_jesAbsolute_YearDown;
Float_t		vbf1_AK4_pt_jesAbsolute_YearUp;
Float_t		vbf1_AK4_pt_jesBBEC1Down;
Float_t		vbf1_AK4_pt_jesBBEC1Up;
Float_t		vbf1_AK4_pt_jesBBEC1_YearDown;
Float_t		vbf1_AK4_pt_jesBBEC1_YearUp;
Float_t		vbf1_AK4_pt_jesEC2Down;
Float_t		vbf1_AK4_pt_jesEC2Up;
Float_t		vbf1_AK4_pt_jesEC2_YearDown;
Float_t		vbf1_AK4_pt_jesEC2_YearUp;
Float_t		vbf1_AK4_pt_jesFlavorQCDDown;
Float_t		vbf1_AK4_pt_jesFlavorQCDUp;
Float_t		vbf1_AK4_pt_jesHFDown;
Float_t		vbf1_AK4_pt_jesHFUp;
Float_t		vbf1_AK4_pt_jesHF_YearDown;
Float_t		vbf1_AK4_pt_jesHF_YearUp;
Float_t		vbf1_AK4_pt_jesRelativeBalDown;
Float_t		vbf1_AK4_pt_jesRelativeBalUp;
Float_t		vbf1_AK4_pt_jesRelativeSample_YearDown;
Float_t		vbf1_AK4_pt_jesRelativeSample_YearUp;
Float_t		vbf1_AK4_pt_jesTotalDown;
Float_t		vbf1_AK4_pt_jesTotalUp;
Float_t		vbf1_AK4_puidSF_tight_Down;
Float_t		vbf1_AK4_puidSF_tight;
Float_t		vbf1_AK4_puidSF_tight_Up;
Float_t		vbf1_AK4_qgid;
Float_t		vbf2_AK4_axis2;
Float_t		vbf2_AK4_eta;
Float_t		vbf2_AK4_m;
Float_t		vbf2_AK4_m_jesAbsoluteDown;
Float_t		vbf2_AK4_m_jesAbsoluteUp;
Float_t		vbf2_AK4_m_jesAbsolute_YearDown;
Float_t		vbf2_AK4_m_jesAbsolute_YearUp;
Float_t		vbf2_AK4_m_jesBBEC1Down;
Float_t		vbf2_AK4_m_jesBBEC1Up;
Float_t		vbf2_AK4_m_jesBBEC1_YearDown;
Float_t		vbf2_AK4_m_jesBBEC1_YearUp;
Float_t		vbf2_AK4_m_jesEC2Down;
Float_t		vbf2_AK4_m_jesEC2Up;
Float_t		vbf2_AK4_m_jesEC2_YearDown;
Float_t		vbf2_AK4_m_jesEC2_YearUp;
Float_t		vbf2_AK4_m_jesFlavorQCDDown;
Float_t		vbf2_AK4_m_jesFlavorQCDUp;
Float_t		vbf2_AK4_m_jesHFDown;
Float_t		vbf2_AK4_m_jesHFUp;
Float_t		vbf2_AK4_m_jesHF_YearDown;
Float_t		vbf2_AK4_m_jesHF_YearUp;
Float_t		vbf2_AK4_m_jesRelativeBalDown;
Float_t		vbf2_AK4_m_jesRelativeBalUp;
Float_t		vbf2_AK4_m_jesRelativeSample_YearDown;
Float_t		vbf2_AK4_m_jesRelativeSample_YearUp;
Float_t		vbf2_AK4_m_jesTotalDown;
Float_t		vbf2_AK4_m_jesTotalUp;
Float_t		vbf2_AK4_phi;
Float_t		vbf2_AK4_ptD;
Float_t		vbf2_AK4_pt;
Float_t		vbf2_AK4_pt_jesAbsoluteDown;
Float_t		vbf2_AK4_pt_jesAbsoluteUp;
Float_t		vbf2_AK4_pt_jesAbsolute_YearDown;
Float_t		vbf2_AK4_pt_jesAbsolute_YearUp;
Float_t		vbf2_AK4_pt_jesBBEC1Down;
Float_t		vbf2_AK4_pt_jesBBEC1Up;
Float_t		vbf2_AK4_pt_jesBBEC1_YearDown;
Float_t		vbf2_AK4_pt_jesBBEC1_YearUp;
Float_t		vbf2_AK4_pt_jesEC2Down;
Float_t		vbf2_AK4_pt_jesEC2Up;
Float_t		vbf2_AK4_pt_jesEC2_YearDown;
Float_t		vbf2_AK4_pt_jesEC2_YearUp;
Float_t		vbf2_AK4_pt_jesFlavorQCDDown;
Float_t		vbf2_AK4_pt_jesFlavorQCDUp;
Float_t		vbf2_AK4_pt_jesHFDown;
Float_t		vbf2_AK4_pt_jesHFUp;
Float_t		vbf2_AK4_pt_jesHF_YearDown;
Float_t		vbf2_AK4_pt_jesHF_YearUp;
Float_t		vbf2_AK4_pt_jesRelativeBalDown;
Float_t		vbf2_AK4_pt_jesRelativeBalUp;
Float_t		vbf2_AK4_pt_jesRelativeSample_YearDown;
Float_t		vbf2_AK4_pt_jesRelativeSample_YearUp;
Float_t		vbf2_AK4_pt_jesTotalDown;
Float_t		vbf2_AK4_pt_jesTotalUp;
Float_t		vbf2_AK4_puidSF_tight_Down;
Float_t		vbf2_AK4_puidSF_tight;
Float_t		vbf2_AK4_puidSF_tight_Up;
Float_t		vbf2_AK4_qgid;
Float_t		vbf_deta;
Float_t		vbf_eta;
Float_t		vbf_m;
Float_t		vbf_m_jesAbsoluteDown;
Float_t		vbf_m_jesAbsoluteUp;
Float_t		vbf_m_jesAbsolute_YearDown;
Float_t		vbf_m_jesAbsolute_YearUp;
Float_t		vbf_m_jesBBEC1Down;
Float_t		vbf_m_jesBBEC1Up;
Float_t		vbf_m_jesBBEC1_YearDown;
Float_t		vbf_m_jesBBEC1_YearUp;
Float_t		vbf_m_jesEC2Down;
Float_t		vbf_m_jesEC2Up;
Float_t		vbf_m_jesEC2_YearDown;
Float_t		vbf_m_jesEC2_YearUp;
Float_t		vbf_m_jesFlavorQCDDown;
Float_t		vbf_m_jesFlavorQCDUp;
Float_t		vbf_m_jesHFDown;
Float_t		vbf_m_jesHFUp;
Float_t		vbf_m_jesHF_YearDown;
Float_t		vbf_m_jesHF_YearUp;
Float_t		vbf_m_jesRelativeBalDown;
Float_t		vbf_m_jesRelativeBalUp;
Float_t		vbf_m_jesRelativeSample_YearDown;
Float_t		vbf_m_jesRelativeSample_YearUp;
Float_t		vbf_m_jesTotalDown;
Float_t		vbf_m_jesTotalUp;
Float_t		vbf_phi;
Float_t		vbf_pt;
Float_t		vbf_pt_jesAbsoluteDown;
Float_t		vbf_pt_jesAbsoluteUp;
Float_t		vbf_pt_jesAbsolute_YearDown;
Float_t		vbf_pt_jesAbsolute_YearUp;
Float_t		vbf_pt_jesBBEC1Down;
Float_t		vbf_pt_jesBBEC1Up;
Float_t		vbf_pt_jesBBEC1_YearDown;
Float_t		vbf_pt_jesBBEC1_YearUp;
Float_t		vbf_pt_jesEC2Down;
Float_t		vbf_pt_jesEC2Up;
Float_t		vbf_pt_jesEC2_YearDown;
Float_t		vbf_pt_jesEC2_YearUp;
Float_t		vbf_pt_jesFlavorQCDDown;
Float_t		vbf_pt_jesFlavorQCDUp;
Float_t		vbf_pt_jesHFDown;
Float_t		vbf_pt_jesHFUp;
Float_t		vbf_pt_jesHF_YearDown;
Float_t		vbf_pt_jesHF_YearUp;
Float_t		vbf_pt_jesRelativeBalDown;
Float_t		vbf_pt_jesRelativeBalUp;
Float_t		vbf_pt_jesRelativeSample_YearDown;
Float_t		vbf_pt_jesRelativeSample_YearUp;
Float_t		vbf_pt_jesTotalDown;
Float_t		vbf_pt_jesTotalUp;
Float_t		zeppHad;
Float_t		zeppLep;
Bool_t		bos_j1_AK4_puid_tight;
Bool_t		bos_j2_AK4_puid_tight;
Bool_t		isAntiIso;
Bool_t		trigger_1El;
Bool_t		trigger_1Mu;
Bool_t		trigger_2El;
Bool_t		trigger_2Mu;
Bool_t		vbf1_AK4_puid_tight;
Bool_t		vbf2_AK4_puid_tight;
} VbsReducedEvent;
//
//===================================================================================
void addBranches_vbsReducedTree(TTree* vbsTree, VbsReducedEvent& vbsEvent){
  // if(vbsTree->GetBranch( "gid")){
   cout << "Adding branches" << endl;
   vbsTree->Branch( "gid",                &vbsEvent.gid,              "gid/I");
   vbsTree->Branch( "sid",                &vbsEvent.sid,              "sid/I");
   vbsTree->Branch( "mcWeight",           &vbsEvent.mcWeight,         "mcWeight/F");
  //}
}
//=================================================================================== 
void arrange_vbsReducedTree(TTree* vbsTree, VbsReducedEvent& vbsEvent){
//Maps the vbsTree branches to members of local  vbsEvent structure
//Extra Branhes
//if(vbsTree->GetBranch( "gid") ) {
   cout << " Set extra branches" << endl;
      
    vbsTree->SetBranchAddress( "gid",                                      &vbsEvent.gid    );
    vbsTree->SetBranchAddress( "sid",                                      &vbsEvent.sid    );
    vbsTree->SetBranchAddress( "mcWeight",                                 &vbsEvent.mcWeight );
    cout << " Done Set extra branches" << endl;
	 vbsTree->SetBranchAddress( "evt", 	 &vbsEvent.evt);
	 vbsTree->SetBranchAddress( "nBtag_loose", 	 &vbsEvent.nBtag_loose);
	 vbsTree->SetBranchAddress( "nBtag_medium", 	 &vbsEvent.nBtag_medium);
	 vbsTree->SetBranchAddress( "nJet30", 	 &vbsEvent.nJet30);
	 vbsTree->SetBranchAddress( "nJet50", 	 &vbsEvent.nJet50);
	 vbsTree->SetBranchAddress( "run", 	 &vbsEvent.run);
	 vbsTree->SetBranchAddress( "bos_AK4AK4_eta", 	 &vbsEvent.bos_AK4AK4_eta);
	 vbsTree->SetBranchAddress( "bos_AK4AK4_m", 	 &vbsEvent.bos_AK4AK4_m);
	 vbsTree->SetBranchAddress( "bos_AK4AK4_pt", 	 &vbsEvent.bos_AK4AK4_pt);
	 vbsTree->SetBranchAddress( "bosCent", 	 &vbsEvent.bosCent);
	 vbsTree->SetBranchAddress( "bos_j1_AK4_eta", 	 &vbsEvent.bos_j1_AK4_eta);
	 vbsTree->SetBranchAddress( "bos_j1_AK4_pt", 	 &vbsEvent.bos_j1_AK4_pt);
	 vbsTree->SetBranchAddress( "bos_j2_AK4_eta", 	 &vbsEvent.bos_j2_AK4_eta);
	 vbsTree->SetBranchAddress( "bos_j2_AK4_pt", 	 &vbsEvent.bos_j2_AK4_pt);
	 vbsTree->SetBranchAddress( "bos_PuppiAK8_eta", 	 &vbsEvent.bos_PuppiAK8_eta);
	 vbsTree->SetBranchAddress( "bos_PuppiAK8_m_sd0_corr", 	 &vbsEvent.bos_PuppiAK8_m_sd0_corr);
	 vbsTree->SetBranchAddress( "bos_PuppiAK8_m_sd0", 	 &vbsEvent.bos_PuppiAK8_m_sd0);
	 vbsTree->SetBranchAddress( "bos_PuppiAK8_phi", 	 &vbsEvent.bos_PuppiAK8_phi);
	 vbsTree->SetBranchAddress( "bos_PuppiAK8_pt", 	 &vbsEvent.bos_PuppiAK8_pt);
	 vbsTree->SetBranchAddress( "bos_PuppiAK8_tau2tau1", 	 &vbsEvent.bos_PuppiAK8_tau2tau1);
	 vbsTree->SetBranchAddress( "btagWeight_loose", 	 &vbsEvent.btagWeight_loose);
	 vbsTree->SetBranchAddress( "dibos_eta", 	 &vbsEvent.dibos_eta);
	 vbsTree->SetBranchAddress( "dibos_m", 	 &vbsEvent.dibos_m);
	 vbsTree->SetBranchAddress( "dibos_mt", 	 &vbsEvent.dibos_mt);
	 vbsTree->SetBranchAddress( "dibos_phi", 	 &vbsEvent.dibos_phi);
	 vbsTree->SetBranchAddress( "dibos_pt", 	 &vbsEvent.dibos_pt);
	 vbsTree->SetBranchAddress( "dilep_eta", 	 &vbsEvent.dilep_eta);
	 vbsTree->SetBranchAddress( "dilep_m", 	 &vbsEvent.dilep_m);
	 vbsTree->SetBranchAddress( "dilep_mt", 	 &vbsEvent.dilep_mt);
	 vbsTree->SetBranchAddress( "dilep_phi", 	 &vbsEvent.dilep_phi);
	 vbsTree->SetBranchAddress( "dilep_pt", 	 &vbsEvent.dilep_pt);
	 vbsTree->SetBranchAddress( "genWeight", 	 &vbsEvent.genWeight);
	 vbsTree->SetBranchAddress( "L1PFWeight", 	 &vbsEvent.L1PFWeight);
	 vbsTree->SetBranchAddress( "lep1_eta", 	 &vbsEvent.lep1_eta);
	 vbsTree->SetBranchAddress( "lep1_iso", 	 &vbsEvent.lep1_iso);
	 vbsTree->SetBranchAddress( "lep1_m", 	 &vbsEvent.lep1_m);
	 vbsTree->SetBranchAddress( "lep1_phi", 	 &vbsEvent.lep1_phi);
	 vbsTree->SetBranchAddress( "lep1_pt", 	 &vbsEvent.lep1_pt);
	 vbsTree->SetBranchAddress( "lep1_q", 	 &vbsEvent.lep1_q);
	 vbsTree->SetBranchAddress( "lep2_eta", 	 &vbsEvent.lep2_eta);
	 vbsTree->SetBranchAddress( "lep2_pt", 	 &vbsEvent.lep2_pt);
	 vbsTree->SetBranchAddress( "MET", 	 &vbsEvent.MET);
	 vbsTree->SetBranchAddress( "MET_phi", 	 &vbsEvent.MET_phi);
	 vbsTree->SetBranchAddress( "neu_pz_type0", 	 &vbsEvent.neu_pz_type0);
	 vbsTree->SetBranchAddress( "nJet30f", 	 &vbsEvent.nJet30f);
	 vbsTree->SetBranchAddress( "nPV", 	 &vbsEvent.nPV);
	 vbsTree->SetBranchAddress( "puWeight", 	 &vbsEvent.puWeight);
	 vbsTree->SetBranchAddress( "vbf1_AK4_eta", 	 &vbsEvent.vbf1_AK4_eta);
	 vbsTree->SetBranchAddress( "vbf1_AK4_phi", 	 &vbsEvent.vbf1_AK4_phi);
	 vbsTree->SetBranchAddress( "vbf1_AK4_pt", 	 &vbsEvent.vbf1_AK4_pt);
	 vbsTree->SetBranchAddress( "vbf1_AK4_qgid", 	 &vbsEvent.vbf1_AK4_qgid);
	 vbsTree->SetBranchAddress( "vbf2_AK4_eta", 	 &vbsEvent.vbf2_AK4_eta);
	 vbsTree->SetBranchAddress( "vbf2_AK4_phi", 	 &vbsEvent.vbf2_AK4_phi);
	 vbsTree->SetBranchAddress( "vbf2_AK4_pt", 	 &vbsEvent.vbf2_AK4_pt);
	 vbsTree->SetBranchAddress( "vbf2_AK4_qgid", 	 &vbsEvent.vbf2_AK4_qgid);
	 vbsTree->SetBranchAddress( "vbf_deta", 	 &vbsEvent.vbf_deta);
	 vbsTree->SetBranchAddress( "vbf_eta", 	 &vbsEvent.vbf_eta);
	 vbsTree->SetBranchAddress( "vbf_m", 	 &vbsEvent.vbf_m);
	 vbsTree->SetBranchAddress( "vbf_phi", 	 &vbsEvent.vbf_phi);
	 vbsTree->SetBranchAddress( "vbf_pt", 	 &vbsEvent.vbf_pt);
	 vbsTree->SetBranchAddress( "zeppHad", 	 &vbsEvent.zeppHad);
	 vbsTree->SetBranchAddress( "zeppLep", 	 &vbsEvent.zeppLep);
 // }
}
//=======================================
#endif
