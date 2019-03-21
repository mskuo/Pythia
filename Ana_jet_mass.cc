#include "NTupler.h"

int main (int argc, char *argv[]) {

  ifstream data_file;
//    data_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/dijet_mass_parton.dat");
//    data_file.open("/Users/ytchien/Research/Deep_learning/Discretized_Jets_new/discretized_gluons_200GeV_100k.txt");
//    data_file.open("/Users/ytchien/Research/Deep_learning/Discretized_Jets_new/discretized_quarks_200GeV_100k.txt");
//    data_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/ATLAS/13_TeV/dijet_mass.dat");
//    data_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/dijet_mass_MPIoff.dat");
    data_file.open("./Zjet_mass.dat");
//    data_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/Zjet_mass.dat");
//    data_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/gammajet_mass.dat");
//    data_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/ATLAS/7_TeV/dijet_mass.dat");
//    data_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/dijet_mass.dat");
//    data_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/ALICE/dijet_mass.dat");
  ofstream output_file;

    output_file.open("Zjet_data.dat");
//    output_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/dijet_data_MPIoff_PFmassless.dat");
//    output_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/dijet_data_parton.dat");
//    output_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/qg/gluon_jet_data.dat");
//    output_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/qg/quark_jet_data.dat");
//    output_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/ATLAS/13_TeV/dijet_data.dat");
//    output_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/dijet_data_MPIoff.dat");
//    output_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/7_TeV/Zjet_data.dat");
//    output_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/Zjet_data.dat");
//    output_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/ATLAS/5_TeV/dijet_data.dat");
//    output_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/gammajet_data.dat");
//    output_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/ATLAS/7_TeV/dijet_data.dat");
//    output_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/dijet_data.dat");
//    output_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/5_TeV/dijet_data_PFmassless.dat");
//    output_file.open("/Users/ytchien/Research/Heavy_ion_jet_mass/ALICE/dijet_data.dat");

int id, charge_id, particle_id;
int index_event;
int N_particle = 0;
const double PI = 3.1415927;
const double beta1 = 0.0, zcut1 = 0.1;
const double beta2 = 1.5, zcut2 = 0.5;
const double beta3 = 1.0, zcut3 = 0.1;
const double beta4 = 2.0, zcut4 = 0.1;

//double R0 = 0.8;
//double R0 = 0.7;
//double R0 = 0.3;
//double R0 = 1.0;
double dR = 0.0;
double R0 = 0.4;
int radius_bin = 1;
double px, py, pz, e;
double photon_pT = 0, photon_eta = 0, photon_phi;
double Z_pT = 0, Z_eta = 0, Z_phi;
double jet_pT, jet_eta, jet_phi, jet_m;
double delta_phi_1, delta_phi_2;
double jet_pT_SD1, jet_eta_SD1, jet_phi_SD1, jet_zg_SD1, jet_rg_SD1, jet_m_SD1;
double jet_pT_SD2, jet_eta_SD2, jet_phi_SD2, jet_zg_SD2, jet_rg_SD2, jet_m_SD2;
double jet_pT_SD3, jet_eta_SD3, jet_phi_SD3, jet_zg_SD3, jet_rg_SD3, jet_m_SD3;
double jet_pT_SD4, jet_eta_SD4, jet_phi_SD4, jet_zg_SD4, jet_rg_SD4, jet_m_SD4;
double Z_drop;
    
 while(1){
//  data_file >> N_particle;
  data_file >> index_event >> N_particle;

  if (!data_file.good()) break;
//  if (index_event == 10) break;
   
  vector<fastjet::PseudoJet> input_particles;
  fastjet::PseudoJet Z_ring_1;
  fastjet::PseudoJet Z_ring_2;
  fastjet::PseudoJet Z_ring_3;
  fastjet::PseudoJet Z_ring_4;
  fastjet::PseudoJet Z_ring_5;
  fastjet::PseudoJet Z_jet_1;
  fastjet::PseudoJet Z_jet_2;
  fastjet::PseudoJet Z_jet_3;
  fastjet::PseudoJet Z_jet_4;
  fastjet::PseudoJet Z_jet_5;
     
  fastjet::PseudoJet prompt_Z;
  fastjet::PseudoJet prompt_photon;
     
  for (int n = 0; n < N_particle; n++){
//   data_file >> px >> py >> pz >> e;
   data_file >> px >> py >> pz >> e >> particle_id;
//   data_file >> px >> py >> pz >> e >> charge_id;
//   e = sqrt(px*px+py*py+pz*pz);// CMS particle flow candidates massless
   fastjet::PseudoJet part(px,py,pz,e);
   part.set_user_index(id);
      if (n == 0 && particle_id == 23){
       prompt_Z = part;
       Z_pT = part.pt();
       Z_eta = part.rap();
       continue;
	cout << "Find particles!" << endl ;
       }
/*      if (n == 0 && particle_id == 22){
          prompt_photon = part;
          photon_pT = part.pt();
          photon_eta = part.rap();
          continue;
      }*/
//      if(charge_id == 1){
          input_particles.push_back(part);
//      }
      dR = prompt_Z.delta_R(part);
      radius_bin = dR/0.2;
        if(radius_bin == 4){
            Z_ring_5+=(part);
        }
        else if (radius_bin == 3){
            Z_ring_4+=(part);
        }
        else if (radius_bin == 2){
            Z_ring_3+=(part);
        }
        else if (radius_bin == 1){
            Z_ring_2+=(part);
        }
        else if (radius_bin == 0){
            Z_ring_1+=(part);
        }
  }
     Z_jet_1+=(prompt_Z);Z_jet_1+=(Z_ring_1);
     Z_jet_2+=(prompt_Z);Z_jet_2+=(Z_ring_1);Z_jet_2+=(Z_ring_2);
     Z_jet_3+=(prompt_Z);Z_jet_3+=(Z_ring_1);Z_jet_3+=(Z_ring_2);Z_jet_3+=(Z_ring_3);
     Z_jet_4+=(prompt_Z);Z_jet_4+=(Z_ring_1);Z_jet_4+=(Z_ring_2);Z_jet_4+=(Z_ring_3);Z_jet_4+=(Z_ring_4);
     Z_jet_5+=(prompt_Z);Z_jet_5+=(Z_ring_1);Z_jet_5+=(Z_ring_2);Z_jet_5+=(Z_ring_3);Z_jet_5+=(Z_ring_4);Z_jet_5+=(Z_ring_5);
//     Z_drop = (pow(Z_jet_5.m(),2)-pow(prompt_Z.m(),2))/Z_pT;
//     cout << prompt_Z.m() << " " << Z_jet_5.m() << " " << (pow(Z_jet_5.m(),2)-pow(prompt_Z.m(),2))/Z_pT << endl;
  
  contrib::SoftDrop sd1(beta1, zcut1, R0);
  contrib::SoftDrop sd2(beta2, zcut2, R0);
  contrib::SoftDrop sd3(beta3, zcut3, R0);
  contrib::SoftDrop sd4(beta4, zcut4, R0);
  
  fastjet::JetDefinition jet_def(fastjet::antikt_algorithm, R0);
  fastjet::ClusterSequence cs(input_particles, jet_def);
//  vector<fastjet::PseudoJet> jets = sorted_by_pt(cs.inclusive_jets());

//     delta_phi_1 = prompt_Z.delta_phi_to(jets[0]);
//     delta_phi_2 = prompt_Z.delta_phi_to(jets[1]);
//     output_file << Z_pT << " " << Z_eta << " " << delta_phi_1 << " " << delta_phi_2 << endl;
//     delta_phi_1 = prompt_photon.delta_phi_to(jets[0]);
//     delta_phi_2 = prompt_photon.delta_phi_to(jets[1]);
//     output_file << photon_pT << " " << photon_eta << " " << delta_phi_1 << " " << delta_phi_2 << endl;

/*         fastjet::PseudoJet groomed_jet1 = sd1(jets[0]);
         jet_rg_SD1 = groomed_jet1.structure_of<contrib::SoftDrop>().delta_R();
         jet_zg_SD1 = groomed_jet1.structure_of<contrib::SoftDrop>().symmetry();
         output_file << jets[0].pt() << " " << jets[0].rap() << " " << jets[0].m() << " " << groomed_jet1.pt() << " " << groomed_jet1.m() << " " << jet_rg_SD1 << " " << jet_zg_SD1 << endl;*/
     
/*     for (int ijet = 0; ijet < 2; ijet++ ){
         fastjet::PseudoJet groomed_jet1 = sd1(jets[ijet]);
         fastjet::PseudoJet groomed_jet2 = sd2(jets[ijet]);
//         fastjet::PseudoJet groomed_jet3 = sd3(jets[ijet]);
//         fastjet::PseudoJet groomed_jet4 = sd4(jets[ijet]);
         jet_rg_SD1 = groomed_jet1.structure_of<contrib::SoftDrop>().delta_R();
         jet_rg_SD2 = groomed_jet2.structure_of<contrib::SoftDrop>().delta_R();
//         jet_rg_SD3 = groomed_jet3.structure_of<contrib::SoftDrop>().delta_R();
//         jet_rg_SD4 = groomed_jet4.structure_of<contrib::SoftDrop>().delta_R();
         jet_zg_SD1 = groomed_jet1.structure_of<contrib::SoftDrop>().symmetry();
         jet_zg_SD2 = groomed_jet2.structure_of<contrib::SoftDrop>().symmetry();
//         jet_zg_SD3 = groomed_jet3.structure_of<contrib::SoftDrop>().symmetry();
//         jet_zg_SD4 = groomed_jet4.structure_of<contrib::SoftDrop>().symmetry();
//         output_file << jets[ijet].pt() << " " << jets[ijet].rap() << " " << jets[ijet].m() << " " << groomed_jet1.pt() << " " << groomed_jet1.m() << " " << jet_rg_SD1 << " " << jet_zg_SD1 << " " << groomed_jet2.pt() << " " << groomed_jet2.m() << " " << jet_rg_SD2 << " " << jet_zg_SD2 << " " << groomed_jet3.pt() << " " << groomed_jet3.m() << " " << jet_rg_SD3 << " " << jet_zg_SD3 << " " << groomed_jet4.pt() << " " << groomed_jet4.m() << " " << jet_rg_SD4 << " " << jet_zg_SD4 << endl;
         output_file << jets[ijet].pt() << " " << jets[ijet].rap() << " " << jets[ijet].m() << " " << groomed_jet1.pt() << " " << groomed_jet1.m() << " " << jet_rg_SD1 << " " << jet_zg_SD1 << " " << groomed_jet2.pt() << " " << groomed_jet2.m() << " " << jet_rg_SD2 << " " << jet_zg_SD2 << endl;

     }*/
     
     output_file << Z_pT << " " << Z_eta << " " << prompt_Z.m() << " " << Z_jet_5.m() << " " << Z_jet_4.m() << " " << Z_jet_3.m() << " " << Z_jet_2.m() << " " << Z_jet_1.m() << " " << Z_jet_5.pt() << " " << Z_jet_4.pt() << " " << Z_jet_3.pt() << " " << Z_jet_2.pt() << " " << Z_jet_1.pt() << endl;

 }
    
}

