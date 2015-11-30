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
	oStr << std::endl << "end" << std::endl << "pause 10";

	system("gnuplot -persist plot.dat");
	
}
