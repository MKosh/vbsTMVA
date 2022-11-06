#ifndef vbsTMVA_hpp
#define vbsTMVA_hpp
////////////////////////////////////////////////////////////////////////
// $Id: vbsTMVA.hpp
//
// File:    vbsTMVA.hpp
// Purpose: H->ZZ->4l analysis interface to TMVA
// (works with VBS4LeptonsAnalysisReduced trees)
// Created: Nov 2017, Sergey Uzunyan (serguei@nicadd.niu.edu)
////////////////////////////////////////////////////////////////////////
#include <unistd.h> //
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iomanip>

#include "RtypesCore.h"
#include "TChain.h"
#include "TROOT.h"
#include "TEventList.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TTree.h"

#include "vbsDL.hpp"

//
//
using namespace std;
//luminosity
const Float_t lum = 35867.06;
const Float_t lum_2016 = 35867.06; //pb-1
const Float_t lum_2017 = 41530.0; //pb-1
const Float_t lum_2018 = 59740.0; //pb-1
const Float_t lum_run2 = 13710.0; //pb^-1
//
//Background groups
#define  gid_sgl      1
#define  gid_bkg      2
#define  gid_data     3
//
#define  gid_ewkWV    11
#define  gid_Diboson  12
#define  gid_Wjets    13
#define  gid_Zjets    14
#define  gid_top      15

TCut cut_sgl              ("cut_sgl",                 "classID==0");
TCut cut_bkg              ("cut_bkg",                 "classID==1");
TCut cut_data             ("cut_data",                "classID==3");

TCut cut_ewkWV            ("cut_ewkWV",               "(gid ==  11)");
TCut cut_DiBosons         ("cut_DiBosons",            "(gid ==  12)");
TCut cut_Wjets            ("cut_Wjets",               "(gid ==  13)");
TCut cut_Zjets            ("cut_Zjets",               "(gid ==  14)");
TCut cut_TT               ("cut_TT",                  "(gid ==  15)");

//Cuts
//from MyControlPlots.C
TCut cleanNAN             ("cleanNAN",                "(mass_lvj_type0_PuppiAK8>0)"); // Use this NAN cut for the old data
TCut mVVgt0               ("mVVgt0",                  "(mass_lvj_type0_PuppiAK8>0)");
TCut oneLepton            ("oneLepton",               "(lep2_pt<0)");
TCut Lpt1gt50             ("Lpt1gt50",                "(lep1_pt>50)");
TCut goodEleta            ("goodEleta",               "(type==1)&&!(abs(l_eta1)>1.4442 && abs(l_eta1)<1.566)");
TCut badEleta             ("badEleta",                "(type==1)&&!(abs(l_eta1)>1.4442 && abs(l_eta1)<1.566)");
TCut etaMu2p4             ("etaMu2p4",                "((type==0)&&(abs(l_eta1)<2.4))");
TCut etaEl2p5             ("etaEl2p5",                "((type==1)&&((abs(l_eta1)<2.5)&&!(abs(l_eta1)>1.4442 && abs(l_eta1)<1.566)))");
TCut goodLepton           ("goodLepton",              Lpt1gt50+( etaMu2p4|| etaEl2p5) );
TCut goodMu               ("goodMu",                  "(l_pt1>50&&(type==0)&&(abs(l_eta1)<2.4))");
TCut goodEl               ("goodEl",                  "(l_pt1>50&&(type==1)&&((abs(l_eta1)<2.5)&&!(abs(l_eta1)>1.4442 && abs(l_eta1)<1.566)))");

// Mark cuts --------------------------------------------------------------------------------------------------------------------------------
TCut year_2016            ("year_2016",               "(year==2016)");
TCut year_2017            ("year_2017",               "(year==2017)");
TCut year_2018            ("year_2018",               "(year==2018)");
// WV Signal Region (a.k.a boosted WV channel)
// regions, sr: signal region, cr: control region
TCut cleanNAN_tau         ("cleanNAN_tau",            "!(TMath::IsNaN(bos_PuppiAK8_tau2tau1))"); // Use this one for the new data
TCut tau21_cut            ("tau21_cut",               "(bos_PuppiAK8_tau2tau1 >= 0.0 && bos_PuppiAK8_tau2tau1 <= 1.0)");
TCut cleanNAN_qgid        ("cleanNAN_qgid",           "!(TMath::IsNaN(vbf1_AK4_qgid))&&!(TMath::IsNaN(vbf2_AK4_qgid))");
TCut qgid_cut             ("qgid_cut",                "(vbf1_AK4_qgid >= 0.0 && vbf1_AK4_qgid <= 1.0)&&(vbf2_AK4_qgid >= 0.0 && vbf2_AK4_qgid <= 1.0)");


