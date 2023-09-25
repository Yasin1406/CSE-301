#include<bits/stdc++.h>
using namespace std;
int graph[100][100],num_vertice,num_edge;
char vertices[100];
set<pair<int,pair<int,int>>> A;
vector<set<char>> make_set;

void read_input();
void kruskal();
int find_set(char ch);
int find_index(char ch);

int main(){
    freopen("kruskal.txt","r",stdin);
    read_input();
    kruskal();
    for(auto a:A){
        cout<<vertices[a.second.first]<<" <-> "<<vertices[a.second.second]<<" "<<a.first<<endl;
    }
    int i,j,k;
    // for(i=0;i<num_vertice;i++){
    //     for(j=0;j<num_vertice;j++){
    //         cout<<graph[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    return 0;
}

void read_input(){
    cin>>num_vertice>>num_edge;
    int i,j,k;
    int u,v;
    graph[num_vertice][num_vertice];
    vertices[num_vertice];
    for(i=0;i<num_vertice;i++){
        for(j=0;j<num_vertice;j++){
            graph[i][j]=0;
        }
    }
    for(i=0;i<num_vertice;i++){
        vertices[i]=97+i;
    }
    for(i=0;i<num_edge;i++){
        cin>>u>>v;
        cin>>graph[u-1][v-1];
        graph[v-1][u-1]=graph[u-1][v-1];
    }
}

void kruskal(){
    int i,j,k;
    for(i=0;i<num_vertice;i++){
        for(auto v:vertices){
            set<char> s;
            s.insert(v);
            make_set.push_back(s);
        }
    }
    set<pair<int,pair<int,int>>> temp;
    for(i=0;i<num_vertice;i++){
        for(j=0;j<num_vertice;j++){
            if(graph[i][j]){
                temp.insert({graph[i][j],{i,j}});
            }            
        }
    }
    // while(make_set.size()!=1){

    // }
    for(auto t:temp){
        int index_u=find_set(vertices[t.second.first]);
        int index_v=find_set(vertices[t.second.second]);
        if(index_u!=index_v){
            A.insert({t.first,{t.second.first,t.second.second}});
            for(auto v:make_set[index_v]){
                make_set[index_u].insert(v);
            }
            auto it=make_set.begin()+index_v;
            make_set.erase(it);
        }
    }
}

int find_set(char ch){
    int i;
    for(i=0;i<make_set.size();i++){
        if(find(make_set[i].begin(),make_set[i].end(),ch)!=make_set[i].end()){
            return i;
        }
    }
    return -1;
}

int find_index(char ch){
    for(int i=0;i<num_vertice;i++){
        if(ch==vertices[i]){
            return i;
        }
    }
    return -1;
}