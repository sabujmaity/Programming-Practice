#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

void leftroatatebyone(int *input, int size){
    int temp = input[0];
    for(int i=1;i<size;i++){
        input[i-1] = input[i];
    }
    input[size-1] = temp;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    int input[6]={1,2,3,4,5,6};
    leftroatatebyone(input,6);
    for(int i=0;i<6;i++){
        cout<< input[i]<<" ";
    }

    
    

}