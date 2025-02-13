#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n" 
#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef long double ld;

long long sum( long long num){
    long long ans = num * 1LL * (num + 1)/2 ;
    return ans;
}


int main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    //Let's Code
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin >> l >> r;
        if( l > r){
            swap(l,r);
        }
        ll result = sum(r) - sum(l-1);
        cout << result << endl;
        
    }


}