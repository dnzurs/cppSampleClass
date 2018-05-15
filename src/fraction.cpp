//============================================================================//
//
//	File Name	: fraction.c
//	Create Date	: 
//	Designers	: Deniz Uras
//	Description	: Fraction Class
//
//	Important Notes:
//
//============================================================================//


//============================================================================//
//=============================== INCLUDES ===================================//
//============================================================================//
#include "fraction.h"
#include <iostream>

//============================================================================//
//==========================  MACRO DEFINITIONS ==============================//
//============================================================================//


//============================================================================//
//=========================== TYPE DEFINITIONS ===============================//
//============================================================================//


//============================================================================//
//=========================== CLASS DEFINITIONS ==============================//
//============================================================================//


//============================================================================//
//========================== FUNCTION PROTOTYPES =============================//
//============================================================================//


//============================================================================//
//============================ GLOBAL VARIABLES ==============================//
//============================================================================//


//============================================================================//
//============================ PRIVATE FUNCTIONS =============================//
//============================================================================//
PRIVATE int Fraction::gcd(int x, int y)
{
	while (x != 0)
	{
		int temp = x;
		x = y % x;
		y = temp;
	}

	return y;
}

PRIVATE void Fraction::simplify()
{
	int divider = gcd(nom, denom);
	
	nom /= divider;
	denom /= divider;
}

PRIVATE void Fraction::commonCtorFunc(const Fraction &r)
{
	nom = r.nom;
	denom = r.denom;

	simplify();
}

//============================================================================//
//============================ PUBLIC FUNCTIONS ==============================//
//============================================================================//
PUBLIC Fraction::Fraction(int nomVal, int denomVal)
{
	if (denomVal == 0)
	{
		throw BadFraction();
	}
	else
	{
		nom = nomVal;
		denom = denomVal;

		simplify();
	}
}

PUBLIC Fraction::Fraction(const Fraction &r)
{
	commonCtorFunc(r);
}

PUBLIC Fraction::Fraction(Fraction &&r)
{
	commonCtorFunc(r);
}

PUBLIC Fraction &Fraction::operator=(const Fraction &r)
{
	commonCtorFunc(r);

	return *this;
}

PUBLIC Fraction &Fraction::operator=(Fraction &&r)
{
	commonCtorFunc(r);

	return *this;
}

PUBLIC Fraction::Fraction(double)
{

}

PUBLIC Fraction::Fraction(const char *p) 
{
	if ((*p == '-') || (*p == '+') || ('0' <= *p && *p <= '9'))
	{
		if (*p == '-')
		{

		}
		else if (*p == '+')
		{

		}
		else if ('0' <= *p && *p <= '9')
		{

		}
	}
	else
	{
		throw BadFraction();
	}
}

PUBLIC bool operator<(const Fraction &r1, const Fraction &r2)
{
	return true;
}

PUBLIC bool operator>(const Fraction &r1, const Fraction &r2)
{
	return true;
}

PUBLIC bool operator<=(const Fraction &r1, const Fraction &r2)
{
	return true;
}

PUBLIC bool operator>=(const Fraction &r1, const Fraction &r2)
{
	return true;
}

PUBLIC bool operator==(const Fraction &r1, const Fraction &r2)
{
	return true;
}

PUBLIC bool operator!=(const Fraction &r1, const Fraction &r2)
{
	return true;
}

PUBLIC Fraction operator+(const Fraction &r1, const Fraction &r2)
{
	return Fraction{  };
}

PUBLIC Fraction operator-(const Fraction &r1, const Fraction &r2)
{
	return Fraction{};
}

PUBLIC Fraction operator*(const Fraction &r1, const Fraction &r2)
{
	return Fraction{};
}

PUBLIC Fraction operator/(const Fraction &r1, const Fraction &r2)
{
	return Fraction{};
}

PUBLIC Fraction &Fraction::operator++()
{
	return *this;
}

PUBLIC Fraction Fraction::operator++(int)
{
	return Fraction{};
}

PUBLIC Fraction &Fraction::operator--()
{
	return *this;
}

PUBLIC Fraction Fraction::operator--(int)
{
	return Fraction{};
}
 
PUBLIC Fraction Fraction::operator+()const
{
	return Fraction{};
}

PUBLIC Fraction Fraction::operator-()const
{
	return Fraction{};
}
 
/*
PUBLIC Fraction::operator bool()
{
	return;
}
*/

PUBLIC Fraction &Fraction::operator+=(const Fraction &r)
{
	return *this = *this + r;
}

PUBLIC Fraction &Fraction::operator-=(const Fraction &r)
{
	return *this;

}

PUBLIC Fraction &Fraction::operator/=(const Fraction &r)
{
	return *this;
}

PUBLIC Fraction &Fraction::operator*=(const Fraction &r)
{
	return *this;
}
 
PUBLIC std::ostream & operator<<(std::ostream &os, const Fraction &r)
{
	return os;
}

PUBLIC std::istream & operator>>(std::istream &is, Fraction &r)
{
	return is;
}
 
PUBLIC static Fraction random()
{

}
