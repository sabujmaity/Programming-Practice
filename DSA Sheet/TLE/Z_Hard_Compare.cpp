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

int M = 1e9+7;

/* long long bpower( long long num, long long pow){
    long long res = 1;
    while(pow>0){
        if(pow & 1){
            res = res * num;
        }
        num = num * num;
        pow >>= 1;
    }
    return res;
} */

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b&1) // To check whether its odd
        return a * (res * 1ll * res);
    else
        return (res * 1ll * res) ;
}

int main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    long long A,B,C,D;
    cin >> A >> B >> C >> D;

   cout << binpow(A,B) << endl;
   cout << binpow(C,D) << endl;

    if( (binpow(A,B) > binpow(C,D)))
        cout << "YES";
    else
        cout << "NO";

    

}