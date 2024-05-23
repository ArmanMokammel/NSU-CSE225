#include <iostream>
#include "StackType.cpp"
#include <string>

using namespace std;

/* Function to clear out all spaces */
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

/* Function to check the precedence of each operator */
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

/* You know what dis is :) */
void postFixTOEval(string inputExpression)
{
    StackType<char> stack;

    string expression = "";
    string result;

    //Get the space trimmed expression
    expression = trimStr(inputExpression);
    
    //For each character in the expression string
    for(int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];

        //This is to check if there are two operators side by side
        //If yes then invalid. Precedence function returns -1 if not operator
        if(checkPrecedence(expression[i]) != -1 && checkPrecedence(expression[i+1]) != -1)
        {
            cout << "Invalid expression" << endl << endl;
            return;
        }

        //If the character is a digit
        if((c >= '0' && c <= '9'))
        {
            //Put it directly to result
            result += c;
        }
        else if(c == '(')
        {
            //Push it to stack
            stack.Push(c);
        }
        else if(c == ')')
        {
            try
            {
                //Put all the operators of the stack directly to result until it reaches "("
                while (stack.Top() != '(') {
                    result += stack.Top();
                    stack.Pop();
                }
                //Then also discard the "(" from stack
                stack.Pop();
            }
            catch (EmptyStack e)
            {
                //If it fails.. this means stack is empty. So must be invalid expression
                cout << "Invalid Expression" << endl << endl;
                return;
            }
        }
        else
        {
            //If it is a operator
            //Check the precedence.. It must be less than or equal to the stack's top element
            while (!stack.IsEmpty() && (checkPrecedence(expression[i]) < checkPrecedence(stack.Top()) || checkPrecedence(expression[i]) == checkPrecedence(stack.Top()))) 
            {
                //Put the top elements to result
                result += stack.Top();
                stack.Pop();
            }
            //Push the new operand to stack
            stack.Push(c);
            result += ' ';
        }
    }

    //Empty out the stack to the result, if there is anything.
    //If a blank "(" or ")" is found then the expression was invalid
    while (!stack.IsEmpty()) {
        if(stack.Top() == '(' || stack.Top() == ')')
        {
            cout << "Invalid Expression" << endl << endl;;
            return;
        }
        result += stack.Top();
        stack.Pop();
    }

    //Print the post fix form
    cout << result << endl;

    expression = result;
    
    StackType<double> evalStack;
    double temp = 0;

    //For each character in the post fix expression string
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