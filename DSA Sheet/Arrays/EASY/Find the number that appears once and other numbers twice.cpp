#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach 

/*int brute( int input[],int size){
    for ( int i = 0; i < size; i++ ){
        int num = input[i];
        int count = 0;
        for ( int j = 0; j < size; j++){
            if ( input[j]==num){
                count++;
            }
        }
        if(count == 1)
            return input[i];

    }
}*/


// Better Approach - Hashing using array 

int better_sol( int input[], int size){
    // To get hash array we need to find the max element
    int maxi =  input[0];
    for( int i = 0 ; i < size ; i++){
        maxi = max( maxi, input[i]);
    }
    int hasharr[maxi+1] = {0};  // Making all default value of array = 0
    for( int i = 0; i < size; i++){
        hasharr[input[i]]++;
    }
    for ( int i = 0; i< size; i++){
        if(hasharr[input[i]] == 1)
            return input[i];
    }
    return -1;
}


// Optimal Approach 
/*int optimal_sol( int input[], int size){
    int Xor = 0;
    for( int i = 0; i < size; i++){
        Xor = Xor ^ input[i];
    }
    return Xor;

}*/

int main(){
    int size;
    cin >> size;
    int input[size];
    for(int i =0;i < size; i++){
        cin >> input[i];
    }
    int answer = better_sol(input,size);
    cout << answer;

} 