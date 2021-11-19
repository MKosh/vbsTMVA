// Purpose: VBS TMVA classifier
// (works with HZZ4LeptonsAnalysisReduced trees)   
// Created: Nov 2017, Sergey Uzunyan (serguei@nicadd.niu.edu)
////////////////////////////////////////////////////////////////////////
/**********************************************************************************
 * Project   : TMVA - a ROOT-integrated toolkit for multivariate data analysis    *
 * Package   : TMVA                                                               *
 * Root Macro: TMVAClassification                                                 *
 *                                                                                *
 * This macro provides examples for the training and testing of the               *
 * TMVA classifiers.                                                              *
 *                                                                                *
 * As input data is used a toy-MC sample consisting of four Gaussian-distributed  *
 * and linearly correlated input variables.                                       *
 *                                                                                *
 * The methods to be used can be switched on and off by means of booleans, or     *
 * via the prompt command, for example:                                           *
 * Batch production                                                               *
 *    root -b -q ./vbsTMVAClassification.cc\(\"vbs_ww\",\"BDT\"\)                 *
 * This will call TVA gui after training                                          *
 *    root -l ./vbsTMVAClassification.cc\(\"vbs_ww\",\"BDT\"\)                    *
 *                                                                                *
 * (note that the backslashes are mandatory)                                      *
 * If no method given, a default set of classifiers is used.                      *
 *                                                                                *
 * The output file "TMVA.root" can be analysed with the use of dedicated          *
 * macros (simply say: root -l <macro.cc>), which can be conveniently              *
 * invoked through a GUI that will appear at the end of the run of this macro.    *
 * Launch the GUI via the command:                                                *
 *                                                                                *
 *    root -l ./TMVAGui.cc                                                         *
 *                                                                                *
 **********************************************************************************/
#include "vector"
#include "vbsTMVA.hpp"
#include "vbsSamples.hpp"
using namespace TMVA;
//

int vbsTMVAClassification(TString sname="vbs_ww", TString myMethodList = "" )
{
   ROOT::EnableImplicitMT();
   // The explicit loading of the shared libTMVA is done in TMVAlogon.cc, defined in .rootrc
   // if you use your private .rootrc, or run from a different directory, please copy the
   // corresponding lines from .rootrc

   // Methods to be processed can be given as an argument; use format:
   //
   //     mylinux~> root -l TMVAClassification.cc\(\"myMethod1,myMethod2,myMethod3\"\)

   //---------------------------------------------------------------
   // This loads the library
   TMVA::Tools::Instance();

   // Default MVA methods to be trained + tested
   std::map<std::string,int> Use;

   // Cut optimisation
   Use["Cuts"]            = 1;
   Use["CutsD"]           = 1;
   Use["CutsPCA"]         = 0;
   Use["CutsGA"]          = 0;
   Use["CutsSA"]          = 0;
   //
   // 1-dimensional likelihood ("naive Bayes estimator")
   Use["Likelihood"]      = 1;
   Use["LikelihoodD"]     = 0; // the "D" extension indicates decorrelated input variables (see option strings)
   Use["LikelihoodPCA"]   = 1; // the "PCA" extension indicates PCA-transformed input variables (see option strings)
   Use["LikelihoodKDE"]   = 0;
   Use["LikelihoodMIX"]   = 0;
   //
   // Mutidimensional likelihood and Nearest-Neighbour methods
   Use["PDERS"]           = 1;
   Use["PDERSD"]          = 0;
   Use["PDERSPCA"]        = 0;
   Use["PDEFoam"]         = 1;
   Use["PDEFoamBoost"]    = 0; // uses generalised MVA method boosting
   Use["KNN"]             = 1; // k-nearest neighbour method
   //
   // Linear Discriminant Analysis
   Use["LD"]              = 1; // Linear Discriminant identical to Fisher
   Use["Fisher"]          = 0;
   Use["FisherG"]         = 0;
   Use["BoostedFisher"]   = 0; // uses generalised MVA method boosting
   Use["HMatrix"]         = 0;
   //
   // Function Discriminant analysis
   Use["FDA_GA"]          = 1; // minimisation of user-defined function using Genetics Algorithm
   Use["FDA_SA"]          = 0;
   Use["FDA_MC"]          = 0;
   Use["FDA_MT"]          = 0;
   Use["FDA_GAMT"]        = 0;
   Use["FDA_MCMT"]        = 0;
   //
   // Neural Networks (all are feed-forward Multilayer Perceptrons)
   Use["MLP"]             = 0; // Recommended ANN
   Use["MLPBFGS"]         = 0; // Recommended ANN with optional training method
   Use["MLPBNN"]          = 1; // Recommended ANN with BFGS training method and bayesian regulator
   Use["CFMlpANN"]        = 0; // Depreciated ANN from ALEPH
   Use["TMlpANN"]         = 0; // ROOT's own ANN
   Use["DNN_GPU"]         = 0; // CUDA-accelerated DNN training.
   Use["DNN_CPU"]         = 0; // Multi-core accelerated DNN.
   //
   // Support Vector Machine
   Use["SVM"]             = 1;
   //
   // Boosted Decision Trees
   Use["BDT"]             = 1; // uses Adaptive Boost
   Use["BDT1"]            = 1; // MM added
   Use["BDT2"]            = 1; // MM added
   Use["BDTG"]            = 0; // uses Gradient Boost
   Use["BDTB"]            = 0; // uses Bagging
   Use["BDTD"]            = 0; // decorrelation + Adaptive Boost
   Use["BDTF"]            = 0; // allow usage of fisher discriminant for node splitting
   //
   // Friedman's RuleFit method, ie, an optimised series of cuts ("rules")
   Use["RuleFit"]         = 1;
   // ---------------------------------------------------------------

   std::cout << std::endl;
   std::cout << "==> Start TMVAClassification" << std::endl;

   // Select methods (don't look at this code - not of interest)
   if (myMethodList != "") {
      for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;

      std::vector<TString> mlist = TMVA::gTools().SplitString( myMethodList, ',' );
      for (UInt_t i=0; i<mlist.size(); i++) {
         std::string regMethod(mlist[i]);

         if (Use.find(regMethod) == Use.end()) {
            std::cout << "Method \"" << regMethod << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
            for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) std::cout << it->first << " ";
            std::cout << std::endl;
            return 1;
         }
         Use[regMethod] = 1;
      }
   }

// --------------------------------------------------------------------------------------------------

   // Apply additional cuts on the signal and background samples (can be different)
   //   TCut mycuts = cleanNAN+more+OneLpt;// 
   TCut mycuts = cleanNAN_qgid+cleanNAN_tau+full_wv_sr; // for example: TCut mycuts = "abs(var1)<0.5 && abs(var2-0.5)<1"; wv_sr
   TCut mycutb = mycuts;//

   VbsReducedEvent vbsEvent;

   std::vector<Sample*> bkgSamples;
   std::vector<Sample*> sglSamples;
   std::vector<Sample*> dataSamples;

   getSamples(dataSamples, sglSamples, bkgSamples);

// Selector - Surprise, surprise it selects things. Look at the vbsSamples.cc after you run the dsw script and copy the samples to the appropriate spot
// This is just for ease of use when running the classification over different datasets
int selector = 2016; // 0000 = old, 2016, 2017, 2018

