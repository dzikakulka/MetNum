FLAGS = -pedantic -Wall -g

PROJ: inter2d inter3d

inter2d: inter2d.o inter.o spline.o
	g++ ${FLAGS} -o inter2d.out out/inter2d.o out/inter.o out/spline.o

inter3d: inter3d.o inter.o fun.o
	g++ ${FLAGS} -o inter3d.out out/inter3d.o out/inter.o out/fun.o

inter3d.o: src/inter3d.cpp
	g++ ${FLAGS} -c -o out/inter3d.o src/inter3d.cpp

inter2d.o: src/inter2d.cpp
	g++ ${FLAGS} -c -o out/inter2d.o src/inter2d.cpp

spline.o: src/spline.cpp inc/spline.hh
	g++ ${FLAGS} -c -o out/spline.o src/spline.cpp

inter.o: inc/inter.hh src/inter.cpp
	g++ ${FLAGS} -c -o out/inter.o src/inter.cpp

fun.o: src/function.cpp inc/function.hh
	g++ ${FLAGS} -c -o out/fun.o src/function.cpp

clean:
	rm -f *.out
	rm -f out/*.o
	rm -f plot.dat
	rm -f data/*.dat

