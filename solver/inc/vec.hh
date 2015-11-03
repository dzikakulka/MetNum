
class Vector
{
	int size;    // rozmiar wektora
	double *el;  // elementy wektora

public:

	// KONSTRUKTORY:
	Vector();                            // bezparametryczny - pusty wektor
	Vector(int new_size, double init=0); // parametryczny - zadania wielkosc, domyslna inicjalizacja na zero

	// METODY:
	int Size() const;                   // rozmiar
	double operator[] (int ind) const;  // zwracanie elementu
	double& operator[] (int ind);       // dostep do elementu
	void Print();                     	// drukuj na stdout
};

// DZIALANIA NA WEKTORACH
Vector operator+ (Vector arg1, Vector arg2); // dodawanie
//Vector operator- (Vector arg1, Vector arg2); // odejmowanie (dla wygody i czytelnosci)
double operator* (Vector arg1, Vector arg2); // mnozenie SKALARNE

// DZIALANIA MIESZANE
Vector operator* (Vector arg1, double arg2); // mnozenie przez skalar
//Vector operator/ (Vector arg1, double arg2); // dzielenie przez skalar (j.w. wygoda)