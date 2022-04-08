#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

// Approach 1 (Naive Approach)
int removeduplicates(int *input, int size){
   /*  int temp[size];
    temp[0] = input[0];
    int res = 1;
    for(int i=1;i<size;i++){
        if(temp[res-1]!=input[i]){
            temp[res]=input[i];
            res++;
        }
    } */
    int res=1;
    for(int i=1;i<size;i++){
        if(input[i]!=input[res-1]){
            input[res]=input[i];
            res++;
        }
    }
    for(int i=0;i<res;i++){
        cout<< input[i]<<" ";
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int input[5]={10,10,20,20,30};
    removeduplicates(input,5);

    
    

}