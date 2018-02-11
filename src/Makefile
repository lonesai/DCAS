CFLAGS =  -c -Wall -lpthread
CC = g++

dcas: dcas.o world.o drone.o
	$(CC) dcas.o world.o drone.o -o dcas
dacs.o: dcas.cpp
	$(CC) $(CFLAGS) dcas.cpp
world.o: world.cpp
	$(CC) $(CFLAGS) world.cpp
drone.o: drone.cpp
	$(CC) $(CFLAGS) drone.cpp
clean:
	rm -rf core *o dcas
