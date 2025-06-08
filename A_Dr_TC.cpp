#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nline "\n" 
#define fo(i,n) for(int i = 0;i<n;i++)
#define pb push_back
#define F first
#define S second
#define int long long
typedef long double ld;
typedef vector<signed> vi;
typedef vector<vector<signed>> vvi;
typedef vector<int> vll;
typedef vector<vector<int>> vvll;
const int mod = 1e9+7;



signed main() {

    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    
    int t; 
    cin >> t; 
    while (t--) {
        int n; 
        cin >> n;
        string s; 
        cin >> s; 
        
        int N1 = 0; 
        
        for (char c : s) {
            if (c == '1') {
                N1++;
            }
        }
        int N0 = n - N1;
        
        
        int total_ones = N1 * (int)(n - 1) + N0;
        cout << total_ones << nline;
    }
    return 0; 
}