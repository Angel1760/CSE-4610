#include "filesys.h"

using namespace std;


class Table: public Filesys
{

public:

Table(string diskname,int blocksize,int numberofblocks, string flatfile, string indexfile);
int Build_Table(string input_file);
int Search(string value);

private :
string flatfile;
string indexfile;
int IndexSearch(string value);

};