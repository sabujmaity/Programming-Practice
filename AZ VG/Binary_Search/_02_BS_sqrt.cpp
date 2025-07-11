#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nline "\n" 
#define int long long
#define fo(i,n) for(int i = 0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long double ld;
typedef vector<signed> vi;
typedef vector<vector<signed>> vvi;
typedef vector<int> vll;
typedef vector<vector<int>> vvll;
const int mod = 1e9+7;

int check(int y, int x){
    // y*y might overflow so taking high = 1e9
    if(y*y > x) return 1;
    else return 0;
}

void solve(){
    int x; 
    cin >> x;
    int low = 0, high = 1e9;
    int ans = high + 1; //int ans = -1; why not this ? understand
    while( low <= high){
        // Correct way to calculate the mid in interviews
        int mid = low +((high - low)/2);    // sum can overflow in the realm of int
        if( check(mid,x) == 0){
            low = mid + 1; // modifying the search space
        } else {
            ans = mid;
            high = mid - 1;
        }
    }
    cout << (ans - 1) << nline;


    
}

signed main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    solve();
    
    
                
    

}