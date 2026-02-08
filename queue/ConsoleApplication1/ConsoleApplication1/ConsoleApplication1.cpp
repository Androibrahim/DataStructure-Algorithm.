 /*
#include <iostream>
using namespace std;
const int max_size = 10;
 
template <class t>
 
class queue
{
private:
    int back=0;
    int front=0;
    int length=0;
    t item[max_size];

public:

    queue()
    {
        back = max_size -1;
        front = 0;
        length = 0;
    }

    bool isempty()
    {
        return length == 0 ; 
    }


    bool isfull()
    {
        return length == max_size ;
    }





    void push(t element)
    {
        if (isfull() == 1)
            cout << "queue is full ";
        else
        {
            back = (back + 1) % max_size; 
            item[back] = element;
            length++;
        }
    }




    void pop()
    {
        if (isempty() == 1)
            cout << "queue is empty ";
        else
        {
            front = (front + 1) % max_size; 
            length--;
        }
    }





    t get_front()
    {
        if (isempty() == 1)
            cout << "queue is empty ";
        else
            return item[front];

    }



    t get_back()
    {
        if (isempty() == 1)
            cout << "queue is empty ";
        else
            return item[back];
    }



    int size()
    {
        return length;
    }

    void display()
    {
        if (isempty())
            cout << "queue is empty";
         else
        {
            
            for (int i = front; i!=back   ; i = (i + 1) % max_size)
            {
                cout << item[i] << "  ";
                
            }
            cout << item[back];
        }
    }
};
int main()
{
    queue<int> q; 
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    cout << "length : " << q.size()<<"\n";
    q.display();

    cout << "\n ====================== \n";
    cout << "front : " << q.get_front() << endl;
    cout << "back : " << q.get_back() << endl;
    cout << "\n ====================== \n";
    q.pop();
    cout << "front : " << q.get_front() << endl;
    cout << "back : " << q.get_back() << endl;
    cout << "\n ====================== \n";
    q.display();
     
    cout << "\n ====================== \n";
    q.push(333);
    q.display();
    cout << "\n ====================== \n";
    cout << "front : " << q.get_front() << endl;
    cout << "back : " << q.get_back() << endl;
    cout << "\n ====================== \n";
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.display();
    cout << "\n ====================== \n";
    cout << "front : " << q.get_front() << endl;
    cout << "back : " << q.get_back() << endl;
    cout << "length : " << q.size();
    return 0;
}
*/
 



























/*
// dynamic array_queue 
 
#include <iostream>
using namespace std;
//const int max_size = 10;

template <class t>

class queue
{
private:
    int back=0;
    int front=0;
    int length=0;
    int max_size=0;
    t *item;

public:

    queue(int size=0)
    {
        if (size <= 0)
            max_size = 100;
        else
            max_size = size;
  
        item = new int[max_size]; 
        back = max_size -1;
        front = 0;
        length = 0;
    }

    bool isempty()
    {
        return length == 0 ;
    }


    bool isfull()
    {
        return length == max_size ;
    }





    void push(t element)
    {
        if (isfull() == 1)
            cout << "queue is full  =>  not add : " << element << endl;
        else
        {
            back = (back + 1) % max_size;
            item[back] = element;
            length++;
        }
    }




    void pop()
    {
        if (isempty() == 1)
            cout << "queue is empty ";
        else
        {
            front = (front + 1) % max_size;
            length--;
        }
    }





    t get_front()
    {
        if (isempty() == 1)
            cout << "queue is empty ";
        else
            return item[front];

    }



    t get_back()
    {
        if (isempty() == 1)
            cout << "queue is empty ";
        else
            return item[back];
    }



    int size()
    {
        return length;
    }

    void display()
    {
        if (isempty())
            cout << "queue is empty";
         else
        {

            for (int i = front; i!=back   ; i = (i + 1) % max_size)
            {
                cout << item[i] << "  ";

            }
            cout << item[back];
        }
    }



    int search(t element)
    {
        if (isempty() == 1)
            cout << "queue is empty \n";
        else
        {
            int pos = -1;
            for (int i = front; i != back; i = (i + 1) % max_size)
            {
                if (item[i] == element)
                {
                    return i;
                    pos=0;
                    break; 
                }
            }
            if (pos == -1 && item[back]==element)
            {
                return back; 
            }

        }
    }
};

int main()
{
    queue<int>q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    
    cout << "length: " << q.size() << endl;
    q.display();
    q.pop();
    q.push(70);
    cout << "\n==========================\n";
    cout<<"position 30 : " << q.search(30) << endl; //2
    cout << "position 70 : " << q.search(70); //0
    return 0;
}
*/




































/*
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
    *//*





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
}*/