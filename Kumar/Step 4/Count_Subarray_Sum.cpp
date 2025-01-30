#include<bits/stdc++.h>
using namespace std; 

void takevalues( vector <int> &input){
    for(int i = 0; i < input.size(); i++){
        int value;
        cin >> value;
        input.push_back(value);
    }
}
vector <int> prefix_sum(vector <int> &input){
    vector <int> prefix;
    prefix[0] == input[0];
    for(int i = 1; i < input.size(); i++){
        prefix[i] = prefix[i-1] + input[i];
    }
    return prefix;
}


int main(){
    vector < int > input;
    takevalues(input);
    vector < int > prefix = prefix_sum(input);
    
}
