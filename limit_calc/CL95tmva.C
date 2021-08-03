/* --------------------------------------------------------------------------------
   Bayesian 95% CL limit calculator for Poisson or Gaussian statistics
   Usage: sigma95A = CLA(ilum, slum, eff, seff, bck, sbck, n, gauss = false)

   Inputs: ilum - Nominal integrated luminosity (pb^-1)
           slum - Absolute error on the integrated luminosity
           eff  - Nominal value of the efficiency times acceptance
           seff - Absolute error on the efficiency times acceptance
           bck  - Nominal value of the background estimate
           sbck - Absolute error on the background
           n    - Number of observed events
           gauss - if true, use Gaussian statistics; automatically false for n = 0

   Note: It is strongly suggested to use Gaussian statistics for n > 100, as the Poisson
         distribution function has been sped up by tabulating its values up to n = 100 and
         the code will gradually slow down for n > 100. Note further that there is always
         a discontinuity when switching from a Poisson to a Gaussian case, which is due to 
         an inheritant difference between the discreet and continuous distributions. The 
         difference is of the order of one event.

   Written  by Greg Landsberg; v1.0 February 27, 2003
   Modified by Greg Landsberg; v1.1 March 18, 2003 - some bugs fixed; 
                                                     automatic graph scaling
   Modified by Greg Landsberg; v1.2 May 15, 2003   - clean-up of the code; 

   Modifyed by Sergey Uzunyan  v1.2-ROOTv6.xx  Jan 26, 2018
             - changed integral calculations for a new TF1 func 
-------------------------------------------------------------------------------- */
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "TMath.h"
#include "TF1.h"
#include "TArrow.h"
#include "TCanvas.h"
using namespace std;

static Double_t A0, sA, B0, sB, epsilon, MaxSig = 100.;
static Double_t MinLike = 1.e-6, ErrMin = 1.e-5, Precision = 1.e-5;
static Int_t N;
static bool lGauss = false;

//Change me to debug
static int Debug = 0;

TF1 *final_likelihood=0;
TCanvas *confidence_canvas=0;
TArrow *arrow=0;

Double_t Likelihood(Double_t *x, Double_t *p);
Double_t Inner(Double_t *x, Double_t *par);
Double_t Outer(Double_t *x, Double_t *p);
Double_t Poisson(Double_t Mu, Int_t n);
Double_t CL95(Double_t ilum, Double_t slum, Double_t eff, Double_t seff, Double_t bck, Double_t sbck, Int_t n, Bool_t gauss = false);
Double_t CalcCL95(Double_t ilum, Double_t slum, Double_t eff, Double_t seff, Double_t bck, Double_t sbck, Int_t n, Bool_t gauss = false);

Double_t CL95(Double_t ilum, Double_t slum, Double_t eff, Double_t seff, Double_t bck, Double_t sbck, Int_t n, Bool_t gauss) {
  Double_t xmax = CalcCL95(ilum,slum,eff,seff,bck,sbck,n,gauss);
  confidence_canvas->Print("Likelihood.eps");
  cout << "Upper 95% C.L. limit on signal = " << xmax << " pb" << endl;
  delete final_likelihood;
  delete confidence_canvas;
  return xmax;
//
}

