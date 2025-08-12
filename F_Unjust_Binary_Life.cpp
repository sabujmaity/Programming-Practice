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
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    vll pA(n + 1, 0);
    vll pB(n + 1, 0);

    for (signed i = 0; i < n; ++i) {
        pA[i + 1] = pA[i] + (a[i] - '0');
        pB[i + 1] = pB[i] + (b[i] - '0');
    }

    struct item {
        int key;
        int ones;
        int zeros;
        bool operator<(const item& other) const {
            return key < other.key;
        }
    };

    vector<item> V(n);
    for (signed y = 1; y <= n; ++y) {
        V[y - 1] = {
            2 * pB[y] - y,
            pB[y],
            y - pB[y]
        };
    }

    sort(V.begin(), V.end());

    vll ps_ones(n, 0);
    vll ps_zeros(n, 0);

    if (n > 0) {
        ps_ones[0] = V[0].ones;
        ps_zeros[0] = V[0].zeros;
        for (signed i = 1; i < n; ++i) {
            ps_ones[i] = ps_ones[i - 1] + V[i].ones;
            ps_zeros[i] = ps_zeros[i - 1] + V[i].zeros;
        }
    }

    int ans = 0;
    int total_zeros = (n > 0) ? ps_zeros[n - 1] : 0;

    for (signed x = 1; x <= n; ++x) {
        int c1 = pA[x];
        int c0 = x - c1;
        int k = x - 2 * c1;

        auto it = upper_bound(V.begin(), V.end(), item{k, 0, 0});
        signed cnt = distance(V.begin(), it);
        signed p = cnt - 1;
        
        int to_add = 0;

        if (cnt > 0) {
            int sz = cnt;
            int s_ones = ps_ones[p];
            to_add += sz * c1 + s_ones;
        }
        
        if (cnt < n) {
            int sz = n - cnt;
            int s_zeros_pref = (p >= 0) ? ps_zeros[p] : 0;
            int s_zeros = total_zeros - s_zeros_pref;
            to_add += sz * c0 + s_zeros;
        }
        
        ans += to_add;
    }

    cout << ans << nline;
}

signed main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    //Let's Code
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}