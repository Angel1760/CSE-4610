output: source.o sdisk.o filesys.o shell.o 
	g++ source.o sdisk.o filesys.o shell.o -o output

proj2: sdisk.o filesys.o source.o
	g++ sdisk.o filesys.o source.o -o proj2


source.o: source.cpp
	g++ -c source.cpp

sdisk.o: sdisk.cpp sdisk.h
	g++ -c sdisk.cpp

filesys.o: filesys.cpp filesys.h
	g++ -c filesys.cpp


shell.o: shell.cpp shell.h
	g++ -c shell.cpp

clean:
	rm *.o 

