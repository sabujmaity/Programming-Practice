#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nline "\n" 
#define fo(i,n) for(int i = 0;i<n;i++)
#define pb push_back
#define F first
#define S second
#define int long long
typedef long double ld;
typedef vector<signed> vi;
typedef vector<vector<signed>> vvi;
typedef vector<int> vll;
typedef vector<vector<int>> vvll;
const int mod = 1e9+7;


signed main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    

    // To declare the min heap 
    priority_queue<int , vector<int>, greater<int>> minheap;
    minheap.push(2);
    minheap.push(3);
    minheap.push(5);
    while(!minheap.empty()){
        cout << minheap.top() << nline;
        // You also need to pop the element otherwise infinite loop
        minheap.pop();
    }

    vector <int> priority_task {1,5,6,3,8,5,97,45};
    // Way to copy the vector inside the max heap;
    priority_queue < int > max_heap(priority_task.begin(), priority_task.end()); 
    while(!max_heap.empty()){
        cout << max_heap.top()<<nline ;
        max_heap.pop();
    }
    return 0;
    

    

}