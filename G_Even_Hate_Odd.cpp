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
        int size;
        cin >> size;
        if(size%2!=0){
            cout << -1;
            return 0;
        }
        int input[size];
        for( int i = 0; i < size ; i++){
            cin >> input[i];
        }
        int count = 0;
        for( int j =0; j < size; j++){
            if(input[j]%2!= 0){
                count++;
            }
        }
        cout << abs(size/2 - count) << nline;
    }


}