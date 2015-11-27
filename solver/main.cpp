#include "inc/eqs.hh"
#include <iostream>

int main()
{

	int rozm;
	std::cin >> rozm;
	
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
	Vector rozwC, rozwG, bladC, bladG;
	s1.Solve_Cram(rozwC, bladC);
	s1.Solve_Gauss(rozwG, bladG);
	M("#C");
	rozwC.Print();
	bladC.Print(); Nl(2);
	M("#G");
	rozwG.Print();
	bladG.Print();
	return 0;
}
