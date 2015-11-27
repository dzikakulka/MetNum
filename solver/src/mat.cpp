#include "../inc/mat.hh"
#include "../inc/util.hh"
#include <iostream>

Matrix::Matrix(){size = 0; row = NULL;}

Matrix::Matrix(int rows, int cols, double init)
{
	size = rows;
	row = new Vector[rows];
	for(int i=0; i<rows; i++)
		row[i].Resize(cols, init);
}

//Matrix::Matrix()
	
/*Matrix::Matrix(Vector *rows, int quant)
{
	size = quant;
	row = new Vector[size];
	for(int i=0; i<size; i++)
		row[i]=rows[i];

		}*/

void Matrix::Set(Vector vec, int ind)
{
	// ASSERT ROZMIAR WEKTORA!
	// ASSERT INDEKS!
	row[ind]=vec;
}

int Matrix::Rows() const{ return size; }

int Matrix::Cols() const{if(size==0) return 0; else return row[0].Size();}

Vector Matrix::operator[] (int ind) const{ return row[ind]; }

Vector& Matrix::operator[] (int ind){ return row[ind]; }

void Matrix::Print() const
{
	for(int i=0; i<size; i++)
		row[i].Print();
	std::cout << std::endl;
}

void Matrix::Resize_Cols(int new_size, double init){}
void Matrix::Resize_Rows(int new_size, double init){}


double Matrix::Det()
{
	if((Rows()!=Cols()) || (size == 0) )
	{
		std::cerr << "Nie da rady" << std::endl;
		return 0;
	}

	int zam=0;
	for(int i=0; i<size; i++)
	{
		if(row[i][i]==0)
		{
			int imax=i+1;
			for(int j=i+2; j<size; j++)
				if(abs(row[j][i]) > abs(row[imax][i])) imax=j;
			if((imax >= size) || (row[imax][i] == 0)) return 0;
			//std::cout << "DEBUG_b:\n" << "i=" << i << " imax=" << imax << std::endl;
			//std::cout << "[i]: "; row[i].Print(); std::cout << "[imax]: "; row[imax].Print();
			Vector temp(row[i]);
			row[i]=row[imax];
			row[imax]=temp;
			//std::cout << "DEBUG_a:\n" << "i=" << i << " imax=" << imax << std::endl;
			//std::cout << "[i]: "; row[i].Print(); std::cout << "[imax]: "; row[imax].Print();
			zam+=imax-i;
		}
	}

	return 0;
}