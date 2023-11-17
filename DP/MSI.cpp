#include<bits/stdc++.h>
using namespace std;

vector<int> A,sum,pre;
int n,maximum,max_index;

void read_input();
void maximum_sum_interval();
void print_msi(int index);

int main(){
    freopen("msi.txt","r",stdin);
    read_input();
    maximum_sum_interval();
    cout<<"Maximum sum: "<<maximum<<endl;
    cout<<"Maximum sum interval: ";
    print_msi(max_index);
    cout<<endl;
    // cout<<"A:\t";
    // for(int i=0;i<=n;i++){
    //     printf("%4d",A[i]);
    // }
    // cout<<endl;
    // cout<<"Sum:\t";
    // for(int i=0;i<=n;i++){
    //     printf("%4d",sum[i]);
    // }
    // cout<<endl;
    // cout<<"Prev:\t";
    // for(int i=0;i<=n;i++){
    //     printf("%4d",pre[i]);
    // }
    cout<<endl;
    return 0;
}

void read_input(){
    int i,value;
    A.push_back(0);
    cin>>n;
    for(i=0;i<n;i++){
        cin>>value;
        A.push_back(value);
    }
}

void maximum_sum_interval(){
    sum.assign(n+1,0);
    pre.resize(n+1);
    pre[0]=0;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+A[i];
        pre[i]=i-1;
        if(A[i]>sum[i]){
            sum[i]=A[i];
            pre[i]=0;
        }
    }
    // maximum=*max_element(sum.begin(),sum.end());
    maximum=sum[0];
    for(int i=1;i<=n;++i){
        if(sum[i]>maximum){
            maximum=sum[i];
            max_index=i;
        }
    }
}

// void print_msi(int index){
//     if(index==0){
//         return;
//     }
//     print_msi(pre[index]);
//     cout<<A[index]<<" ";
// }

void print_msi(int index){
    if(pre[index]>0){
        print_msi(pre[index]);
    }
    cout<<A[index]<<" ";
}

// 14 13 12 11