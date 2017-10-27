all: devran.o
	gcc -o devran devran.o

devran.o: devran.c
	gcc -c devran.c

clean:
	rm -f *.o *~ devran
run: all
	./devran
