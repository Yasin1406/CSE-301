#include<bits/stdc++.h>
using namespace std;

int n,price[100],revenue[100],price_num,sol[100];

int rod_cut();

int main(){
    int i,j;
    price_num=10;
    freopen("rod_cut_input.txt","r",stdin);
    scanf("%d",&n);
    for(i=1;i<=price_num;i++){
        scanf("%d",&price[i]);
    }
    cout<<"Rod length: "<<n<<endl;
    printf("Max revenue: %d\n",rod_cut());
    while(n>0){
        cout<<sol[n]<<" ";
        n-=sol[n];
    }
    cout<<endl;
    return 0;
}

int rod_cut(){
    int i,j,q;
    revenue[0]=0;
    for(i=1;i<100;i++){
        sol[i]=-1;
    }
    for(i=1;i<=n;i++){
        q=-1;
        for(j=1;j<=i;j++){
            //q=max(q,price[j]+revenue[i-j]);
            if(q<price[j]+revenue[i-j]){
                q=price[j]+revenue[i-j];
                sol[i]=j;
            }
        }
        // if(q<price[j]+revenue[i-j]){
        //     q=price[j]+revenue[i-j];
        //     sol[i]=j;
        // }
        revenue[i]=q;
    }
    return revenue[n];
}
