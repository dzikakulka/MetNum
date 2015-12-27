#include "../inc/eqs.hh"
#include <fstream>

#define IN "input.dat"
#define OUT "output.dat"

int main(int argc, char* argv[])
{
	std::ifstream inStr;
	std::ofstream outStr;
	
	if(argc>1) outStr.open(argv[2]);
	else outStr.open(OUT);
	if(argc>0) inStr.open(argv[1]);
	else inStr.open(IN);
	
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
	(bladG.abs() < bladC.abs())?(rozwG.Print(outStr)):(rozwC.Print(outStr));
	/*M("#C", outStr);
	rozwC.Print(outStr);
	bladC.Print(outStr); Nl(1, outStr);
	outStr << bladC.abs(); Nl(2, outStr);
	M("#G", outStr);
	rozwG.Print(outStr);
	bladG.Print(outStr); Nl(1, outStr);
	outStr << bladG.abs();*/

	delete[] rows;
	return 0;
}
