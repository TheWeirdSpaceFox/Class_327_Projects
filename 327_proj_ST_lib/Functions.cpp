//
/*
 * Functions.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: keith
 */
#include <iostream>
#include <memory>

#include "./includes/Functions.h"
#include "./includes/Smalltalk_American.h"
#include "./includes/ST_American_DonutEnthusiest.h"
#include "./includes/Smalltalk_Brit.h"
#include "./includes/Smalltalk.h"
#include "./includes/Watch.h"
#include "./includes/constants.h"
using namespace std;
//create a vector with appropriate numbers of Smalltalk_Brit,Smalltalk_American and ST_American_DonutEnthusiest
//objects using unique pointers.  Since we are using c++11 returning this vector by value is fine since the 
//compiler will move the vector on return rather than recreate it (this means there is no copy penalty)
std::vector<std::unique_ptr<Smalltalk>> getPeople(int numBrit,
		int numAmerican, int numbAmericanDonutEnthusiest,
		int numWatches) {
	
	//create a vector to hold SmallTalk unique pointers
	vector<std::unique_ptr<Smalltalk>> pointers;
			//add brits to vector

		//add brits to vector
	for(int i =0; i < numBrit; i++){
		pointers.push_back(unique_ptr<Smalltalk_Brit>(new Smalltalk_Brit(i)));
	}
	int total = numAmerican+numBrit;
		//add americans  to vector
	for(int i = numBrit; i < total; i++){
		pointers.push_back(unique_ptr<Smalltalk_American>(new Smalltalk_American(i)));
	}

		//add american donut enthusiest  to vector
	for(int i = total; i < numbAmericanDonutEnthusiest+total; i++){
		pointers.push_back(unique_ptr<ST_American_DonutEnthusiest>(new ST_American_DonutEnthusiest(i)));
	}

		//create some watches (as long as number watches <= numb people)
		//then give the watches away to first NUM_WATCHES people in the vector
		// when you are finished using the vector you return
		//from this function(see Smalltalk header for hints)
	 total += numbAmericanDonutEnthusiest;
	 vector<unique_ptr<Watch>> watches;
	 if(numWatches > total){
		 numWatches = total;
	 }
	 for(int i=0; i < numWatches; i++){
		 watches.push_back(unique_ptr<Watch>(new Watch()));
	 }
	 for(int i=0; i < numWatches; i++){
		 pointers[i]->Smalltalk::giveWatch(watches[i]);
	 }
//	 if(numWatches <= numpeople){
//		 for(int i = 0; i <= numpeople; i++){
//			 unique_ptr<Watch> watch;
//	        	pointers[i]->giveWatch(watch);
//	     }

		//return your vector
	 return pointers;
}
