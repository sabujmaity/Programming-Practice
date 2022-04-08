#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

void mergesortedarray(int *arr1, int *arr2, int size1, int size2, int *ans){
    int i=0,j=0,k=0;
    while( i<size1 && j<size2){
        if(arr1[i]<arr2[j])
            ans[k++]=arr1[i++];
        else
            ans[k++]=arr2[j++];
    }
    while(i<size1){
        ans[k++]=arr1[i++];
    }
    while(j<size2){
        ans[k++]=arr2[j++];
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int arr[]={5,8,21,54};
    int arr2[]={1,2,3,4};
    int ans[8];
    mergesortedarray(arr,arr2,4,4,ans);
    for(int i=0;i<8;i++){
        cout<<ans[i]<<" ";
    }
    
    

}