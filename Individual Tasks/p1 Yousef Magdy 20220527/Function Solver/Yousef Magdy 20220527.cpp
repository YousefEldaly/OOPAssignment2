#include <functional>
#include <iostream>
using namespace std;


class Function
{
public:
    virtual double evaluateAt(double value) = 0;
};

class SimpleFunction : public Function {
private:
    function<double(double)>fun;

public:
    SimpleFunction(function<double(double)>fun) {
        this->fun = fun;
    }

    double evaluateAt(double x) {
        return fun(x);
    }
};


class CompositionFunction : public Function {
private:
    function<double(double)>g;
    function<double(double)>f;

public:
    CompositionFunction(function<double(double)>f, function<double(double)>g) {
        this->f = f;
        this->g = g;
    }
    double evaluateAt(double x) {
        return f(g(x));
    }
};

class DerivativeFunction : public Function {
private:
    function<double(double)>f;
    double deltax;
public:
    DerivativeFunction(function<double(double)>f, double dx) {
        this->f = f;
        this->deltax = dx;
    }

    double evaluateAt(double x) {
        return ((f(x+deltax)-(f(x-deltax))) / 2 * deltax) - 1;
    }

};

double cube(double x) {
    return x * x * x;
}

double second(double d) {
    return d * d - 5 * d - 4;
}

double fun(double d) {
    return d * d - 3 * d - 4;
}


int main()
{
    SimpleFunction f1([](double n) -> double {return n * n; });
    cout << f1.evaluateAt(5) << endl;

    DerivativeFunction f2(second, 5);
    cout << f2.evaluateAt(5) << endl;

    CompositionFunction f3(fun, cube);
    cout << f3.evaluateAt(5) << endl;

    return 0;
}

