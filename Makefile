CC = gcc -lrt -lstdc++ -lsupc++ -Iinclude 
CCOnly = gcc -Iinclude -c

CCN = gcc -ggdb -lrt -lstdc++ -Iinclude
CCNOnly = gcc -ggdb -lncurses -Iinclude -c

all : bin/libmath_vector.so bin/test_math_vector

clean :
	rm bin/*.o

bin/math_vector.o: src/math_vector.cpp include/math_vector.h
	$(CCNOnly) src/math_vector.cpp -fpic -o bin/math_vector.o

bin/libmath_vector.so: bin/math_vector.o
	$(CCN) bin/math_vector.o -o bin/libmath_vector.so -shared

bin/test_math_vector: src/*.cpp include/math_vector.h 
	$(CCN) src/*.cpp -o bin/test_math_vector




