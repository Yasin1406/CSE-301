#include<bits/stdc++.h>
using namespace std;
#define SIZE 100
#define INF 1e9+10
vector <pair<int,int>> graph[SIZE];
vector <int> dist(SIZE,INF);
vector <bool> visited(SIZE,false);
vector <string> name;
vector <int> parent(SIZE);
void dijkstra(int source){
    set <pair <int,int>> st;
    st.insert({0,source});
    dist[source] = 0;
    parent[source] = -1;
    while(!st.empty()){
        auto node = *st.begin();
        int v = node.second;
        int dis = node.first;
        st.erase(st.begin());
        if(visited[v])continue;
        visited[v] = true;
        for(auto c: graph[v]){
            int child_v = c.first;
            int val = c.second;
            parent[child_v] = v;
            if(dist[v] + val < dist[child_v]){
                dist[child_v] = dist[v] + val;
                st.insert({dist[child_v],child_v});
            }
        }
    }
}
int indexof(string a){
    for(int i=0; i<SIZE; i++){
        if(name[i]==a)return i;
    }
    return -1;
}
void printPath(int des){
    if(des == -1)return;
    printPath(parent[des]);
    cout << name[des] << " ";
}
int main(){
    freopen("input.txt","r",stdin);
    int edge;
    cin >> edge;
    string s1,s2;
    int dis;
    for(int i=0; i<edge; i++){
        cin >> s1 >> s2 >> dis;
        if(find(name.begin(),name.end(),s1) == name.end())name.push_back(s1);
        if(find(name.begin(),name.end(),s2) == name.end())name.push_back(s2);
        int v1 = indexof(s1);
        int v2 = indexof(s2);
        graph[v1].push_back({v2,dis});
    }
    string source = "Dhaka";
    dijkstra(indexof(source));
    // cout << "Distance from "<< source << ": " << endl;
    // for(int i=0; i<SIZE; i++){
    //     if(name[i] != source && dist[i] != INF)cout << name[i] << "->" << dist[i] << endl;
    // }
    string destination = "Cumilla";
    printPath(indexof(destination));
    cout << endl;
    return 0;
}