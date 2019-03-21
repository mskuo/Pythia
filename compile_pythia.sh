export PYTHIAPATH=~/CMSSW_5_3_32/src/Demo/DemoAnalyzer/Pythia8/pythia8240
export PYTHIA8DATA=~/MG5_aMC_v2_6_4/HEPTools/pythia8/share/Pythia8/xmldoc

echo
echo "Compiling with : "
echo "$ROOTSYS    : "${ROOTSYS}
echo "$PYTHIAPATH : "${PYTHIAPATH}
echo

g++ pythia_jet_mass.cc $PYTHIAPATH/lib/libpythia8.a -o pythia_jet_mass.exe -I$ROOTSYS/include  -I$PYTHIAPATH/include  -Wl,-rpath $ROOTSYS/lib `$ROOTSYS/bin/root-config --glibs` -std=c++11
