#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n" 
#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef long double ld;

void get_input( ll input[], ll size){
    for( ll i=0; i<size; i++){
        cin >> input[i];
    }
}


int main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    ll size,target;
    cin >> size >> target;
    ll input[size];
    get_input(input, size);

    ll count = 0, sum = 0;
    for( int i = 0, j = 0 ; j < size; j++){
        sum += input[j];

        while ( sum > target){
            sum = sum - input[j];
            i++;
        }
        count +=(j-i+1);
    }

    cout << count;
    return 0;

    

    
    

}