//if (selector == 0000){
//   dataSamples.push_back( new Sample("data",	  "Data",	    1,	  1,  gid_data,  gid_data,   1,  1,  0) );
//// // bkgSamples.push_back( new Sample("WV_EWK",	  "WminusTo2JZTo2LJJ_EWK_LO_SM",	    0.02982,	  1,  gid_ewkWV,    1100,    840,  189086.0,  0.0) );
//// // bkgSamples.push_back( new Sample("WV_EWK",	  "WminusToLNuWminusTo2JJJ_EWK_LO_SM",      0.03259,	  1,  gid_ewkWV,    1101,    840,  189560.0,  0.0) );
//// // bkgSamples.push_back( new Sample("WV_EWK",	  "WminusToLNuZTo2JJJ_EWK_LO_SM",	   0.1, 	  1,  gid_ewkWV,    1102,    840,  199542.0,  0.0) );
//// // bkgSamples.push_back( new Sample("WV_EWK",	  "WplusTo2JWminusToLNuJJ_EWK_LO_SM",      0.9107,	  1,  gid_ewkWV,    1103,    840,  1983847.0,  0.0) );
//// // bkgSamples.push_back( new Sample("WV_EWK",	  "WplusTo2JZTo2LJJ_EWK_LO_SM",	           0.05401,	  1,  gid_ewkWV,    1104,    840,  198922.0,  0.0) );
//// // bkgSamples.push_back( new Sample("WV_EWK",	  "WplusToLNuWminusTo2JJJ_EWK_LO_SM",      0.9114,	  1,  gid_ewkWV,    1105,    840,  1991227.0,  0.0) );
//// // bkgSamples.push_back( new Sample("WV_EWK",	  "WplusToLNuWplusTo2JJJ_EWK_LO_SM",       0.08793,	  1,  gid_ewkWV,    1106,    840,  198848.0,  0.0) );
//// // bkgSamples.push_back( new Sample("WV_EWK",	  "WplusToLNuZTo2JJJ_EWK_LO_SM",	   0.1825,	  1,  gid_ewkWV,    1107,    840,  393171.0,  0.0) );
//// // bkgSamples.push_back( new Sample("WV_EWK",	  "ZTo2LZTo2JJJ_EWK_LO_SM",	           0.01589,	  1,  gid_ewkWV,    1108,    840,  99997.0,  0.0) );
//
//   sglSamples.push_back( new Sample("WV_EWK",	  "WminusTo2JZTo2LJJ_EWK_LO_SM",	    0.02982,	  1,  gid_sgl,    100,    910,  189086.0,  0.0) );
//   sglSamples.push_back( new Sample("WV_EWK",	  "WminusToLNuWminusTo2JJJ_EWK_LO_SM",      0.03259,	  1,  gid_sgl,    101,    910,  189560.0,  0.0) );
//   sglSamples.push_back( new Sample("WV_EWK",	  "WminusToLNuZTo2JJJ_EWK_LO_SM",	   0.1, 	  1,  gid_sgl,    102,    910,  199542.0,  0.0) );
//   sglSamples.push_back( new Sample("WV_EWK",	  "WplusTo2JWminusToLNuJJ_EWK_LO_SM",      0.9107,	  1,  gid_sgl,    103,    910,  1983847.0,  0.0) );
//   sglSamples.push_back( new Sample("WV_EWK",	  "WplusTo2JZTo2LJJ_EWK_LO_SM",	           0.05401,	  1,  gid_sgl,    104,    910,  198922.0,  0.0) );
//   sglSamples.push_back( new Sample("WV_EWK",	  "WplusToLNuWminusTo2JJJ_EWK_LO_SM",      0.9114,	  1,  gid_sgl,    105,    910,  1991227.0,  0.0) );
//   sglSamples.push_back( new Sample("WV_EWK",	  "WplusToLNuWplusTo2JJJ_EWK_LO_SM",       0.08793,	  1,  gid_sgl,    106,    910,  198848.0,  0.0) );
//   sglSamples.push_back( new Sample("WV_EWK",	  "WplusToLNuZTo2JJJ_EWK_LO_SM",	   0.1825,	  1,  gid_sgl,    107,    910,  393171.0,  0.0) );
//   sglSamples.push_back( new Sample("WV_EWK",	  "ZTo2LZTo2JJJ_EWK_LO_SM",	           0.01589,	  1,  gid_sgl,    108,    910,  99997.0,  0.0) );
//
//
//   bkgSamples.push_back( new Sample("Diboson",	  "WminusTo2JZTo2LJJ_QCD_LO_SM",	   0.3488,	  1,  gid_Diboson,  1200,   400,  489280.0,  0.0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WminusToLNuWminusTo2JJJ_QCD_LO_SM",	   0.03203,	  1,  gid_Diboson,  1201,   400,  99657.0,  0.0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WminusToLNuZTo2JJJ_QCD_LO_SM",	   1.166,	  1,  gid_Diboson,  1202,   400,  981540.0,  0.0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusTo2JWminusToLNuJJ_QCD_LO_SM",	   5.568,	  1,  gid_Diboson,  1203,   400,  3994663.0,  0.0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusTo2JZTo2LJJ_QCD_LO_SM",	           0.575,	  1,  gid_Diboson,  1204,   400,  499432.0,  0.0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusToLNuWminusTo2JJJ_QCD_LO_SM",	   5.546,	  1,  gid_Diboson,  1205,   400,  3949170.0,  0.0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusToLNuWplusTo2JJJ_QCD_LO_SM",	   0.07584,	  1,  gid_Diboson,  1206,   400,  99992.0,  0.0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusToLNuZTo2JJJ_QCD_LO_SM",	   1.938,	  1,  gid_Diboson,  1207,   400,  1991348.0,  0.0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "ZTo2LZTo2JJJ_QCD_LO_SM",	           0.3449,	  1,  gid_Diboson,  1208,   400,  49999.0,  0.0) );
//
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT_100To200",	   1627.45,	  1,  gid_Wjets,  1300,   924,  79165703.0,  0.0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT_1200To2500",	   1.60809,	  1,  gid_Wjets,  1301,   924,  6708656.0,  0.0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT_200To400",	   435.24,	  1,  gid_Wjets,  1302,   924,  29087430.0,  0.0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT_2500ToInf",	   0.0389136,	  1,  gid_Wjets,  1303,   924,  2520618.0,  0.0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT_400To600",	   59.18,	  1,  gid_Wjets,  1304,   924,  7754252.0,  0.0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT_600To800",	   14.58,	  1,  gid_Wjets,  1305,   924,  18578604.0,  0.0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT_800To1200",	   6.655,	  1,  gid_Wjets,  1306,   924,  7688957.0,  0.0) );
//
//   bkgSamples.push_back( new Sample("Zjets",	  "DY1JetsToLL",	   1012.296845,	  1,  gid_Zjets,  1400,   4,  46443016.0,  0.0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DY2JetsToLL",	   334.717838,	  1,  gid_Zjets,  1401,   4,  19296117.0,  0.0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DY3JetsToLL",	   102.4628,	  1,  gid_Zjets,  1402,   4,  4866978.0,  0.0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DY4JetsToLL",	   54.48136,	  1,  gid_Zjets,  1403,   4,  2798791.0,  0.0) );
//
//   bkgSamples.push_back( new Sample("top",	  "ST_s_channel",	                     11.36,	  1,  gid_top,  1500,   592,  999976.0,  188501.0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_tW_antitop_5f_NoFullyHadronicDecays",19.5741,	  1,  gid_top,  1501,   592,  5424956.0,  0.0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_tW_top_5f_NoFullyHadronicDecays",	   19.5741,	  1,  gid_top,  1502,   592,  5372830.0,  0.0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_t_channel_antitop",	             80.95,	  1,  gid_top,  1503,   592,  3927980.0,  0.0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_t_channel_top_4f",	            136.02,	  1,  gid_top,  1504,   592,  5993570.0,  0.0) );
//   bkgSamples.push_back( new Sample("top",	  "TTToSemilepton",	                     364.3,	  1,  gid_top,  1505,   592,  91832423.0,  0.0) );
//   bkgSamples.push_back( new Sample("top",	  "TTWJetsToLNu",	                    0.2043,	  1,  gid_top,  1506,   592,  5280251.0,  1282079.0) );
//   bkgSamples.push_back( new Sample("top",	  "TTWJetsToQQ",	                    0.4062,	  1,  gid_top,  1507,   592,  833257.0,  201483.0) );
//   bkgSamples.push_back( new Sample("top",	  "TTZToLLNuNu_M-10",	                    0.2529,	  1,  gid_top,  1508,   592,  7969186.0,  2126557.0) );
//   bkgSamples.push_back( new Sample("top",	  "TTZToQQ",	                             0.5297,	  1,  gid_top,  1509,   592,  749367.0,  199113.0) );
//
//} else if (selector == 2016){
//   //These are for the 2016 ntuples
//   dataSamples.push_back( new Sample("data",	 "Data" ,	 1,	 1,	 gid_data, gid_data,	1,	1.0,	0) );
//
//   sglSamples.push_back( new Sample("WV_EWK",	 "WminusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.02982,	  1, gid_sgl,  100,	910,	200000.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WminusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.03259,	  1, gid_sgl,  101,	910,	198300.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WminusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.1,	  1, gid_sgl,  102,	910,	200000.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WplusTo2JWminusToLNuJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.9107,	  1, gid_sgl,  103,	910,	1985200.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WplusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.05401,	  1, gid_sgl,  104,	910,	178000.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WplusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.9114,	  1, gid_sgl,  105,	910,	1998400.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WplusToLNuWplusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.08793,	  1, gid_sgl,  106,	910,	200000.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WplusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.1825,	  1, gid_sgl,  107,	910,	390100.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "ZTo2LZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.01589,	  1, gid_sgl,  108,	910,	100000.0,	0) );
//
//   bkgSamples.push_back( new Sample("Diboson",	  "WminusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.3488,	  1,  gid_Diboson,  1100,   400,	 500000.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WminusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.03203,	  1,  gid_Diboson,  1100,   400,	 100000.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WminusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	1.166,	  1,  gid_Diboson,  1100,   400,	 997400.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusTo2JWminusToLNuJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	5.568,	  1,  gid_Diboson,  1100,   400,	 3823400.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.575,	  1,  gid_Diboson,  1100,   400,	 500000.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	5.546,	  1,  gid_Diboson,  1100,   400,	 4000000.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusToLNuWplusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.07584,	  1,  gid_Diboson,  1100,   400,	 100000.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	1.938,	  1,  gid_Diboson,  1100,   400,	 1971200.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "ZTo2LZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCUETP8M1_13TeV-madgraph-pythia8",	0.3449,	  1,  gid_Diboson,  1100,   400,	 100000.0,	  0) );
//
//   bkgSamples.push_back( new Sample("top",	  "ST_tW_antitop_5f_NoFullyHadronicDecays_13TeV_PSweights-powheg-pythia8",	38.06,	  1,  gid_top,  1100,   592,	 2710849.25,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_tW_antitop_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",	34.97,	  1,  gid_top,  1100,   592,	 174109584.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_tW_top_5f_NoFullyHadronicDecays_13TeV_PSweights-powheg-pythia8",	38.09,	  1,  gid_top,  1100,   592,	 3213335.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_tW_top_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",	34.91,	  1,  gid_top,  1100,   592,	 173908704.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",	67.91,	  1,  gid_top,  1100,   592,	 17771480.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_t-channel_top_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",	113.3,	  1,  gid_top,  1100,   592,	 31835782.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_s-channel_4f_leptonDecays_13TeV_PSweights-amcatnlo-pythia8",	3.365,	  1,  gid_top,  1100,   592,	 33572360.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_s-channel_4f_hadronicDecays_TuneCP5_PSweights_13TeV-amcatnlo-pythia8",	11.24,	  1,  gid_top,  1100,   592,	 54761756.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_s-channel_4f_InclusiveDecays_13TeV-amcatnlo-pythia8",	10.12,	  1,  gid_top,  1100,   592,	 29561764.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8",	377.96,	  1,  gid_top,  1100,   592,	 21432309760.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8",	365.34,	  1,  gid_top,  1100,   592,	 32366942208.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8",	88.29,	  1,  gid_top,  1100,   592,	 4891619840.0,	  0) );
//
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-70To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	1353.0,	  1,  gid_Wjets,  1100,   924,	 10020533.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	1346.0,	  1,  gid_Wjets,  1100,   924,	 78043024.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	360.1,	  1,  gid_Wjets,  1100,   924,	 38984320.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	48.8,	  1,  gid_Wjets,  1100,   924,	 7687800.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	12.07,	  1,  gid_Wjets,  1100,   924,	 18687480.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	5.497,	  1,  gid_Wjets,  1100,   924,	 7830536.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	1.329,	  1,  gid_Wjets,  1100,   924,	 6872441.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	0.03209,	  1,  gid_Wjets,  1100,   924,	 2637821.0,	  0) );
//
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-70to100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	169.9,	  1,  gid_Zjets,  1100,   4,	 9691660.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	147.4,	  1,  gid_Zjets,  1100,   4,	 11017086.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	41.04,	  1,  gid_Zjets,  1100,   4,	 9609137.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	5.674,	  1,  gid_Zjets,  1100,   4,	 9725661.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	1.358,	  1,  gid_Zjets,  1100,   4,	 8292957.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	0.6229,	  1,  gid_Zjets,  1100,   4,	 2673066.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-1200to2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	0.1512,	  1,  gid_Zjets,  1100,   4,	 596079.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-2500toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",	0.003659,	  1,  gid_Zjets,  1100,   4,	 399492.0,	  0) );
//
//} else if (selector == 2017) {
//   // 2017 ntuples
//   dataSamples.push_back( new Sample("data",	 "Data" ,	 1,	 1,	 gid_data, gid_data,	1,	1.0,	0) );
//
//   sglSamples.push_back( new Sample("WV_EWK",	 "WminusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.02982,	  1, gid_sgl,  100,	910,	592774.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WminusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.03259,	  1, gid_sgl,  101,	910,	568778.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WminusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.1,	  1, gid_sgl,  102,	910,	592964.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WplusTo2JWminusToLNuJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.9107,	  1, gid_sgl,  103,	910,	5539710.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WplusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.05401,	  1, gid_sgl,  104,	910,	596742.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WplusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.9114,	  1, gid_sgl,  105,	910,	5970516.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WplusToLNuWplusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.08793,	  1, gid_sgl,  106,	910,	592724.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WplusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.1825,	  1, gid_sgl,  107,	910,	1183046.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "ZTo2LZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.01589,	  1, gid_sgl,  108,	910,	284048.0,	0) );
//
//   bkgSamples.push_back( new Sample("Diboson",	  "WminusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.3488,	  1,  gid_Diboson,  1100,   400,	 1476120.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WminusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.03203,	  1,  gid_Diboson,  1100,   400,	 296398.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WminusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	1.166,	  1,  gid_Diboson,  1100,   400,	 2875730.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusTo2JWminusToLNuJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV",	5.568,	  1,  gid_Diboson,  1100,   400,	 10668784.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.575,	  1,  gid_Diboson,  1100,   400,	 1428816.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV",	5.546,	  1,  gid_Diboson,  1100,   400,	 11267850.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusToLNuWplusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.07584,	  1,  gid_Diboson,  1100,   400,	 296730.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	1.938,	  1,  gid_Diboson,  1100,   400,	 5919374.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "ZTo2LZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.3449,	  1,  gid_Diboson,  1100,   400,	 149536.0,	  0) );
//
//   bkgSamples.push_back( new Sample("top",	  "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8",	365.34,	  1,  gid_top,  1100,   592,	 72526299136.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8",	86.99,	  1,  gid_top,  1100,   592,	 648729856.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "TTToHadronic_TuneCP5_13TeV-powheg-pythia8",	377.96,	  1,  gid_top,  1100,   592,	 61926825984.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_s-channel_antitop_leptonDecays_13TeV-PSweights_powheg-pythia",	1.33,	  1,  gid_top,  1100,   592,	 3422897.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_s-channel_top_leptonDecays_13TeV-PSweights_powheg-pythia",	2.13,	  1,  gid_top,  1100,   592,	 12862777.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_t-channel_antitop_5f_TuneCP5_PSweights_13TeV-powheg-pythia8",	27.19,	  1,  gid_top,  1100,   592,	 557503744.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_t-channel_top_5f_TuneCP5_13TeV-powheg-pythia8",	45.7,	  1,  gid_top,  1100,   592,	 1418556928.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8",	12.04,	  1,  gid_top,  1100,   592,	 279005344.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8",	12.04,	  1,  gid_top,  1100,   592,	 272081088.0,	  0) );
//
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-70To100_TuneCP5_13TeV-madgraphMLM-pythia8",	1292.0,	  1,  gid_Wjets,  1100,   924,	 22201316.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8",	1395.0,	  1,  gid_Wjets,  1100,   924,	 35804624.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8",	407.9,	  1,  gid_Wjets,  1100,   924,	 21192212.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8",	57.48,	  1,  gid_Wjets,  1100,   924,	 14250114.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8",	12.87,	  1,  gid_Wjets,  1100,   924,	 21582308.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8",	5.366,	  1,  gid_Wjets,  1100,   924,	 20272990.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8",	1.074,	  1,  gid_Wjets,  1100,   924,	 19991892.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8",	0.008001,	  1,  gid_Wjets,  1100,   924,	 20629584.0,	  0) );
//
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8",	167.33,	  1,  gid_Zjets,  1100,   4,	 9333543.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8",	161.1,	  1,  gid_Zjets,  1100,   4,	 15124171.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8",	48.66,	  1,  gid_Zjets,  1100,   4,	 11896758.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8",	6.968,	  1,  gid_Zjets,  1100,   4,	 11294006.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8",	1.743,	  1,  gid_Zjets,  1100,   4,	 8691608.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8",	0.8052,	  1,  gid_Zjets,  1100,   4,	 3089712.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8",	0.1933,	  1,  gid_Zjets,  1100,   4,	 616923.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8",	0.003468,	  1,  gid_Zjets,  1100,   4,	 401334.0,	  0) );
//} else if (selector == 2018) {
//   // 2018 ntuples
//   dataSamples.push_back( new Sample("data",	 "Data" ,	 1,	 1,	 gid_data, gid_data,	1,	1.0,	0) );
//
//   sglSamples.push_back( new Sample("WV_EWK",	 "WminusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.02982,	  1, gid_sgl,  100,	910,	584787.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WminusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.03259,	  1, gid_sgl,  101,	910,	565831.5,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WminusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.1,	  1, gid_sgl,  102,	910,	566998.5625,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WplusTo2JWminusToLNuJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.9107,	  1, gid_sgl,  103,	910,	5742718.0,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WplusTo2JZTo2LJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.05401,	  1, gid_sgl,  104,	910,	566355.8125,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WplusToLNuWminusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.9114,	  1, gid_sgl,  105,	910,	5744633.5,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WplusToLNuWplusTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.08793,	  1, gid_sgl,  106,	910,	588277.125,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "WplusToLNuZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.1825,	  1, gid_sgl,  107,	910,	1156414.625,	0) );
//   sglSamples.push_back( new Sample("WV_EWK",	 "ZTo2LZTo2JJJ_EWK_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.01589,	  1, gid_sgl,  108,	910,	297179.84375,	0) );
//
//   bkgSamples.push_back( new Sample("Diboson",	  "WminusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.3488,	  1,  gid_Diboson,  1100,   400,	 1479242.875,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WminusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.03203,	  1,  gid_Diboson,  1100,   400,	 296655.78125,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WminusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	1.166,	  1,  gid_Diboson,  1100,   400,	 2906207.5,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusTo2JWminusToLNuJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV",	5.568,	  1,  gid_Diboson,  1100,   400,	 11275069.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusTo2JZTo2LJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.575,	  1,  gid_Diboson,  1100,   400,	 1451346.625,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusToLNuWminusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV",	5.546,	  1,  gid_Diboson,  1100,   400,	 11385983.0,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusToLNuWplusTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.07584,	  1,  gid_Diboson,  1100,   400,	 295939.40625,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "WplusToLNuZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	1.938,	  1,  gid_Diboson,  1100,   400,	 5706507.5,	  0) );
//   bkgSamples.push_back( new Sample("Diboson",	  "ZTo2LZTo2JJJ_QCD_LO_SM_MJJ100PTJ10_TuneCP5_13TeV-madgraph-pythia8",	0.3449,	  1,  gid_Diboson,  1100,   400,	 143152.015625,	  0) );
//
//   bkgSamples.push_back( new Sample("top",	  "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8",	365.34,	  1,  gid_top,  1100,   592,	 90424811520.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8",	86.99,	  1,  gid_top,  1100,   592,	 4635769344.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "TTToHadronic_TuneCP5_13TeV-powheg-pythia8",	377.96,	  1,  gid_top,  1100,   592,	 102734004224.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_s-channel_antitop_leptonDecays_13TeV-PSweights_powheg-pythia",	1.33,	  1,  gid_top,  1100,   592,	 3476320.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_s-channel_top_leptonDecays_13TeV-PSweights_powheg-pythia",	2.13,	  1,  gid_top,  1100,   592,	 12929918.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_t-channel_antitop_5f_TuneCP5_13TeV-powheg-pythia8",	27.19,	  1,  gid_top,  1100,   592,	 326172576.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_t-channel_top_5f_TuneCP5_13TeV-powheg-pythia8",	45.7,	  1,  gid_top,  1100,   592,	 815051136.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_tW_DS_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8",	12.04,	  1,  gid_top,  1100,   592,	 170525440.0,	  0) );
//   bkgSamples.push_back( new Sample("top",	  "ST_tW_DS_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8",	12.04,	  1,  gid_top,  1100,   592,	 170711072.0,	  0) );
//
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-70To100_TuneCP5_13TeV-madgraphMLM-pythia8",	1292.0,	  1,  gid_Wjets,  1100,   924,	 28054964.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-100To200_TuneCP5_13TeV-madgraphMLM-pythia8",	1395.0,	  1,  gid_Wjets,  1100,   924,	 29385684.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8",	407.9,	  1,  gid_Wjets,  1100,   924,	 25415130.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8",	57.48,	  1,  gid_Wjets,  1100,   924,	 5913598.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8",	12.87,	  1,  gid_Wjets,  1100,   924,	 19690764.0,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8",	5.366,	  1,  gid_Wjets,  1100,   924,	 8357922.5,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8",	1.074,	  1,  gid_Wjets,  1100,   924,	 7567070.5,	  0) );
//   bkgSamples.push_back( new Sample("Wjets",	  "WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8",	0.008001,	  1,  gid_Wjets,  1100,   924,	 3189396.0,	  0) );
//   
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-70to100_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",	167.33,	  1,  gid_Zjets,  1100,   4,	 10010341.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-100to200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",	161.1,	  1,  gid_Zjets,  1100,   4,	 11516746.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-200to400_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",	48.66,	  1,  gid_Zjets,  1100,   4,	 10840079.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-400to600_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",	6.968,	  1,  gid_Zjets,  1100,   4,	 46027504.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-600to800_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",	1.743,	  1,  gid_Zjets,  1100,   4,	 8826238.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-800to1200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",	0.8052,	  1,  gid_Zjets,  1100,   4,	 3120982.0,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-1200to2500_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",	0.1933,	  1,  gid_Zjets,  1100,   4,	 531566.875,	  0) );
//   bkgSamples.push_back( new Sample("Zjets",	  "DYJetsToLL_M-50_HT-2500toInf_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",	0.003468,	  1,  gid_Zjets,  1100,   4,	 415517.0,	  0) );
//} else {
//   cout << "There's an issue with your sample choice. Check -vbsTMVAClassification.cc- somewhere around line 150" << endl;
//}

