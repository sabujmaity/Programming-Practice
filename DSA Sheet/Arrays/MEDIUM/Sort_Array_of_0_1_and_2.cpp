#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef long double ld;
 
// Using DNF Algorithm - Dutch National Flag Algorithm - Visualise the Low, Mid & High (Hypothetical)
void sortarray(vector <int> &input){
    int length = input.size();
    int low = 0, mid = 0, high = length-1;
    while( mid <= high){
        if(input[mid]==0){
            swap(input[low], input[mid]);
            mid++;
            low++;
        }
        else if(input[mid]==1){
            mid++;
        }
        else{
            swap(input[mid],input[high]);
            high--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    
    int element;
    vector <int> input;
    while(cin>>element){
        input.push_back(element);
    }
    sortarray(input);
    for( auto it = input.begin(); it!=input.end(); it++){
        cout << *(it) << " ";
    }
    



    
    

}