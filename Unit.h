#ifndef Unit_h
#define Unit_h

#include <iostream>
using std::string;
namespace ariel {

	const double conversion[9] = { 1, 1, 1, 100, 60, 1000, 100000, 3600, 1000000 };
	const string type[9] = { "cm","sec","g","m","min","kg","km","hour","ton" };

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