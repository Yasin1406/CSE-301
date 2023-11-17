#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph(100,vector<int>(100));
vector<vector<int>> d(100,vector<int>(100));
vector<vector<int>> p(100,vector<int>(100));
vector<string> names(100);
map<string,int> places;
vector<string> path;
vector<int> path_in;
int vertex,edge;
void floyd_warshall();
void print_path(int s,int t);
void read_input();
int main(){
    freopen("floyd.txt","r",stdin);
    read_input();
    for(int i=1;i<=vertex;i++){
        for(int j=1;j<=vertex;j++){
            if(i==j||graph[i][j]==INT_MAX){
                p[i][j]=0;
            }
            else if(i!=j&&graph[i][j]<INT_MAX){
                p[i][j]=i;
            }
        }
    }
    for(int i=1;i<=vertex;i++){
        for(int j=1;j<=vertex;j++){
            d[i][j]=graph[i][j];
        }
    }
    floyd_warshall();
    string beg,des;
    cin>>beg>>des;
    int dist;
    print_path(places[beg],places[des]);
    path.push_back(des);
    path_in.push_back(places[des]);
    path_in.resize(path.size());
    for(auto x:path){
        cout<<x<<" ";
    }
    cout<<endl;
    for(int i=0;i<path.size()-1;i++){
        dist+=graph[path_in[i]][path_in[i+1]];
    }
    cout<<"Distance: "<<d[places[beg]][places[des]]<<endl;
    cout<<endl;
    return 0;
}
void floyd_warshall(){
    for(int k=1;k<=vertex;k++){
        for(int i=1;i<=vertex;i++){
            for(int j=1;j<=vertex;j++){
                if(d[i][k]+d[k][j]<d[i][j]&&(d[k][j]!=INT_MAX&&d[i][k]!=INT_MAX)){
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=p[k][j];
                }
            }
        }
    }
}
void print_path(int s,int t){
    if(p[s][t]==0){
        cout<<"No path"<<endl;
        return;
    }
    else if(p[s][t]==s){
        path.push_back(names[s]);
        path_in.push_back(places[names[s]]);
    }
    else{
        print_path(s,p[s][t]);
        print_path(p[s][t],t);
    }
}
void read_input(){
    for(int i=1;i<100;i++){
        for(int j=1;j<100;j++){
            graph[i][j]=INT_MAX;
        }
    }
    cin>>edge;
    vertex=1;
    int w;
    string s1,s2;
    for(int i=0;i<edge;i++){
        cin>>s1>>s2>>w;
        if(find(names.begin(),names.end(),s1)==names.end()){
            names[vertex]=s1;
            places[s1]=vertex;
            vertex++;
        }
        if(find(names.begin(),names.end(),s2)==names.end()){
            names[vertex]=s2;
            places[s2]=vertex;
            vertex++;
        }
        graph[places[s1]][places[s2]]=w;
    }
    vertex--;
    for(int i=1;i<100;i++){
        for(int j=1;j<100;j++){
            if(i==j){
                graph[i][j]=0;
            }
        }
    }
}