TCut wv_boosted           ("wv_boosted",              "lep2_pt<0 && bos_PuppiAK8_pt>0");
TCut wv_resolved          ("wv_resolved",             "lep2_pt<0 && bos_AK4AK4_pt>0");
TCut zv_boosted           ("zv_boosted",              "lep2_pt>0 && bos_PuppiAK8_pt>0");
TCut zv_resolved          ("zv_resolved",             "lep2_pt>0 && bos_AK4AK4_pt>0");
TCut region               ("region",                  wv_boosted);

TCut lep_pt               ("lep_pt",                  "lep1_pt>25"); // can be different value, debatable // lepton eta cleaning, different for muon and electron, (if muon) || (if ele)
TCut lep_eta              ("lep_eta",                 "(lep1_m > 0.105 && fabs(lep1_eta) < 2.4 ) || (lep1_m < 0.105 && fabs(lep1_eta) < 2.5 && !(fabs(lep1_eta) > 1.4442 && fabs(lep1_eta) < 1.566))"); // && fabs(lep2_eta) < 2.4
TCut lep_ele              ("lep_ele",                 "(lep1_m < 0.105 && fabs(lep1_eta) < 2.5 && !(fabs(lep1_eta) > 1.4442 && fabs(lep1_eta) < 1.566))");
TCut lep_muon             ("lep_muon",                "(lep1_m > 0.105 && fabs(lep1_eta) < 2.4)"); // && fabs(lep2_eta) < 2.4

TCut wv_boosted_lep       ("wv_boosted_lep",          wv_boosted+lep_eta);
TCut wv_boosted_ele       ("wv_boosted_ele",          wv_boosted+lep_ele);
TCut wv_boosted_muon      ("wv_boosted_muon",         wv_boosted+lep_muon);
TCut wv_resolved_lep      ("wv_resolved_lep",         wv_resolved+lep_eta);
TCut wv_resolved_ele      ("wv_resolved_ele",         wv_resolved+lep_ele);
TCut wv_resolved_muon     ("wv_resolved_muon",        wv_resolved+lep_muon);
TCut zv_boosted_lep       ("zv_boosted_lep",          zv_boosted+lep_eta);
TCut zv_boosted_ele       ("zv_boosted_ele",          zv_boosted+lep_ele);
TCut zv_boosted_muon      ("zv_boosted_muon",         zv_boosted+lep_muon);
TCut zv_resolved_lep      ("zv_resolved_lep",         zv_resolved+lep_eta);
TCut zv_resolved_ele      ("zv_resolved_ele",         zv_resolved+lep_ele);
TCut zv_resolved_muon     ("zv_resolved_muon",        zv_resolved+lep_muon);
TCut category_selection   ("category_selection",      wv_boosted_lep);

TCut fatjet_pt            ("fatjet_pt",               "bos_PuppiAK8_pt>200");
TCut fatjet_eta           ("fatjet_eta",              "TMath::Abs(bos_PuppiAK8_eta)<2.4");
TCut fatjet_tau21         ("fatjet_tau21",            "TMath::Abs(bos_PuppiAK8_tau2tau1)<0.55"); // can be different// vbs vbf are used interchangeably TCut fatjet_tau21 ("fatjet_tau21",  "bos_PuppiAK8_tau2tau1<0.55");

TCut vbs_jets_mjj         ("vbs_jets_mjj",            "vbf_m>500");
TCut vbs_jets_pt          ("vbs_jets_pt",             "vbf1_AK4_pt>50 && vbf2_AK4_pt>50");
TCut vbs_delta_eta        ("vbs_delta_eta",           "vbf_deta>2.5"); // this is absolute delta eta

TCut met_pt               ("met_pt",                  "MET>30");
TCut btag_veto            ("btag_veto",               "nBtag_loose==0");

// The unique conditions for each SR/CR
TCut wv_sr                ("wv_sr",                   "(bos_PuppiAK8_m_sd0_corr>65 && bos_PuppiAK8_m_sd0_corr<105)");
TCut wv_cr_wjets          ("wv_cr_wjets",             "(bos_PuppiAK8_m_sd0_corr>50 && bos_PuppiAK8_m_sd0_corr<65) || (bos_PuppiAK8_m_sd0_corr>105 && bos_PuppiAK8_m_sd0_corr<150) && nBtag_loose==0");
TCut wv_cr_top            ("wv_cr_top",               "nBtag_loose>0");
TCut btag_weight          ("btag_weight",             "btagWeight_loose");

