#include "shell.h"
#include "filesys.h"
#include "block.h"


using namespace std;

Shell::Shell(string filename, int blocksize, int numberofblocks):Filesys(filename, numberofblocks, blocksize)
{
    cout << "Shell was created!" << endl;
}

// lists all files
int Shell::dir()
{ 
    vector<string> flist = ls();
  for (int i=0; i < flist.size(); i++)
      {
        cout << flist[i] << endl;
      }
      return 1;
}

// add a new file using buffer as data
int Shell::add(string file,string buffer)
{
    int code = getfirstblock(file);
    if (code >= 0)
    {
        cout << "file exists";
        return 0;
    }
    code = newfile(file);

    if (code == 0)
    {
        cout << "Failed";
        return 0;
    }
    
    //from the block program
    vector<string>blocks = block(buffer, getblocksize());
    for (int i = 0; i < blocks.size(); i++)
    {
        code = addblock(file, blocks[i]);
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
    return 1;
}


//lists the contents of file; this code is similar to the copy function
//seems to be working fine
int Shell::type(string file1, string file2)
{
    
    int block = getfirstblock(file1);
    string buffer;
    int code = newfile(file2);

    while(block > 0){
      string t;
      int error = readblock(file1, block, t);
      buffer += t;
      block = nextblock(file1, block);
    }
    cout << buffer << endl;
    cout << buffer.length() << endl;


    while (block != 0)
    {
        string buffer;
        readblock(file1, block, buffer);
        addblock(file2, buffer);
        block = nextblock(file1, block);
    }
    return 1;

}


//copies file1 to file2
int Shell::copy(string file1, string file2)
{
/*
    int block = getfirstblock(file1);
    int code = newfile(file2);
    string buffer;

/*need to check if this is correct
    //checking if file exists! block -1. then there is no file
    if (block == -1)
    {
        cout << "there is no file";
        return 0;
    }
    //check if file2 already exists or no more room for file (code = 0)
    //double chech return statements for this if and if above
    if (code == 0)
    {
        cout << "file2 already exists";
        return 1;
    }
*/
    int block = getfirstblock(file1);
    int error = newfile(file2);
    string buffer;

    while(block > 0){
      string t;
      error = readblock(file1, block, t);
      buffer += t;
      addblock(file2, buffer);
      block = nextblock(file1, block);
    }
    return 1;
}

/* pertains to the part above
    while (block != 0)
    {
        string buffer;
        readblock(file1, block, buffer);
        addblock(file2, buffer);
        block = nextblock(file1, block);
    }
    return 1;
}
*/
/*
4/7/22
need to:
    check the if statements are correct for both the type and copy function where stated
    check if type code is correct.
*/

//clear the filename vector after you delete the file in filesystem