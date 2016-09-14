all: test run clean

test: test.cpp geometry.cpp geometry.h point.cpp point.h
	g++ -o test.o test.cpp geometry.cpp geometry.h point.cpp point.h

run:
	./test.o

clean:
	rm *.o
