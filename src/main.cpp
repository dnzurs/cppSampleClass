#define  _CRT_SECURE_NO_WARNINGS


#include "date.h"
#include <iostream>


using namespace std;

#define GENERAL_MAIN		(1)
#define DATE_TEST_MAIN		(0)
#define FRACTION_TEST_MAIN	(0)

#if GENERAL_MAIN
int main()
{


}
#elif DATE_TEST_MAIN
int main()
{
	Date date1(1,1,1980);
	Date date2;
	Date date3 = "20/11/2018";


	cout << date1 << "\n";
	cout << date2 << "\n";
	cout << date3 << "\n";


	getchar();
}
#elif FRACTION_TEST_MAIN
int main()
{
	Fraction f1 = Fraction::random();
	Fraction f2{ 1,-3 };
	Fraction f3 = -f2;
	Fraction f4 = { 2,-3 };
	Fraction f5 = "-15/72";
	Fraction f6 = 3.2;
	Fraction f7 = 2;
	Fraction f8(-3, -5);
	Fraction f9;
	
	cout << "f1 = " << f1 << "\n";
	cout << "f2 = " << f2 << "\n";
	cout << "f3 = " << f3 << "\n";
	cout << "f4 = " << f4 << "\n";
	cout << "f5 = " << f5 << "\n";
	cout << "f6 = " << f6 << "\n";
	cout << "f7 = " << f7 << "\n";
	cout << "f8 = " << f8 << "\n";
	cout << "f9 = " << f9 << "\n";

	cout << "Deger giriniz : \n";
	cin >> f9;
	cout << "f9 = " << f9 << "\n";

	cout << "\n***comparing operators***\n";
	cout << "(" << f1 << ")" << " < "  << "(" << f2 << ")" << " = " << (f1 < f2)  << "\n";
	cout << "(" << f1 << ")" << " > "  << "(" << f2 << ")" << " = " << (f1 > f2)  << "\n";
	cout << "(" << f1 << ")" << " <= " << "(" << f2 << ")" << " = " << (f1 <= f2) << "\n";
	cout << "(" << f1 << ")" << " >= " << "(" << f2 << ")" << " = " << (f1 >= f2) << "\n";
	cout << "(" << f1 << ")" << " == " << "(" << f2 << ")" << " = " << (f1 == f2) << "\n";
	cout << "(" << f1 << ")" << " != " << "(" << f2 << ")" << " = " << (f1 != f2) << "\n";
	cout << "\n";

	cout << "\n***operators***\n";
	cout << "f1 = " << f1 << "\n" << "f2 =" << f2 << "\n";
	cout << "f1 + f2 = " << f1 + f2 << "\n";
	cout << "f1 - f2 = " << f1 - f2 << "\n";
	cout << "f1 * f2 = " << f1 * f2 << "\n";
	cout << "f1 / f2 = " << f1 / f2 << "\n";
	cout << "\n";

	cout << "\n***fixes***\n";
	cout << "f1 = "		<< f1	<< "\n";;
	cout << "++f1 = "	<< ++f1 << "\n";;
	cout << "--f1 = "	<< --f1 << "\n";;
	cout << "f1++ = "	<< f1++ << "\n";;
	cout << "f1 = "		<< f1	<< "\n";;
	cout << "f1-- = "	<< f1-- << "\n";;
	cout << "f1 = "		<< f1	<< "\n";;
	cout << "\n";

	cout << "\n***sign operators***\n";
	cout << "+f1 = " << +f1 << "\n";;
	cout << "-f1 = " << -f1 << "\n";;
	cout << "\n";

	cout << "\n***assignment operators***\n";
	cout << f1 << " += " << f2 << " -------> " << "f1 = ";
	f1 += f2;
	cout << f1 << "\n";

	cout << f1 << " -= " << f2 << " -------> " << "f1 = ";
	f1 -= f2;
	cout << f1 << "\n";

	cout << f1 << " *= " << f2 << " -------> " << "f1 = ";
	f1 *= f2;
	cout << f1 << "\n";

	cout << f1 << " /= " << f2 << " -------> " << "f1 = ";
	f1 /= f2;
	cout << f1 << "\n";

	cout << "\n";

	getchar();
	getchar();
}
#endif