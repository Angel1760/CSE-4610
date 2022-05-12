proj1: sdisk.o source.o
	g++ sdisk.o source.o -o proj1 

proj2: sdisk.o filesys.o source.o block.o
	g++ sdisk.o filesys.o source.o block.o -o proj2

proj3: source.o sdisk.o filesys.o shell.o block.o
	g++ source.o sdisk.o filesys.o shell.o block.o -o proj3

proj4: source.o sdisk.o filesys.o shell.o block.o table.o
	g++ source.o sdisk.o filesys.o shell.o block.o table.o -o proj4

source.o: source.cpp
	g++ -c source.cpp

sdisk.o: sdisk.cpp sdisk.h
	g++ -c sdisk.cpp

filesys.o: filesys.cpp filesys.h
	g++ -c filesys.cpp

shell.o: shell.cpp shell.h
	g++ -c shell.cpp

block.o: block.cpp block.h
	g++ -c block.cpp

table.o: table.cpp table.h
	g++ -c table.cpp

clean:
	rm *.o 

