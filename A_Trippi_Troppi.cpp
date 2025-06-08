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

void solve(){
    string input;
    getline(cin,input);

    cout << input[0];

    for( int i = 1; i < input.length(); i++){
        if( input[i-1]==' ' && input[i]!=' '){
            cout << input[i];
        }
    }

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
    //cin.ignore();
    while(t--){
        string a,b,c;
        cin >> a >> b >>c;
        cout << a[0] << b[0] << c[0];
        /* solve();
        cout << nline; */
        cout << nline;
    }


}