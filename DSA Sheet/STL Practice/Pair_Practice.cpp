#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    // Declaration:
    pair < int, string> p;

    // Initialization :

    //p = make_pair( 2, "abc" );      // First Way 
    p = {2,"abc"};                    // Second Way
    
    pair < int ,string > p1 = p;      // Copying the pair in p1
    pair < int , string > &p2 = p;    // Here we created the reference to p

    p2.first = 4;                     // As p2 used as ref so we can access p using p2

    cout<< p.first << " " << p.second<<"\n";
    // Declaring Array Pairs :
    pair< int , int> p_array[3];
    p_array[0] ={1,2};
    p_array[1] ={3,4};
    p_array[2] ={5,6};
    swap(p_array[0], p_array[2]);            //Swap the pair array elements 
    for(int i=0; i< 3 ; i++){
        cout<< p_array[i].first<<" "<< p_array[i].second<<"\n";
    }
    // Input can also be taken in the pairs
    cin>>p.first;
    cout<<"Updated Value of Pair p:"<<"\n"<<p.first<<" "<< p.second;

    


}