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
#include <memory>

#include "vector"
#include "vbsTMVA.hpp"
#include "vbsSamples.hpp"
using namespace TMVA;
//

int vbsTMVAClassification(TString sname="vbs_ww", TString myMethodList = "" )
{
   //ROOT::EnableImplicitMT();
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
   TCut mycuts = qgid_cut+tau21_cut+training_cut; // for example: TCut mycuts = "abs(var1)<0.5 && abs(var2-0.5)<1"; wv_sr
   TCut mycutb = mycuts;//

   VbsReducedEvent vbsEvent;

   std::vector<Sample*> bkgSamples;
   std::vector<Sample*> sglSamples;
   std::vector<Sample*> dataSamples;

   getSamples(dataSamples, sglSamples, bkgSamples);

//----

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
         std::cout << "---------------------------------------------------------------------------------------------------------------------------------"  << std::endl;
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
         std::cout << "---------------------------------------------------------------------------------------------------------------------------------"  << std::endl;
      }
   }

   /* Two options
   *  Put everything up until the comment below that says "Here" above the signal and background loops
   *  That uses less RAM, but makes the final output file sizes larger
   *  Conversely, if the file declaration and the Data loop are below the other loops then
   *  the final files will be smaller, but more RAM will be used during the training, potentially
   *  too much and crashes could occur.
   */
   // Create a ROOT output file where TMVA will store ntuples, histograms, etc.
   stringstream ssofname;
   ssofname << sname << "_SBtmva.root";

   TString outfileName( ssofname.str().c_str() );
   TFile* outputFile = TFile::Open( outfileName, "RECREATE" );

   //Data
	TList* tree_list = new TList();

	  for (UInt_t ns=0; ns < dataSamples.size(); ns++){
      cout << dataSamples[ns]->getGName() << "--" << dataSamples[ns]->getSName() << endl;

      if ( dataSamples[ns]->getLoadFlag()){
        std::cout << "register "  << dataSamples[ns]->getReqList() << " data samples" << std::endl;
				dataSamples[ns]->setInpTree(chain2tree("Events", dataSamples[ns]->getReqList(), dataSamples[ns]->getSName(), dataSamples[ns]->getSName() ));

				 if (dataSamples[ns]->getInpTree()) {
					fillBranch(dataSamples[ns]->getInpTree(), vbsEvent, dataSamples[ns]);
               dataSamples[ns]->getInpTree()->SetName("DataTree");
               dataSamples[ns]->getInpTree()->SetTitle("DataTree");
               dataSamples[ns]->getInpTree()->Write();
               tree_list->Add(dataSamples[ns]->getInpTree());
				 }
				 std::cout << "TMVAClassification:: Total " << dataSamples[ns]->getSName() << " data events " << dataSamples[ns]->getNevents() << std::endl;
			}
      std::cout << "---------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	  }

   TTree* output_tree = TTree::MergeTrees(tree_list);
   //output_tree->SetTitle("DataTree");
   //output_tree->SetName("DataTree");
   // Here

   //outputFile->cd();
   gDirectory->Delete("Events;*");

// //----


   //
   TMVA::Factory* factory = new TMVA::Factory( "TMVAClassification", outputFile,
                                               "!V:!Silent:Color:DrawProgressBar=False:Transformations=I;D;P:AnalysisType=Classification" ); //I;D;P;G,D

   TMVA::DataLoader* dataloader=new TMVA::DataLoader(sname);

   //Defined in vbsDL.hpp
   //setVbsFactoryVarsAndSpectators(dataloader);
   setVbsDLorReaderVarsAndSpectators(dataloader,0,vbsEvent);
   // global event weights per tree (see below for setting event-wise weights)
   Double_t signalWeight     = 1.0;
   Double_t backgroundWeight = 1.0;


   dataloader->SetSignalWeightExpression    ("mcWeight*genWeight");//*L1PFWeight*puWeight*btagWeight_loose*lep1_idEffWeight*lep1_trigEffWeight");//*lep2_idEffWeight*lep2_trigEffWeight*pdfWeight*scaleWeight");
   dataloader->SetBackgroundWeightExpression("mcWeight*genWeight");//*L1PFWeight*puWeight*btagWeight_loose*lep1_idEffWeight*lep1_trigEffWeight");

   // You can add an arbitrary number of signal or background trees
   for (UInt_t ns=0; ns<sglSamples.size();ns++){
      if ( sglSamples[ns]->getInpTree() ) dataloader->AddSignalTree ( sglSamples[ns]->getInpTree(),     signalWeight     );
   }

   //Add backgrounds to factory
   //
   for (UInt_t ns=0; ns< bkgSamples.size();ns++){
      if ( bkgSamples[ns]->getInpTree() ) {
         if ( bkgSamples[ns]->getGName() == "Wjets" ) {
           // std::cout << "Weight factor = " << backgroundWeight << std::endl;
            dataloader->AddBackgroundTree( bkgSamples[ns]->getInpTree(), backgroundWeight    );
         }
         else {
           // std::cout << "Weight factor = " << backgroundWeight << std::endl;
            dataloader->AddBackgroundTree( bkgSamples[ns]->getInpTree(), backgroundWeight    );
         }
      }
   }
   //


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

//   dataloader->PrepareTrainingAndTestTree( mycuts, mycutb,
//                                        "nTrain_Signal=0:nTrain_Background=0:SplitMode=Random:NormMode=NumEvents:!V" );
   dataloader->PrepareTrainingAndTestTree( mycuts, mycutb,
                                        "nTrain_Signal=0:nTrain_Background=0:SplitMode=Random:NormMode=None:!V" );

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

//    TString layoutString ("Layout=TANH|100,TANH|50,TANH|10,LINEAR");
//    TString layoutString ("Layout=TANH|(N+30)*2,TANH|(N+30),TANH|10,LINEAR");
  TString layoutString ("Layout=RELU|64,RELU|32,RELU|32,SIGMOID|32,LINEAR");

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
   //   dnnOptions.Append (":"); dnnOptions.Append (trainingStrategyString);

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
                           "!H:!V:NTrees=1000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:MaxDepth=2:NegWeightTreatment=IgnoreNegWeightsInTraining");

   if (Use["BDT1"])  // Adaptive Boost
      factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDT1",
                           "!H:!V:NTrees=1000:MinNodeSize=1%:MaxDepth=4:BoostType=AdaBoost:AdaBoostBeta=0.6:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20:UseRandomisedTrees=False:UseNvars=2:NegWeightTreatment=IgnoreNegWeightsInTraining" ); // :NegWeightTreatment=IgnoreNegWeightsInTraining" );

   if (Use["BDT2"])
      factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDT2",
                           "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20:UseRandomisedTrees=True:NegWeightTreatment=IgnoreNegWeightsInTraining" ); // :NegWeightTreatment=IgnoreNegWeightsInTraining" );

   if (Use["BDT"])
      factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDT",
                           "!H:!V:NTrees=1000:MinNodeSize=1%:MaxDepth=4:BoostType=AdaBoost:AdaBoostBeta=0.2:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20:UseRandomisedTrees=False:UseNvars=2:NegWeightTreatment=IgnoreNegWeightsInTraining" ); // :NegWeightTreatment=IgnoreNegWeightsInTraining" );

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
//   stringstream ssAUCoutfile;
//    ssAUCoutfile << "ROC/" << "Run2_All_Methods.txt"; // AUCoutfile
//   std::ofstream AUCoutfile;
//   AUCoutfile.open(ssAUCoutfile.str(), std::ios_base::app);
//   std::vector<TString> mlist = TMVA::gTools().SplitString(myMethodList, ',');
//   TString time_and_date = getTimeAndDateString();
//
//   AUCoutfile << "" << std::endl;
//   AUCoutfile << "--------------------------------------------------" << std::endl;
//   AUCoutfile << time_and_date << std::endl;
//   for (UInt_t i=0; i<mlist.size(); i++) {
//      std::string regMethod(mlist[i]);
//      AUCoutfile << "AUC for " << regMethod << ":\t\t" << factory->GetROCIntegral(dataloader, regMethod) << std::endl;
//   }
//   AUCoutfile << "--------------------------------------------------" << std::endl;
//   AUCoutfile.close();
   writeAUCFile(myMethodList, dataloader, factory);
   // --------------------------------------------------------------

   cout << "Clone dataTree" << endl;
   output_tree->Write();

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


