/** 
* @file SayilarListesi.cpp
* @description Dugum'ler birbirine baglanilir. En buyuk sayi burada bulunur ve silinir.
* @course 1.ogretim C grubu
* @assignment 1.odev
* @date 25.11.2023
* @author Sude Selvi sude.selvi@ogr.sakarya.edu.tr
*/
#include "Sayi.hpp"
#include "SayilarListesi.hpp"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
SayilarListesi::SayilarListesi()
{
	ilk=0;
}
SayilarListesi::~SayilarListesi()
{
Dugum* gec=ilk;
	while(gec!=0)
	{
		Dugum* sil=gec;
		gec=gec->sonraki;
		delete sil;
	}
}

void SayilarListesi::DugumEkle(Sayi* sayiadres)
{
	
	Dugum* yeni=new Dugum(sayiadres);
	if(ilk==0)
	{
		ilk=yeni;
	}
	else
	{
		Dugum* gec=ilk;
		while(gec->sonraki!=0)
			gec=gec->sonraki;
		gec->sonraki=yeni;
	}
	
	
}
void SayilarListesi::TeklerBasaAldir()//Sayi.cpp de her sayi icin tekleri basa alma islemi yapilir
{
	Dugum* gec=ilk;
	while(gec!=0)
	{
		gec->sayiadres->TeklerBasa();
		gec=gec->sonraki;
	}

}
void SayilarListesi::SayilariTersle()//Sayi.cpp de her sayi icin tersleme islemi yapilir
{
	Dugum* gec=ilk;
	while(gec!=0)
	{
		gec->sayiadres->Tersle();
		gec=gec->sonraki;
	}

}

Dugum* SayilarListesi::EnBuyukBul()//en buyuk sayi bulunup adresi dondurulur eger sayi kalmamissa 0 dondurulur
{
	if(ilk!=0)
	{
		Dugum* gec=ilk;
		Dugum* enBuyuk=gec;
		while(gec->sonraki!=0)
		{
			int BuyukS=enBuyuk->sayiadres->SayiyiInteCevir();
			int GeciciS=gec->sonraki->sayiadres->SayiyiInteCevir();
			
			if(BuyukS < GeciciS) // en buyuk sayiyi bulur
			{
				enBuyuk=gec->sonraki;
			}
			gec=gec->sonraki;
		}
	
		return enBuyuk;
	}
	else
		return 0;
}

void SayilarListesi::EnBuyukCikar()
{
	Dugum* enBuyuk=EnBuyukBul();	
	if(enBuyuk!=0)
	{	
		Dugum* gec=ilk;
		if(ilk->sonraki==0)//tek dugum kalmis ise
		{
			Dugum* sil=ilk;
			ilk=0;
			delete sil;
		}
		
		else if(ilk==enBuyuk)//en bastaki en buyukse
		{
			gec=gec->sonraki;
			ilk=gec;
			delete enBuyuk;
		}
		else if(enBuyuk->sonraki==0)//en sondaki en buyukse
		{
			while(gec->sonraki!=enBuyuk)
			{
				gec=gec->sonraki;
			}
			gec->sonraki=0;
			delete enBuyuk;
		}
		else
		{
			while(gec->sonraki!=enBuyuk)
				gec=gec->sonraki;
			gec->sonraki=enBuyuk->sonraki;
			delete enBuyuk;
		}
	}
	else
	cout<<"Hic sayi yok"<<endl;	

}

void SayilarListesi::yazdir()
{
	Dugum* gec=ilk;
	while(gec!=0)
	{
		cout<<"###########   ";
		for(int i=0;i<gec->sayiadres->RakamSayisiGetir();i++)
		{
			cout<<"***********"<<setw(1)<<" ";
		}
		
		cout<<endl<<"#"<<gec<<setw(1)<<"#"<<setw(4)<<" ";
		
		gec->sayiadres->yazdir();
		
		cout<<endl<<"#---------#   ";
		for(int i=0;i<gec->sayiadres->RakamSayisiGetir();i++)
		{
			cout<<"***********"<<setw(1)<<" ";
		}
		gec->sayiadres->SayininTamaminiOlustur();
		cout<<right;
		cout<<endl<<"#"<<gec->sayiadres->SayininTamaminiGetir()<<setw(13-(gec->sayiadres->RakamSayisiGetir()))<<"#   ";
		cout<<left;
		gec->sayiadres->yazdir2();
		
		cout<<endl<<"###########   ";
		for(int i=0;i<gec->sayiadres->RakamSayisiGetir();i++)
		{
			cout<<"***********"<<setw(1)<<" ";
		}
		cout<<endl<<endl<<endl;
	
		gec=gec->sonraki;
	}
}