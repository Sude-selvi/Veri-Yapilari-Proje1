#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "SayilarListesi.hpp"
#include "Sayi.hpp"
using namespace std;

bool SatirKontrol(string dosya) // sayilar.txt'de girilen sayilar 9 basamaktan fazla oldugunda sikinti ciktigi icin boyle bir cozum buldum
{
	string satir="";
	fstream ob;
	ob.open(dosya, ios::in);
	while(!ob.eof())
	{
		ob>>satir;
		if(satir.length()>=10)
			return false;
		else
			return true;
	}
}

int main(){
	
	SayilarListesi* sayilist=new SayilarListesi();
	ifstream dosya("sayilar.txt");
	int sayiGec;
  if(dosya.is_open())
  {
		bool kontrol=SatirKontrol("sayilar.txt");
		if(!kontrol)
		{
			cout<<"Sayilari en fazla 9 basamakli giriniz"<<endl;
		}
		else
		{

			string satir;
			std::getline(dosya,satir);
			int sonrakisayi;
			stringstream Oku(satir);
			
			while(Oku>>sonrakisayi)
			{
				Sayi* s=new Sayi();

				s->BasamaklariAyir(sonrakisayi); 
				sayilist->DugumEkle(s);
				s->SayininTamaminiOlustur();
				
			}

			int cevap;
			while(true)
			{
				cout<<endl<<endl;
				sayilist->yazdir();
				cout<<endl<<endl;
				cout<<"1.Tek basamaklari basa al"<<endl;
				cout<<"2.Basamaklari Tersle"<<endl;
				cout<<"3.En buyuk cikar"<<endl;
				cout<<"4.Cikis"<<endl;
				
				cin>>cevap;
				switch(cevap)
				{
					case 1: sayilist->TeklerBasaAldir(); break;
					case 2: sayilist->SayilariTersle(); break;
					case 3: sayilist->EnBuyukCikar(); break;
					case 4: delete sayilist; return 0;  //Program tamamen kapanacagi icin sayilisti burada silmek istedim
					
				}	
			}

		}
  
  }
  dosya.close();
	
	
  return 0;
}


