#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;
/* 
void take_values(int *input[][], int row , int col){
    
} */



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    
    int matrix1[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int matrix2[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int res [3][3];
    for( int i = 0; i < 3; i++){
        for( int j = 0; j< 3 ;j++){
            res[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    // Usage of for - each loop
    for( auto& i : res){
        for( auto& j :i){
            cout << j << " ";
        }
        cout << "\n";
    }


}