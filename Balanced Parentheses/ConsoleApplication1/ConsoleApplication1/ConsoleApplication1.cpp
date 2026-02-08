

//Balanced Parentheses Using Stack {([ ])}
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool arepair(char open, char close)
{

    if (open == '(' && close == ')') return true;
    else if (open == '[' && close == ']')return true;
    else if (open == '{' && close == '}') return true;
    else return false;

}


bool balance(string exp)
{
    stack<char>s;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '('  || exp[i]=='[' || exp[i]=='{')
        {
            s.push(exp[i]);
        }
        else
        {
            if (s.empty()==1 || arepair(s.top(), exp[i]) ==0)
            {
                return false;
            }
            else
            s.pop();
        }
    }

    if (s.empty() == true) return true;
    else   return false;
}
int main()
{
    string x = "[{}()[";
    if (balance(x) == 1)
        cout << "expretion are balande\n";
    else
        cout << "expretion not balance \n";

    return 0;
}
