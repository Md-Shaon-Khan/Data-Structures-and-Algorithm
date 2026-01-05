#include<bits/stdc++.h>
using namespace std;

const int MAX_VERTICES = 10;
const int MAX_EDGES = 20;

struct Edge{
   int u,v,weight;
};

class KruskalMST{
        int parent[MAX_VERTICES];
        Edge edges[MAX_EDGES];
        int vertices,totalEdges;

    public:
        KruskalMST(int v,int e){
            vertices = v;
            totalEdges = e;
       }

       void inputEdges(){
            cout<<"Enter edges (u,v,weight): "<<endl;
            for(int i=0;i<totalEdges;i++){
                cin>>edges[i].u>>edges[i].v>>edges[i].weight;
            }
       }

       void sortEdges(){
            for(int i=0;i<totalEdges-1;i++){
                for (int j = 0; j < totalEdges - i - 1; j++) {
                    if (edges[j].weight > edges[j + 1].weight) {
                        Edge temp = edges[j];
                        edges[j] = edges[j + 1];
                        edges[j + 1] = temp;
                    }
                }
            }
       }

       int find(int vertex){
            if(parent[vertex] == -1)
                return vertex;
            return find(parent[vertex]);
       }

       void unionSet(int u,int v){
            int setU = find(u);
            int setV = find(v);
            if(setU != setV){
                parent[setU] = setV;
            }
       }

       void buildMST(){
            for(int i=0;i<vertices;i++){
                parent[i] = -1;
            }
            
            sortEdges();

            int mstWeight = 0;

            cout<<"\nEdges in Minimum Spanning Tree:\n";

            int edgeCount = 0;
            for(int i=0;i<totalEdges && edgeCount<vertices-1;i++){
                int u = edges[i].u;
                int v = edges[i].v;
                int w = edges[i].weight;

                if(find(u) != find(v)){
                    cout<<u<<" - "<<" : "<<w<<endl;
                    mstWeight += w;
                    unionSet(u,v);
                    edgeCount++;
                }
            }

            cout<<"Total weight of MST: "<<mstWeight<<endl;
       }

};

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    KruskalMST mst(v, e);
    mst.inputEdges();
    mst.buildMST();

    return 0;
}