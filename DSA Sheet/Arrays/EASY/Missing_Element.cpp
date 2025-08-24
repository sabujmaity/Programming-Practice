#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef long double ld;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int size; cin >> size;
    vector<int> nums;
    for( int i = 0; i < size; ++i){
        cin >> nums[i];
    }
    
    vector<int> hash(size+1);
    for(int i = 0; i <size; ++i){
        hash[nums[i]] = i;
    }

}