#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) 
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) 
        return mid;
    else if (arr[mid] > target) 
        return binarySearch(arr, left, mid - 1, target);
    else 
        return binarySearch(arr, mid + 1, right, target);

}

vector<int> findAllOccurrences(int arr[], int n, int target) {

    vector<int> indices;
    int index = binarySearch(arr, 0, n - 1, target);

    if (index == -1) 
        return indices;

    int left = index - 1;

    while (left >= 0 && arr[left] == target) {
        indices.push_back(left);
        left--;
    }

    indices.push_back(index);

    int right = index + 1;

    while (right < n && arr[right] == target) {
        indices.push_back(right);
        right++;
    }

    sort(indices.begin(), indices.end());

    return indices;
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void displayIndices(vector<int> indices) {
    if (indices.empty()) 
        cout << "Element not found." << endl;
    else {
        cout << "Element found at indices: ";
        for (int idx : indices) 
            cout << idx << " ";
        
        cout << endl;
    }
}

int main() {
    int arr[] = {9, 3, 2, 1, 9, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    displayArray(arr, n);

    sort(arr, arr + n);

    cout << "Sorted Array: ";
    displayArray(arr, n);

    int target = 2;
    cout << "Searching for element: " << target << endl;

    vector<int> occurrences = findAllOccurrences(arr, n, target);
    displayIndices(occurrences);

    return 0;
}
