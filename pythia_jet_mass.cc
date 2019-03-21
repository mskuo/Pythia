#include "jet_mass.h"
using namespace Pythia8;

int main(){

//  string ConfigFile = "config_dijet_ALICE.cmnd";
//  string ConfigFile = "config_dijet_CMS_5TeV.cmnd";
//  string ConfigFile = "config_dijet_ATLAS_7TeV.cmnd";
//  string ConfigFile = "config_gammajet_CMS_5TeV.cmnd";
//  string ConfigFile = "config_Zjet_CMS_5TeV.cmnd";
  string ConfigFile = "config_Zjet_CMS_7TeV.cmnd";
//  string ConfigFile = "config_dijet_ATLAS_13TeV.cmnd";
  int charge_id;
  int nEvents = 100000;
//  int nEvents = 10;

  Pythia pythia;
  pythia.readFile(ConfigFile);
  pythia.init();
    
  ofstream output;
//  output.open("/Users/ytchien/Research/Heavy_ion_jet_mass/CMS/7_TeV/Zjet_mass.dat");
  output.open("Zjet_mass.dat");

  for (int iEvent = 0; iEvent < nEvents; ++iEvent) {

    pythia.next();

      int num = 0;
      for (int i = 0; i < pythia.event.size(); ++i){
          //count the number of final state particles
          if (pythia.event[i].isFinal()) num = num + 1;
          //if (pythia.event[i].isFinal() && pythia.event[i].isCharged()) num = num + 1;
      }
      output << iEvent << " " << num << endl;
      
    //loops through the particles in the event just generated
    for (int iPart = 0; iPart < pythia.event.size(); ++iPart) {

      if(pythia.event[iPart].isFinal()){
          if(pythia.event[iPart].isCharged()){charge_id = 1;}
          else{charge_id = 0;}
        output << pythia.event[iPart].px() << " " << pythia.event[iPart].py() << " " << pythia.event[iPart].pz() << " " << pythia.event[iPart].e() << " " << pythia.event[iPart].id() << endl;
//        output << pythia.event[iPart].px() << " " << pythia.event[iPart].py() << " " << pythia.event[iPart].pz() << " " << pythia.event[iPart].e() << " " << charge_id << endl;
      }
    }
      output << endl;
  }

  return 0;
}

int GetCharge(int pID){
    
    int charge = 0;
    
    if (pID == 11 || pID == 13 || pID == -211 || pID == -321 || pID == -2212){
        charge = -1;
    }
    else if (pID == -11 || pID == -13 || pID == 211 || pID == 321 || pID == 2212){
        charge = 1;
    }
    else if(pID == 22 || pID == -22 || pID == 111 || pID == -111 || pID == 130 || pID == -130 || pID == 2112 || pID == -2112){
        charge = 0;
    }
    
    return charge;
    
}
