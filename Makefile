objects = main.o matrix.o vector.o

cmatrix : $(objects)
	cc -o cmatrix $(objects)

main.o : main.c
	cc -c main.c

vector.o : vector.c vector.h
	cc -c vector.c

matrix.o : matrix.c matrix.h
	cc -c matrix.c

clean:
	rm cmatrix $(objects)
