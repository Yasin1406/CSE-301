#include<bits/stdc++.h>
using namespace std;
#define no_arrow 0
#define left 1
#define up 2
#define diagonal 3
#define diagonal_nil 4

string first,second;
vector<int> cost(4);
int operations;
vector<vector<int>> c,arrow;

void edit_distance();
void print_ED(int i,int j);
void print_array();

int main(){
    freopen("ed.txt","r",stdin);
    cin>>first>>second;
    cost[0]=0;
    for(int i=1;i<=3;i++){
        cin>>cost[i];
    }
    edit_distance();
    print_ED(first.size(),second.size());
    return 0;
}

void edit_distance(){
    first=" "+first;
    second=" "+second;
    c.resize(first.size()+1,vector<int>(second.size()+1));
    arrow.resize(first.size()+1,vector<int>(second.size()+1));
    
    for(int i=0;i<=first.size();i++){
        c[i][0]=i;
        arrow[i][0]=up;
    }
    for(int i=0;i<=second.size();i++){
        c[0][i]=i;
        arrow[0][i]=left;
    }
    c[0][0]=0;
    arrow[0][0]=no_arrow;
    for(int i=1;i<=first.size();i++){
        for(int j=1;j<=second.size();j++){
            if(first[i]==second[j]){
                c[i][j]=c[i-1][j-1];
                arrow[i][j]=diagonal_nil;
            }
            else{
                c[i][j]=min(c[i-1][j-1]+cost[3],min(c[i-1][j]+cost[2],c[i][j-1]+cost[1]));
                if(c[i][j]-cost[3]==c[i-1][j-1]){
                    arrow[i][j]=diagonal;
                }
                else if(c[i][j]-cost[2]==c[i-1][j]){
                    arrow[i][j]=up;
                }
                else if(c[i][j]-cost[1]==c[i][j-1]){
                    arrow[i][j]=left;
                }
            }
        }
    }
    print_array();
}

void print_ED(int i,int j){
    if(arrow[i][j]==no_arrow){
        cout<<"Edit distance: "<<c[first.size()][second.size()]<<endl;
        cout<<"Number of operations: "<<operations<<endl;
        cout<<"Operations:"<<endl;
        return;
    }
    if(arrow[i][j]==left){
        operations++;
        print_ED(i,j-1);
        cout<<"Insert "<<second[j]<<" in "<<first<<" at index "<<i<<endl;
    }
    else if(arrow[i][j]==up){
        operations++;
        print_ED(i-1,j);
        cout<<"Delete "<<first[i]<<" from "<<first<<endl;
    }
    else if(arrow[i][j]==diagonal){
        operations++;
        print_ED(i-1,j-1);
        cout<<"Replace "<<first[i]<<" with "<<second[j]<<endl;
    }
    else{
        print_ED(i-1,j-1);
    }
}

void print_array(){
    cout<<"Matrix:"<<endl;
    for(int i=0;i<first.size()+1;i++){
        for(int j=0;j<second.size()+1;j++){
            printf("%4d",c[i][j]);
        }
        cout<<endl;
    }
    cout<<endl<<"Arrow:"<<endl;;
    for(int i=0;i<first.size()+1;i++){
        for(int j=0;j<second.size()+1;j++){
            printf("%4d",arrow[i][j]);
        }
        cout<<endl;
    }
    cout<<endl;
}
