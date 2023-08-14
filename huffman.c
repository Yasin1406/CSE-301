#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
    int freq;
    char ch;
    node *left;
    node *right;
};

void sortArray(node **queue,int s,int n);

node *createNode(node *l,node *r);

void printArray(node *root,int *arr,int top);

int main(){
    int n,i,j;
    node *temp=(node*)malloc(sizeof(node));
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    node **queue=(node**)malloc(sizeof(node*)*n);
    for(i=0;i<n;i++){
        queue[i]=(node*)malloc(sizeof(node));
    }
    
    
    for(i=0;i<n;i++){
        queue[i]->ch=i+65;
        printf("Enter frequency of '%c': ",queue[i]->ch);
        scanf("%d",&queue[i]->freq);
        queue[i]->left=queue[i]->right=NULL;
    }

    sortArray(queue,0,n);

    for(i=0;i<n-1;i++){
        queue[i+1]=createNode(queue[i],queue[i+1]);
        sortArray(queue,i+1,n);
    }

    for(i=0;i<n;i++){
        printf("%d\t",queue[i]->freq);
    }
    printf("\n");
    int arr[n];
    printArray(queue[n-1],arr,0);
    return 0;
}

void sortArray(node **queue,int s,int n){
    int j;
    node *temp=(node*)malloc(sizeof(node));
    for(;s<n;s++){
        for(j=s+1;j<n;j++){
            if(queue[s]->freq>queue[j]->freq){
                temp=queue[s];
                queue[s]=queue[j];
                queue[j]=temp;
            }
        }
    }
}

node *createNode(node *l,node *r){
    node *temp=(node*)malloc(sizeof(node));
    temp->freq=l->freq+r->freq;
    temp->ch='X';
    temp->left=l;
    temp->right=r;
    return temp;
}

void printArray(node *root,int *arr,int top){
    if(!root->left&&!root->right){
        printf("%c: ",root->ch);
        for(int i=0;i<top;i++){
            printf("%d",arr[i]);
        }
        printf("\n");
        return;
    }
    if(root->left){
        arr[top]=0;
        printArray(root->left,arr,top+1);
    }
    if(root->right){
        arr[top]=1;
        printArray(root->right,arr,top+1);
    }
}