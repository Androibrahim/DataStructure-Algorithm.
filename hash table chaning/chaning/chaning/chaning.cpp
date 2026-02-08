 
//hash table chaning

#include <iostream>
#include<list>
using namespace std;

class HashTable
{
private:
    int size = 10;
    list<int>* arr = new list<int>[size];
public:
    HashTable()
    {
        for (int i = 0; i < size; i++)
            arr[i].clear();
    }

    int hash_fun(int element)
    {
        int index = element % size;
        return index;
    }
    void insert(int element)
    {
        arr[hash_fun(element)].push_back(element);
    }


    void search(int element)
    {
        list<int>::iterator it;
        int x = hash_fun(element);
        int i = 0;   bool flag = true;
        for (it = arr[x].begin(); it != arr[x].end(); it++)
        {
            if (*it == element)
            {
                cout << "found in packet : " << x << " in node  ->  " << i<<"\n";
                flag = false;
                break;
            }
            i++;
        }
        if (flag == true) cout << "not found \n";
    }


    void print_hash_table()
    {
        list<int>::iterator it;
        for (int i = 0; i < size; i++)
        {
            cout << i << " --> ";
            for (it = arr[i].begin() ; it!= arr[i].end(); it++)
            {
                cout << *it << "  ";
            }
            cout << endl;
        }
    }
};
    
int main()
{
    class HashTable T;
    T.insert(8);
    T.insert(3);
    T.insert(13);
    T.insert(23);
    T.insert(4);
    T.insert(7);
    T.insert(17);
    

    T.print_hash_table();

    cout << endl;
    T.search(23);
    return 0; 
}


















/*
#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main()
{
    int size = 10;
    list<int>  arr[3]  ;
    arr[2].clear();
    
    arr[0].push_back(10);
    arr[0].push_back(2);

    arr[1].push_back(9);
    arr[1].push_back(9);

    list<int>::iterator it ;

    for (int i = 0; i < 2; i++)
    {
        cout << i << "-> ";
        for (it = arr[i].begin(); it != arr[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }

    
    it = arr[2].begin();
    cout << (*it == NULL);
    return 0;
}
 */