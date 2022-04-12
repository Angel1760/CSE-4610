#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "sdisk.h"

using namespace std;

class Filesys{

public :

Filesys(string filename,int numberofblocks, int blocksize);
int fsclose();
int newfile(string file);
int newfile(string newname); //added 4/5/22; not sure if correct
int rmfile(string file);
int getfirstblock(string file);
int addblock(string file, string block);
int delblock(string file, int blocknumber);
int readblock(string file, int blocknumber, string& buffer);
int writeblock(string file, int blocknumber, string buffer);
int nextblock(string file, int blocknumber);
bool checkblock(string file, int block);



private :
int rootsize;           // maximum number of entries in ROOT
int fatsize;            // number of blocks occupied by FAT
vector<string> filename;   // filenames in ROOT
vector<int> firstblock; // firstblocks in ROOT
vector<int> fat;             // FAT
vector<string> block(string s, int b) //may need to be placed in the public
vector<string> ls();    //added 4/5/22; not sure if needs to be here
int buildfs(); // builds the file system
int readfs();// reads the file system
int fssynch(); // writes the FAT and ROOT to the sdisk
};