// Extra cuts
TCut dummy                ("dummy",                   "");
TCut ZeppWLlt3            ("ZeppWLlt3",               "(TMath::Abs(zeppLep)/vbf_deta)<0.3");
TCut ZeppWHLlt3           ("ZeppWHlt3",               "(TMath::Abs(zeppHad)/vbf_deta)<0.3");
TCut ZeppWLlt1            ("ZeppWLlt1",               "(TMath::Abs(zeppLep)/vbf_deta)<1.0");
TCut ZeppWHLlt1           ("ZeppWHlt1",               "(TMath::Abs(zeppHad)/vbf_deta)<1.0");
TCut noData               ("noData",                  "!(gid==3)");

// Common cuts between the different SR/CR
TCut iso_cut              ("iso_cut",                 "(AntiIsoInt==0)&&(bosCent>0.0)");
TCut vbs_jets             ("vbs_jets",                vbs_jets_mjj+vbs_jets_pt+vbs_delta_eta);
TCut bos_common           ("bos_common",              fatjet_pt+fatjet_eta+fatjet_tau21);
TCut zepp_cut             ("zepp_cut",                ZeppWLlt1+ZeppWHLlt1);
TCut common               ("common",                  iso_cut+zepp_cut+lep_pt+bos_common+vbs_jets+met_pt);
TCut full_common          ("full_common",             common+lep_eta+region);
TCut common_ele           ("common_ele",              common+lep_ele+region);
TCut common_muon          ("common_muon",             common+lep_muon+region);

// Resolved category
TCut resolved_jet_pt      ("resoved_jet_pt",          "bos_j1_AK4_pt > 30.0 && bos_j2_AK4_pt > 30.0");
TCut resolved_common      ("resolved_common",         iso_cut+vbs_jets+met_pt+zepp_cut+lep_pt+lep_eta+resolved_jet_pt+wv_resolved);
TCut wv_resolved_sr       ("wv_resolved_sr",          "bos_AK4AK4_m > 65.0 && bos_AK4AK4_m < 105");
TCut wv_resolved_wcr      ("wv_resolved_wcr",         "(bos_AK4AK4_m > 50 && bos_AK4AK4_m < 65) || (bos_AK4AK4_m > 105 && bos_AK4AK4_m < 150)");
TCut wv_resolved_tcr      ("wv_resolved_tcr",         "nBtag_loose > 0");

TCut full_resolved_sr     ("full_resolved_sr",        resolved_common+btag_veto+wv_resolved_sr);
TCut full_resolved_wcr    ("full_resolved_wcr",       resolved_common+btag_veto+wv_resolved_wcr);
TCut full_resolved_tcr    ("full_resolved_tcr",       resolved_common+wv_resolved_tcr+wv_resolved_sr);
TCut resolved_bdt_cut     ("resolved_bdt_cut",        "BDT2>0.100");
TCut resolved_dnn_cut     ("resolved_dnn_cut",        "DNN_GPU1>0.068");

// Full set of cuts for each SR/CR selecting both electrons and muons
TCut full_wjets_cr        ("full_wjets_cr",           full_common+btag_veto+wv_cr_wjets);
TCut full_top_cr          ("full_top_cr",             full_common+wv_cr_top+wv_sr);
TCut full_wv_sr           ("full_wv_sr",              full_common+btag_veto+wv_sr);//+noData);
TCut boosted_bdt_cut      ("boosted_bdt_cut",         "BDT4>0.539");
TCut boosted_dnn_cut      ("boosted_dnn_cut",         "DNN_GPU1>0.111");

TCut BDT_cut_2016_wv      ("BDT_cut_2016_wv",         "BDT>0.313"); //
TCut BDT_cut_2016_sr      ("BDT_cut_2016_sr",         "BDT>0.038"); // was 0.046
TCut DNN_GPU_cut_2016_wv  ("DNN_GPU_cut_2016_wv",     "DNN_GPU>0.071"); // 
TCut DNN_GPU_cut_2016_sr  ("DNN_GPU_cut_2016_sr",     "DNN_GPU>0.098"); // was 0.084

TCut BDT_cut_2017_wv      ("BDT_cut_2017_wv",         "BDT>0.292");
TCut BDT_cut_2017_sr      ("BDT_cut_2017_sr",         "BDT>0.118"); // was 0.102
TCut DNN_GPU_cut_2017_wv  ("DNN_GPU_cut_2017_wv",     "DNN_GPU>0.066");
TCut DNN_GPU_cut_2017_sr  ("DNN_GPU_cut_2017_sr",     "DNN_GPU>0.112"); // was 0.122


