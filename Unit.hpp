#include <iostream>
using std::string;
namespace ariel {

	enum Unit : char {
		//length units
		CM, M, KM, //CM = 0,M = 1, KM = 2

		//time unis
		SEC, MIN, HOUR, // SEC = 3, MIN = 4, HOUER = 5

	// mass units
	G, KG, TON // G = 6, KG = 7, TON = 8

	};
}