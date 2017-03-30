#include "TTree.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "TMath.h"
#include "TRandom.h"
#include "TChain.h"

using std::cout;
using std::endl;

void ex_4()
{	
	
	gRandom = new TRandom();
	const Int_t n = 10;
	Float_t* pAArray = new float[n];
	Float_t* pBArray = new float[n];
	


TH1F* hist = new TH1F("Histogramm of pAArray",";x", 100,-100,100 );
TFile f("tree1.root","RECREATE");	
TTree t("T","Tree");
TH1F* hist1 = new TH1F("Histogramm of pBArray",";x", 100,-100,100 );

t.Branch("A", pAArray,"pAArray/F");
t.Branch("B", pBArray,"pBArray/F");

// |---------------------------------------
// for(int i = 0; i<n;i++)
// {
// 	pAArray[i] = gRandom->Uniform(100.0) ;
// 	pBArray[i] = gRandom->Gaus(50.0,100.0);
	
// 	cout<<pBArray[i]<<"\t"<<pAArray[i]<<endl;

// 	hist->Fill(pAArray[i]);
// 	hist1->Fill(pBArray[i]);
// 	if (pAArray[i]>0 && pBArray[i]>0)
// 		{
// 			t.Fill();/* code */
// 		}	
// }
// |---------------------------------------

for(int i = 0; i<n; i++)
{
	hist->Fill(gRandom->Gaus(30.0,20.0));
	hist1->Fill(gRandom->Uniform(60));
	t.Fill();
}
t.Write();


TCanvas* c1 = new TCanvas("c1","Gauss");
hist->Draw();
TCanvas* c2 = new TCanvas("c2","Uniform");
hist1->Draw();

// cout<<"Integral "<<hist1->Integral()<<endl;
// cout<<"Mean "<<hist1->GetMean()<<endl;

// hist->Draw();









}