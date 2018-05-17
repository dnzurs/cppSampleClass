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

	if (denom < 0)
	{
		nom = -nom;
	}

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
	if (r1.denom != r2.denom)
	{
		int tempNom1 = r1.nom * r2.denom;
		int tempNom2 = r2.nom * r1.denom;

		return tempNom1 < tempNom2;
	}
	else
	{
		return r1.nom < r2.nom;
	}
}

PUBLIC bool operator>(const Fraction &r1, const Fraction &r2)
{
	return r2 < r1;
}

PUBLIC bool operator<=(const Fraction &r1, const Fraction &r2)
{
	return !(r2 < r1);
}

PUBLIC bool operator>=(const Fraction &r1, const Fraction &r2)
{
	return !(r1 < r2);
}

PUBLIC bool operator==(const Fraction &r1, const Fraction &r2)
{
	return !(r2 < r1) && !(r1 < r2);
}

PUBLIC bool operator!=(const Fraction &r1, const Fraction &r2)
{
	return (r2 < r1) || (r1 < r2);
}

PUBLIC Fraction operator+(const Fraction &r1, const Fraction &r2)
{
	if (r1.denom != r2.denom)
	{
		int tempDenom = r2.denom * r1.denom;
		int tempNom1 = r1.nom * tempDenom / r1.denom;
		int tempNom2 = r2.nom * tempDenom / r2.denom;

		return Fraction{ tempNom1 + tempNom2, tempDenom };
	}
	else
	{
		return Fraction{ r1.nom + r2.nom, r1.denom };
	}
}

PUBLIC Fraction operator-(const Fraction &r1, const Fraction &r2)
{
	if (r1.denom != r2.denom)
	{
		int tempDenom = r2.denom * r1.denom;
		int tempNom1 = r1.nom * tempDenom / r1.denom;
		int tempNom2 = r2.nom * tempDenom / r2.denom;

		return Fraction{ tempNom1 - tempNom2, tempDenom };
	}
	else
	{
		return Fraction{ r1.nom - r2.nom, r1.denom };
	}
}

PUBLIC Fraction operator*(const Fraction &r1, const Fraction &r2)
{
	return Fraction{ r1.nom * r2.nom, r1.denom * r2.denom };
}

PUBLIC Fraction operator/(const Fraction &r1, const Fraction &r2)
{
	return Fraction{ r1.nom * r2.denom, r1.denom * r2.nom };
}

PUBLIC Fraction &Fraction::operator++()
{
	nom += denom;

	return *this;
}

PUBLIC Fraction Fraction::operator++(int)
{
	Fraction temp(*this);

	nom += denom;

	return temp;
}

PUBLIC Fraction &Fraction::operator--()
{
	nom -= denom;

	return *this;
}

PUBLIC Fraction Fraction::operator--(int)
{
	Fraction temp(*this);

	nom -= denom;

	return temp;
}
 
PUBLIC Fraction Fraction::operator+()const
{
	return *this;
}

PUBLIC Fraction Fraction::operator-()const
{
	if (denom < 0)
	{
		-nom;
	}

	return *this;
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
	return *this = *this - r;
}

PUBLIC Fraction &Fraction::operator/=(const Fraction &r)
{
	return *this = *this / r;
}

PUBLIC Fraction &Fraction::operator*=(const Fraction &r)
{
	return *this = *this * r;
}
 
PUBLIC std::ostream & operator<<(std::ostream &os, const Fraction &r)
{
	return os << r.nom << "/" << r.denom << "\n";
}

PUBLIC std::istream & operator>>(std::istream &is, Fraction &r)
{
	return is >> r.nom >> r.denom;
}
 
PUBLIC static Fraction random()
{

}
