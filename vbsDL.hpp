#ifndef vbsDL_hpp
#define vbsDL_hpp
//
//Note::Autogenerated with writeDL.sh on Sun May 30 15:13:58 EDT 2021
//Please check vbsDL*.hpp for available configurations.
//TMVA vars:
// l_pt1  l_eta1 pfMET_Corr ungroomed_PuppiAK8_jet_pt PuppiAK8_jet_tau2tau1 PuppiAK8_jet_mass_so_corr vbf_maxpt_jj_m vbf_maxpt_j2_eta vbf_maxpt_j1_eta vbf_maxpt_j1_pt  vbf_maxpt_j2_pt mass_lvj_type0_PuppiAK8 BosonCentrality_type0 ZeppenfeldWL_type0 ZeppenfeldWH
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

//TMVA variable
if(dataloader) dataloader->AddVariable("BosonCentrality_type0", "BosonCentrality_type0", "", 'F');
if(datareader) datareader->AddVariable("BosonCentrality_type0",    &vbsEvent.BosonCentrality_type0        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("L1_Prefweight",    "L1_Prefweight",   "",      'F');
if(datareader) datareader->AddSpectator("L1_Prefweight",    &vbsEvent.L1_Prefweight        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("PtBalance_type0",    "PtBalance_type0",   "",      'F');
if(datareader) datareader->AddSpectator("PtBalance_type0",    &vbsEvent.PtBalance_type0        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("PtBalance_type2",    "PtBalance_type2",   "",      'F');
if(datareader) datareader->AddSpectator("PtBalance_type2",    &vbsEvent.PtBalance_type2        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("PuppiAK8_jet_mass",    "PuppiAK8_jet_mass",   "",      'F');
if(datareader) datareader->AddSpectator("PuppiAK8_jet_mass",    &vbsEvent.PuppiAK8_jet_mass        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("PuppiAK8_jet_mass_pr",    "PuppiAK8_jet_mass_pr",   "",      'F');
if(datareader) datareader->AddSpectator("PuppiAK8_jet_mass_pr",    &vbsEvent.PuppiAK8_jet_mass_pr        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("PuppiAK8_jet_mass_so_corr", "PuppiAK8_jet_mass_so_corr", "", 'F');
if(datareader) datareader->AddVariable("PuppiAK8_jet_mass_so_corr",    &vbsEvent.PuppiAK8_jet_mass_so_corr        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("PuppiAK8_jet_mass_tr",    "PuppiAK8_jet_mass_tr",   "",      'F');
if(datareader) datareader->AddSpectator("PuppiAK8_jet_mass_tr",    &vbsEvent.PuppiAK8_jet_mass_tr        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("PuppiAK8_jet_sj1_eta",    "PuppiAK8_jet_sj1_eta",   "",      'F');
if(datareader) datareader->AddSpectator("PuppiAK8_jet_sj1_eta",    &vbsEvent.PuppiAK8_jet_sj1_eta        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("PuppiAK8_jet_sj1_m",    "PuppiAK8_jet_sj1_m",   "",      'F');
if(datareader) datareader->AddSpectator("PuppiAK8_jet_sj1_m",    &vbsEvent.PuppiAK8_jet_sj1_m        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("PuppiAK8_jet_sj1_phi",    "PuppiAK8_jet_sj1_phi",   "",      'F');
if(datareader) datareader->AddSpectator("PuppiAK8_jet_sj1_phi",    &vbsEvent.PuppiAK8_jet_sj1_phi        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("PuppiAK8_jet_sj1_pt",    "PuppiAK8_jet_sj1_pt",   "",      'F');
if(datareader) datareader->AddSpectator("PuppiAK8_jet_sj1_pt",    &vbsEvent.PuppiAK8_jet_sj1_pt        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("PuppiAK8_jet_sj1_q",    "PuppiAK8_jet_sj1_q",   "",      'F');
if(datareader) datareader->AddSpectator("PuppiAK8_jet_sj1_q",    &vbsEvent.PuppiAK8_jet_sj1_q        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("PuppiAK8_jet_sj2_eta",    "PuppiAK8_jet_sj2_eta",   "",      'F');
if(datareader) datareader->AddSpectator("PuppiAK8_jet_sj2_eta",    &vbsEvent.PuppiAK8_jet_sj2_eta        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("PuppiAK8_jet_sj2_m",    "PuppiAK8_jet_sj2_m",   "",      'F');
if(datareader) datareader->AddSpectator("PuppiAK8_jet_sj2_m",    &vbsEvent.PuppiAK8_jet_sj2_m        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("PuppiAK8_jet_sj2_phi",    "PuppiAK8_jet_sj2_phi",   "",      'F');
if(datareader) datareader->AddSpectator("PuppiAK8_jet_sj2_phi",    &vbsEvent.PuppiAK8_jet_sj2_phi        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("PuppiAK8_jet_sj2_pt",    "PuppiAK8_jet_sj2_pt",   "",      'F');
if(datareader) datareader->AddSpectator("PuppiAK8_jet_sj2_pt",    &vbsEvent.PuppiAK8_jet_sj2_pt        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("PuppiAK8_jet_sj2_q",    "PuppiAK8_jet_sj2_q",   "",      'F');
if(datareader) datareader->AddSpectator("PuppiAK8_jet_sj2_q",    &vbsEvent.PuppiAK8_jet_sj2_q        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("PuppiAK8_jet_tau2tau1", "PuppiAK8_jet_tau2tau1", "", 'F');
if(datareader) datareader->AddVariable("PuppiAK8_jet_tau2tau1",    &vbsEvent.PuppiAK8_jet_tau2tau1        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("PuppiAK8jet_qjet",    "PuppiAK8jet_qjet",   "",      'F');
if(datareader) datareader->AddSpectator("PuppiAK8jet_qjet",    &vbsEvent.PuppiAK8jet_qjet        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("ZeppenfeldWH", "ZeppenfeldWH", "", 'F');
if(datareader) datareader->AddVariable("ZeppenfeldWH",    &vbsEvent.ZeppenfeldWH        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("ZeppenfeldWL_type0", "ZeppenfeldWL_type0", "", 'F');
if(datareader) datareader->AddVariable("ZeppenfeldWL_type0",    &vbsEvent.ZeppenfeldWL_type0        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("btag0Wgt",    "btag0Wgt",   "",      'F');
if(datareader) datareader->AddSpectator("btag0Wgt",    &vbsEvent.btag0Wgt        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("costheta1_type0",    "costheta1_type0",   "",      'F');
if(datareader) datareader->AddSpectator("costheta1_type0",    &vbsEvent.costheta1_type0        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("costheta1_type2",    "costheta1_type2",   "",      'F');
if(datareader) datareader->AddSpectator("costheta1_type2",    &vbsEvent.costheta1_type2        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("costheta2_type0",    "costheta2_type0",   "",      'F');
if(datareader) datareader->AddSpectator("costheta2_type0",    &vbsEvent.costheta2_type0        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("costheta2_type2",    "costheta2_type2",   "",      'F');
if(datareader) datareader->AddSpectator("costheta2_type2",    &vbsEvent.costheta2_type2        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("costhetastar_type0",    "costhetastar_type0",   "",      'F');
if(datareader) datareader->AddSpectator("costhetastar_type0",    &vbsEvent.costhetastar_type0        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("costhetastar_type2",    "costhetastar_type2",   "",      'F');
if(datareader) datareader->AddSpectator("costhetastar_type2",    &vbsEvent.costhetastar_type2        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("deltaR_lPuppiak8jet",    "deltaR_lPuppiak8jet",   "",      'F');
if(datareader) datareader->AddSpectator("deltaR_lPuppiak8jet",    &vbsEvent.deltaR_lPuppiak8jet        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("deltaphi_METPuppiak8jet",    "deltaphi_METPuppiak8jet",   "",      'F');
if(datareader) datareader->AddSpectator("deltaphi_METPuppiak8jet",    &vbsEvent.deltaphi_METPuppiak8jet        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("deltaphi_METmin",    "deltaphi_METmin",   "",      'F');
if(datareader) datareader->AddSpectator("deltaphi_METmin",    &vbsEvent.deltaphi_METmin        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("deltaphi_METvbfJ1",    "deltaphi_METvbfJ1",   "",      'F');
if(datareader) datareader->AddSpectator("deltaphi_METvbfJ1",    &vbsEvent.deltaphi_METvbfJ1        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("deltaphi_METvbfJ2",    "deltaphi_METvbfJ2",   "",      'F');
if(datareader) datareader->AddSpectator("deltaphi_METvbfJ2",    &vbsEvent.deltaphi_METvbfJ2        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("deltaphi_VPuppiak8jet",    "deltaphi_VPuppiak8jet",   "",      'F');
if(datareader) datareader->AddSpectator("deltaphi_VPuppiak8jet",    &vbsEvent.deltaphi_VPuppiak8jet        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("event",    "event",   "",      'I');
if(datareader) datareader->AddSpectator("event",    &vbsEvent.event        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("genWeight",    "genWeight",   "",      'F');
if(datareader) datareader->AddSpectator("genWeight",    &vbsEvent.genWeight        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("gid",    "gid",   "",      'I');
if(datareader) datareader->AddSpectator("gid",    &vbsEvent.gid        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("id_eff_Weight",    "id_eff_Weight",   "",      'F');
if(datareader) datareader->AddSpectator("id_eff_Weight",    &vbsEvent.id_eff_Weight        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("isVBF",    "isVBF",   "",      'I');
if(datareader) datareader->AddSpectator("isVBF",    &vbsEvent.isVBF        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("l_charge1",    "l_charge1",   "",      'I');
if(datareader) datareader->AddSpectator("l_charge1",    &vbsEvent.l_charge1        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("l_e1",    "l_e1",   "",      'F');
if(datareader) datareader->AddSpectator("l_e1",    &vbsEvent.l_e1        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("l_eta1", "l_eta1", "", 'F');
if(datareader) datareader->AddVariable("l_eta1",    &vbsEvent.l_eta1        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("l_iso1",    "l_iso1",   "",      'F');
if(datareader) datareader->AddSpectator("l_iso1",    &vbsEvent.l_iso1        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("l_phi1",    "l_phi1",   "",      'F');
if(datareader) datareader->AddSpectator("l_phi1",    &vbsEvent.l_phi1        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("l_pt1", "l_pt1", "", 'F');
if(datareader) datareader->AddVariable("l_pt1",    &vbsEvent.l_pt1        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("l_pt2",    "l_pt2",   "",      'F');
if(datareader) datareader->AddSpectator("l_pt2",    &vbsEvent.l_pt2        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("lumi",    "lumi",   "",      'I');
if(datareader) datareader->AddSpectator("lumi",    &vbsEvent.lumi        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("mass_lvj_type0_PuppiAK8", "mass_lvj_type0_PuppiAK8", "", 'F');
if(datareader) datareader->AddVariable("mass_lvj_type0_PuppiAK8",    &vbsEvent.mass_lvj_type0_PuppiAK8        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("mcWeight",    "mcWeight",   "",      'F');
if(datareader) datareader->AddSpectator("mcWeight",    &vbsEvent.mcWeight        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("mt_lvj_type0_PuppiAK8",    "mt_lvj_type0_PuppiAK8",   "",      'F');
if(datareader) datareader->AddSpectator("mt_lvj_type0_PuppiAK8",    &vbsEvent.mt_lvj_type0_PuppiAK8        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("nBTagJet_loose",    "nBTagJet_loose",   "",      'I');
if(datareader) datareader->AddSpectator("nBTagJet_loose",    &vbsEvent.nBTagJet_loose        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("nBTagJet_medium",    "nBTagJet_medium",   "",      'I');
if(datareader) datareader->AddSpectator("nBTagJet_medium",    &vbsEvent.nBTagJet_medium        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("nGoodPuppiAK8jets",    "nGoodPuppiAK8jets",   "",      'I');
if(datareader) datareader->AddSpectator("nGoodPuppiAK8jets",    &vbsEvent.nGoodPuppiAK8jets        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("nPV",    "nPV",   "",      'I');
if(datareader) datareader->AddSpectator("nPV",    &vbsEvent.nPV        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("nTotEvents",    "nTotEvents",   "",      'I');
if(datareader) datareader->AddSpectator("nTotEvents",    &vbsEvent.nTotEvents        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("njets",    "njets",   "",      'I');
if(datareader) datareader->AddSpectator("njets",    &vbsEvent.njets        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("nu_pz_type0",    "nu_pz_type0",   "",      'F');
if(datareader) datareader->AddSpectator("nu_pz_type0",    &vbsEvent.nu_pz_type0        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("pfMET_Corr", "pfMET_Corr", "", 'F');
if(datareader) datareader->AddVariable("pfMET_Corr",    &vbsEvent.pfMET_Corr        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("pfMET_Corr_phi",    "pfMET_Corr_phi",   "",      'F');
if(datareader) datareader->AddSpectator("pfMET_Corr_phi",    &vbsEvent.pfMET_Corr_phi        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("phi1_type0",    "phi1_type0",   "",      'F');
if(datareader) datareader->AddSpectator("phi1_type0",    &vbsEvent.phi1_type0        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("phi1_type2",    "phi1_type2",   "",      'F');
if(datareader) datareader->AddSpectator("phi1_type2",    &vbsEvent.phi1_type2        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("phi_type0",    "phi_type0",   "",      'F');
if(datareader) datareader->AddSpectator("phi_type0",    &vbsEvent.phi_type0        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("phi_type2",    "phi_type2",   "",      'F');
if(datareader) datareader->AddSpectator("phi_type2",    &vbsEvent.phi_type2        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("pu_Weight",    "pu_Weight",   "",      'F');
if(datareader) datareader->AddSpectator("pu_Weight",    &vbsEvent.pu_Weight        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("run",    "run",   "",      'I');
if(datareader) datareader->AddSpectator("run",    &vbsEvent.run        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("sid",    "sid",   "",      'I');
if(datareader) datareader->AddSpectator("sid",    &vbsEvent.sid        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("totalEventWeight",    "totalEventWeight",   "",      'F');
if(datareader) datareader->AddSpectator("totalEventWeight",    &vbsEvent.totalEventWeight        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("trig_eff_Weight",    "trig_eff_Weight",   "",      'F');
if(datareader) datareader->AddSpectator("trig_eff_Weight",    &vbsEvent.trig_eff_Weight        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("type",    "type",   "",      'I');
if(datareader) datareader->AddSpectator("type",    &vbsEvent.type        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("ungroomed_PuppiAK8_jet_charge",    "ungroomed_PuppiAK8_jet_charge",   "",      'I');
if(datareader) datareader->AddSpectator("ungroomed_PuppiAK8_jet_charge",    &vbsEvent.ungroomed_PuppiAK8_jet_charge        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("ungroomed_PuppiAK8_jet_e",    "ungroomed_PuppiAK8_jet_e",   "",      'F');
if(datareader) datareader->AddSpectator("ungroomed_PuppiAK8_jet_e",    &vbsEvent.ungroomed_PuppiAK8_jet_e        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("ungroomed_PuppiAK8_jet_eta",    "ungroomed_PuppiAK8_jet_eta",   "",      'F');
if(datareader) datareader->AddSpectator("ungroomed_PuppiAK8_jet_eta",    &vbsEvent.ungroomed_PuppiAK8_jet_eta        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("ungroomed_PuppiAK8_jet_phi",    "ungroomed_PuppiAK8_jet_phi",   "",      'F');
if(datareader) datareader->AddSpectator("ungroomed_PuppiAK8_jet_phi",    &vbsEvent.ungroomed_PuppiAK8_jet_phi        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("ungroomed_PuppiAK8_jet_pt", "ungroomed_PuppiAK8_jet_pt", "", 'F');
if(datareader) datareader->AddVariable("ungroomed_PuppiAK8_jet_pt",    &vbsEvent.ungroomed_PuppiAK8_jet_pt        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("v_mt_type0",    "v_mt_type0",   "",      'F');
if(datareader) datareader->AddSpectator("v_mt_type0",    &vbsEvent.v_mt_type0        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("v_pt_type0",    "v_pt_type0",   "",      'F');
if(datareader) datareader->AddSpectator("v_pt_type0",    &vbsEvent.v_pt_type0        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("vbf_maxpt_j1_eta", "vbf_maxpt_j1_eta", "", 'F');
if(datareader) datareader->AddVariable("vbf_maxpt_j1_eta",    &vbsEvent.vbf_maxpt_j1_eta        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("vbf_maxpt_j1_pt", "vbf_maxpt_j1_pt", "", 'F');
if(datareader) datareader->AddVariable("vbf_maxpt_j1_pt",    &vbsEvent.vbf_maxpt_j1_pt        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("vbf_maxpt_j2_eta", "vbf_maxpt_j2_eta", "", 'F');
if(datareader) datareader->AddVariable("vbf_maxpt_j2_eta",    &vbsEvent.vbf_maxpt_j2_eta        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("vbf_maxpt_j2_pt", "vbf_maxpt_j2_pt", "", 'F');
if(datareader) datareader->AddVariable("vbf_maxpt_j2_pt",    &vbsEvent.vbf_maxpt_j2_pt        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("vbf_maxpt_jj_Deta",    "vbf_maxpt_jj_Deta",   "",      'F');
if(datareader) datareader->AddSpectator("vbf_maxpt_jj_Deta",    &vbsEvent.vbf_maxpt_jj_Deta        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("vbf_maxpt_jj_m", "vbf_maxpt_jj_m", "", 'F');
if(datareader) datareader->AddVariable("vbf_maxpt_jj_m",    &vbsEvent.vbf_maxpt_jj_m        );
 
}
//=======================================
//========================================
void setChainBranches (TChain* inpChain){
//
   inpChain->SetBranchStatus("*", 0);   // disable all branches
// switch on required  branches
inpChain->SetBranchStatus("BosonCentrality_type0", 1);
inpChain->SetBranchStatus("L1_Prefweight", 1);
inpChain->SetBranchStatus("PtBalance_type0", 1);
inpChain->SetBranchStatus("PtBalance_type2", 1);
inpChain->SetBranchStatus("PuppiAK8_jet_mass", 1);
inpChain->SetBranchStatus("PuppiAK8_jet_mass_pr", 1);
inpChain->SetBranchStatus("PuppiAK8_jet_mass_so_corr", 1);
inpChain->SetBranchStatus("PuppiAK8_jet_mass_tr", 1);
inpChain->SetBranchStatus("PuppiAK8_jet_sj1_eta", 1);
inpChain->SetBranchStatus("PuppiAK8_jet_sj1_m", 1);
inpChain->SetBranchStatus("PuppiAK8_jet_sj1_phi", 1);
inpChain->SetBranchStatus("PuppiAK8_jet_sj1_pt", 1);
inpChain->SetBranchStatus("PuppiAK8_jet_sj1_q", 1);
inpChain->SetBranchStatus("PuppiAK8_jet_sj2_eta", 1);
inpChain->SetBranchStatus("PuppiAK8_jet_sj2_m", 1);
inpChain->SetBranchStatus("PuppiAK8_jet_sj2_phi", 1);
inpChain->SetBranchStatus("PuppiAK8_jet_sj2_pt", 1);
inpChain->SetBranchStatus("PuppiAK8_jet_sj2_q", 1);
inpChain->SetBranchStatus("PuppiAK8_jet_tau2tau1", 1);
inpChain->SetBranchStatus("PuppiAK8jet_qjet", 1);
inpChain->SetBranchStatus("ZeppenfeldWH", 1);
inpChain->SetBranchStatus("ZeppenfeldWL_type0", 1);
inpChain->SetBranchStatus("btag0Wgt", 1);
inpChain->SetBranchStatus("costheta1_type0", 1);
inpChain->SetBranchStatus("costheta1_type2", 1);
inpChain->SetBranchStatus("costheta2_type0", 1);
inpChain->SetBranchStatus("costheta2_type2", 1);
inpChain->SetBranchStatus("costhetastar_type0", 1);
inpChain->SetBranchStatus("costhetastar_type2", 1);
inpChain->SetBranchStatus("deltaR_lPuppiak8jet", 1);
inpChain->SetBranchStatus("deltaphi_METPuppiak8jet", 1);
inpChain->SetBranchStatus("deltaphi_METmin", 1);
inpChain->SetBranchStatus("deltaphi_METvbfJ1", 1);
inpChain->SetBranchStatus("deltaphi_METvbfJ2", 1);
inpChain->SetBranchStatus("deltaphi_VPuppiak8jet", 1);
inpChain->SetBranchStatus("event", 1);
inpChain->SetBranchStatus("genWeight", 1);
inpChain->SetBranchStatus("gid", 1);
inpChain->SetBranchStatus("id_eff_Weight", 1);
inpChain->SetBranchStatus("isVBF", 1);
inpChain->SetBranchStatus("l_charge1", 1);
inpChain->SetBranchStatus("l_e1", 1);
inpChain->SetBranchStatus("l_eta1", 1);
inpChain->SetBranchStatus("l_iso1", 1);
inpChain->SetBranchStatus("l_phi1", 1);
inpChain->SetBranchStatus("l_pt1", 1);
inpChain->SetBranchStatus("l_pt2", 1);
inpChain->SetBranchStatus("lumi", 1);
inpChain->SetBranchStatus("mass_lvj_type0_PuppiAK8", 1);
inpChain->SetBranchStatus("mcWeight", 1);
inpChain->SetBranchStatus("mt_lvj_type0_PuppiAK8", 1);
inpChain->SetBranchStatus("nBTagJet_loose", 1);
inpChain->SetBranchStatus("nBTagJet_medium", 1);
inpChain->SetBranchStatus("nGoodPuppiAK8jets", 1);
inpChain->SetBranchStatus("nPV", 1);
inpChain->SetBranchStatus("nTotEvents", 1);
inpChain->SetBranchStatus("njets", 1);
inpChain->SetBranchStatus("nu_pz_type0", 1);
inpChain->SetBranchStatus("pfMET_Corr", 1);
inpChain->SetBranchStatus("pfMET_Corr_phi", 1);
inpChain->SetBranchStatus("phi1_type0", 1);
inpChain->SetBranchStatus("phi1_type2", 1);
inpChain->SetBranchStatus("phi_type0", 1);
inpChain->SetBranchStatus("phi_type2", 1);
inpChain->SetBranchStatus("pu_Weight", 1);
inpChain->SetBranchStatus("run", 1);
inpChain->SetBranchStatus("sid", 1);
inpChain->SetBranchStatus("totalEventWeight", 1);
inpChain->SetBranchStatus("trig_eff_Weight", 1);
inpChain->SetBranchStatus("type", 1);
inpChain->SetBranchStatus("ungroomed_PuppiAK8_jet_charge", 1);
inpChain->SetBranchStatus("ungroomed_PuppiAK8_jet_e", 1);
inpChain->SetBranchStatus("ungroomed_PuppiAK8_jet_eta", 1);
inpChain->SetBranchStatus("ungroomed_PuppiAK8_jet_phi", 1);
inpChain->SetBranchStatus("ungroomed_PuppiAK8_jet_pt", 1);
inpChain->SetBranchStatus("v_mt_type0", 1);
inpChain->SetBranchStatus("v_pt_type0", 1);
inpChain->SetBranchStatus("vbf_maxpt_j1_eta", 1);
inpChain->SetBranchStatus("vbf_maxpt_j1_pt", 1);
inpChain->SetBranchStatus("vbf_maxpt_j2_eta", 1);
inpChain->SetBranchStatus("vbf_maxpt_j2_pt", 1);
inpChain->SetBranchStatus("vbf_maxpt_jj_Deta", 1);
inpChain->SetBranchStatus("vbf_maxpt_jj_m", 1);
}
//=============================
#endif
