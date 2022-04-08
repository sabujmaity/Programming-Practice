#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    string s = "Sabuj";
    string s1(s);                 // Copying the string functionality

    string s2 (s,1,4);           // Copying string into another string

    string s3 = s.substr(1,4);   // Substring Functionality 

    cout<< s3 << "\n";
    
    if(s2.compare(s3)== 0){      // To compare the the strings 
        cout<< "Equal" << "\n";
    }
    
    

}