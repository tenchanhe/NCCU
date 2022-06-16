CC = g++

sort: main.cpp heapsort.o
	$(CC) main.cpp heapsort.o -o sort

heapsort.o: heapsort.cpp
	$(CC) -c heapsort.cpp

clean:
	rm *.o sort
