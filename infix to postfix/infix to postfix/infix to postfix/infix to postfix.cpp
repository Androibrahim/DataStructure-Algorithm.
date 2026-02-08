// infix to postfix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool is_opertator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/')
        return true;
    else
        return false;
}

bool is_operand(char op)
{
    if (op >= 48 && op <= 57)
        return true;
    else 
        return false;
}

int wight(char op)
{
    int x = 0;
    if (op == '+' || op == '-')
        x = 1;
    else if(op =='*'|| op =='/')
        x = 2;
    return x;
}

bool has_priority(char op1, char op2)
{
    int w1 = wight(op1);
    int w2 = wight(op2);

    if (w1 == w2)
        return  true; 

    else if (w1 > w2)
        return true;

    else
        return false;
}


string infix_to_postfix(string expretion)
{
    size_t len = 0;
    stack<char>s;
    string postfix="";
    len = expretion.length();

    for (int i = 0; i < len; i++)
    {
        if (expretion[i] == ' ')
            continue;

        else if (is_operand(expretion[i]))
            postfix += expretion[i];

        else if (is_opertator(expretion[i]))
        {
            while (!s.empty() && s.top() != '(' && has_priority(s.top(), expretion[i]))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(expretion[i]);
        }


        else if (expretion[i] == '(')
            s.push(expretion[i]);

        else if (expretion[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }

        
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    string exp="";
    cout << "enter infix expretion :  ";
    getline(cin, exp);
    string postfix = infix_to_postfix(exp);
        cout <<"postfix is : "<< postfix;

    return 0;
}
 
