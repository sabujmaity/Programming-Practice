#include<bits/stdc++.h>
using namespace std;

void solve(){
    string input;
    cin >> input;
    int maxcount = 0, curr_count = 1;
    for(int i = 0; i < input.size(); ++i){
        if( input[i] == input[i+1]){
            curr_count++;
        }else{
            maxcount = max(curr_count,maxcount);
            curr_count = 1;
        }
    }
    cout << maxcount;
    return ;
}

int main(){
    solve();
}