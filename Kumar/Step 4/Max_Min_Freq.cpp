#include<bits/stdc++.h>
using namespace std; 
int main (){
    int size;
    cin >> size;
    int input[size];
    for ( int i = 0; i < size; i++){
        cin >> input[i];
    }
    int maxfreq = 0, minfreq = size-1;
    int maxelement = 0, minelement = 0;
    unordered_map < int , int > frequencies;

    // Hashing of the input array 
    for( int i = 0; i< size; i++){
        frequencies[input[i]]++;
    }

    for( auto it : frequencies){
       int count = it.second;
       int ele =  it.first;

       if ( maxfreq < count){
        maxfreq = count;
        maxelement = ele; 
       }
       if ( count < minfreq){
        minfreq = count;
        minelement = ele;
       }
    }
    cout << maxelement << " " << minelement ;

}