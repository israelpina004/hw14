all: hw14.o
	gcc -o hw14 hw14.o

hw14.o: hw14.c
	gcc -c hw14.c

run:
	./hw14

clean:
	rm *.o
