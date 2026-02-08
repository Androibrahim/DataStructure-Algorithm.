 

#include <iostream>
using namespace std;

template<class t>
class double_list
{
private:
    struct node
    {
        t item;
        node* next;
        node* prev;
    };
    node* first;
    node* last;
    int length;

public:
    double_list()
    {
        first = NULL;
        last = NULL;
        length = 0;
    }



    bool isempty()
    {
        return length == 0;
    }



    void push_front(t element)
    {
        node* newnode = new node;
        newnode->item = element;
        if (isempty())
        {
            first = last = newnode;
            newnode->next = NULL;
            newnode->prev = NULL;
        }
        else
        {
            newnode->next = first;
            newnode->prev = NULL;
            first->prev = newnode;
            first = newnode;
        }
        length++;
    }








    void push_back(t element)
    {
        node* newnode = new node;
        newnode->item = element;
        if (isempty())
        {
            first = last = newnode;
            newnode->next = NULL;
            newnode->prev = NULL;
        }
        else
        {
            newnode->next = NULL;
            newnode->prev = last;
            last->next = newnode;
            last = newnode;
        }
        length++;
    }









    void insert_at(int pos, t element)
    {
        if (pos < 0 || pos > length)
            cout << "Out of range!..\n";
        else
        {
            if (pos == 0)
                push_front(element);
            else if (pos == length)
                push_back(element);
            else
            {
                node* newnode = new node;
                newnode->item = element;
                node* cur = first;
                for (int i = 1; i < pos; i++)
                {
                    cur = cur->next;
                }
                newnode->prev = cur;
                newnode->next = cur->next;
                cur->next = newnode;
                cur = newnode;
                cur = cur->next;
                cur->prev = newnode;
                length++;
            }

        }
    }









    void remove_begin()
    {
        if (isempty())cout << "list is empty \n";
        else
        {
            if (length == 1)
            {
                delete first;
                first = last = NULL; 
            }
            else
            {
                node* cur = first;
                first = first->next;
                first->prev = NULL;
                delete cur;
            }
            length--;
        }
    }








    void remove_end()
    {
        if (isempty())cout << "list is empty \n";
        else
        {
            if (length == 1)
            {
                delete first;
                first = last = NULL;
            }
            else
            {
                node* cur = last;
                last = last->prev;
                last->next = NULL;
                delete cur;
            }
            length--;
        }
    }







    void remove_element(t element)
    {
        if (isempty())cout << "list is empty";
        else
        {
            if (first->item == element)
                remove_begin();
            else
            {
                node* cur = first->next;
                while (cur != NULL)
                {
                    if (cur->item == element) break;
                    cur = cur->next;
                }
                if (cur == NULL)
                    cout << "not found\n";
                else if (cur->next == NULL)
                     remove_end();
                else
                {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                    delete cur;
                    length--;
                }

            }
        }
    }



    void remove_at_pos(int pos)
    {
        if (isempty())cout << "list is empty \n";
        else
        {
            if (pos<0 || pos>=length)
                cout << "out of range\n";
            else if (pos == 0)
                remove_begin();
            else if (pos+1 == length)
                remove_end();
            else
            {
                node* cur = first->next;
                for (int i = 1; i < pos; i++)
                {
                    cur = cur->next;
                }
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                delete cur;
                length--;
            }
        }

    }



    void display()
    {
        node* cur = first;
        while (cur != NULL)
        {
            cout << cur->item << " ";
            cur = cur->next;
        }
    }





    void display_reverse()
    {
        cout << "reverse => ";
        node* cur = last;
        while (cur != NULL)
        {
            cout << cur->item << " ";
            cur = cur->prev;
        }
    }


    int size()
    {
        return length;
    }

};

int main()
{
    double_list<int> dl;
    dl.push_back(10);
    dl.push_back(20);
    dl.push_front(5);
    dl.push_front(0);

    dl.insert_at(3, 15);
    dl.display(); cout << endl;
    dl.display_reverse(); cout << endl;

    cout <<"size : " << dl.size();
    cout << "\n =======================\n";

    dl.remove_element(15);
    dl.remove_begin();
    dl.remove_end();
    dl.display(); cout << endl;
    cout << "size : " << dl.size();
    cout << "\n ======================\n";
    dl.push_back(30);
    dl.push_back(40);
    dl.push_back(70);

    dl.display(); cout << endl;
    cout << "size : " << dl.size();
    cout << "\n after delete\n";
    dl.remove_at_pos(2);

    dl.display();
    cout << "\nsize : " << dl.size();
    
    return 0;
}
 