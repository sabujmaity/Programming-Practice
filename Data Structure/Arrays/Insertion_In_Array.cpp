#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int insert_in_array(int *input, int curr_size, int capacity,int pos, int num){
    if(curr_size==capacity)
        return curr_size;
    int index = pos-1;
    for(int i=curr_size-1;i>=index;i++){
        input[i+1] = input[i];
    }
    input[index] = num;
    return curr_size+1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    int arr[5], cap = 5, n = 3;

       arr[0] = 5; arr[1] = 10; arr[2] = 20;

       cout<<"Before Insertion"<<endl;

       for(int i=0; i < n; i++)
       {
       	cout<<arr[i]<<" ";
       }

       cout<<endl;

       int x = 7, pos = 2;

       n = insert_in_array(arr, n, cap, pos, x);

       cout<<"After Insertion"<<endl;
       
       for(int i=0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }
    





    
    

}