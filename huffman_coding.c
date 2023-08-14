#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
    int freq;
    char ch;
    node *left;
    node *right;
};

node *createNode(node *l,node *r);

void sortArray(node *queue[],int n);

void printArray(node *root,int *arr,int top);

int main(){
    int n,i,j;
    node * temp = (node*)malloc(sizeof(node));
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
    
    i=0;
    while(i<n-1){
        
       // printf("\n");
        sortArray(queue,n);
        // printf("After sorting (%d to %d):\n",i,n-1);
        // for(j=0;j<n;j++){
        //     printf("%d: %d\t\t",j,queue[j]->freq);
            
        // }
        printf("\n");
        temp=createNode(queue[0],queue[1]);
        // queue[0]->freq=temp->freq;
        // queue[0]->ch = temp->ch;
        // queue[0]->left = temp->left;
        // queue[0]->right = temp->right;
       queue[0]=temp;
        queue[1]->freq=__INT_MAX__;
       // printf("Temp frequency: %d\n",temp->freq);
        // sortArray(queue,n);
        i++;
        //free(temp);
    }
    int arr[n];
    printArray(temp,arr,0);
   // printf("%c",temp->right->right->right->ch);
    return 0;
}

node *createNode(node *l,node *r){
    node *temp=(node*)malloc(sizeof(node));
    temp->freq=l->freq+r->freq;
    temp->left=l;
    temp->right=r;
    temp->ch='X';
    return temp;
}

void sortArray(node *queue[],int n){
    node *tmp=malloc(sizeof(node));
    int i,j;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(queue[i]->freq>queue[j]->freq){
                tmp=queue[i];
                queue[i]=queue[j];
                queue[j]=tmp;
            }
        }
    }
}

void printArray(node *root,int *arr,int top){
    if(root->left == NULL && root->right==NULL){
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