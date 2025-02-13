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

    int K, S;
    cin >> K >> S;
    
    /* vector < int > input;
    fo(i,K+1){
        input.pb(i);
    } */
    ll count = 0;

    /* fo(i,K+1){
        fo(j,K+1){
            fo(l,K+1){
                sum = input[i]+input[j]+input[l];
                if(sum == S){
                    count++;
                }
            }
        }
    } */

    fo(i,K+1){
        fo(j,K+1){
            ll Z = S - (i+j);
            if(Z >= 0 && Z <= K){
                count++;
            }
        }
    }
    cout << count;

    
    

}