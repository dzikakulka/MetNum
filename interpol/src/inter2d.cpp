#include "../inc/inter.hh"
#include "../inc/spline.hh"

#define POINTS "./input.dat"

void do_prezentacji(const char *lag, const char *cbspl, const char *cpspl, const char *out, int min, int max)
{
	std::ifstream iStr(lag);
	std::ofstream oStr(out);
	//oStr << "unset key\n";
	oStr << "set key left top\n";
	oStr << "Wielomianowa(x)=";
	double in;
	std::vector<double> coeff;
	while(iStr >> in)
	{
		coeff.push_back(in);
	}
	for(int i=0; i<coeff.size(); i++)
		oStr << "+" << coeff[i] << "*x**" << coeff.size()-1-i;
	oStr << "\nNat_cubic_spline(x)=";
	iStr.close();
	iStr.open(cbspl);
	char input;
	while(iStr >> input)
		oStr << input;
	oStr << "\nClamp_cubic_spline(x)=";
	iStr.close();
	iStr.open(cpspl);
	while(iStr >> input)
		oStr << input;
	oStr << "\n plot [x=" << min << ":" << max << "] Wielomianowa(x)";
	oStr << "\n replot Nat_cubic_spline(x)";
	oStr << "\n replot Clamp_cubic_spline(x)";
	oStr << "\n replot 'sinput.dat' with points pointtype 4 lc rgb \"#FF0AFF\"";
	oStr << "\npause -1";
	
}

int main(int argc, char *argv[])
{
	const char *in;
	if(argc<2){in = POINTS;}
	else in = argv[1];
    build_vander(in, "data/vander.dat");
	les_solve("data/vander.dat", "data/lgr_poly.dat");
	//plot2d(in, "data/lgr_poly.dat");
	build_tridiag(in, "data/tridiag.dat", true);
	les_solve("data/tridiag.dat", "data/ncb_coeff.dat");
	ncb_spline(in, "data/ncb_coeff.dat", "data/ncb_poly_nat.dat");
	build_tridiag(in, "data/tridiag.dat", false);
	les_solve("data/tridiag.dat", "data/ncb_coeff.dat");
	ncb_spline(in, "data/ncb_coeff.dat", "data/ncb_poly_clp.dat");
	do_prezentacji("data/lgr_poly.dat", "data/ncb_poly_nat.dat", "data/ncb_poly_clp.dat", "prezout", 0, 5);
	return 0;
}
