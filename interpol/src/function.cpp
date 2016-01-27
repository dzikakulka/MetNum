#include "../inc/function.hh"


FunPlot::FunPlot(plot_type ptype)
{
	type = ptype;
	t_min = t_max = 0;
}

// num plot_type {time_1D, time_2D, implicit_time_2D, implicit_time_3D};

void FunPlot::Add_dataset(Dataset set){ points.push_back(set); }
void FunPlot::Add_fun(std::string fun){ functions.push_back(fun); }
void FunPlot::Plot()
{
	if(functions.empty() && points.empty()) return;
	const char *out = "plot.dat";
	std::ofstream oStr(out);
	char fchar = 'f';


	for(unsigned int i=0; i<functions.size(); i++)
	{
		oStr << fchar << "(t)=" << functions[i] << "\n";
		fchar++;
	}
	fchar--;
	if(type != time_1D) oStr << "set parametric \n";
	if(type == time_2D || type == implicit_time_3D) oStr << 's';
	oStr << "plot [t=" << t_min << ":" << t_max << "] ";
	if(type == time_2D) oStr << "t, ";
	char nchar='f';
	while(nchar<fchar)
	{
		oStr << nchar << "(t), ";
		nchar++;
	}
	oStr << fchar << "(t)";
	//if(type == time_2D) oStr << ", t";
	oStr << "\n";
	for(unsigned int i=0; i<points.size(); i++)
	{
		oStr << "\n replot '-' with points pointtype 4 lt rgb \"#FF0AFF\" \n";
		oStr << ((type==implicit_time_2D || type==implicit_time_3D)?points[i].Data():points[i].Data_Time());
		oStr << "\n end";
	}
	oStr << "\n pause -1";
	
	system("gnuplot -persist plot.dat&");

}

void FunPlot::Set_range(double min, double max)
{
	t_min=min; t_max=max;

}

std::string Dataset::Data(int datadim)
{
	std::stringstream str;
	//std::cerr << "DIM:" << dim;
	for(int i=0; i<count; i++)
	{
		//str << time[i] << " ";
		if(datadim != 0)
			str << (*points[dim-1])[i] << " ";
		else
			for(int j=0; j<dim; j++)
				str << (*points[j])[i] << " ";
		str << "\n";
	}
	return str.str();

}

std::string Dataset::Time()
{
std::stringstream str;
	//std::cerr << "DIM:" << dim;
	for(int i=0; i<count; i++)
	{
		str << time[i] << " ";
		str << "\n";
	}
	return str.str();
}

std::string Dataset::Data_Time(int datadim)
{
	std::stringstream str;
	//std::cerr << "DIM:" << dim;
	for(int i=0; i<count; i++)
	{
		
		if(datadim)
			str << (*points[dim-1])[i] << " ";
		else
			for(int j=0; j<dim; j++)
				str << (*points[j])[i] << " ";
		str << time[i] << " ";
		str << "\n";
	}
	return str.str();

}

double Dataset::tmin() const
{
    double tmin=time[0];
	for(int i=0; i<count; i++)
		if(time[i]<tmin)
			tmin=time[i];
	return tmin;
}
double Dataset::tmax() const
{
    double tmax=time[0];
	for(int i=0; i<count; i++)
		if(time[i]>tmax)
			tmax=time[i];
	return tmax;
}

void Dataset::Init(int d)
{
	dim = d;
	//std::cerr << "DIM:" << dim;
	for(int i=0; i<d; i++)
	{
		std::vector<double> *vec = new std::vector<double>;
		points.push_back(vec);
	}
	
}

bool Dataset::Read(std::ifstream& iStr)
{
	int d;
	iStr >> d;
	Init(d);
	double in;
	d = 0;
	while(iStr >> in)
	{
		//std::cerr << "IN:" << in;
		if(!(d%(dim+1))) time.push_back(in);
		else points[(d-1)%(dim+1)]->push_back(in);
		d++;	
	}
	if((d%(dim+1)))
	{
		std::cerr << "\n Niekompletne dane! " << d << " " << dim;
		return false;
	}
	else
	{
		count=(d+1)/(dim+1);
		return true;
	}
		
}

void Dataset::Print() const
{
	std::cout << count << " samples times " << dim << " dimension(s)\n";
	std::cout << "[i] [time(i)] [dim1(i)] ... [dimn(i)]\n";
	for(int i=0; i<count; i++)
	{
		std::cout << i << ": ";
		std::cout << time[i] << " ";
		for(int j=0; j<dim; j++)
			std::cout << (*points[j])[i] << " ";
		std::cout << "\n";
	}
}

bool Dataset::Read(const char *file)
{
	std::ifstream iStr(file);
	return Read(iStr);
}

int Dataset::Dim() const
{
	return dim;
}

int Dataset::Count() const
{
	return count;
}

double Dataset::t(int ind) const
{
	return time[ind];

}

double Dataset::p(int dim, int ind)
{
	return (*points[dim])[ind];
}

bool les_solve(const char *input, const char *output)
{
	std::string command = SOLVE_RUN;
	command = command + " " + input + " " + output; 
	system(command.c_str());
	
	return true;
}
