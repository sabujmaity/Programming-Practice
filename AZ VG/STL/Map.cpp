#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'

signed main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif


    map<string, int> ages ={{"Sabuj", 26}, {"Sourav", 27}};
    // Want to insert an element
    ages["Ankita"] = 23;  //Key -> Value here the Name is the key which will be used to acess the value 

    //cout << "Age of Ankita :" << " " << ages["Ankita"];

    for(auto it = ages.begin(); it != ages.end(); ++it){
        cout << it->first << " " << it->second << nline;
    }

    /* To find the element using Key it takes
    O(logn) as it uses a Balanced Tree */

    auto itfind = ages.find("Sourav");
    if(itfind != ages.end()){
        cout << "Sourav Age is " << itfind -> second << nline;
    }
    return 0;
}