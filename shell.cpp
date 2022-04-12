#include "shell.h"
#include "filesys.h"
using namespace std;

Shell(string filename, int blocksize, int numberofblocks);

// lists all files
int Shell::dir()
{ 
    vector<string> flist=ls();
  for (i=0; i<flist.size(); i++)
      {
        cout << flist[i] << endl;
      }
}

// add a new file using buffer as data
int Shell::add(string filename,string buffer)
{
    int code = getfirstblock(file);
    if (code >= 0)
    {
        cout << "file exists";
        return 0;
    }
    code = newfile(filename);

    if (code == 0)
    {
        cout << "Failed";
        return 0;
    }
    
    vector<string>blocks = block(buffer, getblocksize());
    for (int i = 0; i < block.size(); i++)
    {
        code = addblock(filename, blocks[i]);
        if (code == 0)
        {
            cout << "error occurred";
            return 0;
        }
        
    }
    return 1;
    
}

// deletes the file
int Shell::del(string file)
{
    //delete all blocks
    int block = getfirstblock(file);
    while (block != 0)                     //this will delete the blocks on the list until all the blocks are deleted
    {
        int code = delblock(file, block);
        block = getfirstblock(file);

    }
    rmfile(file);
    
}

//lists the contents of file; this code is similar to the copy function
int Shell::type(string file)
{
  int block = getfirstblock(file1);
    //checking if file exists! block -1. then there is no file
    if (block == -1)
    {
        cout << "there is no file";
        return 0;
    }
    
    //might need to add readblock(file1, file2) here
    int code = readblock(file1, file2);

    //check if file2 already exists or no more room for file (code = 0)
    //double check return statements for this if and if above
    if (code == 0)
    {
        cout << "file2 already exists";
        return 1;
    }

    while (block != 0)
    {
        string buffer;
        readblock(file1, file2);
        addblock(file2, buffer);
        block = nextblock(file1, block);
    }
    return 1;

}

//copies file1 to file2
int Shell::copy(string file1, string file2)
{
    int block = getfirstblock(file1);
    //checking if file exists! block -1. then there is no file
    if (block == -1)
    {
        cout << "there is no file";
        return 0;
    }
    
    int code = newfile(file2);
    //check if file2 already exists or no more room for file (code = 0)
    //double chech return statements for this if and if above
    if (code == 0)
    {
        cout << "file2 already exists";
        return 1;
    }
    while (block != 0)
    {
        string buffer;
        readblock(file1, file2);
        addblock(file2, buffer);
        block = nextblock(file1, block);
    }
    return 1;

}
/*
4/7/22
need to:
    check the if statements are correct for both the type and copy function where stated
    check if type code is correct.
*/
