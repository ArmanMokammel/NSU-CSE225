#include <iostream>
#include "StackType.cpp"
#include <string>

using namespace std;

string trimStr(string str)
{
    int x = 0;
    string result;

    while(str[x] != '\0')
    {
        if(str[x] == ' ')
        {
            x++;
            continue;
        }
        result += str[x];
        x++;
    }
    return result;
}

int checkPrecedence(char c)
{
    switch(c)
    {
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}

void postFixTOEval(string inputExpression)
{
    StackType<char> stack;

    string expression = "";
    string result;

    expression = trimStr(inputExpression);
    
    for(int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];

        if(checkPrecedence(expression[i]) != -1 && checkPrecedence(expression[i+1]) != -1)
        {
            cout << "Invalid expression" << endl << endl;
            return;
        }

        if((c >= '0' && c <= '9'))
        {
            result += c;
        }
        else if(c == '(')
        {
            stack.Push(c);
        }
        else if(c == ')')
        {
            try
            {
                while (stack.Top() != '(') {
                    result += stack.Top();
                    stack.Pop();
                }
                stack.Pop();
            }
            catch (EmptyStack e)
            {
                cout << "Invalid Expression" << endl << endl;
                return;
            }
        }
        else
        {
            while (!stack.IsEmpty() && (checkPrecedence(expression[i]) < checkPrecedence(stack.Top()) || checkPrecedence(expression[i]) == checkPrecedence(stack.Top()))) 
            {
                result += stack.Top();
                stack.Pop();
            }
            stack.Push(c);
            result += ' ';
        }
    }

    while (!stack.IsEmpty()) {
        if(stack.Top() == '(' || stack.Top() == ')')
        {
            cout << "Invalid Expression" << endl << endl;;
            return;
        }
        result += stack.Top();
        stack.Pop();
    }

    cout << result << endl;

    expression = result;
    
    StackType<double> evalStack;
    double temp = 0;
    for(int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];

        if(c == ' ')
        {
            if(temp == 0)
                continue;

            evalStack.Push(temp);
            temp = 0;
        }
        else if((c >= '0' && c <= '9'))
        {
            temp = (10 * temp) + (c - '0');
        }
        else
        {
            if (temp != 0)
            {
                evalStack.Push(temp);
                temp = 0;
            }
            double a,b, val = 0;
            
            b = evalStack.Top();
            evalStack.Pop();
            a = evalStack.Top();
            evalStack.Pop();

            switch(c)
            {
                case '+':
                    val = a + b;
                    break;
                case '-':
                    val = a - b;
                    break;
                case '*':
                    val = a * b;
                    break;
                case '/':
                    val = a / b;
                    break;
            }

            evalStack.Push(val);
        }
    }

    cout << "result = " << evalStack.Top() << endl << endl;
}

int main()
{
    while(1)
    {
        string inputExpression;

        cout << "Enter expression: ";
        getline(cin, inputExpression);

        postFixTOEval(inputExpression);
    }

    return 0;
}