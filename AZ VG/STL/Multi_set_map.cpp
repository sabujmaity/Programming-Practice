#include <bits/stdc++.h>
using namespace std;

#define int long long
#define nline '\n';

signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    // Time Complexity: O(n log n) for initialization
    multiset < int > ages = {25,45,35,25,25,76};
    // Time Complexity: O(log n) for insert (assuming balanced tree)
    ages.insert(35);
    // Time Complexity: O(log n) for count (assuming balanced tree)
    int count = ages.count(35);
    cout << count << nline;
    // Time Complexity: O(n) for iterating through the multiset (where n is the number of elements)
    for( int age : ages){
        cout << age << " " << nline;
    }

    multimap < string, int > agemap = {{"Sabuj", 26}, {"Sourav", 27},{"Sabuj", 28}};
    agemap.insert(make_pair("Alice",23));
    for( auto it = agemap.begin(); it != agemap.end(); ++it){
        cout << it -> first << " " << it -> second << nline;
    }


}