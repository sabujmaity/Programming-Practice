#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'

int target;
vector < int > input;
int check(int m){
    if(input[m] > target){
        return 1;
    } else{
        return 0;
    }
}

signed main(){
    int size ; cin >> size >> target;
    input.resize(size);
    for(int i = 0; i < size; ++i){
        cin >> input[i];
    }

    int low = 0, high = size-1, ans = high + 1;
    while( low <= high){
        int mid = low + (high-low)/2;
        if(check(mid) == 1){
            ans = mid;
            high = mid - 1;
        }else if(check(mid) == 0){
            low = mid + 1;
        }
    }
    cout << ans;


}