//----
// Events old name was otree

//Data
for (UInt_t ns=0; ns< dataSamples.size();ns++){
   cout << dataSamples[ns]->getGName() << "--" << dataSamples[ns]->getSName() << endl;

   if ( dataSamples[ns]->getLoadFlag()){ 
      cout << "register "  << dataSamples[ns]->getReqList() << " data samples" << endl;
    
      dataSamples[ns]->setInpTree( chain2tree("Events", dataSamples[ns]->getReqList(), "DataTree", "DataTree" ) );

      if( dataSamples[ns]->getInpTree() ){
         fillBranch( dataSamples[ns]->getInpTree(), vbsEvent, dataSamples[ns]); 
      }
      cout << "TMVAClassification:: Total " << dataSamples[ns]->getSName() << " data events " <<   dataSamples[ns]->getNevents() << endl;
   }
}



//Signals
for (UInt_t ns=0; ns<sglSamples.size();ns++){
   cout << sglSamples[ns]->getGName() << "--" << sglSamples[ns]->getSName() << endl;

   if ( sglSamples[ns]->getLoadFlag()){ 
     // cout << "register  "  << sglSamples[ns]->getGName() << "--" << sglSamples[ns]->getSName() << " signal samples" << endl;

      sglSamples[ns]->setInpTree( chain2tree("Events", sglSamples[ns]->getReqList(), sglSamples[ns]->getSName(), sglSamples[ns]->getSName() ) );

      if( sglSamples[ns]->getInpTree() ){
         fillBranch( sglSamples[ns]->getInpTree(), vbsEvent, sglSamples[ns]); 
      }
      cout << "TMVAClassification:: Total " << sglSamples[ns]->getSName() << " signal events " <<   sglSamples[ns]->getNevents() << endl;
   }
}

