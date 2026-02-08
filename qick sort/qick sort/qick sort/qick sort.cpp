 

#include <iostream>
using namespace std;

int partitioning(int arr[], int first, int last)
{
    int pivot = arr[first];
    int i = first;
    int j = last;

    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);

      
        while (arr[j] > pivot)
        {
            j--;
        }

        if(i<j) swap(arr[i], arr[j]);

    }

    swap(arr[first], arr[j]);
    return j;

}


void qick_sort(int arr[], int first, int last)
{
    if (first < last)
    {
        int pivot = partitioning(arr, first, last); //partitioning and sorting 
        qick_sort(arr, first, pivot - 1);
        qick_sort(arr, pivot + 1, last);
    }
}

int main()
{
    int arr[]{ 10,5,8,12,15,6,4,9,16,50,2 };
    int first = 0;
    int last = size(arr) - 1;
    qick_sort(arr, first, last);

    cout << "after qick sort is :";
    for (int i = 0; i <= last; i++)
        cout << arr[i] << "  ";

    return 0;
}



 