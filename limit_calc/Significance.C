//
// $Id: Significance.C,v 1.2 2019/09/20 06:20:53 uid13011 Exp $
//
// File: Significance.cpp
// Purpose: Compute the probability that the background flucuates to at least
//   the number of observed events.  The calculation assumes the background
//   uncertainty is gaussian, but uses a Poisson probability for all cases
//   of observed events.  The significance is
//
//       S = P(B>=N;<B>,Sigma_B) = 1 - P(B>=N;<B>,Sigma_B)
//                               = 1 - Sum(Integral(P(N;B)*G(B;<B>,Sigma_B)
//   in which P(N;B) is Poisson probabilty of N for a mean B and G(B;<B>,Sigma_B)
//   is the gaussian probability about the predicted background <B>.  The
//   integral itself is defined using a recursion relation.
//
//  Use Root for the erf calculation
//
// Created: 28-FEB-2003   
//
// $Revision: 1.2 $
//
//

// Include files
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include "TMath.h"
//-- static TMath *tm = new TMath();

using namespace std;
double cut=20.0;

//double GaussianSignificance(int ndata, double bkg, double sbkg);
double PoissonSignificance(int ndata, double bkg, double sbkg);
double PoissonSignificance(int ndata, double bkg);

double Significance(int ndata, double bkg, double sbkg=0.0)
{
  double pfluc = -1.0;  
  if( sbkg <= 0.0 /*|| sqrt(bkg)>cut*sbkg*/ ) pfluc=PoissonSignificance(ndata,bkg);
  else pfluc = PoissonSignificance(ndata,bkg,sbkg);
  return pfluc;
}

double PoissonSignificance(int ndata, double bkg)
{
  // Switch to gaussian method
  if( ndata>100 ) return -1.0;

  // Straight Poisson sum.  Beware that as in the routine below, we must
  // not use a 1-P(i<nData) form because of numerical round off...
  int nmax = 10*sqrt((double)ndata)+ndata;
  double coeff = 1.0;
  vector<double> terms;
  for( int i=0 ; i<nmax ; i++ ) {
    if( i>0 ) coeff = coeff*(bkg/i);
    if( i>=ndata ) terms.push_back(coeff);
  }

  // Now sort, sum, scale and return
  sort(terms.begin(),terms.end());
  double prob=0.0;
  for( unsigned int j=0 ; j<terms.size() ; j++ ) {
    prob += terms[j];
    //cout << terms[j] << ", Sum = " << prob <<  endl;
  }
  prob = exp(-bkg)*prob;
  return prob;
}

double PoissonSignificance(int ndata, double bkg, double sbkg)
//
// Purpose: 
//
// Arguements:
//
// Returns:
//
{
  static const double PI=3.1415927;
  static const double sr2 = sqrt(2.0);

  // The integral over the background can be evaluated analytically using
  // a trivial recursion relation.  Compute the first two terms from scratch
  // and then do the rest using recursion in the loop below.
  double a = (-bkg/sbkg+sbkg)/sqrt(2.0);
  //-- double erfa = tm->Erf(a);
  double erfa = TMath::Erf(a);
  //cout << a << " ==> " << erfa << endl;
  vector<double> gausint;
  gausint.push_back(0.5 * (1-erfa));
  gausint.push_back(0.5 * (-a + a*erfa + exp(-a*a)/sqrt(PI)));

  // Compute each term needed from 0 to nmax.  We must go from 0 to nData-1
  // to initialize the integral terms via the recursion relation.  For 
  // convenience, the coefficient for each i is also saved.  The full term
  // is calculated only for nData <= i <= nmax.  We must go all the way to
  // nmax because if we use only the terms with i<nData and then compute 
  // P(N>=nData) = 1-P(N<nData), we get bitten by round off error.
  int nmax = 10*sqrt((double)ndata)+ndata;
  double coeff=1.0;  // bkg^k/k!
  vector<double> terms;
  for( int k=0 ; k<nmax ; k++ ) {
    // Set up the various coefficients (all using recursion)
    if( k>=1 ) {
      coeff = coeff*(sr2*sbkg/k);
      if( k>1 ) gausint.push_back(-a*gausint[k-1] + (k-2)*gausint[k-2]/2.0);
    }
    //cout << k << ": " << coeff << ", " << gausint[k]
    //	 << " => " << coeff*gausint[k] << endl;
    if( k>=ndata ) terms.push_back(coeff*gausint[k]);
  }

  // Now sort the individual terms in increasing order.  Then the sum 
  // will have minimized numerical round off effects.  Finally, apply
  // the constant terms and return.
  sort(terms.begin(),terms.end());
  double prob = 0.0;
  for( unsigned int j=0 ; j<terms.size() ; j++ ) {
    prob += terms[j];
    //cout << terms[j] << ", Sum = " << prob << endl;
  }

  // Compute the overall multiplicative normalization and return the
  // probability
  double factor = exp(-bkg)*exp(sbkg*sbkg/2.0);
  prob = prob*factor;
  return prob;
}

#ifdef STANDALONE
int main(int argc, char **argv)
{
  if( argc != 3 && argc !=4 ) {
    cout << "Use: significance ndata bkg [sbkg]" << endl;
    return 1;
  }

  // Get the arguements
  int ndata = atoi(argv[1]);
  double bkg = atof(argv[2]);
  double sbkg = -1;
  if( argc == 4 ) sbkg = atof(argv[3]);
    
  // Compute the probability
  double prob = Significance(ndata,bkg,sbkg);
  cout << "Probability(" << bkg<< " => " <<ndata << ") = " << prob << endl;
  return 0;
}
#endif
