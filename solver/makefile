FLAGS = -pedantic -Wall -g

solve.out: main.o util.o vec.o mat.o eqs.o
	g++ ${FLAGS} -o solve.out out/main.o out/util.o out/vec.o out/mat.o out/eqs.o

main.o: main.cpp
	g++ ${FLAGS} -c -o out/main.o main.cpp

util.o: inc/util.hh src/util.cpp
	g++ ${FLAGS} -c -o out/util.o src/util.cpp

vec.o: inc/vec.hh src/vec.cpp
	g++ ${FLAGS} -c -o out/vec.o src/vec.cpp

mat.o: inc/mat.hh src/mat.cpp
	g++ ${FLAGS} -c -o out/mat.o src/mat.cpp

eqs.o: inc/eqs.hh src/eqs.cpp
	g++ ${FLAGS} -c -o out/eqs.o src/eqs.cpp

clean:
	rm -f *.out
	rm -f out/*.o
	rm -f output.dat 

qsolve: qsolve.o util.o vec.o mat.o eqs.o
	g++ ${FLAGS} -o qsolve.out out/qsolve.o out/util.o out/vec.o out/mat.o out/eqs.o

qsolve.o: src/qsolve.cpp
	g++ ${FLAGS} -c -o out/qsolve.o src/qsolve.cpp
