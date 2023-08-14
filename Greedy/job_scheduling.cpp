#include<bits/stdc++.h>
using namespace std;

struct job{
    string jobName;
    int start;
    int finish;
    bool compatibility;
}jobs[100];

void sortJobs(int n);

void compCheck(int index,int n);

void printJob(int n);

int main(){
    freopen("job_scheduling.txt","r",stdin);
    int n,i,j;
    cin >> n;
    for(i=0;i<n;i++){
        cin>>jobs[i].jobName>>jobs[i].start>>jobs[i].finish;
        jobs[i].compatibility=true;
    }
    sortJobs(n);
    compCheck(0,n);
    printJob(n);

}

void sortJobs(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(jobs[i].finish>jobs[j].finish){
                swap(jobs[i],jobs[j]);
            }
        }
    }
}

void compCheck(int index,int n){
    if(index==n)return;
    int i=index+1;
    while(i<n){
        if(jobs[i].start<jobs[index].finish){
            jobs[i].compatibility=false;
            i++;
        }
        else{
            break;
        }
    }
    compCheck(i,n);
}

void printJob(int n){
    for(int i=0;i<n;i++){
        if(jobs[i].compatibility){
            cout<<jobs[i].jobName<<endl;
        }
    }
    cout<<endl;
}
