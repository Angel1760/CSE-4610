//stub for filesys
/* to archive the project: tar -cf angel.tar project
 * will create: angel.tar
 * to execute archive: tar -xf angel.tar
*/
#include "sdisk.h"
#include "filesys.h"
#include "block.h"

#include <sstream>
#include <cstdlib>

using namespace std;

Filesys::Filesys(string filename,int numberofblocks, int blocksize):Sdisk(filename,numberofblocks,blocksize)
{
    rootsize = getblocksize() / 12;
    fatsize = (getnumberofblocks() * 6) / getblocksize() + 1;

    string buffer;
    int code = getblock(1, buffer);
    if(code == 0)
    {
        cout << "error occures" << endl;
        return;
    }

    if(buffer[0] == '#')
    {
        buildfs();
        cout << "Building file system" << endl;
        return;
    }
    else
    {
        readfs();
        return;
    }
}

int Filesys::fsclose()
{
    return 1;
}

int Filesys::buildfs()
{
//from the video 7, 30 min in 
ostringstream ostream;

//building root
for (int i = 0; i < rootsize; i++)
    {
        filename.push_back("XXXXX");
        firstblock.push_back(0);
        ostream << "XXXX" << " " << 0 << ""; //video add
    }
    string buffer = ostream.str();


    //building FAT
    fat.push_back(fatsize +2);
    fat.push_back(-1);
for (int i = 0; i < fatsize; i++)
    {
        fat.push_back(-1);
    }
for (int i = fatsize +2; i < getnumberofblocks(); i++)
    {
        fat.push_back(i + 1);
    }
    fat[fat.size()-1] = 0;
    return fssynch();
}


int Filesys::fssynch()
{

vector<string> block(string buffer, int b);

ostringstream ostream;

for (int i = 0; i < rootsize; i++)
    {
        ostream << filename[1] << firstblock[1] << " ";
    }

    string buffer1 = ostream.str();

    vector<string>blocks1 = block(buffer1, getblocksize());
    putblock(1, blocks1[0]);
   
ostringstream ostream2;
for (int i = 0; i < fat.size(); i++)
    {
        ostream2 << fat[i] << " ";
    }
string buffer2 = ostream2.str();
vector<string>blocks2 = block(buffer2, getblocksize());
for (int i = 0; i < blocks2.size(); i++)
    {
        putblock(2+i, blocks2[i]);
    }
    return 1;

}

int Filesys::readfs(){

string buffer1, buffer2;
getblock(1, buffer1);
string tempbuffer;

for (int i = 0; i < fatsize; i++)
    {
    getblock(2+i, tempbuffer);
    buffer2 += tempbuffer;
    tempbuffer.clear();
    }

    istringstream istream1, istream2;
    istream1.str(buffer1);
    istream2.str(buffer2);

for (int i = 0; i < rootsize; i++)
    {
        string f;
        int n;
        istream1 >> f >> n;
        filename.push_back(f);
        firstblock.push_back(n);
    }
    
    int k;
for(int i = 0; i < getnumberofblocks(); i++)
    {
        istream2 >> k;
        fat.push_back(k);  
    }
    return 0;
}

int Filesys::newfile(string newname){
    for (int i = 0; i < rootsize; i++)
        {
            if (filename[i] == newname)
            {
                cout << "file exists" << endl;
                return 0;
            }
        }
    for (int i = 0; i < rootsize; i++)
    {
        if (filename[i] == "XXXXX")
        {
            filename[i] == newname;
            firstblock[i] == 0;
            return 1;
        }
    }
    cout << "no space in Root" << endl;
    return 0;

}
int Filesys::rmfile(string file){
    return 0;
}

int Filesys::getfirstblock(string file){
//return first block number of file
//-1 if file is not found

    for (int i = 0; i < filename.size(); i++)
    {
        if(filename[i]==file)
        {
            return firstblock[i];
        }
    }
    return -1;
}

int Filesys::addblock(string file, string block){
    int blockid = getfirstblock(file);
    if (blockid == -1)
    {
        cout << "file does not exist" << endl;
        return 0;
    }
    int allocate = fat[0];
    if (allocate == 0)
    {
        cout << "no space on disk" << endl;
        return 0;
    }

    fat[0] = fat[fat[0]]; //allocating the block 
    fat[allocate] = 0;    

    if (blockid == 0)
    {
        for (int i = 0; i < rootsize; i++)
        {
            if (filename[i] == file)        //when there are no blocks in the file
            {
                firstblock[i] = allocate;
            }
            
        }
        
    }
    else   //these will be for the files that already exist
    {
        while (fat[blockid] != 0)
        {
            blockid = fat[blockid]; //
        }
        fat[blockid] = allocate;
    }
    fssynch();      //updating the freelist
    putblock (allocate, block);
    return 1;
}

int Filesys::delblock(string file, int blocknumber)
{
    if(!checkblock(file, blocknumber))
    {
        cout << "Can't do it" << endl;
        return 0;
    }

    int block = getfirstblock(file);
    if(block == blocknumber)
    {
        for(int  i = 0; i < filename.size(); i++)
        {
            if(filename[i] == file)
            {
                firstblock[i] = fat[blocknumber];
                break;
            }
        }
    }
    else
    {
        int b = block;
        while(fat[b] != blocknumber)
        {
            b = fat[b];
        }
        fat[b] == fat[blocknumber];
    }

    fat[blocknumber] = fat[0];
    fat[0] = blocknumber;
    fssynch();

    return 1;
}

int Filesys::readblock(string file, int blocknumber, string& buffer)
{
    if (checkblock(file, blocknumber))
    {
        //can put: "putblock" for writeblock
        getblock(blocknumber, buffer);
        return 1;
    }
    else
    {
        return 0;
    }

}

int Filesys::writeblock(string file, int blocknumber, string buffer)
{
    if(checkblock(file, blocknumber))
    {
        putblock(blocknumber, buffer);
        return 1;
    }
    else
    {
        return 0;
    }
}

int Filesys::nextblock(string file, int blocknumber)
{

    if(checkblock(file, blocknumber))
    {
        return fat[blocknumber];
    }
    else
    {
        return -1;
    }
}

//added from newfile.cpp; i think this is where it should be placed
bool Filesys::checkblock(string file, int block)
{
    //check if block number is in file
    int blockid = getfirstblock(file);
    if(blockid == -1)
    {
        return false;
    }
    while (blockid !=0)
    {
        if(blockid == block)
        {
            return true;
        }
        blockid = fat[blockid];
    }
    return false;
}

//may not need here, may need elsewhere
vector<string> Filesys::ls()
{ vector<string> flist;
  for (int i=0; i<filename.size(); i++)
      {
        if (filename[i] != "XXXXX")
           {
             flist.push_back(filename[i]);
           }
      }
  return flist;
}

/*
vector<string> Filesys::block(string s, int b)
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
    string tempblock;

    for (int i = 0; i < numberofblocks; i++)
    {
    tempblock = s.substr(b*i, b);
    blocks.push_back(tempblock);
    }

    //add #'s to index the number of blocks
    int lastblock = blocks.size() - 1;
    for (int i = blocks[lastblock].length(); i<b; i++)
    {
        blocks[lastblock] += "#";
    }
    return blocks;
}
*/
