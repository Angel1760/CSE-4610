#include <vector>
#include <string>
#include "shell.h"
#include "filesys.h"
using namespace std;

Shell(string filename, int blocksize, int numberofblocks);

// lists all files
int Shell::dir()


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

//lists the contents of file
int Shell::type(string file)
{

}

//copies file1 to file2
int Shell::copy(string file1, string file2)
{

}