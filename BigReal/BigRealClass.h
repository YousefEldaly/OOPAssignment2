// FCAI Object Oriented Programming Assignment 2
// BigReal using the BigDecimalInt as a client
// Made by:
// Yousef Magdy Eldaly     ID: 20220527
// Yousef Karam            ID: 20210480
// Omnia Magdy             ID: 20211018
#ifndef BIGREALCLASS_H_INCLUDED
#define BIGREALCLASS_H_INCLUDED
#include "BigDecimalIntClass.h"


class BigReal
{
    friend ostream& operator<<(ostream&, const BigReal&);        // overloading Stream Extraction Operator
    friend istream& operator>>(istream&, BigReal&);              // Overloading Stream Insertion Operator

private:
    BigDecimalInt whole;
    BigDecimalInt fraction;
    string whole_string;
    string fraction_string;
    string number;
    char big_sign = '+';

public:
    BigReal(double realNumber = 0.0);          // Default constructor
    BigReal(string realNumber);
    BigReal(BigDecimalInt bigInteger);
    BigReal(const BigReal&);                   // Copy constructor
    BigReal(BigReal&&);                        // Move constructor
    BigReal &operator=(const BigReal&);        // Assignment Operator
    BigReal &operator= (BigReal&&);            // Move Assignment


    ///////////////////////////

    BigReal operator+ (BigReal& other);         // Overloading + operator
    BigReal operator- (BigReal& other);         // Overloading - operator

    ////////////////////////

    bool operator<(BigReal anotherReal);        // Overloading <  operator
    bool operator>(BigReal anotherReal);        // Overloading >  operator
    bool operator==(BigReal anotherReal);       // Overloading == operator
    int size();                                 // get size of BigReal
    char sign();                                // get sign of BigReal

};

#endif // BIGREALCLASS_H_INCLUDED
