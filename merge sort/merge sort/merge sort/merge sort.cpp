 

#include <iostream>
using namespace std;
// Merge two sorted subarrays [left, mid] and [mid+1, right]
void merge(int arr[], int left, int mid, int right)
{
    // Create size of temp arrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays
    int* l_arr = new int[n1];
    int* r_arr = new int[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        l_arr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        r_arr[i] = arr[mid + 1 + i];

    // Merge the temp arrays back into arr[left..right]
    int i = 0; int j = 0; int k = left;
    while (i < n1 && j < n2)
    {
        if (l_arr[i] < r_arr[j])
        {
            arr[k] = l_arr[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = r_arr[j];
            j++;
            k++;
        }
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = l_arr[i];
        i++;
        k++;
    }

    // Copy theremaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = r_arr[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        // Recursively sort first and second halves
        merge_sort(arr,left, mid);
        merge_sort(arr, mid + 1, right);
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}
int main()
{
    int arr[] = { 4,3,1,2 };
    int left = 0;
    int right = size(arr) - 1;
    merge_sort(arr, left, right);

    cout << "array after merge sort is : ";
    for (int i = 0; i <= right; i++)
        cout << arr[i] << "  ";

    
}
 