#include "sdisk.h"


Sdisk::Sdisk(string diskname, int numberofblocks, int blocksize)
{
	
    this->diskname = diskname;
    this->numberofblocks = numberofblocks;
    this->blocksize = blocksize;

	fstream iofile;
	iofile.open(diskname.c_str(), ios::in);
	//check if file exists 
	if(iofile.good())
	{
		iofile.close();
		return;
	}
	else 
	{
		iofile.close();
		ofstream outfile;
		outfile.open(diskname.c_str());
		for(int i=0; i<numberofblocks*blocksize; i++)
		{
			outfile.put('#');
		}
		//close file
		outfile.close();
		return;
	}

}

int Sdisk::getnumberofblocks()
{
	return this->numberofblocks;
}

//block size of bytes 
int Sdisk::getblocksize()
{
	return this->blocksize;
}

/*retrieves block blocknumber from the disk and stores the data in the string buffer. 
It returns an error code of 1 if successful and 0 otherwise.*/
int Sdisk::getblock(int blocknumber, string& buffer)
{
	
	if (blocknumber > (numberofblocks -1))
	{
		return 0;
	}
	
	ifstream input; 
	char temp;

	input.open(diskname.c_str());
		
	if(!input.is_open())
	{
		return 0;
	}

	input.seekg(blocknumber * blocksize);
	for(int i = 0; i < blocksize; ++i)
	{
		input.get(temp);
		buffer.push_back(temp);
	}

	input.close();
	return 1;
}

//writes the string buffer to block blocknumber. It returns an error code of 1 if successful and 0 otherwise.
int Sdisk::putblock(int blocknumber, string buffer)
{
	
if (blocknumber > (numberofblocks -1))
	{
		return 0;
	}
	fstream output; 
	output.open(diskname.c_str(), ios::in | ios::out);
		
	if(!output.is_open())
	{
		return 0;
	}

	output.seekp(blocknumber * blocksize);

	for(int i = 0; i < buffer.length(); ++i)
	{
		output.put(buffer[i]);
	}

	output.close();
	return 1;
}