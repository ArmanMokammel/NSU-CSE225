#include <iostream>
#include "StackType.cpp"

using namespace std;

template<class ItemType>
void checkStack(StackType<ItemType> stack, string input)
{
    try
    {
        for(int i = 0; i < input.length(); i++)
        {
            if(input[i] == '('){
                stack.Push(input[i]);
            }
            else if(input[i] == ')'){
                stack.Pop();
            }
            else{
                cout << "Invalid character(s)" << endl;
                return;
            }
        }

    }
    catch(EmptyStack e)
    {
        cout << "Not Balanced" << endl;
        return;
    }


    if(stack.IsEmpty())
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;

        for(int i = 0; i < stack.size(); i++)
        {
            stack.Pop();
        }
    }


}

int main()
{
    StackType<char> stack;
    string input;

    input = "()";
    cout << "Enter a sequence of parenthesis: " << input << endl;
    checkStack(stack, input);

    input = "(())()(()())()";
    cout << "Enter a sequence of parenthesis: " << input << endl;
    checkStack(stack, input);

    input = "(())()((()";
    cout << "Enter a sequence of parenthesis: " << input << endl;
    checkStack(stack, input);

    input = "(())))((()";
    cout << "Enter a sequence of parenthesis: " << input << endl;
    checkStack(stack, input);
    

    return 0;
}