Double_t CalcCL95(Double_t ilum, Double_t slum, Double_t eff, Double_t seff, Double_t bck, Double_t sbck, Int_t n, Bool_t gauss)
{
   Double_t xmax = MaxSig;
   Double_t x[1], p[1];
//
   A0 = ilum*eff;
//   sA = TMath::Max(ErrMin,sqrt(ilum*seff*ilum*seff + eff*slum*eff*slum));
   sA = sqrt(ilum*seff*ilum*seff + eff*slum*eff*slum);
   B0 = bck;
//   sB = TMath::Max(ErrMin,sbck);
   sB = sbck;
   epsilon = TMath::Max(Precision/ilum,1.e-4);
//
   lGauss = gauss;
   if (n == 0) lGauss = false;
//
   N = n;
   x[0] = xmax;
//
   if(Debug)  cout << "CalcCL95:: A0/sA/B0/sB/epsilon = " << A0 << "/" << sA << "/" << B0 << "/"  <<  sB << "/" << epsilon   << endl; 
   if(Debug)  cout << "ilum/slum/eff/bck/sbck/n = " << ilum << " / " << slum << " / " << eff << " / " << bck << " / " << sbck << " / " << n << " / " << endl;  
   Double_t delta = (Likelihood(x,p) - MinLike)/MinLike;
   if(Debug) cout << "CalcCL95:call Delta:: Delta/x0/p0/Minlike = " << delta << "/" << x[0] << "/" << p[0] << "/" << MinLike << endl; 

   while (delta > 0)
   {
      xmax = 2.*xmax;
      x[0] = xmax;
      delta = (Likelihood(x,p) - MinLike)/MinLike;
   }
//
   Double_t x1 = 0, x2 = xmax;
   while (fabs(delta) > epsilon) 
   {      
      if (delta > 0) x1 = x[0];
      else x2 = x[0];
      x[0] = (x1 + x2)/2.;
      delta = (Likelihood(x,p) - MinLike)/MinLike;
    if(Debug) cout << "CalcCL95: Delta = " << delta << endl; 
   }         
 
   if(Debug){
     cout << "End debug, exiting " << endl;
     exit(0);
   }

   xmax = x[0];
//

   Int_t i = 0;
   if (xmax > 1)
   {
      while (xmax > 10.)
      {
         xmax /= 10.;
         i++;
      }
      xmax = (Int_t)(xmax + 1)*pow(double(10.),i);
   }
   else
   {
      while (xmax < 1.)
      {
         xmax *= 10.;
         i++;
      }
      xmax = (Int_t)(xmax + 1)*pow(double(10.),-i);
   }
//
   TF1 *like = new TF1("Likelihood",Likelihood,0.,xmax,0);
   if (Debug) { cout << "Likelihood function is evaluated over [0," << xmax << "]\n"; }
   //
   //Double_t Norm = like->Integral(0.,xmax,p,epsilon);      // used in ROOT v5.XX
   like->SetParameters(p);
   Double_t Norm = like->Integral(0.,xmax,epsilon);

//
   x1 = 0;
   x2 = xmax;
   xmax = (x1 + x2)/2.;

    //delta = like->Integral(0,xmax,p,epsilon)/Norm - 0.95; // used in ROOT v5.XX

    like->SetParameters(p);
    delta = like->Integral(0,xmax,epsilon)/Norm - 0.95;
//
   while (fabs(delta) > epsilon) 
   {
      if (delta < 0) x1 = xmax;
      else x2 = xmax;
      xmax = (x1 + x2)/2.;
      
     //delta = like->Integral(0,xmax,p,epsilon)/Norm - 0.95;   // used in ROOT v5.XX
      
      like->SetParameters(p);
      delta = like->Integral(0,xmax,epsilon)/Norm - 0.95;
   }         
   
   x[0] = like->GetMaximumX(0.,MaxSig);
//    arrow = new TArrow(xmax,Likelihood(x,p)/7.,xmax,0,0.04);
//     TCanvas *c = new TCanvas("cl","Confidence Limit",700,500);
//    like->Draw();
//    arrow->SetLineWidth(3.);
//    arrow->Draw();

   final_likelihood = like;
   //   confidence_canvas = c;
   return xmax;
}

Double_t Likelihood(Double_t *x, Double_t *p)
{
   Double_t retval;
   if (sB == 0.)
   {
      if (sA == 0.) 
      {
         if (lGauss) retval = 1./sqrt(2.*TMath::Pi()*N)*exp(-(N-B0-x[0]*A0)*(N-B0-x[0]*A0)/2./N);
         else retval = Poisson(B0+x[0]*A0,N);
      }
      else 
      {
         Double_t sigma, par[2];
         TF1 *in = new TF1("Inner",Inner,0.,A0 + 5.*sA,2);
         par[0]=B0;  // background value
         par[1]=x[0];  // signal cross section value
         Double_t low = A0 > 5.*sA ? A0 - 5.*sA : 0.;
	 // retval = in->Integral(low,A0+5.*sA,par,epsilon);  // used in ROOT v5.XX
         in->SetParameters(par);
         retval = in->Integral(low,A0+5.*sA,epsilon);
         if(Debug) cout << " Likelihood::in, setParameters(), par[0]/par[1]= " << par[0] << "/" <<  par[1] << endl;

         delete in;
      }
   }
   else
   {
      TF1 *out = new TF1("Outer",Outer,0.,B0 + 5.*sB,1);   
      Double_t low = B0 > 5.*sB ? B0 - 5.*sB : 0.;
      // retval = out->Integral(low,B0+5.*sB,x,epsilon);     // used in ROOT v5.XX
      out->SetParameters(x);
      //cout << "Debug -- Integral --" << endl;
      if(Debug) cout << "low/B0+5*sB/epsilon " << low << "/" << B0+5.0*sB << "/" << epsilon << endl;
      retval = out->Integral(low,B0+5.*sB,epsilon); // ERROR starts from here -- Step 1 ------------------------------------------------------------------------------------------------------------------------------
      if(Debug) cout << "  Likelihood::out, x[0]/retval/ = " << x[0] << "/" << retval << endl;  
      delete out;
   }
   return retval;
}

