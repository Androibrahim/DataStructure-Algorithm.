

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











