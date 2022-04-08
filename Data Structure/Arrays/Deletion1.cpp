#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

int deletion1(int *input,int size , int element){
    int i;
    for( i = 0;i<size; i++){
        if(input[i]==element)
            break;
    }
    if(i==size)
        return size;
    for(int k=i;k<size-1;k++){
        input[k]=input[k+1];
    }
        return (size-1);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    int input[5]={1,2,3,4,5};
    int newsize=deletion1(input,5,3);
    for(int i=0;i<newsize;i++){
        cout<<input[i]<<" ";
    }
    
    

}