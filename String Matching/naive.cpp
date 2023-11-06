#include<bits/stdc++.h>
using namespace std;

string pattern,text;

void read_input();
int get_occur_num();


int main(){
    read_input();
    int occur=get_occur_num();
    cout<<"Occured "<<occur<<" time(s)"<<endl;
    return 0;
}

void read_input(){
    freopen("input.txt","r",stdin);
    cin>>pattern>>text;
}

int get_occur_num(){
    int num=0,m=text.size(),n=pattern.size();
    for(int i=0;i<=m-n;i++){
        if(pattern==text.substr(i,n)){
            num++;
            cout<<"Pattern occured at shift: "<<i<<endl;
        }
    }
    return num;
}
