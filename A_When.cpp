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

    int input; cin >> input;
    int hour = 21, min = 0;
    while(input--){
        min++;
        if( min == 60){
            min = 0;
            hour++;
        }
    }
    cout<<hour<<":";
    if( min < 10){
        cout << '0';
    }
    cout << min;
    return 0;

    
    

}