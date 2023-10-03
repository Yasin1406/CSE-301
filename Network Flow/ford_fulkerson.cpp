#include<bits/stdc++.h>
using namespace std;
#define size 50
int graph[size][size],vertex_num,edge_num;
vector<int> path;
vector<bool> isVisited(size,false);

void read_input();
bool BFS(int source,int destination);

int main(){
    freopen("ford.txt","r",stdin);
    int i,j;
    read_input();
    
    
    return 0;
}

void read_input(){
    int i,j,u,v;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            graph[i][j]=INT_MAX;
        }
    }
    cin>>vertex_num>>edge_num;
    for(i=0;i<edge_num;i++){
        cin>>u>>v>>graph[u][v];
    }
}

bool BFS(int source,int destination){
    queue<int> q;
    q.push(source);
    isVisited[source]=true;
    while(!q.empty()){
        int v=q.back();
        q.pop();
        for(auto )
    }
}