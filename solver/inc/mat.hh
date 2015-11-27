#include "vec.hh"

class Matrix
{
 
	int size;
	Vector *row;

public:
	Matrix();
	Matrix(int rows, int cols, double init=0);
	//Matrix(Vector *rows, int size);
	void Set(Vector vec, int ind);
	//void Append(Vector vec);
	Matrix(const Matrix& mat);

	Matrix Transpose() const;
	
	double Det(bool part_piv=true) const;
	
	int Rows() const;                          
	int Cols() const;
	Vector operator[] (int ind) const;     
	Vector& operator[] (int ind);             
	void Print() const;               	      
	void Resize(int rows, int cols);

};

Vector operator*(const Matrix& mat, const Vector& vec);
