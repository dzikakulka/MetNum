#include "src/vec.cpp"

int main()
{
	Vector wek1(3);
	wek1[0]=1; wek1[1]=2; wek1[2]=3;
	Vector wek2(3);
	Vector wek3(3, 2);

	Vector ans1 = wek1 * 5;
	ans1.Print(); std::cout << std::endl;

	double ans2 = wek1 * wek3;
	std::cout << "wek1 * wek2 = " << ans2 << std::endl;

	double ans3 = wek1 * wek2;

	std::cout << "Zjedz mnie" << std::endl;

	return 0;
}
