#include "../inc/inter.hh"

#define POINTS "./input.dat"

int main(int argc, char *argv[])
{
	const char *in;
	if(argc<2){in = POINTS;}
	else in = argv[1];
    build_vander(in, "vander.dat");
	les_solve("vander.dat", "s_out.dat");
	plot2d(in, "s_out.dat");	
	return 0;
}
