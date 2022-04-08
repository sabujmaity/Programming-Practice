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
    int input[] = {1,4,3,5,9,2};
    int i;
    sort( input, input+6);
    fo(i,6){
        cout << input[i] << " ";
    }
    cout << "\n";
    sort( input , input + 6 , greater <int> ());   // Sorting in decreasing order functionality
    int j;
    fo(j,6){
        cout << input[j] << " ";
    }

    
    

}