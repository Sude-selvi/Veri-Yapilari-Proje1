/** 
* @file Dugum.cpp
* @description Dugum adinda bir dugum olusturulur. Icinde tuttugu degere Sayi'nin adresi atanir. Sonraki deger sifir olarak belirlenir.
* @course 1.ogretim C grubu
* @assignment 1.odev
* @date 25.11.2023
* @author Sude Selvi sude.selvi@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"
#include <iostream>
#include <string>
using namespace std;
Dugum::Dugum(Sayi* sayiadres)
{
	this->sayiadres=sayiadres;
	this->sonraki=0;
	
	
}
Dugum::~Dugum()
{
	delete sayiadres;
	
}