#include<bits/stdc++.h>
using namespace std;

struct job{
    string name;
    int start;
    int finish;
    bool conflicts;
}jobs[100];

vector<vector<job>> sequence;
int vec_in;

void sortJobs(int job_num);

void check_conflicts(int index,int n);

int main(){
    freopen("job_scheduling.txt","r",stdin);
    int job_num,i,j;
    cin>>job_num;
    for(i=0;i<job_num;i++){
        cin>>jobs[i].name>>jobs[i].start>>jobs[i].finish;
        jobs[i].conflicts=false;
    }
    sortJobs(job_num);
    check_conflicts(0,job_num);
    for(i=0;i<job_num;i++){
        if(jobs[i].conflicts==false){
            cout<<jobs[i].name<<endl;
        }
    }
    return 0;
}

void sortJobs(int job_num){
    int i,j;
    for(i=0;i<job_num;i++){
        for(j=i+1;j<job_num;j++){
            if(jobs[i].finish>jobs[j].finish){
                swap(jobs[i],jobs[j]);
            }
        }
    }
}

void check_conflicts(int index,int job_num){
    if(index==job_num){
        return;
    }
    int i=index+1;
    while(i<job_num){
        if(jobs[index].finish<=jobs[i].start){
            break;
        }
        jobs[i].conflicts=true;
        i++;
    }
    check_conflicts(i,job_num);
}