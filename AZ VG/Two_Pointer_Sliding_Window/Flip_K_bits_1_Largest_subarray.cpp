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
    
    int size, k; cin >> size >> k;
    vector<int>input(size);
    for(int i = 0; i< size; ++i){
        cin >> input[i];
    }

    /* Brute Force Approach */
    /* int length = 0;
    for( int i = 0; i<size; ++i ){
        int count = 0;
        for( int j = i; j<size; ++j){
            if( input[j]==0){
                count++;
            }
            if( count > k){
                break;
            }
            length=max(length, j-i+1); //Untill the count touches k we need to get the max length 
        }
    }
    cout << length; */

    /* Two Pointer Approach - Use Template always  */
    int head = -1, tail = 0;
    int count_zero = 0;
    int ans = 0;
    while(tail < size){
        while( /* There is a next element to eat */head + 1 < size && ( input[head+1]==1||count_zero < k)/* and we can eat it */){
            head++;
            /* Include element at head in the data structure */
            if(input[head] == 0) count_zero++;
        }
        ans = max(ans, head-tail+1);
        if(tail>head){
             /* When we have 0 elements in the window */
            tail++;
            head = tail -1;
        }else{
            /* change ds because of removing tail element */
            if(input[tail] == 0) count_zero--;
            tail++;
        }
    }
    cout << ans << nline;



    
    

}