TCut BDT_cut_2018_wv      ("BDT_cut_2018_wv",         "BDT>0.316");
TCut BDT_cut_2018_sr      ("BDT_cut_2018_sr",         "BDT>0.098"); // was 0.084
TCut DNN_GPU_cut_2018_wv  ("DNN_GPU_cut_2018_wv",     "DNN_GPU>0.09");
TCut DNN_GPU_cut_2018_sr  ("DNN_GPU_cut_2018_sr",     "DNN_GPU>0.103"); // was 0.078

// use these
TCut BDT_cut_Run2_wv      ("BDT_cut_Run2_wv",         "BDT>0.344");
TCut BDT_cut_Run2_sr      ("BDT_cut_Run2_sr",         "BDT>0.118"); // was 0.104
TCut DNN_GPU_cut_Run2_wv  ("DNN_GPU_cut_Run2_wv",     "DNN_GPU>0.060");
TCut DNN_GPU_cut_Run2_sr  ("DNN_GPU_cut_Run2_sr",     "DNN_GPU>0.092"); // was 0.125
// use these


// Full SR/CR cuts specifying one type of lepton
TCut wjets_cr_ele         ("wjets_cr_ele",            common_ele+btag_veto+wv_cr_wjets);
TCut wjets_cr_muon        ("wjets_cr_muon",           common_muon+btag_veto+wv_cr_wjets);
TCut top_cr_ele           ("top_cr_ele",              common_ele+wv_cr_top+wv_sr);
TCut top_cr_muon          ("top_cr_muon",             common_muon+wv_cr_top+wv_sr);
TCut wv_sr_ele            ("wv_sr_ele",               common_ele+btag_veto+wv_sr);
TCut wv_sr_muon           ("wv_sr_muon",              common_muon+btag_veto+wv_sr);

TCut wtot_2016            ("wtot_2016",               "35867.06*genWeight*mcWeight*L1PFWeight*puWeight"); //"35867.06*genWeight*mcWeight*L1PFWeight*puWeight"
TCut wtot_2017            ("wtot_2017",               "41530*genWeight*mcWeight*L1PFWeight*puWeight"); // 41530
TCut wtot_2018            ("wtot_2018",               "59740*genWeight*mcWeight*L1PFWeight*puWeight"); // 59740
TCut allCuts              ("allCuts",                 (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));
TCut norm_btag            ("norm_btag",               "((year==2016)*(lumin*mcWeight*genWeight*L1PFWeight*puWeight*btagWeight_loose*lep1_idEffWeight*lep1_trigEffWeight))+((year==2017)*(lumin*mcWeight*genWeight*L1PFWeight*puWeight*btagWeight_loose*lep1_idEffWeight*lep1_trigEffWeight))+((year==2018)*(lumin*mcWeight*genWeight*puWeight*btagWeight_loose*lep1_idEffWeight*lep1_trigEffWeight))");
TCut norm_hist 	          ("norm_hist",               "((year==2016)*(lumin*mcWeight*genWeight*L1PFWeight*puWeight*lep1_idEffWeight*lep1_trigEffWeight))+((year==2017)*(lumin*mcWeight*genWeight*L1PFWeight*puWeight*lep1_idEffWeight*lep1_trigEffWeight))+((year==2018)*(lumin*mcWeight*genWeight*puWeight*L1PFWeight*lep1_idEffWeight*lep1_trigEffWeight))");
//TCut boosted_scale_hist   ("boosted_scale_hist",      "((((year==2016)&&(gid==13))*(1.378))+(((year==2016)&&(gid==15))*(0.895))+(((year==2016)&&(gid!=13)&&(gid!=15))*1.)) + ((((year==2017)&&(gid==13))*(1.213))+(((year==2017)&&(gid==15))*(1.036))+(((year==2017)&&(gid!=13)&&(gid!=15))*1.)) + ((((year==2018)&&(gid==13))*(0.631))+(((year==2018)&&(gid==15))*(0.697))+(((year==2018)&&(gid!=13)&&(gid!=15))*1.))");
TCut boosted_scale_hist   ("boosted_scale_hist",      "((((year==2016)&&(gid==13))*(1.400))+(((year==2016)&&(gid==15))*(0.901))+(((year==2016)&&(gid!=13)&&(gid!=15))*1.)) + ((((year==2017)&&(gid==13))*(1.264))+(((year==2017)&&(gid==15))*(1.040))+(((year==2017)&&(gid!=13)&&(gid!=15))*1.)) + ((((year==2018)&&(gid==13))*(0.576))+(((year==2018)&&(gid==15))*(0.689))+(((year==2018)&&(gid!=13)&&(gid!=15))*1.))");
TCut resolved_scale_hist	("resolved_scale_hist",     "((((year==2016)&&(gid==13))*(1.940))+(((year==2016)&&(gid==15))*(1.089))+(((year==2016)&&(gid!=13)&&(gid!=15))*1.)) + ((((year==2017)&&(gid==13))*(1.960))+(((year==2017)&&(gid==15))*(1.354))+(((year==2017)&&(gid!=13)&&(gid!=15))*1.)) + ((((year==2018)&&(gid==13))*(1.029))+(((year==2018)&&(gid==15))*(0.884))+(((year==2018)&&(gid!=13)&&(gid!=15))*1.))");
TCut scale_hist               ("scale_hist",               boosted_scale_hist);

