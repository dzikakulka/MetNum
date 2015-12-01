#include "../inc/inter.hh"

#define POINTS "./input.dat"

int main(int argc, char *argv[])
{
	const char *in;
	if(argc<2){in = POINTS;}
	else in = argv[1];
    build_vander(in, "data/vander.dat");
	les_solve("data/vander.dat", "data/s_out.dat");
	plot2d(in, "data/s_out.dat");	
	return 0;
}
