#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

void printVector(vector<int> &v){
    // v.size () -> O(1)
    cout << "Size : " << v.size() << "\n";
    for( int i = 0; i<v.size(); i++){
        cout<< v[i] << " ";
    }
    v.push_back(22);
    cout<<"\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    // Declaring the Vector 
    vector< int > v;
    int n;
    cin>>n;
    for(int i=0; i<n ; i++){
        int x;
        cin>>x;
        v.push_back(x);     // T.C -> O(1)
    }
    cout<<"v :"<<"\n";
    printVector(v);

    vector < int > v2(10);      // Declaring the vector of size 10 -> by default the value is always 0
    v2.push_back(7);  // after declaration we can still add in vector and size will increase accordingly
    cout<<"v2 :"<<"\n";
    printVector(v2);

    vector < int > v3 ( 10 , 3);  // By default if you want some value to the whole vector
    cout<<"v3 :"<<"\n";
    v3.push_back(7);
    printVector(v3);
    v3.pop_back();      // deletes the last value of vector
    printVector(v3);

    vector < int > v4 = v3;  // it directly makes a copy of the vector but be careful as its T.C -> is O(n)
    cout<<"v4 :"<<"\n";
    v4.push_back(56);
    printVector(v4);
    // To avoid the copying of vector which is a expensive operation always pass the reference of the vector

}