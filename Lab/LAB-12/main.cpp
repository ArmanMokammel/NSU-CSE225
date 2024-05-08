#include <iostream>
#include <math.h>

using namespace std;

int factorial(int n)
{
    if(n == 1 || n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}

int sumOfDigits(int n)
{
    if (n == 0)
        return 0;
    else
        return n+sumOfDigits(n-1);
}

double sumOfSeries(int n)
{
    if (n == 0)
        return 1;
    else
        return 1.0/pow(2,n) + sumOfSeries(n-1);
}

int main()
{
    int x;
    cout << "Enter a positive number: ";
    cin >> x;

    cout << "Factorial of " << x << " is: " << factorial(x) << endl;
    cout << "Fibonacci of " << x << " is: " << fib(x) << endl;
    cout << "Sum of digits of " << x << " is: " << sumOfDigits(x) << endl;
    cout << "Sum of series of " << x << " is: " << sumOfSeries(x) << endl;

    return 0;
}
