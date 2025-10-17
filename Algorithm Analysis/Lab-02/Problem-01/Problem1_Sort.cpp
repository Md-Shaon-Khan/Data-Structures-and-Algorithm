#include <bits/stdc++.h>
using namespace std;

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bubble sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void printArray(const vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
    cout << "\n";
}

int main() {
    vector<pair<int,int>> orders = {
        {1012, 3}, {1005, 1}, {1020, 4}, {1001, 2}, {1018, 1},
        {1008, 3}, {1004, 5}, {1024, 1}, {1010, 2}, {1002, 3},
        {1019, 2}, {1003, 1}, {1006, 3}, {1011, 2}, {1023, 1},
        {1021, 4}, {1007, 1}, {1013, 2}, {1022, 1}, {1014, 3},
        {1016, 2}, {1009, 5}, {1015, 1}, {1017, 4}, {1025, 2}
    };

    vector<int> arr1, arr2, arr3;
    for (auto &o : orders) { //Inserted only first value which is Order_Id 
        arr1.push_back(o.first);
        arr2.push_back(o.first);
        arr3.push_back(o.first);
    }

    selectionSort(arr1);
    insertionSort(arr2);
    bubbleSort(arr3);

    cout << "Selection Sort Order IDs:\n"; printArray(arr1);
    cout << "Insertion Sort Order IDs:\n"; printArray(arr2);
    cout << "Bubble Sort Order IDs:\n"; printArray(arr3);

    return 0;
}