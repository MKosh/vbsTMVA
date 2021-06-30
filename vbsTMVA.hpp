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

#include "TROOT.h"
#include "TChain.h"
#include "TEventList.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#
#include "vbsDL.hpp" 
//
//
using namespace std;
//luminosity
const Float_t lum = 35867.06;
const Float_t lum_2016 = 35867.06; //pb-1
const Float_t lum_2017 = 41530.0; //pb-1
const Float_t lum_2018 = 59740.0; //pb-1
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

TCut cut_sgl         ("cut_sgl",        "classID==0");
TCut cut_bkg         ("cut_bkg",        "classID==1");
TCut cut_data        ("cut_data",       "classID==3");
 
TCut cut_ewkWV       ("cut_ewkWV",      "(gid ==  11)");
TCut cut_DiBosons    ("cut_DiBosons",   "(gid ==  12)");
TCut cut_Wjets       ("cut_Wjets",      "(gid ==  13)");
TCut cut_Zjets       ("cut_Zjets",      "(gid ==  14)");
TCut cut_TT          ("cut_TT",         "(gid ==  15)");

//Cuts
//from MyControlPlots.C
TCut cleanNAN       ("cleanNAN",        "(mass_lvj_type0_PuppiAK8>0)"); // Use this NAN cut for the old data
TCut cleanNAN_tau   ("cleanNAN_tau",    "!TMath::IsNaN(bos_PuppiAK8_tau2tau1)"); // Use this one for the new data
TCut mVVgt0         ("mVVgt0",          "(mass_lvj_type0_PuppiAK8>0)"); 
TCut oneLepton      ("oneLepton",       "(lep2_pt<0)"); 
TCut Lpt1gt50       ("Lpt1gt50",        "(lep1_pt>50)"); 
TCut goodEleta      ("goodEleta",       "(type==1)&&!(abs(l_eta1)>1.4442 && abs(l_eta1)<1.566)");
TCut badEleta       ("badEleta",        "(type==1)&&!(abs(l_eta1)>1.4442 && abs(l_eta1)<1.566)");
TCut etaMu2p4       ("etaMu2p4",        "((type==0)&&(abs(l_eta1)<2.4))");
TCut etaEl2p5       ("etaEl2p5",        "((type==1)&&((abs(l_eta1)<2.5)&&!(abs(l_eta1)>1.4442 && abs(l_eta1)<1.566)))");
TCut goodLepton     ("goodLepton",       Lpt1gt50+( etaMu2p4|| etaEl2p5) );
TCut goodMu         ("goodMu",          "(l_pt1>50&&(type==0)&&(abs(l_eta1)<2.4))");
TCut goodEl         ("goodEl",          "(l_pt1>50&&(type==1)&&((abs(l_eta1)<2.5)&&!(abs(l_eta1)>1.4442 && abs(l_eta1)<1.566)))");

