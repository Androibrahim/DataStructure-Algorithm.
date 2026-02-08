 
/*
#include <iostream>
using namespace std;


template<class t>
class array_list
{
private:

    int* arr;
    int max_size;
    int length = 0;
public:
    array_list(int size = 0 )
    {
        if (size <= 0)
            max_size = 10;
        else
            max_size = size;

        arr = new int[max_size];
        length = 0;
    }


    bool isempty()
    {
        return length == 0;
    }

    bool isfull()
    {
        return length == max_size;
    }


    int size()
    {
        return length;
    }





    void insert_at( int pos ,t element)
    {
        if (isfull()) cout << "array is full... \n";
        else if (pos < 0 || pos > length)
            cout << pos <<" : out of range... \n";
        else
        {
            for (int i = length; i > pos; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[pos] = element;
            length++;
        }
    }








    void remove_at(int pos)
    {
        if (isempty())cout << "array is empty... \n";
        else if (pos < 0 || pos >= length)
            cout << pos << " : out of range \n";
        else
        {
            for (int i = pos; i < length ; i++)
            {
                arr[i] = arr[i + 1];
            }
            length--;
        }
    }






    void insert_end(t element)
    {
        if (isfull())cout << "array is full cant add  : " << element << endl;
        else
        {
            arr[length] = element;
            length++;
        }
    }





    int search(t element)
    {
        if (isempty())cout << "array is empty \n";
        else
        {
            for (int i = 0; i < length; i++)
            {
                
                if (arr[i] == element)
                    return i;
            }
            return 0;
        }
    }






    void insert_non_doublicated(t element)
    {
        if (isfull())cout << "array is full \n";
        else
        {
            if (search(element) == 0)
            {
                arr[length] = element;
                length++;
            }
            else
                cout<<element << "  : not add is are exist \n";
        }
    }





    void update(int pos, t element)
    {
        if (isempty())cout << "array is empty \n";
        else
            arr[pos] = element;
    }





    t get_element(int pos)
    {
        if (isempty())cout << "array is empty \n";
        else
        return arr[pos];
    }




    void print()
    {
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }



    void clear()
    {
        length = 0;
    }

    ~array_list()
    {
        length = 0;
        delete[]arr;
        cout << "\ndelete arry \n";
    }
};
int main()
{

    array_list<int> l(10);
    l.insert_end(10);
    l.insert_end(20);
    l.insert_end(30);
    l.insert_end(40);
    l.insert_end(50);
    l.insert_end(60);


    l.remove_at(2);
    cout << l.get_element(2) << endl;
    cout << "array size is : " << l.size() << endl;
    l.print();

    cout << "\n =============================\n";

    l.insert_at(2, 15);
    l.print();
    cout << "\narray size is : " << l.size() << endl;

    cout<<l.search(15)<<endl;

    l.insert_non_doublicated(50);
    l.insert_non_doublicated(70);
    cout << "\narray size is : " << l.size() << endl;
    l.insert_end(20);
    l.update(0, 11);
    cout << "\narray size is : " << l.size() << endl;
    l.print();
    l.insert_end(22);
    l.insert_end(24);
    l.insert_end(44);
    cout << "\n ========================\n";
    l.print();
    cout << "array size is : " << l.size() << endl;
    cout << "array is full ?  = " << l.isfull();
    cout << "\n ========================\n";
    
    l.clear();
    l.print();
   cout<< l.size();

   // l.~array_list(); // manual deleted 
    
    return 0; 
}
*/
 