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

    float num;
    cin >> num;

    /* if(floor(num)==ceil(num)){
        cout << "int" << " " << (int)num;
    } */

    float check = num - floor(num);
    if(check == 0){
        cout << "int" << " " << (int)num; 
    }
    else {
        cout << "float" << " " << (int)num << " " << setprecision(3)<<check;
    }

    
    

}