// Mark cuts --------------------------------------------------------------------------------------------------------------------------------
// WV Signal Region (a.k.a boosted WV channel)
TCut category_selection ("category_selection",     "lep2_pt<0 && bos_PuppiAK8_pt>0");// can be different for muon or electron, see eta cut
//TCut category_selection ("category_selection",  "!isAntiIso && lep2_pt<0 && bos_PuppiAK8_pt>0")
TCut lep_pt             ("lep_pt",                 "lep1_pt>25"); // can be different value, debatable // lepton eta cleaning, different for muon and electron, (if muon) || (if ele)
//TCut lep_eta            ("lep_eta",                "(lep1_m>0.105 && TMath::Abs(lep1_eta)<2.4 && TMath::Abs(lep2_eta)<2.4) || (lep1_m<0.105 && TMath::Abs(lep1_eta)<2.5 && !(TMath::Abs(lep1_eta)>1.4442 && TMath::Abs(lep1_eta)<1.566) && TMath::Abs(lep2_eta)<2.5 && !(TMath::Abs(lep2_eta)>1.4442 && TMath::Abs(lep2_eta)<1.566))");
TCut lep_eta            ("lep_eta",                "lep1_m > 0.105 && fabs(lep1_eta) < 2.4 && fabs(lep2_eta) < 2.4) || (lep1_m < 0.105 && fabs(lep1_eta) < 2.5 && !(fabs(lep1_eta) > 1.4442 && fabs(lep1_eta) < 1.566)"); // muon || electron
TCut fatjet_pt          ("fatjet_pt",              "bos_PuppiAK8_pt>200");
TCut fatjet_eta         ("fatjet_eta",             "TMath::Abs(bos_PuppiAK8_eta)<2.4");
TCut fatjet_tau21       ("fatjet_tau21",           "TMath::Abs(bos_PuppiAK8_tau2tau1)<0.55"); // can be different// vbs vbf are used interchangeably TCut fatjet_tau21 ("fatjet_tau21",  "bos_PuppiAK8_tau2tau1<0.55");
TCut vbs_jets_mjj       ("vbs_jets_mjj",           "vbf_m>500");
TCut vbs_jets_pt        ("vbs_jets_pt",            "vbf1_AK4_pt>50 && vbf2_AK4_pt>50");
TCut vbs_delta_eta      ("vbs_delta_eta",          "vbf_deta>2.5"); // this is absolute delta eta
TCut met_pt             ("met_pt",                 "MET>30");
TCut btag_veto          ("btag_veto",              "nBtag_loose==0");// regions, sr: signal region, cr: control region
TCut wv_sr              ("wv_sr",                  "(bos_PuppiAK8_m_sd0_corr>65 && bos_PuppiAK8_m_sd0_corr<105)");
TCut wv_cr_vjets        ("wv_cr_vjets",            "(bos_PuppiAK8_m_sd0_corr>50 && bos_PuppiAK8_m_sd0_corr<65) || (bos_PuppiAK8_m_sd0_corr>105 && bos_PuppiAK8_m_sd0_corr<150) && nBtag_loose==0");
TCut wv_cr_top          ("wv_cr_top",              "nBtag_loose>0");
TCut dummy              ("dummy",                  "");
TCut ZeppWL             ("ZeppWLlt3",              "(TMath::Abs(zeppLep)/vbf_deta)<0.3");
TCut ZeppWH             ("ZeppWHlt3",              "(TMath::Abs(zeppHad)/vbf_deta)<0.3");
TCut noData             ("noData",                 "!(gid==3)");

TCut common             ("common",                 "(isAntiIso==0) && (bosCent > 0.0)");
TCut bos_common         ("bos_common",             fatjet_pt+fatjet_eta+fatjet_tau21);
TCut full_common        ("full_common",            category_selection+lep_pt+lep_eta+fatjet_pt+fatjet_eta+fatjet_tau21+vbs_jets_mjj+vbs_jets_pt+vbs_delta_eta+met_pt);
TCut full_vjets_cr      ("full_vjets_cr",          full_common+btag_veto+wv_cr_vjets);
TCut full_top_cr        ("full_top_cr",            full_common+wv_cr_top+wv_sr);
TCut full_wv_sr         ("full_wv_sr",             full_common+btag_veto+wv_sr);//+noData);

TCut wtot_2016          ("wtot_2016",              "35867.06*genWeight*mcWeight*L1PFWeight*puWeight"); //"35867.06*genWeight*mcWeight*L1PFWeight*puWeight"
TCut wtot_2017          ("wtot_2017",              "41530*genWeight*mcWeight*L1PFWeight*puWeight"); // 41530
TCut wtot_2018          ("wtot_2018",              "59740*genWeight*mcWeight*L1PFWeight*puWeight"); // 59740
TCut wtotL1             ("wtotL1",                 "L1PFWeight*genWeight*puWeight");
TCut allCuts            ("allCuts",                (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));
// Mark Cuts ---------------------------------------------------------------------------------------------------------------------------------


//TCut cleanNAN_phi           ("cleanNAN_phi",     "(phi_type0>0&&phi_type2>0&&phi_type0<3.14&&phi_type2<3.14)"  ); 
TCut cleanNAN_phi           ("cleanNAN_phi",       "(!TMath::IsNaN(phi_type0) && !TMath::IsNaN(phi_type2))"  ); // was (!TMath::IsNaN(phi_type0) && !TMath::IsNaN(phi_type2))
TCut wtot_old               ("wtot_old",           "35867.06*mcWeight*L1_Prefweight*btag0Wgt*genWeight*trig_eff_Weight*id_eff_Weight*pu_Weight");
TCut wtotL1_old             ("wtotL1_old",         "L1_Prefweight*btag0Wgt*genWeight*trig_eff_Weight*id_eff_Weight*pu_Weight");

TCut more	                ("more",	            "(type==0||type==1)");
TCut OneLpt                 ("OneLpt",             "(l_pt2<0 && l_pt1>50 && (((type==0)&&(abs(l_eta1)<2.4)) || ((type==1)&&((abs(l_eta1)<2.5)&&!(abs(l_eta1)>1.4442 && abs(l_eta1)<1.566)))))" );

