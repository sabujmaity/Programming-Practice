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
        vector <int> input;
       // ll x, sum = 0;
        for(int j = 0 ; j < 4; j++){
            int x;
            cin >>x;
            input.push_back(x);
            //sum +=x;
        }
        bool f = true;
        for( int i = 1 ; i < input.size(); i++){
            if( input[i] != input[0]){
                f = false;
            }
        }
        if(f){
            cout << "Yes" <<nline;
        }
        else{
            cout << "No" << nline;
        }
    }


}