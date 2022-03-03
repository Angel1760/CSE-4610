//to compile: c++ -c sdisk.cpp main.cpp
//c++ -o project1 main.o
#include "sdisk.h"
#include 
#ifndef SDISK_H
#def

/*
This constructor incorporates the creation of the disk with the "formatting" of the device.
*/
Sdisk::Sdisk(string diskname, int numberofblocks, int blocksize)
{
	fstream f;
	ifstream file1;

	this->diskname = diskname;
	this->numberofblocks = numberofblocks;
	this->blocksize = blocksize;

	//might break the project later on for part 3, 4

/*
	f.open("diskname", ios::in | ios::out);
	if (!f)
	{
		cout << "Error opening file" << endl;
		exit(0);
	}
*/
	//looking for a c_string
	file1.open(diskname.c_str());
	bool diskStatus = file1.good(); file1.close();
	if(diskStatus == true){
		return;
	}
	else{
		ofstream file2;
		file2.open(diskname.c_str());
		for(int i = 0; i < numberofblocks * blocksize; i++)
		{
			file2.put('#');
		}

		file2.close();
	}
		//create diskname;
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
	fstream iofile;
	iofile.open(diskname.c_str(), ios::in | ios::out);
	buffer.clear();

	if(blocknumber >= 0 && blocknumber < blocksize * numberofblocks)
	{
		
		if (!iofile.is_open())
		{
			cout << "Could not get Block" << endl;
			return 0;
		}
		
		char c;
		iofile.seekg(blocknumber * blocksize);

		for (int i = 0; i < blocksize; i++)
		{
			iofile.get(c);
			buffer.push_back(c); 
		}

		cout << "Successfully accessed the file" << endl;
		return 1;
	}
	else
	{
		cout << "Blocknumber is 0 or blocknumber is less than blocksize * number of blocks" << endl;
		return 0;
	}
}

//writes the string buffer to block blocknumber. It returns an error code of 1 if successful and 0 otherwise.
int Sdisk::putblock(int blocknumber, string buffer)
{
	fstream iofile;
	iofile.open(diskname.c_str(), ios::in | ios::out); //binary final part of project
	buffer.clear();

	if(blocknumber >= 0 && blocknumber < blocksize * numberofblocks)
	{
		iofile.seekp(blocknumber * blocksize);

		for (int i = 0; i < blocksize; i++)
		{
			iofile.put(buffer[i]);
		}

		cout << "Successfully accessed the file" << endl;
		return 1;
	}
	else
	{
		cout << "Blocknumber is 0 or blocknumber is less than blocksize * number of blocks" << endl;
		return 0;
	}
	#endif
}