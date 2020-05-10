export CC=g++
export CFLAGS=-W -Wall -std=c++11 -pedantic

# Specify to compile main and use clean
all: main_vcons main clean

main_vcons: main_vcons.o vconsignee.o ticket.o
	$(CC) -o main_vcons.exe main_vcons.o vconsignee.o ticket.o $(CFLAGS)

main_vcons.o: main_vcons.cpp vconsignee.hpp luggage.hpp
	$(CC) -c main_vcons.cpp $(CFLAGS)

main: main.o consignee.o ticket.o
	$(CC) -o main.exe main.o consignee.o ticket.o $(CFLAGS)

main.o: main.cpp consignee.hpp
	$(CC) -c main.cpp $(CFLAGS)

vconsignee.o: vconsignee.cpp vconsignee.hpp ticket.hpp
	$(CC) -c vconsignee.cpp $(CFLAGS)

consignee.o: consignee.cpp consignee.hpp ticket.hpp
	$(CC) -c consignee.cpp $(CFLAGS)

ticket.o: ticket.cpp ticket.hpp
	$(CC) -c ticket.cpp $(CFLAGS)

clean:
	rm -rf *.o