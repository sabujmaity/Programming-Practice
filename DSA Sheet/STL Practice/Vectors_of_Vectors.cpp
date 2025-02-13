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

/* void print_v( vector< vector < int > > &v){
    for( int i = 0; i < v.size(); i++){
        for( int j = 0; j < v[i].size(); j++){
            cout << v[i][j]<< " ";
        }
        cout << endl;
    }
}
 */

void print_v(vector< int > &v){
    for( int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}

int main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int N;
    cin >> N;
    vector< vector < int > > v;
    for ( int i = 0; i<N ; i++){
        int n;
        cin >> n;
        vector < int > temp;
        for ( int j = 0; j<n; j++){
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp); // Thinking should be what v is waiting for the push_back function to enter depends upont he decalaration 
    }
    for (int k = 0 ; k < v.size(); k++){
        print_v(v[k]);
        cout << endl;
    }
     // print_v(v);

    
    

}