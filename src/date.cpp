//============================================================================//
//
//	File Name	: date.c
//	Create Date	: 2018/05/20
//	Designers	: Deniz Uras
//	Description	: Date Class
//
//	Important Notes:
//
//============================================================================//


//============================================================================//
//=============================== INCLUDES ===================================//
//============================================================================//
#include "date.h"
#include "utility.h"

#include <iostream>
#include <ctime>

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

//============================================================================//
//========================== FUNCTION PROTOTYPES =============================//
//============================================================================//


//============================================================================//
//============================ GLOBAL VARIABLES ==============================//
//============================================================================//


//============================================================================//
//============================ PRIVATE FUNCTIONS =============================//
//============================================================================//


//============================================================================//
//============================ PUBLIC FUNCTIONS ==============================//
//============================================================================//
PUBLIC Date::Date() 
{

}	

PUBLIC Date::Date(int d, int m, int y)
{

}	

PUBLIC Date::Date(const char *pstr)
{

}

PUBLIC Date::Date(const std::string &s)
{

}		

PUBLIC int Date::MonthDay()const
{
	return 0;

}

PUBLIC int Date::WeekDay()const
{
	return 0;

}

PUBLIC int Date::YearDay()const
{
	return 0;

}

PUBLIC int Date::Year()const
{
	return 0;

}

PUBLIC int Date::Month()const
{
	return 0;
}		
						
PUBLIC Date & Date::setMonth(int m)
{
	return Date{};
}

PUBLIC Date & Date::setYear(int y)
{
	return Date{};
}

PUBLIC Date & Date::setMonthDay(int d)
{
	return Date{};
}

PUBLIC Date & Date::operator+=(int n)
{
	return Date{};
}

PUBLIC Date & Date::operator-=(int n)
{
	return Date{};

}

PUBLIC Date &Date::operator++()
{
	return Date{};

}		

PUBLIC Date Date::operator++(int)
{
	return Date{};

}	

PUBLIC Date &Date::operator--()
{
	return Date{};

}

PUBLIC Date Date::operator--(int)
{
	return Date{  };
}	

PUBLIC bool operator<(const Date &d1, const Date &d2)
{
	return true;

}

PUBLIC bool operator<=(const Date &d1, const Date &d2)
{
	return true;

}

PUBLIC bool operator>(const Date &d1, const Date &d2)
{
	return true;

}

PUBLIC bool operator>=(const Date &d1, const Date &d2)
{
	return true;

}

PUBLIC bool operator==(const Date &d1, const Date &d2)
{
	return true;

}

PUBLIC bool operator!=(const Date &d1, const Date &d2)
{
	return true;
}

PUBLIC int operator-(const Date &r1, const Date &r2)
{
	return 0;
}  
													   
PUBLIC Date Date::operator+(int)const
{
	return Date{};

}

PUBLIC Date Date::operator-(int)const
{
	return Date{};
}

PUBLIC std::ostream &operator<<(std::ostream &os, const Date &r)
{
	return os;
} 

PUBLIC std::istream &operator>>(std::istream &is, Date &r)
{
	return is;
}

PUBLIC std::string Date::to_string()const
{
	return std::string{};
}

PUBLIC Date Date::randomDate()
{
	return Date{};
}
