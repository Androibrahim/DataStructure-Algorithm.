// binary search iteration.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
// sorted array
int binary_search(int arr[], int first, int last , int element)
{
    int mid = 0;
    while (first <= last)
    {
        mid = (first + last) / 2;
        if (arr[mid] == element)
            return mid;
        else if (arr[mid] > element)
            last = mid - 1;       
        else
            first = mid+1;
    }
    return -1;
}

int main()
{
    int arr[] = { 1,2,3,4,5,6};
    int size_arr = size(arr);
     
    int result = binary_search(arr, 0, size_arr-1 ,4);
    if (result!=-1)
        cout << "found element  : " << arr[result] << "  in index : " << result << " \n";
    else
        cout << "not found\n";
}
 