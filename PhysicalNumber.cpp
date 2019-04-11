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
	if (sameType(b))
	{
		this->value += b.value*(conversion[b.category] / conversion[this->category]);
		return *this;
	}
	else
	{
		throw invalid_argument("invalid action: can not add diffrent physical unit");
	}
	
}

PhysicalNumber & ariel::PhysicalNumber::operator-=(const PhysicalNumber & b)
{
	if (sameType(b))
	{
		this->value -= b.value*(conversion[b.category] / conversion[this->category]);
		return *this;
	}
	else
	{
		throw invalid_argument("invalid action: can not subtract diffrent physical unit");
	}
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
	else
	{
		string type1 = type[this->category];
		string type2 = type[b.category];
		string exep = "Units do not match - [" + type1 + "] cannot be converted to [" + type2 + "]";
		throw invalid_argument(Prints exep);
	}
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
	else
	{
		string type1 = type[this->category];
		string type2 = type[b.category];
		throw invalid_argument(Prints "Units do not match - " + type1 + "cannot be converted to " + type2);
	}
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
	else
	{
		string type1 = type[this->category];
		string type2 = type[b.category];
		throw invalid_argument(Prints "Units do not match - " + type1 + "cannot be converted to " + type2);
	}
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
	else
	{
		string type1 = type[this->category];
		string type2 = type[b.category];
		throw invalid_argument(Prints "Units do not match - " + type1 + "cannot be converted to " + type2);
	}
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
	else
	{
		string type1 = type[this->category];
		string type2 = type[b.category];
		throw invalid_argument(Prints "Units do not match - " + type1 + "cannot be converted to " + type2);
	}
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
	else
	{
		string type1 = type[this->category];
		string type2 = type[b.category];
		throw invalid_argument(Prints "Units do not match - " + type1 + "cannot be converted to " + type2);
	}
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
	double num = std::numeric_limits<double>::max();
	string str;
		input >> num >>str;
		if (num!= std::numeric_limits<double>::max()) {
			phy.value = num;
		}
		else { throw std::invalid_argument("error value input >>"); };

		if ((str.size() <= 6) && (str.size() >= 3))
		{
			if ((str.substr(0, 1) == "[") && (str.substr(str.size() - 1, str.size() - 1)== "]"))
			{
				string temp = str.substr(1, str.size() - 2);
					for (int i = 0; i < 9; i++)
					{
						if (type[i] == temp)
						{
							phy.category = Unit(i);
							
							return input;
						}
						
					}
				throw std::invalid_argument("error category input 1 >>");
			}
			else {
				throw std::invalid_argument("error category input 2>>");
			}
		}
		else
		{
			throw std::invalid_argument("error category input 3>>");
		}
		
	return input;

}

ostream & ariel::operator<<(ostream & out,const PhysicalNumber & phy)
{
	return (out<<phy.value<<"["<<type[phy.category]<<"]");
}
