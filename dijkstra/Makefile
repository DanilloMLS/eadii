all:dijkstra.exe

dijkstra.exe:main.o dijkstra.o
	gcc dijkstra.o main.o -o dijkstra.exe

dijkstra.o:dijkstra.c
	gcc -c dijkstra.c -o dijkstra.o

main.o:main.c
	gcc -c main.c -o main.o

clean:
	rm -f dijkstra.exe *.o
