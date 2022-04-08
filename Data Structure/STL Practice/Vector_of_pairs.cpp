#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

void printVector( vector < pair < int,int > > &v){
    for ( int i = 0; i < v.size(); i++){
        cout<< v[i].first << " " << v[i].second << "\n";
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    vector < pair < int , int > > v ={ {2,3} , {4,5} };
    printVector ( v );
// Takin input in nested vector pair 
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x,y});  // v.push_back(make_pair(x,y));
    }
    printVector(v);

    
    

}