#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;
void left_rotateby_d( int *input, int size, int d){
// Naive Approach ( Three Traversal )
    int temp[d];
    for( int i=0;i<d; i++){
        temp[i]=input[i];
    }
    for( int i=d;i<size;i++){
        input[i-d] = input[i];
    }
    for(int i=0;i<d;i++){
        input[size-d+i] = temp[i];
    }
// Better Approach
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    int input[6]={1,2,3,4,5,6};
    left_rotateby_d(input,6,2);
    for(int i=0;i<6;i++){
        cout<< input[i]<<" ";
    }

    
    

}