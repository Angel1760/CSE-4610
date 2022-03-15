//to compile: c++ -c sdisk.cpp main.cpp
//c++ -o project1 main.o
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#ifndef SDISK_H
#define SDISK_H


class Sdisk{
public: 
//This constructor incorporates the creation of the disk with the "formatting" of the device.

Sdisk(string diskname, int numberofblocks, int blocksize);
int getnumberofblocks();
//block size of bytes 
int getblocksize();
/*retrieves block blocknumber from the disk and stores the data in the string buffer. 
It returns an error code of 1 if successful and 0 otherwise.*/
int getblock(int blocknumber, string& buffer);
//writes the string buffer to block blocknumber. It returns an error code of 1 if successful and 0 otherwise.
int putblock(int blocknumber, string buffer);

private:

    string diskname;
    int numberofblocks;
    int blocksize;
};
#endif