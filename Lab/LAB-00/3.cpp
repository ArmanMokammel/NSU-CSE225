#include <iostream>

using namespace std;

int main()
{
    int a, b;
    char op;
    float result;

    //Or I could do cin >> a >> b for one line multiple inputs
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    switch(op){
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = (float) a / b;
            break;
        default:
            cout << "Invalid operator" << endl;
            return 0;

    }

    cout << "The result of a" << op << "b is: " << result << endl;

    return 0;
}

