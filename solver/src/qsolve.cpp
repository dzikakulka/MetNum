#include "../inc/eqs.hh"
#include <fstream>

#define IN "../input.dat"
#define OUT "../output.dat"

int main()
{

	std::ifstream inStr;
	inStr.open(IN);
	std::ofstream outStr;
	outStr.open(OUT);
	
	int rozm;
    inStr >> rozm;
	
	Matrix m1(rozm, rozm);
	Vector v1(rozm);
	
	Vector *rows = new Vector[rozm];
   	for(int i=0; i<rozm; i++){
		rows[i].Resize(rozm);
		rows[i].Read(inStr);
		m1.Set(rows[i], i);
	}
	v1.Read(inStr);

	EqSys s1(m1, v1);
	Vector rozwC, rozwG, bladC, bladG;
	s1.Solve_Cram(rozwC, bladC);
	s1.Solve_Gauss(rozwG, bladG);
	M("#C");
	rozwC.Print(outStr);
	bladC.Print(outStr); Nl(2);
	M("#G");
	rozwG.Print(outStr);
	bladG.Print(outStr);
	return 0;
}
