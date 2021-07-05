# CMS Draft Analysis Note v13

## Notes
- Zjets = DY
- Diboson = VBS_QCD

## Backgrounds

### Top background variables plotted
- Lepton pt
- Lepton eta
- PuppiMET
- Trailing VBS jet pt
- deta VBS jets
- M_jj VBS (invariable mass of VBS jets)
- Pt W leptonic
- Whad reco mass
- Zepp. Lepton
- nJets cleaned from AK8 >= 30 GeV
- dphi VBS jets
- W hadronic Pt
- Qgl \<VBS 0 jet, Vjet 0 jet, Vjet 1 jet\> (Quark Gluon Likelihood for 1st VBS jet and Vjets)

### W+ jets background
Same as above, plus
- W boson centrality

### Non-prompt background
- Lepton pt
- Lepton eta
- Mass T W leptonic
- PuppiMET_pt

## Signal

### Variables for DNN training
| Variable   | Description              |
| :---       | :---                     |
| Lepton $\eta$ | Lepton Pseudorapidity    |
| Lepton $p_T$  | Lepton transverse momentum |
| Njets | Number of jets with pt > 30 GeV |
| ${p_T}^0_{VBS}$ | pT 1st VBS jet |
| ${p_T}^1_{VBS}$ | pT 2nd VBS jet |
| ${p_T}_{Vjets}^{0}$ | pT 1st jet from hadronic V or boosted V pT |
| ${p_T}^0_{VBS}$ | pT 2nd jet from hadronic V |
| $M^{vbs}_{jj}$ | Invariant mass of the VBS tag jets pair |
| $M^{V}_{jj}$ | Invariant mass of the had V jets or boosted V mass |
| $\Delta \eta^{vbs}$ | Pseudorapidity interval between VBS jets |
| $\Delta \phi^{vbs}$ | Azimuthal distance between VBS jets |
| $\Delta \eta^{Vjets}$ | Pseudorapidity interval between hadronic V jets |
| $Z^{lep}$ | Zeppenfeld variable for the lepton |
| $Z^{vjet}_0$ | Zeppenfeld variable fo rthe boosted V jet |
| $C_{VW}$ | hadronic V boson centrality |

## Vars R.S. Plotted
| R.S. | My Analysis |
| :--- | :--- |
| boson_centrality | bosCent |
| dijet_eta | bos_AK4AK4_eta |
| dijet_j1_eta | bos_j1_AK4_eta |
| dijet_j1_pt | bos_j1_AK4_pt |
| dijet_j2_eta | bos_j2_AK4_eta |
| dijet_j2_pt | bos_j2_AK4_pt |
| dijet_m | bos_AK4AK4_m |
| dijet_pt | bos_AK4AK4_pt |
| fajet_eta | bos_PuppiAK8_eta |
| fatjet_m | bos_PuppiAK8_m_sd0_corr |
| fatjet_phi | bos_PuppiAK8_phi |
| fatjet_pt | bos_PuppiAK8_pt |
| fatjet_tau21 | bos_PuppiAK8_tau2tau1 |
| lept1_eta | lep1_eta |
| lept1_phi | lep1_phi |
| lept1_pt | lep1_pt |
| lept2_eta | lep2_eta |
| lept2_phi | lep2_phi |
| lept2_pt | lep2_pt |
| mva_score_wv |  |
| mva_score_wv_log |  |
| mva_score_wv_var1 |  |
| mva_score_wv_var1_log |  |
| pf_met_corr | MET |
| pf_met_corr_phi | MET_phi |
| v_eta |  |
| v_m |  |
| v_mt |  |
| v_pt |  |
| vbf_j1_eta | vbf1_AK4_eta |
| vbf_j1_phi | vbf1_AK4_phi |
| vbf_j1_pt | vbf1_AK4_pt |
| vbf_j2_eta | vbf2_AK4_eta |
| vbf_j2_phi | vbf2_AK4_phi |
| vbf_j2_pt | vbf2_AK4_pt |
| vbf_jj_Deta | vbf_deta |
| vbf_jj_m | vbf_m |
| vv_eta | dibos_eta |
| vv_m | dibos_m |
| vv_phi | dibos_phi |
| vv_pt | dibos_pt |
| zeppenfeld_v_Deta |  |
| zeppenfeld_w_Deta |  |
|  |  |
|  |  |