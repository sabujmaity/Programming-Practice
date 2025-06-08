#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nline "\n" 
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




bool can_complete(const vector<int>& current_counts, int start) {
    vector<int> reqs;
    int num_positions_left = 0;
    for (int j = start; j <= 10; ++j) {
        reqs.pb(max(0, 10 - j)); 
        num_positions_left++;
    }

    vector<int> available_digits_desc;
    int total_available = 0;

    for (int d = 9; d >= 0; --d) {
        for (int k = 0; k < current_counts[d]; ++k) {
            available_digits_desc.pb(d);
        }
        total_available += current_counts[d];
    }

    if (total_available < num_positions_left) {
         return false; 
    }

    for (int k = 0; k < num_positions_left; ++k) {
        if (available_digits_desc[k] < reqs[k]) {
            return false;
        }
    }
    
    return true; 
}

signed main() {
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        vector<int> counts(10, 0); 
        for (char c : s) {
            counts[c - '0']++;
        }
        
        string result = "";
        for (int i = 1; i <= 10; ++i) {
            int req = max(0, 10 - i);
            for (int d = req; d <= 9; ++d) {
                if (counts[d] > 0) {
                    counts[d]--;
                    if (can_complete(counts, i + 1)) { 
                        result += to_string(d);
                        break;
                    } else {
                        counts[d]++;
                    }
                }
            }
        }
        
        cout << result << nline;
    }
    return 0;
}
