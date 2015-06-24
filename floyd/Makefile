all:floyd.exe

floyd.exe:main.o floyd.o
	gcc floyd.o main.o -o floyd.exe

floyd.o:floyd.c
	gcc -c floyd.c -o floyd.o

main.o:main.c
	gcc -c main.c -o main.o

clean:
	rm -f floyd.exe *.o
