#include <string>
#include <vector>

#include "block.h"
#include "filesys.h"


using namespace std;

vector<string> block(string buffer, int b)
{
// blocks the buffer into a list of blocks of size b

vector<string> blocks;
int numberofblocks=0;

if (buffer.length() % b == 0) 
   { 
     numberofblocks= buffer.length()/b;
   }
else 
   {
      numberofblocks= buffer.length()/b +1;
   }

string tempblock;
for (int i=0; i<numberofblocks; i++)
    { 
      tempblock=buffer.substr(b*i,b);
      blocks.push_back(tempblock);
    }

int lastblock=blocks.size()-1;

for (int i=blocks[lastblock].length(); i<b; i++)
    { 
      blocks[lastblock]+="#";
    }

  return blocks;
}
/*
stringstream ostream;

for (int i = 0; i < rootsize; i++)
    {
        ostream << filename[1] << " " << firstblock[1] << " ";
    }

    string buffer = ostream.str();

    vector<string>blocks = block(buffer, getblocksize());
    putblock(1, blocks[0]);
}
*/

