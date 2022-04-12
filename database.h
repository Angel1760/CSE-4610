#include "filesys.h"

using namespace std;


class Table: public Filesys
{

public:

Table(string diskname,int blocksize,int numberofblocks, string flatfile, string indexfile);
int Build_Table(string input_file);
int Search(string value);

private :

string flatfile;                 //stores information without any particular order
string indexfile;                //created for search keys; for faster search
int numberofrecords;
FileSys filesystem;
int IndexSearch(string value);

};