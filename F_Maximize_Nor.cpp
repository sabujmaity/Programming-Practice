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

int K;          
int K_MASK;    


inline int compute_nor(int x, int y) {
    
    return (~(x | y)) & K_MASK;
}
struct Node {
    
    int max_val = 0;

    
    int lazy_max = 0;
};


vector<Node> tree;


int N_segtree;


void push(int node, int start, int end) {
    
    if (tree[node].lazy_max == 0 && tree[node].max_val == 0) {
        
         if(tree[node].lazy_max == 0) return; 
    }


    
    tree[node].max_val = std::max(tree[node].max_val, tree[node].lazy_max);

    
    if (start != end) {
        
        tree[2 * node].lazy_max = std::max(tree[2 * node].lazy_max, tree[node].lazy_max);
        tree[2 * node + 1].lazy_max = std::max(tree[2 * node + 1].lazy_max, tree[node].lazy_max);
    }

    
    tree[node].lazy_max = 0;
}


void update_range_max(int node, int start, int end, int l, int r, int val) {
    
    push(node, start, end);

    
    if (start > end || start > r || end < l) {
        return;
    }

    
    if (l <= start && end <= r) {
        tree[node].lazy_max = std::max(tree[node].lazy_max, val);
        push(node, start, end); 
        return;
    }

    
    int mid = start + (end - start) / 2; 
    update_range_max(2 * node, start, mid, l, r, val);         
    update_range_max(2 * node + 1, mid + 1, end, l, r, val);    

    
    tree[node].max_val = std::max(tree[2 * node].max_val, tree[2 * node + 1].max_val);
}



int query_final_value(int node, int start, int end, int idx) {
    push(node, start, end);

   
    if (start == end) {
        return tree[node].max_val;
    }

    
    int mid = start + (end - start) / 2;
    if (idx <= mid) {
        
        return query_final_value(2 * node, start, mid, idx);
    } else {
        
        return query_final_value(2 * node + 1, mid + 1, end, idx);
    }
   
}


signed main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    //Let's Code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin >> N >> K; 
        K_MASK = (1 << K) - 1;

        
        vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }

        N_segtree = N; 
        tree.assign(4 * N_segtree + 1, {0, 0});
        
        for (int l = 0; l < N; ++l) { 
            int current_nor = a[l];
            update_range_max(1, 0, N_segtree - 1, l, l, current_nor); 

            
            for (int r = l + 1; r < N; ++r) {
                 
                 current_nor = compute_nor(current_nor, a[r]); 

                 
                 update_range_max(1, 0, N_segtree - 1, l, r, current_nor); 
            }
        }

        
        for (int i = 0; i < N; ++i) {
            cout << query_final_value(1, 0, N_segtree - 1, i) << (i == N - 1 ? "" : " ");
        }
        cout << nline; 
    }
    return 0;
}
