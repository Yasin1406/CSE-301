#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> transition;
vector<char> alphabets={'a','b'};
string pattern,text;

void read_input();
void ctf();
bool is_suffix(int k,int q,char ch);
void print_transition();

int main(){
    read_input();
    ctf();
    print_transition();
    return 0;
}

void read_input(){
    freopen("input.txt","r",stdin);
    cin>>pattern>>text;
}

void ctf(){
    int m=pattern.size(),k;
    transition.resize(m+1,vector<int>(alphabets.size()));
    for(int q=0;q<=m;q++){
        for(auto a:alphabets){
            k=1+min(m,q+1);
            while(!is_suffix(--k,q,a));
            transition[q][a-'a']=k;
        }
    }
}

bool is_suffix(int k,int q,char ch){
    string pk=pattern.substr(0,k);
    string pq=pattern.substr(0,q)+ch;
    int index=pq.size()-pk.size();
    return pk==pq.substr(index);
}

void print_transition(){
    for(auto q:transition){
        for(auto a:q){
            cout<<a<<" ";
        }
        cout<<endl;
    }
}