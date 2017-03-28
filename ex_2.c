#include<iostream>
#include"TH1.h"
#include"TAxis"
using std::cout;
using std::endl;

void ex_2()
{
	TH1F* hist = new TH1F("Histofram of Pain", ";x", 10, 0.,100.);	
	hist->Fill(11.3);
	hist->Fill(25.4);
	hist->Fill(18.1);

	for (unsigned int i = 0; i<10; i++)
{
	hist->Fill(i*i);
}

	hist->Draw();

cout<<"mean = "<<hist->GetMean()<<" sigma = "<<hist->GetRMS()<<endl;
cout<<" Integral of hist I = "<< hist->Integral()<<endl;
// 	for (unsigned int j = 0;j<10;j++)
// {
// 		cout<<" Bean Content : "<< hist->GetBinContent(j)<<endl;
// }
cout<<"Bin with max Value "<<hist->GetMaximumBin()<<endl;
cout<<"Bin with Min Value "<<hist->GetMinimumBin()<<endl;

cout<<"Max value : "<< hist->GetBinContent(hist->GetMaximumBin())<<endl;
cout<<"Min value : "<< hist->GetBinContent(hist->GetMinimumBin())<<endl;
hist->GetYaxis()->SetTitle("Entries");
hist->SetLineColor(kGreen);


}