Double_t Inner(Double_t *x, Double_t *par)
{
    Double_t sigma, B;
//
    B = par[0];
    sigma = par[1];
    if (lGauss) return 1./(2.*TMath::Pi()*sqrt(double(N)))/sA*exp(-(x[0]-A0)*(x[0]-A0)/2./sA/sA)*exp(-(N-B-sigma*x[0])*(N-B-sigma*x[0])/2./N);
    else        return 1./sqrt(2.*TMath::Pi())/sA*exp(-(x[0]-A0)*(x[0]-A0)/2./sA/sA)*Poisson(B+sigma*x[0],N);
}

Double_t Outer(Double_t *x, Double_t *p)
{
   Double_t retval;
   if (sA == 0.) 
   {
      if (lGauss) retval = 1./(2.*TMath::Pi()*sqrt(double(N)))/sB*exp(-(x[0]-B0)*(x[0]-B0)/2./sB/sB)*exp(-(N-x[0]-p[0]*A0)*(N-x[0]-p[0]*A0)/2./N);
      else retval = 1./sqrt(2.*TMath::Pi())/sB*exp(-(x[0]-B0)*(x[0]-B0)/2./sB/sB)*Poisson(x[0]+p[0]*A0,N);
   }
   else 
   {
      Double_t sigma, par[2];
      TF1 *in = new TF1("Inner",Inner,0.,A0 + 5.*sA,2);
      par[0]=x[0];  // background value // I don't understand how, but it gives the ?right? value. 
      par[1]=p[0];  // signal cross section value
      Double_t low = A0 > 5.*sA ? A0 - 5.*sA : 0.;
      if (Debug) cout << "par[0]/par[1] = " << par[0] << " / " << par[1] << endl;
      //retval = 1./sqrt(2.*TMath::Pi())/sB*exp(-(x[0]-B0)*(x[0]-B0)/2./sB/sB)*in->Integral(low,A0+5.*sA,par,epsilon);  // used in ROOT v5.XX
      in->SetParameters(par);
      retval = 1./sqrt(2.*TMath::Pi())/sB*exp(-(x[0]-B0)*(x[0]-B0)/2./sB/sB)*in->Integral(low,A0+5.*sA,epsilon); // ERROR continues here -- step 2: Integrating over this "Inner" function
      delete in;
   }
   return retval;
}

Double_t Poisson(Double_t Mu, Int_t n)
{
   Double_t logP;
//
// Tabulate values of \sum log(i+2) up to n=100 for faster calculation
//
   Double_t logTable[99] =  {   -0.69314718,   -1.79175947,   -3.17805383,   -4.78749174,   -6.57925121,   -8.52516136,  -10.60460290,  -12.80182748,  -15.10441257,  -17.50230785,
                               -19.98721450,  -22.55216385,  -25.19122118,  -27.89927138,  -30.67186011,  -33.50507345,  -36.39544521,  -39.33988419,  -42.33561646,  -45.38013890,
                               -48.47118135,  -51.60667557,  -54.78472940,  -58.00360522,  -61.26170176,  -64.55753863,  -67.88974314,  -71.25703897,  -74.65823635,  -78.09222355,
                               -81.55795946,  -85.05446702,  -88.58082754,  -92.13617560,  -95.71969454,  -99.33061245, -102.96819861, -106.63176026, -110.32063971, -114.03421178,
                              -117.77188140, -121.53308152, -125.31727115, -129.12393364, -132.95257504, -136.80272264, -140.67392365, -144.56574395, -148.47776695, -152.40959258,
                              -156.36083630, -160.33112822, -164.32011226, -168.32744545, -172.35279714, -176.39584841, -180.45629142, -184.53382886, -188.62817342, -192.73904729,
                              -196.86618167, -201.00931640, -205.16819948, -209.34258675, -213.53224149, -217.73693411, -221.95644182, -226.19054832, -230.43904357, -234.70172344,
                              -238.97838956, -243.26884900, -247.57291410, -251.89040221, -256.22113555, -260.56494097, -264.92164980, -269.29109765, -273.67312429, -278.06757344,
                              -282.47429269, -286.89313330, -291.32395009, -295.76660135, -300.22094865, -304.68685677, -309.16419358, -313.65282995, -318.15263962, -322.66349913,
                              -327.18528770, -331.71788720, -336.26118198, -340.81505887, -345.37940706, -349.95411804, -354.53908552, -359.13420537, -363.73937556 };
                              
   logP = -Mu + n*log(Mu);
   if (n > 2) logP += logTable[TMath::Min(n,100)-2];
   
   for (Int_t i = 101; i <= n; i++) logP -= log((Double_t) i);
 
   return exp(logP);
}



