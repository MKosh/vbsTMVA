/*
root -b
.L estimate.C
estimate(10,0.04)
*/

// Float_t sigma_mc  = 0.15;
Float_t sigma_mc  = 0.20;
Float_t sigma_acc = 0.15;
Float_t Lum = 225;
Float_t sigma_lum = 0.065;

void estimate(double Nmc, double acc)
{
   if (gSystem->Load("CL95_C.so") < 0) gSystem->CompileMacro("CL95.C","k");
   if (gSystem->Load("Significance_C.so") < 0) gSystem->CompileMacro("Significance.C","k");
   if (gSystem->Load("limit_calc_macro_C.so") < 0) gSystem->CompileMacro("limit_calc_macro.C","k");

   Float_t dNmc = Nmc*sigma_mc;
   Float_t dacc = acc*sigma_acc;
   Float_t dLum = Lum*sigma_lum;
   
   // consider data as MC
   Float_t Ndata = Nmc;
   
   cout<< "--> Ndata = " << Ndata << " Nmc = " << Nmc << " dNmc = " << dNmc << " acc = " << acc << " dacc = " << dacc << " Lum = " << Lum << " dLum = " << dLum <<endl;
   
   limit_calc_macro(Ndata, Nmc, dNmc, acc, dacc, Lum, dLum, 0);
}
