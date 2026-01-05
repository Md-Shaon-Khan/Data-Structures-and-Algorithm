#include<bits/stdc++.h>
using namespace std;

bool canColor(int v,vector<vector<int>>&graph,vector<int>&color,int c){
    for (int i = 0; i < graph.size(); i++) {            // Check all vertices connected to v
        if (graph[v][i] == 1 && color[i] == c) {        // If there is an edge AND that vertex has same color
            return false;   // cannot color
        }
    }

    return true; // safe to color
}

bool solve(int vertex,vector<vector<int>>& graph,int M,vector<int>&color){
    if(vertex == graph.size()){
        return true;
    }

    for(int c=1;c<=M;c++){
        if(canColor(vertex,graph,color,c)){
            color[vertex] = c;
            if(solve(vertex+1,graph,M,color)){
                return true;
            }
            color[vertex] = 0; 
        }
    }
    return false;
}

int main(){
    int V = 4;
    int M = 3;

    vector<vector<int>> graph = {
        {0,1,1,0},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,0}
    };

    vector<int> color(V,0);

    if(solve(0,graph,M,color)){
        cout<<"Solution exists:\n";
        for(int i=0;i<V;i++){
            cout<<"Vertex "<<i<<" ->color "<<color[i]<<endl;
        }
    }
    else{
        cout<<"No solution exists.\n";
    }

    return 0;
}