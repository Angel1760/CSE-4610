//stub for filesys
/* to archive the project: tar -cf angel.tar project
 * will create: angel.tar
 * to execute archive: tar -xf angel.tar
*/

#include "filesys.h"

int Filesys::Filesys(string filename,int numberofblocks, int blocksize){

}

int Filesys::fsclose(){

}

int Filesys::newfile(string file){

}

int Filesys::rmfile(string file){

}

int Filesys::getfirstblock(string file){

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


