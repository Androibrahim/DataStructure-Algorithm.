 
#include <iostream>
using namespace std;

class hash_table
{
private:
    int size=10;
    int *arr = new int[size];
public:
    hash_table()
    {   
        for (int i = 0; i < size; i++)
            arr[i] = NULL;
    }


    bool is_full()
    {    
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == NULL)
                return false;
        }
        return true;
    }

    int hash_fun(int element)
    {
        int index = element % size;
        if (arr[index]==NULL)
            return index;
        else
        {
           
            for (int i=index+1; i <= size; i++)
            {
                i = i % size;
                if (arr[i] == NULL)
                    return i;
            }
             
        }
    }
    void insertion(int element)
    {
        if (is_full() == false)
        {
            arr[hash_fun(element)] = element;
        }
        else
            cout << "array is full";
    }


    int searsh(int element)
    {
        int stop = (element % size)-1 ;
        for (int i = element % size; i <= size; i++)
        {
            i = i % size;
            if (arr[i] == element)
                return i;
            if (arr[i] == NULL)
                return -1;
            if (i == stop)
                return -1;
        }
    }

    void display(int index)
    {
        cout << arr[index];
    }
};
int main()
{
     
    hash_table ob1;
    ob1.insertion(3);
    ob1.insertion(13);
    ob1.insertion(9);
    ob1.insertion(12);
    ob1.insertion(117);
    ob1.insertion(15);
    ob1.insertion(3);
    ob1.insertion(13);
    ob1.insertion(5);
    

    ob1.display(8);

    cout << endl;
    int a = 117;
    if (ob1.searsh(a) != -1)
        cout << "found: " << a << " in index : " << ob1.searsh(117);
    else
        cout << a << " not found\n";
    
}

