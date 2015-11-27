#include "../inc/vec.hh"
#include <iostream>

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

Vector::Vector(const Vector& vec)
{
    size=vec.Size();
	el = new double[size];
	for(int i=0; i<size; i++) el[i]=vec[i];
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


Vector& Vector::operator= (const Vector& other)
{
	this->Resize(other.Size());
	for(int i=0; i<size; i++)
		el[i]=other[i];
	return *this;
}

// drukuj na stdout
void Vector::Print() const { std::cout << std::endl; for(int i=0; i<size; i++) std::cout << el[i] << " "; }

void Vector::Resize(int new_size, double init)
{
	double *n_el = new double[new_size];

	for(int i=0; i<((new_size<size)?new_size:size); i++) n_el[i]=el[i];
	if(new_size>size) for(int i=size; i<new_size; i++) n_el[i]=init;

	delete[] el;
	el=n_el;
	size=new_size;
}

void Vector::Read()
{
	for(int i=0; i<size; i++)
		std::cin >> el[i];
	//std::cout << "Read: "; this->Print(); std::cout << std::endl;
}


Vector operator+ (const Vector& arg1, const Vector& arg2)
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

double operator* (const Vector& arg1, const Vector& arg2)
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

Vector operator* (const Vector& arg1, double arg2)
{
	Vector ans(arg1.Size());
	for(int i=0; i<arg1.Size(); i++) ans[i]=arg1[i]*arg2;
	return ans;
}

Vector operator/  (const Vector& arg1, double arg2)
{
		Vector ans(arg1.Size());
	for(int i=0; i<arg1.Size(); i++) ans[i]=arg1[i]/arg2;
	return ans;
}
