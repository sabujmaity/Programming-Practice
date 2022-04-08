#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

void printVector( vector < int > v){
    for ( int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << "\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int size;
    cin >> size;
    vector < int > v[size];    // Size vectors are declared 
    for ( int i = 0; i < size; i++){
        int n;
        cin >> n;
        for( int j = 0; j < n; j++){
            int x; 
            cin >> x;
            v[i].push_back(x);
        }
    }
    for ( int i = 0; i < size; i++){
        printVector(v[i]);
    }


    
    

}