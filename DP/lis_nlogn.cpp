#include<bits/stdc++.h>
using namespace std;
int lis[100],index_lis[100],previous[100],n,a[100],l_len;
void lis_fast_dp();
void print_lis(int index);
int main(){
    freopen("lis_input.txt","r",stdin);
    cin>>n;
    int i,j,k;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    lis_fast_dp();
    cout<<"LIS: "<<l_len<<endl;
    print_lis(index_lis[l_len]);
    cout<<endl;
    return 0;

}
void lis_fast_dp(){
    l_len=0;
    lis[0]=-__INT16_MAX__;
    index_lis[0]=-1;
    previous[0]=-1;
    int i,j,k,s,h;
    for(i=1;i<=n;i++){
        if(lis[l_len]<a[i]){
            lis[++l_len]=a[i];
            index_lis[l_len]=i;
            previous[i]=index_lis[l_len-1];
        }
        else{
            s=0;
            h=l_len;
            while(s<h){
                int m=(s+h)/2;
                if(lis[m]<a[i]){
                    s=m+1;
                }
                else{
                    h=m;
                }
            }
            lis[s]=a[i];
            index_lis[s]=i;
            previous[i]=index_lis[s-1];
        }
    }
}
void print_lis(int index){
    if(index==-1){
        return;
    }
    print_lis(previous[index]);
    cout<<a[index]<<" ";
}