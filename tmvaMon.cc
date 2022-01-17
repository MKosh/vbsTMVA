#define tmvaMon_cxx
//=======================================================================
// $Id: tmvaMon.cc
// 
// File:    tmvaMon.cc
// Purpose: tmva event processor 
// Created: Dec 2017, Sergey Uzunyan (serguei@nicadd.niu.edu)
// Updated: 2021, Mark M. 
// root -l tmvaMon.cc\(\"vbs_ww\"\)
// root[1]  plotvar(anl,"PuppiAK8_jet_mass_so_corr", cleanNAN,  1.00, 0, 0,     0., 400., 5.);
// root[2]  plotvar(anl,"BDT"    ,  tmvasel,  1.0,  0, 0,     -1.0, 1.0, 0.05);
// root[5]  plotvar(anl,"DNN_GPU",  tmvasel,  1.0 , 0, 0,        0., 1.,  0.025,  1, 0);
//plotvar(anl, "PuppiAK8_jet_mass_so_corr", tmvasel,,  1.0, 1, 0,  20., 220., 10,       1, 0,  "VBS (WV), 35.9 fb^{-1}",    "AK8 Softdrop mass (GeV)",  "Events/bin");
//plotvar(anl, "mass_lvj_type0_PuppiAK8",   tmvasel,,  1.0, 1, 0,  0.0,  2500., 50,    1, 0,  "VBS (WV), 35.9 fb^{-1}", "mass_lvj_type0_PuppiAK8 ( M_{WW} ) (GeV)", "Events/bin");
//plotvar(anl, "BDT",                       tmvasel+allCuts,  1.0, 1, 1,  -1., 1.3, 0.05,   1, 0, "VBS (WV), 35.9 fb^{-1}", "BDT",        "Events/bin");
//
// find optimal cut max(s/sqrt(s+b)
//anl->optCutScan("sgf1",cleanNAN+allCuts,"BDT",-1, 1, 0.1,0.0005, 20)
//
// control plost
// cplots(anl, allCuts, "allCuts")
//
//printCutflow(anl, "mass_lvj_type0_PuppiAK8", "paperCuts", dummy,  1.0, 1, 0,  0.0,  2500., 50,    1, 0,  "VBS (WV), 35.9 fb^{-1}", "mass_lvj_type0_PuppiAK8 ( M_{WW} ) (GeV)", "Events/bin");
//=======================================================================

//#include "tmvaMon.hpp"
#include <unistd.h>
#include <ctime>
#include <vector>
#include <iostream>

#include "vbsTMVA.hpp"
#include "TPad.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TSystem.h"
#include "TImage.h"
#include "TKey.h"
#include "TH1.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TFile.h"
#include "TDirectory.h"
#include "TObjArray.h"
#include "THStack.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TBuffer.h"
#include "TCut.h"
#include "TMath.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TRatioPlot.h"
#include "TGaxis.h"
#include "TPostScript.h"
#include "TDOMParser.h"
#include "TXMLNode.h"
#include "TXMLAttr.h"
#include "TList.h"

#include "./limit_calc/CL95tmva.C"
#include "./limit_calc/Significance.C"

using namespace std;

//======================================================================================================================
//
namespace xsect{
  // signal channels cross-sections in pb

  Float_t xCH_WZToLL_M200	 =   0.195011;
  Float_t xCH_WZToLL_M300	 =   0.107954;
  Float_t xCH_WZToLL_M400	 =   0.065514;
  Float_t xCH_WZToLL_M500  =   0.04231;
  Float_t xCH_WZToLL_M600	 =   0.028534;
  Float_t xCH_WZToLL_M700	 =   0.019903;
  Float_t xCH_WZToLL_M800	 =   0.014244;
  Float_t xCH_WZToLL_M900	 =   0.010395;
  Float_t xCH_WZToLL_M1000 =   0.007685;
  Float_t xCH_WZToLL_M1500 =   0.00204;

  Float_t xCH_WZToLNu_M200  =  0.652561;
  Float_t xCH_WZToLNu_M300  =  0.361243;
  Float_t xCH_WZToLNu_M400  =  0.219229;
  Float_t xCH_WZToLNu_M500  =  0.141582;
  Float_t xCH_WZToLNu_M600  =  0.095481;
  Float_t xCH_WZToLNu_M700  =  0.0666;
  Float_t xCH_WZToLNu_M800  =  0.047665;
  Float_t xCH_WZToLNu_M900  =  0.034785;
  Float_t xCH_WZToLNu_M1000 =  0.025718;
  Float_t xCH_WZToLNu_M1500 =  0.006825;
  Float_t xCH_WZToLNu_M2000 =  0.002126;

  Float_t xDCH_WW_M200  =	1.554483;
  Float_t xDCH_WW_M300  =	0.871547;
  Float_t xDCH_WW_M400  =	0.536185;
  Float_t xDCH_WW_M500  =	0.35078;	
  Float_t xDCH_WW_M600  =	0.239827;
  Float_t xDCH_WW_M700  =	0.169306;
  Float_t xDCH_WW_M800  =	0.122536;
  Float_t xDCH_WW_M900  =	0.090467;
  Float_t xDCH_WW_M1000 = 0.067863;
  Float_t xDCH_WW_M1500 =	0.018868;
  Float_t xDCH_WW_M2000 =	0.006135;

   //VW_EVK x-sections
  Float_t xWminusTo2JZTo2LJJ_EWK_LO_SM       = 0.02982;
  Float_t xWminusToLNuWminusTo2JJJ_EWK_LO_SM = 0.03259;
  Float_t xWminusToLNuZTo2JJJ_EWK_LO_SM      = 0.1;
  Float_t xWplusTo2JWminusToLNuJJ_EWK_LO_SM  = 0.9107;
  Float_t xWplusTo2JZTo2LJJ_EWK_LO_SM 	   = 0.05401;
  Float_t xWplusToLNuWminusTo2JJJ_EWK_LO_SM  = 0.9114;
  Float_t xWplusToLNuWplusTo2JJJ_EWK_LO_SM   = 0.08793;
  Float_t xWplusToLNuZTo2JJJ_EWK_LO_SM       = 0.1825;
  Float_t xZTo2LZTo2JJJ_EWK_LO_SM 	   = 0.01589;

    //Float_t  xSignal    =   xCH_WZToLL_M500;
    //Float_t  xSignal    =   xCH_WZToLL_M500+xCH_WZToLNu_M500+xDCH_WW_M500 ;
  Float_t  xSignal    = xWminusTo2JZTo2LJJ_EWK_LO_SM       + \
                        xWminusToLNuWminusTo2JJJ_EWK_LO_SM + \
                        xWminusToLNuZTo2JJJ_EWK_LO_SM      + \
                        xWplusTo2JWminusToLNuJJ_EWK_LO_SM  + \
                        xWplusTo2JZTo2LJJ_EWK_LO_SM   + \
                        xWplusToLNuWminusTo2JJJ_EWK_LO_SM + \
                        xWplusToLNuWplusTo2JJJ_EWK_LO_SM + \
                        xWplusToLNuZTo2JJJ_EWK_LO_SM + \
                        xZTo2LZTo2JJJ_EWK_LO_SM ;
  // 2.32484
}

Float_t g_lum;

//======================================================================================================================
//
class TmvaSample{
  private:  
    //Int_t   _sid;
    TTree*  _testTree;
    TTree*  _trainTree;
    Float_t _tmvaScale;

    Float_t   _xsec;
    Float_t   _ngen; // _xsect (fb) * lum (fb-1)  
    Stat_t  _stats[4];
    TCut    _samplecut;
  public:
    Int_t   _sid;
      //TmvaSample(const char* smplname, TTree* testTree, TTree* trainTree, Int_t sID, TCut samplecut);
    TmvaSample(Int_t sid, Int_t scolor, const char* smplname, TCut samplecut,Float_t ngen_normfb, TTree* testTree, TTree* trainTree);
    TH1F*    _hf1;
    TH2F*    _hf2;
    TString  _name;
    Int_t    _scolor;

    Float_t  npass; // npass/ngen ( _xsect (fb) * lum (fb-1) )  
    Float_t  npass_err;
    Float_t  accpt;

    Float_t fillSampleHist(const char* var, TCut cuts, Float_t scale=1.0);
    //  Float_t calcSgf(const char* sgfName);
    TCut   getScut(){return _samplecut;}
    TTree* getTestTree(){ return _testTree;}
    TTree* getTrainTree(){ return _trainTree;}
};

//======================================================================================================================
//
TmvaSample::TmvaSample(Int_t sid,Int_t scolor, const char* smplname, TCut samplecut,Float_t ngen_normfb, TTree* testTree, TTree* trainTree){
  _sid       = sid;
  _scolor    = scolor;
  _samplecut = samplecut; 
  _name      = smplname;
  _ngen      = ngen_normfb;
  _testTree  = testTree;
  _trainTree = trainTree;
}

//======================================================================================================================
//
Float_t TmvaSample::fillSampleHist(const char* var, TCut cuts, Float_t scale){
  if(_sid == 3) {
    _testTree->Project(_hf1->GetName(), var, (cuts+_samplecut), "goff");
  } else {
    _testTree->Project(_hf1->GetName(), var, norm_hist*(cuts+_samplecut), "goff");
  }

  int year = 2017;
  if (_sid == 15 && year == 2018) {
    //scale *= 0.6875; // 2018 Scale ttbar 
  } else if (_sid == 13 && year == 2018) {
   // scale *= 0.802; // 2018 Scale Wjets
  } else if (_sid == 15 && year == 2016) {

  } else if (_sid == 13 && year == 2016) {
   // scale *= 1.794;
  } else if (_sid == 15 && year == 2017) {

  } else if (_sid == 13 && year == 2017) {
    //scale *= 1.303;
  } else if (_sid == 15 && year == 1111) {
   // scale *= 0.133;
  } else if (_sid == 13 && year == 1111) {
   //  scale *= 1.0;
  }

  _hf1->GetStats(_stats);
  npass    = _stats[0]*(scale);
  npass_err= scale*TMath::Sqrt(_stats[1]);
  accpt   = 100.*  npass/_ngen;
  // cout << "stats/scale/npass/npass_err/ngen/accpt = " << _stats[0] << " / " << scale << " / " << npass << " / " << npass_err << " / " << _ngen << " / " << accpt << endl;

  //ROOT V6 does not change statistics when scaling histogramms
  //(but root 5.34 does)
  //Thus we first get stats and then scale
  _hf1->GetStats(_stats);
  _hf1->Scale(scale);
  return npass;
}

//======================================================================================================================
//
class CutList {
  TObjArray _cuts;
public:
  CutList() {
    _cuts.SetOwner();
    _cuts.Clear();
  }
  ~CutList() {_cuts.Clear();}
  void Clear() {_cuts.Clear();}
  CutList& operator << (const TCut& cut) {
    TCut* pcut = new TCut(cut);
    _cuts.Add(pcut);
    return *this;
  }
  Int_t N()         const {return _cuts.GetLast()+1;}
  Int_t GetLast()   const {return _cuts.GetLast();}
  TCut operator [] (Int_t n) const {
    TCut cut;
    if (n > GetLast()) {
      cout<< "*** ERROR CutList::operator[]: No. " << n << " out of bound " << GetLast() <<endl;
      return cut;
    }
    cut = *((const TCut*) _cuts.At(n));
    return cut;
  }
  TCut Cut(Int_t n) const {
    TCut cut;
    if (n > GetLast()) {
      cout<< "*** ERROR CutList::Cut: No. " << n << " out of bound " << GetLast() <<endl;
      return cut;
    }
    cut = *((const TCut*) _cuts.At(n));
    return cut;
  }
  TCut SumTo(Int_t n) const {
    TCut sum;
    if (n > N()) {
      cout<< "*** ERROR CutList::SumTo: No. " << n << " exceeds last stored " << GetLast() <<endl;
      return sum;
    }
    for (int i=0; i<=n; ++i) {
      const TCut* cut = (const TCut*) _cuts.At(i);
      sum += *cut;
    }
    return sum;
  }
  TCut All() const {
    TCut sum;
    for (int i=0; i<=GetLast(); ++i) {
      const TCut* cut = (const TCut*) _cuts.At(i);
      sum += *cut;
    }
    return sum;
  }
  void PrintLine() const {
    for (int i=0; i<=GetLast(); ++i) {
      if (i > 0) cout<< "+";
      const TCut* cut = (const TCut*) _cuts.At(i);
      if (strcmp(cut->GetName(), "CUT")) cout<< cut->GetName();
      else cout<< "\"" << cut->GetTitle() << "\"";
    }
    cout<<endl;
  }
  void Print() const {
    for (int i=0; i<_cuts.GetLast()+1; ++i) {
      const TCut* cut = (const TCut*) _cuts.At(i);
      cout<< i <<" "<< cut->GetTitle() <<endl;
    }
  }
};

//======================================================================================================================
//
class TmvaAnl{
  private:
    TString _anl_name;
    TFile*  _inputSBD;

    TmvaSample* _sgl;
    TmvaSample* _bkg;
    TmvaSample* _data;
    vector<TmvaSample*> _vsamples;

    Int_t   _debug;
    Int_t   _istyle;
    TH1F*   _hframe;

    Float_t _sgf0; // eff*purity
    Float_t _sgf1; // s/sqrt(s+b)
    Float_t _sgf2; // 95% CL exp limit, fb
    Float_t _sgf3; // s/sqrt(b)
    Int_t   _useGauss; // for TLimit (==1 if _sgl_npass>20)

    map<Float_t,Float_t> _optmap;
    TGraphErrors*        _optgraph;

    Float_t _scale_sgl_tmva;
    Float_t _scale_bkg_tmva;
    Float_t _lum;  //lum in fb-1

    vector<TH1F*> bkg_hists;
    Int_t        _nstackplots;
    Int_t        _fsaveplots;

  public:
    CutList cuts;
    static const UInt_t  PB2FB = 1000;
    TmvaAnl(TString  anlname,Float_t lum_fbinv, std::vector<TmvaSample*> vsamples, Float_t& scale_sgl_tmva,Float_t& scale_bkg_tmva);
    void setDataSample(UInt_t sID){ _data = _vsamples[sID]; }
    void setSglSample(UInt_t sID){  _sgl = _vsamples[sID]; }
    void setBkgSample(UInt_t sID){  _bkg = _vsamples[sID]; }
    void setsvplots(Int_t isvplots){ _fsaveplots = isvplots;}
    void setLum(Float_t lum) { _lum = lum;}
    void PrintStat(TCut& cuts,Int_t debug);
    void setHistStyle(TH1F* hist);

