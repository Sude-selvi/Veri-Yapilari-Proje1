/** 
* @file Basamak.cpp
* @description Bir basamak dugumu olusturulur ve sonraki adresi sifir olarak belirlenir.
* @course 1.ogretim C grubu
* @assignment 1.odev
* @date 25.11.2023
* @author Sude Selvi sude.selvi@ogr.sakarya.edu.tr
*/
#include "Basamak.hpp"
#include <iostream>
#include <string>
using namespace std;
Basamak::Basamak(int basamak)
{
	this->basamak=basamak;
	this->sonraki=0;

}
Basamak::~Basamak()
{	
}