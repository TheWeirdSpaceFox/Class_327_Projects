/*
 * Smalltalk_American.cpp
 *
 *  Created on: Nov 30, 2023
 *      Author: amanda
 */
#include "./includes/Smalltalk_American.h"
#include "./includes/constants.h"
#include "./includes/Watch.h"
#include "./includes/Smalltalk.h"

using namespace std;
//this constructor should call the 2 parameter constructor below in it's initializer list
Smalltalk_American::Smalltalk_American(int iPerson)
	:Smalltalk_American(AMERICAN, iPerson){
	Smalltalk_American::populatePhrases();
	}

	//use base class constructor in initializer list to set Nationality and iPerson (See constants for Nationality strings)
	//also prepare the object for use by calling populatePhrases()
	Smalltalk_American::Smalltalk_American(std::string myNationality,int iPerson) :
			Smalltalk(myNationality, iPerson){
			Smalltalk_American::populatePhrases();
	}

	Smalltalk_American::~Smalltalk_American(void){

	}

	void Smalltalk_American::populatePhrases(){
		mySmallTalk.push_back(AMERICAN_PHRASE_1);
		mySmallTalk.push_back(AMERICAN_PHRASE_2);
		mySmallTalk.push_back(AMERICAN_PHRASE_3);
		mySmallTalk.push_back(AMERICAN_PHRASE_4);
		mySmallTalk.push_back(AMERICAN_PHRASE_5);
	}