//Backgrounds
for (UInt_t ns=0; ns<bkgSamples.size();ns++){
  cout << bkgSamples[ns]->getGName() << "--" << bkgSamples[ns]->getSName() << endl;

   if ( bkgSamples[ns]->getLoadFlag()){ 
      //  cout << "register  "  << bkgSamples[ns]->getGName() << "--" << bkgSamples[ns]->getSName() << " background  samples" << endl;

      bkgSamples[ns]->setInpTree( chain2tree("Events", bkgSamples[ns]->getReqList(), bkgSamples[ns]->getSName(), bkgSamples[ns]->getSName() ) );

      if( bkgSamples[ns]->getInpTree() ){   
         fillBranch( bkgSamples[ns]->getInpTree(), vbsEvent, bkgSamples[ns]); 
      }
      cout << "TMVAClassification:: Total " << bkgSamples[ns]->getSName() << " background events " <<   bkgSamples[ns]->getNevents() << endl;
   }
}


// //----

  // Create a ROOT output file where TMVA will store ntuples, histograms, etc.
   stringstream ssofname;
   ssofname << sname << "_SBtmva.root";
   //ssofname << "vbs4l_SBtmva.root";


   TString outfileName( ssofname.str().c_str() );
   TFile* outputFile = TFile::Open( outfileName, "RECREATE" );

   //
   TMVA::Factory* factory = new TMVA::Factory( "TMVAClassification", outputFile,
                                               "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification" ); //I;D;P;G,D

   TMVA::DataLoader* dataloader=new TMVA::DataLoader(sname);

   //Defined in vbsDL.hpp 
   //setVbsFactoryVarsAndSpectators(dataloader);
   setVbsDLorReaderVarsAndSpectators(dataloader,0,vbsEvent);
   // global event weights per tree (see below for setting event-wise weights)
   Double_t signalWeight     = 1.0;
   Double_t backgroundWeight = 1.0;
   

   dataloader->SetSignalWeightExpression    ("mcWeight");
   dataloader->SetBackgroundWeightExpression("mcWeight" );

   // You can add an arbitrary number of signal or background trees
   for (UInt_t ns=0; ns<sglSamples.size();ns++){
      if ( sglSamples[ns]->getInpTree() )  dataloader->AddSignalTree ( sglSamples[ns]->getInpTree(),     signalWeight     );
   }
   // If you wish to modify default settings
   // (please check "src/Config.h" to see all available global options)
   //
   //    (TMVA::gConfig().GetVariablePlotting()).fTimesRMS = 8.0;
   //    (TMVA::gConfig().GetIONames()).fWeightFileDir = "myWeightDirectory";

   // Define the input variables that shall be used for the MVA training
   // note that you may also use variable expressions, such as: "3*var1/var2*abs(var3)"
   // [all types of expressions that can also be parsed by TTree::Draw( "expression" )]
