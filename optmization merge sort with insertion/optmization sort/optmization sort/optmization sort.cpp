

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

const int INSERTION_THRESHOLD = 16; // Threshold for when to use Insertion Sort

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {

        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void insertion_sort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge_sort_v1(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_v1(arr, left, mid);
        merge_sort_v1(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
//
void merge_sort_v2(vector<int>& arr, int left, int right) {
    if (right - left + 1 <= INSERTION_THRESHOLD) { // Use Insertion Sort for smaller subarrays
        insertion_sort(arr, left, right);
        return;
    }
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_v2(arr, left, mid);
        merge_sort_v2(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {

    const int size = 1000000;
    //const int size = 10;
    vector<int> no_optimized(size);
    vector<int> no(size);

    for (int i = 0; i < size; i++)
    {
        //no[i]=i+1;
        no[i] = size - i;
        //no_optimized[i]=i+1;
        no_optimized[i] = size - i;
    }

    clock_t start_time = clock();
    merge_sort_v2(no_optimized, 0, size - 1);
    clock_t end_time = clock();
    clock_t result = end_time - start_time;
    cout << result << " milliseconds (with optimization)" << endl << endl;

    start_time = clock();
    merge_sort_v1(no, 0, size - 1);
    end_time = clock();
    result = end_time - start_time;
    cout << result << " milliseconds (without optimization)" << endl;


    //cout << "without" << " \t" << "with optimization" <<endl;
        //for (int i = 0; i < size; i++) {
        //    cout << no[i] << " \t\t" << no_optimized[i] <<endl;
        //}
}
