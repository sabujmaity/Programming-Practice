#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;
// Approach 1 (Naive Approach)
/* bool checksortedarray(int *input, int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(input[i]>input[j])
                return false;
        }

    }
    return true;
}
 */
bool checksortedarray(int *input, int size){
    for(int i=1;i<size;i++){
        if(input[i-1]>input[i])
            return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int input[5]={1,2,3,4,5};
    bool val = checksortedarray(input,5);
    if(val)
        cout<<"Sorted";
    else
        cout<<"Not Sorted";
    

}