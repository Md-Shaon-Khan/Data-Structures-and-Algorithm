#include <bits/stdc++.h>
using namespace std;

int rodCutting(int m, int n,  vector<int>& price) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= j)
                dp[i][j] = max(price[i - 1] + dp[i][j - i], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[m][n];
}

int main() {
    int m, n;
    cout << "Enter the number of cut lengths (m) and rod length (n): ";
    cin >> m >> n;
    cout << "DP table size will be (m+1) x (n+1) with first row and first column as 0\n";

    vector<int> length(m), price(m);
    // cout << "Enter the cut lengths separated by space:\n";
    // for (int i = 0; i < m; i++) cin >> length[i];

    cout << "Enter the prices for each cut length separated by space:\n";
    for (int i = 0; i < m; i++) cin >> price[i];

    cout << "Maximum obtainable value: " << rodCutting(m, n, price);

    return 0;
}