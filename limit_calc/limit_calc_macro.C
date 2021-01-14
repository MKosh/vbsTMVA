//=================================================================
//   Purpose and Methods: Implement a limit calculation ala D02775A/
//
// VERSION 4 is essentially a complete rewrite using root and its capability
// to perform numerical integration. The significance calculation now uses
// a closed form for the calculation.  Direct support for Quaero has been
// removed as of version 4.
//
//   Created  01-MAY-1996   John Hobbs
//   Modified 27-Apr-2001   Bruce Knuteson (Version 2)
//   Modified 30-Jul-2002   John Hobbs
//   Modified 28-Feb-2003   John Hobbs, Greg Landsberg (Version 4)
//
//  NOTES:
//
//   1. To compile a standalone executable, define the compile directive STANDALONE
//   2. To get the QUAERO behaviour, define the compiler directive QUAERO. 
//        The DZero behaviour is the default
//
//  HISTORY:
//
// ************************* Version 4 **************************************
//
//  Remove the limit calculation from this code and use Greg Landsberg's
//   Confidence.cpp to calculate cross section limits.  Use an analytic
//   implementation of Significance.cpp (Hobbs) for calculating probability
//   that background alone flucuates to observation or higher.
//  Remove the Quaero compatibility
//
//      This code now requires Root.
//
// ************************* Version 3 ***************************************
//
//  Port to NT: lgamma and srand48, drand48 replacements.  See _WIN32 #ifdef
//  make nsim static at file scope in order to make the original interface work
//   properly.
//
// ************************* Version 2 ***************************************
//
//  JDH, Reinstate previous get_limit interface via overload of get_limit
//  JDH, Reinstate main using #ifdef STANDALONE switches
//  JDH, Define QUAERO, which gives Bruce Knutson's (non-DZero) standard
//        method to handle negative lumi, acceptance or background.
//
//  From: Bruce Knuteson [knuteson@d0mino.fnal.gov]
//  Sent: Friday, April 27, 2001 3:52 PM
//  To: hobbs@sbhep.physics.sunysb.edu
//  Subject: limit_calc.cc
//
//  Hi John,
//
//  Given our discussion last evening, I took the liberty of modifying your limit calculator this afternoon.  I've checked that my modifications give results equivalent to yours in particular cases.
//
//  Changes worth noting:
//   - Quantities with large fractional errors are handled in a reasonable way (the way that I generally handle them, at least).
//   - Use of the standard template vector avoids a memory leak in the old code but means that the new code should be compiled with -O2 to run at a reasonable speed.
//   - Any number of expected bkg or data events should be acceptable
//   - I've clobbered the feature that allows several experiments to be included at the same time (sorry).
//   - Precision per unit running time should be improved compared to the old code, although I haven't attempted to quantify this.
//
//  Please let me know if you find any errors :-)
//
//  cheers,
//  Bruce

// ***********************  Version 1 ****************************************
//  First working version

#include <cstring>
#include <cmath>
#include <iostream>
#include "TCanvas.h"
#include "TF1.h"
#include "TStyle.h"
#include "TH1.h"

using namespace std;

// Eventually, put this in a base class for all confidence limit calculations
extern TCanvas *confidence_canvas;
extern TF1 *final_likelihood;

Double_t CalcCL95(Double_t ILum, Double_t slum,
		  Double_t eff, Double_t seff, 
		  Double_t bck, Double_t sbck, 
		  Int_t Nev, Bool_t IfGauss);

double Significance(int ndata, double bkg, double sbkg);

// int main(int argc,char **argv)
// {
// 
//   if( argc != 9 ) {
//     cout << "Insufficient data on command line" <<endl;
//     cout << "Use: limit_calc ndata nbkg sbkg acc sacc lumi slumi force_gauss(=0 for web page)"
// 	 << endl;
//     return(1);
//   }

  int limit_calc_macro(int ndata, double nbkg, double sbkg, double acc, double acc_error, double lumi, double lumi_error, bool IfGauss=0) {
  // Set up the root style (empty backgrounds, not grey pattern)
  gStyle->SetPadColor(0);
  gStyle->SetCanvasColor(0);

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
  double cl95res = CalcCL95(lumi, lumi_error, 
			    acc, acc_error, 
			    nbkg, sbkg, 
			    ndata, IfGauss);

  // and compute the probability that background flucuates to at least
  // the observed data.
  double pfluc = Significance(ndata, nbkg, sbkg);

  // Produce the JPEG plot of the cross section pdf
  char *fname = "limit_calc.eps";
  final_likelihood->GetHistogram()->GetXaxis()->SetTitle("Cross Section, 1/Lumi units");
  final_likelihood->GetHistogram()->GetYaxis()->SetTitle("Probability density");
  //confidence_canvas->Update();
  confidence_canvas->Print(fname);

  // and write out the information to be picked up by the HTML writer.
  cout << "LIMIT_CALC-RESULTS " << cl95res << "  " << pfluc << "  "  << fname << endl;
  

  return 0;
}
