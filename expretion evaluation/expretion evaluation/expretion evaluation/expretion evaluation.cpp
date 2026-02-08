// expretion evaluation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stack>
#include<string>

using namespace std;

bool is_operator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/')
        return true;
    else
        return false;
}

int perform_operation(int num1, int num2, char op)
{
    int ans = 0; 

    switch (op)
    {
    case '+':
        ans = num2 + num1;
        break;

    case '-':
        ans = num2 - num1;
        break;

    case '*':
        ans = num2 * num1;
        break;
    case '/':
        ans = num2 / num1;
        break;        
    }
    return ans;
}

int main()
{
    int i=0 , j=0 , num1=0 , num2=0 ,len=0 ,x=0 ;
    char exp[1000];
    char buffer[15];    
    stack <int> s;

    cout << "Enter a Postfix Expression: ( e.g. 4 5 * )\n";
    cin.getline(exp, 1000);
    len = strlen(exp);

    for (i = 0; i < len; i++)
    {
        if (exp[i] >= 48 && exp[i] <= 57)
            buffer[j++] = exp[i];

        else if (exp[i] == ' ')
        {
            if (j > 0)
            {
                buffer[j] = NULL; //or buffer[j]='\n';
                x = atoi(buffer);
                s.push(x);
                j = 0;
            }
        }

        else if (is_operator(exp[i]))
        {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            s.push(perform_operation(num1, num2, exp[i]));
        }
    }

    cout << "answer = " << s.top();
    return 0;
}
 