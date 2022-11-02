// check if the valid express or not.
#include <iostream>
#include <stack>
using namespace std;

bool validExpression(string expression)
{

    stack<char> s;

    for (int i = 0; i < expression.length(); i++)
    {
        char temp = expression[i];
        // when opening bracket, push in stack
        if (temp == '[' || temp == '(' || temp == '{')
        {
            s.push(temp);
        }
        // when closing bracket, check top and pop.
        else
        {

            if (!s.empty())
            {
                char top = s.top();
                if ((top == '(' && temp == ')') || (top == '{' && temp == '}') || (top == '[' && temp == ']'))
                {
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    string expression = "())";
    cout << validExpression(expression);
}

/*
3
[]
())
{[(
    */