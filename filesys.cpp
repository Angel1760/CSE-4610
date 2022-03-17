//stub for filesys
/* to archive the project: tar -cf angel.tar project
 * will create: angel.tar
 * to execute archive: tar -xf angel.tar
*/
#include "filesys.h"
#include "sdisk.h"


Filesys::Filesys(string filename,int numberofblocks, int blocksize):
    
Sdisk(diskname,numberofblocks,blocksize){
    string buffer;
    int code = getblock(1, buffer);
    rootsize = getblocksize() / 12;
    fatsize = getnumberofblocks() * 6 / getblocksize() +1;
    //not sure to use the first if statement
    if (code == 0)
        {
            cout << "Error occured";
            return;
        }
    if(buffer[0]=="#")
        {
            buildfs();
            cout << "Building file system"; 
        }
    else
    {
        readfs();
        return;
    }

}

int Filesys::buildfs(){
//building root
for (int i = 0; i < rootsize; i++)
    {
        filename.push_back("XXXXX");
        firstblock.push_back(0);
    }
    //building FAT
    fat.push_back(fatsize +2);
    fat.push_back(-1);
for (int i = 0; i < getnumberofblocks; i++)
    {
        fat.push_back(-1);
    }
for (i = fatsize +2; i < numberofblocks; i++)
    {
        fat.push_back(i+1);
    }
    fat[fat.size()-1] = 0;
    return fssynch();
}

int Filesys::fssynch(){
ostringstream ostream1;

for (int i = 0; i < rootsize; i++)
    {
        ostream1 << filename[1] << firstblock[1] << " ";
    }
    string buffer1 = ostream.str();
    vector<string>blocks1 = block(buffer1; getblocksize());
    putblock(1,block[0]);
   
ostream ostream2;
for (int i = 0; i < fat.size(); i++)
    {
        ostream2 << fat[i] << " ";
    }
    string buffer2 = ostream2.str();
    vector<string>blocks2 = block(buffer2, getblocksize());

for (int i = 0; i < block2.size(); i++)
    {
        putblock(2+i, block2[i]);
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
        istream1 << f << n;
        filename.push_back(f);
        firstblock.push_back(n);
    }
    
    int k;
for (int i = 0; i < getnumberofblocks(); i++)
    {
        istream2 << k;
        fat.push_back(k);  
    }
    
}

int Filesys::fsclose(){

}

int Filesys::newfile(string file){

}

int Filesys::rmfile(string file){

}

int Filesys::getfirstblock(string file){
//return first block number of file
//-1 if file is not found

    for (int i = 0; i < rootsize filename.size(); i++)
    {
        if(filename[i]==file)
        {
            return firstblock[i];
        }
    }
    return -1;
    
}

int Filesys::addblock(string file, string block){

}

int Filesys::delblock(string file, int blocknumber){

}

int Filesys::readblock(string file, int blocknumber, string& buffer){

}

int Filesys::writeblock(string file, int blocknumber, string buffer){

}

int Filesys::nextblock(string file, int blocknumber){

}


