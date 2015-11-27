#include "util.hh"

class Vector
{
	int size;    // rozmiar wektora
	double *el;  // elementy wektora

public:

	// KONSTRUKTORY:
	Vector();                            // bezparametryczny - pusty wektor
	Vector(int new_size, double init=0); // parametryczny - zadania wielkosc, domyslna inicjalizacja na zero
	Vector(const Vector& vec);
	
	// METODY:
	int Size() const;                          // rozmiar
	double operator[] (int ind) const;         // zwracanie elementu
	double& operator[] (int ind);              // dostep do elementu
	Vector& operator= (const Vector& other);
	void Print(std::ostream& outStr=std::cout) const;               	       // drukuj na stdout
	void PrintIl() const;               	       // drukuj na stdout
	void Resize(int new_size, double init=0);  // zmien rozmiar
	void Read(std::istream& inStr=std::cin);
};

// DZIALANIA NA WEKTORACH
Vector operator+ (const Vector& arg1, const Vector& arg2); // dodawanie
//Vector operator- (Vector arg1, Vector arg2); // odejmowanie (dla wygody i czytelnosci)
double operator* (const Vector& arg1, const Vector& arg2); // mnozenie SKALARNE

// DZIALANIA MIESZANE
Vector operator* (const Vector& arg1, double arg2); // mnozenie przez skalar
Vector operator/ (const Vector& arg1, double arg2); // dzielenie przez skalar (j.w. wygoda)