//ramanpreet
//TCut OneMuPt50              ("OneMuPt50",           "(l_pt2<0 && l_pt1>50 && (((type==0)&&(abs(l_eta1)<2.4)) ) )");
//TCut fatjetLoose            ("fatjetLoose",         "((ungroomed_PuppiAK8_jet_pt>200)&&(abs(ungroomed_PuppiAK8_jet_eta)<2.4))");
//TCut antitagVBF             ("antitagVBF",          "(nBTagJet_loose==0)");
//TCut pfMETpuppi50           ("pfMETpuppi50",        "((type==0)&&(pfMET_Corr>50))");
//TCut mjw65to105             ("mjw65to105",          "((PuppiAK8_jet_mass_so_corr>65) && (PuppiAK8_jet_mass_so_corr<105))");
//TCut MjjVBF300              ("MjjVBF300",           "(vbf_maxpt_jj_m>300)");
//TCut detajjVBF2             ("detajjVBF4",          "(abs(vbf_maxpt_j2_eta-vbf_maxpt_j1_eta)>2.0)");

//paper selections
//TCut tmvasel                ("tmvasel",             cleanNAN+more+OneLpt  ); 
//TCut pfMETpuppi_m30e80      ("pfMETpuppi_m30e80",   "(((type==0)&&(pfMET_Corr>30)) || ((type==1)&&(pfMET_Corr>80)))");
TCut pfMETpuppi_m50e80      ("pfMETpuppi_m50e80",  "(((type==0)&&(pfMET_Corr>50)) || ((type==1)&&(pfMET_Corr>80)))");

TCut fatjet                 ("fatjet",             "((ungroomed_PuppiAK8_jet_pt>200)&&(abs(ungroomed_PuppiAK8_jet_eta)<2.4)&&(PuppiAK8_jet_tau2tau1<0.55))");
//TCut mjw40to125             ("mjw40to125",          "((PuppiAK8_jet_mass_so_corr>40) && (PuppiAK8_jet_mass_so_corr<125))");
TCut mjw65to105             ("mjw65to105",         "((PuppiAK8_jet_mass_so_corr>65) && (PuppiAK8_jet_mass_so_corr<105))");

TCut antitagVBF             ("antitagVBF",         "(nBTagJet_loose==0)");
TCut MjjVBF800              ("MjjVBF800",          "(vbf_maxpt_jj_m>800)");
TCut detajjVBF4	          ("detajjVBF4",         "(abs(vbf_maxpt_j2_eta-vbf_maxpt_j1_eta)>4.0)");
//TCut detajjVBF3p5           ("detajjVBF3p5",        "(abs(vbf_maxpt_j2_eta-vbf_maxpt_j1_eta)>3.5)");
TCut ptjjVBF30              ("ptjjVBF30",          "(vbf_maxpt_j1_pt>30) && (vbf_maxpt_j2_pt>30)");
TCut mlvj600                ("mlvj600",            "(mass_lvj_type0_PuppiAK8>600)");
TCut BCtype0gt1             ("BCtype0gt1",         "(BosonCentrality_type0>1.0)");
TCut ZeppWLlt3              ("ZeppWLlt3",          "((abs(ZeppenfeldWL_type0)/abs(vbf_maxpt_j2_eta-vbf_maxpt_j1_eta))<0.3)");
TCut ZeppWHlt3              ("ZeppWHlt3",          "((abs(ZeppenfeldWH)/abs(vbf_maxpt_j2_eta-vbf_maxpt_j1_eta))<0.3)" );
//TCut allCuts                ("allCuts",             (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));

//TCut wtot                  ("wtot",                "f_weight");
// TCut treff                 ("treff",               "f_eff_weight");

// TCut mqvbf                 ("mqvbf",               "");

