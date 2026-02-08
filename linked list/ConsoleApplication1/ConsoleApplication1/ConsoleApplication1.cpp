 
/*
#include <iostream>
using namespace std;
template<class t>

class linked_list
{
private:
    struct node
    {
        t item; 
        node* next; 
    };
    node* head=NULL;
    node* tail=NULL;
    int length = 0;
public:
    linked_list()
    {
        head = tail = NULL;
        length = 0; 
    }




    bool isempty()
    {
        return length == 0;
    }




    void insert_first(t element)
    {
        node* newnode = new node;
        newnode->item = element;
        if (length == 0)
        {
            head = tail = newnode;
            newnode->next = NULL;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
        length++;
    }





    void insert_end(t element)
    {
        node* newnode = new node;
        newnode->item = element;
        if (length == 0)
        {
            head = tail = newnode;
            newnode->next = NULL;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
            newnode->next = NULL;
        }
        length++;
    }








    void insert_at_position(int pos, t element)
    {
        if (pos <0 || pos > length)
            cout << "out of range..\n";
        else
        {
            node* newnode = new node;
            newnode->item = element;
            if (pos == 0)
                insert_first(element);
            else if (pos == length)
                insert_end(element);
            else
            {
                node* cur = head;
                for (int i = 1; i < pos; i++)
                    cur = cur->next; 
                newnode->next = cur->next;
                cur->next = newnode;
            }
            length++;
        }
    }









    void display()
    {
        if (length == 0)
            cout << "linked_lis is empty..\n";
        else
        {
            node* cur = head;
            while (cur != NULL)
            {
                cout << cur->item << " ";
                cur = cur->next;
            }
        }
    }









    void erase_first()
    {
        if (length == 0)
            cout << "empty list \n";
        else
        {
            if (length == 1)
                head = tail = NULL;
            else
            {
                node* temp = head;
                head = head->next;
                delete temp;
            }
            length--;
        }
    }










    void erase_end()
    {
        if (length == 0)
            cout << "empty list..\n";
        else
        {
            if (length == 1)
                head = tail = NULL;
            else
            {
                node* cur =head->next ;
                node* pre = head;
                while (cur != tail)
                {
                    pre = cur;
                    cur = cur->next;
                }
                delete cur;
                pre->next = NULL;
                tail = pre;
            }
            length--;
        }
    }









    void erase_element(t element)
    {
        if (length == 0)
            cout << "empty list..\n";
        else
        {
            node* pre;
            node* cur;
            if (head->item == element && length ==1)
            {
                delete head; 
                head = tail = NULL;
                length--;
            }
            else if (head->item == element)
            {
                cur = head;
                head = head->next;
                delete cur;
                length--;
            }
            else if (tail->item == element)
            {
                erase_end();
            }
            else
            {
                cur = head->next;
                pre = head;
                while (cur != tail)
                {
                    if (cur->item == element) break;
                    pre = cur;
                    cur = cur->next;
                }
                if (cur == tail)
                    cout << "not fond..\n";
                else
                {
                    pre ->next = cur->next;
                    delete cur;
                    length--;
                }
            }
           
        }
    }












    void remove_postion(int pos)
    {
        
        if (isempty())cout << "list is empty\n";
        else if (pos <0 || pos>=length) cout << "out of range\n";     
        else
        {
            node* cur;
            node* pre;
            if (pos == 0)
                erase_first();
            else if (pos + 1 == length)
                erase_end();
            else
            {
                cur = head->next;
                pre = head;
                for (int i = 1; i < pos; i++)
                {
                    pre = cur;
                    cur = cur->next;
                }
                pre->next = cur->next;
                delete cur;
                length--;
            }
             
        }
    }








    void reverse()
    {
        if (isempty())cout << "list is empty \n";
        else
        {
            node* cur = head;
            node* pre = NULL;
            node* next = cur->next;
            while (cur != NULL)
            {
               next = cur->next;
               cur->next = pre;
               pre = cur;
               cur = next;
            }
            head = pre;
        }
    }









    int search(t element)
    {
        if (isempty())cout << "list is empty \n";
        else
        {
            node* cur = head;
            int pos = 0;
            while (cur != NULL)
            {
                if (cur->item == element)
                    return pos;
                    cur = cur->next;
                    pos++;     
            }
            return -1;
        }
    }


};
int main()
{

    linked_list<int>l;
    l.insert_first(10);
    l.insert_first(20);
    l.insert_first(30);
    l.display();
    cout << "\n===================\n";
    linked_list<int>l1;
    l1.insert_end(10);
    l1.insert_end(20);
    l1.insert_end(30);
    l1.display();
    cout << "\n===================\n";
    l1.insert_at_position(2, 25);
    l1.display();




    cout << "\n===================\n\n";
    linked_list<int>l2;
    l2.insert_first(10);
    l2.insert_end(30);
    l2.insert_end(40);
    l2.insert_at_position(1, 20);
    l2.insert_first(0);
    l2.insert_end(50);

    l2.erase_first();
    l2.erase_end();
    l2.erase_element(30);
    l2.erase_element(10);
    l2.erase_element(40);
   // l2.erase_element(20);

    l2.display();


    cout << "\n ===============================\n";
    linked_list<int>l3;
    l3.insert_first(10);
    l3.insert_end(30);
    l3.insert_end(40);
    l3.insert_at_position(1, 20);
    l3.insert_first(0);
    l3.insert_end(50);
    
    // remove_postion     // 0  10 20 30 40 50
    l3.remove_postion(0); // 10 20 30 40 50
    l3.remove_postion(1); // 10 30 40 50
    l3.remove_postion(2); // 10 30 50
    l3.remove_postion(2); // 10 30

    l3.display();




    cout << "\n ===============================\n";
    linked_list<int>l4;
    l4.insert_first(10);
    l4.insert_end(30);
    l4.insert_end(40);
    l4.insert_at_position(1, 20);
    l4.insert_first(0);
    l4.insert_end(50);

    l4.display();
    l4.reverse(); cout <<endl;
    l4.display();

    cout << "\n =====\n";
    cout<<  l4.search(20);




    return 0;
}
*/
 