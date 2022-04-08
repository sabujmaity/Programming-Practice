#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

int countLength( char input[]){
    int i = 0;
    for( i = 0; input[i]!=0; i++);
    return i;
}

void reverseString( char input []){
    int length = countLength( input );
    int i = 0, j = length - 1;
    while( i < j){
        int temp = input[i];
        input[i++] = input[j];
        input[j--] = temp;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    char input [100];
    cin.getline(input , 100);

    reverseString(input);
    cout<< input ;


    
    

}