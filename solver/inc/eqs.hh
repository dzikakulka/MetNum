#include "../inc/mat.hh"

class EqSys
{

	int size;
	Matrix A;
	Vector b;
	
public:
	
	EqSys(const Matrix& coeff, const Vector& res);

	bool Solve_Cram(Vector& x_out);

	void Print();
};
