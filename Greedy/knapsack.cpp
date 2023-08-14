#include<bits/stdc++.h>
using namespace std;

struct item{
    double weight;
    double benifit;
}items[100];

double used_weight,max_ben;

void sortItem(int n,double max_weight);

void max_benifit(int n);

int main(){

}

void sortItem(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if((items[i].benifit/items[i].weight)<(items[j].benifit/items[j].weight)){
                swap(items[i],items[j]);
            }
        }
    }
}

void max_benifit(int n,double max_weight){
    int i;
    while(used_weight<=max_weight&&i<n){
        
    }
}
