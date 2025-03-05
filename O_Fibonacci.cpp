#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nline "\n" 
#define fo(i,n) for(int i = 0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;


int main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    long long num;
    cin >> num;

    long long first = 0, second = 1, third;
    if( num == 1){
        cout << 0;
    }
    else if( num == 2){
        cout << 1;
    }
    else{
        while(num > 2){
            third = first + second;
            first = second;
            second = third;
            num--;
        }
        cout << third;
    }
    return 0;
    
    

}