//    dataloader->AddVariable( "myvar1 := var1+var2", 'F' );
//    dataloader->AddVariable( "myvar2 := var1-var2", "Expression 2", "", 'F' );
//    dataloader->AddVariable( "var3",                "Variable 3", "units", 'F' );
//    dataloader->AddVariable( "var4",                "Variable 4", "units", 'F' );

//    // You can add so-called "Spectator variables", which are not used in the MVA training,
//    // but will appear in the final "TestTree" produced by TMVA. This TestTree will contain the
//    // input variables, the response values of all trained MVAs, and the spectator variables

//    dataloader->AddSpectator( "spec1 := var1*2",  "Spectator 1", "units", 'F' );
//    dataloader->AddSpectator( "spec2 := var1*3",  "Spectator 2", "units", 'F' );


   //Add backgrounds to factory
   //
   for (UInt_t ns=0; ns< bkgSamples.size();ns++){
      if ( bkgSamples[ns]->getInpTree() )  dataloader->AddBackgroundTree( bkgSamples[ns]->getInpTree(), backgroundWeight    );
   }
   //   
//    if (n_background_WplusJets && fWjets)     dataloader->AddBackgroundTree( background_WplusJets , backgroundWeight );
//    if (n_background_ZplusJets && fZjets)     dataloader->AddBackgroundTree( background_ZplusJets , backgroundWeight );
//    if (n_background_DiBosons  && fDiBosons)  dataloader->AddBackgroundTree( background_DiBosons ,  backgroundWeight );
//    if (n_background_top       && ftop     )  dataloader->AddBackgroundTree( background_top,        backgroundWeight );
   //   


   // To give different trees for training and testing, do as follows:
   //
   //     dataloader->AddSignalTree( signalTrainingTree, signalTrainWeight, "Training" );
   //     dataloader->AddSignalTree( signalTestTree,     signalTestWeight,  "Test" );

   // Use the following code instead of the above two or four lines to add signal and background
   // training and test events "by hand"
   // NOTE that in this case one should not give expressions (such as "var1+var2") in the input
   //      variable definition, but simply compute the expression before adding the event
   // ```cpp
   // // --- begin ----------------------------------------------------------
   // std::vector<Double_t> vars( 4 ); // vector has size of number of input variables
   // Float_t  treevars[4], weight;
   //
   // // Signal
   // for (UInt_t ivar=0; ivar<4; ivar++) signalTree->SetBranchAddress( Form( "var%i", ivar+1 ), &(treevars[ivar]) );
   // for (UInt_t i=0; i<signalTree->GetEntries(); i++) {
   //    signalTree->GetEntry(i);
   //    for (UInt_t ivar=0; ivar<4; ivar++) vars[ivar] = treevars[ivar];
   //    // add training and test events; here: first half is training, second is testing
   //    // note that the weight can also be event-wise
   //    if (i < signalTree->GetEntries()/2.0) dataloader->AddSignalTrainingEvent( vars, signalWeight );
   //    else                              dataloader->AddSignalTestEvent    ( vars, signalWeight );
   // }
   //
   // // Background (has event weights)
   // background->SetBranchAddress( "weight", &weight );
   // for (UInt_t ivar=0; ivar<4; ivar++) background->SetBranchAddress( Form( "var%i", ivar+1 ), &(treevars[ivar]) );
   // for (UInt_t i=0; i<background->GetEntries(); i++) {
   //    background->GetEntry(i);
   //    for (UInt_t ivar=0; ivar<4; ivar++) vars[ivar] = treevars[ivar];
   //    // add training and test events; here: first half is training, second is testing
   //    // note that the weight can also be event-wise
   //    if (i < background->GetEntries()/2) dataloader->AddBackgroundTrainingEvent( vars, backgroundWeight*weight );
   //    else                                dataloader->AddBackgroundTestEvent    ( vars, backgroundWeight*weight );
   // }
   // // --- end ------------------------------------------------------------
   // ```
   // End of tree registration

   // Set individual event weights (the variables must exist in the original TTree)
   // -  for signal    : `dataloader->SetSignalWeightExpression    ("weight1*weight2");`
   // -  for background: `dataloader->SetBackgroundWeightExpression("weight1*weight2");`



   // Tell the dataloader how to use the training and testing events
   //
   // If no numbers of events are given, half of the events in the tree are used
   // for training, and the other half for testing:
   //
   //    dataloader->PrepareTrainingAndTestTree( mycut, "SplitMode=random:!V" );
   //
   // To also specify the number of testing events, use:
   //
   //    dataloader->PrepareTrainingAndTestTree( mycut,
   //         "NSigTrain=3000:NBkgTrain=3000:NSigTest=3000:NBkgTest=3000:SplitMode=Random:!V" );
   //  dataloader->PrepareTrainingAndTestTree( mycuts, mycutb,
   //                                         "nTrain_Signal=1000:nTrain_Background=1000:SplitMode=Random:NormMode=NumEvents:!V" );

