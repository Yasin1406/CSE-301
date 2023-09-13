#include<bits/stdc++.h>
using namespace std;

void read_input();
void initialize(string source);
void relaxation(int u,int v);
void dijkstra(string source);
void print_graph();
void print_distance();

typedef struct node{
    string dest;
    int weight;
};
int w[100][100],vertex_num,edge_num,dis[100],pre[100];
map<string,int> vertices;
int main(){
    freopen("input.txt","r",stdin);
    read_input();
    print_graph();
    dijkstra("Dhaka");
    print_distance();
    return 0;
}

void read_input(){
    cin>>vertex_num>>edge_num;
    string s,u,v;
    for(int i=0;i<vertex_num;i++){
        cin>>s;
        vertices[s]=i;
    }
    for(int i=0;i<edge_num;i++){
        cin>>u>>v;
        cin>>w[vertices[u]][vertices[v]];
    }
}

void initialize(string source){
    for(int i=0;i<vertex_num;i++){
        dis[i]=INT_MAX;
        pre[i]=-1;
    }
    dis[vertices[source]]=0;

}

void relaxation(int u,int v){
    if(dis[v]>dis[u]+w[u][v]){
        dis[v]=dis[u]+w[u][v];
        pre[v]=u;
    }
}

// void dijkstra(string source){
//     initialize(source);
//     priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int,string>>>q;
//     for(auto x:vertices){
//         q.push({w[vertices[source]][x.second], x.first});
//     }
//     while(!q.empty()){
//         int u=vertices[q.top().second];
//         q.pop();
//         for(int v=0;v<vertex_num;v++){
//             if(w[u][v]>0){
//                 relaxation(u,v);
//             }
//         }
//     }
// }

void dijkstra(string source){

}

void print_graph(){
    for(int i=0;i<vertex_num;i++){
        for(int j=0;j<vertex_num;j++){
            cout<<w[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void print_distance(){
    for(int i=0;i<vertex_num;i++){
        cout<<dis[i]<<endl;
    }
}