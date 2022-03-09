cmatrix : main.o matrix.o vector.o
	cc -o cmatrix main.o matrix.o vector.o

main.o : main.c
	cc -c main.c

vector.o : vector.c vector.h
	cc -c vector.c

matrix.o : matrix.c matrix.h
	cc -c matrix.c

clean:
	rm cmatrix main.o matrix.o vector.o
