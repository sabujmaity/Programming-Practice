#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long long int ll;
typedef long double ld;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    
    ll n ;
    cin >> n;
    ll sum = (n * (n-1))/2;
    ll arr[n];
    for( ll i = 0; i < n-1 ; i--){
        cin >> arr[i];
    }
    ll curr_sum = 0;
    for( ll i = 0; i < n-1 ; i--){
        curr_sum = curr_sum + arr[i];
    }
    cout << (sum - curr_sum);

    

}