TCut training_cut   ("training_cut",      region);
//Cuts ---------------------------------------------------------------------------------------------------------------------------------


class Sample{
private:
  Int_t   _year;
  TString   _sname;
  TString   _gname;
  TString   _year_str;
  Float_t   _xsec;
  Float_t   _lumin;
  Int_t     _loadFlag;
  Int_t     _gid;
  Int_t     _sid;
  Int_t     _color;
  Int_t     _nMCgen;        // total generated events
  Int_t     _nMCgenNeg;     // negative generated events (strange VBS anl thing)
  //
  TTree*    _inpTree;          // total good events for scale calculation
  //Int_t     _ngen;          // total good events for scale calculation
  Float_t   _ngen;
  Int_t     _nevents;       // events in tree
  TString   _reqlist;       // reqlist name
  Float_t   _sweight;       // _xsec/_ngen

public:

  Sample(Int_t year, Float_t lumin, const char* gname, const char* sname, Float_t xsec, Int_t loadFlag, Int_t gid, Int_t sid, Int_t color, Float_t  nMCgen,  Float_t nMCgenNeg ){
    _lumin = lumin;
    _year=year;
    TString year_str = std::to_string(_year);
    _year_str = year_str;

    _sname=sname;
    _gname=gname;

    if(gid == gid_data){
      _reqlist="reqlists/rqs_"+year_str+"--"+_gname+"--"+_sname+"_data.lst";
    }else if (gid >9) {
      _reqlist="reqlists/rqs_"+year_str+"--"+_gname+"--"+_sname+"_bkg.lst";
    }else{
      _reqlist="reqlists/rqs_"+year_str+"--"+_gname+"--"+_sname+"_sgl.lst";
    }
    _loadFlag  = loadFlag;
    _xsec      = xsec;
    _gid       = gid;
    _sid       = sid;
    _color     = color;
    _nMCgen    = nMCgen;
    _nMCgenNeg = nMCgenNeg;
    _ngen      = nMCgen - 2* nMCgenNeg;
    _nevents   = 0;
    _inpTree   = NULL;
  };

  Float_t   getLumin(){return _lumin; };
  TString   getSName(){return _sname;  };
  TString   getGName(){return _gname;  };
  TString   getReqList(){return _reqlist;};
  Float_t   getNgen(){return _ngen;};
  Int_t     getXsec(){return _xsec;};
  Int_t     getGid(){return _gid;};
  Int_t     getSid(){return _sid;};
  Int_t     getScolor(){return _color;};
  Int_t     getLoadFlag(){return _loadFlag; };
  Float_t   getWeight(){return _sweight; };
  Int_t   getYear(){return _year; };
  TString getYearString(){return _year_str; };

  void      setInpTree(TTree* inpTree){
     _inpTree = inpTree;
     if (_inpTree){
      _nevents = _inpTree->GetEntries();
      _sweight = _xsec/_ngen;
     }
  };

  TTree*    getInpTree(){ return _inpTree; };
  Int_t     getNevents(){ return _nevents; };
  
  void      Print(){
    std::cout << "Sample:: Group/Name/LoadFlag/gid/sid/color/xsec/ngen/sweight = " <<
      _gname << "/" << _sname  << "/" <<
      _loadFlag << "/" <<
      _gid  << "/" <<
      _sid  << "/" <<
      _color << "/" <<
      _xsec << "/" <<
      _ngen << "/" <<
      _sweight << "/" <<
    endl;
  };
};


//Input skim set
//rqs_data.txt  rqs_gg2zz_bkg.lst  rqs_qcd_bkg.lst  rqs_signal.lst  rqs_tt_bkg.lst  rqs_wx_bkg.lst  rqs_ZZother_bkg.lst
//
typedef struct {
  Float_t pt;
  Float_t eta;
  Float_t phi;
  Float_t charge;
  Float_t pfx;
  Float_t sip;
  Int_t   pdgid;
} VbsLepton;


//Local functions

