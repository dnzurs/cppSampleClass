//============================================================================//
//
//	File Name	: fraction.h
//	Create Date	: 
//	Designers	: Deniz Uras
//	Description	: Fraction Class
//
//	Important Notes:
//
//============================================================================//

#ifndef _FRACTION_H_
#define _FRACTION_H_

//============================================================================//
//=============================== INCLUDES ===================================//
//============================================================================//
#include <exception>
#include <iosfwd>

//============================================================================//
//==========================  MACRO DEFINITIONS ==============================//
//============================================================================//

//============================================================================//
//=========================== TYPE DEFINITIONS ===============================//
//============================================================================//

//============================================================================//
//=========================== CLASS DEFINITIONS ==============================//
//============================================================================//
class BadFraction : public std::exception {

};

class Fraction {
public:
	// constructors and destructor
	Fraction(int nomVal = 0, int denomVal = 1); //ctor
	Fraction(const Fraction &r);				//copy ctor
	Fraction(Fraction &&r);						//move ctor
	Fraction &operator=(const Fraction &r);		//copy assignment
	Fraction &operator=(Fraction &&r);			//move assignment
	Fraction(double dVal);						//ctor as double 
	Fraction(const char *p);					//ctor as char 
	~Fraction() = default;						//destructor

	// operators
	friend bool operator<(const Fraction &r1, const Fraction &r2);
	friend bool operator>(const Fraction &r1, const Fraction &r2);
	friend bool operator<=(const Fraction &r1, const Fraction &r2);
	friend bool operator>=(const Fraction &r1, const Fraction &r2);
	friend bool operator==(const Fraction &r1, const Fraction &r2);
	friend bool operator!=(const Fraction &r1, const Fraction &r2);
	friend Fraction operator+(const Fraction &r1, const Fraction &r2);
	friend Fraction operator-(const Fraction &r1, const Fraction &r2);
	friend Fraction operator*(const Fraction &r1, const Fraction &r2);
	friend Fraction operator/(const Fraction &r1, const Fraction &r2);

	// fixes
	Fraction &operator++();		//prefix
	Fraction operator++(int);	//postfix
	Fraction &operator--();		//prefix
	Fraction operator--(int);	//postfix

	// signs
	Fraction operator+()const;	//sign op.
	Fraction operator-()const;  //sign op.

	// type casts
	explicit operator bool()const;

	// assignments
	Fraction &operator+=(const Fraction &r);
	Fraction &operator-=(const Fraction &r);
	Fraction &operator/=(const Fraction &r);
	Fraction &operator*=(const Fraction &r);

	// io
	friend std::ostream & operator<<(std::ostream &os, const Fraction &);  // (4) (-3/5)  (1 / 9)  
	friend std::istream & operator>>(std::istream &is, Fraction &);

	// utilities
	static Fraction random();  // nom or denom are less than 10
	
	// variables
	int nom;
	int denom;
private:
	static int gcd(int x, int y);
	void simplify();
	void commonCtorFunc(const Fraction &r);
};

//============================================================================//
//========================== FUNCTION PROTOTYPES =============================//
//============================================================================//

#endif //_FRACTION_H_
#if 1

#endif

