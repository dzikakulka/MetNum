#include "../inc/spline.hh"


std::string build_spline(Dataset input, spline_type type)
{
	build_tridiag(input, type, "data/tridiag.dat", 0);
	les_solve("data/tridiag.dat", "data/Dn.dat");
	return ncb_spline(input, "data/Dn.dat", 0);
}

void build_tridiag(Dataset input, spline_type type, const char *output, int dim)
{
	//std::ifstream iStr(input);
	std::ofstream oStr(output);
	bool nat = (type==natural)?true:false;
	/*std::vector<double> p_y;
	double in;
	while(iStr >> in)
	{
		//p_x.push_back(in);
		if(iStr >> in)
			p_y.push_back(in);
		else
			std::cerr << "Niekompletne dane!" << std::endl;
			}*/

	//oStr << p_y.size() << "\n";
	std::cerr << "X:" << input.Count();
	oStr << input.Count() << "\n";
	
	for(int i=0; i<input.Count(); i++)
	{
		for(int j=0; j<input.Count(); j++)
		{
			if( (j == 0) && (i == 0) && nat ) oStr << "2 ";
			else if ( (j == input.Count()-1) && (i == input.Count()-1) && nat) oStr << "2 ";
			else if(!nat && (( (j==0) && (i==input.Count()-1) )||( (j==input.Count()) && (i==0) ))) oStr << "1 ";
			else if(j==i) oStr << "4 ";
			else if( (j == i-1) || (j == i+1) ) oStr << "1 ";
			else oStr << "0 ";
		}
		oStr << "\n";
	}
	int i1=1, i2=0;
	for(int i=0; i<input.Count(); i++)
	{
		oStr << 3*(input.p(dim, i1)-input.p(dim, i2)) << " "; // i1 << " " << i2 << "\n";
		if(i1 != 1) i2++;
		if(i1 < (input.Count()-1)) i1++;
	}
	
	
}

std::string ncb_spline(Dataset points, const char *coeffs, int dim)
{

	std::ifstream iStr(coeffs);
	//std::ofstream oStr(poly_out);
	std::stringstream oStr;

	/*std::vector<double> p_x, p_y;
	double in;
	while(iStr >> in)
	{
		p_x.push_back(in);
		if(iStr >> in)
			p_y.push_back(in);
		else
			std::cerr << "Niekompletne dane!" << std::endl;
			}*/

	int n = points.Count();

	//for(int i=0; i<p_x.size(); i++)
//		if(p_x[i]!=i) {std::cout << "NIE-E"; std::terminate();}

	//iStr.close();
	//iStr.open(coeffs);

	std::vector<double> p_y;
	for(int i=0; i<points.Count(); i++)
		p_y.push_back(points.p(dim, i));
	
	double in;
	std::vector<double> b_x;
	while(iStr >> in)
		b_x.push_back(in);
	//std::cerr << "S:" << b_x.size() << " N:" << n << " " << "\n";
	

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
		oStr << "+ ((t>=" << i << " && t<";
		if(i+1 == spline.size()) oStr << "="; 
		oStr << i+1 << ")?(";
		for(int j=0; j<spline[i]->size(); j++)
		{
				oStr << " + " << (*spline[i])[j] << " * (t-" << i << ")**" << j;
		}
		//oStr << "\n";
		oStr << "):0)";

		//poly += "[" + i + ":" + i+1 + "] -> ";
	}
	std::string out = oStr.str();
	return out;
	}
