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
    ll a; // The earlier code was ok but due to overflow it was not able to calculate
    cin >> a;
    cout << a << " ";
    while(a > 1){
        if (a % 2 == 0){
            a = a/2;
            cout << a << " ";
        }
        else{
            a = a*3 + 1; 
            cout << a << " ";
        }
    }

    
    

}