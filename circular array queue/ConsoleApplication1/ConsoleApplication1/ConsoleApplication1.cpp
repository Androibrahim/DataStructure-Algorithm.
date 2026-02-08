

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






