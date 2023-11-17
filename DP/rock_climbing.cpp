#include<bits/stdc++.h>
using namespace std;

int row,col;
vector<vector<int>> rock,cost;

void read_input();
void rock_climbing();
void print_matrix();
void print_path(int r,int c);
void rock_climbing_recursion(int r);

int main(){
    read_input();
    rock_climbing();
    // print_matrix();
    int i=min_element(cost[row].begin(),cost[row].end())-cost[row].begin();
    print_path(row,i);

    return 0;
}

void read_input(){
    freopen("rock_climbing.txt","r",stdin);
    cin>>row>>col;
    rock.resize(row+1,vector<int>(col+1));
    cost.resize(row+1,vector<int>(col+1));
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            cin>>rock[i][j];
        }
    }
    for(int i=0;i<=row;i++){
        cost[i][0]=INT_MAX;
        cost[i][col]=INT_MAX;
    }
}

void rock_climbing(){
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            cost[i][j]=min(cost[i-1][j-1],min(cost[i-1][j],cost[i-1][j+1]))+rock[i][j];
        }
    }
}

void print_matrix(){
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            printf("%4d",cost[i][j]);
        }
        cout<<endl;
    }
}

void print_path(int r,int c){
    if(r==0){
        return;
    }
    
    int minimum=min(min(cost[r-1][c],cost[r-1][c-1]),cost[r-1][c+1]);
    if(minimum==cost[r-1][c]){
        print_path(r-1,c);
    }
    else if(minimum==cost[r-1][c-1]){
        print_path(r-1,c-1);
    }
    else{
        print_path(r-1,c+1);
    }
    cout<<rock[r][c]<<endl;
}

// void rock_climbing_recursion(int r){
//     if(r==0){
//         return;
//     }
//     // rock_climbing_recursion(r-1);
//     for(int j=1;j<=col;j++){
//         cost[r][j]=min(cost[r-1][j-1],min(cost[r-1][j],cost[r-1][j+1]))+rock[r][j];
//     }

// }