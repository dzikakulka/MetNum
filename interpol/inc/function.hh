#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>

class Dataset
{
	
	int dim;
	int count;
	std::vector< double > time;
	std::vector< std::vector<double>* > points;
public:
	void Init(int d);
	bool Read(const char *file);
	int Dim() const;
	int Count() const;
	void Print() const;
	double t(int ind) const;
	double p(int dim, int ind);
	bool Read(std::ifstream& iStr);
};
