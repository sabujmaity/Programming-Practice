#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

void printVec( vector < int > & v){
    for(int i= 0; i < v.size() ; i++){
        cout<< v[i]<<" ";
    }
    cout<<"\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    vector < int > v;
    int size;
    cin>>size;
    for( int i =0; i< size; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    printVec(v);
    int ans =0;
    for( int i =0; i< v.size(); i++){
        ans = ans ^ v[i];
    }

    cout<< "Unique Element :"<<ans;




    
    

}