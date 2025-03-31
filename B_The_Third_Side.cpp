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
        ll size; cin >> size;
        priority_queue < int > input;
        for( int i = 0; i < size ; i++){
            int x; cin >> x;
            input.push(x);
        }

        while(input.size() > 1){
            int first = input.top(); input.pop();
            int sec = input.top(); input.pop();
            int x = first + sec - 1;
            input.push(x);
        }
        cout << input.top() << nline;
    }


}