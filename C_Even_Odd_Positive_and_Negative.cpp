#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nline "\n" 
#define fo(i,n) for(int i = 0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef long double ld;


int main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int size;
    cin >> size;

    vector<int> input;
    fo(i,size){
        int x;
        cin >> x;
        input.pb(x);
    }

    int c_even = 0,c_odd = 0,c_pos = 0,c_neg = 0;
    fo(i,size){
        if(input[i] % 2==0 || input[i]==0){
            c_even++;
            if(input[i]>0){
                c_pos++;
            }
            else if (input[i]<0){
                c_neg++;
            }
        }
        else{
            if(input[i]>0){
                c_pos++;
            }
            else if (input[i]<0){
                c_neg++;
            }
        }
        
    }

    cout <<"Even:" << " " << c_even <<nline;
    cout <<"Odd:" << " " << size - c_even <<nline;
    cout <<"Positive:" << " " << c_pos <<nline;
    cout <<"Negative:" << " " << c_neg <<nline;

    
    

}