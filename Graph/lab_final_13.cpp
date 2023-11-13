#include<bits/stdc++.h>
using namespace std;

vector<set<string>> sets;
vector<pair<int,pair<string,string>>> edges;
set<string> junctions;
int vertice_num,edge_num,total_weight;
set<pair<int,pair<string,string>>> mst;

void read_input();
void make_set(string junc);
int find_set(string junc);
void union_set(string junc1,string junc2);
void kruskal();
int calculate_mst_weight();

int main(){
    freopen("kruskal.txt","r",stdin);
    read_input();
    kruskal();
    cout<<"Maximum "<<total_weight-calculate_mst_weight()<<" rupee can be saved"<<endl;
    return 0;
}

void read_input(){
    cin>>vertice_num>>edge_num;
    string from,to;
    int dist;
    for(int i=0;i<edge_num;i++){
        cin>>from>>to;
        junctions.insert(from);
        junctions.insert(to);
        cin>>dist;
        total_weight+=dist;
        edges.push_back({dist,{from,to}});
    }
}

void make_set(string junc){
    set<string> st;
    st.insert(junc);
    sets.push_back(st);
}

int find_set(string junc){
    int i=0;
    for(auto s:sets){
        for(auto j:s){
            if(j==junc){
                return i;
            }
        }
        i++;
    }
    return -1;
}

void union_set(string junc1,string junc2){
    int idx_1,idx_2;
    idx_1=find_set(junc1);
    idx_2=find_set(junc2);
    for(auto e:sets[idx_2]){
        sets[idx_1].insert(e);
    }
    sets.erase(sets.begin()+idx_2);
}

void kruskal(){
    for(auto j:junctions){
        make_set(j);
    }
    sort(edges.begin(),edges.end());
    for(auto e:edges){
        if(find_set(e.second.first)!=find_set(e.second.second)){
            mst.insert(e);
            union_set(e.second.first,e.second.second);
        }
    }
}

int calculate_mst_weight(){
    int sum=0;
    for(auto e:mst){
        sum+=e.first;
    }
    return sum;
}