#include "complex.h"
#include <iostream>

using namespace std;

Complex::Complex()
{
    Real = 0;
    Imaginary = 0;
}

Complex::Complex(double r, double i)
{
    Real = r;
    Imaginary = i;
}

Complex Complex::operator+(Complex a)
{
    Complex t;
    t.Real = Real + a.Real;  //c1.real + c2.real
    t.Imaginary = Imaginary + a.Imaginary;  //c1.imaginary + c2.imaginary
    return t;
}

bool Complex::operator==(Complex b)
{
    bool result = false;
    result = Real == b.Real && Imaginary == b.Imaginary;  //If both are true
    return result;
}

void Complex::Print()
{
    cout << Real << ", " << Imaginary << endl;
}

