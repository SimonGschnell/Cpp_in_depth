# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
seperate_folder: examples.o add.o main
	mkdir -p example
	mv examples.o example
	mv add.o example

main: namespaces.o add.o
	$(CC) $(CFLAGS) -o main namespaces.o add.o


examples.o: namespaces.cpp
	$(CC) $(CFLAGS) -c namespaces.cpp

add.o: add.cpp
	$(CC) $(CFLAGS) -c add.cpp

remove_obj: 
	rm *.o
