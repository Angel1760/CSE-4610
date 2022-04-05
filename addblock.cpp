#include "filesys.h"
#include "sdisk.h"

/*
 1) allocate block: 
 2) update free list 
 3) addblock to the file
    *create multiple: addblock("file1",buffer) throughout
*/

int getfirstblock(file) //go through the root directory; accessor function; if not there, return -1. If exists, return 1

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
