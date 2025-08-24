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
    vector<int>input;
    for( int i = 0; i < size; ++i){
        int x; cin >> x;
        input.emplace_back(x);
        /* cin>> input[i]; */
    }

    /* for( int i = 0; i < size; ++i){
        cout << input[i] << " ";
    } */

    for(int i = 0; i <=size-2; ++i){
        int min = i;
        for( int j = i; j <=size-1; ++j){
            if(input[j] < input[min] ){
                min = j;
            }
        }
        swap(input[i],input[min]);
    }
    for( int i = 0; i < size; ++i){
        cout << input[i] << " ";
    }




    
    
    

}