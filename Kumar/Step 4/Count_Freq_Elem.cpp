#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* void bruteforce( int query, int size, int input[]){
    int count = 0;
        for ( int j = 0; j < size; j++){
            if ( query == input[j]){
                count++;
            }
        }
        cout << count;
} */

/* void better( int query, int size, int input[]){
    int hasharr[51] = {0};
    for ( int j = 0; j < size; j++){
        hasharr[input[j]]++;
    }
    int freq = hasharr[query];
    cout << freq;
} */
void optimal( int query, int size, int input[]){
    unordered_map < int , int > hashmap;
    for ( int i = 0 ; i < size; i++){
        hashmap[input[i]]++;
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int size;
        cin >> size;
        int input[size];
        for ( int i = 0; i < size ; i++){
            cin >> input[i];
        }
        int query;
        cin >> query;

        /* bruteforce( query, size, input); */
        /* better( query, size, input); */
        optimal ( query, size, input);
        
        

    }

}
