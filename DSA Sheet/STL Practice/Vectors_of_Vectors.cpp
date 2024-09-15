#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;
void printVec( vector < int > v){
    for( int i = 0; i < v.size(); i++){
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
    int row ;
    cin >> row;
    vector < vector < int > > v;
    for ( int i = 0; i < row; ++i){
        int col;
        cin >> col;
        vector < int > temp;   // You can also create an empty vector i.e v.push_back(vector < int > ());
        for( int j = 0; j < col; ++j){
            int x;
            cin >> x;
            temp.push_back(x);   // v[i].push_back(x);
        }
        v.push_back(temp);
    }
    for( int i = 0; i < v.size() ; i++){
        printVec(v[i]);
    }
    

    
    

}