 
/*
//implementaion stack
#include <iostream>
#include<string>
using namespace std;
const int max_size = 50;

template<class t>
class stack
{
private:
    int top;
    t item[max_size];
public:
     
    stack():top(-1){}

    // fun push();
    void push(t element)
    {
        if (top >= max_size - 1)
            cout << "cant push => stack is full\n";
        else
        {
            top++;
            item[top] = element;
        }
    }




    //fun isempty()
    bool isempty()
    {
        if (top <= -1)
            return true;
        else
            return false;
    }




    // fun pop()
    void pop()
    {
        if (isempty() == 1)
            cout << "stack is empty cant pop";
        else
            top--;
    }


    //pop&save()
    void pop_and_save(t &element)
    {
        if (isempty() == 1)
            cout << "stack is empty cant pop";
        else
        {
            element = item[top];
            top--;            
        }
    }



    t pop_and_save2( )
    {
        if (isempty() == 1)
            cout << "stack is empty cant pop";
        else
        {
            t x = top;
            top--;
            return item[x];
        }
    }


    //ctrl_z
    void ctrl_z(t x_element)
    {
        top++;
        item[top] = x_element;
    }

    //fun get_top()
    void get_top()
    {
        if (isempty() == 1)
            cout << "stack is empty cant  get_top";
        else
        {
            cout << item[top];
        }

    }
    



    //print
    void print()
    {
        for (int i = 0; i < top + 1; i++)
        {
            cout << item[i] << " ";
        }
    }
};

 

int main()
{
     

    stack<int>s;
    s.push(5);
    s.push(6);
    s.push(10);
   
    s.print();
    cout << endl;
    s.get_top();

    cout << "\n===========================\n";
    s.push(5);
    s.push(6);
    s.push(10);
    s.pop();
    s.print();
    cout << endl;
    s.get_top();
    s.push(10);
    cout << endl;
    s.print();
    cout << endl;
    s.get_top();

    cout << "\n================================\n";

    stack<char>s2;
    s2.push('a');
    s2.push('b');
    s2.push('c');
    s2.print();

    cout << endl;
    char x;
    s2.pop_and_save(x);
    cout << x;
    cout << "\nvalue in stack is:"; s2.print();
     



    cout << "\n===================================\n";


    stack<int>s3;
    s3.push(1);
    s3.push(2);
    s3.push(3);
    s3.push(4);
    s3.print();
    cout << endl;

    int save = 0;
    save = s3.pop_and_save2();
    cout << save;
    cout << endl;
    cout << "s3 now : "; s3.print();
    s3.ctrl_z(save);
    cout << "\ns3 after ctrl_z : "; s3.print();

   
    return 0;
}
*/
 






















/*
//linked stack 
#include<iostream>
#include<string>
using namespace std;

template<class t>

class stack
{
    struct node
    {
        t item;
        node* next;
    };

    node* top;

public:
    stack()
    {
        top = NULL;
    }


    // push()
    void push(t new_element)
    {
        node* new_item = new node;
        new_item->item = new_element;
        new_item->next = top;
        top = new_item;
    }


    // isempty()
    bool isempty()
    {
        return top == NULL;
    }


    // pop
    void pop()
    {
        if (isempty())
            cout << "stack is empty to pop";
        else
        {
            node* temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }




    //pop and save value
    void pop_save( t &x)
    {
        if (isempty())
            cout << "stack is empty to pop";

        else
        {
            x = top->item;
            node* temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }


    void get_top()
    {
        if (top == NULL)
            cout << "stack is empty";
        else
            cout << top->item;
    }

    //display
    void display()
    {
        node* cur = top;
          while(!cur==NULL)
        {
            cout << cur->item<<" ";
            cur = cur->next;
        }
    }
};

int main()
{
    stack<int>s;
    s.push(100);
    s.push(200);
    s.push(300);

    s.display();
    cout << endl;
    s.get_top();
    cout << endl;
    s.pop();
    s.display();
    cout << endl;
    s.get_top();

    cout << endl;
    int x = 0;
    s.pop_save(x);
    cout <<"element pop = " << x << "\n stack now : ";
    s.display();
    return 0;
}
*/


















/*
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
}*/




 