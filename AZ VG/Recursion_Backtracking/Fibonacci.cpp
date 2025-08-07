#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define nline '\n'

int solve(int num){
    if(num <= 1){
        return num;
    } else{
        return solve(num-1) + solve(num-2);
    }
}
signed main(){
    int num;
    cin >> num;
    cout << solve(num);
}