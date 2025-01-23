#include<bits/stdc++.h>
using namespace std;
int main(){
    int size, target;
    cin >> size >> target;
    int input[size];
    for ( int i = 0; i < size; i++){
        cin >> input[i];
    }
    
    unordered_set < int > diff;
    for( int i = 0; i < size; i++){
        int temp = target - input[i];
        if( diff.find(temp)!=diff.end()){ // The difference is present in the set 
            cout << temp << ","<< input[i];
            return 0;
        }
        diff.insert(input[i]);
    }
    cout << "No Exist";
    return -1;
}