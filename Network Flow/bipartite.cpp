#include<bits/stdc++.h>
using namespace std;

int graph[50][50],vertex_num,edge_num;

void read_input();

int main(){
    freopen("bi.txt","r",stdin);
    read_input();
    for(int i=1;i<=vertex_num;i++){
        for(int j=1;j<=vertex_num;j++){
            printf("%7d ",graph[i][j]);
        }
        cout<<endl;
    }
    return 0;
}

void read_input(){
    cin>>vertex_num>>edge_num;
    int u,v;
    for(int i=0;i<edge_num;i++){
        cin>>u>>v;
        graph[u][v]=1;
    }
}