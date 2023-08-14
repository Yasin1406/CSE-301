#include<bits/stdc++.h>
using namespace std;

int n,price[100],revenue[100],price_num,sol[100];

int rod_cut();
int rod_cut_aux(int n);

int main(){
    int i,j;
    price_num=10;
    freopen("rod_cut_input.txt","r",stdin);
    scanf("%d",&n);
    for(i=1;i<=price_num;i++){
        scanf("%d",&price[i]);
    }
    printf("Max revenue: %d\n",rod_cut());
    return 0;
}

int rod_cut(){
    int i;
    for(i=0;i<n+1;i++){
        revenue[i]=-1;
    }
    return rod_cut_aux(n);
}

int rod_cut_aux(int n){
    if(revenue[n]>=0){
        return revenue[n];
    }
    int q;
    if(n==0){
        q=0;
    }
    else{
        q=-1;
        for(int i=1;i<=n;i++){
            q=max(q,price[i]+rod_cut_aux(n-i));
        }
    }
    revenue[n]=q;
    return revenue[n];
}