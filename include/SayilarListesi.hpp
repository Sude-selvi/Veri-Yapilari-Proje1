#ifndef SayilarListesi_hpp
#define SayilarListesi_hpp
#include "Dugum.hpp"
#include "Sayi.hpp"
#include <iostream>
#include <string>
using namespace std;
class SayilarListesi
{
public:
	SayilarListesi();
	~SayilarListesi();
	void DugumEkle(Sayi* sayiadres);
	void yazdir();
	void TeklerBasaAldir();
	void SayilariTersle();
	Dugum* EnBuyukBul();
	void EnBuyukCikar();
private:
	Dugum* ilk;
};


#endif
