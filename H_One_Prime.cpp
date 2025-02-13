#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nline "\n" 
#define fo(i,n) for(int i = 1;i<=n;i++)
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef long double ld;


int main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    ll ip;
    cin >> ip;
    int cnt = 0;
    fo(i,ip){
        if(ip % i== 0)
            cnt++;
    }
    if(cnt == 2)
        cout << "YES";
    else
        cout << "NO";
    return 0;

    
    

}