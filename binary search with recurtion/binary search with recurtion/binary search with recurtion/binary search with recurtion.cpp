

#include <iostream>
using namespace std;

int binary_search(int arr[], int left, int right, int target)
{
    if (left > right)
        return -1;


    int mid = (left + right) / 2;
    if (arr[mid] == target)
        return mid;

    if (target < arr[mid])
        binary_search(arr, left, mid - 1, target);
    else
        binary_search(arr, mid + 1, right, target);



}

int main()
{
    int arr[] = { 1,2,3,4,5 };
    int l = 0;
    int r = size(arr) - 1;
    int res = binary_search(arr, l, r, 3);

    if (res == -1)
        cout << "not found\n";
    else
        cout << "number " << arr[res] << " ->founded in index " << res;

    return 0;
}
