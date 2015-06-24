all:kruskal.exe

kruskal.exe:main.o kruskal.o
	gcc kruskal.o main.o -o kruskal.exe

kruskal.o:kruskal.c
	gcc -c kruskal.c -o kruskal.o

main.o:main.c
	gcc -c main.c -o main.o

clean:
	rm -f kruskal.exe *.o
