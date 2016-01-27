#include "../inc/inter.hh"

#define ADD_RANGE 0


std::string build_lpoly(Dataset points)
{
	build_vander(points, "data/vander.dat", 0);
	les_solve("data/vander.dat", "data/coeffs.dat");
	return lpoly("data/coeffs.dat");
}

std::string lpoly(const char *coeffs)
{
	std::ifstream iStr(coeffs);
	std::stringstream str;

	std::vector<double> temp;
	double in;
	while(iStr >> in)
		temp.push_back(in);

	int n=temp.size();
	for(int i=0; i<n; i++)
		str << " + " << temp[i] << "*t**" << n-i-1;
	return str.str();
	
}



void build_vander(Dataset points, const char *output, int dim)
{
	/*std::vector<double> p_x, p_y;
	std::ifstream inStr(input);
	double in;
	while(inStr >> in)
	{
		p_x.push_back(in);
		if(inStr >> in)
			p_y.push_back(in);
		else
			std::cerr << "Niekompletne dane!" << std::endl;
			}*/

	std::ofstream oStr(output);
	
	oStr << points.Count() << std::endl << std::endl;
	for(unsigned int i=0; i<points.Count(); i++){
		for(int j=points.Count()-1; j>=0; j--)
			oStr << pow(points.t(i), (double) j) << " ";
		oStr << std::endl;}
	oStr << std::endl << std::endl;
	for(unsigned int i=0; i<points.Count(); i++)
		oStr << points.p(dim, i) << " ";


}

void plot2d(const char *points, const char *poly)
{

	std::ifstream iStr(points);

	double in, x_first, x_last;
	if(iStr >> in) x_first = in;

	for(int k=2; iStr >> in; k=((k==3)?(1):(k+1)))
		if(k==1) x_last = in;

	iStr.close();
	iStr.open(poly);
	
	std::vector<double> coeff;
	double temp;
	while(iStr >> temp)
		coeff.push_back(temp);
	
	std::ofstream oStr("plot.dat");
	oStr << "f(x) = ";
	for(unsigned int i=0; i<coeff.size(); i++)
		oStr << "+" << coeff[i] << "*t**" << coeff.size()-1-i;
	double range = x_last - x_first;
	oStr << "\nplot [x=" << x_first-(range*ADD_RANGE) << ":" << x_last+(range*ADD_RANGE) << "] f(x)\n";
	//std::string points_file(points);
	//if(points_file[0]=='.') points_file.erase(0, 2);
	oStr << "replot '" << points << "' with points\n";
	oStr << "pause -1";

	system("gnuplot -persist plot.dat&");
	
}

void split3d(const char *input, const char *out1, const char *out2)
{
	std::ifstream inStr(input);
	std::ofstream oStr1(out1);
	std::ofstream oStr2(out2);

	double in;
	while(inStr >> in)
	{
		oStr1 << in << " ";
		oStr2 << in << " ";
		//std::cout << "X: " << in << std::endl;
		if(inStr >> in)
		{
			oStr1 << in << std::endl;
			//	std::cout << "Y: " << in << std::endl;
			if(inStr >> in)
			{
				oStr2 << in << std::endl;
				//	std::cout << "Z: " << in << std::endl;
			}
			else
				std::cerr << "Niekompletne dane!" << std::endl;
		}
		else
			std::cerr << "Niekompletne dane!" << std::endl;
	}


}

void plot3d(const char *points, const char *polyxy, const char *polyxz)
{
	std::ifstream iStr(polyxy);
	std::vector<double> coeff;
	double temp;
	while(iStr >> temp)
		coeff.push_back(temp);

	std::ofstream oStr("plot.dat");
	oStr << "y(x) = ";
	for(unsigned int i=0; i<coeff.size(); i++)
		oStr << "+" << coeff[i] << "*x**" << coeff.size()-1-i;
	oStr << std::endl;
	
	coeff.clear();
	iStr.close();
	iStr.open(polyxz);

	while(iStr >> temp)
		coeff.push_back(temp);
	
	oStr << "z(x) = ";
	for(unsigned int i=0; i<coeff.size(); i++)
		oStr << "+" << coeff[i] << "*x**" << coeff.size()-1-i;
	oStr << std::endl;

	iStr.close();
	iStr.open(points);
	
    double in, x_first, x_last;
	if(iStr >> in) x_first = in;

	for(int k=2; iStr >> in; k=((k==3)?(1):(k+1)))
		if(k==1) x_last = in;
	
	oStr << "set parametric" << std::endl;
	oStr << "set xlabel \"X\"\nset ylabel \"Y\"\nset zlabel \"Z\"\n";
  	double range = x_last - x_first;
	oStr << "splot [x=" << x_first-(range*ADD_RANGE) << ":" << x_last+(range*ADD_RANGE) << "] x, y(x), z(x) \n";
	oStr << "replot '" << points << "' with points\n pause -1"; 

	system("gnuplot -persist plot.dat&");
}
