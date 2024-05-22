#include <iostream>
#include "StackType.cpp"
#include <string>

using namespace std;

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

int main()
{
    StackType<char> stack;

    string inputExpression;
    string expression = "";
    string result;

    cout << "Enter expression: ";
    getline(cin, inputExpression);
    
    int x = 0;
    while(inputExpression[x] != '\0')
    {
        if(inputExpression[x] == ' ')
        {
            x++;
            continue;
        }

        expression += inputExpression[x];
        x++;
    }

    for(int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result += c;
        }
        else if(c == '(')
        {
            stack.Push(c);
        }
        else if(c == ')')
        {
            while (stack.Top() != '(') {
                result += stack.Top();
                stack.Pop();
            }
            stack.Pop();
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
        result += stack.Top();
        stack.Pop();
    }
 
    cout << result << endl;

    return 0;
}