//======================================================================================================================
//
void fillBranch(TTree* groupTree,VbsReducedEvent& vbsEvent, Int_t groupID,  const char* groupName);

void fillBranch(TTree* groupTree, VbsReducedEvent& vbsEvent, Sample* sample);

void arrange_vbsReducedTree(TTree* vbsTree, VbsReducedEvent& vbsEvent); //map of  VBS4LeptonsAnalysisReduced branches to the local structure
//void   setChainBranches (TChain* inpChain);
TTree* chain2tree(TString inpChainName="VBS4LeptonsAnalysisReduced",
                  TString reqlist="reqlists/rqs_data.txt", TString combinedTreeName="", TString combinedTreeTitle="");

void setVbsDLorReaderVarsAndSpectators(TMVA::DataLoader* dataloader, TMVA::Reader* datareader, VbsReducedEvent& vbsEvent);

TChain* getChain(TString treeName, TString filelist); //creates chain from list of files

void getStat(TTree* tree, const char* var, TCut& cut, Stat_t stats[4]);  //number of normalized events

void convertTrees(const char* treeName, const char* filelist);

TString getDateString();

TString getTimeString();
//void fixVbsTree( TTree* vbsTree, const char* fname);

//======================================================================================================================
//
TObjArray* GetListOfBranches(TTree* tree){
  TObjArray* brlist = (TObjArray*) tree->GetListOfBranches()->Clone();
    brlist->SetOwner(kFALSE);
    brlist->Sort();

  for( Int_t nb = 0; nb < brlist->GetEntries(); nb++){
    TBranch* br = (TBranch*)  brlist->At(nb);

    //We assume only one leaf of the same name in a branch; else use
    // TObjArray* br_leaves = br->GetListOfLeaves();
    TLeaf* leaf = br->GetLeaf(br->GetName());
    //  cout << leaf->GetName() << "/" << leaf->GetTypeName() << endl;
  }
    return brlist;
}

//======================================================================================================================
//
TString getDateString() {
  time_t now = time(0);
  struct tm* timeStruct = localtime(&now);
  std::stringstream date;
  date << std::to_string(timeStruct->tm_mon+1) << "-" << std::to_string(timeStruct->tm_mday) 
      << "-" << std::to_string(timeStruct->tm_year+1900);

  return date.str().c_str();
}

//======================================================================================================================
//
TString getTimeString() {
  time_t now = time(0);
  struct tm* timeStruct = localtime(&now);
  std::stringstream time_str;
  time_str << std::to_string(timeStruct->tm_hour) << "-" << std::to_string(timeStruct->tm_min); 

  return time_str.str().c_str();
}

//======================================================================================================================
//
TString getTimeAndDateString() {
  time_t now = time(0);
  struct tm* timeStruct = localtime(&now);
  std::stringstream time_and_date;
  time_and_date << std::to_string(timeStruct->tm_mon+1) << "-" << std::to_string(timeStruct->tm_mday) 
      << "-" << std::to_string(timeStruct->tm_year+1900) << " " << std::to_string(timeStruct->tm_hour) << ":" << std::to_string(timeStruct->tm_min);

  return time_and_date.str().c_str();
}

//======================================================================================================================
//
void writeAUCFile (TString myMethodList, TMVA::DataLoader* dataloader, TMVA::Factory* factory) {
  stringstream ss_AUC_outfile;
    ss_AUC_outfile << "ROC/" << "Run2_wv_SR_threeBDTs.txt"; // AUCoutfile
  std::ofstream AUC_outfile;
  AUC_outfile.open(ss_AUC_outfile.str(), std::ios_base::app);
  std::vector<TString> mlist = TMVA::gTools().SplitString(myMethodList, ',');
  TString time_and_date = getTimeAndDateString();

  AUC_outfile << "" << std::endl;
  AUC_outfile << "--------------------------------------------------" << std::endl;
  AUC_outfile << time_and_date << std::endl;
   for (UInt_t i=0; i<mlist.size(); i++) {
      std::string reg_method(mlist[i]);
      AUC_outfile << "AUC for " << reg_method << ":\t" << factory->GetROCIntegral(dataloader, reg_method) << std::endl;
   }
   AUC_outfile << "--------------------------------------------------" << std::endl;
   AUC_outfile.close();
   std::cout << "ROC file written" << std::endl;
}

//======================================================================================================================
//
void SelectVbsVars(vector<string>& vbsVars, TObjArray* brlist){
  string  var_sig = "f_";
  for(int i = 0; i < brlist->GetEntries(); ++i) {
    string brname = brlist->At(i)->GetName();
    if( brname.find(var_sig) != std::string::npos ){
      vbsVars.push_back(brname);
    }
  }
}