// There are 3 choices for this option None, NumEvents, EqualNumEvents with the last being the default.
// NumEvents ensures that the average weight for each class, independently, is 1. 
// EqualNumEvents ensures that, for all classes taken together is 1.

   //For NormMode=NumEvents got verry strange num of events  in test tree
// -- ==================================================================================================
// --- Classifier   (  #signal, #backgr.)  Optimal-cut  S/sqrt(S+B)      NSig      NBkg   EffSig   EffBkg
// --- --------------------------------------------------------------------------------------------------
// ---    MLPBFGS:  (     1000,     1000)       0.1423      30.0485  935.8346  34.12273   0.9358  0.03412
// ---    DNN_GPU:  (     1000,     1000)       0.4051       29.867  942.9458  53.81086   0.9429  0.05381
// ---        BDT:  (     1000,     1000)       0.0082      30.1025  938.3947  33.37822   0.9384  0.03338
// Still want go with this
// I do assume significance calculations for training is wrong but it's ok if 
// we will do max(s/sqrt(s+b) ) optimization after cuts on discriminats
   dataloader->PrepareTrainingAndTestTree( mycuts, mycutb,
                                        "nTrain_Signal=0:nTrain_Background=0:SplitMode=Random:NormMode=NumEvents:!V" );


//    dataloader->PrepareTrainingAndTestTree( mycuts, mycutb,
//                                         "nTrain_Signal=0:nTrain_Background=0:SplitMode=Random:NormMode=None:!V" );
   //No changes (?)
