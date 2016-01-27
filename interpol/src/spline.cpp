#include "../inc/spline.hh"


std::string build_spline(Dataset input, spline_type type, int ind)
{
	build_tridiag(input, type, "data/tridiag.dat", ind-1);
	les_solve("data/tridiag.dat", "data/Dn.dat");
	return ncb_spline(input, "data/Dn.dat", ind-1);
}

void build_tridiag(Dataset input, spline_type type, const char *output, int dim)
{
	std::ofstream oStr(output);
	bool nat = (type==natural)?true:false;
	
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
	std::stringstream oStr;
	int n = points.Count();

	std::vector<double> p_y;
	for(int i=0; i<points.Count(); i++)
		p_y.push_back(points.p(dim, i));
	
	double in;
	std::vector<double> b_x;
	while(iStr >> in)
		b_x.push_back(in);
	

	std::vector<double> c_x;
	for(int i=0; i<(n-1); i++)
		c_x.push_back(3*(p_y[i+1]-p_y[i])-2*b_x[i]-b_x[i+1]);

	std::vector<double> d_x;
	for(int i=0; i<(n-1); i++)
		d_x.push_back(2*(p_y[i]-p_y[i+1])+b_x[i]+b_x[i+1]);

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
	for(unsigned int i=0; i<spline.size(); i++)
	{
		oStr << "+ ((t>=" << i << " && t<";
		if(i+1 == spline.size()) oStr << "="; 
		oStr << i+1 << ")?(";
		for(unsigned int j=0; j<spline[i]->size(); j++)
		{
				oStr << " + " << (*spline[i])[j] << " * (t-" << i << ")**" << j;
		}
		oStr << "):0)";

	}
	std::string out = oStr.str();
	return out;
	}
