#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>

#define SOLVE_RUN "./solve"

bool les_solve(const char *input, const char *output);


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
	std::string Data(int dim = 0);
	std::string Time();
	std::string Data_Time(int dim = 0);
	double tmin() const;
	double tmax() const;
	double p(int dim, int ind);
	bool Read(std::ifstream& iStr);
};

enum plot_type {time_1D, time_2D, implicit_time_2D, implicit_time_3D};

class FunPlot
{
	plot_type type;
	double t_min;
	double t_max;
	std::vector<Dataset> points;
	std::vector<std::string> functions;

public:
	FunPlot(plot_type ptype);
	void Set_range(double min, double max);
	void Add_dataset(Dataset set);
	void Add_fun(std::string fun);
	void Plot();
	
};
