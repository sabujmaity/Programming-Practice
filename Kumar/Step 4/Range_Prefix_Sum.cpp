#include <bits/stdc++.h>
using namespace std;

void takevalues( vector <int> &input){
    for(int i = 0; i < input.size(); i++){
        int value;
        cin >> value;
        input.push_back(value);
    }
}

vector <int> prefix_sum( vector <int> &input){
    vector <int> prefix_array;
    prefix_array[0] = input[0];
    for ( int i = 1; i < input.size(); i++){
        prefix_array[i] = prefix_array[i-1] + input[i];
    }
    return prefix_array;
}

int main(){
    vector < int > input;
    takevalues(input);
    vector<int> prefix_array = prefix_sum(input);
    int t;
    cin >> t;
    while(t--){
    int l,r;
    cin >> l >> r;
    int result = prefix_array[r] + prefix_array[l-1];
    cout << result;
    }
    return 0;
    
}