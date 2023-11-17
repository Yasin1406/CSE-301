#include<bits/stdc++.h>
using namespace std;
#define MAX 50 
#define INF 1e5

int w[MAX][MAX];
int d[MAX];
int p[MAX];

vector<string> vertices;
int numEdges, numVertex, edgeWeight;
string src, dest;

void readInput();
int getIndex(string city);
void initializeSingleSource(string src);
void relax(string to, string from, int edgeWeight);
bool bellman_ford(string src);
void printGraph();
void printPath(int dest);

int main(){
    readInput();
    for(string city : vertices) cout << city << " ";
    cout << endl;
    numVertex = vertices.size();
    cout << numVertex << endl;
    printGraph();
    bellman_ford(src) ? cout << "There is no negative edge weight cycle in the graph" << endl : cout << "There is a negative edge weight cycle in the graph" << endl; 
    return 0;
}

int getIndex(string city){
    for(int i = 0; i < vertices.size();++i){
        if(vertices[i] == city) return i;
    }
    return -1;
}

void readInput(){   
    freopen("floyd.txt", "r", stdin);
    cin >> numEdges;
    string from,to;
    for(int i = 1; i <= numEdges;++i){
        cin >> from >> to;
        if(find(vertices.begin(), vertices.end(), from) == vertices.end()) vertices.push_back(from);
        if(find(vertices.begin(), vertices.end(), to) == vertices.end()) vertices.push_back(to);
        int u = getIndex(from);
        int v = getIndex(to);
        cin >> edgeWeight;
        w[u][v] = edgeWeight;        
    }
    cin >> src;
    cout << src << endl;
}

void initializeSingleSource(string src){
    for(string vertex : vertices){
        int v = getIndex(vertex);
        d[v] = INF;
        p[v] = -1;
    }
    // int source = getIndex(src);
    // cout << source << " --> Source idx"<< endl; 
    d[getIndex(src)] = 0;
}

void relax(int u, int v){
    if(d[u] + w[u][v] < d[v]){
        d[v] = d[u] + w[u][v]; 
    }
    p[v] = u;
}

bool bellman_ford(string src){
    initializeSingleSource(src);
    for(int i = 0; i < numVertex - 1; ++i){
        for(int u = 0; u < numVertex; ++u){
            for(int v = 0; v < numVertex; ++v){
                if(w[u][v]){
                    relax(u,v);
                } 
            }
        }
    }

    for(int u = 0; u < numVertex; ++u){
        for(int v = 0; v < numVertex; ++v){
            if(d[v] > d[u] + w[u][v]) return false; 
        }
    }

    return true;
}

void printGraph(){
    for(int u = 0; u < numVertex; ++u){
        for(int v = 0 ; v < numVertex; ++v){
            cout << w[u][v] << " ";
        }
        cout << endl;
    }
}

void printPath(int dest){
    if(p[dest] == -1) return;   
    printPath(p[dest]);
    cout << vertices[p[dest]] << "--->";
}