#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

// Approach 1 (Naive Approach)
void leader_elements( int *input, int size ){
    /* for(int i=0;i<size;i++){
        bool flag = false;
        for(int j=i+1;j<size;j++){
            if(input[j]>input[i]){
                flag = true;
                break;
            }
        }
        if(flag == false)
            cout<<input[i]<<" ";
    } */
    // Approach 2 (optimised)
    int curr_lead = input[size-1];
    cout<< curr_lead<<" ";
    for(int i= size-2;i>=0;i--){
        if(input[i]>curr_lead){
            cout<< input[i];
            curr_lead = input[i];
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int input[6]={1,200,26,4,57,78};
    leader_elements(input,6);

    
    

}