

//linked queue
#include<iostream>
using namespace std;

template<class t>

class queue
{
private :
    struct node
    {
        t item;
        node* next;
    };

    node*  front;
    node* back;
    int length = 0;

public:
    queue()
    {
        front = NULL;
        back = NULL;
        length = 0;
    }


    bool isempty()
    {
        if (front == NULL && back==NULL) //or => if(length ==0)return 1 else return 0;
            return true;
        else
            return false;
    }



    void push(t element)
    {
        if (isempty())
        {
            front = new node; //123
            front->item = element;
            front->next = NULL;
            back = front;
            length++;
        }

        else
        {
            node* new_node = new node;//1234
            new_node->item = element;
            new_node->next = NULL;
            back->next = new_node;
            back = new_node;
            length++;
        }
    }






    void pop()
    {
        if (isempty())
            cout << "queue is emptpy \n";
        else
        {
            if (length == 1 || (front == back))
            {
                front = NULL;  // or delete front
                back = NULL;   // or delete back
                length = 0;
            }
            else
            {
                node* temp = front;
                front = front->next;
                temp->next = NULL;
                delete temp;
                length--;
            }

        }
    }






    t get_front()
    {
        if (isempty()) cout << "queue is empty\n";
        else return front->item;
    }



    t get_back()
    {
        if (isempty()) cout << "queue is empty\n";
        else return back->item;
    }






    void clear()
    {
        if (isempty())cout << "queue is empty \n";

        else
        {
                node* cur ;
                while (front != NULL)
                {
                    cur = front;
                    front = front->next;
                    cur = NULL;
                }
                back = NULL;
                front = NULL;
                length = 0;
        }
    }












    /*
    void clear()
    {
        if (isempty())cout << "queue is empty \n";

        else
        {
            if (length == 1 || (front == back))
            {

                delete back;
                length = 0;
            }
            else
            {
                node* cur;
                while (front != NULL)
                {
                    cur = front;
                    front = front->next;
                    cur = NULL;
                }
                back = NULL;
                front = NULL;
                length = 0;
            }
        }
    }
    */





    void display()
    {
        if (isempty()) cout << "queue is empty [ ] \n";

        else
        {
            cout << "[ ";
            node* cur = front;
            while (cur != NULL)
            {
                cout << cur->item<<"  ";
                cur = cur->next;
            }
            cout << "]";
        }
    }



    int size()
    {
        return length;
    }
};

int main()
{
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display();
    cout << "\nsize = " << q.size();
    cout << "\n ==========================\n";
    q.pop();
    q.display();
    cout << "\n";
    cout <<"size = " << q.size();

    cout << "\n ==========================\n";
    q.clear();
    cout << "size = " << q.size() << endl;
    q.display();
    return 0;
}