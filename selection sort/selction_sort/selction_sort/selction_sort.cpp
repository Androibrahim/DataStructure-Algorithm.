 
#include <iostream>
//#include<algorithm>
using namespace std;

void selection_sort(int arr[], int size)
{
    int min_index = 0;
    for (int i = 0; i < size; i++)
    {
        min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}


void print_selection_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
}
int main()
{
    int array[] = { 50, 20, 60, 10, 30 , -5 };
    int size_arr = size(array);
    selection_sort(array, size_arr);
    print_selection_sort(array, size_arr);
    return 0;
}

 