    //TmvaSample* getDataSample(){return _data;}

    void setHframe(const char* var, TCut cuts, Float_t xmin, Float_t xmax, Float_t bw,
  	  const char hTitle[]="test", const char xTitle[]="test", const char yTitle[]="test");
    TH1F* makeHist(const char* hname, const char* hvar, Int_t nbins, Float_t hvar_min, Float_t hvar_max);

    Float_t optCutAlg1(const char* optParName,TCut basecuts, const char* cutvar, Float_t cutvar_min, Float_t cutvar_max, Float_t dsgf, Float_t dstepw, Int_t npoints);
    Float_t optCutScan(const char* optParName, TCut basecuts, const char* cutvar, Float_t cutvar_min, Float_t cutvar_max, Float_t dsgf, Float_t dstepw, Int_t npoints);
    void setSampleHists();
    void fillSampleHists(const char* var, TCut cut, Float_t scale=1.0);
    void setTmvaScales(Float_t& scale_sgl_tmva,Float_t& scale_bkg_tmva){
      _scale_sgl_tmva = scale_sgl_tmva;
      _scale_bkg_tmva = scale_bkg_tmva;
    }
    Int_t ArrangeHtms(Int_t flogy=0);
    void  StackHtms(Int_t& imax, Float_t& ymin, Int_t flogy=0, Int_t overFlow=0);
    void  PlotHists(Float_t ymin, Int_t flogy=0, Int_t overFlow=0);
    void  PlotLegend(const char* var);
    void  PlotSgf(const char* var); 
    void  sdb(Int_t dbl){ _debug=dbl; };
    Float_t optParVal(const char* optParName);
    TmvaSample* getSglSample(){ return _sgl;};
    TmvaSample* getDataSample(){ return _data;};

    void PlotShapes(Float_t ymin, Int_t flogy=0, Int_t overFlow=0);
    void makeShapeComp(Float_t ymin, Int_t flogy=0, Int_t overFlow=0);
};

//======================================================================================================================
//
TmvaAnl::TmvaAnl(TString anlname, Float_t lum_fbinv, std::vector<TmvaSample*> vec_samples, Float_t& scale_sgl_tmva,Float_t& scale_bkg_tmva){
  _debug=0;
  _anl_name = anlname;
  _vsamples = vec_samples;
  _lum      = lum_fbinv;  // fb-1

  _sgl=vec_samples[0];
  _bkg=vec_samples[1];
  _data=vec_samples[2];

  _scale_sgl_tmva=scale_sgl_tmva;
  _scale_bkg_tmva=scale_bkg_tmva;
  _nstackplots=0;
  _fsaveplots=0;
  _sgf0=0;
  _sgf1=0;
  _sgf2=0;
  _sgf3=0;
}

//======================================================================================================================
//
Int_t plotShapeComp(TmvaAnl* anl, const char* var, TCut cut, Float_t scale=1.0, Int_t debug=0, Int_t istyle=0,
        Float_t xmin=0., Float_t xmax=200., Float_t bw=-1.,Int_t flogy=0, Int_t flogx=0, Int_t overFlow=0,
	      const char hTitle[]="test", const char xTitle[]="test", const char yTitle[]="test");

Int_t plotSingleVariable(TmvaAnl* anl, const char* var, TCut cut, const char* cutName, Float_t scale=1.0, Int_t debug=0, Int_t istyle=0,
        Float_t xmin=0., Float_t xmax=200., Float_t bw=-1.,Int_t flogy=0, Int_t flogx=0, Int_t overFlow=0,
	      const char hTitle[]="test", const char xTitle[]="test", const char yTitle[]="test");

Int_t plotvar( TmvaAnl* anl, const char* var, TCut cut, Float_t scale=1.0, Int_t debug=0, Int_t istyle=0,
	       Float_t xmin=0., Float_t xmax=200., Float_t bw=-1.,Int_t flogy=0, Int_t flogx=0, Int_t overFlow=0,
	       const char hTitle[]="test", const char xTitle[]="test", const char yTitle[]="test");

Int_t cplotvar( TmvaAnl* anl, const char* var, TCut cut, Float_t scale=1.0, Int_t debug=0, Int_t istyle=0,
	       Float_t xmin=0., Float_t xmax=200., Float_t bw=-1.,Int_t flogy=0, Int_t flogx=0,
	       const char hTitle[]="test", const char xTitle[]="test", const char yTitle[]="test");

// Int_t cplotvar(TmvaAnl* anl, const char* var, TCut cuts, Float_t scale, Int_t debug, Int_t istyle,
// 	       Float_t xmin, Float_t xmax, Float_t bw,Int_t flogy, Int_t flogx,
// 	       const char hTitle[], const char xTitle[], const char yTitle[]);

void  printCutflow( TmvaAnl* anl, const char* var, const char* flowname="", TCut cut="", Float_t scale=1.0, Int_t debug=0, Int_t istyle=0,
	       Float_t xmin=0., Float_t xmax=200., Float_t bw=-1.,Int_t flogy=0, Int_t flogx=0,
	       const char hTitle[]="test", const char xTitle[]="test", const char yTitle[]="test");

void cplots(TmvaAnl* anl, TCut cuts, TString CutName);

void shapePlots(TmvaAnl*, TCut cuts, TString CutName);

void genPlots(TmvaAnl *anl, TCut cuts = "", TString name = "test", TString folder = "datasets", 
    TString file_name = "training_methods", const char plot_style = 'r');

TCut  splitCuts(const char* strcuts);

void SetRatioPlotStyle(TRatioPlot* ratio);

TString getDateString();

Int_t makeNewDirectory(TString path);

//======================================================================================================================
//
TmvaAnl* anl;
stringstream ssifname;
TmvaAnl* getAnl(TString& anlName, Float_t lum_fbinv = 35.867);
TH1F* cloneHist(TH1F* hframe, const char* histname);
TH1F* xCloneHist(TH1F* hframe, const char* cloneName, Int_t cloneNum);
TGraphErrors*  map2graph( const char* sgfName,const char* cutvar, map<Float_t,Float_t>& opthist,  Float_t& best_cutval, Float_t& sgf_at_bestcut );
Int_t limit_calc(int ndata, double nbkg, double sbkg,  double acc,  double acc_error, double lumi, double lumi_error,  bool IfGauss,double& cl95res, double&  pfluc );

//======================================================================================================================
//
void tmvaMon(TString anlName="vbf_ww", Float_t lum_fb=35.867, TCut cut="", TString cutName="test"){
  //
  TH1::StatOverflows(kTRUE);  // To force the underflows and overflows in the getStat() computations
  TGaxis::SetMaxDigits(3);
  gErrorIgnoreLevel = kWarning; // Ignore "Info in ..." printouts in ROOT session, helpful for making the cutflow tables
  anl = getAnl(anlName,lum_fb);
  g_lum = lum_fb;
  cout << "" << endl;
  cout << "Luminosity = " << g_lum << " fb^-1" << endl;
  cout << "To plot all control plot variables with a particular cut (or for no cuts exclude args 2 and 3) use" << endl;
  cout << "  cplots(anl, cut, \"cutname\")" << endl;
  cout << "To plot, for example,  vbf1_AK4_qgid  using \"cleanNAN\" set of cuts " << endl;
  cout << "  plotvar(anl,\"vbf1_AK4_qgid\",cleanNAN)" << endl;
  cout << "  plotSingleVariable(anl, \"vbf1_AK4_qgid\", dummy, \"dummy\", 1.0, 1, 0, xmin, xmax, binwidth, logy, logx, \"hist title\", \"xtitle\", \"ytitle\")" << endl;
  cout << "To view cutflow tables use: " << endl;
  cout << "  printCutflow(anl, \"lep1_pt\",  \"testCuts\", dummy,  1.0, 1, 0,   20., 400., 20, 1, 0, \"VBS (WV), 35.867fb^{-1}\", \"Lepton_1 p_{T} (GeV)\", \"Events/bin\")" << endl;
  cout << "To examine TMVA plots:" << endl;
  cout << "  tmgui()" << endl;
  cout << "" << endl;

cplots(anl, cut, cutName); // XXX This comment is just for the makefile to see and sed to change whether this line actually runs
//shapePlots(anl, cut, cutName); // XXX
  //genPlots(anl, cut, cutName))))))))))))))))))), "datasets/plot_args", "training_methods", 's'); // XXX genPlots

  //plotvar(anl,"PuppiAK8_jet_mass_so_corr", cleanNAN, 1.00, 0, 0,     0., 400., 5.);
  //plotvar(sgl,"PuppiAK8_jet_mass_so_corr", z1m40, 1.00, 0, 0,     0., 400., 5.);
}

//======================================================================================================================
//
void  tmvacmp(TmvaAnl* anl, const char* sgf, const char* varset="test"){
  stringstream tmvacut;
  stringstream htitle;
  stringstream ofname; 
  TCanvas*  cmpCanvas = (TCanvas*)gROOT->FindObject("cmpCanvas"); 
  if(cmpCanvas) {cmpCanvas->Delete(); }
  cmpCanvas = new TCanvas("cmpCanvas","cmpCanvas",10,10,1000,1000);

  TCanvas*  cmpPad = (TCanvas*)gROOT->FindObject("cmpPad"); 
  if(cmpPad) {cmpPad->Delete(); }
  cmpPad = new TCanvas("cmpPad","cmpPad",10,10,700,700);

  const Int_t ntmva=4;
  const char* TMVAset[ntmva] = { "f_Djet_VAJHU", "BDT","MLPBFGS", "DNN_GPU" };
  Float_t opt_cut = 0;
  Float_t tmva_min =  0.;
  Float_t tmva_max =  1.;

  cmpPad->cd();
  // // plotvar(anl, "mass_lvj_type0_PuppiAK8",    allCuts,  1.0, 1, 0,  0.0,  2500., 50,    1, 0,  "VBS (WV), 35.9 fb^{-1}", "mass_lvj_type0_PuppiAK8 ( M_{WW} ) (GeV)", "Events/bin");
  // // gPad->SaveAs("mass_lvj_type0_PuppiAK8_vbsWV.eps");
  // // gPad->SaveAs("mass_lvj_type0_PuppiAK8_vbsWV.png");
  // // gPad->SaveAs("mass_lvj_type0_PuppiAK8_vbsWV.pdf");

  anl->setsvplots(1);
  cmpCanvas->Clear();
  cmpCanvas->Divide(2,ntmva);

  for ( Int_t iset=0; iset<ntmva; iset++ ){
    tmvacut.str("");
    ofname.str("");
    cout << "iset = " << TMVAset[iset] << endl;
    if ( strcmp(TMVAset[iset],"BDT")  == 0 || strcmp(TMVAset[iset],"Fisher")  == 0 ) {
      tmva_min = -1;
    } else {
      tmva_min =  0;
    }
    cout << "iset/tmva_min  = " << TMVAset[iset] << "/" << tmva_min << endl;

    //  opt_cut = anl->optCutScan("sgf0",cleanNAN, TMVAset[iset], tmva_min, tmva_max, 0.1,0.0005, 10); //effxpurity
    opt_cut = anl->optCutScan(sgf,cleanNAN, TMVAset[iset], tmva_min, tmva_max, 0.1,0.0005, 10); //s/sqrt(b)

    cmpCanvas->cd(2*iset+1);
    plotvar(anl, TMVAset[iset], allCuts,  1.00, 0, 0,     tmva_min,   tmva_max, 0.1,  1, 0, 0, 0, "VBS (WV), 35.9 fb^{-1}", TMVAset[iset]);
      cmpPad->cd();
    plotvar(anl, TMVAset[iset], allCuts,  1.00, 0, 0,     tmva_min,   tmva_max, 0.1,  1, 0, 0, 0, "VBS (WV), 35.9 fb^{-1}", TMVAset[iset]);


    ofname <<  TMVAset[iset] << "_" << varset << "_" << sgf << ".pdf";
    gPad->SaveAs(ofname.str().c_str());
    ofname.str("");
    ofname <<  TMVAset[iset] << "_" << varset << "_" << sgf << ".png";
    gPad->SaveAs(ofname.str().c_str());
    ofname.str("");
    ofname <<  TMVAset[iset] << "_" << varset << "_" << sgf << ".eps";
    gPad->SaveAs(ofname.str().c_str());
    ofname.str("");

    cmpCanvas->cd(2*iset+2);
    cout << "opt_cut_" << TMVAset[iset] << " = " << opt_cut << endl;
    tmvacut <<  TMVAset[iset] << " > " << opt_cut;
    cout   << "tmvacut = " << tmvacut.str().c_str() << endl;
    htitle.str("");
    htitle << "VBS (WV), 35.9 fb^{-1}, " <<  tmvacut.str().c_str();

    plotvar(anl,"PuppiAK8_jet_mass_so_corr", allCuts+tmvacut.str().c_str(),  1.00, 0, 1,        111., 147., 4.,  0, 0, 0, htitle.str().c_str(), "m_{4l} (GeV)");
    cmpPad->cd();
    plotvar(anl,"PuppiAK8_jet_mass_so_corr", allCuts+tmvacut.str().c_str(),  1.00, 0, 1,        111., 147., 4.,  0, 0, 0, htitle.str().c_str(), "m_{4l} (GeV)");
    ofname << "mass_lvj_type0_PuppiAK8_vbsWV_" << TMVAset[iset] <<  "_" << sgf << "Max_" << varset << ".pdf";
    gPad->SaveAs(ofname.str().c_str());
    ofname.str("");
    ofname << "mass_lvj_type0_PuppiAK8_vbsWV_" << TMVAset[iset] << "_" << sgf << "Max_"  << varset << ".png";
    gPad->SaveAs(ofname.str().c_str());
    ofname.str("");
    ofname << "mass_lvj_type0_PuppiAK8_vbsWV_" << TMVAset[iset] << "_" << sgf << "Max_" << varset << ".eps";
    gPad->SaveAs(ofname.str().c_str());
    ofname.str("");
  }

  ofname.str("");
  ofname << "tmvaCMP_" << varset << "_" <<  sgf << ".pdf";
  cmpCanvas->SaveAs(ofname.str().c_str());
  ofname.str("");
  ofname << "tmvaCMP_" << varset <<  "_" << sgf << ".eps";
  cmpCanvas->SaveAs(ofname.str().c_str());
  anl->setsvplots(0);
}

