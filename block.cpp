#include <vector>
#include <string>
#include "filesys.h"

using namespace std;

/*
string class 
    s. c_str() //converts string to c string
    s.length() // size of string
    s.substr(k,n) //k=position, n=length
*/
vector<string> block(string s, int b)
{
    //s-buffer, b-blocksize
    vector<string> blocks;
    int numberofblocks = 0;
   
    if(s.length() % b == 0)
    {
        numberofblocks = s.length() / b;
    }
    else
    {
        numberofblocks = s.length() / b + 1;
    }
}

string tempblock;
for (int i = 0; i < numberofblocks; i++)
{
   tempblock = s.substr(b*i, b)
   blocks.pushback(tempblock);
}

//add #'s to index the number of blocks
int lastblock = block.size() - 1;

for (int i = blocks[lastblock].length(); i<b; i++)
    {
        blocks[lastblock] += "#";
    }
    return blocks;