 
#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size)
{
    bool flag = true;    int count_step = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = false;
            }
            count_step++;
        }
        if (flag == true)
            break;
    }
    cout << "count_step is " << count_step<<endl;
}


void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";
}
int main()
{
    int arr[] = { 2,4,3,0,1,6 } ;
    int n = size(arr);
    bubble_sort(arr, n);
    print(arr, n);
    return 0;
}

  