//======================================================================================================================
//
TmvaAnl* getAnl(TString& anlName, Float_t lum_fbinv){
  ssifname <<  anlName << "_SBtmva.root";
  TString inpfileName( ssifname.str().c_str() );  
  //  
  TFile* inputSBD  = TFile::Open(inpfileName);
  int nev_test_data =0;
 
  TDirectory* anl_dir = (TDirectory*) inputSBD->GetDirectory(anlName);
  if (anl_dir) {
    anl_dir->cd();
    cout <<  "Using analysis directory " << anlName << endl;
  } else {
    cout <<  "Can not find the analysis directory " <<  anlName << endl;
    exit(1);
  }

  TTree* treeSB        = (TTree*)anl_dir->Get("TestTree");
  TTree* treeSB_train  = (TTree*)anl_dir->Get("TrainTree");
  TTree* treeData      = (TTree*)anl_dir->Get("DataTree");

  if(treeSB){
    std::cout << "--- plot_tmv: Using signal&bkg test trees from file: " << inputSBD->GetName() << std::endl;
  } 
  if ( ! treeData){
    std::cout <<  "--- plot_tmv: No data were evaluated; using MC only " << std::endl;
  }
  int nev_test_bkg  =  treeSB->GetEntries("classID==1");
  int nev_train_bkg =  treeSB_train->GetEntries("classID==1");
  int nev_test_sgl  =  treeSB->GetEntries("classID==0");
  int nev_train_sgl =  treeSB_train->GetEntries("classID==0");

  if(treeData) nev_test_data  =  treeData->GetEntries();
  //   cout << "Ngen signal :: nsignal = " <<   nsignal << endl;
  cout << " Entries bkg :: test/train/test+train = " <<  
      nev_test_bkg <<  "/" <<  
      nev_train_bkg <<  "/" <<  
      nev_test_bkg +  nev_train_bkg <<
  endl;  
  cout << " Entries sgl :: test/train/test+train = " <<  
      nev_test_sgl <<  "/" <<  
      nev_train_sgl <<  "/" <<  
      nev_test_sgl +  nev_train_sgl <<
  endl;

  Float_t scale_bkg_tmva= (nev_test_bkg+0.0)/(nev_train_bkg+nev_test_bkg);
  Float_t scale_sgl_tmva= (nev_test_sgl+0.0)/(nev_train_sgl+nev_test_sgl);

  cout << " scale_sgl_tmva/scale_bkg_tmva = " <<  scale_sgl_tmva << "/"  << scale_bkg_tmva  << endl;
  cout << " Entries data  = " <<  nev_test_data << endl;

  std::vector<TmvaSample*> anl_samples; 

  //TmvaSample::TmvaSample(Int_t sid, const char* smplname, TCut samplecut,Float_t xsec_fb = 1., TTree* testTree = treeSB, TTree* trainTree = treeSB_train)
  Float_t  nsignal_norm  = lum_fbinv * TmvaAnl::PB2FB* xsect::xSignal;
  Float_t  nsignal_xsect =  TmvaAnl::PB2FB*xsect::xSignal;
  //
  cout << " Signal x-sect, fb / Generated signal events (normalized to Lum =  " << lum_fbinv << " fb ) :: " << nsignal_xsect << "/" << nsignal_norm << endl; 
  cout << " 1.0 * lum_fbinv * PB2FB = " << 1.0*lum_fbinv*TmvaAnl::PB2FB << endl;

// TmvaSample::TmvaSample(Int_t sid,Int_t scolor, const char* smplname, TCut samplecut,Float_t ngen_normfb, TTree* testTree, TTree* trainTree)
  TmvaSample* sgl  = new TmvaSample(1, kRed-6,"sgl", "classID==0", nsignal_norm, treeSB, treeSB_train); // new color = kTeal+5 | old color = kTeal+2
  TmvaSample* bkg  = new TmvaSample(2, kWhite,  "bkg", "classID==1", 1.0* lum_fbinv * TmvaAnl::PB2FB, treeSB, treeSB_train); 
  TmvaSample* data = new TmvaSample(3, kBlack,"data","classID==3", 1.0* lum_fbinv * TmvaAnl::PB2FB, treeData, treeData);
  //
//   TmvaSample* ewkWV    = new TmvaSample(gid_ewkWV,   910,  "ewkWV",    cut_ewkWV,    1.0* lum_fbinv * TmvaAnl::PB2FB,  treeSB, treeSB_train);
//   TmvaSample* Wjets    = new TmvaSample(gid_Wjets,   924,  "Wjets",    cut_Wjets,    1.0* lum_fbinv * TmvaAnl::PB2FB,  treeSB, treeSB_train);
//   TmvaSample* Zjets    = new TmvaSample(gid_Zjets,     4,  "Zjets",    cut_Zjets,    1.0* lum_fbinv * TmvaAnl::PB2FB,  treeSB, treeSB_train);
//   TmvaSample* DiBosons = new TmvaSample(gid_Diboson, 400,  "DiBosons", cut_DiBosons, 1.0* lum_fbinv * TmvaAnl::PB2FB,  treeSB, treeSB_train);
//   TmvaSample* TT       = new TmvaSample(gid_top,     592,  "TT",       cut_TT  ,     1.0* lum_fbinv * TmvaAnl::PB2FB,  treeSB, treeSB_train);

// Color order: old = kOrange-4 (zjets) -> kMagenta-10 (dibos) -> kAzure-4 (tt) -> kCyan-3 (wjets) -> kRed-5 (sgl)
// Color order: new = kMagenta-10 -> kTeal+3 -> kOrange-2 -> kAzure-4 -> kRed-6 | pink -> green -> yellow -> blue -> red

  TmvaSample* Zjets    = new TmvaSample(gid_Zjets,   kOrange-4,    "Zjets",    cut_Zjets,    1.0* lum_fbinv * TmvaAnl::PB2FB,  treeSB, treeSB_train); // new color = kOrange-4 | old color = kYellow
//  TmvaSample* ewkWV    = new TmvaSample(gid_ewkWV,   kRed-10,       "ewkWV",    cut_ewkWV,    1.0* lum_fbinv * TmvaAnl::PB2FB,  treeSB, treeSB_train);
  TmvaSample* DiBosons = new TmvaSample(gid_Diboson, kTeal-7,  "DiBosons", cut_DiBosons, 1.0* lum_fbinv * TmvaAnl::PB2FB,  treeSB, treeSB_train); // new color = kMagenta-10 | old color = kOrange+4 ... kTeal-8 also pretty good here, kteal+2 is okay
  TmvaSample* TT       = new TmvaSample(gid_top,     kMagenta-10,   "TT",       cut_TT  ,     1.0* lum_fbinv * TmvaAnl::PB2FB,  treeSB, treeSB_train); // new color = kAzure-4 | old color = kAzure+7
  TmvaSample* Wjets    = new TmvaSample(gid_Wjets,   kAzure-4,      "Wjets",    cut_Wjets,    1.0* lum_fbinv * TmvaAnl::PB2FB,  treeSB, treeSB_train); // new color = kCyan-3 | old color = kCyan-10
//  TmvaSample* QCD  = new TmvaSample(17,kPink+1,         "QCD",     "gid==17",    1.0* lum_fbinv* TmvaAnl::PB2FB,   treeSB, treeSB_train);

  anl_samples.push_back(sgl);
  anl_samples.push_back(bkg);
  anl_samples.push_back(data);
  //Add smaller backgrounds first
  anl_samples.push_back(Zjets);
  //  anl_samples.push_back(ewkWV);
  anl_samples.push_back(DiBosons);
  anl_samples.push_back(TT);
  anl_samples.push_back(Wjets);
  //

  return new TmvaAnl(anlName,lum_fbinv,anl_samples,scale_sgl_tmva,scale_bkg_tmva); 
}

//======================================================================================================================
//
Int_t plotShapeComp(TmvaAnl* anl, const char* var, TCut cuts, Float_t scale, Int_t debug, Int_t istyle,
        Float_t xmin, Float_t xmax, Float_t bw,Int_t flogy, Int_t flogx, Int_t overFlow,
	      const char hTitle[], const char xTitle[], const char yTitle[]) {

  anl->setHframe(var,norm_hist*(cuts+cut_bkg),xmin,xmax,bw,hTitle,xTitle,yTitle); //need init hf1 for each sample
  anl->setSampleHists();
  anl->fillSampleHists(var,cuts,scale);

  Float_t ymin= 0.0;
  if (flogy) ymin= pow(10,flogy*(-1));

  gStyle->SetOptStat(0);
  //TCanvas* canvas1 = (TCanvas*)gROOT->FindObject("canvas1");
  //if (canvas1) { canvas1->Delete(); }
  //canvas1 = new TCanvas("canvas1","canvas1", 10,10, 800,800);
  anl->PlotShapes(ymin, flogy, overFlow); 
  anl->PlotLegend(var);

  if(istyle==1){
    anl->PlotSgf(var);
  }else if(istyle>1){ 
    TH1F* sglscale =  (TH1F*) gROOT->FindObject("sglscale"); 
    if(sglscale){
      sglscale->Delete();
    }
    sglscale= (TH1F*) anl->getSglSample()->_hf1->Clone();
    sglscale->SetName("sglscale");
    sglscale->Scale(istyle);
    sglscale->Draw("hist same");
  }

  gPad->SetLogy(flogy);
  anl->PrintStat(cuts,debug);

  //stringstream outPlotname;
  //outPlotname << "Plot_" << var << "_" << cutName << ".pdf";
  //canvas1->SaveAs(outPlotname.str().c_str());
  return 0;
}

//======================================================================================================================
//
Int_t plotSingleVariable( TmvaAnl* anl, const char* var, TCut cuts, const char* cutName, Float_t scale, Int_t debug, Int_t istyle,
	       Float_t xmin, Float_t xmax, Float_t bw,Int_t flogy, Int_t flogx, Int_t overFlow,
	       const char hTitle[], const char xTitle[], const char yTitle[]){
  
  anl->setHframe(var,norm_hist*(cuts+cut_bkg),xmin,xmax,bw,hTitle,xTitle,yTitle); //need init hf1 for each sample
  anl->setSampleHists();
  anl->fillSampleHists(var,cuts,scale);

  Float_t ymin= 0.0;
  if (flogy) ymin= pow(10,flogy*(-1));

  gStyle->SetOptStat(0);
  TCanvas* canvas1 = (TCanvas*)gROOT->FindObject("canvas1");
  if (canvas1) { canvas1->Delete(); }
  canvas1 = new TCanvas("canvas1","canvas1", 10,10, 800,800);
  anl->PlotHists(ymin, flogy, overFlow); 
  anl->PlotLegend(var);

  if(istyle==1){
    anl->PlotSgf(var);
  }else if(istyle>1){ 
    TH1F* sglscale =  (TH1F*) gROOT->FindObject("sglscale"); 
    if(sglscale){
      sglscale->Delete();
    }
    sglscale = (TH1F*) anl->getSglSample()->_hf1->Clone();
    sglscale->SetName("sglscale");
    sglscale->Scale(istyle);
    sglscale->Draw("hist same");
  }

  gPad->SetLogy(flogy);
  anl->PrintStat(cuts,debug);

  stringstream outPlotname;
  outPlotname << "Plot_" << var << "_" << cutName << ".pdf";
  canvas1->SaveAs(outPlotname.str().c_str());
  return 0;
}

Int_t plotvar( TmvaAnl* anl, const char* var, TCut cuts, Float_t scale, Int_t debug, Int_t istyle,
	       Float_t xmin, Float_t xmax, Float_t bw,Int_t flogy, Int_t flogx, Int_t overFlow,
	       const char hTitle[], const char xTitle[], const char yTitle[]){

  anl->setHframe(var,norm_hist*(cuts+cut_bkg),xmin,xmax,bw,hTitle,xTitle,yTitle); //need init hf1 for each sample
  anl->setSampleHists();
  anl->fillSampleHists(var,cuts,scale);

  Float_t ymin= 0.0;
  if (flogy) ymin= 1; // pow(10,flogy*(-1));

  gStyle->SetOptStat(0);  
  anl->PlotHists(ymin, flogy, overFlow); 
  anl->PlotLegend(var); 

  if(istyle==1){
    anl->PlotSgf(var);
  }else if(istyle>1){ 
    TH1F* sglscale =  (TH1F*) gROOT->FindObject("sglscale"); 
    if(sglscale){
      sglscale->Delete();
    }
    sglscale= (TH1F*) anl->getSglSample()->_hf1->Clone();
    sglscale->SetName("sglscale");
    sglscale->Scale(istyle);
    sglscale->Draw("hist same");
  }
 
  gPad->SetLogy(flogy);
  anl->PrintStat(cuts,debug);
  return 0;
}

//======================================================================================================================
//
Int_t cplotvar(TmvaAnl* anl, const char* var, TCut cuts, Float_t scale, Int_t debug, Int_t istyle,
	       Float_t xmin, Float_t xmax, Float_t bw,Int_t flogy, Int_t flogx,
	       const char hTitle[], const char xTitle[], const char yTitle[]){

  anl->setHframe(var,norm_hist*(cuts+cut_bkg),xmin,xmax,bw,hTitle,xTitle,yTitle); //need init hf1 for each sample
  anl->setSampleHists();
  anl->fillSampleHists(var,cuts,scale);
  anl->setsvplots(1);
  TCanvas*  plotCanvas = (TCanvas*)gROOT->FindObject("dualplot"); 
  if(plotCanvas) {plotCanvas->Delete(); }
    plotCanvas = new TCanvas("dualplot","dualplot",10,10,1350,500);
  plotCanvas->Divide(2,1);

  //  Float_t ymin= 0.0;
  Float_t ymin= pow(10,1*(-1));
  if (flogy) ymin= pow(10,flogy*(-1));

  gStyle->SetOptStat(0);  

  plotCanvas->cd(1);
  gPad->SetLogy(1);
  anl->PlotHists(ymin, flogy); 
  anl->PlotLegend(var); 
  if(istyle==1){
    anl->PlotSgf(var);
  }else if(istyle>1){ 
    TH1F* sglscale =  (TH1F*) gROOT->FindObject("sglscale"); 
    if(sglscale){
      sglscale->Delete();
    }
    sglscale= (TH1F*) anl->getSglSample()->_hf1->Clone();
    sglscale->SetName("sglscale");
    sglscale->Scale(istyle);
    sglscale->Draw("hist same");
  }

  plotCanvas->cd(2); 
  // hdata->SetMaximum(npmax*1.2);
  anl->getDataSample()->_hf1->SetMaximum(anl->getDataSample()->_hf1->GetMaximum()/1.2);
  anl->PlotHists(ymin, flogy); 
  anl->PlotLegend(var); 
  if(istyle==1){
    anl->PlotSgf(var);
  }else if(istyle>1){ 
    TH1F* sglscale =  (TH1F*) gROOT->FindObject("sglscale"); 
    if(sglscale){
      sglscale->Delete();
    }
    sglscale= (TH1F*) anl->getSglSample()->_hf1->Clone();
    sglscale->SetName("sglscale");
    sglscale->Scale(istyle);
    sglscale->Draw("hist same");
  }

  anl->setsvplots(0);

  anl->PrintStat(cuts,debug);

  stringstream ssoutname; 
  ssoutname << "cPlotVar_" <<  var << cuts.GetName() << ".png";
  plotCanvas->SaveAs(ssoutname.str().c_str());
  return 0;
}

