//-- limit_calc compiled under ROOT v4.00/08b

// howto run
limit> ./limit_calc
Insufficient data on command line
Use: limit_calc ndata nbkg sbkg acc sacc lumi slumi force_gauss(=0 for web page)

limit> ./limit_calc 28 30.44 5.065 0.0346 0.0052 248 14.88 0

// medium muons only: single muon
limit> ./limit_calc 28 30.4378 5.06511 0.0345806 0.0051871 248 14.88 0
Likelihood function is evaluated over [0,6]
Info in <TCanvas::Print>: eps file limit_calc.eps has been created
LIMIT_CALC-RESULTS 1.80029  0.105189  limit_calc.eps
// our result for single muons (medium only) is 1.80029
// medium muons only: dimuon
limit> ./limit_calc 3 2.22242 0.600886 0.0107097 0.00160645 248 14.88 0
Likelihood function is evaluated over [0,10]
Info in <TCanvas::Print>: eps file limit_calc.eps has been created
LIMIT_CALC-RESULTS 2.44629  0.304932  limit_calc.eps
// our result for dimuons (medium only) is 2.44629

limit>
limit>
// medium/loose muons: single muon
limit> ./limit_calc 28 28.9526 4.99972 0.032129 0.00481935 248 14.88 0
Likelihood function is evaluated over [0,7]
Info in <TCanvas::Print>: eps file limit_calc.eps has been created
LIMIT_CALC-RESULTS 2.05078  0.0832737  limit_calc.eps
// our result for single muons (medium/loose) is 2.05078
limit> ./limit_calc 3 3.76408 1.00978 0.0135484 0.00203226 248 14.88 0
Likelihood function is evaluated over [0,8]
Info in <TCanvas::Print>: eps file limit_calc.eps has been created
LIMIT_CALC-RESULTS 1.72266  0.503154  limit_calc.eps
// our result for single muons (medium/loose) is 1.72266  <-- slightly better
limit>
limit>
limit> echo combine
//-- combine
limit>
// medium muons only
limit> ./limit_calc 31 32.66022 5.10 0.0452903 0.005430 248 14.88 0
Likelihood function is evaluated over [0,5]
Info in <TCanvas::Print>: eps file limit_calc.eps has been created
LIMIT_CALC-RESULTS 1.42334  0.119454  limit_calc.eps
//-- combine result for medium muons only is 1.42334
limit>
limit>
limit>
limit>
// medium/loose muons
limit> ./limit_calc 31 32.71668 5.100 0.0456774 0.005230 248 14.88 0
Likelihood function is evaluated over [0,5]
Info in <TCanvas::Print>: eps file limit_calc.eps has been created
LIMIT_CALC-RESULTS 1.40137  0.120777  limit_calc.eps
//-- combine result for medium/loose muons is 1.40137


//-- 170 GeV --//

limit>
//-- 170 GeV single medium
limit> ./limit_calc 28 30.4378 5.06511 0.0454286 0.00681429 248 14.88 0
Likelihood function is evaluated over [0,5]
Info in <TCanvas::Print>: eps file limit_calc.eps has been created
LIMIT_CALC-RESULTS 1.37085  0.105189  limit_calc.eps
// res for 170 GeV single medium is 1.37085
limit> echo 'that was 170 GeV single medium'
that was 170 GeV single medium
limit>
limit>
limit> echo '170 GeV, dimuon medium'
// 170 GeV, dimuon medium
limit> ./limit_calc 3 2.22242 0.600886 0.0108571 0.00162857 248 14.88 0
Likelihood function is evaluated over [0,10]
Info in <TCanvas::Print>: eps file limit_calc.eps has been created
LIMIT_CALC-RESULTS 2.41211  0.304932  limit_calc.eps
// res for 170 GeV, dimuon medium is 2.41211
limit>
limit> echo 'combined single+dimuon for medium muons only'
// combined single+dimuon for medium muons only
limit>
limit> ./limit_calc 31 32.66022 5.10 0.0562857 0.0070 248 14.88 0
Likelihood function is evaluated over [0,4]
Info in <TCanvas::Print>: eps file limit_calc.eps has been created
LIMIT_CALC-RESULTS 1.14941  0.119454  limit_calc.eps
// combined single+dimuon for medium muons only: 1.14941
limit>
limit>
limit> echo '170 GeV medium/loose muons'
//-- 170 GeV medium/loose muons
limit>
limit> echo '170 GeV medium/loose muons: single'
// 170 GeV medium/loose muons: single
limit>
limit> ./limit_calc 28 28.9526 4.99972 0.0415238 0.00622857 248 14.88 0
Likelihood function is evaluated over [0,6]
Info in <TCanvas::Print>: eps file limit_calc.eps has been created
LIMIT_CALC-RESULTS 1.58643  0.0832737  limit_calc.eps
// res for 170 GeV medium/loose muons: single is 1.58643
limit>
limit> echo '170 GeV medium/loose muons: dimuon'
// 170 GeV medium/loose muons: dimuon
limit>
limit> ./limit_calc 3 3.76408 1.00978 0.0153333 0.0023 248 14.88 0
Likelihood function is evaluated over [0,7]
Info in <TCanvas::Print>: eps file limit_calc.eps has been created
LIMIT_CALC-RESULTS 1.52271  0.503154  limit_calc.eps
// res for 170 GeV medium/loose muons: dimuon is 1.52271
limit>
limit> echo '170 GeV medium/loose muons: combined'
// 170 GeV medium/loose muons: combined
limit>
limit> ./limit_calc 31 32.71668 5.10 0.0568571 0.00664 248 14.88 0
Likelihood function is evaluated over [0,4]
Info in <TCanvas::Print>: eps file limit_calc.eps has been created
LIMIT_CALC-RESULTS 1.12793  0.120777  limit_calc.eps
// res for 170 GeV medium/loose muons: combined is 1.12793
limit>
