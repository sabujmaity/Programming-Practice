#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

void reverse(int *input, int size){
    int low = 0, high = size-1;
    while(low<high){
        int temp = input[low];
        input[low] = input[high];
        input[high] = temp;
        low++;
        high--;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    
    int input[6]={1,2,3,4,57,78};
    reverse(input,6);
    for(int i=0;i<6;i++){
        cout<<input[i]<<" ";
    }

    
    

}