#include "mat.hh"

class EqSys
{

	int size;
	Matrix A;
	Vector b;
	
public:
	
	EqSys(const Matrix& coeff, const Vector& res);

	bool Solve_Cram(Vector& x_out, Vector& err_out);
	bool Solve_Gauss(Vector& x_out, Vector& err_out);

	void Print();
};
