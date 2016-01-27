#ifndef _FH
#define _FH
#include "../inc/function.hh"
#endif
#include "../inc/lpoly.hh"
#include "../inc/spline.hh"


int main(int argc, char *argv[])
{

	// num plot_type {time_1D, time_2D, implicit_time_2D, implicit_time_3D};

	if(argc<3)
	{
		std::cerr << "Wywolanie: ./inter.out [dane] [nspline | cspline | lpoly] \n";
		return 1;
	}

	int typ_int;
	if(!std::strcmp(argv[2], "nspline")) typ_int = 0;
	else if(!std::strcmp(argv[2], "cspline")) typ_int = 1;
	else if(!std::strcmp(argv[2], "lpoly")) typ_int = 2;
	else
	{
		std::cerr << "Wywolanie: ./inter.out [dane] [nspline | cspline | lpoly] \n";
		return 1;
	}
	
	Dataset D1;
	D1.Read(argv[1]);
	std::cout << "\n Input: \n";
	D1.Print();
	int dim = D1.Dim();

	plot_type type;
	switch(dim)
	{
	case(1):
		type = time_1D; break;
	case(2):
		type = implicit_time_2D; break;
	case(3):
		type = implicit_time_3D; break;
	}
	
	FunPlot P1(type);
	P1.Set_range(D1.tmin(), D1.tmax());
	P1.Add_dataset(D1);
	for(int i=1; i<=dim; i++)
		if(typ_int == 0) P1.Add_fun(build_spline(D1, natural, i));
		else if(typ_int == 1) P1.Add_fun(build_spline(D1, clamped, i));
		else if(typ_int == 2) P1.Add_fun(build_lpoly(D1, i));
	P1.Plot();
	
	return 0;
}
