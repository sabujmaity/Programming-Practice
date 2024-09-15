#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef long double ld;

void freq_sorted_array( vector<int> &input){
    int size = input.size();
    int freq = 1, i = 1;
    while( i < size){
        while( i < size && input[i] == input[i-1]){
            freq++;
            i++;
        }
        cout << (input[i-1])<< ":" << freq << "\n";
        i++;
        freq = 1;  // Resetting the freq for next unique element 
    }
    if( size == 1 || input[size-1] != input[size-2]){   // For corner cases and single element 
        cout << input[size-1] << ":" << freq;  
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    vector <int> input = {10,10,10,20,20,30,30};
    freq_sorted_array(input);
    

    
    

}