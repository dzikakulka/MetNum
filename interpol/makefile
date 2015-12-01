FLAGS = -pedantic -Wall -g

PROJ: inter2d inter3d

inter2d: inter2d.o inter.o
	g++ ${FLAGS} -o inter2d.out out/inter2d.o out/inter.o

inter3d: inter3d.o inter.o
	g++ ${FLAGS} -o inter3d.out out/inter3d.o out/inter.o

inter3d.o: src/inter3d.cpp
	g++ ${FLAGS} -c -o out/inter3d.o src/inter3d.cpp

inter2d.o: src/inter2d.cpp
	g++ ${FLAGS} -c -o out/inter2d.o src/inter2d.cpp

inter.o: inc/inter.hh src/inter.cpp
	g++ ${FLAGS} -c -o out/inter.o src/inter.cpp

clean:
	rm -f *.out
	rm -f out/*.o
	rm -f plot.dat
	rm -f data/*.dat