//===========================================================================================
//
void TmvaAnl::PrintStat(TCut& cuts, Int_t debug){

  Float_t sum_bkg = 0;
  Float_t sum_err = 0;
  Float_t tot_err = 0;

  for(UInt_t ns=_vsamples.size()-1; ns>2; ns--){
    sum_bkg += _vsamples[ns]->npass;
    sum_err += _vsamples[ns]->npass_err*_vsamples[ns]->npass_err;
  }
  tot_err = sqrt(sum_err);

  if (debug>1){ 

    cout     << "|--------------------------------------------------------------------------------------------------------------------|"      << endl;
    cout     << "|-----------------------|--------------|------------------------|----------------------------|-------------| 95% CL, |"      << endl;
    cout     << "|         Cut           |    DATA      |       Total_bkg        |      Total_sgl (accpt)     | S/sqrt(S+B) | exp(fb) |"      << endl;
    cout     << "|-----------------------|--------------|------------------------|----------------------------|-------------|---------|"      << endl;
    //
  }
  if (debug>0){ 
    cout     << "|--------------------------------------------------------------------------------------------------------------------|"      << endl;

    cout        <<  "|  "    << setw(20) <<  cuts.GetName(); 
    printf(" |  %6.0f    |    %3.1f+/-%3.1f      |    %4.2f+/-%4.2f (%5.2f)    |    %4.2f    | %4.2f   |\n",
	    _data->npass, sum_bkg , tot_err, _sgl->npass, _sgl->npass_err, _sgl->accpt, _sgf1,  _sgf3);     // _data->npass, _bkg->npass , _bkg->npass_err, _sgl->npass, _sgl->npass_err, _sgl->accpt, _sgf1,  _sgf3); 
    cout     << "|--------------------------------------------------------------------------------------------------------------------|"      << endl;
  }
  if (debug>1){ 
    cout << ".!limit_calc  " << " " <<  _bkg->npass << " " <<_bkg->npass << " " << setprecision(5) << _bkg->npass_err  << " "
             <<  _sgl->accpt/100  << " " <<  0.15 * _sgl->accpt/100.  << " " << _lum << " " << 0.065*_lum << " " << _useGauss  << endl;

    for( UInt_t ns=0; ns < _vsamples.size(); ns++){
      cout << "TmvaAnl::fillSampleHist :: " << setprecision(5) <<  _vsamples[ns]->_hf1->GetName() <<  " , nevents = " <<  _vsamples[ns]->npass  << "+/-" << _vsamples[ns]->npass_err << endl;
    }
 
    cout << "eff X purity == sgf0 =  "  <<  _sgf0  << endl <<
		 "s/sqrt(s+b) ==  sgf1 = " << _sgf1 << endl <<
                 "s/sqrt(b)   ==  sgf2 = " << _sgf2 << endl << 
                 "95% CL, fb  ==  sgf3  = "<< _sgf3 << 
      endl;
  }
}

//======================================================================================================================
//
TGraphErrors* map2graph( const char* sgfName,const char* cutvar, map<Float_t,Float_t>& optmap, Float_t& best_cutval, Float_t& sgf_at_bestcut    ){

  std::string year2 = "2017";
  if (year2 == "1111") {
    year2 = "Run2";
  }
  TString date = getDateString();

  TCanvas* cgraph = (TCanvas*)gROOT->FindObject("cOptGraph"); 
  if(cgraph) {cgraph->Delete(); }
    cgraph = new TCanvas("c1","cOptGraph",10,10,700,700);
  Int_t npoints=  optmap.size();
  Float_t aclf[npoints];
  Float_t asgf[npoints];
  Float_t aclf_err[npoints];
  Float_t asgf_err[npoints];

  stringstream ssSgfText; 
  stringstream ssBestCutText; 
  ssSgfText.setf(ios::fixed); 
  ssSgfText.precision(3); 

  ssBestCutText.setf(ios::fixed); 
  ssBestCutText.precision(3); 
 
  stringstream xtitle;
  stringstream ytitle;
  stringstream graphtitle;

  TLatex* SgfText;
  TLatex* BestCutText ;

  ytitle << "Optimization criterion";
  xtitle << "lower cut on " << cutvar;


  if (strcmp(sgfName,"sgf0") == 0 ){
    ytitle.str("");
    ytitle << "eff#times#pi";
    ssSgfText     << "max("           << ytitle.str().c_str() << ") = " << setw(6) << sgf_at_bestcut;
    ssBestCutText << "Optimal cut = " << setw(6) << best_cutval;

  }else if (strcmp(sgfName,"sgf1") == 0 ){
    ytitle.str("");
    ytitle << "S/#sqrt{S+B} ";
    ssSgfText     << "max("           << ytitle.str().c_str() << ") = " << setw(6) << sgf_at_bestcut;
    ssBestCutText << "Optimal cut = " << setw(6) << best_cutval;
  }else if (strcmp(sgfName,"sgf2") == 0 ){
    ytitle.str("");
    ytitle << "95% CL, fb";
    ssSgfText     << "min(95% CL) = " << setw(6) << sgf_at_bestcut;
    ssBestCutText << "Optimal cut = " << setw(6) << best_cutval;

  }else if (strcmp(sgfName,"sgf3") == 0 ){
    ytitle.str("");
    ytitle << "S/#sqrt{B}";
    ssSgfText     << "max("           << ytitle.str().c_str() << ") = " << setw(6) << sgf_at_bestcut;
    ssBestCutText << "Optimal cut = " << setw(6) << best_cutval;
  }

  SgfText     = new TLatex(0.33,.20, ssSgfText.str().c_str());
  BestCutText = new TLatex(0.33,.15, ssBestCutText.str().c_str());
  if (strcmp(sgfName,"sgf2") == 0 ){
    SgfText->SetText(0.33,.80, ssSgfText.str().c_str());
    BestCutText->SetText(0.33,.75, ssBestCutText.str().c_str());
  }

  std::map<Float_t, Float_t>::iterator it = optmap.begin();
  int ip = 0;

  while (it != optmap.end()) {
    aclf[ip] = it->first;
    asgf[ip] = it->second;
    aclf_err[ip] = 0;
    asgf_err[ip] = 0;
    //cout << "ip/cutval/sgf = " << ip << "/" << aclf[ip] << "/" << asgf[ip] << endl;
  
    it++;
    ip++;
  }  
 
  stringstream sgfname;
  sgfname << sgfName;
 
  TGraphErrors* sgf;
 
  sgf = (TGraphErrors* )gROOT->FindObject(sgfname.str().c_str()); 
  if(sgf){
    sgf->Delete();
  }

  sgf = new TGraphErrors(npoints, aclf, asgf, aclf_err, asgf_err);
  sgf->SetName(sgfname.str().c_str());

  sgf->SetLineWidth(2);
  sgf->SetMarkerStyle(21);
  sgf->SetMarkerSize(0.8);
  sgf->SetTitle("Discriminant cut optimization");

  SgfText->SetNDC();
  SgfText->SetTextSize(0.035);
  SgfText->SetTextColor(1);
  SgfText->SetTextFont(22);
  SgfText->SetTextAlign(22);

  BestCutText->SetNDC();
  BestCutText->SetTextSize(0.035);
  BestCutText->SetTextColor(1);
  BestCutText->SetTextFont(22);
  BestCutText->SetTextAlign(22);
  BestCutText->Draw();

  sgf->GetYaxis()->SetTitle(ytitle.str().c_str());
  sgf->GetXaxis()->SetTitle(xtitle.str().c_str());
  // sgf->Draw("same p");
  sgf->Draw();
  //sgf->Fit("pol2","R","",600.,1700.);
  SgfText->Draw("same");
  BestCutText->Draw("same");
  
  stringstream splname;
  stringstream plotName;
  plotName << "plots/" << year2 << "/" << date << "/" << sgfName << "_" << cutvar;

  splname << plotName.str().c_str() << ".pdf";
  gPad->SaveAs(splname.str().c_str());
  splname.str("");

  return sgf;
}

//======================================================================================================================
//
Float_t TmvaAnl::optCutScan(const char* optParName, TCut basecuts, const char* cutvar, Float_t cutvar_min, Float_t cutvar_max, Float_t dsgf=0.0005, Float_t dstepw=0.0005, Int_t npoints=20){
  // sgf0 - eff*purity
  // sgf1 - s/sqrt(s+b)
  // sgf2 - 95% CL exp limit, fb
  // sgf3 - s/sqrt(b)
  _optmap.clear();
  //Do not save service histograms
  setsvplots(0);
  Float_t stepw   = (cutvar_max - cutvar_min)/npoints;
  Float_t sgf_curr = optParVal(optParName);
  Int_t nprobe = 0;
  stringstream cutvar_cut;
  Float_t cutval = cutvar_min;
  
  Float_t bestcut=cutvar_min ;
  Float_t bestcut_min = cutvar_min ;
  Float_t bestcut_max = cutvar_min ;
  Float_t bestsgf = 0;
  Float_t sgf_max = 0;
  Float_t sgf_min = 100000;

  while ( stepw > dstepw){
    nprobe=0;
    while ( nprobe < npoints ) {
      cutval = cutvar_min+ nprobe*stepw;
      cutvar_cut.str("");
      cutvar_cut << "(" << cutvar << " > " <<  cutval  << " ) " ;   
      setHframe("nPV",norm_hist*(basecuts+cut_bkg),0.0,10.0, 1.0);
      setSampleHists();
      fillSampleHists("nPV",basecuts+cutvar_cut.str().c_str(),1.0);
      sgf_curr = optParVal(optParName);
      _optmap.insert(std::make_pair(cutval, sgf_curr));
      if (  sgf_curr > sgf_max ){ sgf_max = sgf_curr; bestcut_max= cutval; }
      if (  sgf_curr < sgf_min ){ sgf_min = sgf_curr; bestcut_min= cutval; }
      nprobe++;
      cout << cutvar << " :: point/step/cutval/significance  = "  << nprobe  << "/" <<  stepw << "/" << cutval << "/" << sgf_curr  << endl;
    } 
    if (strcmp(optParName,"sgf2") == 0 ){
      bestcut = bestcut_min;
      bestsgf =  sgf_min;
    } else {
      bestcut = bestcut_max;
      bestsgf = sgf_max;
    }

    cutvar_min =  bestcut - stepw;
    cutvar_max =  bestcut + stepw;
    stepw=0.2*stepw;
    npoints= (cutvar_max - cutvar_min)/stepw;
     
  }
  //
  cout << "bestcut/sgf  = "  << bestcut << "/" <<  bestsgf << endl;
  _optgraph = map2graph(optParName, cutvar, _optmap, bestcut, bestsgf );
  //
  setsvplots(1);
  return bestcut;
}

//======================================================================================================================
//
Float_t TmvaAnl::optCutAlg1(const char* optParName, TCut basecuts, const char* cutvar, Float_t cutvar_min, Float_t cutvar_max, Float_t dsgf=0.0005, Float_t dstepw=0.0005, Int_t npoints= 100){
  //anl->OptimizeCut(cleanNAN,"BDT",-1, 1, 0.01);  
  //create sign monit  histograms  to hold test vals 
  // Int_t npoints = 100;

  _optmap.clear();
  // TH1F* sgf0hist = makeHist(optParName,cutvar,nbins,cutvar_min,cutvar_max);
  //
  //Do not save service histograms
  setsvplots(0);
  stringstream cutvar_cut;
  Float_t stepw   = 0.25*(cutvar_max - cutvar_min);
  Float_t cutval_right = cutvar_min+0.5*(cutvar_max - cutvar_min)+stepw ;
  Float_t cutval_left  = cutvar_min+0.5*(cutvar_max - cutvar_min)-stepw;
  Float_t cutval       =  cutval_left ;  

  Float_t  sgf_diff =  1.0;   
  Float_t  sgf_curr_left  = optParVal(optParName);
  Float_t  sgf_curr_right = optParVal(optParName);
  Float_t  sgf_curr = optParVal(optParName);
  Int_t nprobe = 0;
  while ( (sgf_diff > dsgf || sgf_diff == 0)  && nprobe < npoints && stepw > dstepw) { 
    //  while ( (sgf_diff > dsgf || sgf_diff == 0)  && nprobe < npoints){ 
    
    //check left point
    cutvar_cut.str("");
    cutvar_cut << "(" << cutvar << " > " <<  cutval_left << " ) " ;   
    setHframe("njets",norm_hist*(basecuts+cut_bkg),0.0,10.0, 1.0);
    setSampleHists();
    fillSampleHists("njets",basecuts+cutvar_cut.str().c_str(),1.0);
    sgf_curr_left=  optParVal(optParName);
  
    //check right point
    cutvar_cut.str("");
    cutvar_cut << "(" << cutvar << " > " <<  cutval_right << " ) " ;   
    setHframe("njets",norm_hist*(basecuts+cut_bkg),0.0,10.0, 1.0);
    setSampleHists();
    fillSampleHists("njets",basecuts+cutvar_cut.str().c_str(),1.0);
    sgf_curr_right= optParVal(optParName);
  
    if (sgf_curr_right > sgf_curr_left){    
      if (strcmp(optParName,"sgf3") == 0 ){
        sgf_curr = sgf_curr_left; 
        cutval_left-=stepw; 
        cutval_right  = cutval_left+stepw; 
	      cout << "slope to left!" << endl;
      } else {
        sgf_curr = sgf_curr_right; 
        cutval_right+=stepw; 
        cutval_left  = cutval_right-stepw; 
      }

    } else if (sgf_curr_right < sgf_curr_left) {
      if (strcmp(optParName,"sgf3") == 0 ){
        sgf_curr = sgf_curr_right; 
        cutval_right+=stepw; 
        cutval_left  = cutval_right-stepw; 
	      cout << "slope to right!" << endl;
      } else {
        sgf_curr= sgf_curr_left;
        cutval_left-=stepw;
        cutval_right=cutval_left+stepw;
      }

    } else {
      cutval_right+=stepw; 
      cutval_left-=stepw;
      //  stepw = stepw;
    }
  
    sgf_diff = fabs( optParVal(optParName) - sgf_curr);
  
    if ( _debug>1 ) {
      cout << "OptimizeCut:: nprobe/var/cut_left/cut_right/stepw///sgfleft/sgfright/sgf_diff  = " <<  
                 nprobe << "/"  <<  cutvar << "/" <<  cutval_left  << "/" <<  cutval_right  << "/" <<  
                 stepw << "/"  << sgf_curr_left << "/" << sgf_curr_right << "/" << sgf_diff <<
        endl; 
    }

    if (strcmp(optParName,"sgf3") == 0 ) {
      if ( optParVal(optParName) > sgf_curr ) stepw = 0.5*stepw; 
    } else {
      if ( optParVal(optParName) < sgf_curr ) stepw = 0.5*stepw;
    }

    //   cout << " nprobe/sgf_curr/sgf_diff/cutval_left/cutval_right = " << nprobe << "/" << sgf_curr  << "/" << sgf_diff  << "/" << cutval_left  << "/" << cutval_right << endl;
    nprobe++;
    if (strcmp(optParName,"sgf3") == 0 ){
      if ( sgf_curr_right  <  sgf_curr_left )   cutval = cutval_right ;
    } else {
      if ( sgf_curr_right >  sgf_curr_left )   cutval = cutval_right ;
    }
    //  _vsgf.push_back( sgf_curr );
    // _vcutval.push_back( cutval ); 
    _optmap.insert(std::make_pair(cutval, sgf_curr));

  }
  gStyle->SetOptStat(0); 
  PlotHists(0.0);
  PlotLegend("njets");
  PlotSgf("njets");
  
  _optgraph = map2graph(optParName,cutvar, _optmap, cutval, sgf_curr);
  return cutval;
}

