all:prim.exe

prim.exe:main.o prim.o
	gcc prim.o main.o -o prim.exe

prim.o:prim.c
	gcc -c prim.c -o prim.o

main.o:main.c
	gcc -c main.c -o main.o

clean:
	rm -f prim.exe *.o
