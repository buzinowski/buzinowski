#include "TTree.h"
#include <iostream>
#include <cstdlib>
#include "TChain.h"
#include "TH1.h"


using std::cout;
using std::endl;

void chain()
{
	TChain chain("T");

// TFile ft1 = new TFile("tree1.root","OPEN");
// TFile ft2("tree2.root","OPEN");
// TFile ft3("tree3.root","OPEN");
// TFile all("tree_all.root","RECREATE");
// TTree tall("T1","Tree all");


chain.Add("tree1.root");
chain.Add("tree2.root");
chain.Add("tree3.root");

chain.Draw("A");
TFile* file = TFile::Open("output.root","RECREATE");
chain.CloneTree(-1,"fast");
file->Write();
delete file;

	
}