//======================================================================================================================
//
Float_t TmvaAnl::optParVal(const char* optParName){
  // sgf0 - eff*purity
  // sgf1 - s/sqrt(s+b)
  // sgf2 - 95% CL exp limit, fb
  // sgf3 - s/sqrt(b)
  Float_t result = _sgf0;
  if (strcmp(optParName,"sgf0") ==0 ){
    result = _sgf0;
  }else if (strcmp(optParName,"sgf1") ==0 ){
    result = _sgf1;
  }else if (strcmp(optParName,"sgf2") ==0 ){
    result = _sgf2;
  }else if (strcmp(optParName,"sgf3") ==0 ){
    result = _sgf3;
  }
  return result;
}

//======================================================================================================================
//
TH1F* TmvaAnl::makeHist(const char* hname, const char* hvar, Int_t nbins, Float_t hvar_min, Float_t hvar_max){
  stringstream histname;
  TH1F* hist(0);
  histname << hname << _nstackplots;
  hist = (TH1F*)gROOT->FindObject(histname.str().c_str()); 
  if(hist){
    hist->Delete();
  }
  hist =  new TH1F(histname.str().c_str(), hvar, nbins, hvar_min, hvar_max);
  return hist;
}

//======================================================================================================================
//
void TmvaAnl::PlotHists(Float_t ymin, Int_t flogy, Int_t overFlow){
  bkg_hists.clear();
  //Stack backgrounds
  for(UInt_t ns=3; ns <  _vsamples.size(); ns++){
    bkg_hists.push_back(_vsamples[ns]->_hf1);
  }
  //
  Int_t imax = ArrangeHtms(flogy); 
  //cout << "# bkgs = " <<  bkg_hists.size() << endl;
  StackHtms(imax,ymin,flogy,overFlow);
  if (_fsaveplots) _nstackplots++;

}

//======================================================================================================================
//
Int_t TmvaAnl::ArrangeHtms(Int_t flogy){
  //Signal
  TH1F* hdata = _data->_hf1;
  TH1F* hbkg  = _bkg->_hf1;
  TH1F* hsgl  = _sgl->_hf1;

  hsgl->SetFillStyle(1001); // Updated from 3001
//   hsgl->SetFillColor(kGreen);
//   hsgl->SetLineColor(kGreen+2);
  hsgl->SetLineWidth(0); // was 1
  hsgl->SetLineStyle(1);

  //Bkg // Sum of all backgrounds
  hbkg->SetFillStyle(1001); // Updated from 3001
  hbkg->SetFillColor(0); //kRed-7
  //hbkg->SetMarkerStyle(20);
  //hbkg->SetMarkerColor(2);
  hbkg->SetLineColor(1);
  hbkg->SetLineWidth(1); // was 2
  hbkg->SetLineStyle(1);

  //Data
  //hdata->SetFillStyle(1001);
  hdata->SetFillColor(0);

  hdata->SetMarkerStyle(20);
  hdata->SetMarkerColor(1);
  hdata->SetMarkerSize(0.5); // was 0.6
  hdata->SetLineWidth(1); // MM
  hdata->SetLineColor(1);

  Float_t ymax[3];
  ymax[0]= hdata->GetMaximum();
  ymax[1]= hbkg->GetMaximum();
  ymax[2]= hsgl->GetMaximum();

  int imax=0;
  Float_t npmax=0;
  for(int j = 0; j<3; j++){
    if ( ymax[j] > npmax ) { 
      npmax=ymax[j]; 
      imax=j;
    }
  }

  if (flogy == 1) {
    hdata->SetMaximum(npmax*40); // 20 was good, Analysis note uses 40
  } else if (flogy == 0) {
    hdata->SetMaximum(npmax*2); // MM was 1.2 I changed that, added the flogy argument and the if statement. 1.45 was good, Analysis Note uses 3
  }
  return imax;
}

//======================================================================================================================
//
void  TmvaAnl::StackHtms(Int_t& imax, Float_t& ymin, Int_t flogy, Int_t overFlow){
  TH1F* hdata = _data->_hf1;
  TH1F* hbkg  = _bkg->_hf1;
  TH1F* hsgl  = _sgl->_hf1;

  stringstream sNameHstack;
  sNameHstack << "hstack_bkg_" << _nstackplots;
  stringstream sNameHSignal;
  sNameHSignal << "signal_histogram_" << _nstackplots;

  TH1F* sum_bkg_hists = (TH1F*)gROOT->FindObject("sum_bkg_hists");
  if (sum_bkg_hists) { sum_bkg_hists->Delete(); }
  sum_bkg_hists = (TH1F*)_hframe->Clone("sum_bkg_hists");

  TH1F* signal_hist = (TH1F*)gROOT->FindObject(sNameHSignal.str().c_str());
  if (signal_hist) { signal_hist->Delete(); }
  signal_hist = (TH1F*)_hframe->Clone(sNameHSignal.str().c_str());

  THStack*  hstack_bkg = (THStack*)gROOT->FindObject(sNameHstack.str().c_str()); 
  if( hstack_bkg){ hstack_bkg->Delete(); }
  hstack_bkg = new THStack(sNameHstack.str().c_str(),sNameHstack.str().c_str()); 
  hstack_bkg->SetTitle(hsgl->GetTitle());
  

  if (flogy) {
    ymin = 1.;
  }

  hstack_bkg->SetMinimum(ymin);
  hdata->SetMinimum(ymin);
  hsgl->SetMinimum(ymin);
  signal_hist->SetMinimum(ymin);


  Float_t ymax = _data->_hf1->GetMaximum();
  if ( imax == 1){
    ymax = _bkg->_hf1->GetMaximum();
  }else{
    ymax = _sgl->_hf1->GetMaximum();
  }

  if (overFlow == 1) {
    hdata->SetBinContent(hdata->GetNbinsX(), hdata->GetBinContent(hdata->GetNbinsX()) + hdata->GetBinContent(hdata->GetNbinsX()+1) );
  }

  for(UInt_t ih=0; ih< bkg_hists.size(); ih++){ 
    if (overFlow == 1) {
      bkg_hists[ih]->SetBinContent(bkg_hists[ih]->GetNbinsX(), bkg_hists[ih]->GetBinContent(bkg_hists[ih]->GetNbinsX()) + bkg_hists[ih]->GetBinContent(bkg_hists[ih]->GetNbinsX()+1));
    }
    sum_bkg_hists->Add(bkg_hists[ih]);
    hstack_bkg->Add(bkg_hists[ih]);
  } 

  hstack_bkg->Add(hsgl);
  sum_bkg_hists->Add(hsgl);

  signal_hist->Add(hsgl);

  bool plot_ratios = true;

  if (plot_ratios) {

    TRatioPlot* ratio_plot = (TRatioPlot*)gROOT->FindObject("ratio_plot"); // Ratio plot to go under the main plot
    if (ratio_plot) { ratio_plot->Delete(); }
    ratio_plot = new TRatioPlot(hdata, sum_bkg_hists);

    SetRatioPlotStyle(ratio_plot);

    TGraphAsymmErrors* errors_hist = (TGraphAsymmErrors*)gROOT->FindObject("errors_hist"); // Error bars for the sum of the backgrounds
    if (errors_hist) { errors_hist->Delete(); }
    errors_hist = new TGraphAsymmErrors((TH1F*)sum_bkg_hists->Clone("errors_hist"));

    errors_hist->SetFillStyle(3145);
    errors_hist->SetMarkerStyle(0);
    errors_hist->SetFillColor(kGray+2);
    errors_hist->SetLineColor(1);


    TGraphAsymmErrors* errors_on_ratio = (TGraphAsymmErrors*)gROOT->FindObject("errors_on_ratio"); // Error bars for the ratio plot
    if (errors_on_ratio) { errors_on_ratio->Delete(); }
    errors_on_ratio = new TGraphAsymmErrors((TH1F*)sum_bkg_hists->Clone("errors_on_ratio"));

    errors_on_ratio->SetFillStyle(1001);
    errors_on_ratio->SetMarkerStyle(0);
    errors_on_ratio->SetFillColor(kGray+1);

    for (int ibin=1; ibin<=sum_bkg_hists->GetNbinsX(); ibin++) {
      errors_on_ratio->SetPointY(ibin, 1.0);
      if (errors_hist->GetPointY(ibin) != 0.0) {
        errors_on_ratio->SetPointEYhigh(ibin, errors_hist->GetErrorYhigh(ibin)/errors_hist->GetPointY(ibin));
        errors_on_ratio->SetPointEYlow(ibin, errors_hist->GetErrorYlow(ibin)/errors_hist->GetPointY(ibin));
      } else {
        errors_on_ratio->SetPointEYhigh(ibin, 0.0);
        errors_on_ratio->SetPointEYlow(ibin, 0.0);
      }
    }

    TVirtualPad* lower = (TVirtualPad*)gROOT->FindObject("lower");
    if (lower) { lower->Delete(); }
    lower = ratio_plot->GetLowerPad();
    
    TVirtualPad* upper = (TVirtualPad*)gROOT->FindObject("upper");
    if (upper) { upper->Delete(); }
    upper = ratio_plot->GetUpperPad();

    lower->cd();
    errors_on_ratio->Draw("2");
    ratio_plot->GetLowerRefGraph()->Draw("p same");
    
    upper->cd();
    gPad->SetTicks(2,2);
    
    hdata->Draw("E1 a");
    hstack_bkg->Draw("A hist same");
    errors_hist->Draw("2 same");
    hdata->Draw("E1 same");  
    
    signal_hist->SetFillStyle(0);
    signal_hist->SetLineWidth(2);
    signal_hist->SetLineColor(kRed);
    if (!flogy) {
      signal_hist->Scale(10);
    } 
    signal_hist->Draw("hist same");

    gPad->RedrawAxis();
    gPad->SetLogy(flogy);

  } else {

    TGraphErrors* errors_hist = (TGraphErrors*)gROOT->FindObject("errors_hist"); // Error bars for the sum of the backgrounds
    if (errors_hist) { errors_hist->Delete(); }
    errors_hist = new TGraphErrors(sum_bkg_hists);

    errors_hist->SetFillStyle(3145);
    errors_hist->SetMarkerStyle(0);
    errors_hist->SetFillColor(kGray+1);
    errors_hist->SetLineColor(1);

    if(imax==0){
      hdata->Draw("E1");
      hstack_bkg->Draw("hist same");
      errors_hist->Draw("E2");
    }else if( imax == 1) {
      //strange but this combo does plot axis labeles accurately
      //  hstack_bkg->Draw();
      // hdata->Draw("E same");
      hdata->Draw("E1");
      hstack_bkg->Draw("hist same");
      errors_hist->Draw("E2");
    }else{
      hdata->Draw("E1");
      hstack_bkg->Draw("hist same");
      errors_hist->Draw("E2");
    }  
    //gPad->RedrawAxis();
    //errors_hist->Draw("2");
    hdata->Draw("E1 same");
  }
  
}

