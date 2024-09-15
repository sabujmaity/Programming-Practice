#include<bits/stdc++.h>
using namespace std;

int max_conse_ones( int input[], int size){
    int maxi = 0;
    int count = 0;
    for( int i = 0; i < size; i++){
        if(input[i]==1)
            count++;
        else
            count = 0;
        maxi = max(count,maxi);
    }
    return maxi;
}

int main(){
    int size;
    cin >> size;
    int input[size];
    for( int i = 0; i < size; i++){
        cin >> input[i];
    }
    int answer = max_conse_ones( input, size);
    cout << answer;

}