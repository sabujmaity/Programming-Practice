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




signed main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int size; 
    cin >> size;
    vector <int> input(size);

    for(auto &it : input){
        cin >> it;
    }
    /* for(auto &it : input){
        cout << it << " ";
    } */
    
    // Follow this structure strictly blindly as stated by VG
    int low = 0;
    int high = size -1;
    int ans = -1;
    while( low <= high){ // understand the search space inclusive 
        /* int mid = (low + high)/2; */
        int mid = low +((high - low)/2);
        if(input[mid] == 0){
            low = mid + 1;  // trying to reduce the search space 
        } else if ( input[mid] == 1){
            ans = mid;
            high = mid - 1; // trying to reduce the search space 
        }
    }
    cout << ans << nline;
    
    
    

}