//======================================================================================================================
//
void TmvaAnl::PlotLegend(const char* var){

  TH1F* hdata = _data->_hf1;
  TH1F* hbkg  = _bkg->_hf1;
  TH1F* hsgl  = _sgl->_hf1;

  TH1F* hsgl_clone = (TH1F*)gROOT->FindObject("hsgl_clone");
  if (hsgl_clone) { hsgl_clone->Delete(); }
  hsgl_clone = (TH1F*)hsgl->Clone("hsgl_clone");
  hsgl_clone->SetFillStyle(0);
  hsgl_clone->SetLineWidth(2);
  hsgl_clone->SetLineColor(kRed);

  stringstream sNameLegend;
  sNameLegend << "Anl_legend_" << _nstackplots;
  TLegend* legend = (TLegend*)gROOT->FindObject(sNameLegend.str().c_str()); 
  if(legend) delete legend;

  //legend = new TLegend(.63, .58, .88, .88);
  legend = new TLegend(.29, .7, .9, .87); // 0.29, 0.73, 0.89, 0.87

  legend->SetName(sNameLegend.str().c_str());
  legend->SetFillColor(0);
  legend->SetLineColor(0);
  legend->SetNColumns(2);
  legend->SetFillStyle(0);
  legend->SetBorderSize(0);

  TLegend* cms_leg = (TLegend*)gROOT->FindObject("cms_leg");
  if (cms_leg) { cms_leg->Delete(); }
  TLegend* cms_leg2 = (TLegend*)gROOT->FindObject("cms_leg2");
  if (cms_leg2) { cms_leg2->Delete(); }

  cms_leg = new TLegend(0.11, 0.81, 0.24, 0.9);
  cms_leg2 = new TLegend(0.11, 0.78, 0.24, 0.83);

  cms_leg->SetFillStyle(0);
  cms_leg->SetFillColor(0);
  cms_leg->SetLineColor(0);
  cms_leg->SetBorderSize(0);
  cms_leg->SetTextFont(62);

  cms_leg2->SetFillStyle(0);
  cms_leg2->SetFillColor(0);
  cms_leg2->SetLineColor(0);
  cms_leg2->SetBorderSize(0);
  cms_leg2->SetTextFont(52);

  cms_leg->AddEntry((TObject*)0,"CMS", "");
  cms_leg2->AddEntry((TObject*)0,"Preliminary", "");

  TGraphErrors* err = (TGraphErrors*)gROOT->FindObject("err");
  if (err) { err->Delete(); }

  err = new TGraphErrors(hdata);
  err->SetFillStyle(3145);
  err->SetMarkerStyle(0);
  err->SetFillColor(kGray+2);
  err->SetLineColor(1);

  stringstream ss; ss.str("");
  ss.setf(ios::fixed);                            // set fixed format
  std::streamsize ss_cout_prec = ss.precision();  // store original precision
  ss.str("");

  if (_data->npass) {
    ss.precision(0);
    ss <<setw(4)<< "Data" <<" "<< setw(6)<< _data->npass;
    legend->AddEntry(hdata , ss.str().c_str());
  }
  if (_sgl->npass) {
    ss.str("");
    ss.precision(1);
    ss <<setw(4)<<  "SM(EW) WV"  <<" " << setw(6) <<_sgl->npass << "(" <<setw(4)  <<setprecision(2)<< _sgl->accpt << ")";
    legend->AddEntry(hsgl, ss.str().c_str(), "f");
  }

  float_t sum_bkg = 0.0;
  float_t sum_err = 0.0;


  for(UInt_t ns=_vsamples.size()-1; ns>2; ns--){
    sum_bkg += _vsamples[ns]->npass;
    sum_err += _vsamples[ns]->npass_err*_vsamples[ns]->npass_err;
  }
  float_t tot_err = sqrt(sum_err);

    //std::cout << "======================================================" << std::endl;
    //std::cout << " bkg npass = " << _bkg->npass << " / bkg err = " << _bkg->npass_err << std::endl;
    //std::cout << " Sum bkg = " << sum_bkg << " / tot err = " << tot_err << std::endl;
    //std::cout << "======================================================" << std::endl;
 
  if ( _bkg->npass) {
    ss.str("");
    ss.precision(1);
	  ss <<setw(4)<< "#Sigma bkg"   <<" " << setw(6) << sum_bkg << " #pm" <<setw(4)<<  tot_err; // setw(6) << _bkg->npass << "#pm" << setw(4) << _bkg->npass_err;
    legend->AddEntry( hbkg, ss.str().c_str(), "f");
  }

  for(UInt_t ns=_vsamples.size()-1; ns>2; ns--){
    if ( strcmp(_vsamples[ns]->_name,"ewkWV") ==0 ) {
      ss.str("");
      ss.precision(1);
      ss <<setw(4)<<  "SM EW WV"  <<" " << setw(6) <<  _vsamples[ns]->npass << " #pm " <<setw(4)<< _vsamples[ns]->npass_err;
      legend->AddEntry(_vsamples[ns]->_hf1, ss.str().c_str(), "f");
    } else if ( strcmp(_vsamples[ns]->_name,"Wjets") ==0 ) {
      ss.str("");
      ss.precision(1);
      ss <<setw(4)<<  "Wjets\t" <<" " << setw(6) <<  _vsamples[ns]->npass << " #pm " <<setw(4)<< _vsamples[ns]->npass_err;
      legend->AddEntry(_vsamples[ns]->_hf1, ss.str().c_str(), "f");
    } else if ( strcmp(_vsamples[ns]->_name,"Zjets") ==0 ) {
      ss.str("");
      ss.precision(1);
      ss <<setw(4)<<  "Zjets\t" <<" " << setw(6) <<  _vsamples[ns]->npass << " #pm " <<setw(4)<< _vsamples[ns]->npass_err;
      legend->AddEntry(_vsamples[ns]->_hf1, ss.str().c_str(), "f");
    } else if ( strcmp(_vsamples[ns]->_name,"DiBosons") ==0 ){
      ss.str("");
      ss.precision(1);
      ss <<setw(4)<<  "DiBosons\t" <<" " << setw(6) <<  _vsamples[ns]->npass << " #pm " <<setw(4)<< _vsamples[ns]->npass_err;
      legend->AddEntry(_vsamples[ns]->_hf1, ss.str().c_str(), "f");
    } else if ( strcmp(_vsamples[ns]->_name,"TT") ==0 ) {
      ss.str("");
      ss.precision(1);
      ss <<setw(4)<<  "tt\t" <<" " << setw(6) <<  _vsamples[ns]->npass << " #pm " <<setw(4)<< _vsamples[ns]->npass_err;
      legend->AddEntry(_vsamples[ns]->_hf1, ss.str().c_str(), "f");
    } else if ( strcmp(_vsamples[ns]->_name,"QCD") ==0 ) {
      ss.str("");
      ss.precision(1);
      ss <<setw(4)<<  "QCD\t" <<" " << setw(6) <<  _vsamples[ns]->npass << " #pm " <<setw(4)<< _vsamples[ns]->npass_err;
      legend->AddEntry(_vsamples[ns]->_hf1, ss.str().c_str(), "f");
    } else {;
    }
  }

  ss.str("");
  ss.precision(1);
  ss << setw(4) << "VBS EW (x10)";
  legend->AddEntry(hsgl_clone, ss.str().c_str(), "f");

  legend->AddEntry((TObject*)0, "", "");

  ss.str("");
  ss.precision(1);
  ss << setw(4) << "Stat. Unc.";
  legend->AddEntry(err, ss.str().c_str(), "f");
  
  legend->Draw();
  cms_leg->Draw();
  cms_leg2->Draw();
}

//======================================================================================================================
//
void TmvaAnl::PlotShapes(Float_t ymin, Int_t flogy, Int_t overFlow){
  bkg_hists.clear();
  //Stack backgrounds
  for(UInt_t ns=3; ns <  _vsamples.size(); ns++){
    bkg_hists.push_back(_vsamples[ns]->_hf1);
  }
  makeShapeComp(ymin, flogy, overFlow);
  if (_fsaveplots) _nstackplots++;
}

//======================================================================================================================
//
void TmvaAnl::makeShapeComp(Float_t ymin, Int_t flogy=0, Int_t overFlow=0) {
  // Plot the shape comparison graphs
  TH1F* hdata = _data->_hf1;
  TH1F* hbkg  = _bkg->_hf1;
  TH1F* hsgl  = _sgl->_hf1;

  Float_t norm = 1.;
  hdata->Scale(norm/hdata->Integral());
  hsgl->Scale(norm/hsgl->Integral());

  Float_t npmax = hdata->GetMaximum();

  if (flogy) {
    ymin = 0.1;
    hdata->SetMaximum(npmax*40);
  } else {
    hdata->SetMaximum(npmax*2);
  }

  hdata->SetLineColor(0);
  hdata->SetLineWidth(4);
  hdata->SetFillStyle(0);
  if (overFlow == 1) {
    hdata->SetBinContent(hdata->GetNbinsX(), hdata->GetBinContent(hdata->GetNbinsX()) + hdata->GetBinContent(hdata->GetNbinsX()+1) );
  }

  hsgl->SetLineColor(kRed);
  hsgl->SetLineWidth(4);
  hsgl->SetFillStyle(0);

  hdata->Draw("hist");

  for(UInt_t ih=0; ih< bkg_hists.size(); ih++){ 
    bkg_hists[ih]->Scale(norm/bkg_hists[ih]->Integral());
    bkg_hists[ih]->SetLineColor(bkg_hists[ih]->GetFillColor());
    if (overFlow == 1) {
      bkg_hists[ih]->SetBinContent(bkg_hists[ih]->GetNbinsX(), bkg_hists[ih]->GetBinContent(bkg_hists[ih]->GetNbinsX()) + bkg_hists[ih]->GetBinContent(bkg_hists[ih]->GetNbinsX()+1));
    }
    bkg_hists[ih]->SetLineWidth(4);
    bkg_hists[ih]->SetFillStyle(0);
    bkg_hists[ih]->Draw("hist same");
  }

  hsgl->Draw("hist same");
  gPad->RedrawAxis();
}

//======================================================================================================================
//
void TmvaAnl::PlotSgf(const char* var){
  stringstream ssSgf0Text; 
  stringstream ssSgf1Text; 
  stringstream ssSgf2Text; 
  stringstream ssSgf3Text; 
 
  ssSgf0Text.setf(ios::fixed); 
  ssSgf0Text.precision(2); 
  ssSgf0Text << "eff#times#pi = " << setw(6) << _sgf0;

  ssSgf1Text.setf(ios::fixed); 
  ssSgf1Text.precision(2); 
  ssSgf1Text << "S/#sqrt{S+B} = " << setw(6) << _sgf1;
 
  ssSgf2Text.setf(ios::fixed); 
  ssSgf2Text.precision(2); 
  ssSgf2Text << "95% CL, fb   = " << setw(6) << _sgf2;

  ssSgf3Text.setf(ios::fixed); 
  ssSgf3Text.precision(2); 
  ssSgf3Text << "S/#sqrt{B} = "   << setw(6) << _sgf3;

  TLatex* signif0;
  TLatex* signif1;
  TLatex* signif2;
  TLatex* signif3;

  if ( (strcmp(var,"f_dphi") != 0 ) ) {
    signif0 = new TLatex(0.73,.50, ssSgf0Text.str().c_str());
    signif1 = new TLatex(0.73,.45, ssSgf1Text.str().c_str());
    signif2 = new TLatex(0.73,.40, ssSgf2Text.str().c_str());
    signif3 = new TLatex(0.73,.35, ssSgf3Text.str().c_str());
  } else{
    signif0 = new TLatex(0.20,.50, ssSgf0Text.str().c_str());
    signif1 = new TLatex(0.20,.45, ssSgf1Text.str().c_str()); 
    signif2 = new TLatex(0.20,.40, ssSgf2Text.str().c_str());
    signif3 = new TLatex(0.20,.35, ssSgf3Text.str().c_str());
  }
  signif0->SetNDC();
  signif0->SetTextSize(0.040);
  signif0->SetTextColor(1);
  signif0->SetTextFont(22);
  signif0->SetTextAlign(22);
  signif0->Draw();

  signif1->SetNDC();
  signif1->SetTextSize(0.040);
  signif1->SetTextColor(1);
  signif1->SetTextFont(22);
  signif1->SetTextAlign(22);
  signif1->Draw();

  signif2->SetNDC();
  signif2->SetTextSize(0.040);
  signif2->SetTextColor(1);
  signif2->SetTextFont(22);
  signif2->SetTextAlign(22);
  signif2->Draw();

  signif3->SetNDC();
  signif3->SetTextSize(0.040);
  signif3->SetTextColor(1);
  signif3->SetTextFont(22);
  signif3->SetTextAlign(22);
  signif3->Draw();
}

//======================================================================================================================
//
void TmvaAnl::fillSampleHists(const char* var, TCut cuts, Float_t scale){
    Float_t scale_sgl=scale/_scale_sgl_tmva;
    Float_t scale_bkg=scale/_scale_bkg_tmva; // 2018 W+jets CR scale 0.78418 to whole bkg | 0.7501 ttbar CR scale to whole bkg
    //cout << "Applied to test sample: scale_sgl/scale_bkg = " <<  scale_sgl << "/" << scale_bkg << endl;  
    _sgl->fillSampleHist(var,cuts,scale_sgl);
    _bkg->fillSampleHist(var,cuts,scale_bkg);
    _data->fillSampleHist(var,cuts,scale);

    _sgf0 =0.0;
    _sgf1 =0.0;
    _sgf2 =0.0;
    _sgf3 =0.0;
    if (_sgl->npass+_bkg->npass){    
      _sgf1 =  (_sgl->npass)/sqrt(_sgl->npass+_bkg->npass); 
      _sgf0 =  _sgl->accpt*_sgl->npass/(_sgl->npass+_bkg->npass);   // eff*purity*100
    }
    if (_bkg->npass) _sgf3 =  (_sgl->npass)/sqrt(_bkg->npass);

    _useGauss=0;
    if ( _sgl->npass > 20 )  _useGauss=1;
    Double_t cl95res= 0.0;
    Double_t pfluc= 0.0;
    if (_bkg->npass) limit_calc( _bkg->npass, _bkg->npass , _bkg->npass_err, _sgl->accpt/100.,  0.15 * _sgl->accpt/100., _lum, 0.065*_lum , _useGauss,  cl95res, pfluc );
    _sgf2 =cl95res;
    //  cout << "LIMIT_CALC-RESULTS (expected, fb)/pfluc  " << _sgf2 << " / " << pfluc << endl;
    if (_debug ) cout << "_sgf0/_sgf1/_sgf2/_sgf3 = "  <<  _sgf0 << "/" << _sgf1 << "/" << _sgf2 << "/" << _sgf3 << endl;
    for( UInt_t ns=3; ns <  _vsamples.size(); ns++){
      _vsamples[ns]->fillSampleHist(var,cuts,scale_bkg);
    }
 }

//======================================================================================================================
//
void  TmvaAnl::setSampleHists(){
    for( UInt_t ns=0; ns <  _vsamples.size(); ns++){
      _vsamples[ns]->_hf1 = xCloneHist(_hframe,_vsamples[ns]->_name,_nstackplots);
      _vsamples[ns]->_hf1->SetFillStyle(1001); // Updated from 3001
      _vsamples[ns]->_hf1->SetFillColor(_vsamples[ns]->_scolor);
       setHistStyle(_vsamples[ns]->_hf1);
    }
}

