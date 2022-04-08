#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

int largest_element(int *input, int size){
    int max=input[0];
    for( int i=1;i<size;i++){
        if(input[i]>max)
            max = input[i];
    }
    return max;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int array[5]={45,546,5,78,55};
    int max_element = largest_element(array,5);
    cout<<max_element;
    
    

}