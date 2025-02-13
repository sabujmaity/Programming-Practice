#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n" 
#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef long double ld;


int main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    vector < int > input ;
    int x;
    while(x){
        cin >> x;
        input.push_back(x);
    }
    unordered_set < int > setinput;
    for( int i = 0; i < input.size(); i++){
        setinput.insert(input[i]);
    }
    if( input.size() == setinput.size()){
        cout << "False";
    }
    else {
        cout << "True";
    }

    
    

}