//RamansSelections
//TCut rOneLpt                ("rOneLpt",             "(l_pt2<0 && l_pt1>50 && (((type==0)&&(abs(l_eta1)<2.4)) || ((type==1)&&((abs(l_eta1)<2.5)&&!(abs(l_eta1)>1.4442 && abs(l_eta1)<1.566)))))" );
//TCut rpfMETpuppi_m50e80     ("rpfMETpuppi_m50e80",  "(((type==0)&&(pfMET_Corr>50)) || ((type==1)&&(pfMET_Corr>80)))");
//TCut rptjjVBF30             ("rptjjVBF30",          "(vbf_maxpt_j1_pt>30) && (vbf_maxpt_j2_pt>30)");
//TCut rantitagVBF            ("rantitagVBF",         "(nBTagJet_loose==0)");
//TCut rfatjetPt200           ("rfatjetPt200 ",       "(ungroomed_PuppiAK8_jet_pt>200)");
//TCut rfatjetEta2p4          ("rfatjetEta2p4",       "(abs(ungroomed_PuppiAK8_jet_eta)<2.4)");
//TCut rmjw65to105            ("rmjw65to105",         "((PuppiAK8_jet_mass_so_corr>65) && (PuppiAK8_jet_mass_so_corr<105))");
//TCut rMjjVBF800             ("rMjjVBF800",          "(vbf_maxpt_jj_m>800)");
//TCut rMjjVBF300             ("rMjjVBF300",          "(vbf_maxpt_jj_m>300)");
//TCut rMjjVBF500             ("rMjjVBF500",          "(vbf_maxpt_jj_m>500)");
//TCut rdetajjVBF4            ("rdetajjVBF4",         "(abs(vbf_maxpt_j2_eta-vbf_maxpt_j1_eta)>4.0)");
//TCut rdetajjVBF2            ("rdetajjVBF2",         "(abs(vbf_maxpt_j2_eta-vbf_maxpt_j1_eta)>2.0)");
//TCut rallCuts               ("rallCuts",            (rOneLpt+ rpfMETpuppi_m50e80+rptjjVBF30+rantitagVBF+rfatjetPt200+rfatjetEta2p4+rmjw65to105+rMjjVBF800+rdetajjVBF4+mlvj600));
//TCut rallCutsr2             ("rallCuts",            (rOneLpt+ rpfMETpuppi_m50e80+rptjjVBF30+rantitagVBF+rfatjetPt200+rfatjetEta2p4+rMjjVBF300+rdetajjVBF2+mlvj600));
//TCut cuts0_W                ("cuts0_W",             "(l_pt2<0 && l_pt1>0) && (ungroomed_PuppiAK8_jet_pt>200) && (vbf_maxpt_jj_m>500)" );

class Sample{

private:  
  TString   _sname;
  TString   _gname;
  Float_t   _xsec;
  Int_t     _loadFlag;
  Int_t     _gid;
  Int_t     _sid;
  Int_t     _color;
  Int_t     _nMCgen;        // total generated events
  Int_t     _nMCgenNeg;     // negative generated events (strange VBS anl thing)
  //
  TTree*    _inpTree;          // total good events for scale calculation    
  //Int_t     _ngen;          // total good events for scale calculation
  Float_t _ngen;    
  Int_t     _nevents;       // events in tree
  TString   _reqlist;       // reqlist name
  Float_t   _sweight;       // _xsec/_ngen

 public:

