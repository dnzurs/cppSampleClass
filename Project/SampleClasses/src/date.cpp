//============================================================================//
//
//	File Name	: date.c
//	Create Date	: 2018/06/08
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
#include <sstream>

//============================================================================//
//==========================  MACRO DEFINITIONS ==============================//
//============================================================================//
#define IS_LEAP_YEAR(x) ((!((x)%4))&&(((x)%100) || (!((x)%400)))) 

//============================================================================//
//=========================== TYPE DEFINITIONS ===============================//
//============================================================================//

//============================================================================//
//=========================== CLASS DEFINITIONS ==============================//
//============================================================================//
class PimplDate {
public:
	int mday;
	int wday;
	int yday;
	int month;
	int year;
};

//============================================================================//
//========================== FUNCTION PROTOTYPES =============================//
//============================================================================//

//============================================================================//
//============================ GLOBAL VARIABLES ==============================//
//============================================================================//
const std::string monthName[] =
{
	"Ocak",		"Subat",	"Mart",
	"Nisan",	"Mayis",	"Haziran",
	"Temmuz",	"Agustos",	"Eylul",
	"Ekim",		"Kasim",	"Aralik"
};

const std::string weekDayName[] =
{
	"Pazartesi", "Sali", "Carsamba", "Persembe", "Cuma", "Cumartesi", "Pazar"
};

const int dayOfMonths[2][12] =
{
	{ 31,28,31,30,31,30,31,31,30,31,30,31 },
	{ 31,29,31,30,31,30,31,31,30,31,30,31 }		// for leap year
};

const int dayOfYear[] = { 365, 366 };

