#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mat,sign;
void edit_distance(string first,string second,int inF,int inS);
void print_edit_distance(string first,string second,int l1,int l2,int end);
int main(){
    int i,j;
    string first,second;
    cout<<"Enter first string: ";
    cin>>first;
    cout<<"Enter second string: ";
    cin>>second;
    int l1=first.size(),l2=second.size();
    mat.resize(l1+1,vector<int>(l2+1));
    sign.resize(l1+1,vector<int>(l2+1));
    for(i=0;i<mat[0].size();i++){
        mat[0][i]=i;
        if(i!=0)sign[0][i]=1;
    }
    for(j=0;j<mat.size();j++){
        mat[j][0]=j;
        if(j!=0)sign[j][0]=2;
    }
    edit_distance(first,second,0,0);
    return 0;
}

void edit_distance(string first,string second,int inF,int inS){
    if(inF==first.size()){
        int i,j;
        cout<<"    ";
        for(i=1;i<mat[0].size();i++){
            cout<<second[i-1]<<" ";
        }
        cout<<endl;
        cout<<"  ";
        for(i=0;i<mat[0].size();i++){
            cout<<mat[0][i]<<" ";
        }
        cout<<endl;
        for(i=1;i<mat.size();i++){
            cout<<first[i-1]<<" ";
            for(j=0;j<mat[i].size();j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        int end=mat[first.size()][second.size()];
        cout<<"Operations needed: "<<end<<endl;
        
        print_edit_distance(first,second,first.size(),second.size(),end);
        return;
    }
    int i;
    for(i=0;i<second.size();i++){
        if(first[inF]==second[i]){
            mat[inF+1][i+1]=mat[inF][i];
            sign[inF+1][i+1]=4;
        }
        else{
            mat[inF+1][i+1]=1+min(mat[inF+1][i],min(mat[inF][i+1],mat[inF][i]));
            if(mat[inF+1][i+1]-1==mat[inF+1][i]){
                sign[inF+1][i+1]=1;
            }
            else if(mat[inF-1][i]==mat[inF+1][i+1]){
                sign[inF+1][i+1]=2;
            }
            else if(mat[inF+1][i+1]-1==mat[inF][i]){
                sign[inF+1][i+1]=3;
            }
        }
    }
    /*  1 for insertion
        2 for deletion
        3 for replacement
        4 for no operation  */
    edit_distance(first,second,inF+1,0);
}
void print_edit_distance(string first,string second,int l1,int l2,int end){
    if(end==0){
        return;
    }
    if(sign[l1][l2]==4){
        print_edit_distance(first,second,l1-1,l2-1,end);
    }
    else if(sign[l1][l2]==3){
        print_edit_distance(first,second,l1-1,l2-1,end-1);
        // cout<<"Replace '"<<first[l1-1]<<"' with '"<<second[l2-1]<<"'"<<endl;
        // first[l1-1]=second[l2-1];
        cout<<"Replace"<<endl;
    }
    else if(sign[l1][l2]==2){
        print_edit_distance(first,second,l1-1,l2,end-1);
        //cout<<"Delete '"<<first[l1]<<"'"<<endl;
        cout<<"Delete"<<endl;
    }
    else{
        print_edit_distance(first,second,l1,l2-1,end-1);
       // cout<<"Insert '"<<second[l2-1]<<"' in the place of '"<<first[l1]<<"'"<<endl;
        cout<<"Insert"<<endl;
    }
}