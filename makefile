all: ex6_q2.cpp Polynomial.h
	g++ ex6_q2.cpp -o ex6_q2
all-GDB: ex6_q2.cpp Polynomial.h 
	g++ -g ex6_q2.cpp -o ex6_q2
