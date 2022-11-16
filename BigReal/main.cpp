#include <iostream>
#include <string>
#include "BigDecimalIntClass.h"
#include "BigRealClass.h"

int main()
{
    // Test Cases

    // Test Cases
    BigReal a{"123255544.123456789"},b{"123255544.123456789"},c{"-123255544.123456789"};
    BigReal d{"159.123456789"};

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////testing cout and addition of mized signs////////////////////////////

    BigReal e = a + b;
    cout << e << endl;
    cout << "expected result is 246511088.246913578" << endl << endl;

    BigReal g = a + c;
    cout << g << endl;
    cout << "expected result is 0" << endl << endl;


    BigReal h = a + d;
    cout << h << endl;
    cout << "expected result is 123255703.246913578" << endl << endl;

////////////////////////////////////////////////////////////////////////////////////////
//////////////////// Testing <, >, =, and == operators/////////////////////////////////////

    BigReal x(123255544.123456789);
    BigReal y(1232555989844.123456789);
    BigReal z(123255944.123456789);

    if (x < y)
    {
        cout << "x is less than y" << endl;
    }
    else
    {
        cout << "x is greater than y" << endl;
    }
    cout << "expected result is x is less than y" << endl << endl;
    if (x > z)
    {
        cout << "x is greater than z" << endl;
    }
    else
    {
        cout << "x is less than z" << endl;
    }
    cout << "expected result is x is less than z" << endl << endl;

    if (x == z)
    {
        cout << "x is equal to z" << endl;
    }
    else
    {
        cout << "x is not equal to z" << endl;
    }
    cout << "expected result is x is not equal to z" << endl << endl;
    if(x == a)
    {
        cout << "x is equal to a" << endl;
    }
    else
    {
        cout << "x is not equal to a" << endl;
    }
    cout << "expected result is x is equal to a" << endl << endl;

    x = y;
    if(x == y){
        cout << "x is equal to y" << endl;
    }
    else
    {
        cout << "x is not equal to y" << endl;
    }
    cout << "expected result is x is equal to a" << endl << endl;


////////////////////////////////////////////////////////////////////////////////
///////////////////////////////testing subtraction of "+" nums//////////////////
    BigReal smallnumber{"1.9"};
    BigReal smallnumber2{"1.1"};
    BigReal smallnumber3{"1.0"};
    BigReal smallnumber4{"0.9"};
    BigReal smallnumber5{"0.1"};

    cout << "smallnumber is " << smallnumber << endl;                         //1
    cout << "expected result is smallnumber is 1.9" << endl << endl;

    cout << smallnumber - smallnumber2 << endl;                               //2
    cout << "expected result is 0.8" << endl << endl;

    cout << smallnumber - smallnumber3 << endl;                               //3
    cout << "expected result is 0.9" << endl << endl;

    cout << smallnumber - smallnumber4 << endl;                               //4
    cout << "expected result is 1.0" << endl << endl;

    cout << smallnumber - smallnumber5 << endl;                               //5
    cout << "expected result is 1.8" << endl << endl;

    cout << smallnumber2 - smallnumber << endl;                               //6
    cout << "expected result is -0.8" << endl << endl;

    cout << smallnumber2 - smallnumber3 << endl;                              //7
    cout << "expected result is 0.1" << endl << endl;

/////////////////////////////////////////////////////////////////////////////////////////////////

    BigReal i, j;
    cin >> i >> j;

    cout << i + j << endl << endl;
    cout << i - j << endl << endl;

    //Default Constructor*/
    return 0;
}
