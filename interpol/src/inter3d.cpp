//#include "../inc/inter.hh"
//#include "../inc/function.hh"
#include "../inc/spline.hh"

int main(int argc, char *argv[])
{
	/*const char *in;
	if(argc<2){in = POINTS;}
	else in=argv[1];
	split3d(in, "data/xy.dat", "data/xz.dat");
	build_vander("data/xy.dat", "data/vander.dat");
	les_solve("data/vander.dat", "data/xy_poly.dat");
	build_vander("data/xz.dat", "data/vander.dat");
	les_solve("data/vander.dat", "data/xz_poly.dat");
	plot3d(in, "data/xy_poly.dat", "data/xz_poly.dat");*/


	Dataset D1;
	D1.Read("dtest");
	D1.Print();

	std::ofstream oStr("ntest");
	
	oStr << "f(x)=" << build_spline(D1, natural) << "\n";
	oStr << "plot [x=0:3] f(x)" << "\n pause -1";

	return 0;
}
