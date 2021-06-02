#ifndef vbsDL_hpp
#define vbsDL_hpp
//
//Note::Autogenerated with writeDL.sh on Tue Jun  1 17:24:07 EDT 2021
//Please check vbsDL*.hpp for available configurations.
//TMVA vars:
//vbf2_AK4_pt vbf1_AK4_pt zeppLep vbf_m lep1_eta vbf_pt vbf2_AK4_eta dibos_pt bos_PuppiAK8_tau2tau1 vbf_deta
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

//TMVA spectator 
if(dataloader) dataloader->AddSpectator("L1PFWeight",    "L1PFWeight",   "",      'F');
if(datareader) datareader->AddSpectator("L1PFWeight",    &vbsEvent.L1PFWeight        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("MET_phi",    "MET_phi",   "",      'F');
if(datareader) datareader->AddSpectator("MET_phi",    &vbsEvent.MET_phi        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("bos_PuppiAK8_eta",    "bos_PuppiAK8_eta",   "",      'F');
if(datareader) datareader->AddSpectator("bos_PuppiAK8_eta",    &vbsEvent.bos_PuppiAK8_eta        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("bos_PuppiAK8_m_sd0",    "bos_PuppiAK8_m_sd0",   "",      'F');
if(datareader) datareader->AddSpectator("bos_PuppiAK8_m_sd0",    &vbsEvent.bos_PuppiAK8_m_sd0        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("bos_PuppiAK8_phi",    "bos_PuppiAK8_phi",   "",      'F');
if(datareader) datareader->AddSpectator("bos_PuppiAK8_phi",    &vbsEvent.bos_PuppiAK8_phi        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("bos_PuppiAK8_pt",    "bos_PuppiAK8_pt",   "",      'F');
if(datareader) datareader->AddSpectator("bos_PuppiAK8_pt",    &vbsEvent.bos_PuppiAK8_pt        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("bos_PuppiAK8_tau2tau1", "bos_PuppiAK8_tau2tau1", "", 'F');
if(datareader) datareader->AddVariable("bos_PuppiAK8_tau2tau1",    &vbsEvent.bos_PuppiAK8_tau2tau1        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("btagWeight_loose",    "btagWeight_loose",   "",      'F');
if(datareader) datareader->AddSpectator("btagWeight_loose",    &vbsEvent.btagWeight_loose        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("dibos_eta",    "dibos_eta",   "",      'F');
if(datareader) datareader->AddSpectator("dibos_eta",    &vbsEvent.dibos_eta        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("dibos_m",    "dibos_m",   "",      'F');
if(datareader) datareader->AddSpectator("dibos_m",    &vbsEvent.dibos_m        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("dibos_mt",    "dibos_mt",   "",      'F');
if(datareader) datareader->AddSpectator("dibos_mt",    &vbsEvent.dibos_mt        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("dibos_phi",    "dibos_phi",   "",      'F');
if(datareader) datareader->AddSpectator("dibos_phi",    &vbsEvent.dibos_phi        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("dibos_pt", "dibos_pt", "", 'F');
if(datareader) datareader->AddVariable("dibos_pt",    &vbsEvent.dibos_pt        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("dilep_eta",    "dilep_eta",   "",      'F');
if(datareader) datareader->AddSpectator("dilep_eta",    &vbsEvent.dilep_eta        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("dilep_m",    "dilep_m",   "",      'F');
if(datareader) datareader->AddSpectator("dilep_m",    &vbsEvent.dilep_m        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("dilep_mt",    "dilep_mt",   "",      'F');
if(datareader) datareader->AddSpectator("dilep_mt",    &vbsEvent.dilep_mt        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("dilep_phi",    "dilep_phi",   "",      'F');
if(datareader) datareader->AddSpectator("dilep_phi",    &vbsEvent.dilep_phi        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("dilep_pt",    "dilep_pt",   "",      'F');
if(datareader) datareader->AddSpectator("dilep_pt",    &vbsEvent.dilep_pt        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("evt",    "evt",   "",      'I');
if(datareader) datareader->AddSpectator("evt",    &vbsEvent.evt        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("genWeight",    "genWeight",   "",      'F');
if(datareader) datareader->AddSpectator("genWeight",    &vbsEvent.genWeight        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("gid",    "gid",   "",      'I');
if(datareader) datareader->AddSpectator("gid",    &vbsEvent.gid        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("lep1_eta", "lep1_eta", "", 'F');
if(datareader) datareader->AddVariable("lep1_eta",    &vbsEvent.lep1_eta        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("lep1_iso",    "lep1_iso",   "",      'F');
if(datareader) datareader->AddSpectator("lep1_iso",    &vbsEvent.lep1_iso        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("lep1_m",    "lep1_m",   "",      'F');
if(datareader) datareader->AddSpectator("lep1_m",    &vbsEvent.lep1_m        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("lep1_phi",    "lep1_phi",   "",      'F');
if(datareader) datareader->AddSpectator("lep1_phi",    &vbsEvent.lep1_phi        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("lep1_pt",    "lep1_pt",   "",      'F');
if(datareader) datareader->AddSpectator("lep1_pt",    &vbsEvent.lep1_pt        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("lep1_q",    "lep1_q",   "",      'F');
if(datareader) datareader->AddSpectator("lep1_q",    &vbsEvent.lep1_q        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("lep2_eta",    "lep2_eta",   "",      'F');
if(datareader) datareader->AddSpectator("lep2_eta",    &vbsEvent.lep2_eta        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("lep2_pt",    "lep2_pt",   "",      'F');
if(datareader) datareader->AddSpectator("lep2_pt",    &vbsEvent.lep2_pt        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("mcWeight",    "mcWeight",   "",      'F');
if(datareader) datareader->AddSpectator("mcWeight",    &vbsEvent.mcWeight        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("nBtag_loose",    "nBtag_loose",   "",      'I');
if(datareader) datareader->AddSpectator("nBtag_loose",    &vbsEvent.nBtag_loose        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("nBtag_medium",    "nBtag_medium",   "",      'I');
if(datareader) datareader->AddSpectator("nBtag_medium",    &vbsEvent.nBtag_medium        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("nPV",    "nPV",   "",      'F');
if(datareader) datareader->AddSpectator("nPV",    &vbsEvent.nPV        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("neu_pz_type0",    "neu_pz_type0",   "",      'F');
if(datareader) datareader->AddSpectator("neu_pz_type0",    &vbsEvent.neu_pz_type0        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("puWeight",    "puWeight",   "",      'F');
if(datareader) datareader->AddSpectator("puWeight",    &vbsEvent.puWeight        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("run",    "run",   "",      'I');
if(datareader) datareader->AddSpectator("run",    &vbsEvent.run        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("sid",    "sid",   "",      'I');
if(datareader) datareader->AddSpectator("sid",    &vbsEvent.sid        );
 
//TMVA spectator 
if(dataloader) dataloader->AddSpectator("vbf1_AK4_eta",    "vbf1_AK4_eta",   "",      'F');
if(datareader) datareader->AddSpectator("vbf1_AK4_eta",    &vbsEvent.vbf1_AK4_eta        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("vbf1_AK4_pt", "vbf1_AK4_pt", "", 'F');
if(datareader) datareader->AddVariable("vbf1_AK4_pt",    &vbsEvent.vbf1_AK4_pt        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("vbf2_AK4_eta", "vbf2_AK4_eta", "", 'F');
if(datareader) datareader->AddVariable("vbf2_AK4_eta",    &vbsEvent.vbf2_AK4_eta        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("vbf2_AK4_pt", "vbf2_AK4_pt", "", 'F');
if(datareader) datareader->AddVariable("vbf2_AK4_pt",    &vbsEvent.vbf2_AK4_pt        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("vbf_deta", "vbf_deta", "", 'F');
if(datareader) datareader->AddVariable("vbf_deta",    &vbsEvent.vbf_deta        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("vbf_m", "vbf_m", "", 'F');
if(datareader) datareader->AddVariable("vbf_m",    &vbsEvent.vbf_m        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("vbf_pt", "vbf_pt", "", 'F');
if(datareader) datareader->AddVariable("vbf_pt",    &vbsEvent.vbf_pt        );
 
//TMVA variable
if(dataloader) dataloader->AddVariable("zeppLep", "zeppLep", "", 'F');
if(datareader) datareader->AddVariable("zeppLep",    &vbsEvent.zeppLep        );
 
}
//=======================================
//========================================
void setChainBranches (TChain* inpChain){
//
   inpChain->SetBranchStatus("*", 0);   // disable all branches
// switch on required  branches
inpChain->SetBranchStatus("L1PFWeight", 1);
inpChain->SetBranchStatus("MET_phi", 1);
inpChain->SetBranchStatus("bos_PuppiAK8_eta", 1);
inpChain->SetBranchStatus("bos_PuppiAK8_m_sd0", 1);
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
inpChain->SetBranchStatus("lep1_eta", 1);
inpChain->SetBranchStatus("lep1_iso", 1);
inpChain->SetBranchStatus("lep1_m", 1);
inpChain->SetBranchStatus("lep1_phi", 1);
inpChain->SetBranchStatus("lep1_pt", 1);
inpChain->SetBranchStatus("lep1_q", 1);
inpChain->SetBranchStatus("lep2_eta", 1);
inpChain->SetBranchStatus("lep2_pt", 1);
inpChain->SetBranchStatus("mcWeight", 1);
inpChain->SetBranchStatus("nBtag_loose", 1);
inpChain->SetBranchStatus("nBtag_medium", 1);
inpChain->SetBranchStatus("nPV", 1);
inpChain->SetBranchStatus("neu_pz_type0", 1);
inpChain->SetBranchStatus("puWeight", 1);
inpChain->SetBranchStatus("run", 1);
inpChain->SetBranchStatus("sid", 1);
inpChain->SetBranchStatus("vbf1_AK4_eta", 1);
inpChain->SetBranchStatus("vbf1_AK4_pt", 1);
inpChain->SetBranchStatus("vbf2_AK4_eta", 1);
inpChain->SetBranchStatus("vbf2_AK4_pt", 1);
inpChain->SetBranchStatus("vbf_deta", 1);
inpChain->SetBranchStatus("vbf_m", 1);
inpChain->SetBranchStatus("vbf_pt", 1);
inpChain->SetBranchStatus("zeppLep", 1);
}
//=============================
#endif