//======================================================================================================================
//
TTree* chain2tree(TString inpChainName, TString reqlist, TString combinedTreeName, TString combinedTreeTitle){
//accumulates signal samples in a single tree
  TChain* inpChain = getChain(inpChainName, reqlist);
  setChainBranches(inpChain);
  TTree* combinedTree(0);
  if(inpChain->GetEntries()){
    combinedTree = (TTree*)  inpChain->CloneTree();
    if(*combinedTreeTitle != '\0') combinedTree->SetTitle(combinedTreeTitle);
    if(*combinedTreeName  != '\0') combinedTree->SetName(combinedTreeName);
    delete inpChain;
  }
  cout << "Exit chain2tree " << combinedTree << endl;
  return combinedTree;
}

//======================================================================================================================
//place holder to use a cut with clone
TTree* chain2tree(TString inpChainName,TCut cut, TString reqlist, TString combinedTreeName, TString combinedTreeTitle){
//
  TChain* inpChain = getChain(inpChainName, reqlist);
  setChainBranches(inpChain);
  TTree* combinedTree(0);
  if(inpChain->GetEntries()){
    combinedTree = (TTree*)  inpChain->CloneTree();
    if(*combinedTreeTitle != '\0') combinedTree->SetTitle(combinedTreeTitle);
    if(*combinedTreeName  != '\0') combinedTree->SetName(combinedTreeName);
    delete inpChain;
  }
  cout << "Exit chain2tree " << combinedTree << endl;
  return combinedTree;
}

//======================================================================================================================
//
TString getFileNames(Sample* data_sample) {
  TString reqlist = data_sample->getReqList();
  ifstream f(reqlist);
  std::vector<TString> file_names;
  std::cout << "Processing filelist " << reqlist << std::endl;

  if (!f.is_open()) {
    std::cout << "getFileName: File not found: " << reqlist << std::endl;
    exit(0);
  }

  char fname[255] = "0";
  Int_t len = sizeof(fname);
  TString temp;
  while (f.getline(fname,len)) {
    if (strlen(fname) == 0) continue;
    temp = fname;
  }
  return temp;
}

//======================================================================================================================
//
TTree* cutTree(TTree* bigTree,TCut& cut){
  TEventList* elist = (TEventList*)gROOT->FindObject("elist");
  if(elist){
    delete elist;
  }
  //
  bigTree->Draw(">>elist",cut);
  elist = (TEventList*) gDirectory->Get("elist");
  bigTree->SetEventList(elist);
 //
  TTree* smallTree= bigTree->CopyTree("");
//  cout << "treeCut:: nevtOrig/nevtCut = " <<
//           bigTree->GetEntries() << "/" <<
//           smallTree->GetEntries() <<
//           " , TCut = " <<
//           cut <<

//  endl;
// bigTree->SetEventList(0);
  return smallTree;
}

//======================================================================================================================
//
TTree* getTree(TString treeName, TString fname) {
//get TTree treeName from file  fname
  TDirectory* dir = gDirectory;       // current dir
  TFile* f = gROOT->GetFile(fname);
  if (!f) f = new TFile(fname);
  else    f->cd();
  if (!f) {
    cout<< "Error:: input file not found: " << fname <<endl;
    return 0;
  }
  TTree* ftree  = (TTree*) gDirectory->Get(treeName);
  cout<< "Total entries " <<  std::setw(32)  << fname << " is " << ftree->GetEntries() <<endl;
  dir->cd();     // back to starting dir
  return ftree;
}

//======================================================================================================================
//
void convertTrees(const char* treeName, const char* filelist) {
//to modify a tree and withe it into a new file
//
  ifstream f(filelist);
  if (!f.is_open()) {
    cout<< "convertTrees: File not found: " << filelist <<endl;
  }else{
    char fname[255]="0";
    Int_t len = sizeof(fname);
    while (f.getline(fname,len)) {
      if (strlen(fname) == 0 || fname[0] == '#') continue;
      TTree* current_tree = getTree(treeName,fname);
	//  fixVbsTree(current_tree,fname);
      cout<< "File/tree "  <<  fname << "/" <<  treeName << " , total events: " << current_tree->GetEntries() <<endl;
    }
  }
}

