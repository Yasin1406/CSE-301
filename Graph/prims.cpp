#include<bits/stdc++.h>
using namespace std;

vector<pair<int,pair<string,string>>> edges;
vector<string> vertices;
int edge_num,vertex_num;
map<string,int> vertex_index;
vector<int> key,pi,Q;
string root;
int graph[100][100];

void read_input();
void prims();
int get_min_of_Q();
void print_mst();

int main(){
    freopen("kruskal.txt","r",stdin);
    read_input();
    prims();
    print_mst();
    return 0;
}

void read_input(){
    cin>>vertex_num>>edge_num;
    string from,to;
    int i,j,weight;
    j=0;
    for(i=0;i<edge_num;i++){
        cin>>from>>to;
        if(find(vertices.begin(),vertices.end(),from)!=vertices.end()){
            vertices.push_back(from);
            vertex_index[from]=j++;
        }
        if(find(vertices.begin(),vertices.end(),to)!=vertices.end()){
            vertices.push_back(to);
            vertex_index[to]=j++;
        }
        cin>>weight;
        graph[vertex_index[from]][vertex_index[to]]=weight;
        edges.push_back({weight,{from,to}});
    }
    cin>>root;
}

void prims(){
    int i,j,k,u,v;
    key.resize(vertex_num);
    pi.resize(vertex_num);
    for(i=0;i<vertex_num;i++){
        key[i]=INT_MAX;
        pi[i]=-1;
        Q[i]=key[i];
    }
    key[vertex_index[root]]=0;
    Q[vertex_index[root]]=0;
    while(!Q.empty()){
        u=get_min_of_Q();
        Q.erase(Q.begin()+u);
        for(v=0;v<vertex_num;v++){
            if(graph[u][v]>0&&graph[u][v]<key[v]){
                pi[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
}

int get_min_of_Q(){
    int distance=INT_MAX,i,index=-1;
    for(i=0;i<Q.size();i++){
        if(Q[i]<distance){
            distance=Q[i];
            index=i;
        }
    }
    return index;
}

void print_mst(){
    int i,j;
    for(i=0;i<vertex_num;i++){
        if(pi[i]>0){
            cout<<vertices[pi[i]]<<" -> "<<vertices[i]<<" : "<<key[i]<<endl;
        }
    }
}