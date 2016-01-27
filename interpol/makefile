FLAGS = -pedantic -Wall -g

inter: fun.o lpoly.o spline.o inter.o
	g++ ${FLAGS} -o inter.out out/fun.o out/lpoly.o out/spline.o out/inter.o

fun.o: src/function.cpp inc/function.hh
	g++ ${FLAGS} -c -o out/fun.o src/function.cpp

lpoly.o: src/lpoly.cpp inc/lpoly.hh
	g++ ${FLAGS} -c -o out/lpoly.o src/lpoly.cpp

spline.o: src/spline.cpp inc/spline.hh
	g++ ${FLAGS} -c -o out/spline.o src/spline.cpp

inter.o: src/inter.cpp
	g++ ${FLAGS} -c -o out/inter.o src/inter.cpp

clean:
	rm -f *.out
	rm -f out/*.o
	rm -f plot.dat
	rm -f data/*

