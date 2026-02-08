 
#include <iostream>
using namespace std;

void insertion_sort(int arr[], int size)
{
    int k=0 , j=0;

    for (int i = 1; i < size; i++)
    {
        k = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > k) // while (j >= 0 && arr[j] < k) insort desinding
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
    }    
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";
}
int main()
{
    int arr[] = { 4,5,3,1,2 };
    int n = size(arr);
    insertion_sort(arr, n);
    print(arr, n);
    return 0;
}

 