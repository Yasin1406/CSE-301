#include<bits/stdc++.h>
using namespace std;

int rod_size,n,cost;
vector<int> price,revenue,cut_point;
int max_revenue;

void read_input();
void cut_rod();
void print_solution();

int main(){
    read_input();
    cut_rod();
    print_solution();
    return 0;
}

void read_input(){
    freopen("rod_cut_input.txt","r",stdin);
    cin>>rod_size>>n;
    price.resize(max(n+1,rod_size+1));
    price[0]=0;
    int v;
    for(int i=1;i<=n;i++){
        cin>>price[i];
    }
    cin>>cost;
    // cout<<"Cost: "<<cost<<endl;
}

void cut_rod(){
    revenue.resize(rod_size+1);
    revenue[0]=0;
    cut_point.resize(rod_size+1);
    cut_point[0]=0;
    int q,i,j;
    for(j=1;j<=rod_size;j++){
        q=-INT_MAX;
        for(i=1;i<=j;i++){
            if(q<price[i]+revenue[j-i]-cost){
                q=price[i]+revenue[j-i]-cost;
                cut_point[j]=i;
            }
        }
        revenue[j]=q;
    }
    max_revenue=revenue[rod_size];
    if(cost>0){
        max_revenue+=cost;
    }
}

void print_solution(){
    cout<<"Maximum revenue: "<<max_revenue<<endl;
    int n=rod_size;
    while(n>0){
        cout<<cut_point[n]<<" ";
        n-=cut_point[n];
    }
    cout<<endl;
}