//======================================================================================================================
//
TChain* getChain(TString treeName, TString filelist) {
//creates chain for a tree in filelist
  TChain* chain = new TChain(treeName);
  ifstream f(filelist);
  cout << "Processing filelist " << filelist <<endl;
  if (!f.is_open()) {
    cout<< "getChain: File not found: " << filelist <<endl;
    exit(0);
  }
  char fname[255]="0";
  Int_t len = sizeof(fname);
  while (f.getline(fname,len)) {
    if (strlen(fname) == 0 || fname[0] == '#') continue;
      std::cout << "fname = " << fname << std::endl;
      Int_t n = chain->Add(fname, -1);  // second parameter to ensure file exists
      if (n == 0) {
        cout<< "getChain:ERROR:: while processing filelist " << filelist << ". File not found: " << fname <<endl;
        return 0;
      }
    }
  cout<< "getChain: Tree "  << treeName << " , total events: " << chain->GetEntries() <<endl;
  return chain;
}

//======================================================================================================================
//
void getStat(TTree* tree, const char* var, TCut& cut, Stat_t stats[4]){
  TH1::StatOverflows(kTRUE);
  //Stat_t stats[4]={0};
  tree->Draw(var,cut);
  TH1F* hstat = (TH1F*)gROOT->FindObject("hstat");
  if(hstat) hstat->Delete();
  hstat= (TH1F*)tree->GetHistogram()->Clone("hstat");
  hstat->GetStats(stats);
  cout << "Nevents = " << stats[0] << " +/- " <<  stats[1] << endl;
  //
}

//======================================================================================================================
//
Int_t getVbsReqStat(const char* filelist) {
//creates chain for a tree in filelist
  ifstream f(filelist);
  if (!f.is_open()) {
    cout<< "getVbsReqStat:Input filelist " << filelist  << " not found: " <<endl;
    return 0;
  }
  char filename[255]="0";
  Int_t len = sizeof(filename);
  TFile* inpfile;
  Stat_t stats[4];
  Int_t nInitReqEvt= 0;
  Float_t nInitReqEvt_w = 0.0;
  Float_t nNtpReqEvt = 0.0;
  Float_t nNtpReqEvt_w2 = 0.0;
  while (f.getline(filename,len)) {
    if (strlen(filename) == 0 || filename[0] == '#') continue;

    inpfile = TFile::Open(filename);
    if (inpfile){
      TH1F* cutflow_w = (TH1F*) gROOT->FindObject("nEvent_4l_w");
      TH1F* cutflow   = (TH1F*) gROOT->FindObject("nEvent_4l");
      TTree* mtree  = (TTree*) gROOT->FindObject("VBS4LeptonsAnalysisReduced");
	    nInitReqEvt_w+=cutflow_w->GetBinContent(1);
	    nInitReqEvt  +=cutflow->GetBinContent(1);
	    getStat(mtree,"f_mass4l",norm_hist,stats);
      nNtpReqEvt    += stats[0];
	    nNtpReqEvt_w2 += stats[1]*stats[1];
    }else{
      cout<< "getVbsReqStat:ERROR:: while processing filelist " << filelist << ". File not found: " << filename <<endl;
    }
  }
  cout<< "getVbsReqStat: reqlist "  <<  filelist << " , nevt_gen/nevt_gen_w: " << nInitReqEvt << "/" << nInitReqEvt_w <<endl;
  cout<< "getVbsReqStat: reqlist "  <<  filelist << " , nevt_ntp = : " <<  nNtpReqEvt << "+-" << sqrt(nNtpReqEvt_w2) <<endl;
  return nInitReqEvt;
}

//======================================================================================================================
//
void fillBranch(TTree* groupTree, VbsReducedEvent& vbsEvent, Sample* sample){
  addBranches_vbsReducedTree(groupTree,vbsEvent);
  arrange_vbsReducedTree(groupTree,vbsEvent);

  TBranch* bGroupID  = groupTree->GetBranch("gid");
  TBranch* bSampleID = groupTree->GetBranch("sid");
  TBranch* bMCweight = groupTree->GetBranch("mcWeight");
  TBranch* bYear     = groupTree->GetBranch("year");
  TBranch* bYearf    = groupTree->GetBranch("yearf");
  TBranch* bLumin    = groupTree->GetBranch("lumin");

  vbsEvent.gid = sample->getGid();
  vbsEvent.sid = sample->getSid();
  vbsEvent.mcWeight = sample->getWeight();
  vbsEvent.year = sample->getYear();
  vbsEvent.yearf = Float_t(sample->getYear());
  vbsEvent.lumin = sample->getLumin();

  for (Long64_t ievt=0; ievt < groupTree->GetEntries(); ievt++) {
	  groupTree->GetEntry(ievt);
    bGroupID->Fill();
    bSampleID->Fill();
    bMCweight->Fill();
    bYear->Fill();
    bYearf->Fill();
    bLumin->Fill();
 	}

}
//================================================

#endif
