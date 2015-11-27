#include "../inc/eqs.hh"
#include <iostream>
#include <iomanip>

EqSys::EqSys(const Matrix& coeff, const Vector& res)
{
	if((coeff.Rows() != coeff.Cols()) || (res.Size() != coeff.Rows()))
	{
		std::cout << "Zle wymiary macierzy/wektora do ukl rown\n";
		std::terminate();
	}
	A=coeff; b=res; size=A.Rows();
}

bool EqSys::Solve_Cram(Vector& x_out)
{
	double m_det = A.Det();
	if(m_det==0) return false;
	double *x_det = new double[A.Rows()];
	for(int i=0; i<A.Rows(); i++)
	{
		Matrix temp(A.Transpose());
		temp[i]=b;
		x_det[i]=temp.Det();
	}
	x_out.Resize(A.Rows());
	for(int i=0; i<A.Rows(); i++)
		x_out[i]=x_det[i]/m_det;
	return true;
}

void EqSys::Print()
{
	std::cout << "\n[A|b]:\n";
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
			std::cout << std::setw(3) << A[i][j];
	std::cout << " | " << std::setw(3) << b[i] << std::endl;
	}
	
}
