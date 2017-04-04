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
	TH1F* hist = new TH1F("Histogramm",";x",100,0,100);
	TH1F* hist1 = new TH1F("Histogramm1",";x",100,0,100);
	chain.Add("tree1.root");
	chain.Add("tree2.root");
	chain.Add("tree3.root");

	Float_t a,b;

	chain.SetBranchAddress("A", &a);
	chain.SetBranchAddress("B", &b);

	int nEntries = chain.GetEntries();

	for (int i = 0; i < nEntries; i++)
	{
		chain.GetEntry(i);
//		cout << a << endl;
		hist->Fill(a);
		hist1->Fill(b);
	}
	TCanvas* c1 = new TCanvas("c1","A");
	hist->Draw();
	TCanvas* c2 = new TCanvas("c2","B");
	hist1->Draw();

	//chain.Draw("A");
	TFile* file = TFile::Open("output.root","RECREATE");
	chain.CloneTree(-1,"fast");
	file->Write();
	delete file;

}
