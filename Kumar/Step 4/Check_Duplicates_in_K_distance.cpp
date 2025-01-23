#include <bits/stdc++.h>
using namespace std;


int main(){
    int size, distance;
    cin >> size >> distance;
    int input[size];
    for ( int i = 0; i < size; i++){
        cin >> input[i];
    }
    // Brute Force Approach:
    /* for( int i = 0; i < size; i++){
        for ( int j = i+1; j<=(distance+i) && j<size; j++){
            if( input[i] == input[j]){
                if((j-i)<=distance){
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";
    return 0; */

    // Optimal using Hashing 
    unordered_map <int, int > elements;
    for ( int i = 0; i < size; i++){
        if( elements.find(input[i])==elements.end()){
            elements[input[i]] = i;
        }
        else{
            if( i - elements[input[i]] <= distance){
                cout << "Yes";
                return 0;
            }
        elements[input[i]]=i;
        }
    }
    cout << "No";

}