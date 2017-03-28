#include "TH1.h"
#include "TCanvas.h"
#include "TLegend.h"
#include <iostream>

using std::cout;
using std::endl;
void ex_3()
{
TH1F* hist1 = new TH1F("Histogram 1", ";x", 10,-5,5);
TH1F* hist2 = new TH1F("Histogram 2", ";x", 10,-5,5);
hist1->FillRandom("gaus", 500);
hist2->FillRandom("pol2", 500);
// hist1->Draw();
// hist2->Draw();
TCanvas* c1 = new TCanvas("c1","gauss");
hist1->Draw();

TCanvas* c2 = new TCanvas("c2","polynomial");
hist2->Draw();

hist1->SetLineColor(kRed);
hist2->SetLineColor(kGreen);

TH1F* hist1b = (TH1F*)hist1->Clone("gaus2");
TH1F* hist2b = (TH1F*)hist2->Clone("pol2");

hist1b->Sumw2();
hist2b->Sumw2();

if (hist1b->Integral() == 0)
{
	cout<<"Divine by zero"<<endl;
	return(0);
}else
{
	hist1b->Scale(1./hist1b->Integral());
}

if (hist2b->Integral() == 0)
{
	cout<<"Divine by zero"<<endl;
	return(0);
}else
{
	hist2b->Scale(1./hist2b->Integral());
}

TCanvas* c3 = new TCanvas("c3","both");
hist1b->Draw();
hist2b->Draw("same");

TLegend* legend = new TLegend(0.16, 0.63, 0.45, 0.91);
legend->AddEntry(hist1b,"Gaussian", "l");
legend->AddEntry(hist2b,"Polynomial", "l");
legend->Draw();

c3->Print("gaussian-polynomial.pdf(");
c2->Print("gaussian-polynomial.pdf");
c1->Print("gaussian-polynomial.pdf)");
c3->Print("gaussian-polynomial_3.root");
c2->Print("gaussian-polynomial_2.root");
c1->Print("gaussian-polynomial_1.root");
}