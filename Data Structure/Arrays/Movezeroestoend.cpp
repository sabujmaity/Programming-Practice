#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

void movezeroestoend(int *input, int size){
    int count = 0;
    for(int i=0;i<size;i++){
        if(input[i]!=0){
            input[count] = input[i];
            count++;
        }
    }
    // Making Remaining Elements zero
    while(count<size){
        input[count++]=0;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int input[6]={1,0,2,0,0,6};
    movezeroestoend(input,6);
    for(int i=0;i<6;i++){
        cout<< input[i]<<" ";
    }

    
    

}