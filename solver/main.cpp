#include "inc/eqs.hh"

int main()
{

	int rozm;
	M("\nRozmiar ukladu: ");
	std::cin >> rozm;
	
	Matrix m1(rozm, rozm);
	Vector v1(rozm);

	M("\nElementy macierzy:");
	Vector *rows = new Vector[rozm];
	std::cout << std::endl;
	for(int i=0; i<rozm; i++){
		rows[i].Resize(rozm);
		rows[i].Read();
		m1.Set(rows[i], i);
	}

	M("\nWektor wyrazow wolnych:\n");
	v1.Read();

	EqSys s1(m1, v1);
	Vector rozwC, rozwG, bladC, bladG;
	s1.Solve_Cram(rozwC, bladC);
	s1.Solve_Gauss(rozwG, bladG);
	M("\nRozw Cramer:\n x: ");
	rozwC.PrintIl();
	M("\nBlad Cramer:\n e: ");
	bladC.PrintIl();
	std::cout << "(abs: " << bladC.abs() << ")"; Nl(2);
	M("Rozw Gauss:\n x: ");
	rozwG.PrintIl();
	M("\nBlad Gauss:\n e: ");
	bladG.PrintIl();
	std::cout << "(abs: " << bladG.abs() << ")"; Nl(2);
	return 0;
}
