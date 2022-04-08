#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;
// Approach 1 (Naive Approach)  As there are two travesal of array

/* int second_largest_element(int *input,int size){
    int max1=input[0],max2=input[0];
    for(int i =1;i<size;i++){
        if(input[i]>max1){
            max1=input[i];
        }
    }
    for( int i=1;i<size;i++){
        if(input[i]!=max1){
            if(input[i]>max2){
                max2=input[i];
            }
        }
    }
    return max2;
} */

// Approach 2 ( In one traversal )
int second_largest_element( int *input,int size){
    int second_largest = -1, largest = 0;
    for( int i = 1; i < size; i++){
        if(input[i]>input[largest]){
            second_largest = largest;
            largest = i;
        }
        else if(input[i]!=input[largest]){
            if(second_largest == -1 || input[i]>input[second_largest]){
                second_largest = i;
            }
        }
    }
    return second_largest;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    int array[5]={45,546,5,78,55};
    int second_max_element = second_largest_element(array,5);
    //cout<<second_max_element;
    cout<<array[second_max_element];

    
    

}