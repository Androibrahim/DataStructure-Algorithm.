// heap sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void heapify(int arr[], int size, int position)
{
    int  left = (position * 2 ) + 1;
    int right = (position * 2 ) + 2;

    int max = position;

    if (left < size && arr[left] >  arr[max])
        max = left;
    if (right < size && arr[right] > arr[max])
        max = right;

    if (max != position)
    {
        swap(arr[position], arr[max]);
        heapify(arr, size, max);
    }
}


void build_heap(int arr[], int size)
{
    int position = (size / 2) - 1;

    for (int i = position; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
}


void heap_sort(int arr[], int size)
{
    build_heap(arr, size);
    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);      
        build_heap(arr, i);  // or heapify(arr, i, 0);
    }
}
int main()
{

    /*int arr[] = { 2,3,5,5,4,1,6 };*/
    int arr[] = { 5,12,10,4,6 };
    int s = size(arr);

    heap_sort(arr, s);

    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";

    return 0;
}
 