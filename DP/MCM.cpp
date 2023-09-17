#include<bits/stdc++.h>
using namespace std;

int p[100],s[100][100],m[100][100],n;
int lookup_chain(int i,int j);
void print_optimal(int i,int j);
void iterative();
int main(){
 //   freopen("input.txt","r",stdin);
    int i,j,k;
  //  cout<<"Enter number of matrices: ";
    cin>>n;
    // p[n+2];
    // s[n+1][n+1];
    // m[n+1][n+1];
   // cout<<"Enter the dimensions:"<<endl;
    for(i=0;i<=n;i++){
        cin>>p[i];
    }
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            m[i][j]=__INT16_MAX__;
        }
    }
    for(i=0;i<=n;i++){
        cout<<p[i]<<" ";
    }
    int x=lookup_chain(1,n);
    cout<<"Min: "<<x<<endl;
    iterative();
    cout<<"Min: "<<m[1][n]<<endl;
    print_optimal(1,n);
    cout<<endl;
}
int lookup_chain(int i,int j){
    //cout<<i<<endl;
    if(m[i][j]<__INT16_MAX__){
        return m[i][j];
    }
    int k,q;
    if(i==j){
        m[i][j]=0;
    }
    else{
        for(k=i;k<=j-1;k++){
            q=lookup_chain(i,k)+lookup_chain(k+1,j)+p[i-1]*p[k]*p[j];
            if(q<m[i][j]){
                m[i][j]=q;
                s[i][j]=k;
            }
        }
    }
 //   cout<<m[i][j]<<endl;
    return m[i][j];
}
void print_optimal(int i,int j){
    if(i==j){
        cout<<"A"<<i<<" ";
    }
    else{
        cout<<"( ";
        print_optimal(i,s[i][j]);
        print_optimal(s[i][j]+1,j);
        cout<<") ";
    }
}
void iterative(){
    int i,j,k,l,q;
    for(i=1;i<=n;i++){
        m[i][i]=0;
    }
    for(l=2;l<=n;l++){
        for(i=1;i<=n-l+1;i++){
            j=i+l-1;
            m[i][j]=__INT16_MAX__;
            for(k=i;k<=j-1;k++){
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
}