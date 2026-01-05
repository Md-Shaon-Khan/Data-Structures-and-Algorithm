#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void merge(int arr[], int start, int mid, int end) {
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int left[len1], right[len2];

    for (int i = 0; i < len1; i++) 
        left[i] = arr[start + i];

    for (int j = 0; j < len2; j++) 
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;

    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) 
           arr[k++] = left[i++];
        else 
           arr[k++] = right[j++];
    }

    while (i < len1) 
       arr[k++] = left[i++];

    while (j < len2) 
       arr[k++] = right[j++];
}

void mergeSort(int arr[], int start, int end) {
    if (start >= end) 
       return;

    int mid = start + (end - start) / 2;
    
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) 
       cout << arr[i] << " ";
       
    cout << endl;
}

int main() {
    int arr1[] = {1, 5, 8, 12, 15, 18, 21, 25, 28, 30, 33, 35, 38, 40, 42, 45, 47, 49, 52, 55};
    int arr2[] = {12, 31, 35, 8, 32, 17, 5, 44, 9, 28, 40, 21, 30, 15, 7, 50, 19, 11, 46, 3};
    int arr3[] = {60, 58, 55, 52, 49, 45, 42, 38, 35, 33, 30, 28, 25, 21, 18, 15, 12, 8, 5, 1};

    int n = 20;

    
    auto start1 = high_resolution_clock::now();
    mergeSort(arr1, 0, n - 1);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1);
    cout << "Best Case (Already Sorted):" << endl;
    display(arr1, n);
    cout << "Time taken: " << duration1.count() << " microseconds\n\n";

    
    auto start2 = high_resolution_clock::now();
    mergeSort(arr2, 0, n - 1);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2);
    cout << "Average Case (Random Order):" << endl;
    display(arr2, n);
    cout << "Time taken: " << duration2.count() << " microseconds\n\n";

    
    auto start3 = high_resolution_clock::now();
    mergeSort(arr3, 0, n - 1);
    auto end3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(end3 - start3);
    cout << "Worst Case (Reverse Sorted):" << endl;
    display(arr3, n);
    cout << "Time taken: " << duration3.count() << " microseconds\n";

    return 0;
}
