#include<bits/stdc++.h>
using namespace std;

// Naive Approach
int subarray_sum( int arr[], int n, int target){
    int length = 0;
    for( int i = 0; i < n; i++){
        long long sum = 0;
        for( int j = i; j < n; j++){
            sum += arr[j];
            if( sum == target){
                length = max(length, j-i+1);
            }
        }
    }
    return length;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    int size, target;
    cin >> size >> target;
    int inputarr[size];
    for(int i = 0 ; i < size; i++){
        cin >> inputarr[i];
    }
    int result = subarray_sum( inputarr, size, target);
    cout << result;

}