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

    long double A , B;
    cin >> A >> B;
    long double res = A/B;

    
    cout << "floor" << " " << A << " "<< "/" << " " << B << " " << "=" <<" " << floor(res) << nline;
    cout << "ceil" << " " << A << " "<< "/" << " " << B << " " << "=" <<" " << ceil(res) << nline;
    cout << "round" << " " << A << " "<< "/" << " " << B << " " << "=" <<" " << round(res) << nline;

    
    

}