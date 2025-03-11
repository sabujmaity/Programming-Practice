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

    //Brute force Approach -> increment the year by one & check for the uniquness enter the number into the set
    int n ; cin >> n;
    n++;
    while(true){
        string temp = to_string(n); // function to convert the int to string 
        bool flg = true;
        // check distinctiveness
        int size = temp.size();
        for( int i = 0; i < size ; i++){
            for( int j = i+1; j < size ; j++){
                if(temp[i]==temp[j]){
                    flg = false;
                    break;
                }
            }
        }
        if(flg){
            cout << n;
            return 0;
        }
        n++;

    }

    
    

}