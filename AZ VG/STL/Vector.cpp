#include<bits/stdc++.h>
using namespace std;

#define int long long
#define nline '\n'
signed main(){

    vector <int> v = {1,2,8,9,3,4,5};
    for(vector<int>::const_iterator it = v.begin(); it!=v.end(); ++it){
        cout << *it << " ";
    } cout << nline;

    for( auto it = v.begin(); it!=v.end(); ++it){
        cout << *it << " ";
    } cout << nline;

    for( auto it : v){
        cout << it << " ";
    } cout << nline;

    for(auto it = v.rbegin(); it !=v.rend(); ++it){
        cout << *it << " ";
    } cout << nline;

    sort(v.begin(),v.end());
    cout << "Sorted" << nline;
    for( auto it : v){
        cout << it; 
    } cout << nline;
    vector<int> a{1,1,2,3,3,3,3,4,4,4,5,5,6};
    sort(a.begin(),a.end());
    auto lb = lower_bound(a.begin(), a.end(), 4);
    *lb = 9;
    for(auto it : a){
        cout << it << " ";
    } cout << nline;
    sort(a.begin(),a.end());
    for(auto it : a){
        cout << it << " ";
    } cout << nline;
 
}