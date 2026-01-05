#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, int n, vector<int>& weights, vector<int>& values) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int W, n;
    cout << "Enter the maximum weight capacity of the drone: ";
    cin >> W;
    cout << "Enter the number of rock samples: ";
    cin >> n;

    vector<int> weights(n), values(n);

    cout << "Enter the weights of the rocks separated by space:\n";
    for (int i = 0; i < n; i++) cin >> weights[i];

    cout << "Enter the scientific values of the rocks separated by space:\n";
    for (int i = 0; i < n; i++) cin >> values[i];

    int maxValue = knapsack(W, n, weights, values);
    cout << "Maximum scientific value achievable: " << maxValue << endl;

    return 0;
}