// --- ==================================================================================================
// --- Classifier   (  #signal, #backgr.)  Optimal-cut  S/sqrt(S+B)      NSig      NBkg   EffSig   EffBkg
// --- --------------------------------------------------------------------------------------------------
// ---        BDT:  (     1000,     1000)       0.0082      30.1025  938.3947  33.37822   0.9384  0.03338
// --- --------------------------------------------------------------------------------------------------
//If no weight supplied (????)  with dataloader->SetSignalWeightExpression    ("f_weight");/  dataloader->SetSignalWeightExpression    ("f_weight");
// -- ==================================================================================================
// --- Classifier   (  #signal, #backgr.)  Optimal-cut  S/sqrt(S+B)      NSig      NBkg   EffSig   EffBkg
// --- --------------------------------------------------------------------------------------------------
// ---        BDT:  (     1000,     1000)      -0.0222      28.7406  879.4696  56.90374   0.8795   0.0569
// --- --------------------------------------------------------------------------------------------------


   // ### Book MVA methods
   //
   // Please lookup the various method configuration options in the corresponding cxx files, eg:
   // src/MethoCuts.cxx, etc, or here: http://tmva.sourceforge.net/optionRef.html
   // it is possible to preset ranges in the option string in which the cut optimisation should be done:
   // "...:CutRangeMin[2]=-1:CutRangeMax[2]=1"...", where [2] is the third input variable

   // Cut optimisation
   if (Use["Cuts"])
      factory->BookMethod( dataloader, TMVA::Types::kCuts, "Cuts",
                           "!H:!V:FitMethod=MC:EffSel:SampleSize=200000:VarProp=FSmart" );

   if (Use["CutsD"])
      factory->BookMethod( dataloader, TMVA::Types::kCuts, "CutsD",
                           "!H:!V:FitMethod=MC:EffSel:SampleSize=200000:VarProp=FSmart:VarTransform=Decorrelate" );

   if (Use["CutsPCA"])
      factory->BookMethod( dataloader, TMVA::Types::kCuts, "CutsPCA",
                           "!H:!V:FitMethod=MC:EffSel:SampleSize=200000:VarProp=FSmart:VarTransform=PCA" );

   if (Use["CutsGA"])
      factory->BookMethod( dataloader, TMVA::Types::kCuts, "CutsGA",
                           "H:!V:FitMethod=GA:CutRangeMin[0]=-10:CutRangeMax[0]=10:VarProp[1]=FMax:EffSel:Steps=30:Cycles=3:PopSize=400:SC_steps=10:SC_rate=5:SC_factor=0.95" );

   if (Use["CutsSA"])
      factory->BookMethod( dataloader, TMVA::Types::kCuts, "CutsSA",
                           "!H:!V:FitMethod=SA:EffSel:MaxCalls=150000:KernelTemp=IncAdaptive:InitialTemp=1e+6:MinTemp=1e-6:Eps=1e-10:UseDefaultScale" );

   // Likelihood ("naive Bayes estimator")
   if (Use["Likelihood"])
      factory->BookMethod( dataloader, TMVA::Types::kLikelihood, "Likelihood",
                           "H:!V:TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmoothBkg[1]=10:NSmooth=1:NAvEvtPerBin=50" );

   // Decorrelated likelihood
   if (Use["LikelihoodD"])
      factory->BookMethod( dataloader, TMVA::Types::kLikelihood, "LikelihoodD",
                           "!H:!V:TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmooth=5:NAvEvtPerBin=50:VarTransform=Decorrelate" );

   // PCA-transformed likelihood
   if (Use["LikelihoodPCA"])
      factory->BookMethod( dataloader, TMVA::Types::kLikelihood, "LikelihoodPCA",
                           "!H:!V:!TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmooth=5:NAvEvtPerBin=50:VarTransform=PCA" );

   // Use a kernel density estimator to approximate the PDFs
   if (Use["LikelihoodKDE"])
      factory->BookMethod( dataloader, TMVA::Types::kLikelihood, "LikelihoodKDE",
                           "!H:!V:!TransformOutput:PDFInterpol=KDE:KDEtype=Gauss:KDEiter=Adaptive:KDEFineFactor=0.3:KDEborder=None:NAvEvtPerBin=50" );

   // Use a variable-dependent mix of splines and kernel density estimator
   if (Use["LikelihoodMIX"])
      factory->BookMethod( dataloader, TMVA::Types::kLikelihood, "LikelihoodMIX",
                           "!H:!V:!TransformOutput:PDFInterpolSig[0]=KDE:PDFInterpolBkg[0]=KDE:PDFInterpolSig[1]=KDE:PDFInterpolBkg[1]=KDE:PDFInterpolSig[2]=Spline2:PDFInterpolBkg[2]=Spline2:PDFInterpolSig[3]=Spline2:PDFInterpolBkg[3]=Spline2:KDEtype=Gauss:KDEiter=Nonadaptive:KDEborder=None:NAvEvtPerBin=50" );

   // Test the multi-dimensional probability density estimator
   // here are the options strings for the MinMax and RMS methods, respectively:
   //
   //      "!H:!V:VolumeRangeMode=MinMax:DeltaFrac=0.2:KernelEstimator=Gauss:GaussSigma=0.3" );
   //      "!H:!V:VolumeRangeMode=RMS:DeltaFrac=3:KernelEstimator=Gauss:GaussSigma=0.3" );
   if (Use["PDERS"])
      factory->BookMethod( dataloader, TMVA::Types::kPDERS, "PDERS",
                           "!H:!V:NormTree=T:VolumeRangeMode=Adaptive:KernelEstimator=Gauss:GaussSigma=0.3:NEventsMin=400:NEventsMax=600" );

   if (Use["PDERSD"])
      factory->BookMethod( dataloader, TMVA::Types::kPDERS, "PDERSD",
                           "!H:!V:VolumeRangeMode=Adaptive:KernelEstimator=Gauss:GaussSigma=0.3:NEventsMin=400:NEventsMax=600:VarTransform=Decorrelate" );

   if (Use["PDERSPCA"])
      factory->BookMethod( dataloader, TMVA::Types::kPDERS, "PDERSPCA",
                           "!H:!V:VolumeRangeMode=Adaptive:KernelEstimator=Gauss:GaussSigma=0.3:NEventsMin=400:NEventsMax=600:VarTransform=PCA" );

   // Multi-dimensional likelihood estimator using self-adapting phase-space binning
   if (Use["PDEFoam"])
      factory->BookMethod( dataloader, TMVA::Types::kPDEFoam, "PDEFoam",
                           "!H:!V:SigBgSeparate=F:TailCut=0.001:VolFrac=0.0666:nActiveCells=500:nSampl=2000:nBin=5:Nmin=100:Kernel=None:Compress=T" );

   if (Use["PDEFoamBoost"])
      factory->BookMethod( dataloader, TMVA::Types::kPDEFoam, "PDEFoamBoost",
                           "!H:!V:Boost_Num=30:Boost_Transform=linear:SigBgSeparate=F:MaxDepth=4:UseYesNoCell=T:DTLogic=MisClassificationError:FillFoamWithOrigWeights=F:TailCut=0:nActiveCells=500:nBin=20:Nmin=400:Kernel=None:Compress=T" );

   // K-Nearest Neighbour classifier (KNN)
   if (Use["KNN"])
      factory->BookMethod( dataloader, TMVA::Types::kKNN, "KNN",
                           "H:nkNN=20:ScaleFrac=0.8:SigmaFact=1.0:Kernel=Gaus:UseKernel=F:UseWeight=T:!Trim" );

   // H-Matrix (chi2-squared) method
   if (Use["HMatrix"])
      factory->BookMethod( dataloader, TMVA::Types::kHMatrix, "HMatrix", "!H:!V:VarTransform=None" );

   // Linear discriminant (same as Fisher discriminant)
   if (Use["LD"])
      factory->BookMethod( dataloader, TMVA::Types::kLD, "LD", "H:!V:VarTransform=None:CreateMVAPdfs:PDFInterpolMVAPdf=Spline2:NbinsMVAPdf=50:NsmoothMVAPdf=10" );

   // Fisher discriminant (same as LD)
   if (Use["Fisher"])
      factory->BookMethod( dataloader, TMVA::Types::kFisher, "Fisher", "H:!V:Fisher:VarTransform=None:CreateMVAPdfs:PDFInterpolMVAPdf=Spline2:NbinsMVAPdf=50:NsmoothMVAPdf=10" );

   // Fisher with Gauss-transformed input variables
   if (Use["FisherG"])
      factory->BookMethod( dataloader, TMVA::Types::kFisher, "FisherG", "H:!V:VarTransform=Gauss" );

   // Composite classifier: ensemble (tree) of boosted Fisher classifiers
   if (Use["BoostedFisher"])
      factory->BookMethod( dataloader, TMVA::Types::kFisher, "BoostedFisher",
                           "H:!V:Boost_Num=20:Boost_Transform=log:Boost_Type=AdaBoost:Boost_AdaBoostBeta=0.2:!Boost_DetailedMonitoring" );

   // Function discrimination analysis (FDA) -- test of various fitters - the recommended one is Minuit (or GA or SA)
   if (Use["FDA_MC"])
      factory->BookMethod( dataloader, TMVA::Types::kFDA, "FDA_MC",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=MC:SampleSize=100000:Sigma=0.1" );

   if (Use["FDA_GA"]) // can also use Simulated Annealing (SA) algorithm (see Cuts_SA options])
      factory->BookMethod( dataloader, TMVA::Types::kFDA, "FDA_GA",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=GA:PopSize=100:Cycles=2:Steps=5:Trim=True:SaveBestGen=1" );

   if (Use["FDA_SA"]) // can also use Simulated Annealing (SA) algorithm (see Cuts_SA options])
      factory->BookMethod( dataloader, TMVA::Types::kFDA, "FDA_SA",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=SA:MaxCalls=15000:KernelTemp=IncAdaptive:InitialTemp=1e+6:MinTemp=1e-6:Eps=1e-10:UseDefaultScale" );

   if (Use["FDA_MT"])
      factory->BookMethod( dataloader, TMVA::Types::kFDA, "FDA_MT",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=MINUIT:ErrorLevel=1:PrintLevel=-1:FitStrategy=2:UseImprove:UseMinos:SetBatch" );

   if (Use["FDA_GAMT"])
      factory->BookMethod( dataloader, TMVA::Types::kFDA, "FDA_GAMT",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=GA:Converger=MINUIT:ErrorLevel=1:PrintLevel=-1:FitStrategy=0:!UseImprove:!UseMinos:SetBatch:Cycles=1:PopSize=5:Steps=5:Trim" );

   if (Use["FDA_MCMT"])
      factory->BookMethod( dataloader, TMVA::Types::kFDA, "FDA_MCMT",
                           "H:!V:Formula=(0)+(1)*x0+(2)*x1+(3)*x2+(4)*x3:ParRanges=(-1,1);(-10,10);(-10,10);(-10,10);(-10,10):FitMethod=MC:Converger=MINUIT:ErrorLevel=1:PrintLevel=-1:FitStrategy=0:!UseImprove:!UseMinos:SetBatch:SampleSize=20" );

   // TMVA ANN: MLP (recommended ANN) -- all ANNs in TMVA are Multilayer Perceptrons
   if (Use["MLP"])
      factory->BookMethod( dataloader, TMVA::Types::kMLP, "MLP", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:!UseRegulator" );

   if (Use["MLPBFGS"])
      factory->BookMethod( dataloader, TMVA::Types::kMLP, "MLPBFGS", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:TrainingMethod=BFGS:!UseRegulator" );

   if (Use["MLPBNN"])
      factory->BookMethod( dataloader, TMVA::Types::kMLP, "MLPBNN", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=60:HiddenLayers=N+5:TestRate=5:TrainingMethod=BFGS:UseRegulator" ); // BFGS training with bayesian regulators


   // Multi-architecture DNN implementation.
   if (Use["DNN_CPU"] or Use["DNN_GPU"]) {
      // General layout.
//       TString layoutString ("Layout=TANH|128,TANH|128,TANH|128,LINEAR");

//       // Training strategies.
//       TString training0("LearningRate=1e-1,Momentum=0.9,Repetitions=1,"
//                         "ConvergenceSteps=20,BatchSize=256,TestRepetitions=10,"
//                         "WeightDecay=1e-4,Regularization=L2,"
//                         "DropConfig=0.0+0.5+0.5+0.5, Multithreading=True");
//       TString training1("LearningRate=1e-2,Momentum=0.9,Repetitions=1,"
//                         "ConvergenceSteps=20,BatchSize=256,TestRepetitions=10,"
//                         "WeightDecay=1e-4,Regularization=L2,"
//                         "DropConfig=0.0+0.0+0.0+0.0, Multithreading=True");
//       TString training2("LearningRate=1e-3,Momentum=0.0,Repetitions=1,"
//                         "ConvergenceSteps=20,BatchSize=256,TestRepetitions=10,"
//                         "WeightDecay=1e-4,Regularization=L2,"
//                         "DropConfig=0.0+0.0+0.0+0.0, Multithreading=True");
//       TString trainingStrategyString ("TrainingStrategy=");
//       trainingStrategyString += training0 + "|" + training1 + "|" + training2;

    TString layoutString ("Layout=TANH|100,TANH|50,TANH|10,LINEAR");
//    TString layoutString ("Layout=TANH|(N+30)*2,TANH|(N+30),TANH|10,LINEAR");
//  TString layoutString ("Layout=RELU|64,RELU|32,RELU|32,SIGMOID|32,LINEAR");

    TString training0 ("LearningRate=1e-1,Momentum=0.0,Repetitions=1,ConvergenceSteps=300,BatchSize=256,TestRepetitions=15,WeightDecay=0.001,Regularization=NONE,DropConfig=0.0+0.5+0.5+0.5,DropRepetitions=1,Multithreading=True");
    TString training1 ("LearningRate=1e-2,Momentum=0.5,Repetitions=1,ConvergenceSteps=300,BatchSize=256,TestRepetitions=7,WeightDecay=0.001,Regularization=L2,Multithreading=True,DropConfig=0.0+0.1+0.1+0.1,DropRepetitions=1");
    TString training2 ("LearningRate=1e-2,Momentum=0.3,Repetitions=1,ConvergenceSteps=300,BatchSize=256,TestRepetitions=7,WeightDecay=0.0001,Regularization=L2,Multithreading=True");
    TString training3 ("LearningRate=1e-2,Momentum=0.1,Repetitions=1,ConvergenceSteps=300,BatchSize=256,TestRepetitions=7,WeightDecay=0.0001,Regularization=NONE,Multithreading=True");




    TString trainingStrategyString ("TrainingStrategy=");
    trainingStrategyString += training0 + "|" + training1 + "|" + training2 + "|" + training3;


      // General Options.
      TString dnnOptions ("!H:V:ErrorStrategy=CROSSENTROPY:VarTransform=N:"
                          "WeightInitialization=XAVIERUNIFORM");
      dnnOptions.Append (":"); dnnOptions.Append (layoutString);
      dnnOptions.Append (":"); dnnOptions.Append (trainingStrategyString);

      // Cuda implementation.
      if (Use["DNN_GPU"]) {
         TString gpuOptions = dnnOptions + ":Architecture=GPU";
         factory->BookMethod(dataloader, TMVA::Types::kDL, "DNN_GPU", gpuOptions);
      }
      // Multi-core CPU implementation.
      if (Use["DNN_CPU"]) {
         TString cpuOptions = dnnOptions + ":Architecture=CPU";
         factory->BookMethod(dataloader, TMVA::Types::kDL, "DNN_CPU", cpuOptions);
      }
   }

   // CF(Clermont-Ferrand)ANN
   if (Use["CFMlpANN"])
      factory->BookMethod( dataloader, TMVA::Types::kCFMlpANN, "CFMlpANN", "!H:!V:NCycles=200:HiddenLayers=N+1,N"  ); // n_cycles:#nodes:#nodes:...

   // Tmlp(Root)ANN
   if (Use["TMlpANN"])
      factory->BookMethod( dataloader, TMVA::Types::kTMlpANN, "TMlpANN", "!H:!V:NCycles=200:HiddenLayers=N+1,N:LearningMethod=BFGS:ValidationFraction=0.3"  ); // n_cycles:#nodes:#nodes:...

   // Support Vector Machine
   if (Use["SVM"])
      factory->BookMethod( dataloader, TMVA::Types::kSVM, "SVM", "Gamma=0.25:Tol=0.001:VarTransform=Norm" );

   // Boosted Decision Trees
   if (Use["BDTG"]) // Gradient Boost
      factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDTG",
                           "!H:!V:NTrees=1000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:MaxDepth=2" );

   if (Use["BDT1"])  // Adaptive Boost
      factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDT1",
                           "!H:!V:NTrees=1000:MinNodeSize=1%:MaxDepth=4:BoostType=AdaBoost:AdaBoostBeta=0.6:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20:UseRandomisedTrees=False:UseNvars=2" ); // :NegWeightTreatment=IgnoreNegWeightsInTraining" );

   if (Use["BDT2"])
      factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDT2",
                           "!H:!V:NTrees=1000:MinNodeSize=1%:MaxDepth=4:BoostType=AdaBoost:AdaBoostBeta=0.6:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20:UseRandomisedTrees=False:UseNvars=4" ); // :NegWeightTreatment=IgnoreNegWeightsInTraining" );
   if (Use["BDT"])
      factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDT",
                           "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20:UseRandomisedTrees=True" ); // :NegWeightTreatment=IgnoreNegWeightsInTraining" );

   if (Use["BDTB"]) // Bagging
      factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDTB",
                           "!H:!V:NTrees=400:BoostType=Bagging:SeparationType=GiniIndex:nCuts=20" );

   if (Use["BDTD"]) // Decorrelation + Adaptive Boost
      factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDTD",
                           "!H:!V:NTrees=400:MinNodeSize=5%:MaxDepth=3:BoostType=AdaBoost:SeparationType=GiniIndex:nCuts=20:VarTransform=Decorrelate" );

   if (Use["BDTF"])  // Allow Using Fisher discriminant in node splitting for (strong) linearly correlated variables
      factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDTF",
                           "!H:!V:NTrees=50:MinNodeSize=2.5%:UseFisherCuts:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:SeparationType=GiniIndex:nCuts=20" );

   // RuleFit -- TMVA implementation of Friedman's method
   if (Use["RuleFit"])
      factory->BookMethod( dataloader, TMVA::Types::kRuleFit, "RuleFit",
                           "H:!V:RuleFitModule=RFTMVA:Model=ModRuleLinear:MinImp=0.001:RuleMinDist=0.001:NTrees=20:fEventsMin=0.01:fEventsMax=0.5:GDTau=-1.0:GDTauPrec=0.01:GDStep=0.01:GDNSteps=10000:GDErrScale=1.02" );

   // For an example of the category classifier usage, see: TMVAClassificationCategory
   //
   // --------------------------------------------------------------------------------------------------
   //  Now you can optimize the setting (configuration) of the MVAs using the set of training events
   // STILL EXPERIMENTAL and only implemented for BDT's !
   //
   //     factory->OptimizeAllMethods("SigEffAt001","Scan");
   //factory->OptimizeAllMethods("ROCIntegral","FitGA");
   //
   // --------------------------------------------------------------------------------------------------

   // Now you can tell the factory to train, test, and evaluate the MVAs
   //
   // Train MVAs using the set of training events
   cout << "Train All Methods" << endl;
   factory->TrainAllMethods();

   // Evaluate all MVAs using the set of test events
   cout << "Test All Methods" << endl;
   factory->TestAllMethods();

   // Evaluate and compare performance of all configured MVAs
   cout << "Evaluate All Methods" << endl;
   factory->EvaluateAllMethods();

   ////////////////////////////////////////////////////////////////////////////
   /// Print out AUC for each method, both to the terminal, and to a file
   /// The // AUCoutfile comment needs to stay exactly how it is for the makefile
   /// to catch it and properly rename the ssAUCoutile name.
   stringstream ssAUCoutfile;
    ssAUCoutfile << "ROC/" << "Run2_test.txt"; // AUCoutfile
   std::ofstream AUCoutfile;
   AUCoutfile.open(ssAUCoutfile.str(), std::ios_base::app);
   std::vector<TString> mlist = TMVA::gTools().SplitString(myMethodList, ',');

   AUCoutfile << "" << std::endl;
   AUCoutfile << "--------------------------------------------------" << std::endl;

   for (UInt_t i=0; i<mlist.size(); i++) {
      std::string regMethod(mlist[i]);
      AUCoutfile << "AUC for " << regMethod << ": " << factory->GetROCIntegral(dataloader, regMethod) << std::endl;
   }
   AUCoutfile << "" << std::endl;
   AUCoutfile << "--------------------------------------------------" << std::endl;
   AUCoutfile.close();

   // --------------------------------------------------------------
   cout << "Clone dataTree" << endl;
   // dataTree->CloneTree()->Write();
   dataSamples[0]->getInpTree()->CloneTree()->Write();
   //  dataTree->Write();



 
   // Save the output
   outputFile->Close();

   std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
   std::cout << "==> TMVAClassification is done!" << std::endl;
   std::cout << "==> To apply results to data:: " << std::endl;
   std::cout << "==> root  -b -q  ./vbsTMVAClassificationApplication.cc\\(\\\"" << sname << "\\\",\\\"" << myMethodList << "\\\"\\)" << std::endl;
   //   std::cout << "==> Use plot_tmva.cc\\(\\\"" << sname << "\\\"\\) to analyse..." << std::endl;
   //   std::cout << "==> To analyze output:: " << std::endl;
   //    std::cout << "==> root -l tmvaMon.cc\\(\\\"" << sname << "\\\"\\)" << std::endl;
   //
   delete factory;
   delete dataloader;
   // Launch the GUI for the root macros
   if (!gROOT->IsBatch()) TMVA::TMVAGui( outfileName );

   return 0;
}

int main( int argc, char** argv )
{

   // Select methods (don't look at this code - not of interest)
   TString methodList;
   TString sname=argv[1]; 
   for (int i=2; i<argc; i++) {
      TString regMethod(argv[i]);
      if(regMethod=="-b" || regMethod=="--batch") continue;
      if (!methodList.IsNull()) methodList += TString(",");
      methodList += regMethod;
   }
   return vbsTMVAClassification(sname,methodList);
}


