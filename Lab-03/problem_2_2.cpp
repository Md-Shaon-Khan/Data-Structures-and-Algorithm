#include <iostream>
using namespace std;

const int MAX_VERTICES = 10;
const int INF = 1e9;

class PrimMST {
    int adj[MAX_VERTICES][MAX_VERTICES];
    int vertices;

public:
    PrimMST(int v) {
        vertices = v;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void inputEdges(int edges) {
        for (int i = 0; i < edges; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u][v] = w;
            adj[v][u] = w;
        }
    }

    int selectMinKey(int key[], bool visited[]) {
        int min = INF, minIndex = -1;
        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    void buildMST() {
        int key[MAX_VERTICES];
        int parent[MAX_VERTICES];
        bool visited[MAX_VERTICES];

        for (int i = 0; i < vertices; i++) {
            key[i] = INF;
            visited[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < vertices - 1; count++) {
            int u = selectMinKey(key, visited);
            visited[u] = true;

            for (int v = 0; v < vertices; v++) {
                if (adj[u][v] && !visited[v] && adj[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adj[u][v];
                }
            }
        }

        int totalWeight = 0;
        for (int i = 1; i < vertices; i++) {
            cout << parent[i] << " - " << i << " : " << adj[i][parent[i]] << endl;
            totalWeight += adj[i][parent[i]];
        }
        cout << "Total weight of MST: " << totalWeight << endl;
    }
};

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    PrimMST mst(v);
    cout << "Enter edges (u v weight):" << endl;
    mst.inputEdges(e);
    cout << "\nEdges in MST:\n";
    mst.buildMST();

    return 0;
}