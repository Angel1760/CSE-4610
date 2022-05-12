#include "table.h"
#include "filesys.h"
#include "block.h"
#include <sstream>
#include <cstdlib>
using namespace std;

Table::Table(string diskname, int numberofblocks, int blocksize, string flatfile, string indexfile):Filesys(diskname, numberofblocks, blocksize)
{
    this->flatfile = flatfile;
    this->indexfile = indexfile;
}

int Table::build_table(string input_file)
{
int code = newfile(indexfile);
code = newfile(flatfile);

  ostringstream ostream;  // create indexfile
  ifstream infile;
  infile.open(input_file.c_str());
  string inputline;
  getline(infile, inputline);

  while(infile.good()){
    string key = inputline.substr(0, 5);  // grabs first 5 char
    string rest = inputline.substr(5);  // grabs rest of the line

    vector<string> blocks = block(inputline, getblocksize());
    int blockid = addblock(flatfile, blocks[0]);
    ostream << key << " " << blockid << " ";
    getline(infile, inputline);
  }
  ostream << "XXXXX" << " " << 0 << " ";
  string buffer = ostream.str();
  vector<string> iblocks = block(buffer, getblocksize());

  // create indexfile
  for(int i = 0; i < iblocks.size(); i++){
    addblock(indexfile, iblocks[i]);
  }
return 0;
}

int Table::indexSearch(string value)
{
  istringstream instream;
  int b = getfirstblock(indexfile);
  string bigBuffer;
  while(b != 0){
     string buffer; 
       int error = readblock(indexfile, b, buffer);
       bigBuffer += buffer;
       b = nextblock(indexfile, b);
      }

    instream.str(bigBuffer);
    
    string k;
    int f;
    instream >> k >> f;
    while(k != "XXXXX")
    {
        if(k == value)
        {
    
            return f;
        }

        instream >> k >> f; 

  }
return 0;
    
}

int Table::search(string value)
{
  int ecode = indexSearch(value);
  if(ecode == 0)
  {
       cout << "record not found" << endl;
       return 0;
  }
  else
  {
        string buffer;
        ecode = readblock(flatfile, ecode, buffer);
        cout << buffer << endl;
        return 1;
   }
}