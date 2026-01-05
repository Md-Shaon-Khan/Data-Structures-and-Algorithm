#include <bits/stdc++.h>
using namespace std;

bool canColor(int v, vector<vector<int>> &graph, // Can we give color 'c' to vertex 'v' ?
              vector<int> &color, int c) {

    for (int i = 0; i < graph.size(); i++) {            // Check all vertices connected to v
        if (graph[v][i] == 1 && color[i] == c) {        // If there is an edge AND that vertex has same color
            return false;   // cannot color
        }
    }

    return true; // safe to color
}

bool solve(int v, vector<vector<int>> &graph,   // Backtracking function to color graph
           int M, vector<int> &color) {

    if (v == graph.size()) {  // If all vertices are colored
        return true;  // solution found
    }

    for (int c = 1; c <= M; c++) {  // Try all colors from 1 to M
 
        if (canColor(v, graph, color, c)) {   // Check if color c can be used for vertex v
            color[v] = c;  // Choose color
            if (solve(v + 1, graph, M, color)) { // Move to next vertex
                return true;
            }
            color[v] = 0;             // Backtrack (remove color)
        }
    }
    return false;    // No color works for this vertex
}

int main() {

    int V = 4;    // number of vertices
    int M = 3;    // number of colors

    vector<vector<int>> graph = {     // Adjacency matrix of graph
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };

    vector<int> color(V, 0);     // Color array (0 means no color)

    if (solve(0, graph, M, color)) {    // Start coloring from vertex 0
        cout << "Solution exists:\n";
        for (int i = 0; i < V; i++) {    // Print color of each vertex
            cout << "Vertex " << i << " -> Color " << color[i] << endl;
        }
    } 
    else {
        cout << "No solution possible\n";
    }

    return 0;
}
