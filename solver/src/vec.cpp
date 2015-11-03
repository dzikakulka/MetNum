#include "../inc/vec.hh"
#include <iostream>

#define NULL 0

/// KONSTRUKTORY ///
// bezparametryczny - pusty wektor
Vector::Vector(){ size=0; el=NULL; }
// parametryczny - zadania wielkosc, domyslna inicjalizacja na zero
Vector::Vector(int new_size, double init)
		{
			size=new_size;
			el = new double[new_size];
			for(int i=0; i<new_size; i++) el[i]=init;
		}

/// METODY ///
// rozmiar
int Vector::Size() const { return size;}
// zwracanie elementu
double Vector::operator[] (int ind) const
		{
			if(ind>(size-1))
			{
				std::cerr << "ROg -- i:" << ind << " s:" << size << "\n";
				std::terminate();
			}

			return el[ind];
		}
// dostep do elementu
double& Vector::operator[] (int ind)
		{
			if(ind>(size-1))
			{
				std::cerr << "ROs -- i:" << ind << " s:" << size << "\n";
				std::terminate();
			}

			return el[ind];
		}
// drukuj na stdout
void Vector::Print(){ std::cout << std::endl; for(int i=0; i<size; i++) std::cout << el[i] << " "; }



Vector operator+ (Vector arg1, Vector arg2)
{
	if(arg1.Size()!=arg2.Size())
	{
		std::cerr << "DS+ -- s1:" << arg1.Size() << " s2:" << arg2.Size() << "\n";
		std::terminate();
	}

	Vector ans(arg1.Size());
	for(int i=0; i<arg1.Size(); i++) ans[i]=arg1[i]+arg2[i];
	return ans;
}

double operator* (Vector arg1, Vector arg2)
{
	if(arg1.Size()!=arg2.Size())
	{
		std::cerr << "DS* -- s1:" << arg1.Size() << " s2:" << arg2.Size() << "\n";
		std::terminate();
	}

	double ans = 0;
	for(int i=0; i<arg1.Size(); i++) ans+=arg1[i]*arg2[i]; 
	return ans;
}

Vector operator* (Vector arg1, double arg2)
{
	Vector ans(arg1.Size());
	for(int i=0; i<arg1.Size(); i++) ans[i]=arg1[i]*arg2;
	return ans;
}
