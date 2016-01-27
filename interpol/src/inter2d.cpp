#ifndef _FH
#define _FH
#include "../inc/function.hh"
#endif
#include "../inc/inter.hh"
#include "../inc/spline.hh"


/*void do_prezentacji(const char *lag, const char *cbspl, const char *cpspl, const char *out, int min, int max)
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
	
	}*/

int main(int argc, char *argv[])
{

	// num plot_type {time_1D, time_2D, implicit_time_2D, implicit_time_3D};
	
	Dataset D1;
	D1.Read(argv[1]);
	D1.Print();
	FunPlot P1(time_1D);
	P1.Set_range(D1.tmin(), D1.tmax());
	P1.Add_dataset(D1.data());
	P1.Add_fun(build_lpoly(D1));
	P1.Add_fun(build_spline(D1, natural));
	P1.Plot();
	//std::ofstream oStr("ntest");
	
	//oStr << "f(x)=" << build_lpoly(D1) << "\n";
	//oStr << "plot [x=0:3] f(x)" << "\n pause -1";
	return 0;
}