  Sample(const char* gname, const char* sname, Float_t xsec, Int_t loadFlag, Int_t gid, Int_t sid, Int_t color, Float_t  nMCgen,  Float_t nMCgenNeg ){
    _sname=sname;
    _gname=gname;
    if(gid == gid_data ){
       _reqlist="reqlists/rqs_"+_gname+"--"+_sname+"_data.lst";
    }else if (gid >9) {
       _reqlist="reqlists/rqs_"+_gname+"--"+_sname+"_bkg.lst";
    }else{
       _reqlist="reqlists/rqs_"+_gname+"--"+_sname+"_sgl.lst";
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
  TString   getSName(){return _sname;  };
  TString   getGName(){return _gname;  };
  TString   getReqList(){return _reqlist;};
  Float_t     getNgen(){return _ngen;};
  Int_t     getXsec(){return _xsec;};
  Int_t     getGid(){return _gid;};
  Int_t     getSid(){return _sid;};
  Int_t     getScolor(){return _color;};
  Int_t     getLoadFlag(){return _loadFlag; };
  Float_t     getWeight(){return _sweight; };
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
    cout << "Sample:: Group/Name/LoadFlag/gid/sid/color/xsec/ngen/sweight = " << 
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
}VbsLepton;


//Local functions
//void fillBranch1( TBranch* bGroupID, TBranch* bjet3_highpt_pt,  TBranch* bjet3_highpt_eta, TBranch* bjet3_highpt_phi,   TTree* groupTree, Int_t groupID,  const char* groupName);
void fillBranch(TTree* groupTree,VbsReducedEvent& vbsEvent, Int_t groupID,  const char* groupName);
void fillBranch(TTree* groupTree, VbsReducedEvent& vbsEvent, Sample* sample);

void arrange_vbsReducedTree(TTree* vbsTree, VbsReducedEvent& vbsEvent); //map of  VBS4LeptonsAnalysisReduced branches to the local structure
//void   setChainBranches (TChain* inpChain);
TTree* chain2tree(TString inpChainName="VBS4LeptonsAnalysisReduced",
                  TString reqlist="reqlists/rqs_data.txt", TString combinedTreeName="", TString combinedTreeTitle="");

//
void setVbsDLorReaderVarsAndSpectators(TMVA::DataLoader* dataloader, TMVA::Reader* datareader, VbsReducedEvent& vbsEvent);
TChain* getChain(TString treeName, TString filelist); //creates chain from list of files
void getStat(TTree* tree, const char* var, TCut& cut, Stat_t stats[4]);  //number of normalized events
void convertTrees(const char* treeName, const char* filelist);
//void fixVbsTree( TTree* vbsTree, const char* fname);
//
//========================================
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
//
//========================================
void SelectVbsVars(vector<string>& vbsVars, TObjArray* brlist){
   string  var_sig = "f_";
   for(int i = 0; i < brlist->GetEntries(); ++i) {
     string brname = brlist->At(i)->GetName(); 
     if( brname.find(var_sig) != std::string::npos ){
       vbsVars.push_back(brname);
     }
   } 
}
//
//=======================================
TTree* chain2tree(TString inpChainName, TString reqlist, TString combinedTreeName, TString combinedTreeTitle){
//accumulates signal samples in a single tree
// Nevents = 0.942616 +/- 4.62438e-05  ZH_HToZZ
// Nevents = 20.17 +/- 0.00997012      glgl_HToZZ
// Nevents = 0.359368 +/- 1.06845e-05  ttH_HToZZ
// Nevents = 1.92646 +/- 0.000168216   VBF_HToZZTo4L
// Nevents = 0.217594 +/- 6.66961e-06  WminusH_HToZZTo4L
// Nevents = 0.343426 +/- 1.09348e-05  WplusH_HToZZ

//   cout << "chain2tree:: inpChainName/reqlist/combinedTreeName/combinedTreeTitle = " <<
//          inpChainName << "/" <<
//          reqlist      << "/" <<
//          combinedTreeName      << "/" <<
//        combinedTreeTitle <<
//   endl;
 
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
//
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
//===========================================================
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
//=======================================
TTree* getTree(TString treeName, TString fname)
{
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
   cout<< "Total entries " <<  setw(32)  << fname << " is " << ftree->GetEntries() <<endl;                                       
   dir->cd();     // back to starting dir                                                                                    
   return ftree;
}
//=======================================
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
//=======================================
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
      Int_t n = chain->Add(fname, -1);  // second parameter to ensure file exists                                             
      if (n == 0) {
         cout<< "getChain:ERROR:: while processing filelist " << filelist << ". File not found: " << fname <<endl;
         return 0;
      }
   }
   cout<< "getChain: Tree "  << treeName << " , total events: " << chain->GetEntries() <<endl;                           
   return chain;
}
//===============================================================
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
//===============================================================
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
	 getStat(mtree,"f_mass4l",wtot_2016,stats);
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
//================================================  
void fillBranch(TTree* groupTree, VbsReducedEvent& vbsEvent, Sample* sample){         
//
          addBranches_vbsReducedTree(groupTree,vbsEvent);
          arrange_vbsReducedTree(groupTree,vbsEvent);

          TBranch* bGroupID  = groupTree->GetBranch( "gid");
          TBranch* bSampleID = groupTree->GetBranch( "sid");
          TBranch* bMCweight = groupTree->GetBranch( "mcWeight");

          vbsEvent.gid = sample->getGid();
          vbsEvent.sid = sample->getSid();
          vbsEvent.mcWeight = sample->getWeight();

cout << "------------------------------ mcWeight/xsec/ngen/Calc = " << vbsEvent.mcWeight << " / " << sample->getXsec() << " / " << sample->getNgen() <<" ---------------------------" << endl;
//sleep(3);
          for (Long64_t ievt=0; ievt < groupTree->GetEntries(); ievt++) {
	      groupTree->GetEntry(ievt);
              bGroupID->Fill(); 
              bSampleID->Fill(); 
              bMCweight->Fill(); 
 	  }
}
//================================================  

#endif
