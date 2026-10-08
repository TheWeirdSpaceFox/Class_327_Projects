/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	fstream my_file;
	my_file.open(filename.c_str());

	if (my_file.is_open()){
		string line;
		//might not remove n's
		while(!my_file.eof()){
			getline(my_file, line);
			contents += line;
		}
		my_file.close();
		return SUCCESS;
		}
		else{
			return COULD_NOT_OPEN_FILE_TO_READ;
		}

}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	fstream my_file;
	my_file.open(filename.c_str(), ios_base::out);
	if (my_file.is_open()){
		for (int start = 0; start < myEntryVector.size();start++){
		my_file<<myEntryVector[start]<<endl;
		}
		my_file.close();
	return SUCCESS;
	}
	else{
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}
}


