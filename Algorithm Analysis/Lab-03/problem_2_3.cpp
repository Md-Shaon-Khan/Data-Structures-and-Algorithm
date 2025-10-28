#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;
const int INF = 1e9;

class Dijkstra {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int vertices;
    bool isDirected;

public:
    Dijkstra(int v, bool directed) {
        vertices = v;
        isDirected = directed;
        for (int i = 0; i < vertices; i++)
            for (int j = 0; j < vertices; j++)
                graph[i][j] = 0;
    }

    void inputEdges(int edges) {
        cout << "Enter edges (from to weight):\n";
        for (int i = 0; i < edges; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u][v] = w;
            if (!isDirected) {
                graph[v][u] = w;
            }
        }
    }

    int selectMinVertex(int dist[], bool visited[]) {
        int min = INF;
        int index = -1;

        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                index = i;
            }
        }
        return index;
    }

    void dijkstra(int src) {
        int dist[MAX_VERTICES];
        bool visited[MAX_VERTICES];

        for (int i = 0; i < vertices; i++) {
            dist[i] = INF;
            visited[i] = false;
        }

        dist[src] = 0;

        for (int count = 0; count < vertices - 1; count++) {
            int u = selectMinVertex(dist, visited);
            if (u == -1) break;
            visited[u] = true;

            for (int v = 0; v < vertices; v++) {
                if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < vertices; i++) {
            cout << "To " << i << " : " << (dist[i] == INF ? -1 : dist[i]) << endl;
        }
    }
};

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    char choice;
    cout << "Is the graph directed? (y/n): ";
    cin >> choice;
    bool isDirected = (choice == 'y' || choice == 'Y');

    Dijkstra d(v, isDirected);
    d.inputEdges(e);

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    d.dijkstra(src);

    return 0;
}