export CC=g++
export CFLAGS=-W -Wall -std=c++11 -pedantic

# Specify to compile main and use clean
all: main clean

main: main.o consignee.o ticket.o
	$(CC) -o main.exe main.o consignee.o ticket.o $(CFLAGS)

main.o: main.cpp consignee.hpp
	$(CC) -c main.cpp $(CFLAGS)

consignee.o: consignee.cpp consignee.hpp ticket.hpp
	$(CC) -c consignee.cpp $(CFLAGS)

ticket.o: ticket.cpp ticket.hpp
	$(CC) -c ticket.cpp $(CFLAGS)

clean:
	rm -rf *.o