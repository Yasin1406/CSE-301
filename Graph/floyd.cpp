#include<bits/stdc++.h>
using namespace std;
#define SIZE 50
int graph[SIZE][SIZE];
int dist[SIZE][SIZE];
int parent[SIZE][SIZE];
vector<string> name;

void floydWarshall(int size){
    for(int k=1;k<=size;k++){
        for(int i=1;i<=size;i++){
            for(int j=1;j<=size;j++){
                if((dist[k][j] != INT_MAX and dist[i][k] != INT_MAX) and dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }
}

void printPath(int source,int destination){
    if(parent[source][destination]==0){
        cout << "No path" << endl;
        return;
    }
    else if(parent[source][destination]==source) cout << name[source-1] << " -> ";
    else{
        printPath(source,parent[source][destination]);
        printPath(parent[source][destination],destination);
    }
}

int indexof(string a){
    for(int i=0; i<SIZE; i++){
        if(name[i]==a)return i+1;
    }
    return -1;
}

int main(){
    freopen("floyd.txt","r",stdin);
    int num_vertex,num_edge,from,to,dis;
    cin >> num_edge;
    for(int i=1;i<=SIZE;i++){
        for(int j=1;j<=SIZE;j++){
            if(i==j)graph[i][j] = 0;
            else graph[i][j]=INT_MAX;
        }
    }
    string one,two;
    for(int i=0;i<num_edge;i++){
        cin >> one >> two >> dis;
        if(find(name.begin(),name.end(),one) == name.end())name.push_back(one);
        if(find(name.begin(),name.end(),two) == name.end())name.push_back(two);
        from = indexof(one);
        to = indexof(two);
        graph[from][to] = dis;
    }
    num_vertex = name.size();
    for(int i=1;i<=num_vertex;i++){
        for(int j=1;j<=num_vertex;j++){
            if(i==j or graph[i][j]==INT_MAX)parent[i][j] = 0;
            else if(i!=j and graph[i][j] < INT_MAX)parent[i][j] = i;
        }
    }
    for(int i=1;i<=num_vertex;i++){
        for(int j=1;j<=num_vertex;j++){
            dist[i][j]=graph[i][j];
        }
    }
    floydWarshall(num_vertex);
    for(int i=1;i<=num_vertex;i++){
        for(int j=1;j<=num_vertex;j++){
            if(dist[i][j]==INT_MAX) cout << "e" << " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    string source = "Dhaka",destination = "Tangail";
    cout << endl << endl;
    cout << "Path from " << source << " to " << destination << " : ";
    printPath(indexof(source),indexof(destination));
    cout << destination << endl;
    cout << endl;
    cout << "Total distance from " << source << " to " << destination << " is : " << dist[indexof(source)][indexof(destination)] << endl << endl;
    return 0;
}