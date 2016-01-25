#include "../inc/inter.hh"
#include "../inc/spline.hh"

#define POINTS "./input.dat"

int main(int argc, char *argv[])
{
	const char *in;
	if(argc<2){in = POINTS;}
	else in = argv[1];
    //build_vander(in, "data/vander.dat");
	//les_solve("data/vander.dat", "data/lgr_poly.dat");
	//plot2d(in, "data/lgr_poly.dat");
	build_tridiag(in, "data/tridiag.dat");
	les_solve("data/tridiag.dat", "data/ncb_coeff.dat");
	ncb_spline(in, "data/ncb_coeff.dat", "data/ncb_poly.dat");
	return 0;
}
