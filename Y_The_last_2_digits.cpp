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


int main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    int product = ((a % 100)*(b % 100)*(c % 100)*(d % 100))%100;
    if(product < 10){
        cout <<0<<product;
    }
    else{
        cout << product;
    }
    return 0;


    
    

}