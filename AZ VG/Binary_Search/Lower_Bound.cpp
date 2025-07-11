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


int x; 
vector <int> input;

int check(int m){
    if( input[m] >= x){
        return 1;
    } else{
        return 0;
    }
}

void solve(){
    int size;
    cin >> size >> x;
    input.resize(size);
    for(int i = 0; i < size; ++i){
        cin >> input[i];
    }

    //Lower Bound
    int low = 0, high = size-1, ans = high + 1;
    while( low <= high ){
        int mid = low + ((high - low)/2);
        if(check(mid) == 1){
            ans = mid;
            high = mid - 1;
        } else if( check(mid)== 0){
            low = mid + 1;
        }
    }
    cout << ans << nline;

}

signed main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    
    solve();
    
    

}