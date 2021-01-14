#ifndef vbsReducedTree_hpp
#define vbsReducedTree_hpp
//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Dec 18, 2020 by ROOT version 6.10/08
// from TTree otree/otree
// found on file: WWTree_ChargedHiggsToWZToLLQQ_M600_13TeV.root
//////////////////////////////////////////////////////////
//VbsReducedEvent structure (keeps variables of the VbsAnalysisReduced ntuple)
typedef struct {
//Additional branches - to be added
   Int_t           gid;                  // - group  ID
   Int_t           sid;                  // - sample ID
   Float_t         mcWeight;             //== xsect/ngen 
//
   // Declaration of leaf types

Float_t	L1PFWeight
Float_t	LHEWeight
Float_t	MET
Float_t	MET_2017raw
Float_t	MET_phi
Float_t	MET_scaleDn
Float_t	MET_scaleUp
Float_t	aqgcWeight
Float_t	bosCent
Float_t	bos_AK4AK4_eta
Float_t	bos_AK4AK4_m
Float_t	bos_AK4AK4_m_scaleDn
Float_t	bos_AK4AK4_m_scaleUp
Float_t	bos_AK4AK4_phi
Float_t	bos_AK4AK4_pt
Float_t	bos_AK4AK4_pt_scaleDn
Float_t	bos_AK4AK4_pt_scaleUp
Float_t	bos_PuppiAK8_e2_sdb1
Float_t	bos_PuppiAK8_e2_sdb2
Float_t	bos_PuppiAK8_e3_sdb1
Float_t	bos_PuppiAK8_e3_sdb2
Float_t	bos_PuppiAK8_e3_v1_sdb1
Float_t	bos_PuppiAK8_e3_v1_sdb2
Float_t	bos_PuppiAK8_e3_v2_sdb1
Float_t	bos_PuppiAK8_e3_v2_sdb2
Float_t	bos_PuppiAK8_e4_v1_sdb1
Float_t	bos_PuppiAK8_e4_v1_sdb2
Float_t	bos_PuppiAK8_e4_v2_sdb1
Float_t	bos_PuppiAK8_e4_v2_sdb2
Float_t	bos_PuppiAK8_eta
Float_t	bos_PuppiAK8_m_sd0
Float_t	bos_PuppiAK8_m_sd0_corr
Float_t	bos_PuppiAK8_m_sd0_corr_scaleDn
Float_t	bos_PuppiAK8_m_sd0_corr_scaleUp
Float_t	bos_PuppiAK8_phi
Float_t	bos_PuppiAK8_pt
Float_t	bos_PuppiAK8_pt_scaleDn
Float_t	bos_PuppiAK8_pt_scaleUp
Float_t	bos_PuppiAK8_tau2tau1
Float_t	bos_j1_AK4_eta
Float_t	bos_j1_AK4_m
Float_t	bos_j1_AK4_m_scaleDn
Float_t	bos_j1_AK4_m_scaleUp
Float_t	bos_j1_AK4_phi
Float_t	bos_j1_AK4_pt
Float_t	bos_j1_AK4_pt_scaleDn
Float_t	bos_j1_AK4_pt_scaleUp
Float_t	bos_j2_AK4_eta
Float_t	bos_j2_AK4_m
Float_t	bos_j2_AK4_m_scaleDn
Float_t	bos_j2_AK4_m_scaleUp
Float_t	bos_j2_AK4_phi
Float_t	bos_j2_AK4_pt
Float_t	bos_j2_AK4_pt_scaleDn
Float_t	bos_j2_AK4_pt_scaleUp
Float_t	btagWeight
Float_t	dibos_eta
Float_t	dibos_m
Float_t	dibos_m_scaleDn
Float_t	dibos_m_scaleUp
Float_t	dibos_phi
Float_t	dibos_pt
Float_t	dibos_pt_scaleDn
Float_t	dibos_pt_scaleUp
Float_t	dilep_eta
Float_t	dilep_m
Float_t	dilep_m_scaleDn
Float_t	dilep_m_scaleUp
Float_t	dilep_phi
Float_t	dilep_pt
Float_t	dilep_pt_scaleDn
Float_t	dilep_pt_scaleUp
Int_t	evt
Float_t	genWeight
Bool_t	isAntiIso
Float_t	lep1_dxy
Float_t	lep1_dz
Float_t	lep1_eta
Float_t	lep1_idEffWeight
Float_t	lep1_iso
Float_t	lep1_m
Float_t	lep1_phi
Float_t	lep1_pt
Float_t	lep1_pt_scaleDn
Float_t	lep1_pt_scaleUp
Float_t	lep1_q
Float_t	lep2_dxy
Float_t	lep2_dz
Float_t	lep2_eta
Float_t	lep2_idEffWeight
Float_t	lep2_iso
Float_t	lep2_m
Float_t	lep2_phi
Float_t	lep2_pt
Float_t	lep2_pt_scaleDn
Float_t	lep2_pt_scaleUp
Float_t	lep2_q
Int_t	ls
Int_t	nAqgcWeight
Int_t	nBtag_loose
Int_t	nBtag_medium
Int_t	nBtag_tight
Int_t	nJet30
Int_t	nJet50
Float_t	nPU_mean
Float_t	nPV
Int_t	nPdfWeight
Int_t	nScaleWeight
Float_t	neu_pz_type0
Float_t	neu_pz_type0_scaleDn
Float_t	neu_pz_type0_scaleUp
Float_t	pdfWeight
Float_t	puWeight
Float_t	puWeight_Dn
Float_t	puWeight_Up
Int_t	run
Float_t	scaleWeight
Float_t	scaleWeight
Bool_t	trigger_1El
Bool_t	trigger_1Mu
Bool_t	trigger_2El
Bool_t	trigger_2Mu
Float_t	vbf1_AK4_axis2
Float_t	vbf1_AK4_eta
Float_t	vbf1_AK4_m
Float_t	vbf1_AK4_m_scaleDn
Float_t	vbf1_AK4_m_scaleUp
Float_t	vbf1_AK4_phi
Float_t	vbf1_AK4_pt
Float_t	vbf1_AK4_ptD
Float_t	vbf1_AK4_pt_scaleDn
Float_t	vbf1_AK4_pt_scaleUp
Float_t	vbf1_AK4_gqid
Float_t	vbf2_AK4_axis2
Float_t	vbf2_AK4_eta
Float_t	vbf2_AK4_m
Float_t	vbf2_AK4_m_scaleDn
Float_t	vbf2_AK4_m_scaleUp
Float_t	vbf2_AK4_phi
Float_t	vbf2_AK4_pt
Float_t	vbf2_AK4_ptD
Float_t	vbf2_AK4_pt_scaleDn
Float_t	vbf2_AK4_pt_scaleUp
Float_t	vbf2_AK4_gqid
Float_t	vbf_eta
Float_t	vbf_m
Float_t	vbf_m_scaleDn
Float_t	vbf_m_scaleUp
Float_t	vbf_phi
Float_t	vbf_pt
Float_t	vbf_pt_scaleDn
Float_t	vbf_pt_scaleUp
Float_t	zeppHad
Float_t	zeppLep
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
vbsTree->SetBranchAddress( "L1PFWeight", 	 vbsEvent.L1PFWeight );
vbsTree->SetBranchAddress( "LHEWeight", 	 vbsEvent.LHEWeight );
vbsTree->SetBranchAddress( "MET", 	 vbsEvent.MET );
vbsTree->SetBranchAddress( "MET_2017raw", 	 vbsEvent.MET_2017raw );
vbsTree->SetBranchAddress( "MET_phi", 	 vbsEvent.MET_phi );
vbsTree->SetBranchAddress( "MET_scaleDn", 	 vbsEvent.MET_scaleDn );
vbsTree->SetBranchAddress( "MET_scaleUp", 	 vbsEvent.MET_scaleUp );
vbsTree->SetBranchAddress( "aqgcWeight", 	 vbsEvent.aqgcWeight );
vbsTree->SetBranchAddress( "bosCent", 	 vbsEvent.bosCent );
vbsTree->SetBranchAddress( "bos_AK4AK4_eta", 	 vbsEvent.bos_AK4AK4_eta );
vbsTree->SetBranchAddress( "bos_AK4AK4_m", 	 vbsEvent.bos_AK4AK4_m );
vbsTree->SetBranchAddress( "bos_AK4AK4_m_scaleDn", 	 vbsEvent.bos_AK4AK4_m_scaleDn );
vbsTree->SetBranchAddress( "bos_AK4AK4_m_scaleUp", 	 vbsEvent.bos_AK4AK4_m_scaleUp );
vbsTree->SetBranchAddress( "bos_AK4AK4_phi", 	 vbsEvent.bos_AK4AK4_phi );
vbsTree->SetBranchAddress( "bos_AK4AK4_pt", 	 vbsEvent.bos_AK4AK4_pt );
vbsTree->SetBranchAddress( "bos_AK4AK4_pt_scaleDn", 	 vbsEvent.bos_AK4AK4_pt_scaleDn );
vbsTree->SetBranchAddress( "bos_AK4AK4_pt_scaleUp", 	 vbsEvent.bos_AK4AK4_pt_scaleUp );
vbsTree->SetBranchAddress( "bos_PuppiAK8_e2_sdb1", 	 vbsEvent.bos_PuppiAK8_e2_sdb1 );
vbsTree->SetBranchAddress( "bos_PuppiAK8_e2_sdb2", 	 vbsEvent.bos_PuppiAK8_e2_sdb2 );
vbsTree->SetBranchAddress( "bos_PuppiAK8_e3_sdb1", 	 vbsEvent.bos_PuppiAK8_e3_sdb1 );
vbsTree->SetBranchAddress( "bos_PuppiAK8_e3_sdb2", 	 vbsEvent.bos_PuppiAK8_e3_sdb2 );
vbsTree->SetBranchAddress( "bos_PuppiAK8_e3_v1_sdb1", 	 vbsEvent.bos_PuppiAK8_e3_v1_sdb1 );
vbsTree->SetBranchAddress( "bos_PuppiAK8_e3_v1_sdb2", 	 vbsEvent.bos_PuppiAK8_e3_v1_sdb2 );
vbsTree->SetBranchAddress( "bos_PuppiAK8_e3_v2_sdb1", 	 vbsEvent.bos_PuppiAK8_e3_v2_sdb1 );
vbsTree->SetBranchAddress( "bos_PuppiAK8_e3_v2_sdb2", 	 vbsEvent.bos_PuppiAK8_e3_v2_sdb2 );
vbsTree->SetBranchAddress( "bos_PuppiAK8_e4_v1_sdb1", 	 vbsEvent.bos_PuppiAK8_e4_v1_sdb1 );
vbsTree->SetBranchAddress( "bos_PuppiAK8_e4_v1_sdb2", 	 vbsEvent.bos_PuppiAK8_e4_v1_sdb2 );
vbsTree->SetBranchAddress( "bos_PuppiAK8_e4_v2_sdb1", 	 vbsEvent.bos_PuppiAK8_e4_v2_sdb1 );
vbsTree->SetBranchAddress( "bos_PuppiAK8_e4_v2_sdb2", 	 vbsEvent.bos_PuppiAK8_e4_v2_sdb2 );
vbsTree->SetBranchAddress( "bos_PuppiAK8_eta", 	 vbsEvent.bos_PuppiAK8_eta );
vbsTree->SetBranchAddress( "bos_PuppiAK8_m_sd0", 	 vbsEvent.bos_PuppiAK8_m_sd0 );
vbsTree->SetBranchAddress( "bos_PuppiAK8_m_sd0_corr", 	 vbsEvent.bos_PuppiAK8_m_sd0_corr );
vbsTree->SetBranchAddress( "bos_PuppiAK8_m_sd0_corr_scaleDn", 	 vbsEvent.bos_PuppiAK8_m_sd0_corr_scaleDn );
vbsTree->SetBranchAddress( "bos_PuppiAK8_m_sd0_corr_scaleUp", 	 vbsEvent.bos_PuppiAK8_m_sd0_corr_scaleUp );
vbsTree->SetBranchAddress( "bos_PuppiAK8_phi", 	 vbsEvent.bos_PuppiAK8_phi );
vbsTree->SetBranchAddress( "bos_PuppiAK8_pt", 	 vbsEvent.bos_PuppiAK8_pt );
vbsTree->SetBranchAddress( "bos_PuppiAK8_pt_scaleDn", 	 vbsEvent.bos_PuppiAK8_pt_scaleDn );
vbsTree->SetBranchAddress( "bos_PuppiAK8_pt_scaleUp", 	 vbsEvent.bos_PuppiAK8_pt_scaleUp );
vbsTree->SetBranchAddress( "bos_PuppiAK8_tau2tau1", 	 vbsEvent.bos_PuppiAK8_tau2tau1 );
vbsTree->SetBranchAddress( "bos_j1_AK4_eta", 	 vbsEvent.bos_j1_AK4_eta );
vbsTree->SetBranchAddress( "bos_j1_AK4_m", 	 vbsEvent.bos_j1_AK4_m );
vbsTree->SetBranchAddress( "bos_j1_AK4_m_scaleDn", 	 vbsEvent.bos_j1_AK4_m_scaleDn );
vbsTree->SetBranchAddress( "bos_j1_AK4_m_scaleUp", 	 vbsEvent.bos_j1_AK4_m_scaleUp );
vbsTree->SetBranchAddress( "bos_j1_AK4_phi", 	 vbsEvent.bos_j1_AK4_phi );
vbsTree->SetBranchAddress( "bos_j1_AK4_pt", 	 vbsEvent.bos_j1_AK4_pt );
vbsTree->SetBranchAddress( "bos_j1_AK4_pt_scaleDn", 	 vbsEvent.bos_j1_AK4_pt_scaleDn );
vbsTree->SetBranchAddress( "bos_j1_AK4_pt_scaleUp", 	 vbsEvent.bos_j1_AK4_pt_scaleUp );
vbsTree->SetBranchAddress( "bos_j2_AK4_eta", 	 vbsEvent.bos_j2_AK4_eta );
vbsTree->SetBranchAddress( "bos_j2_AK4_m", 	 vbsEvent.bos_j2_AK4_m );
vbsTree->SetBranchAddress( "bos_j2_AK4_m_scaleDn", 	 vbsEvent.bos_j2_AK4_m_scaleDn );
vbsTree->SetBranchAddress( "bos_j2_AK4_m_scaleUp", 	 vbsEvent.bos_j2_AK4_m_scaleUp );
vbsTree->SetBranchAddress( "bos_j2_AK4_phi", 	 vbsEvent.bos_j2_AK4_phi );
vbsTree->SetBranchAddress( "bos_j2_AK4_pt", 	 vbsEvent.bos_j2_AK4_pt );
vbsTree->SetBranchAddress( "bos_j2_AK4_pt_scaleDn", 	 vbsEvent.bos_j2_AK4_pt_scaleDn );
vbsTree->SetBranchAddress( "bos_j2_AK4_pt_scaleUp", 	 vbsEvent.bos_j2_AK4_pt_scaleUp );
vbsTree->SetBranchAddress( "btagWeight", 	 vbsEvent.btagWeight );
vbsTree->SetBranchAddress( "dibos_eta", 	 vbsEvent.dibos_eta );
vbsTree->SetBranchAddress( "dibos_m", 	 vbsEvent.dibos_m );
vbsTree->SetBranchAddress( "dibos_m_scaleDn", 	 vbsEvent.dibos_m_scaleDn );
vbsTree->SetBranchAddress( "dibos_m_scaleUp", 	 vbsEvent.dibos_m_scaleUp );
vbsTree->SetBranchAddress( "dibos_phi", 	 vbsEvent.dibos_phi );
vbsTree->SetBranchAddress( "dibos_pt", 	 vbsEvent.dibos_pt );
vbsTree->SetBranchAddress( "dibos_pt_scaleDn", 	 vbsEvent.dibos_pt_scaleDn );
vbsTree->SetBranchAddress( "dibos_pt_scaleUp", 	 vbsEvent.dibos_pt_scaleUp );
vbsTree->SetBranchAddress( "dilep_eta", 	 vbsEvent.dilep_eta );
vbsTree->SetBranchAddress( "dilep_m", 	 vbsEvent.dilep_m );
vbsTree->SetBranchAddress( "dilep_m_scaleDn", 	 vbsEvent.dilep_m_scaleDn );
vbsTree->SetBranchAddress( "dilep_m_scaleUp", 	 vbsEvent.dilep_m_scaleUp );
vbsTree->SetBranchAddress( "dilep_phi", 	 vbsEvent.dilep_phi );
vbsTree->SetBranchAddress( "dilep_pt", 	 vbsEvent.dilep_pt );
vbsTree->SetBranchAddress( "dilep_pt_scaleDn", 	 vbsEvent.dilep_pt_scaleDn );
vbsTree->SetBranchAddress( "dilep_pt_scaleUp", 	 vbsEvent.dilep_pt_scaleUp );
vbsTree->SetBranchAddress( "evt", 	 vbsEvent.evt );
vbsTree->SetBranchAddress( "genWeight", 	 vbsEvent.genWeight );
vbsTree->SetBranchAddress( "isAntiIso", 	 vbsEvent.isAntiIso );
vbsTree->SetBranchAddress( "lep1_dxy", 	 vbsEvent.lep1_dxy );
vbsTree->SetBranchAddress( "lep1_dz", 	 vbsEvent.lep1_dz );
vbsTree->SetBranchAddress( "lep1_eta", 	 vbsEvent.lep1_eta );
vbsTree->SetBranchAddress( "lep1_idEffWeight", 	 vbsEvent.lep1_idEffWeight );
vbsTree->SetBranchAddress( "lep1_iso", 	 vbsEvent.lep1_iso );
vbsTree->SetBranchAddress( "lep1_m", 	 vbsEvent.lep1_m );
vbsTree->SetBranchAddress( "lep1_phi", 	 vbsEvent.lep1_phi );
vbsTree->SetBranchAddress( "lep1_pt", 	 vbsEvent.lep1_pt );
vbsTree->SetBranchAddress( "lep1_pt_scaleDn", 	 vbsEvent.lep1_pt_scaleDn );
vbsTree->SetBranchAddress( "lep1_pt_scaleUp", 	 vbsEvent.lep1_pt_scaleUp );
vbsTree->SetBranchAddress( "lep1_q", 	 vbsEvent.lep1_q );
vbsTree->SetBranchAddress( "lep2_dxy", 	 vbsEvent.lep2_dxy );
vbsTree->SetBranchAddress( "lep2_dz", 	 vbsEvent.lep2_dz );
vbsTree->SetBranchAddress( "lep2_eta", 	 vbsEvent.lep2_eta );
vbsTree->SetBranchAddress( "lep2_idEffWeight", 	 vbsEvent.lep2_idEffWeight );
vbsTree->SetBranchAddress( "lep2_iso", 	 vbsEvent.lep2_iso );
vbsTree->SetBranchAddress( "lep2_m", 	 vbsEvent.lep2_m );
vbsTree->SetBranchAddress( "lep2_phi", 	 vbsEvent.lep2_phi );
vbsTree->SetBranchAddress( "lep2_pt", 	 vbsEvent.lep2_pt );
vbsTree->SetBranchAddress( "lep2_pt_scaleDn", 	 vbsEvent.lep2_pt_scaleDn );
vbsTree->SetBranchAddress( "lep2_pt_scaleUp", 	 vbsEvent.lep2_pt_scaleUp );
vbsTree->SetBranchAddress( "lep2_q", 	 vbsEvent.lep2_q );
vbsTree->SetBranchAddress( "ls", 	 vbsEvent.ls );
vbsTree->SetBranchAddress( "nAqgcWeight", 	 vbsEvent.nAqgcWeight );
vbsTree->SetBranchAddress( "nBtag_loose", 	 vbsEvent.nBtag_loose );
vbsTree->SetBranchAddress( "nBtag_medium", 	 vbsEvent.nBtag_medium );
vbsTree->SetBranchAddress( "nBtag_tight", 	 vbsEvent.nBtag_tight );
vbsTree->SetBranchAddress( "nJet30", 	 vbsEvent.nJet30 );
vbsTree->SetBranchAddress( "nJet50", 	 vbsEvent.nJet50 );
vbsTree->SetBranchAddress( "nPU_mean", 	 vbsEvent.nPU_mean );
vbsTree->SetBranchAddress( "nPV", 	 vbsEvent.nPV );
vbsTree->SetBranchAddress( "nPdfWeight", 	 vbsEvent.nPdfWeight );
vbsTree->SetBranchAddress( "nScaleWeight", 	 vbsEvent.nScaleWeight );
vbsTree->SetBranchAddress( "neu_pz_type0", 	 vbsEvent.neu_pz_type0 );
vbsTree->SetBranchAddress( "neu_pz_type0_scaleDn", 	 vbsEvent.neu_pz_type0_scaleDn );
vbsTree->SetBranchAddress( "neu_pz_type0_scaleUp", 	 vbsEvent.neu_pz_type0_scaleUp );
vbsTree->SetBranchAddress( "pdfWeight", 	 vbsEvent.pdfWeight );
vbsTree->SetBranchAddress( "puWeight", 	 vbsEvent.puWeight );
vbsTree->SetBranchAddress( "puWeight_Dn", 	 vbsEvent.puWeight_Dn );
vbsTree->SetBranchAddress( "puWeight_Up", 	 vbsEvent.puWeight_Up );
vbsTree->SetBranchAddress( "run", 	 vbsEvent.run );
vbsTree->SetBranchAddress( "scaleWeight", 	 vbsEvent.scaleWeight );
vbsTree->SetBranchAddress( "scaleWeight", 	 vbsEvent.scaleWeight );
vbsTree->SetBranchAddress( "trigger_1El", 	 vbsEvent.trigger_1El );
vbsTree->SetBranchAddress( "trigger_1Mu", 	 vbsEvent.trigger_1Mu );
vbsTree->SetBranchAddress( "trigger_2El", 	 vbsEvent.trigger_2El );
vbsTree->SetBranchAddress( "trigger_2Mu", 	 vbsEvent.trigger_2Mu );
vbsTree->SetBranchAddress( "vbf1_AK4_axis2", 	 vbsEvent.vbf1_AK4_axis2 );
vbsTree->SetBranchAddress( "vbf1_AK4_eta", 	 vbsEvent.vbf1_AK4_eta );
vbsTree->SetBranchAddress( "vbf1_AK4_m", 	 vbsEvent.vbf1_AK4_m );
vbsTree->SetBranchAddress( "vbf1_AK4_m_scaleDn", 	 vbsEvent.vbf1_AK4_m_scaleDn );
vbsTree->SetBranchAddress( "vbf1_AK4_m_scaleUp", 	 vbsEvent.vbf1_AK4_m_scaleUp );
vbsTree->SetBranchAddress( "vbf1_AK4_phi", 	 vbsEvent.vbf1_AK4_phi );
vbsTree->SetBranchAddress( "vbf1_AK4_pt", 	 vbsEvent.vbf1_AK4_pt );
vbsTree->SetBranchAddress( "vbf1_AK4_ptD", 	 vbsEvent.vbf1_AK4_ptD );
vbsTree->SetBranchAddress( "vbf1_AK4_pt_scaleDn", 	 vbsEvent.vbf1_AK4_pt_scaleDn );
vbsTree->SetBranchAddress( "vbf1_AK4_pt_scaleUp", 	 vbsEvent.vbf1_AK4_pt_scaleUp );
vbsTree->SetBranchAddress( "vbf1_AK4_gqid", 	 vbsEvent.vbf1_AK4_gqid );
vbsTree->SetBranchAddress( "vbf2_AK4_axis2", 	 vbsEvent.vbf2_AK4_axis2 );
vbsTree->SetBranchAddress( "vbf2_AK4_eta", 	 vbsEvent.vbf2_AK4_eta );
vbsTree->SetBranchAddress( "vbf2_AK4_m", 	 vbsEvent.vbf2_AK4_m );
vbsTree->SetBranchAddress( "vbf2_AK4_m_scaleDn", 	 vbsEvent.vbf2_AK4_m_scaleDn );
vbsTree->SetBranchAddress( "vbf2_AK4_m_scaleUp", 	 vbsEvent.vbf2_AK4_m_scaleUp );
vbsTree->SetBranchAddress( "vbf2_AK4_phi", 	 vbsEvent.vbf2_AK4_phi );
vbsTree->SetBranchAddress( "vbf2_AK4_pt", 	 vbsEvent.vbf2_AK4_pt );
vbsTree->SetBranchAddress( "vbf2_AK4_ptD", 	 vbsEvent.vbf2_AK4_ptD );
vbsTree->SetBranchAddress( "vbf2_AK4_pt_scaleDn", 	 vbsEvent.vbf2_AK4_pt_scaleDn );
vbsTree->SetBranchAddress( "vbf2_AK4_pt_scaleUp", 	 vbsEvent.vbf2_AK4_pt_scaleUp );
vbsTree->SetBranchAddress( "vbf2_AK4_gqid", 	 vbsEvent.vbf2_AK4_gqid );
vbsTree->SetBranchAddress( "vbf_eta", 	 vbsEvent.vbf_eta );
vbsTree->SetBranchAddress( "vbf_m", 	 vbsEvent.vbf_m );
vbsTree->SetBranchAddress( "vbf_m_scaleDn", 	 vbsEvent.vbf_m_scaleDn );
vbsTree->SetBranchAddress( "vbf_m_scaleUp", 	 vbsEvent.vbf_m_scaleUp );
vbsTree->SetBranchAddress( "vbf_phi", 	 vbsEvent.vbf_phi );
vbsTree->SetBranchAddress( "vbf_pt", 	 vbsEvent.vbf_pt );
vbsTree->SetBranchAddress( "vbf_pt_scaleDn", 	 vbsEvent.vbf_pt_scaleDn );
vbsTree->SetBranchAddress( "vbf_pt_scaleUp", 	 vbsEvent.vbf_pt_scaleUp );
vbsTree->SetBranchAddress( "zeppHad", 	 vbsEvent.zeppHad );
vbsTree->SetBranchAddress( "zeppLep", 	 vbsEvent.zeppLep );
 // }
}
//=======================================
#endif
