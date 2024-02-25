#ifndef Sayi_hpp 
#define Sayi_hpp
#include "Basamak.hpp"
#include <string>


class Sayi
{
public:
	Sayi();
	~Sayi();
	void BasamaklariAyir(int sayi);
	void ekle(int rakam);
	void yazdir();
	void SayininTamaminiOlustur();
	int RakamSayisiGetir();
	void Tersle();
	std::string SayininTamaminiGetir();
	void TeklerBasa();
	void yazdir2();
	int SayiyiInteCevir();
	std::string sayinintamami;
	int intSayi;
private:
	Basamak* ilk;

	
};

#endif