#include "PhysicalNumber.h"
#include "Unit.h"

using namespace std;
using ariel::Unit;
using ariel::PhysicalNumber;

bool ariel::PhysicalNumber::sameType(const PhysicalNumber & b) const
{
	if (this->category % 3 == b.category % 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

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
	 if (sameType(b))
	 {
		 double num = b.value*(conversion[b.category] / conversion[this->category]);
		 num = num + this->value;

		 return PhysicalNumber(num, this->category);
	 }
	 else
	 {
		 throw invalid_argument("invalid action: can not add diffrent physical unit");
	 }
}

 const PhysicalNumber ariel::PhysicalNumber::operator-(const PhysicalNumber & b) const
{
	 if (sameType(b))
	 {
		 double num = b.value*(conversion[b.category] / conversion[this->category]);
		 num = this->value - num;
		 return PhysicalNumber(this->value - (b.value*(conversion[b.category] / conversion[this->category])), this->category);
	 }
	 else
	 {
		 throw invalid_argument("invalid action: can not subtract diffrent physical unit");
	 }
}

 const PhysicalNumber ariel::PhysicalNumber::operator-() const
{
	 return PhysicalNumber(-this->value, this->category);
}

 const PhysicalNumber ariel::PhysicalNumber::operator+() const
{
	 return PhysicalNumber(+this->value, this->category);
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
	if (sameType(b))
	{
		if (this->value >= b.value*(conversion[b.category] / conversion[this->category]))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool ariel::PhysicalNumber::operator>(const PhysicalNumber & b) const
{
	if (sameType(b))
	{
		if (this->value > b.value*(conversion[b.category] / conversion[this->category]))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool ariel::PhysicalNumber::operator<=(const PhysicalNumber & b) const
{
	if (sameType(b))
	{
		if (this->value <= b.value*(conversion[b.category] / conversion[this->category]))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool ariel::PhysicalNumber::operator<(const PhysicalNumber & b) const
{
	if (sameType(b))
	{
		if (this->value < b.value*(conversion[b.category] / conversion[this->category]))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool ariel::PhysicalNumber::operator==(const PhysicalNumber & b) const
{
	if (sameType(b))
	{
		if (this->value == b.value*(conversion[b.category] / conversion[this->category]))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool ariel::PhysicalNumber::operator!=(const PhysicalNumber & b) const
{
	if (sameType(b))
	{
		if (this->value != b.value*(conversion[b.category] / conversion[this->category]))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

 PhysicalNumber & ariel::PhysicalNumber::operator++()
{
	 ++this->value;
	return *this;
}

 PhysicalNumber ariel::PhysicalNumber::operator++(int value)
{
	 PhysicalNumber corrent(*this);
	 this->value++;
	 return corrent;
}

 PhysicalNumber & ariel::PhysicalNumber::operator--()
{
	--this->value;
	return *this;
}

 PhysicalNumber ariel::PhysicalNumber::operator--(int value)
{
	 PhysicalNumber corrent(*this);
	 this->value--;
	 return corrent;
}

istream & ariel::operator>>(istream & input,  PhysicalNumber & phy)
{
	return input;
}

ostream & ariel::operator<<(ostream & out,const PhysicalNumber & phy)
{
	return (out<<phy.value<<"["<<type[phy.category]<<"]");
}
