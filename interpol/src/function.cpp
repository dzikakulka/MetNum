#include "../inc/function.hh"


void Dataset::Init(int d)
{
	dim = d;
	std::cerr << "DIM:" << dim;
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
		std::cerr << "IN:" << in;
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
		std::cout << i << " ";
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



