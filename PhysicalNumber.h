#include <exception>
#include <exception>
#include<iostream>
#include<string>
#include "Unit.h"
using namespace std;
namespace ariel {
	class PhysicalNumber {
		double value; //the number value of the phtsical number
		Unit category;


	public:
		PhysicalNumber(double x, Unit cat); //contractor from a number value and a Unit value
		PhysicalNumber operator + (PhysicalNumber &b); //function of '+' operator between 2 Phsical numbers
		PhysicalNumber &operator += (PhysicalNumber &b); //add Physical number to another
		friend PhysicalNumber operator - (PhysicalNumber &b); // sub '-' operator function between two Physical numbers
		PhysicalNumber &operator -= (PhysicalNumber &b); // sub Pysical number from another
		PhysicalNumber &operator = (PhysicalNumber &b); // the operator '=' function
		bool &operator >= (PhysicalNumber &b); //bool function of operator '>='
		bool &operator > (PhysicalNumber &b); //boole function of operator '>'
		bool &operator <= (PhysicalNumber &b); //bool function of operator '<='
		bool &operator < (PhysicalNumber &b); //bool function of operator '<'
		bool &operator == (PhysicalNumber &b); //bool function of operator '=='
		PhysicalNumber &operator ++ (); //the function of operator '++' that add 1 to Physical number
		PhysicalNumber &operator -- (); //the function of operator '--' that sub 1 from Physical number
		friend istream &operator << (istream &input, PhysicalNumber &phy); //a istream operator '<<' function to get an input to a Physical number
		friend ostream &operator <<(ostream &out, PhysicalNumber &phy); //a ostream operator '>>' function to get an output from a Physical number
	};
}