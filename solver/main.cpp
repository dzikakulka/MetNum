#include "inc/mat.hh"

int main()
{
	/*Vector v1(4,1);
    Vector v2 = v1;
	v1.Print();	v2.Print();
	v1.Read();
	v1.Print();	v2.Print();*/
	
	
	Vector v1(5), v2(5), v3(5), v4(5), v5(5);
	v1.Read(); v2.Read(); v3.Read(); v4.Read(); v5.Read();
	Matrix m1(5,5);
	m1.Set(v1, 0);
	m1.Set(v2, 1);
	m1.Set(v3, 2);
	m1.Set(v4, 3);
	m1.Set(v5, 4);
	m1.Print();
	m1.Det();
	m1.Print();
	
	return 0;
}
