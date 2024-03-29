#ifndef NTUPLER_H
#define NTUPLER_H

#define CERRD cout<<"Problem on "<<__FILE__<<"  "<<__LINE__<<endl;

#include <TROOT.h>
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TString.h"
#include "TLorentzVector.h"
#include "TRandom3.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>

#include <fastjet/PseudoJet.hh>
#include <fastjet/ClusterSequence.hh>
#include <fastjet/Selector.hh>

#include "fastjet/tools/Filter.hh"
#include "fastjet/tools/Pruner.hh"

#include "fastjet/Nsubjettiness.hh"
#include "fastjet/EnergyCorrelator.hh"
#include "fastjet/SoftDrop.hh"

using namespace fastjet;
using namespace std;


///////////////////////////
//input file and tree
///////////////////////////
TTree *treein;
TFile *filein;

int nEvents;

// delta R for truth labelling
double dR_match;

///////////////////////////
//input tree branches
///////////////////////////
double truth_q1_pt;
double truth_q1_eta;
double truth_q1_phi;
double truth_q1_m;

double truth_q2_pt;
double truth_q2_eta;
double truth_q2_phi;
double truth_q2_m;

double truth_q1_px;
double truth_q1_py;
double truth_q1_pz;
double truth_q1_e;

double truth_q2_px;
double truth_q2_py;
double truth_q2_pz;
double truth_q2_e;

double truth_t1_pt;
double truth_t1_eta;
double truth_t1_phi;
double truth_t1_m;

double truth_t2_pt;
double truth_t2_eta;
double truth_t2_phi;
double truth_t2_m;

double truth_W1_pt;
double truth_W1_eta;
double truth_W1_phi;
double truth_W1_m;

double truth_W2_pt;
double truth_W2_eta;
double truth_W2_phi;
double truth_W2_m;

double truth_H_pt;
double truth_H_eta;
double truth_H_phi;
double truth_H_m;

vector<int>*    fspart_id;
vector<double>* fspart_pt;
vector<double>* fspart_eta;
vector<double>* fspart_phi;
vector<double>* fspart_m;



///////////////////////////
//output file and tree
///////////////////////////
TTree *treeout;
TFile *fileout;

///////////////////////////
//for temporary storage
///////////////////////////
TLorentzVector truth_q1;
TLorentzVector truth_q2;
TLorentzVector truth_t1;
TLorentzVector truth_t2;
TLorentzVector truth_W1;
TLorentzVector truth_W2;
TLorentzVector truth_H;

TLorentzVector tau_axis1;
TLorentzVector tau_axis2;
TLorentzVector tau_axis3;
TLorentzVector tau_axis4;
TLorentzVector Tsubjet1;
TLorentzVector Tsubjet2;
TLorentzVector Tsubjet3;
TLorentzVector Tsubjet4;
TLorentzVector particle;
TLorentzVector soft_particle;
TLorentzVector particle_subtraction;
int jetflavor;

int    tempJet_flavor;
double tempJet_pt;
double tempJet_eta;
double tempJet_phi;
double tempJet_m;
double tempJet_Tau21;
double tempJet_D2;
double tempJet_TJet_m1;
double tempJet_TJet_m2;


///////////////////////////
//output tree branches
///////////////////////////
int    NumberOfVertices;

vector<int>    TruthRaw_flavor;
vector<double> TruthRaw_pt;
vector<double> TruthRaw_eta;
vector<double> TruthRaw_phi;
vector<double> TruthRaw_m;
vector<double> TruthRaw_Tau21;
vector<double> TruthRaw_D2;
vector<double> TruthRaw_TJet_m1;
vector<double> TruthRaw_TJet_m2;

vector<int>    TruthRawTrim_flavor;
vector<double> TruthRawTrim_pt;
vector<double> TruthRawTrim_eta;
vector<double> TruthRawTrim_phi;
vector<double> TruthRawTrim_m;
vector<double> TruthRawTrim_Tau21;
vector<double> TruthRawTrim_D2;
vector<double> TruthRawTrim_TJet_m1;
vector<double> TruthRawTrim_TJet_m2;


///////////////////////////
//extra functions
///////////////////////////
void ResetBranches();

int GetJetTruthFlavor(TLorentzVector jettemp,
                      TLorentzVector truth_t1,
                      TLorentzVector truth_t2,
                      TLorentzVector truth_W,
                      TLorentzVector truth_Z,
                      TLorentzVector truth_H,
                      int debug);

vector<PseudoJet> ToyCalorimeter(vector<PseudoJet> truth_particles);

double GetTau21(PseudoJet& input);

double T_Nsubjettiness(int N, PseudoJet& input, double beta_min, double beta_max);
double T_NsubjettinessRatio(int N_num, int N_den, PseudoJet& input, double beta_min, double beta_max);

double T_EnergyCorrelator_C2(PseudoJet& input, double beta_min, double beta_max);
double T_EnergyCorrelator_D2(PseudoJet& input, double beta_min, double beta_max);
double T_EnergyCorrelator_C3(PseudoJet& input, double beta_min, double beta_max);



#endif
