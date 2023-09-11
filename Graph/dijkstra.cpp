#include<bits/stdc++.h>
using namespace std;
void initialize(int source);
void relax(int u,int v);
void dijkstra(int source);
int extract_min();
void printGraph();
void readInput();
void print_path(int v);
int graph[100][100],vertices=0,edges,dis[100],previous[100],w[100][100];
string names[100];
bool flag[100];
int main(){
    // cout<<"Enter number of vertices and edges: ";
    // cin>>vertices>>edges;
    // int i,j,k;
    // for(i=0;i<vertices;i++){
    //     for(j=0;j<vertices;j++){
    //         cin>>graph[i][j];
    //     }
    // }
    freopen("dijkstra_input.txt","r",stdin);
    readInput();
    printGraph();
    dijkstra(0);
    cout<<endl;
    return 0;
}
void initialize(int source){
    int i,j;
    for(i=0;i<vertices;i++){
        dis[i]=INT_MAX;
        previous[i]=-1;
    }
    dis[source]=0;
}
void relax(int u,int v){
    if(dis[v]>dis[u]+w[u][v]){
        dis[v]=dis[u]+w[u][v];
        previous[v]=u;
    }
}
void dijkstra(int source){
    int i,j,k,u,v;
    initialize(source);
    for(i=0;i<vertices;i++){
        flag[i]=true;
    }
    int queueSize=vertices;
    while(queueSize){
        u=extract_min();
        for(int v=0;v<vertices;v++){
            relax(u,v);
        }
    }
}
int extract_min(){
    int m=INT_MAX,i,index;
    for(i=0;i<vertices;i++){
        if(m>dis[i]&&flag[i]){
            m=dis[i];
            index=i;
        }
    }
    return index;
}
void readInput(){
    int u,v;
    string s;
    while(cin>>s){
        if(s=="END"){
            break;
        }
        for(u=0;u<vertices;u++){
            if(names[u]==s){
                break;
            }
        }
        if(u==vertices){
            names[vertices]=s;
            vertices++;
        }
        cin>>s;
        for(v=0;v<vertices;v++){
            if(names[v]==s){
                break;
            }
        }
        if(v==vertices){
            names[vertices]=s;
            vertices++;
        }
        cin>>w[u][v];
    }
    
}
void printGraph(){
    int i,j;
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            cout<<w[i][j]<<" ";
        }
        cout<<endl;
    }
}
void print_path(int v){
    if(v==-1){
        return;
    }
    cout<<names[v]<<" ";
}