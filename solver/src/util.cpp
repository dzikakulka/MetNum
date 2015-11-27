#include "../inc/util.hh"

double abs(double val)
{
	return (val>0)?val:(-1*val);
}

void M(std::string mess, std::ostream& outStr){ outStr << mess; }

void Nl(int lines, std::ostream& outStr){ for(int i=0; i<lines; i++) outStr << std::endl << std::flush; }
