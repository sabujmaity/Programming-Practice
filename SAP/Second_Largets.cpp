#include<bits/stdc++.h>
using namespace std;

void solve(){
    //int size;
    vector<int> input;
    int x;
    while(cin >> x){
        input.push_back(x);
    }
    int largest = -1, secondlargest = -1;
    int size = input.size();
    for( int i = 0; i < size-1; i++){
        if( input[i] > largest){
            secondlargest = largest;
            largest = input[i];
        }
        else if( input[i] < largest && input[i] > secondlargest){
            secondlargest = input[i];
        }
    }
    cout << secondlargest;
}

int main(){
    solve();
}