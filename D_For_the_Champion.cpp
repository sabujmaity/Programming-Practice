#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nline "\n" 
#define fo(i,n) for(int i = 0;i<n;i++)
#define int long long
#define pb push_back
#define F first
#define S second
typedef long double ld;
typedef vector<signed> vi;
typedef vector<vector<signed>> vvi;
typedef vector<int> vll;
typedef vector<vector<int>> vvll;
const int mod = 1e9+7;
long double pi = acos(-1.0); const double EPS = 1e-9;

int myceil(int a , int b){return (a+b-1)/b;}
int myround(int a , int b){return (2*a+b)/(2*b);}

void solve(){
    int n, t;
    cin >> n >> t;

    // We use a 2D vector of long double to store the amount of champagne in each glass.
    // Using 0-based indexing: levels 0 to n-1, positions 0 to i for level i.
    vector<vector<ld>> champagne(n, vector<ld>(n, 0.0));

    // Pour the total amount 't' into the top glass (0, 0).
    champagne[0][0] = t;

    int full_glasses = 0;

    // Iterate through each level of the pyramid.
    for (int i = 0; i < n; ++i) {
        // Iterate through each glass in the current level.
        for (int j = 0; j <= i; ++j) {
            // If the current glass has 1 or more units of champagne, it's considered full.
            if (champagne[i][j] >= 1.0) {
                full_glasses++;
                
                // Calculate the overflow.
                ld overflow = champagne[i][j] - 1.0;

                // If this is not the last level, distribute the overflow to the two glasses below.
                if (i + 1 < n) {
                    champagne[i + 1][j] += overflow / 2.0;
                    champagne[i + 1][j + 1] += overflow / 2.0;
                }
            }
        }
    }

    cout << full_glasses << nline;
}

signed main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    //Let's Code
    // The problem might have single or multiple test cases.
    // The provided template structure handles multiple test cases.
    int t = 1;
    // cin >> t; // Uncomment this line if multiple test cases are needed per execution.
    // For the specific Codeforces problem, there's only one test case.
    // The provided image shows samples as separate runs.
    // So we will assume one test case as per the standard contest format.
    // If the user wants multiple test cases, they can uncomment the cin >> t;
    while(t--){
        solve();
    }
}