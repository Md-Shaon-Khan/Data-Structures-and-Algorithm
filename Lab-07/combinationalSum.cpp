#include <bits/stdc++.h>
using namespace std;

void getAllCombinations(vector<int>& arr, int idx, int tar, vector<int>& combin, set<vector<int>>& s) {
    if (idx == arr.size() || tar < 0)                             //When to stop and here idx == arr.size() means we have considered all elements
       return;

    if (tar == 0) {
        s.insert(combin);                                         //Insert the current combination into the set
        return;
    }

    combin.push_back(arr[idx]);                                   // Include the current element in the combination
    getAllCombinations(arr, idx + 1, tar - arr[idx], combin, s); // Recur by moving to the next index after including the current element once
    getAllCombinations(arr, idx, tar - arr[idx], combin, s);     // Recur by staying at the same index to allow unlimited use of the current element
    combin.pop_back();                                            // Backtrack: remove the last added element before exploring other choices
    getAllCombinations(arr, idx + 1, tar, combin, s);            // Recur by excluding the current element and moving to the next index

}
int main() {
    vector<int> arr = {1, 2, 3};
    int target = 5;

    vector<int> combin;
    set<vector<int>> s;

    getAllCombinations(arr, 0, target, combin, s);

    cout << "All unique combinations that sum to " << target << ":\n";
    for (auto &v : s) {
        for (int i : v) cout << i << " ";
        cout << endl;
    }

    return 0;
}
