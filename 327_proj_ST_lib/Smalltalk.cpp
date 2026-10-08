/*
 * Smalltalk.cpp
 *
 *  Created on: Nov 30, 2023
 *      Author: amanda
 */
#include <string>
#include <memory>
#include "./includes/Smalltalk.h"
#include "./includes/Watch.h"
#include "./includes/constants.h"
using namespace std;
	//derived class will set Nationality, iPerson. iPerson is just a counter used to distinguish between objects of the same type
    Smalltalk::Smalltalk(std::string myNationality,int iPerson){
//		this->nationality = myNationality;
		this->iPerson = iPerson;
		this->current_phrase = 0;
		pWatch = 0;
	}

		Smalltalk::~Smalltalk(void){
//		delete nationality;
//		delete iPerson;
			pWatch.reset();
	}

	//cycles through phrases added in populatePhrases. Returns them 1 by 1 starting with the first and ending
	//with the last and then it starts over
	//takes the form Nationality iPerson: phrase
	//for instance the following string comes from an American instance, the 10th iPerson and it is printing AMERICAN_PHRASE_2
	//AMERICAN 10:Why yes, I would like to supersize that
	string Smalltalk::saySomething(){
		int phrasenum = current_phrase % mySmallTalk.size();
		string phrase = nationality + " " + to_string(iPerson) + " " + mySmallTalk[phrasenum];
		current_phrase++;
		return phrase;
//	for(int i = 0; i < mySmallTalk.size(); i++){
//		return this->nationality, this->iPerson, mySmallTalk[i];
//		}
	}

	//returns the time (if pWatch contains a watch ) in the form of THE_CURRENT_TIME_IS: (from the actual watch object itself) and then the time
	//or I_DO_NOT_HAVE_A_WATCH string (if pWatch does not contain a watch)
	std::string Smalltalk::getTime(){
		if(pWatch == 0){
			return I_DO_NOT_HAVE_A_WATCH;
		}
		else{
			return THE_CURRENT_TIME_IS + pWatch->getTime();/////how to call function +++++++++++
		}
	}

	//if this object has a watch it is taken away, otherwise an empty unique_ptr is returned
	// This transaction simulates giving away a watch
	std::unique_ptr<Watch>  Smalltalk::takeWatch(){
		if (pWatch != 0){
			pWatch = 0;
			unique_ptr<Watch> x;
			x= move(pWatch);
			return x;
		}
		else{
			return unique_ptr<Watch>();
		}
	}

	//if pWatch is NULL return false
	//if already have a watch then return false and dont change pWatch pointer
	//otherwise accept watch and use std::move to move watch
	//from pWatch to this->pWatch and return true
	bool Smalltalk::giveWatch(std::unique_ptr<Watch> &pWatch){
		if(this->pWatch != 0){
			return false;
		}
		this->pWatch = move(pWatch);
		return true;
//		if (pWatch == NULL){
//			return false;
//		}
//		if(pWatch == 0){
//			return false;
//		}
//		else{
//			std::unique_ptr<Watch> newwatch;
//			newwatch = move(pWatch);
//		}

	}

	//Abstract Base Class (ABC), implement in derived classes
	void Smalltalk::populatePhrases(){}





