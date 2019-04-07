#include "PhysicalNumber.h"
#include "Unit.h"

using namespace std;
using ariel::Unit;
using ariel::PhysicalNumber;

PhysicalNumber::PhysicalNumber(const double val, const Unit cat)
{
	this->value = val;
	this->category = cat;
}

PhysicalNumber::PhysicalNumber(const PhysicalNumber & copy)
{
	this->category = copy.category;
	this->value = copy.value;
}

 const PhysicalNumber ariel::PhysicalNumber::operator+(const PhysicalNumber & b) const
 {
	 double num = 3.3;
	return PhysicalNumber(num, this->category);
}

 const PhysicalNumber ariel::PhysicalNumber::operator-(const PhysicalNumber & b) const
{
	 double num = 3.3;
	 return PhysicalNumber(num, this->category);
}

 const PhysicalNumber ariel::PhysicalNumber::operator-() const
{
	 double num = 3.3;
	 return PhysicalNumber(num, this->category);
}

 const PhysicalNumber ariel::PhysicalNumber::operator+() const
{
	 double num = 3.3;
	 return PhysicalNumber(num, this->category);
}

PhysicalNumber & ariel::PhysicalNumber::operator=(const PhysicalNumber & b)
{
	return *this;
}

PhysicalNumber & ariel::PhysicalNumber::operator+=(const PhysicalNumber & b)
{
	return *this;
}

PhysicalNumber & ariel::PhysicalNumber::operator-=(const PhysicalNumber & b)
{
	return *this;
}

bool ariel::PhysicalNumber::operator>=(const PhysicalNumber & b) const
{
	return false;
}

bool ariel::PhysicalNumber::operator>(const PhysicalNumber & b) const
{
	return false;
}

bool ariel::PhysicalNumber::operator<=(const PhysicalNumber & b) const
{
	return false;
}

bool ariel::PhysicalNumber::operator<(const PhysicalNumber & b) const
{
	return false;
}

bool ariel::PhysicalNumber::operator==(const PhysicalNumber & b) const
{
	return false;
}

bool ariel::PhysicalNumber::operator!=(const PhysicalNumber & b) const
{
	return false;
}

 PhysicalNumber & ariel::PhysicalNumber::operator++()
{
	return *this;
}

 PhysicalNumber ariel::PhysicalNumber::operator++(int  n)
{
	return *this;
}

 PhysicalNumber & ariel::PhysicalNumber::operator--()
{
	return *this;
}

 PhysicalNumber ariel::PhysicalNumber::operator--(int n)
{
	return *this;
}

istream & ariel::operator>>(istream & input,  PhysicalNumber & phy)
{
	return input;
}

ostream & ariel::operator<<(ostream & out,const PhysicalNumber & phy)
{
	return (out<<phy.value<<"["<<phy.category<<"]");
}
