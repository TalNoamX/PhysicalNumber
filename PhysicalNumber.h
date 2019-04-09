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
		bool sameType(const PhysicalNumber &b)const;


	public:
		PhysicalNumber(const double x, const Unit cat); //contractor from a number value and a Unit value
		PhysicalNumber(const PhysicalNumber &copy); //contractor from a number value and a Unit value

		const PhysicalNumber operator + (const PhysicalNumber &b)const; //function of '+' operator between 2 Phsical numbers
		const PhysicalNumber operator - (const PhysicalNumber &b)const;// sub '-' operator function between two Physical numbers
		const PhysicalNumber operator - ()const;
		const PhysicalNumber operator + ()const;

		PhysicalNumber& operator = (const PhysicalNumber &b); // the operator '=' function
		PhysicalNumber& operator += (const PhysicalNumber &b); //add Physical number to another
		PhysicalNumber& operator -= (const PhysicalNumber &b); // sub Pysical number from another

		bool operator >= (const PhysicalNumber &b)const; //bool function of operator '>='
		bool operator > (const PhysicalNumber &b)const; //boole function of operator '>'
		bool operator <= (const PhysicalNumber &b)const; //bool function of operator '<='
		bool operator < (const PhysicalNumber &b)const; //bool function of operator '<'
		bool operator == (const PhysicalNumber &b)const; //bool function of operator '=='
		bool operator != (const PhysicalNumber &b)const; //bool function of operator '!='

		PhysicalNumber &operator ++ (); //the function of operator '++' that add 1 to Physical number
		PhysicalNumber operator ++ (int n);
		PhysicalNumber &operator -- (); //the function of operator '--' that sub 1 from Physical number
		PhysicalNumber operator -- (int n);

		friend istream &operator >> (istream &input, PhysicalNumber &phy); //a istream operator '>>' function to get an input to a Physical number
		friend ostream &operator <<(ostream &out, const PhysicalNumber &phy); //a ostream operator '<<' function to get an output from a Physical number
	};
	istream &operator >> (istream &input, PhysicalNumber &phy);
	ostream &operator <<(ostream &out, const PhysicalNumber &phy);
}