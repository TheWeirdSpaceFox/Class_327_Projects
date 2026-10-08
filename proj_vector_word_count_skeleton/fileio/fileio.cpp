#include "../includes/fileio.h"
#include <iostream>
/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*
  returns True - file opened successfully
          False - file not opened*/
bool openFile(std::fstream& myfile, const std::string& myFileName,std::ios_base::openmode mode){
	if(!myfile.is_open()){
		myfile.open(myFileName);
		if(myfile.is_open()) {
			return true;
		}
	}
	return false;
}
/*iff myfile is open then close it*/
void closeFile(std::fstream& myfile){
	if(myfile.is_open()){
		myfile.close();
	}
}

/* serializes all content in entries to file outputfilename
 * check out utils for helpful type conversion functions
 * BTW serialize means the process of translating a data structure
 * into a format that can be stored in a file
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in the vector entries
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writetoFile(std::vector<constants::entry>  &entries, const std::string &outputfilename){
		std::ofstream myfile;
		myfile.open(outputfilename.c_str(), std::ios::out);
		if(!myfile.is_open()){
			return constants::FAIL_FILE_DID_NOT_OPEN;
		}
		if(entries.empty()){
			return constants::FAIL_NO_ARRAY_DATA;
		}
		std::string line;
		for(unsigned int i = 0;i<entries.size();i++){
			myfile << entries.at(i).word << " " << entries.at(i).number_occurences << std::endl;
		}
		return constants::SUCCESS;
}
