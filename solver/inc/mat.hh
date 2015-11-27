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
	
	double Det(bool part_piv=true) const;
	
	int Rows() const;                          
	int Cols() const;
	Vector operator[] (int ind) const;     
	Vector& operator[] (int ind);             
	void Print() const;               	      
	void Resize_Cols(int new_size, double init=0);
	void Resize_Rows(int new_size, double init=0);



};
