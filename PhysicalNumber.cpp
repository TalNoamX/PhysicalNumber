#include "PhysicalNumber.h"

using namespace std;
using ariel::Unit;
using ariel::PhysicalNumber;

ariel::PhysicalNumber::PhysicalNumber(double val, Unit cat)
{
	this->value = val;
	this->category = cat;
}
PhysicalNumber &operator + (PhysicalNumber &b)
{
	return b;
}
PhysicalNumber &operator += (PhysicalNumber &b)
{
	return b;
}
PhysicalNumber &operator - (PhysicalNumber &b)
{
	return b;
}
PhysicalNumber &operator -= (PhysicalNumber &b)
{
	return b;
}
PhysicalNumber &operator = (PhysicalNumber &b)
{
	return b;
}
bool &operator >= (PhysicalNumber &b)
{
	return true;
}
bool &operator > (PhysicalNumber &b)
{
	return true;
}
bool &operator <= (PhysicalNumber &b)
{
	return true;
}
bool &operator < (PhysicalNumber &b)
{
	return true;
}
bool &operator == (PhysicalNumber &b)
{
	return true;
}
PhysicalNumber &operator ++ ()
{
	return this;
}
PhysicalNumber &operator -- ()
{
	return this;
}
friend istream &operator << (istream &input, PhysicalNumber &phy);
friend ostream &operator <<(ostream &out, PhysicalNumber &phy);
