#include<bits/stdc++.h>
using namespace std;

#define MAX 100
#define DIAGONAL_NILL_ARROW 0 // no op
#define DIAGONAL_ARROW 1 // replace
#define UP_ARROW 2 // delete
#define LEFT_ARROW 3 // insert
#define NO_ARROW -1

string s1,s2;
char x[MAX], y[MAX];
int len1, len2;
int c[MAX][MAX], arrow[MAX][MAX];

void init();
void print_cost_arr();
void print_arrow_arr();
void print_edit_operations(int i, int j);

int main(){

    // freopen("ED.txt", "r", stdin);
    cin >> s1 >> s2;

    len1 = s1.size();
    len2 = s2.size();

    x[len1+1];
    y[len2+1];

    for(int i = 0; i < len1; ++i) x[i+1] = s1[i];
    for(int i = 0; i < len2; ++i) y[i+1] = s2[i];

    c[len1+1][len2+1];
    arrow[len1+1][len2+1];

    init();
    print_cost_arr();
    print_arrow_arr();

    cout << "Edit distance between " << s1 << " to " << s2 << " is: " << c[len1][len2] << endl;
    print_edit_operations(len1, len2);

    return 0;
}

void init(){

    for(int i = 0; i < len1+1; ++i){
        c[i][0] = i;
        arrow[i][0] = UP_ARROW;
    } 
    for(int j = 0; j < len2+1; ++j){
        c[0][j] = j;
        arrow[0][j] = LEFT_ARROW;
    }

    c[0][0] = 0;
    arrow[0][0] = NO_ARROW; 

    for(int i = 1; i < len1+1; ++i){
        for(int j = 1; j < len2+1; ++j){
            
            if(x[i] == y[j]){
                
                c[i][j] = c[i-1][j-1];
                arrow[i][j] = DIAGONAL_NILL_ARROW;
            
            }else{
                // i,j -> cur
                // i-1, j-1 -> Diag (replace)
                // i, j - 1 -> Left (insert)
                // i - 1, j -> Up (delete)
                /* */
                c[i][j] = min(c[i-1][j-1], min(c[i-1][j], c[i][j-1])) + 1; // 1 -> op cost
                
                // // insert < replace && replace < deletion ---> insert (priority 1)
                // if(c[i][j-1] < c[i-1][j-1] && c[i-1][j-1] < c[i-1][j]) arrow[i][j] = LEFT_ARROW; // insert
                // // insert >= replace && replace > deletion ---> Delete 
                // else if(c[i][j-1] >= c[i-1][j-1] && c[i-1][j-1] > c[i-1][j]) arrow[i][j] = UP_ARROW; // delete
                // // else replace
                // else arrow[i][j] = DIAGONAL_ARROW;
                if(c[i][j] - 1 == c[i-1][j-1]) arrow[i][j] = DIAGONAL_ARROW;
                else if(c[i][j] - 1 == c[i-1][j]) arrow[i][j] = UP_ARROW;
                else arrow[i][j] = LEFT_ARROW;            
            } 
        }   
    }

}

void print_cost_arr(){

    // cout << y << endl;
    for(int i  = 0; i < len2 + 1; ++i) 
    for(int i = 0; i < len1+1; ++i){
        cout << x[i] << " ";
        for(int j = 0; j < len2+1; ++j){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

}


void print_arrow_arr(){

    for(int i = 0; i < len1+1; ++i){
        for(int j = 0; j < len2+1; ++j){
            if(arrow[i][j] == DIAGONAL_ARROW)cout << "D" << " ";
            else if(arrow[i][j] == DIAGONAL_NILL_ARROW)cout << "N" << " ";
            else if(arrow[i][j] == LEFT_ARROW) cout << "L" << " ";
            else cout << "U" << " ";
        }
        cout << endl;
    }

}

void print_edit_operations(int i, int j){

    if(arrow[i][j] == NO_ARROW) return;

    if(arrow[i][j] == LEFT_ARROW){
        print_edit_operations(i,j-1);
        cout << "Insert " << y[j] << " in " << s1 << " at index " << i << endl;
    }else if(arrow[i][j] == UP_ARROW){
        print_edit_operations(i-1, j);
        cout << "Delete " << x[i] << " from " << s1 << endl;
    }else if(arrow[i][j] == DIAGONAL_ARROW){
        print_edit_operations(i-1, j-1);
        cout << "Replace " << x[i] << " by " << y[j] << endl;
    }else{
        print_edit_operations(i-1, j-1);
    }

}