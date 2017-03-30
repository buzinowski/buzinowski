#include "TTree.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "TMath.h"
#include "TRandom.h"
#include "TChain.h"

using std::cout;
using std::endl;

void chain()
{

TFile ft1("tree1.root","OPEN");
TFile ft2("tree2.root","OPEN");
TFile ft3("tree3.root","OPEN");
TFile all("tree_all.root","RECREATE");
TTree tall("T1","Tree all");

TChain ch1("ft1");
TChain ch2("ft2");
TChain ch3("ft3");
TChain ch("tall");

ch.AddFriend("ft1");
ch.AddFriend("ft2");
ch.AddFriend("ft3");
ch.Draw("var:T.A:T.B");
// tall.AddFriend("ft1","tree1.root");
// tall.AddFriend("ft2","tree2.root");
// tall.AddFriend("ft3","tree3.root");
// tall.Draw();
// tall.Write();



	
}