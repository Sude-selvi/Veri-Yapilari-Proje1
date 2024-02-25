/** 
* @file Sayi.cpp
* @description Dosyadan gelen sayilari basamaklarina ayirir, basamaklari birbirine baglar, basamaklari basa alma ve tersleme islemleri burada yapilir.
* @course 1.ogretim C grubu
* @assignment 1.odev
* @date 25.11.2023
* @author Sude Selvi sude.selvi@ogr.sakarya.edu.tr
*/


#include "Sayi.hpp"
#include "SayilarListesi.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;
Sayi::Sayi()
{
	ilk=0;
	sayinintamami="";
}
Sayi::~Sayi()
{
Basamak* gec=ilk;
	while(gec!=0)
	{
		Basamak* sil=gec;
		gec=gec->sonraki;
		delete sil;
	}

}
void Sayi::ekle(int rakam)
{
		Basamak* yeni=new Basamak(rakam);//yeni bir basamak dugumu olusturuldu ve devaminda baglama islemleri yapildi
		yeni->sonraki=ilk;
		ilk=yeni;
}
void Sayi::BasamaklariAyir(int sayi)
{
	int basam;
	int uzunluk=trunc(log10(sayi))+1;//gelen sayinin uzunlugunu bulduk

	while(!(uzunluk==0))
	{
		basam=sayi%10;
		ekle(basam);
		sayi=sayi/10;
		uzunluk--;
	}

}

void Sayi::SayininTamaminiOlustur()//basamaklardaki rakamlari tek tek dolanip bir string icine atiyoruz
{
	sayinintamami="";
	Basamak* gec=ilk;
	while(gec!=0)
	{
		sayinintamami+=to_string(gec->basamak);
		gec=gec->sonraki;
		
	}
}
int Sayi::SayiyiInteCevir()//string haldeki sayiyi integer yapiyoruz
{
	SayininTamaminiOlustur();
	return stoi(sayinintamami);
}

std::string Sayi::SayininTamaminiGetir()
{
	return sayinintamami;
}

int Sayi::RakamSayisiGetir()//basamakta kac rakam var oldugunu bulan fonksiyon
{
	int Rsayi=0;
	Basamak* gecici=ilk;
	while(gecici!=0)
	{
		Rsayi++;
		gecici=gecici->sonraki;
	}
	return Rsayi;
}

void Sayi::TeklerBasa()
{
	int rakamsayisi=RakamSayisiGetir();
	
	for(int i=0;i<rakamsayisi-1;i++)
	{	
		Basamak* gec=ilk;
		Basamak* gecicioncesi=ilk;
		if(gec!=0)
		{
			for(int j=0;j<rakamsayisi-i-1;j++)
			{
				if(gec!=0)
				{
					if(j==0&&gec->basamak%2==0&&gec->sonraki->basamak%2==1)//ilk iki sayinin karsilastirilir. eger bastaki sayi cift sonraki sayi tekse yer degistirilir ve ilkin yeni degeri belirlenir
					{
						Basamak* cift=gec;
						Basamak* tek=gec->sonraki;
						
						cift->sonraki=tek->sonraki;
						tek->sonraki=cift;
						gec=cift;
						gecicioncesi=tek;
						ilk=gecicioncesi;
					}
					
					else if((j==0 && gec->basamak%2==0&&gec->sonraki->basamak%2==0)||(j==0&&gec->basamak%2==1&&gec->sonraki->basamak%2==0)||(j==0&&gec->basamak%2==1&&gec->sonraki->basamak%2==1)) 
					{//ilk iki sayi yer degistirilmemis ise gec degeri bir sonraki degeri gosterir. gecicioncesi ilk degeri gostermeye devam eder.
						gec=gec->sonraki;
					}
					
					else if(j!=0 && gec->basamak%2==0&&gec->sonraki->basamak%2==1)//sayi ciftse ve sonraki sayi tekse yer degistirme islemleri yapilir
					{
						Basamak* cift=gec;
						Basamak* tek=gec->sonraki;
						
						gecicioncesi->sonraki=tek;
						if(tek->sonraki==0)
							cift->sonraki=0;
						else
							cift->sonraki=tek->sonraki;
						tek->sonraki=cift;
						gec=cift;
						gecicioncesi=tek;
						
					}
					else//yer degistirme islemleri yapilmamis ise gec ve gecicioncesi sonraki sayilari gosterir
					{
						gec=gec->sonraki;
						gecicioncesi=gecicioncesi->sonraki;
					}
					
					
					
				}
			}
		}
				
	}	
}
void Sayi::Tersle()//hep ilk rakami alip en sona goturur. sonrasinda ikinci rakami alip en sonun bir oncesine goturur. bu boyle azalarak devam eder
{
	int rakamsayisi=RakamSayisiGetir();
	for(int i=0;i<rakamsayisi-1;i++)
	{
		Basamak* gec=ilk;
		Basamak* geconcesi=ilk;
		Basamak* gecsonrasi=ilk;
		for(int j=0;j<rakamsayisi-i-1;j++)
			{
				if(j==0)//ilk rakamin yeri degistigi icin ilk pointerinin gosterdigi adres de degisecektir. burada bu islemler yapilir.
				{
					gec=gec->sonraki;
					gecsonrasi=gec->sonraki;
					geconcesi->sonraki=gecsonrasi;
					gec->sonraki=geconcesi;
					geconcesi=gec;
					gec=gec->sonraki;
					ilk=geconcesi;
				}
				else  //Hep gec ve gecsonrasi yer degistirecek
				{
					gec->sonraki=gecsonrasi->sonraki;
					geconcesi->sonraki=gecsonrasi;
					gecsonrasi->sonraki=gec;
					geconcesi=gecsonrasi;
					gecsonrasi=gec->sonraki;
				}
			}
	}
	
}

void Sayi::yazdir()
{	
	Basamak* gec=ilk;
		while(gec!=0)
		{	
			cout<<left;
			cout<<"*"<<gec<<"*"<<setw(3);
			gec=gec->sonraki;
		}
	
}
void Sayi::yazdir2()
{	
	Basamak* gec=ilk;
		while(gec!=0)
		{	cout<<right;
			cout<<"*"<<setw(5)<<gec->basamak<<setw(5)<<"*"<<setw(1)<<" ";
			gec=gec->sonraki;
		}
	
}