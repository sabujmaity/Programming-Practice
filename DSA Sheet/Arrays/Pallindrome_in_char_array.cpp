#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

bool checkpallindrome(char str[]){
    int i=0;
    for( i=0;str[i]!=0;i++);
    i--;
    for(int j=0;j<i;j++,i--){
        if(str[j]!=str[i])
            return false;
    }
    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    
    char str[100];
    cin>>str;
    if(checkpallindrome(str))
        cout<<"Yes";
    else
        cout<<"No";

    
    

}