//======================================================================================================================
//
void  TmvaAnl::setHframe(const char* var, TCut cuts, Float_t xmin, Float_t xmax, Float_t bw,
       const char hTitle[], const char xTitle[], const char yTitle[]){
    //
    _hframe = (TH1F*)gROOT->FindObject("hframe"); 
    if(_hframe) _hframe->Delete();
    if(bw == -1.){
      _hframe=0;       
      //Set range of the hframe template based on the background histogram
      
      (_bkg->getTestTree())->Draw(var, cuts, "goff");
      _hframe= (TH1F*) (_bkg->getTestTree())->GetHistogram()->Clone("hframe");
      Float_t ymax= _hframe->GetMaximum()/_scale_bkg_tmva;
      _hframe->Reset();
      _hframe->SetMaximum(1.3 * ymax);
      bw=_hframe->GetBinWidth(1);

    } else {
      //Use requested xmin,xmax
      Int_t   nbins=(xmax-xmin)/bw;    
      Float_t xmin_hist=xmin;
      if ( (strcmp(var,"floatNbjets") ==0 )|| (strcmp(var,"floatNgood") ==0 ) || (strcmp(var,"f_category") ==0 ) || (strcmp(var,"f_njets_pass") ==0 ) ){
        Float_t xmin_hist=xmin-0.5*bw;
      }
      Float_t xmax_hist=xmin_hist+nbins*bw;
      _hframe = new TH1F("hframe",var, nbins, xmin_hist, xmax_hist); //xmax_hist
    }

    stringstream Htitle;
    if ( strcmp(hTitle,"test") ==0 ) {
      Htitle    << var << ", " << cuts.GetTitle();  
    } else {
      Htitle   << hTitle; 
    }
    _hframe->SetTitle(Htitle.str().c_str());
  

    stringstream Xtitle; 
    if ( strcmp(xTitle,"test") ==0 ) {
      Xtitle   << var;
    } else {
      Xtitle   << xTitle;    
    }   
    _hframe->GetXaxis()->SetTitle(Xtitle.str().c_str());

    stringstream Ytitle; 
    if ( strcmp(yTitle,"test") == 0 )  {
      Ytitle   << "evt/" << bw;
    }else{
      Ytitle   << yTitle;    
    }   
    _hframe->GetYaxis()->SetTitle(Ytitle.str().c_str());

    //gStyle->SetErrorX(0);
    gStyle->SetLineScalePS(0.5);
    gStyle->SetHatchesSpacing(2.5);
    gStyle->SetHatchesLineWidth(1);

    setHistStyle(_hframe);
    //   cout << Htitle.str().c_str()<< "/" << Ytitle.str().c_str() << endl; 
    // return hframe;
 }

//======================================================================================================================
//
TH1F* xCloneHist(TH1F* hfr, const char* cloneName, Int_t cloneNum ){
  stringstream scloneName;
  scloneName << cloneName << "_" << cloneNum;
  return cloneHist(hfr,scloneName.str().c_str());
}

//======================================================================================================================
//
TH1F* cloneHist(TH1F* hframe, const char* histname){
    TH1F* newhist = (TH1F*)gROOT->FindObject(histname); 
    if(newhist){ newhist->Delete(); }
    newhist = (TH1F*) hframe->Clone(histname); 
    TCut allCuts         ("allCuts",     (lep_pt+fatjet_pt+wv_sr+btag_veto+vbs_jets_mjj+vbs_delta_eta+vbs_jets_pt));
//    TCut allCuts        ("allCuts",    (more+OneLpt+pfMETpuppi_m50e80+fatjet+mjw65to105+antitagVBF+MjjVBF800+detajjVBF4+ptjjVBF30+mlvj600+BCtype0gt1+ZeppWLlt3+ZeppWHlt3));
    return newhist;
}

//======================================================================================================================
//
void SetRatioPlotStyle(TRatioPlot* ratio) {
  std::vector<double> gridlines = {0.5, 1.0, 1.5};
  ratio->SetGridlines(gridlines);
  ratio->Draw("grid"); // took out hideup
  ratio->GetLowYaxis()->SetNdivisions(404);
  ratio->SetSeparationMargin(0);
  ratio->GetLowerRefYaxis()->CenterTitle();
  ratio->GetLowerRefYaxis()->SetTitleFont(42);
  ratio->GetLowerRefYaxis()->SetTitleSize(0.035);
  ratio->GetLowerRefYaxis()->SetTitleOffset(1.4);
  ratio->GetLowerRefYaxis()->SetLabelFont(42);
  ratio->GetLowerRefYaxis()->SetLabelSize(0.035);
  ratio->GetLowerRefYaxis()->SetTitle("Data/MC");
  ratio->GetLowerRefGraph()->SetMarkerStyle(20);
  ratio->GetLowerRefGraph()->SetMarkerSize(0.5);
  ratio->GetLowerRefGraph()->SetMinimum(0.1);
  ratio->GetLowerRefGraph()->SetMaximum(2);
}

//======================================================================================================================
//
void setHistStyle(TH1F* hist){
  hist->GetXaxis()->SetLabelFont(42);
  hist->GetXaxis()->SetLabelSize(0.035);
  hist->GetXaxis()->SetTitleSize(0.035);
  hist->GetXaxis()->SetTitleFont(42);
  hist->GetYaxis()->SetLabelFont(42);
  hist->GetYaxis()->SetLabelSize(0.035);
  hist->GetYaxis()->SetTitleSize(0.035);
  hist->GetYaxis()->SetNdivisions(210);
  hist->GetXaxis()->SetNdivisions(510);
  hist->GetYaxis()->SetTitleFont(42);
  hist->GetYaxis()->SetTitleOffset(1.4);
  hist->GetXaxis()->SetTitleOffset(1.2);
  hist->SetLineColor(1);
  hist->SetFillStyle(1001);
  hist->SetLineWidth(0); // was 2
}

//======================================================================================================================
//
void  TmvaAnl::setHistStyle(TH1F* hist){
  hist->GetXaxis()->SetLabelFont(42);
  hist->GetXaxis()->SetLabelSize(0.035);
  hist->GetXaxis()->SetTitleSize(0.035);
  hist->GetXaxis()->SetTitleFont(42);
  hist->GetYaxis()->SetLabelFont(42);
  hist->GetYaxis()->SetLabelSize(0.035);
  hist->GetYaxis()->SetTitleSize(0.035);
  hist->GetYaxis()->SetNdivisions(210);
  hist->GetXaxis()->SetNdivisions(510);
  hist->GetYaxis()->SetTitleFont(42);
  hist->GetYaxis()->SetTitleOffset(1.4);
  hist->GetXaxis()->SetTitleOffset(1.2);
  hist->SetLineColor(1);
  hist->SetFillStyle(1001); // Set the style for each background process
  hist->SetLineWidth(0); // was 1
}

//======================================================================================================================
//
void tmgui(){
    TMVA::TMVAGui( ssifname.str().c_str()  );
}


//======================================================================================================================
//
Int_t limit_calc(int ndata, double nbkg, double sbkg,  double acc,  double acc_error, double lumi, double lumi_error,  bool IfGauss,double& cl95res, double&  pfluc ) {
//   if( argc != 9 ) {
//     cout << "Insufficient data on command line" <<endl;
//     cout << "Use: limit_calc ndata nbkg sbkg acc sacc lumi slumi force_gauss(=0 for web page)"
// 	 << endl;
//     return(1);
//   }

//   // Set up the root style (empty backgrounds, not grey pattern)
//   gStyle->SetPadColor(0);
//   gStyle->SetCanvasColor(0);

//   // Read the command line parameters...
//   int ndata = atoi(argv[1]);
//   double nbkg = atof(argv[2]);
//   double sbkg = atof(argv[3]);
//   double acc = atof(argv[4]);
//   double acc_error = atof(argv[5]);
//   double lumi = atof(argv[6]);
//   double lumi_error = atof(argv[7]);
//   bool IfGauss = atol(argv[8]);

  // Do the cross section limit calculation.  Assume the signal acceptance
  // and luminosity uncertainties are uncorrelated so we can combine them
  // and call ConfidenceCmd.  sacc must be the absolute uncertainty on the
  // product of acceptance*lumi, and bkg, the absolute uncertainty on the
  // background.  We assume uncorrelated uncertainties.
  
  cl95res = CalcCL95(lumi, lumi_error, 
			    acc, acc_error, 
			    nbkg, sbkg, 
			    ndata, IfGauss);

  // and compute the probability that background flucuates to at least
  // the observed data.
  pfluc = Significance(ndata, nbkg, sbkg);

  // Produce the JPEG plot of the cross section pdf
  string fname = "limit_calc.pdf";
  final_likelihood->GetHistogram()->GetXaxis()->SetTitle("Cross Section, 1/Lumi units");
  final_likelihood->GetHistogram()->GetYaxis()->SetTitle("Probability density");
  //confidence_canvas->Update();
  // confidence_canvas->SaveAs(fname.c_str());

  // and write out the information to be picked up by the HTML writer.
  //  cout << "LIMIT_CALC-RESULTS " << cl95res << "  " << pfluc << "  "  << fname.c_str() << endl;
  
  return 0;
}

//======================================================================================================================
//
//TString getDateString() {
//  time_t now = time(0);
//  struct tm* timeStruct = localtime(&now);
//  std::stringstream date;
//  date << std::to_string(timeStruct->tm_mon+1) << "-" << std::to_string(timeStruct->tm_mday) 
//      << "-" << std::to_string(timeStruct->tm_year+1900);
//
//  return date.str().c_str();
//}
//
////======================================================================================================================
////
//TString getTimeString() {
//  time_t now = time(0);
//  struct tm* timeStruct = localtime(&now);
//  std::stringstream time_str;
//  time_str << std::to_string(timeStruct->tm_hour) << "-" << std::to_string(timeStruct->tm_min); 
//
//  return time_str.str().c_str();
//}

//======================================================================================================================
//
Int_t makeNewDirectory(TString path) {
  return gSystem->Exec("mkdir "+path);
}

//======================================================================================================================
//
void genPlots(TmvaAnl *anl, TCut cuts = "", TString name = "test", TString folder = "datasets/plot_args", 
    TString file_name = "training_methods", const char plot_style = 'r') {
  anl->setsvplots(1);

  std::cout << "\nPlot style: " << plot_style << std::endl;
  TString file = folder + "/" + file_name + ".xml";
  TString date = getDateString();
  TString time_str = getTimeString();

  stringstream plot_title;
  stringstream saved_plot_name;

  plot_title << g_lum << " fb^{-1} (13 TeV)";
  std::string year2 = "2017";
  if (year2 == "1111") {
    year2 = "Run2";
  }

  TString plt = "plots/";
  TString path = plt+year2.c_str()+"/"+date;
  Int_t dir = makeNewDirectory(path);
  (dir == 0) ? std::cout << "New folder created to store plots: plots/" << year2 << "/" << date << std::endl :
          std::cout << "\nERROR: Error in -> Function -> genPlots: Plot folder can't be created" << std::endl;

  TString title_str = plot_title.str().c_str();
  TCanvas* cp1 = new TCanvas("cp1","cp1",10,10,900,900);
  cp1->Clear();
  saved_plot_name << "plots/" << year2 << "/" << date << "/" << year2 << "_plot_set_" << time_str << ".pdf[";
  cp1->Print(saved_plot_name.str().c_str());
  saved_plot_name.str("");
  saved_plot_name << "plots/" << year2 << "/" << date << "/" << year2 << "_plot_set_" << time_str << ".pdf";

  TDOMParser* parser = new TDOMParser();
  parser->SetValidate(false);
  parser->ParseFile(file);
  auto* node = parser->GetXMLDocument()->GetRootNode();
  node = node->GetChildren()->GetNextNode();
  TList* attr_list;

  switch (plot_style) {
    case 'r': { // normal ratio plots
      for (; node; node = node->GetNextNode()) {
        if (node->GetNodeType() == TXMLNode::kXMLElementNode) {
          if (node->HasAttributes()) {
            attr_list = node->GetAttributes();
            plotvar(anl, ((TXMLAttr*)attr_list->At(1))->GetValue(), cuts,
                    (Float_t)stof(((TXMLAttr*)attr_list->At(3))->GetValue()),
                    (Int_t)stoi(((TXMLAttr*)attr_list->At(4))->GetValue()),
                    (Int_t)stoi(((TXMLAttr*)attr_list->At(5))->GetValue()),
                    (Float_t)stof(((TXMLAttr*)attr_list->At(6))->GetValue()),
                    (Float_t)stof(((TXMLAttr*)attr_list->At(7))->GetValue()),
                    (Float_t)stof(((TXMLAttr*)attr_list->At(8))->GetValue()),
                    (Int_t)stoi(((TXMLAttr*)attr_list->At(9))->GetValue()),
                    (Int_t)stoi(((TXMLAttr*)attr_list->At(10))->GetValue()),
                    (Int_t)stoi(((TXMLAttr*)attr_list->At(11))->GetValue()),
                    title_str,
                    ((TXMLAttr*)attr_list->At(13))->GetValue(),
                    ((TXMLAttr*)attr_list->At(14))->GetValue());
            //saved_plot_name << "plots/" << year2 << "/" << date << "/" << ((TXMLAttr*)attr_list->At(1))->GetValue() << "_" << name << "_plot.pdf";
            cp1->Print(saved_plot_name.str().c_str());
            //saved_plot_name.str("");
            cp1->Clear();
          }
        }
      }
      break;
    }
    case 's': { // shape comparisons
      for (; node; node = node->GetNextNode()) {
        if (node->GetNodeType() == TXMLNode::kXMLElementNode) {
          if (node->HasAttributes()) {
            attr_list = node->GetAttributes();
            plotShapeComp(anl, ((TXMLAttr*)attr_list->At(1))->GetValue(), cuts,
                    (Float_t)stof(((TXMLAttr*)attr_list->At(3))->GetValue()),
                    (Int_t)stoi(((TXMLAttr*)attr_list->At(4))->GetValue()),
                    (Int_t)stoi(((TXMLAttr*)attr_list->At(5))->GetValue()),
                    (Float_t)stof(((TXMLAttr*)attr_list->At(6))->GetValue()),
                    (Float_t)stof(((TXMLAttr*)attr_list->At(7))->GetValue()),
                    (Float_t)stof(((TXMLAttr*)attr_list->At(8))->GetValue()),
                    (Int_t)stoi(((TXMLAttr*)attr_list->At(9))->GetValue()),
                    (Int_t)stoi(((TXMLAttr*)attr_list->At(10))->GetValue()),
                    (Int_t)stoi(((TXMLAttr*)attr_list->At(11))->GetValue()),
                    title_str,
                    ((TXMLAttr*)attr_list->At(13))->GetValue(),
                    ((TXMLAttr*)attr_list->At(14))->GetValue());
            //saved_plot_name << "plots/" << year2 << "/" << date << "/" << ((TXMLAttr*)attr_list->At(1))->GetValue() << "_" << name << "_shape.pdf";
            cp1->SaveAs(saved_plot_name.str().c_str());
            //saved_plot_name.str("");
            cp1->Clear();
          }
        }
      }
      break;
    }
    default:
      std::cout << "\nERROR: Error in -> Function -> genPlots: Issue with plot_style selection. Please use a valid option" << std::endl;
      std::cout << "  Valid options include: \'r\' : for standard ratio plots - \'s\' : for shape comparison plots" << std::endl;
      break;
  }

  saved_plot_name.str("");
  saved_plot_name << "plots/" << year2 << "/" << date << "/" << year2 << "_plot_set_" << time_str << ".pdf]";
  cp1->Print(saved_plot_name.str().c_str());

  anl->setsvplots(0);
}

