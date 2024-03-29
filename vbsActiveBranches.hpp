#ifndef vbsActiveBranches_hpp
#define vbsActiveBranches_hpp
////////////////////////////////////////////////////////////////////////
// : vbsActiveBranches.hpp
// 
// File:    vbsActiveBranches.hpp
// Purpose: set active Branches for VBS analysis interface to TMVA 
// (works with VBS4LeptonsAnalysisReduced trees)   
// Autogenerated using write_vbsDL.sh
////////////////////////////////////////////////////////////////////////
#include "TROOT.h"
#include "TChain.h"

void   setChainBranches (TChain* inpChain);
//========================================
void setChainBranches (TChain* inpChain){
//
   inpChain->SetBranchStatus("", kFALSE);   // disable all branches
// switch on required  branches
inpChain->SetBranchStatus("AntiIsoInt", 1);
inpChain->SetBranchStatus("bos_AK4AK4_eta", 1);
inpChain->SetBranchStatus("bos_AK4AK4_m", 1);
inpChain->SetBranchStatus("bos_AK4AK4_pt", 1);
inpChain->SetBranchStatus("bosCent", 1);
inpChain->SetBranchStatus("bos_j1_AK4_eta", 1);
inpChain->SetBranchStatus("bos_j1_AK4_pt", 1);
inpChain->SetBranchStatus("bos_j2_AK4_eta", 1);
inpChain->SetBranchStatus("bos_j2_AK4_pt", 1);
inpChain->SetBranchStatus("bos_PuppiAK8_eta", 1);
inpChain->SetBranchStatus("bos_PuppiAK8_m_sd0", 1);
inpChain->SetBranchStatus("bos_PuppiAK8_m_sd0_corr", 1);
inpChain->SetBranchStatus("bos_PuppiAK8_phi", 1);
inpChain->SetBranchStatus("bos_PuppiAK8_pt", 1);
inpChain->SetBranchStatus("bos_PuppiAK8_tau2tau1", 1);
inpChain->SetBranchStatus("btagWeight_loose", 1);
inpChain->SetBranchStatus("dibos_eta", 1);
inpChain->SetBranchStatus("dibos_m", 1);
inpChain->SetBranchStatus("dibos_mt", 1);
inpChain->SetBranchStatus("dibos_phi", 1);
inpChain->SetBranchStatus("dibos_pt", 1);
inpChain->SetBranchStatus("dilep_eta", 1);
inpChain->SetBranchStatus("dilep_m", 1);
inpChain->SetBranchStatus("dilep_mt", 1);
inpChain->SetBranchStatus("dilep_phi", 1);
inpChain->SetBranchStatus("dilep_pt", 1);
inpChain->SetBranchStatus("evt", 1);
inpChain->SetBranchStatus("genWeight", 1);
inpChain->SetBranchStatus("gid", 1);
inpChain->SetBranchStatus("L1PFWeight", 1);
inpChain->SetBranchStatus("lep1_eta", 1);
inpChain->SetBranchStatus("lep1_idEffWeight", 1);
inpChain->SetBranchStatus("lep1_iso", 1);
inpChain->SetBranchStatus("lep1_m", 1);
inpChain->SetBranchStatus("lep1_phi", 1);
inpChain->SetBranchStatus("lep1_pt", 1);
inpChain->SetBranchStatus("lep1_q", 1);
inpChain->SetBranchStatus("lep1_trigEffWeight", 1);
inpChain->SetBranchStatus("lep2_eta", 1);
inpChain->SetBranchStatus("lep2_idEffWeight", 1);
inpChain->SetBranchStatus("lep2_phi", 1);
inpChain->SetBranchStatus("lep2_pt", 1);
inpChain->SetBranchStatus("lep2_trigEffWeight", 1);
inpChain->SetBranchStatus("lumin", 1);
inpChain->SetBranchStatus("mcWeight", 1);
inpChain->SetBranchStatus("MET", 1);
inpChain->SetBranchStatus("MET_phi", 1);
inpChain->SetBranchStatus("nBtag_loose", 1);
inpChain->SetBranchStatus("nBtag_medium", 1);
inpChain->SetBranchStatus("neu_pz_type0", 1);
inpChain->SetBranchStatus("nJet30", 1);
inpChain->SetBranchStatus("nJet30f", 1);
inpChain->SetBranchStatus("nJet50", 1);
inpChain->SetBranchStatus("nPV", 1);
inpChain->SetBranchStatus("puWeight", 1);
inpChain->SetBranchStatus("run", 1);
inpChain->SetBranchStatus("sid", 1);
inpChain->SetBranchStatus("vbf1_AK4_eta", 1);
inpChain->SetBranchStatus("vbf1_AK4_m", 1);
inpChain->SetBranchStatus("vbf1_AK4_phi", 1);
inpChain->SetBranchStatus("vbf1_AK4_pt", 1);
inpChain->SetBranchStatus("vbf1_AK4_qgid", 1);
inpChain->SetBranchStatus("vbf2_AK4_eta", 1);
inpChain->SetBranchStatus("vbf2_AK4_m", 1);
inpChain->SetBranchStatus("vbf2_AK4_phi", 1);
inpChain->SetBranchStatus("vbf2_AK4_pt", 1);
inpChain->SetBranchStatus("vbf2_AK4_qgid", 1);
inpChain->SetBranchStatus("vbf_deta", 1);
inpChain->SetBranchStatus("vbf_eta", 1);
inpChain->SetBranchStatus("vbf_m", 1);
inpChain->SetBranchStatus("vbf_phi", 1);
inpChain->SetBranchStatus("vbf_pt", 1);
inpChain->SetBranchStatus("year", 1);
inpChain->SetBranchStatus("zeppHad", 1);
inpChain->SetBranchStatus("zeppLep", 1);
}
//=======================================
#endif
