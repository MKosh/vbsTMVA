/*
.500  35  15.8
.525  30  15.8
.550  26  15.8
.575  25  15.8
.600  22  15.7
.625  21  15.7
.650  20  15.7
.675  19  15.7
.700  16  15.7
*/

void met_dphi_fit()
{
   const Int_t np = 9;
   cout<< "np=" << np <<endl;

   Float_t x[np]    = {.500, .525, .550, .575, .600, .625, .650, .675, .700};
   Float_t ydat[np] = {35,   30,   26,   25,   22,   21,   20,   19,   16};
   Float_t ybkg[np] = {15.8, 15.8, 15.8, 15.8, 15.7, 15.7, 15.7, 15.7, 15.7};
   Float_t y[np];
   Float_t dy[np];

   TFile* f = TFile::Open("met_dphi_fit.root", "recreate");
   
   TH1F* qcd = new TH1F("qcd", "Fit to Data - #SigmaMC; #Delta#phi missingET and nearest jet; Events with missingET 50-55 GeV", np, x[0], x[np-1]+x[1]-x[0]);
   qcd->Sumw2();
   
   for (int i=0; i<np; ++i) {
      y[i]  = ydat[i] - ybkg[i];
      dy[i] = sqrt(y[i]);
      qcd->SetBinContent(i+1,  y[i]);
      qcd->SetBinError  (i+1, dy[i]);
      cout<< x[i] <<"\t "<< y[i] <<"\t "<< dy[i] <<endl;
   }
   
   gStyle->SetOptFit();
   qcd->Fit("expo", "", "", .5, .7);
   
   Float_t marker_x [1] = {.7};
   Float_t marker_dx[1] = {.01};
   Float_t marker_y [1] = {2.8};
   Float_t marker_dy[1] = {1};
   
   TGraphErrors* marker = new TGraphErrors(1, marker_x,marker_y,marker_dx,marker_dy);
   marker->SetMarkerStyle(20);
   marker->SetMarkerColor(2);
   marker->SetLineColor(2);
   // marker->SetLineWidth(2);
   
   TCanvas* canv;
   canv = new TCanvas();
   gPad->SetLogy(1);
   qcd->Draw();
   marker->Draw("same p");
   canv->Update();
   canv->SaveAs("met_dphi_fit.ps");
   canv->SaveAs("met_dphi_fit.gif");
}
