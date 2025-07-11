#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nline '\n'
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
long double pi = acos(-1.0);


void solve(){
    int n;
    cin >> n;
    // Dummy to handle cin and getline
    string temp;
    getline(cin, temp);
    string arr[n];
    for(int i = 0; i < n; i++){
        //cin >> arr[i];
        getline(cin,arr[i]);
    }
    // Print in the reverse order
    for ( int i = n-1; i>=0; i--){
        cout << "Hi " << arr[i] << " !" << nline;
    }
}

void area_circle(){
    long double R;
    cin >> R;
    cout << pi * R * R << nline;
}

void sum_of_num(){
    int n;
    cin >> n;
    cout << n *(n+1)/2;
}

//internal fucntion can lead to loss of information
void floor_ceil_round(){
    int a,b;
    cin >> a >> b;
    int floor, ceil , round;
    //Correct way of calculating the floor, ceil and round
    floor = a/b;
    ceil = (a+b-1)/b;
    round = (2*a+b)/(2*b);
    cout << floor << nline << ceil << nline  << round << nline;
}

signed main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    
    
    

}