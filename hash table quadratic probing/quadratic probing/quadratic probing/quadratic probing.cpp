 

#include <iostream>
using namespace std;

class hash_table
{
private:
    int size = 7;
    int* arr = new int[size];
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
        if (arr[index] == NULL)
            return index;
             
        else
        {  
            for (int i = 1;  i<size ; i++)
            {
                int new_index = (index + i * i) % size;
                if (arr[new_index] == NULL)
                    return new_index;        
            }
        }
    }

    void insertion(int element)
    {
        if (is_full() == 1)
            cout << "table is full can not insert the last element : " << element << "\n";
        else
            arr[hash_fun(element)] = element;
    }


    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << "  ";
    }
};
int main()
{
    hash_table T;
    T.insertion(50);
    T.insertion(700);
    T.insertion(76);
    T.insertion(85);
    T.insertion(92);
    T.insertion(73);
    T.insertion(101);
   
    T.print();
    return 0;
}

 