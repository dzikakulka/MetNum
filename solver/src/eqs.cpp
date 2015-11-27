#include "../inc/eqs.hh"
#include <iostream>

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
	if(m_det==0){std::cout << "Zerowy wyznacznik glowny ukladu\n"; return false;}
	double *x_det = new double[A.Rows()];
	for(int i=0; i<A.Rows(); i++)
	{
		Matrix temp(A.Transpose());
		temp[i]=b;
		x_det[i]=temp.Det();
	}
	x_out.Resize(A.Rows());
	for(int i=0; i<x_out.Size(); i++)
		x_out[i]=x_det[i]/m_det;
	return true;
}

bool EqSys::Solve_Gauss(Vector& x_out)
{
	Matrix mat(A);
	//Vector vec(b.Size());
	//vec=b;
	mat.Resize(mat.Rows(), mat.Cols()+1);
	for(int i=0; i<b.Size(); i++)
		mat[i][mat.Cols()-1] = b[i];
	mat.Print();
	
	for(int i=0; i<size; i++)
	{
		if(mat[i][i]==0)
		{
			int imax=i;
			for(int j=i+1; j<size; j++)
				if(abs(mat[j][i]) > abs(mat[imax][i])) imax=j;
			if(mat[imax][i]==0){std::cerr << "Uklad sprzeczny/niejednoznaczny\n"; return false;}
			//std::cout << "DEBUG_b:\n" << "i=" << i << " imax=" << imax << std::endl;
			//std::cout << "[i]: "; mat[i].Print(); std::cout << "[imax]: "; mat[imax].Print();
			if(i!=imax)
			{
				Vector temp2(mat[i]);
				mat[i]=mat[imax];
				mat[imax]=temp2;
				//	double temp = vec[i];
				//	vec[i]=vec[imax];
				//	vec[imax]=temp;
			}
            //std::cout << "DEBUG_a:\n" << "i=" << i << " imax=" << imax << std::endl;
			//std::cout << "[i]: "; mat[i].Print(); std::cout << "[imax]: "; mat[imax].Print();
		}
		//	vec[i]=vec[i]/mat[i][i];
		mat[i]=mat[i]/mat[i][i];
		
		//	vec.Print();
		for(int j=i+1; j<size; j++)
		{
			mat[j]=mat[j]+((mat[i]*(-1))*(mat[j][i]/mat[i][i]));
			//		vec[j]=vec[j]+(-1*vec[i]*(mat[j][i]/mat[i][i]));
		}
			
	}
	
	for(int i=mat.Rows()-1; i>=0; i--)
		for(int j=i-1; j>=0; j--)
			mat[j]=mat[j]+((mat[i]*-1)*mat[j][i]);
	//	mat.Print();
	x_out.Resize(mat.Rows());
	for(int i=0; i<x_out.Size(); i++)
		x_out[i]=mat[i][mat.Cols()-1];
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
