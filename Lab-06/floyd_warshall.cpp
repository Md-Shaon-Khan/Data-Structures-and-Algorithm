#include <bits/stdc++.h>
using namespace std;

void floydWarshall(int n, vector<vector<int>>& graph) {
    vector<vector<int>> dp = graph;

    cout << "DP table size is " << n << " x " << n << "\n";
    cout << "Initially, dp[i][j] = weight of edge i->j or INF if no edge\n";

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    cout << "Shortest distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter adjacency matrix (use -1 for no edge):\n";

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            cin >> w;
            if (w == -1)
                graph[i][j] = INT_MAX;
            else
                graph[i][j] = w;
        }
    }

    floydWarshall(n, graph);
    return 0;
}
