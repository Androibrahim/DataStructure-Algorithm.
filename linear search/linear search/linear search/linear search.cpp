// linear search.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
using namespace std;

int linear_search(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
            return i;
    }
    return 0;
}
int main()
{
    int arr[] = { 1,2,3,4,5,6 };
    int s_arr = size(arr);
    int num = 3; 
    int r= linear_search(arr, s_arr, num);
    if (r)cout << " found : " << arr[r]<<"   -in index "<<r;
    else
       cout << "not found \n";
}

 