//============================================================================//
//============================ PRIVATE FUNCTIONS =============================//
//============================================================================//
PRIVATE void Date::increaseDayOfDate(int n)
{
	date->mday += n;

	if (date->mday > dayOfMonths[IS_LEAP_YEAR(date->year)][date->month])
	{
		date->mday = 1;
		date->month++;

		if (date->month > 12)
		{
			date->month = 1;
			date->year++;
		}
	}

	// week day and year day of date
	setDate();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PRIVATE void Date::decreaseDayOfDate(int n)
{
	date->mday -= n;

	if (date->mday == 0)
	{
		date->month--;

		date->mday = dayOfMonths[IS_LEAP_YEAR(date->year)][date->month];

		if (date->month == 0)
		{
			date->month = 12;
			date->year--;
		}
	}

	// week day and year day of date
	setDate();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PRIVATE int findDayOfWeek(int d, int m, int y)
{
	return (d += m < 3 ? y-- : y - 2, 23 * m / 9 + d + 4 + (y / 4) - (y / 100) + (y / 400)) % 7;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PRIVATE	void Date::setDate()
{
	date->yday = 0;
	date->yday += date->mday;


	for (int i = 0; i < date->month - 1; ++i)
	{
		date->yday += dayOfMonths[IS_LEAP_YEAR(date->year)][i];
	}

	date->wday = findDayOfWeek(date->mday, date->month, date->year);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PRIVATE PimplDate* getMemory(void)
{
	return new PimplDate;
}

//============================================================================//
//============================ PUBLIC FUNCTIONS ==============================//
//============================================================================//
PUBLIC Date::Date()
{
	time_t	nowTime = time(0);
	tm		currDate;

	localtime_s(&currDate, &nowTime);

	date = getMemory();

	date->mday = currDate.tm_mday;
	date->wday = currDate.tm_wday;
	date->yday = currDate.tm_yday;
	date->month = currDate.tm_mon + 1;
	date->year = currDate.tm_year + 1900;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date::Date(int d, int m, int y)
{
	date = getMemory();

	if (random_min_year < y && y < random_max_year)
	{
		if (1 <= m && m <= 12)
		{
			if (1 <= d && d <= 31)
			{
				date->mday = d;
				date->month = m;
				date->year = y;

				// week day and year day of date
				setDate();
			}
		}
	}
	else
	{
		Date();
	}
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date::Date(const char *pstr)
{
	char temp[5] = { 0 };

	/*
	scaning -> gg/aa/yyyy
	index   -> 0123456789
	*/

	date = getMemory();

	//day
	memcpy(temp, pstr, 2);
	date->mday = atoi(temp);

	//month
	memset(temp, 0, sizeof(temp));
	memcpy(temp, (pstr + 3), 2);
	date->month = atoi(temp);

	//year
	memset(temp, 0, sizeof(temp));
	memcpy(temp, (pstr + 6), 4);
	date->year = atoi(temp);

	// week day and year day of date
	setDate();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date::Date(const std::string &str)
{
	std::string s(str);
	std::string delimiter = "/";
	std::string token;
	size_t pos = 0;
	int	counter = 0;

	date = getMemory();

	while ((pos = s.find(delimiter)) != std::string::npos)
	{
		token = s.substr(0, pos);

		if (counter == 0)
		{
			date->mday = std::stoi(token, 0, 10);
		}
		else if (counter == 1)
		{
			date->month = std::stoi(token, 0, 10);
		}

		s.erase(0, pos + delimiter.length());
		++counter;
	}

	date->year = std::stoi(s, 0, 10);

	// week day and year day of date
	setDate();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date::Date(const Date &r)
{
	date = getMemory();

	this->date->mday = r.date->mday;
	this->date->month = r.date->month;
	this->date->wday = r.date->wday;
	this->date->yday = r.date->yday;
	this->date->year = r.date->year;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date::Date(Date &&r)
{
	date = getMemory();

	this->date->mday = r.date->mday;
	this->date->month = r.date->month;
	this->date->wday = r.date->wday;
	this->date->yday = r.date->yday;
	this->date->year = r.date->year;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date::~Date(void)
{
	delete date;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC int Date::MonthDay()const
{
	return date->mday;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC int Date::WeekDay()const
{
	return date->wday;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC int Date::YearDay()const
{
	return date->yday;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC int Date::Year()const
{
	return date->year;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC int Date::Month()const
{
	return date->month;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date & Date::setMonth(int m)
{
	date->month = m;

	return *this;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date & Date::setYear(int y)
{
	date->year = y;

	return *this;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date & Date::setMonthDay(int d)
{
	date->mday = d;

	return *this;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date & Date::operator+=(int n)
{
	increaseDayOfDate(n);

	return *this;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date & Date::operator-=(int n)
{
	decreaseDayOfDate(n);

	return *this;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date & Date::operator++()
{
	increaseDayOfDate(1);

	return *this;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date Date::operator++(int)
{
	Date tempDate(date->mday, date->month, date->year);

	increaseDayOfDate(1);

	return tempDate;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date & Date::operator--()
{
	decreaseDayOfDate(1);

	return *this;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date Date::operator--(int)
{
	Date tempDate(date->mday, date->month, date->year);

	decreaseDayOfDate(1);

	return tempDate;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC bool operator<(const Date &d1, const Date &d2)
{
	bool retVal = false;

	retVal = d1.date->yday < d2.date->year ? true : false;

	if (retVal == false && (d1.date->yday == d2.date->year))
	{
		retVal = d1.date->month < d2.date->month ? true : false;
	}

	if (retVal == false && (d1.date->month == d2.date->month))
	{
		retVal = d1.date->mday < d2.date->mday ? true : false;
	}

	return retVal;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC bool operator<=(const Date &d1, const Date &d2)
{
	return !(d2 < d1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC bool operator>(const Date &d1, const Date &d2)
{
	return d2 < d1;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC bool operator>=(const Date &d1, const Date &d2)
{
	return !(d1 < d2);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC bool operator==(const Date &d1, const Date &d2)
{
	return !(d2 < d1) && !(d1 < d2);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC bool operator!=(const Date &d1, const Date &d2)
{
	return (d2 < d1) || (d1 < d2);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC int operator-(const Date &r1, const Date &r2)
{
	int tempDay = 0;
	int diffYear = r1.date->year - r2.date->year;

	tempDay = r1.date->yday - r2.date->yday;

	if (diffYear < 0)
	{
		for (int i = 0; i < -diffYear; ++i)
		{
			tempDay -= dayOfYear[IS_LEAP_YEAR(r2.date->year)];
		}
	}
	else if (diffYear > 0)
	{
		for (int i = 0; i < diffYear; ++i)
		{
			tempDay += dayOfYear[IS_LEAP_YEAR(r1.date->year)];
		}
	}

	return tempDay;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date Date::operator+(int n)const
{
	Date tempDate(date->mday, date->month, date->year);

	tempDate.increaseDayOfDate(n);

	return tempDate;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date Date::operator-(int n)const
{
	Date tempDate(date->mday, date->month, date->year);

	tempDate.decreaseDayOfDate(n);

	return tempDate;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC std::ostream &operator<<(std::ostream &os, const Date &r)
{
	std::ostringstream osst;

	osst << r.date->mday << " " << monthName[r.date->month - 1] << " " << r.date->year << " " << weekDayName[r.date->wday - 1];
	return os << osst.str();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC std::istream &operator>>(std::istream &is, Date &r)
{
	std::string tempStr;

	is >> tempStr;

	Date tempDate(tempStr);

	r.date->mday = tempDate.date->mday;
	r.date->month = tempDate.date->month;
	r.date->year = tempDate.date->year;
	r.date->yday = tempDate.date->yday;
	r.date->wday = tempDate.date->wday;

	return is;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC std::string Date::to_string()const
{
	return std::string{ std::to_string(date->mday) + "/" + std::to_string(date->month) + "/" + std::to_string(date->year) };
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
PUBLIC Date Date::randomDate()
{
	Date tempDate;

	tempDate.date->year = rand() % (random_max_year - random_min_year) + random_min_year;
	tempDate.date->month = rand() % 12 + 1;
	tempDate.date->mday = rand() % dayOfMonths[IS_LEAP_YEAR(tempDate.date->year)][tempDate.date->month] + 1;

	// week day and year day of date
	tempDate.setDate();

	return tempDate;
}
