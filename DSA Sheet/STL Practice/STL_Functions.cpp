#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef long double ld;

struct Interval{
    int st;
    int et;
};

bool compare ( Interval i1 , Interval i2){
    return i1.st < i2.st;
}
void func(int i, int& j, int p){
    i++;
    j++;
    p++;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    int input[] = {1,4,3,5,9,2};
    int i;
    sort( input, input+6);
    fo(i,6){
        cout << input[i] << " ";
    }
    cout << "\n";
    sort( input , input + 6 , greater <int> ());   // Sorting in decreasing order functionality
    int j;
    fo(j,6){
        cout << input[j] << " ";
    }
    cout << "\n";

    Interval arr[] = {{5,6} , {7,1} ,{9,6}};
    sort( arr , arr + 3 , compare);
    int k;
    fo(k,3){
        cout << arr[k].st << ":" << arr[k].et << endl;
    }
    char st[] = "ABCD";
    for(int i = 0; st[i] != '\0'; i++) {
     cout << st[i] << *(st)+i << *(i+st) << i[st];
    }
    cout<<endl;
    int i1 = 10;
    int j1 = 6;
    int &p = i1;
    func(i1, j1, p);
    cout << i1 << " " << j1 << " " << p;


}