//======================================================================================================================
// 
void cplots(TmvaAnl* anl, TCut cuts="", TString CutName="test"){
  anl->setsvplots(1);
gStyle->SetLineScalePS(0.5);
  TString date = getDateString();
  TString time_str = getTimeString();
  stringstream out_f_name;

  std::string year2 = "2017";
  std::cout << "year = " << year2 << std::endl;
  if (year2 == "1111") {
    year2 = "Run2";
  }

  stringstream plt_title;
  plt_title << year2 <<" VBS, " << g_lum << " fb^{-1}";
  std::string s = plt_title.str();
  const char* title_str = s.c_str();
  // title: VBS (WV), 35.9fb^{-1}

  TString plt = "plots/";
  TString path = plt+year2.c_str()+"/"+date;
  Int_t dir = makeNewDirectory(path);
  (dir == 0) ? std::cout << "New folder created to store plots: plots/" << year2 << "/" << date << std::endl :
          std::cout << "\nERROR: Error in -> Function -> cPlots: Plot folder can't be created" << std::endl;

  TDOMParser* parser = new TDOMParser();
  parser->SetValidate(false);
//  parser->ParseFile("datasets/plot_args/c_s_plot_attrs.xml");
parser->ParseFile("datasets/plot_args/MVA_variables.xml");
  auto* node = parser->GetXMLDocument()->GetRootNode();
  node = node->GetChildren()->GetNextNode();

  TList* attr_list = node->GetAttributes();

  TCanvas* cp1 = new TCanvas("cp1", "cp1", 10,10,1200,1200);
  
  out_f_name << "plots/" << year2 << "/" << date << "/" << year2 << "_multiplot_set_" << time_str << ".pdf[";
  cp1->SaveAs(out_f_name.str().c_str());
  cp1->Clear();
  cp1->Divide(3,3);

  out_f_name.str("");
  out_f_name << "plots/" << year2 << "/" << date << "/" << year2 << "_multiplot_set_" << time_str << ".pdf";

  Int_t iter = 1;
  char plot_style = 'r';

  switch (plot_style) {
    case 'r': {
      for (; node; node = node->GetNextNode()) {
        if (node->GetNodeType() == TXMLNode::kXMLElementNode && node->HasAttributes()) {
          cp1->cd(iter);
          attr_list = node->GetAttributes();
          plotvar(anl, ((TXMLAttr*)attr_list->At(1))->GetValue(), cuts,
                  (Float_t)stof(((TXMLAttr*)attr_list->At(3))->GetValue()),
                  (Int_t)stoi(((TXMLAttr*)attr_list->At(4))->GetValue()),
                  (Int_t)stoi(((TXMLAttr*)attr_list->At(5))->GetValue()),
                  (Float_t)stof(((TXMLAttr*)attr_list->At(6))->GetValue()),
                  (Float_t)stof(((TXMLAttr*)attr_list->At(7))->GetValue()),
                  (Float_t)stof(((TXMLAttr*)attr_list->At(8))->GetValue()),
                  (Int_t)stoi(((TXMLAttr*)attr_list->At(9))->GetValue()),
                  (Int_t)stoi(((TXMLAttr*)attr_list->At(10))->GetValue()),
                  (Int_t)stoi(((TXMLAttr*)attr_list->At(11))->GetValue()),
                  title_str,
                  ((TXMLAttr*)attr_list->At(13))->GetValue(),
                  ((TXMLAttr*)attr_list->At(14))->GetValue());
          if (iter == 9) {
            cp1->SaveAs(out_f_name.str().c_str());
            cp1->Clear();
            cp1->Divide(3,3);
            iter = 1;
          } else if (!node->GetNextNode()->GetNextNode()) {
            cp1->SaveAs(out_f_name.str().c_str());
          } else {
            ++iter;
          }
        }
      }
      break;
    }
    case 's': {
      for (; node; node = node->GetNextNode()) {
        if (node->GetNodeType() == TXMLNode::kXMLElementNode && node->HasAttributes()) {
          cp1->cd(iter);
          attr_list = node->GetAttributes();
          plotShapeComp(anl, ((TXMLAttr*)attr_list->At(1))->GetValue(), cuts,
                        (Float_t)stof(((TXMLAttr*)attr_list->At(3))->GetValue()),
                        (Int_t)stoi(((TXMLAttr*)attr_list->At(4))->GetValue()),
                        (Int_t)stoi(((TXMLAttr*)attr_list->At(5))->GetValue()),
                        (Float_t)stof(((TXMLAttr*)attr_list->At(6))->GetValue()),
                        (Float_t)stof(((TXMLAttr*)attr_list->At(7))->GetValue()),
                        (Float_t)stof(((TXMLAttr*)attr_list->At(8))->GetValue()),
                        (Int_t)stoi(((TXMLAttr*)attr_list->At(9))->GetValue()),
                        (Int_t)stoi(((TXMLAttr*)attr_list->At(10))->GetValue()),
                        (Int_t)stoi(((TXMLAttr*)attr_list->At(11))->GetValue()),
                        title_str,
                        ((TXMLAttr*)attr_list->At(13))->GetValue(),
                        ((TXMLAttr*)attr_list->At(14))->GetValue());
          if (iter == 9) {
            cp1->Print(out_f_name.str().c_str());
            cp1->Clear();
            cp1->Divide(3,3);
            iter = 1;
          } else if (!node->GetNextNode()->GetNextNode()) {
            cp1->Print(out_f_name.str().c_str());
          } else {
           ++iter;
          }
        }
      }
      break;
    }
    default: 
      std::cout << "Error in genMultiPlot (cplots) switch" << std::endl; 
      break;
  }
  out_f_name.str("");
  out_f_name << "plots/" << year2 << "/" << date << "/" << year2 << "_multiplot_set_" << time_str << ".pdf]";
  cp1->SaveAs(out_f_name.str().c_str());

  anl->setsvplots(0);
}

//======================================================================================================================
//
void shapePlots(TmvaAnl* anl, TCut cuts="", TString CutName="test") {
  anl->setsvplots(1);

  TString date = getDateString();
  stringstream shapeFname;
  stringstream var;
  stringstream plt_title;
  plt_title << "VBS (WV), " << g_lum << " fb^{-1} (13TeV)";
  std::string s = plt_title.str();
  const char* title_str = s.c_str();
  std::string year2 = "2017";
  if (year2 == "1111") {
    year2 = "Run2";
  }
  std::cout << "cuts = " << cuts << " Lumi = " << g_lum << std::endl;
  std::cout << "" << std::endl;

  TString plt = "plots/";
  TString path = plt+year2.c_str()+"/"+date;
  Int_t dir = makeNewDirectory(path);
  (dir == 0) ? std::cout << "New folder created to store plots: plots/" << year2 << "/" << date << std::endl :
          std::cout << "\nERROR: Error in -> Function -> shapePlots: Plot folder can't be created" << std::endl;

  // Create the XML parser
  TDOMParser* parser = new TDOMParser();
  parser->SetValidate(false);
  parser->ParseFile("datasets/plot_args/c_s_plot_attrs.xml");
  auto* node = parser->GetXMLDocument()->GetRootNode();
  // Drill down into the actual child nodes that hold the plot attributes
  // Shouldn't need to change unless the structure of the XML file changes
  node = node->GetChildren()->GetNextNode()->GetChildren()->GetNextNode();
  if (node->GetNodeType() == TXMLNode::kXMLCommentNode) {
    node = node->GetNextNode()->GetNextNode();
  }
  TList* attr_list = node->GetAttributes();

  for (Int_t iter = 1; iter <= 4; iter++) {
    TCanvas* cp1 = (TCanvas*)gROOT->FindObject("cp1"); 
    if(cp1) { cp1->Delete(); }
    cp1 = new TCanvas("cp1","cp1",10,10,1200,1200);
    cp1->Divide(3,3);

    for (Int_t jter = 1; jter <= 9; jter++) {
      cp1->cd(jter);
      if (node->GetNodeType() == TXMLNode::kXMLElementNode) {
        plotShapeComp(anl, ((TXMLAttr*)attr_list->At(1))->GetValue(), cuts, 
                        (Float_t)stof(((TXMLAttr*)attr_list->At(3))->GetValue()), 
                        (Int_t)stoi(((TXMLAttr*)attr_list->At(4))->GetValue()),
                        (Int_t)stoi(((TXMLAttr*)attr_list->At(5))->GetValue()),
                        (Float_t)stof(((TXMLAttr*)attr_list->At(6))->GetValue()),
                        (Float_t)stof(((TXMLAttr*)attr_list->At(7))->GetValue()),
                        (Float_t)stof(((TXMLAttr*)attr_list->At(8))->GetValue()),
                        (Int_t)stoi(((TXMLAttr*)attr_list->At(9))->GetValue()),
                        (Int_t)stoi(((TXMLAttr*)attr_list->At(10))->GetValue()),
                        (Int_t)stoi(((TXMLAttr*)attr_list->At(11))->GetValue()),
                        title_str,
                        ((TXMLAttr*)attr_list->At(13))->GetValue(),
                        ((TXMLAttr*)attr_list->At(14))->GetValue());
      } else if (node->GetNodeType() == TXMLNode::kXMLCommentNode) {
        jter--;
        node = node->GetNextNode()->GetNextNode();
        attr_list = node->GetAttributes();
        continue;
      }
      if (strcmp(node->GetNodeName(),"end") == 0) {
        break;
      } else {
        node = node->GetNextNode()->GetNextNode();
        attr_list = node->GetAttributes();
      }
    }

    shapeFname << "plots/" << year2 << "/" << date << "/s" << iter << "_" << year2 << "_" << CutName << ".pdf";
    cp1->SaveAs(shapeFname.str().c_str());
    shapeFname.str("");
    //shapeFname << "plots/2017/s1_2017"  << "_" << CutName << ".root";
    //cp1->SaveAs(shapeFname.str().c_str()); 
    //shapeFname.str("");
  }
  anl->setsvplots(0);
}
   
//======================================================================================================================
//
TCut splitCuts( const char* strcuts){
  cout << strcuts << endl;
  TCut rootcut = TCut("cut", (TCut) strcuts);
  return rootcut;
}

//======================================================================================================================
//
void  printCutflow(TmvaAnl* anl, const char* var, const char*  flowname, TCut basecuts, Float_t scale, Int_t debug, Int_t istyle,
	       Float_t xmin, Float_t xmax, Float_t bw,Int_t flogy, Int_t flogx,
	       const char hTitle[], const char xTitle[], const char yTitle[]) {
//=========================================
//printCutflow(anl, "mass_lvj_type0_PuppiAK8", "paperCuts", dummy,  1.0, 1, 0,  0.0,  2500., 50,    1, 0,  "VBS (WV), 35.9 fb^{-1}", "mass_lvj_type0_PuppiAK8 ( M_{WW} ) (GeV)", "Events/bin");
  TCut Cuts;
  stringstream CanvasName;
  stringstream hist_title;

  anl->setsvplots(1);

  TCanvas* c1= (TCanvas*)gROOT->FindObject("c1"); 
  if(c1) delete c1;
  c1=new TCanvas("c1", "vbsflow", 1,0,800,600);

   // select postscript output type
   // type = 111   portrait  ps
   // type = 112   landscape ps
   // type = 113   eps
  Int_t type = 112;

  stringstream OutPdfFname;
  
  cout     << "|--------------------------------------------------------------------------------------------------------------------|"      << endl;
  cout     << "|-----------------------|--------------|------------------------|----------------------------|-------------| 95% CL, |"      << endl;
  cout     << "|         Cut           |    DATA      |       Total_bkg        |      Total_sgl (accpt)     | S/sqrt(S+B) | exp(fb) |"      << endl;
  cout     << "|-----------------------|--------------|------------------------|----------------------------|-------------|---------|"      << endl;
 
  anl->cuts.Clear();
  anl->cuts  <<
    category_selection <<
    lep_pt <<
    lep_eta <<
    fatjet_pt <<
    fatjet_eta <<
    fatjet_tau21 <<
    met_pt <<
    //btag_veto <<         // this has to be commented out when doing top cr
    vbs_jets_mjj <<
    vbs_delta_eta <<
    vbs_jets_pt <<
    //wv_cr_vjets
    wv_cr_top <<
    wv_sr                // needed for both SR and top CR
  ;
  CanvasName <<  flowname << " : " << anl->cuts.Cut(0).GetName();
  TCut currentCut;
  for (Int_t i=0; i<=anl->cuts.GetLast(); ++i){
    currentCut=anl->cuts.Cut(i);
    Cuts=Cuts + currentCut;
    c1->cd();
    CanvasName << " + " << currentCut.GetName();
    hist_title << "VBS (WV), " << g_lum << "fb^{-1}, " << currentCut.GetName();
    plotvar(anl, var, Cuts, scale, -1, istyle, xmin, xmax, bw, flogy, flogx, 1, hist_title.str().c_str(), xTitle, yTitle);
    anl->PrintStat(currentCut, debug);
	  c1->Update();
    if (i == 0) {
      OutPdfFname << "docs/cutflows/Cutflow_" << var << "_" << flowname << ".pdf(";
      c1->Print(OutPdfFname.str().c_str(), "pdf");
      OutPdfFname.str("");
    } else if (i == anl->cuts.GetLast()) {
      OutPdfFname << "docs/cutflows/Cutflow_" << var << "_" << flowname << ".pdf)";
      c1->Print(OutPdfFname.str().c_str(), "pdf");
      OutPdfFname.str("");
    } else {
      OutPdfFname << "docs/cutflows/Cutflow_" << var << "_" << flowname << ".pdf";
      c1->Print(OutPdfFname.str().c_str(), "pdf");
      OutPdfFname.str("");
    }
    hist_title.str("");
  }//End cuts loop
  anl->setsvplots(0);
}
