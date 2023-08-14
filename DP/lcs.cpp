#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mat,sign;
void lcs(string first,string second,int inF,int inS);
void print_lcs(string first,int l1,int l2);
int main(){
    string first,second;
    cout<<"Enter first string: ";
    cin>>first;
    cout<<"Enter second string: ";
    cin>>second;
    int l1=first.size(),l2=second.size();
    mat.resize(l1+1,vector<int>(l2+1));
    sign.resize(l1+1,vector<int>(l2+1));
    lcs(first,second,0,0);
    return 0;
}

void lcs(string first,string second,int inF,int inS){
    if(inF==first.size()){
        cout<<"Longest common subsequence: ";
        print_lcs(first,first.size(),second.size());
        cout<<endl;
        return;
    }
    int i,j;
    for(i=0;i<second.size();i++){
        if(first[inF]==second[i]){
            mat[inF+1][i+1]=1+mat[inF][i];
            sign[inF+1][i+1]=3;
        }
        else{
            if(mat[inF][i+1]>=mat[inF+1][i]){
                mat[inF+1][i+1]=mat[inF][i+1];
                sign[inF+1][i+1]=1;
            }
            else{
                mat[inF+1][i+1]=mat[inF+1][i];
                sign[inF+1][i+1]=2;
            }
        }
        /*  1 for upper arrow
            2 for left arrow
            3 for left diagonal arrow  */
    }
    lcs(first,second,inF+1,0);
}
void print_lcs(string first,int l1,int l2){
    if(l1==0||l2==0){
        return;
    }
    if(sign[l1][l2]==3){
        print_lcs(first,l1-1,l2-1);
        cout<<first[l1-1]<<" ";
    }
    else{
        if(sign[l1][l2]==1){
            print_lcs(first,l1-1,l2);
        }
        else{
            print_lcs(first,l1,l2-1);
        }
    }
}