#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "sdisk.h"
#include "block.h"

#pragma once
#ifndef FILESYS_H
#define FILESYS_H

using namespace std;

class Filesys: public Sdisk
{
public :

Filesys(string filename,int numberofblocks, int blocksize);
int fsclose();
int newfile(string file); //added 4/5/22; not sure if correct
int rmfile(string file);
int getfirstblock(string file);
int addblock(string file, string block);
int delblock(string file, int blocknumber);
int readblock(string file, int blocknumber, string& buffer);
int writeblock(string file, int blocknumber, string buffer);
int nextblock(string file, int blocknumber);

bool checkblock(string file, int block);

//vector<string> block(string buffer, int b); //shouldnt be here but makes source.cpp work
vector<string> ls();    //added 4/5/22; not sure if needs to be here




private :
int rootsize;           // maximum number of entries in ROOT
int fatsize;            // number of blocks occupied by FAT
vector<string> filename;   // filenames in ROOT
vector<int> firstblock; // firstblocks in ROOT
vector<int> fat;             // FAT
int buildfs(); // builds the file system
int readfs();// reads the file system
int fssynch(); // writes the FAT and ROOT to the sdisk
};
#endif
