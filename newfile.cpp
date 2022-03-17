#include "filesys.h"
#include "sdisk.h"



int Filesys::newfile(string newname){
    for (int i = 0; i < rootsize; i++)
        {
            if (filename[i]==newname)
            {
                cout << "file exists" << endl;
                return 0;
            }
        }
    for (int i = 0; i < rootsize; i++)
    {
        if (filename == "XXXXX")
        {
            filename == newname;
            return 1;
        }
        
    }
    cout << "no space in Root" << endl;
    return 0;

}

//needs to be placed somewhere
bool Filesys::checkblock(string file, int block){
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
    
}
