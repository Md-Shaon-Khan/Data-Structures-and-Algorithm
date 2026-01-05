#include<bits/stdc++.h>
using namespace std;

bool sequentialSearch(const vector<int>& arr, int key) {
    for (int x : arr)
        if (x == key)
            return true;
    return false;
}

bool binarySearchCustom(const vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return true;
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main() {
    vector<pair<int,int>> orders = {
        {1012, 3}, {1005, 1}, {1020, 4}, {1001, 2}, {1018, 1},
        {1008, 3}, {1004, 5}, {1024, 1}, {1010, 2}, {1002, 3},
        {1019, 2}, {1003, 1}, {1006, 3}, {1011, 2}, {1023, 1},
        {1021, 4}, {1007, 1}, {1013, 2}, {1022, 1}, {1014, 3},
        {1016, 2}, {1009, 5}, {1015, 1}, {1017, 4}, {1025, 2}
    };

    vector<int> orderIDs;
    for (auto &o : orders)
        orderIDs.push_back(o.first);

    int searchID;
    cout << "Enter Order ID to search for discount: ";
    cin >> searchID;

    bool foundSeq = sequentialSearch(orderIDs, searchID);

    sort(orderIDs.begin(), orderIDs.end());
    bool foundBin = binarySearchCustom(orderIDs, searchID);

    cout << "\nSequential Search: "
         << (foundSeq ? "Order Found" : "Order Not Found") << "\n";

    cout << "Binary Search: "
         << (foundBin ? "Order Found" : "Order Not Found") << "\n";

    return 0;
}
