CC = g++															   
 
sort: main.cpp hashtable.o
	$(CC) main.cpp hashtable.o -o sort
 
hashtable.o: hashtable.cpp
	$(CC) -c hashtable.cpp

#sort: main.cpp skiplist.o
#	$(CC) main.cpp skiplist.o -o sort
 
#skiplist.o: skiplist.cpp
#	$(CC) -c skiplist.cpp

#sort: main.cpp treap.o
#	$(CC) main.cpp treap.o -o sort
 
#treap.o: treap.cpp
#	$(CC) -c treap.cpp

#sort: main.cpp sortedarray.o
#	$(CC) main.cpp sortedarray.o -o sort
 
#sortedarray.o: sortedarray.cpp
#	$(CC) -c sortedarray.cpp

clean:
	rm *.o sort
