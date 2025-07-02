#include<bits/stdc++.h>
using namespace std;

#define int long long
#define nline '/n'

signed main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif


    int size, Q;
    cin >> size >> Q;
    vector <int> input(size,0); // Intialize with 0 and size

    while(Q--){
        int L, R, x;
        cin >> L >> R >> x;

        // The operation is simplified by modifying the array then taking prefix sum
        input[L]+=x;
        if( R < size){
            input[R+1]-=x;
        }
        //Now take the prefix sum concept
        for( int i = 1; i < size; ++i){
            input[i] = input[i] + input[i-1];
        }

    }
    // Final output of the array
    for( int i = 0 ; i < size; ++i){
            cout << input[i] << " ";
        }
}