#include<bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(string &x1, string &x2){
    int m = x1.size();
    int n = x2.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x1[i-1] == x2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    int i = m, j = n;
    string lcs = "";
    while(i > 0 && j > 0){
        if(x1[i-1] == x2[j-1]){
            lcs += x1[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string X, Y;
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    string lcs = longestCommonSubsequence(X, Y);
    cout << "Length of Longest Common Subsequence: " << lcs.size() << endl;
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
