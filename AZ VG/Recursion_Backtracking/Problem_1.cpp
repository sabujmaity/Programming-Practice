/* Given a N - Find ABCDE/FGHIJ = N */

#include<bits/stdc++.h>
using namespace std;
#define nline '\n'

void solve1(int n){
    // Brute Force checking every permutation
    string str = "1234567890";
    //we want to take the substrings of 5 digits 
    do{
        int num = stoi(str.substr(0,5));
        int den = stoi(str.substr(5,5));

        if(num %den == 0 && num/den == n){
            cout << num << " " << den << nline;
        }

    }while(next_permutation(str.begin(), str.end()));
}

void solve2(int n){
    // Think mathematically - another approach just divide the abcde/n can get us fghij
    for( int fghij = 01234; fghij<= 98765/n; fghij++ ){
        int abcde = fghij * n;

        set <int> st;
        int temp;

        temp = fghij;
        for( int i = 0; i < 5; i++){
            st.insert(temp%10);
            temp /=10;
        }
        temp = abcde;
        for( int i = 0; i < 5; i++){
            st.insert(temp%10);
            temp /=10;
        }
        if(st.size() == 10){
            cout << abcde << " " << fghij;
        }

    }
}


int main(){
    int n ;
    cin >> n;
    solve1(n);
}

