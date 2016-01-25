#include "../inc/spline.hh"

void build_tridiag(const char *input, const char *output)
{
	std::ifstream iStr(input);
	std::ofstream oStr(output);

	std::vector<double> p_y;
	double in;
	while(iStr >> in)
	{
		//p_x.push_back(in);
		if(iStr >> in)
			p_y.push_back(in);
		else
			std::cerr << "Niekompletne dane!" << std::endl;
	}

	oStr << p_y.size() << "\n";
	
	for(int i=0; i<p_y.size(); i++)
	{
		for(int j=0; j<p_y.size(); j++)
		{
			if( (j == 0) && (i == 0) ) oStr << "2 ";
			else if ( (j == p_y.size()-1) && (i == p_y.size()-1) ) oStr << "2 "; 
			else if(j==i) oStr << "4 ";
			else if( (j == i-1) || (j == i+1) ) oStr << "1 ";
			else oStr << "0 ";
		}
		oStr << "\n";
	}
	int i1=1, i2=0;
	for(int i=0; i<p_y.size(); i++)
	{
		oStr << 3*(p_y[i1]-p_y[i2]) << " "; // i1 << " " << i2 << "\n";
		if(i1 != 1) i2++;
		if(i1 < (p_y.size()-1)) i1++;
	}
	
	
}

void ncb_spline(const char *points, const char *coeffs, const char *poly_out)
{

	std::ifstream iStr(points);
	std::ofstream oStr(poly_out);

	std::vector<double> p_x, p_y;
	double in;
	while(iStr >> in)
	{
		p_x.push_back(in);
		if(iStr >> in)
			p_y.push_back(in);
		else
			std::cerr << "Niekompletne dane!" << std::endl;
	}

	int n = p_x.size();

	for(int i=0; i<p_x.size(); i++)
		if(p_x[i]!=i) {std::cout << "NIE-E"; std::terminate();}

	iStr.close();
	iStr.open(coeffs);
	
	std::vector<double> b_x;
	while(iStr >> in)
		b_x.push_back(in);

	std::vector<double> c_x;
	for(int i=0; i<(n-1); i++)
		c_x.push_back(3*(p_y[i+1]-p_y[i])-2*b_x[i]-b_x[i+1]);

	std::vector<double> d_x;
	for(int i=0; i<(n-1); i++)
		d_x.push_back(2*(p_y[i]-p_y[i+1])+b_x[i]+b_x[i+1]);

	/*
	std::vector<double> *ptr = &p_x;
	for(int i=0; i<(*ptr).size(); i++)
		oStr << (*ptr)[i] << " ";
	oStr << "\n";
	ptr = &p_y;
	for(int i=0; i<(*ptr).size(); i++)
		oStr << (*ptr)[i] << " ";
	oStr << "\n";
	ptr = &b_x;
	for(int i=0; i<(*ptr).size(); i++)
		oStr << (*ptr)[i] << " ";
	oStr << "\n";
	ptr = &c_x;
	for(int i=0; i<(*ptr).size(); i++)
		oStr << (*ptr)[i] << " ";
	oStr << "\n";
	ptr = &d_x;
	for(int i=0; i<(*ptr).size(); i++)
		oStr << (*ptr)[i] << " ";
		oStr << "\n";*/

	std::vector< std::vector<double>* > spline;
	for(int i=0; i<(n-1); i++)
	{
		std::vector<double> *poly = new std::vector<double>;
		poly->push_back(p_y[i]);
		poly->push_back(b_x[i]);
		poly->push_back(c_x[i]);
		poly->push_back(d_x[i]);
		spline.push_back(poly);
	}
	for(int i=0; i<spline.size(); i++)
	{
		//oStr << "[" << i << ":" << i+1 << "] -> ";
		oStr << "+ ((x>=" << i << " && x<";
		if(i+1 == spline.size()) oStr << "="; 
		oStr << i+1 << ")?(";
		for(int j=0; j<spline[i]->size(); j++)
		{
			oStr << " + " << (*spline[i])[j] << " * (x-" << i << ")**" << j;
		}
		//oStr << "\n";
		oStr << "):0)";

	}
	
}
