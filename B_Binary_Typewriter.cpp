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

int calculate_formula( const string &s){
    int n = s.length();
    if(n==0){
        return 0;
    }
    int keff = 0;
    if(s[0] == '1'){
        keff++;
    }
    for( int i = 1; i<n; ++i){
        if(s[i] != s[i-1]){
            keff++;
        }
    }
    return keff;
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        if( n==0){
            cout << 0 << nline;
            continue;
        }

        int keffbase = calculate_formula(s);
        int cbase = n + keffbase;
        int cnt1 = 0;
        int cnt2 = 0;
        for( int i =0; i<n-1; i++){
            if(s[i]=='0' && s[i+1]=='1'){
                cnt1++;
            } else if(s[i] =='1' && s[i+1]=='0'){
                cnt2++;
            }
        }
        bool reduce = (cnt1 >=2) || (cnt2 >= 2) || (s[0] == '1' && cnt1 >= 1);

        int final;
        if( reduce){
            final = cbase - 2;
        } else{
            bool irreducible = false;
            if(keffbase == 1){
                if( n > 0 && s[0] == '1' && cnt1 == 0){
                    irreducible = true;
                } else if(n > 0 && s[0] == '0' && cnt1 == 1 && cnt2 == 0 ){
                    irreducible = true;
                }
            }
        if( irreducible){
            final = cbase;
        } else if( keffbase >=1){
            final = cbase - 1;
        } else{
            final = cbase;
        }
    }
    cout << final << nline;
    }
    return 0;
               
}   