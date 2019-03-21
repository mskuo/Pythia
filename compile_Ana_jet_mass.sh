export FJINSTALL=~/CMSSW_5_3_32/src/Demo/DemoAnalyzer/fastjet-install
#export FJCONTRIB=~/CMSSW_5_3_32/src/Demo/DemoAnalyzer/fjcontrib

echo
echo "Compiling with : "
echo "$ROOTSYS    : "${ROOTSYS}
echo "$FJINSTALL  : "${FJINSTALL}
#echo "$FJCONTRIB   : "${FJCONTRIB}

#g++ -shared -fPIC -o $FJCONTRIB/Nsubjettiness/libNsubjettiness.so Nsubjettiness.o 
g++ -o Ana_jet_mass.exe Ana_jet_mass.cc -I$ROOTSYS/include -I$FJINSTALL/include/fastjet  -Wl,-rpath $ROOTSYS/lib `$ROOTSYS/bin/root-config --glibs` `$FJINSTALL/bin/fastjet-config --cxxflags --libs --plugins` -lNsubjettiness -lEnergyCorrelator -lRecursiveTools   -std=c++11
