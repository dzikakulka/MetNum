#include "../inc/util.hh"

double abs(double val)
{
	return (val>0)?val:(-1*val);
}

void M(std::string mess){ std::cout << mess; }

void Nl(int lines){ for(int i=0; i<lines; i++) std::cout << std::endl << std::flush; }
