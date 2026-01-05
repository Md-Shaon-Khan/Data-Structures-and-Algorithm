#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end) {

    
    int len1 = mid - start + 1;
    int len2 = end - mid;

    
    int left[len1];
    int right[len2];

   
    for (int i = 0; i < len1; i++) {
        left[i] = arr[start + i];
    }
    for (int j = 0; j < len2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    
    int i = 0;
    int j = 0;  
    int k = start;  

    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

   
    while (i < len1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    
    while (j < len2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr[] = {12, 31, 35, 8, 32, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    display(arr, n);

    return 0;
}