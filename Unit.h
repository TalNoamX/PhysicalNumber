#ifndef Unit_h
#define Unit_h

#include <iostream>
using std::string;
namespace ariel {

	enum  Unit {
		//every unit get the same quivalence relation mod 3.
		/*
		this part represent distance units
		*/
		CM = 0,
		M = 3,
		KM = 6,

		/*
		this part represent time units
		*/
		SEC = 1,
		MIN = 4,
		HOUR = 7,

		/*
		this part represent weight units
		*/
		G = 2,
		KG = 5,
		TON = 8

	};

}
#endif