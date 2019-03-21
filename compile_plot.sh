export FJINSTALL=~/CMSSW_5_3_32/src/Demo/DemoAnalyzer/fastjet-install

echo
echo "Compiling with : "
echo "$ROOTSYS    : "${ROOTSYS}
echo "$FJINSTALL : "${FJINSTALL}
echo

g++ -o histogram.exe histogram.cc -I$ROOTSYS/include -I$FJINSTALL/include/fastjet  -Wl,-rpath $ROOTSYS/lib `$ROOTSYS/bin/root-config --glibs` `$FJINSTALL/bin/fastjet-config --cxxflags --libs --plugins` -lNsubjettiness -lEnergyCorrelator   -std=c++11
