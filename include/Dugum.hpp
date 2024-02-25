#ifndef Dugum_hpp
#define Dugum_hpp
#include "Sayi.hpp"


class Dugum
{
public:
	Dugum(Sayi* sayiadres); 
	~Dugum();
	Sayi* sayiadres;
	Dugum* sonraki;
private:	
	
};

#endif