#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int index = start - 1;

    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            index++;
            swap(arr[index], arr[j]);
        }
    }
    swap(arr[index + 1], arr[end]);
    return index + 1;
}

void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int pivotIndex = partition(arr, start, end);
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int best[]    = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int average[] = {12, 5, 18, 7, 3, 16, 1, 10, 20, 9,14, 2, 19, 6, 11, 4, 13, 8, 17, 15};
    int worst[]   = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11,10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    int n = sizeof(best) / sizeof(best[0]);

    
    auto start1 = high_resolution_clock::now();
    quickSort(best, 0, n - 1);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1);
    cout << "Best Case (Already Sorted):" << endl;
    display(best, n);
    cout << "Time taken: " << duration1.count() << " microseconds\n\n";

    
    auto start2 = high_resolution_clock::now();
    quickSort(average, 0, n - 1);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2);
    cout << "Average Case (Random Order):" << endl;
    display(average, n);
    cout << "Time taken: " << duration2.count() << " microseconds\n\n";

    
    auto start3 = high_resolution_clock::now();
    quickSort(worst, 0, n - 1);
    auto end3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(end3 - start3);
    cout << "Worst Case (Reverse Sorted):" << endl;
    display(worst, n);
    cout << "Time taken: " << duration3.count() << " microseconds\n";

    return 0;
}
