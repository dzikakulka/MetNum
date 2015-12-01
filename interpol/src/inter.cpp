#include "../inc/inter.hh"

//#define PLOT "plot.dat"

bool les_solve(const char *input, const char *output)
{
	std::string command = SOLVE_RUN;
	command = command + " " + input + " " + output; 
	system(command.c_str());
	
	return true;
}

void build_vander(const char *input, const char *output)
{
	std::vector<double> p_x, p_y;
	std::ifstream inStr(input);
	double in;
	while(inStr >> in)
	{
		p_x.push_back(in);
		if(inStr >> in)
			p_y.push_back(in);
		else
			std::cerr << "Niekompletne dane!" << std::endl;
	}

	std::ofstream oStr(output);
	oStr << p_x.size() << std::endl << std::endl;
	for(unsigned int i=0; i<p_x.size(); i++){
		for(int j=p_x.size()-1; j>=0; j--)
			oStr << pow(p_x[i], (double) j) << " ";
		oStr << std::endl;}
	oStr << std::endl << std::endl;
	for(unsigned int i=0; i<p_x.size(); i++)
		oStr << p_y[i] << " ";


}

void plot2d(const char *points, const char *poly)
{

	std::ifstream iStr(poly);
	std::vector<double> coeff;
	double temp;
	while(iStr >> temp)
		coeff.push_back(temp);

	std::ofstream oStr("plot.dat");
	oStr << "f(x) = ";
	for(unsigned int i=0; i<coeff.size(); i++)
		oStr << "+" << coeff[i] << "*x**" << coeff.size()-1-i;
	oStr << std::endl << "plot f(x)";
	oStr << std::endl << "replot \"-\" using 1:2 with points" << std::endl;
	iStr.close();
	iStr.open(points);
	char in;
	while(iStr >> std::noskipws >> in)
		oStr << in;
	oStr << std::endl << "end" << std::endl << "pause -1";

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

	std::ofstream tempStr("data/temp.dat");
	
	tempStr << "replot '-' using 1:2:3 with points" << std::endl;
	
    double in, x_first, x_last;
	if(iStr >> in){ x_first = in; tempStr << in << " ";}

	for(int k=2; iStr >> in; k=((k==3)?(1):(k+1)))
	{
		tempStr << in << " ";
		if(k==3) tempStr << std::endl;
		if(k==1) x_last = in;
	}
	tempStr << "end" << std::endl << "pause -1";
	
	oStr << "set parametric" << std::endl;
	oStr << "set xlabel \"X\"\nset ylabel \"Y\"\nset zlabel \"Z\"\n";
	oStr << "splot [x=" << x_first-(x_first*0.1) << ":" << x_last+(x_last*0.1) << "] x, y(x), z(x) \n";

	tempStr.close();
	iStr.close();
	iStr.open("data/temp.dat");
	char tmp;
	while(iStr >> std::noskipws >> tmp)
		oStr << tmp;

	system("gnuplot -persist plot.dat&");
}
