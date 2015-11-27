FLAGS = -pedantic -Wall -g

solve.out: main.o util.o vec.o mat.o
	g++ ${FLAGS} -o solve.out out/main.o out/util.o out/vec.o out/mat.o
	./solve.out

main.o: main.cpp
	g++ ${FLAGS} -c -o out/main.o main.cpp

util.o: inc/util.hh src/util.cpp
	g++ ${FLAGS} -c -o out/util.o src/util.cpp

vec.o: inc/vec.hh src/vec.cpp
	g++ ${FLAGS} -c -o out/vec.o src/vec.cpp

mat.o: inc/mat.hh src/mat.cpp
	g++ ${FLAGS} -c -o out/mat.o src/mat.cpp
