#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nline "\n" 
#define fo(i,n) for(int i = 0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;


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
    int skills[4];
    for ( int i = 0; i < 4 ; i++){
        cin >> skills[i];
    }
    int win, win1;
    if( skills[0] > skills[1])
        win = skills[0];
    else
        win = skills[1];
    
    if( skills[2] > skills[3])
        win1 = skills[2];
    else
        win1 = skills[3];
    
    sort(skills,skills+4);
    if( (win == skills[2] && win1==skills[3])||(win == skills[3] && win1==skills[2]))
        cout << "YES"<< nline;
    else
        cout << "NO" << nline;

}
}