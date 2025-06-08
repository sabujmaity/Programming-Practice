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
        int n, k;
        cin >> n >> k;
        vector <int> b(n);
        int count1 = 0; 
        int first1 = -1;
        int last1 = -1; 

        for (int i = 0; i < n; ++i) {
            long long current_element;
            cin >> current_element;
            if (current_element <= k) {
                b[i] = 1;
                count1++;
                if (first1 == -1) {
                    first1 = i; 
                }
                last1 = i;
            } else {
                b[i] = 0;
            }
        }
        if (count1 < 2) {
            cout << "NO"<< nline;
        } else {
            bool c = ((last1 - first1 + 1) == count1);

            if (c && n > 3 && first1 > 0 && last1 < n - 1) {
                cout << "NO"<<nline;
            } else {
                cout << "YES"<<nline;
            }
        }
    }
    return 0;

}