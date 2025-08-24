#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nline "\n" 
#define int long long
#define fo(i,n) for(int i = 0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long double ld;
typedef vector<signed> vi;
typedef vector<vector<signed>> vvi;
typedef vector<int> vll;
typedef vector<vector<int>> vvll;
const int mod = 1e9+7;
long double pi = acos(-1.0); const double EPS = 1e-9;

int myceil(int a , int b){return (a+b-1)/b;}
int myround(int a , int b){return (2*a+b)/(2*b);}

void solve(){
    
}

signed main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int size; cin >> size;
    vector<int>input(size);
    for( int i = 0; i < size; ++i){
        cin >> input[i];
    }

    for( int i = size-1; i>=0; --i){
        for( int j = 0; j<=i-1; ++j){
            if( input[j] > input[j+1]){
                swap(input[j+1],input[j]);
            }
        }
    }

    for( int i = 0; i < size; ++i){
        cout << input[i] << " ";
    }
    
    
    

}