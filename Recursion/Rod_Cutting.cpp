#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef long double ld;

int max_pieces(int length, int a, int b, int c){
    if ( length == 0)
        return 0;
    if ( length < 0)
        return -1;
    
    // As normal max we are able to compare only two values
    // I used iterator and used the elements as list
    int pieces = std :: max({ max_pieces( length - a,a,b,c), 
    max_pieces( length - b,a,b,c), 
    max_pieces( length - c,a,b,c)});

    if ( pieces == -1)
        return -1 ;
    return pieces + 1;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int length, a, b, c;
    cin >> length >> a >> b >> c;
    cout << max_pieces( length, a, b, c);

    
    

}