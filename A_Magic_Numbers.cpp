#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
signed main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    string num;
    cin >> num;
    int i = 0;
    int n = num.length();
    while(i < n){ 
        if(num.substr(i,3) == "144"){
            i+=3;
        } else if( num.substr(i,2)== "14"){
            i+=2;
        } else if( num.substr(i,1)=="1"){
            i+=1;
        } else {
            cout << "NO" << nline;
            return 0;
        }
    }
    cout << "YES" << nline;
    return 0;
}