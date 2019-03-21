#include "NTupler.h"

int main (int argc, char *argv[]) {
    
    ifstream variable_file;
  variable_file.open("./Zjet_data.dat");
//  variable_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/dijet_data_MPIoff_PFmassless.dat");
//  variable_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/dijet_data_parton.dat");
//  variable_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/qg/quark_jet_data.dat");
//  variable_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/qg/gluon_jet_data.dat");
//  variable_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/ATLAS/13_TeV/dijet_data.dat");
//  variable_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/dijet_data_MPIoff.dat");
//  variable_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/7_TeV/Zjet_data.dat");
//  variable_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/Zjet_data.dat");
//  variable_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/ATLAS/5_TeV/dijet_data.dat");
//  variable_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/gammajet_data.dat");
//  variable_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/ATLAS/7_TeV/dijet_data.dat");
//  variable_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/dijet_data.dat");
//  variable_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/dijet_data_PFmassless.dat");
//  variable_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/ALICE/data.dat");
    
const double PI = 3.1415927;
double photon_pT, photon_eta, photon_phi;
double Z_pT, Z_eta, Z_phi, Z_m;
double Z_drop;
double jet_pT, jet_eta, jet_m;
double jet1_pT, jet1_eta, jet1_m;
double jet2_pT, jet2_eta, jet2_m;
double delta_phi_1, delta_phi_2;
double jet_pT_SD1, jet_eta_SD1, jet_phi_SD1, jet_zg_SD1, jet_rg_SD1, jet_m_SD1;
double jet_pT_SD2, jet_eta_SD2, jet_phi_SD2, jet_zg_SD2, jet_rg_SD2, jet_m_SD2;
double jet_pT_SD3, jet_eta_SD3, jet_phi_SD3, jet_zg_SD3, jet_rg_SD3, jet_m_SD3;
double jet_pT_SD4, jet_eta_SD4, jet_phi_SD4, jet_zg_SD4, jet_rg_SD4, jet_m_SD4;
double jet1_pT_SD1, jet1_eta_SD1, jet1_phi_SD1, jet1_zg_SD1, jet1_rg_SD1, jet1_m_SD1;
double jet1_pT_SD2, jet1_eta_SD2, jet1_phi_SD2, jet1_zg_SD2, jet1_rg_SD2, jet1_m_SD2;
double jet1_pT_SD3, jet1_eta_SD3, jet1_phi_SD3, jet1_zg_SD3, jet1_rg_SD3, jet1_m_SD3;
double jet1_pT_SD4, jet1_eta_SD4, jet1_phi_SD4, jet1_zg_SD4, jet1_rg_SD4, jet1_m_SD4;
double jet2_pT_SD1, jet2_eta_SD1, jet2_phi_SD1, jet2_zg_SD1, jet2_rg_SD1, jet2_m_SD1;
double jet2_pT_SD2, jet2_eta_SD2, jet2_phi_SD2, jet2_zg_SD2, jet2_rg_SD2, jet2_m_SD2;
double jet2_pT_SD3, jet2_eta_SD3, jet2_phi_SD3, jet2_zg_SD3, jet2_rg_SD3, jet2_m_SD3;
double jet2_pT_SD4, jet2_eta_SD4, jet2_phi_SD4, jet2_zg_SD4, jet2_rg_SD4, jet2_m_SD4;
double Z_jet_1_m, Z_jet_2_m, Z_jet_3_m, Z_jet_4_m, Z_jet_5_m;
double Z_jet_1_pT, Z_jet_2_pT, Z_jet_3_pT, Z_jet_4_pT, Z_jet_5_pT;

const double pT_bin_up = 250, pT_bin_low = 200;
//const double eta_bin = 1.5;
    
//const double Z_pT_bin_up = 500, Z_pT_bin_low = 120;
//const double jet_pT_bin1_up = 150, jet_pT_bin1_low = 125;
//const double jet_pT_bin2_up = 220, jet_pT_bin2_low = 150;
//const double jet_pT_bin3_up = 300, jet_pT_bin3_low = 220;
//const double jet_pT_bin4_up = 450, jet_pT_bin4_low = 300;
//double jet_pT_bin_up = jet_pT_bin4_up, jet_pT_bin_low = jet_pT_bin4_low;
//const double Z_eta_bin = 2.5;
//const double jet_eta_bin = 2.5;

//const double Z_pT_bin_up = 300, Z_pT_bin_low = 60;
//const double jet_pT_bin_up = 300, jet_pT_bin_low = 30;
//const double Z_eta_bin = 2.5;
//const double jet_eta_bin = 1.6;

const double pT_bin1_up = 158, pT_bin1_low = 126;
const double pT_bin2_up = 199, pT_bin2_low = 158;
const double pT_bin3_up = 251, pT_bin3_low = 199;
const double pT_bin4_up = 316, pT_bin4_low = 251;
const double pT_bin5_up = 398, pT_bin5_low = 316;
const double pT_bin6_up = 500, pT_bin6_low = 398;
const double eta_bin = 2.1;
    
//const double photon_pT_bin_up = 300, photon_pT_bin_low = 60;
//const double jet_pT_bin_up = 300, jet_pT_bin_low = 30;
//const double photon_eta_bin = 1.44;
//const double jet_eta_bin = 1.6;
    
//const double pT_bin1_up = 300, pT_bin1_low = 200;
//const double pT_bin2_up = 400, pT_bin2_low = 300;
//const double pT_bin3_up = 500, pT_bin3_low = 400;
//const double pT_bin4_up = 600, pT_bin4_low = 500;
//const double eta_bin = 2.0;
    
//const double pT_bin_up = 160, pT_bin_low = 140;
//const double pT_bin_up = 180, pT_bin_low = 160;
//const double pT_bin_up = 200, pT_bin_low = 180;
//const double pT_bin_up = 300, pT_bin_low = 200;
//const double eta_bin = 1.3;
//const double D12 = 0.1;

//const double pT_bin_up = 80, pT_bin_low = 60;
//const double pT_bin_up = 100, pT_bin_low = 80;
//const double pT_bin_up = 120, pT_bin_low = 100;
//const double eta_bin = 0.5;
    
//const double pT_bin_up = 200, pT_bin_low = 0;
//const double eta_bin = 5;

//TH1D *pT_Plot = new TH1D("Histogram pT","pT", 50, 0, 500);
//TH1D *mpT_Plot = new TH1D("Histogram m","m/pT", 25, 0, 0.25);
//TH1D *SD1_mpT_Plot = new TH1D("Histogram m sd1","m/pT", 25, 0, 0.25);
//TH1D *D12cut_SD1_mpT_Plot = new TH1D("Histogram m sd1 D12 cut","m/pT", 25, 0, 0.25);
    
//TH1D *pT_Plot = new TH1D("Histogram pT","pT", 50, 0, 2000);
//TH1D *SD1_mpT_Plot = new TH1D("Histogram m sd1","Log[m/pT]", 10, -4.5, -0.5);
//TH1D *SD2_mpT_Plot = new TH1D("Histogram m sd2","Log[m/pT]", 10, -4.5, -0.5);
//TH1D *SD3_mpT_Plot = new TH1D("Histogram m sd3","Log[m/pT]", 10, -4.5, -0.5);
//TH1D *SD4_mpT_Plot = new TH1D("Histogram m sd4","Log[m/pT]", 10, -4.5, -0.5);
    
//TH1D *XJZ_Plot = new TH1D("Histogram XJZ","XJZ", 20, 0, 2);
//TH1D *XleadingJZ_Plot = new TH1D("Histogram XleadingJZ","XJZ", 20, 0, 2);
//TH1D *Z_pT_Plot = new TH1D("Histogram Z_pT","Z pT", 20, 0, 300);
//TH1D *jet_pT_Plot = new TH1D("Histogram jet_pT","jet pT", 20, 0, 300);
//TH1D *leading_jet_mass_Plot = new TH1D("Histogram leading_jet_mass","leading jet mass", 10, 0, 150);
//TH1D *m_bin_Plot = new TH1D("Histogram m bin","m", 30, 0, 150);
//TH1D *m_bin1_Plot = new TH1D("Histogram m bin1","m", 30, 0, 150);
//TH1D *m_bin2_Plot = new TH1D("Histogram m bin2","m", 30, 0, 150);
//TH1D *m_bin3_Plot = new TH1D("Histogram m bin3","m", 30, 0, 150);
//TH1D *m_bin4_Plot = new TH1D("Histogram m bin4","m", 30, 0, 150);

TH1D *Z_drop_Plot = new TH1D("Histogram Z drop","Z drop", 50, 0, 25);
    
TH1D *pT_Plot = new TH1D("Histogram pT","pT", 50, 0, 500);
TH1D *m_bin1_Plot = new TH1D("Histogram m bin1","m/pT", 25, 0, 0.25);
TH1D *m_bin2_Plot = new TH1D("Histogram m bin2","m/pT", 25, 0, 0.25);
TH1D *m_bin3_Plot = new TH1D("Histogram m bin3","m/pT", 25, 0, 0.25);
TH1D *m_bin4_Plot = new TH1D("Histogram m bin4","m/pT", 25, 0, 0.25);
TH1D *m_bin5_Plot = new TH1D("Histogram m bin5","m/pT", 25, 0, 0.25);
TH1D *m_bin6_Plot = new TH1D("Histogram m bin6","m/pT", 25, 0, 0.25);
    
//TH1D *XJZ_Plot = new TH1D("Histogram XJZ","XJZ", 20, 0, 2);
//TH1D *XleadingJZ_Plot = new TH1D("Histogram XleadingJZ","XJZ", 20, 0, 2);
//TH1D *Z_pT_Plot = new TH1D("Histogram Z_pT","Z pT", 20, 0, 200);
//TH1D *jet_pT_Plot = new TH1D("Histogram jet_pT","jet pT", 20, 0, 200);
//TH1D *leading_jet_mass_Plot = new TH1D("Histogram leading_jet_mass","leading jet mass", 10, 0, 20);
    
//TH1D *XJgamma_Plot = new TH1D("Histogram XJgamma","XJgamma", 20, 0, 2);
//TH1D *XleadingJgamma_Plot = new TH1D("Histogram XleadingJgamma","XJgamma", 20, 0, 2);
//TH1D *photon_pT_Plot = new TH1D("Histogram photon_pT","photon pT", 20, 0, 120);
//TH1D *jet_pT_Plot = new TH1D("Histogram jet_pT","jet pT", 20, 0, 120);
//TH1D *leading_jet_mass_Plot = new TH1D("Histogram leading_jet_mass","leading jet mass", 10, 0, 20);
    
//TH1D *pT_Plot = new TH1D("Histogram pT","pT", 60, 0, 600);
//TH1D *m_bin1_Plot = new TH1D("Histogram m bin1","m", 20, 0, 200);
//TH1D *m_bin2_Plot = new TH1D("Histogram m bin2","m", 20, 0, 200);
//TH1D *m_bin3_Plot = new TH1D("Histogram m bin3","m", 30, 0, 300);
//TH1D *m_bin4_Plot = new TH1D("Histogram m bin4","m", 30, 0, 300);

//TH1D *pT_Plot = new TH1D("Histogram pT","pT", 60, 0, 300);
//TH1D *m_Plot = new TH1D("Histogram m","m", 25, 0, 50);
//TH1D *pT_Plot = new TH1D("Histogram pT","pT", 60, 0, 120);
//TH1D *m_Plot = new TH1D("Histogram m","m", 30, 0, 30);
    
//TH1D *SD1_mpT_Plot = new TH1D("Histogram mpT SD1","m/pT", 25, 0, 0.25);
//TH1D *SD2_mpT_Plot = new TH1D("Histogram mpT SD2","m/pT", 25, 0, 0.25);

 while(1){
  
  if (!variable_file.good()) break;
     
//    variable_file >> jet_pT >> jet_eta >> jet_m >> jet_pT_SD1 >> jet_m_SD1 >> jet_rg_SD1 >> jet_zg_SD1;
//  variable_file >> jet1_pT >> jet1_eta >> jet1_m >> jet1_pT_SD1 >> jet1_m_SD1 >> jet1_rg_SD1 >> jet1_zg_SD1 >> jet1_pT_SD2 >> jet1_m_SD2 >> jet1_rg_SD2 >> jet1_zg_SD2 >> jet1_pT_SD3 >> jet1_m_SD3 >> jet1_rg_SD3 >> jet1_zg_SD3 >> jet1_pT_SD4 >> jet1_m_SD4 >> jet1_rg_SD4 >> jet1_zg_SD4 >> jet2_pT >> jet2_eta >> jet2_m >> jet2_pT_SD1 >> jet2_m_SD1 >> jet2_rg_SD1 >> jet2_zg_SD1 >> jet2_pT_SD2 >> jet2_m_SD2 >> jet2_rg_SD2 >> jet2_zg_SD2 >> jet2_pT_SD3 >> jet2_m_SD3 >> jet2_rg_SD3 >> jet2_zg_SD3 >> jet2_pT_SD4 >> jet2_m_SD4 >> jet2_rg_SD4 >> jet2_zg_SD4;
     
//  variable_file >> Z_pT >> Z_eta >> delta_phi_1 >> delta_phi_2 >> jet1_pT >> jet1_eta >> jet1_m >> jet1_pT_SD1 >> jet1_m_SD1 >> jet1_rg_SD1 >> jet1_zg_SD1 >> jet1_pT_SD2 >> jet1_m_SD2 >> jet1_rg_SD2 >> jet1_zg_SD2 >> jet2_pT >> jet2_eta >> jet2_m >> jet2_pT_SD1 >> jet2_m_SD1 >> jet2_rg_SD1 >> jet2_zg_SD1 >> jet2_pT_SD2 >> jet2_m_SD2 >> jet2_rg_SD2 >> jet2_zg_SD2;
//  variable_file >> photon_pT >> photon_eta >> delta_phi_1 >> delta_phi_2 >> jet1_pT >> jet1_eta >> jet1_m >> jet1_pT_SD1 >> jet1_m_SD1 >> jet1_rg_SD1 >> jet1_zg_SD1 >> jet1_pT_SD2 >> jet1_m_SD2 >> jet1_rg_SD2 >> jet1_zg_SD2 >> jet2_pT >> jet2_eta >> jet2_m >> jet2_pT_SD1 >> jet2_m_SD1 >> jet2_rg_SD1 >> jet2_zg_SD1 >> jet2_pT_SD2 >> jet2_m_SD2 >> jet2_rg_SD2 >> jet2_zg_SD2;
//  variable_file >> jet_pT >> jet_eta >> jet_m >> jet_pT_SD1 >> jet_m_SD1 >> jet_rg_SD1 >> jet_zg_SD1 >> jet_pT_SD2 >> jet_m_SD2 >> jet_rg_SD2 >> jet_zg_SD2;
//  variable_file >> jet_pT >> jet_eta >> jet_m;
  variable_file >> Z_pT >> Z_eta >> Z_m >> Z_jet_5_m >> Z_jet_4_m >> Z_jet_3_m >> Z_jet_2_m >> Z_jet_1_m >> Z_jet_5_pT >> Z_jet_4_pT >> Z_jet_3_pT >> Z_jet_2_pT >> Z_jet_1_pT;

     Z_drop = (pow(Z_jet_5_m,2)-pow(Z_m,2))/Z_pT/2;
//     Z_drop = (pow(Z_jet_5_m,2)-pow(Z_jet_1_m,2))/Z_pT/2;
//     Z_drop = (pow(Z_jet_5_m,2)-pow(prompt_Z.m(),2))/Z_pT/2;
     Z_drop_Plot->Fill(Z_drop);
         
/*     if (jet_pT > pT_bin_low && jet_pT < pT_bin_up){
     pT_Plot->Fill(jet_pT);
     mpT_Plot->Fill(jet_m/jet_pT);
     SD1_mpT_Plot->Fill(jet_m_SD1/jet_pT);
     if (jet_rg_SD1 > 0.1){
         D12cut_SD1_mpT_Plot->Fill(jet_m_SD1/jet_pT);
     }
     }*/
     
/*     pT_Plot->Fill(jet_pT);
     if (jet1_pT > pT_bin_low && jet1_pT < pT_bin_up && abs(jet1_eta) < eta_bin && jet1_pT < 1.5*jet2_pT){
         SD1_mpT_Plot->Fill(2*log10(jet1_m_SD1/jet1_pT));
         SD2_mpT_Plot->Fill(2*log10(jet1_m_SD2/jet1_pT));
         SD3_mpT_Plot->Fill(2*log10(jet1_m_SD3/jet1_pT));
         SD4_mpT_Plot->Fill(2*log10(jet1_m_SD4/jet1_pT));
         if (abs(jet2_eta) < eta_bin){
             SD1_mpT_Plot->Fill(2*log10(jet2_m_SD1/jet2_pT));
             SD2_mpT_Plot->Fill(2*log10(jet2_m_SD2/jet2_pT));
             SD3_mpT_Plot->Fill(2*log10(jet2_m_SD3/jet2_pT));
             SD4_mpT_Plot->Fill(2*log10(jet2_m_SD4/jet2_pT));
         }
     }*/
     
 //   Z_pT_Plot->Fill(Z_pT);
 //   jet_pT_Plot->Fill(jet1_pT);
 //   jet_pT_Plot->Fill(jet2_pT);
     
 //    photon_pT_Plot->Fill(photon_pT);
 //    jet_pT_Plot->Fill(jet1_pT);
 //    jet_pT_Plot->Fill(jet2_pT);
     
 //    m_Plot->Fill(jet_m);
 //    if (jet_pT > pT_bin_low && jet_pT < pT_bin_up && abs(jet_eta) < eta_bin)
 //    {
 //        pT_Plot->Fill(jet_pT);
 //        m_Plot->Fill(jet_m);
 //        if (jet_rg_SD1 > D12){
 //        SD1_mpT_Plot->Fill(jet_m_SD1/jet_pT);
 //        }
 //        if (jet_rg_SD2 > D12){
 //        SD2_mpT_Plot->Fill(jet_m_SD2/jet_pT);
 //        }
 //    }
     
 /*    if (jet_pT > pT_bin1_low && jet_pT < pT_bin1_up && abs(jet_eta) < eta_bin)
      {
      m_bin1_Plot->Fill(jet_m/jet_pT);
      }
      else if (jet_pT > pT_bin2_low && jet_pT < pT_bin2_up && abs(jet_eta) < eta_bin)
      {
      m_bin2_Plot->Fill(jet_m/jet_pT);
      }
      else if (jet_pT > pT_bin3_low && jet_pT < pT_bin3_up && abs(jet_eta) < eta_bin)
      {
      m_bin3_Plot->Fill(jet_m/jet_pT);
      }
      else if (jet_pT > pT_bin4_low && jet_pT < pT_bin4_up && abs(jet_eta) < eta_bin)
      {
      m_bin4_Plot->Fill(jet_m/jet_pT);
      }
      else if (jet_pT > pT_bin5_low && jet_pT < pT_bin5_up && abs(jet_eta) < eta_bin)
      {
      m_bin5_Plot->Fill(jet_m/jet_pT);
      }
      else if (jet_pT > pT_bin6_low && jet_pT < pT_bin6_up && abs(jet_eta) < eta_bin)
      {
      m_bin6_Plot->Fill(jet_m/jet_pT);
      }*/
     
/*     if (jet_pT > pT_bin1_low && jet_pT < pT_bin1_up && abs(jet_eta) < eta_bin)
     {
         m_bin1_Plot->Fill(jet_m);
     }
     else if (jet_pT > pT_bin2_low && jet_pT < pT_bin2_up && abs(jet_eta) < eta_bin)
     {
         m_bin2_Plot->Fill(jet_m);
     }
     else if (jet_pT > pT_bin3_low && jet_pT < pT_bin3_up && abs(jet_eta) < eta_bin)
     {
         m_bin3_Plot->Fill(jet_m);
     }
     else if (jet_pT > pT_bin4_low && jet_pT < pT_bin4_up && abs(jet_eta) < eta_bin)
     {
         m_bin4_Plot->Fill(jet_m);
     }*/

/*     if (Z_pT > Z_pT_bin_low && Z_pT < Z_pT_bin_up && abs(Z_eta) < Z_eta_bin){
      if (jet1_pT > jet_pT_bin_low && jet1_pT < jet_pT_bin_up && abs(jet1_eta) < jet_eta_bin  && abs(delta_phi_1) > 7*PI/8){
      XJZ_Plot->Fill(jet1_pT/Z_pT);
      XleadingJZ_Plot->Fill(jet1_pT/Z_pT);
      leading_jet_mass_Plot->Fill(jet1_m);
      }
      if (jet2_pT > jet_pT_bin_low && jet2_pT < jet_pT_bin_up && abs(jet2_eta) < jet_eta_bin && abs(delta_phi_2) > 7*PI/8){
      XJZ_Plot->Fill(jet2_pT/Z_pT);
      }
      }*/
     
/*     if (Z_pT > Z_pT_bin_low && Z_pT < Z_pT_bin_up && abs(Z_eta) < Z_eta_bin){
         if (jet1_pT > jet_pT_bin1_low && jet1_pT < jet_pT_bin1_up && abs(jet1_eta) < jet_eta_bin  && abs(delta_phi_1) > 2){
             m_bin1_Plot->Fill(jet1_m);
         }
         else if (jet1_pT > jet_pT_bin2_low && jet1_pT < jet_pT_bin2_up && abs(jet1_eta) < jet_eta_bin  && abs(delta_phi_1) > 2){
             m_bin2_Plot->Fill(jet1_m);
         }
         else if (jet1_pT > jet_pT_bin3_low && jet1_pT < jet_pT_bin3_up && abs(jet1_eta) < jet_eta_bin  && abs(delta_phi_1) > 2){
             m_bin3_Plot->Fill(jet1_m);
         }
         else if (jet1_pT > jet_pT_bin4_low && jet1_pT < jet_pT_bin4_up && abs(jet1_eta) < jet_eta_bin  && abs(delta_phi_1) > 2){
             m_bin4_Plot->Fill(jet1_m);
         }
         
         if (jet2_pT > jet_pT_bin1_low && jet2_pT < jet_pT_bin1_up && abs(jet2_eta) < jet_eta_bin && abs(delta_phi_2) > 2){
             m_bin1_Plot->Fill(jet2_m);
         }
         else if (jet2_pT > jet_pT_bin2_low && jet2_pT < jet_pT_bin2_up && abs(jet2_eta) < jet_eta_bin && abs(delta_phi_2) > 2){
             m_bin2_Plot->Fill(jet2_m);
         }
         else if (jet2_pT > jet_pT_bin3_low && jet2_pT < jet_pT_bin3_up && abs(jet2_eta) < jet_eta_bin && abs(delta_phi_2) > 2){
             m_bin3_Plot->Fill(jet2_m);
         }
         else if (jet2_pT > jet_pT_bin4_low && jet2_pT < jet_pT_bin4_up && abs(jet2_eta) < jet_eta_bin && abs(delta_phi_2) > 2){
             m_bin4_Plot->Fill(jet2_m);
         }
     }*/
     
/*     if (photon_pT > photon_pT_bin_low && photon_pT < photon_pT_bin_up && abs(photon_eta) < photon_eta_bin){
         if (jet1_pT > jet_pT_bin_low && jet1_pT < jet_pT_bin_up && abs(jet1_eta) < jet_eta_bin  && abs(delta_phi_1) > 7*PI/8){
             XJgamma_Plot->Fill(jet1_pT/photon_pT);
             XleadingJgamma_Plot->Fill(jet1_pT/photon_pT);
             leading_jet_mass_Plot->Fill(jet1_m);
         }
         if (jet2_pT > jet_pT_bin_low && jet2_pT < jet_pT_bin_up && abs(jet2_eta) < jet_eta_bin && abs(delta_phi_2) > 7*PI/8){
             XJgamma_Plot->Fill(jet2_pT/photon_pT);
         }
     }*/
 }
    TFile *mass_plot = new TFile("Histogram.root", "RECREATE");
//    TFile *mass_plot = new TFile("ATLAS/5_TeV/dijet_plot_MPIoff_PFmassless.root", "UPDATE");
//    TFile *mass_plot = new TFile("ATLAS/5_TeV/dijet_plot_PFmassless.root", "UPDATE");
//    TFile *mass_plot = new TFile("ATLAS/5_TeV/dijet_plot_parton.root", "UPDATE");
//    TFile *mass_plot = new TFile("qg/quark_jet_plot.root", "UPDATE");
//    TFile *mass_plot = new TFile("qg/gluon_jet_plot.root", "UPDATE");
//    TFile *mass_plot = new TFile("ATLAS/13_TeV/dijet_plot.root", "UPDATE");
//    TFile *mass_plot = new TFile("ATLAS/5_TeV/dijet_plot_MPIoff.root", "UPDATE");
//    TFile *mass_plot = new TFile("CMS/7_TeV/Zjet_plot.root", "UPDATE");
//    TFile *mass_plot = new TFile("CMS/5_TeV/Zjet_plot.root", "UPDATE");
//    TFile *mass_plot = new TFile("ATLAS/5_TeV/dijet_plot.root", "UPDATE");
//    TFile *mass_plot = new TFile("CMS/5_TeV/gammajet_plot.root", "UPDATE");
//    TFile *mass_plot = new TFile("ATLAS/7_TeV/dijet_plot.root", "UPDATE");
//    TFile *mass_plot = new TFile("CMS/5_TeV/dijet_plot.root", "UPDATE");
//    TFile *mass_plot = new TFile("CMS/5_TeV/dijet_plot_PFmassless.root", "UPDATE");
//    TFile *mass_plot = new TFile("ALICE/plot.root", "UPDATE");

//    XJZ_Plot->Write();
//    XleadingJZ_Plot->Write();
//    Z_pT_Plot->Write();
//    jet_pT_Plot->Write();
//    leading_jet_mass_Plot->Write();
//    m_bin_Plot->Write();
//    m_bin1_Plot->Write();
//    m_bin2_Plot->Write();
//    m_bin3_Plot->Write();
//    m_bin4_Plot->Write();
    
//    XJgamma_Plot->Write();
//    XleadingJgamma_Plot->Write();
//    photon_pT_Plot->Write();
//    jet_pT_Plot->Write();
//    leading_jet_mass_Plot->Write();

    Z_drop_Plot->Write();
    pT_Plot->Write();
//    mpT_Plot->Write();
//    SD1_mpT_Plot->Write();
//    D12cut_SD1_mpT_Plot->Write();
//    SD2_mpT_Plot->Write();
//    SD3_mpT_Plot->Write();
//    SD4_mpT_Plot->Write();
//    m_Plot->Write();
    m_bin1_Plot->Write();
    m_bin2_Plot->Write();
    m_bin3_Plot->Write();
    m_bin4_Plot->Write();
    m_bin5_Plot->Write();
    m_bin6_Plot->Write();
//    SD1_mpT_Plot->Write();
//    SD2_mpT_Plot->Write();
    mass_plot->Close();
    
}

