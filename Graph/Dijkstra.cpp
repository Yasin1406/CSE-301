#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> graph[100];
vector<string> vertices;
vector<bool> is_visited(100);
vector<int> dis(100);
vector<int> parent(100);
set<pair<int,int>> p_q;
int edge;
void initialize(string source);
int indexof(string name);
void relax(int u,int v,int w);
void dijkstra(string source);
void read_input();
void print_path(int index);
int main(){
    freopen("input.txt","r",stdin);
    read_input();
    dijkstra("Dhaka");
    for(int i=0;i<vertices.size();i++){
        cout<<"Dhaka -> "<<vertices[i]<<": "<<dis[i]<<endl;
    }
    print_path(3);
    cout<<endl;
    return 0;

}
void initialize(string source){
    for(int i=0;i<vertices.size();i++){
        dis[i]=INT_MAX;
        parent[i]=-1;
    }
    dis[indexof(source)]=0;
}
int indexof(string name){
    for(int i=0;i<vertices.size();i++){
        if(name==vertices[i]){
            return i;
        }
    }
    return -1;
}
void relax(int u,int v,int w){
    if(dis[v]>(dis[u]+w)){
        dis[v]=dis[u]+w;
        parent[v]=u;
        p_q.insert({dis[v],v});
    }
}
void dijkstra(string source){
    initialize(source);
    int in_source=indexof(source);
    p_q.insert({0,in_source});
    while(!p_q.empty()){
        auto u=(*p_q.begin()).second;
        p_q.erase(p_q.begin());
        for(auto c:graph[u]){
            relax(u,c.first,c.second);
        }
    }
}
void read_input(){
    cin>>edge;
    string s1,s2;
    int w;
    for(int i=0;i<edge;i++){
        cin>>s1>>s2>>w;
        if(find(vertices.begin(),vertices.end(),s1)==vertices.end()){
            vertices.push_back(s1);
        }
        if(find(vertices.begin(),vertices.end(),s2)==vertices.end()){
            vertices.push_back(s2);
        }
        graph[indexof(s1)].push_back({indexof(s2),w});
    }
}
void print_path(int index){
    if(index<0){
        return;
    }
    print_path(parent[index]);
    cout<<vertices[index]<<" ";
}