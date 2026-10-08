#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../includes/fileio.h"
using namespace std;
//attempt to open file 'filename' and read in all data
//returns SUCCESS if all goes well or COULD_NOT_OPEN_FILE
int load(const std::string filename, std::vector<process> &myProcesses){
	ifstream File;
	File.open(filename);
	if (!File.is_open()){
		return COULD_NOT_OPEN_FILE;
	}
	File.close();
	return SUCCESS;
}

//attempt to create or open file 'filename' to write all data to
//returns SUCCESS if all goes well or COULD_NOT_OPEN_FILE
int save(const std::string filename, std::vector<process> &myProcesses){
	ofstream File;
	File.open(filename);
	if(!File.is_open()){
		return COULD_NOT_OPEN_FILE;
	}
	File.close();
	return SUCCESS;
}
