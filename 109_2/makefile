CC=g++

pokemon.exe: pokemon_main.o pokemon.o
	$(CC) -o pokemon.exe pokemon_main.o pokemon.o

pokemon_main.o: pokemon_main.cpp pokemon.h
	$(CC) -c pokemon_main.cpp

pokemon.o: pokemon.cpp pokemon.h
	$(CC) -c pokemon.cpp
