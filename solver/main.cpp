#include "inc/eqs.hh"
#include <iostream>

int main()
{
	/*Vector v1(4,1);
    Vector v2 = v1;
	v1.Print();	v2.Print();
	v1.Read();
	v1.Print();	v2.Print();*/

	/*
	int rozm;
	std::cout << "Rozmiar: "; std::cin >> rozm;
	
	Matrix m1(rozm, rozm);
	
	Vector *rows = new Vector[rozm];
	std::cout << std::endl;
	for(int i=0; i<rozm; i++){
		rows[i].Resize(rozm);
		rows[i].Read();
		m1.Set(rows[i], i);
	}
	m1.Print();
	std::cout << "DET: " << m1.Det();
	m1.Print();
	*/

		int rozm;
	std::cout << "Rozmiar: "; std::cin >> rozm;
	
	Matrix m1(rozm, rozm);
	Vector v1(rozm);
	
	Vector *rows = new Vector[rozm];
	std::cout << std::endl;
	for(int i=0; i<rozm; i++){
		rows[i].Resize(rozm);
		rows[i].Read();
		m1.Set(rows[i], i);
	}
	v1.Read();

	EqSys s1(m1, v1);
	s1.Print();
	Vector rozw(rozm);
	s1.Solve_Cram(rozw);
	rozw.Print();	
	/*m1.Print();
	m1.Resize(3, 5);
	m1.Print();
	Matrix m2(m1.Transpose());
	m2.Print();*/
	
	return 0;
}
