#include<bits/stdc++.h>
using namespace std;


struct Node{
    int key;
    Node *left;
    Node *right;
    // Constructor for Node
    Node( int k ){
        key = k;
        left = right = NULL;
    }
};

// Inorder Traversal :
void inorder( Node *root){
    inorder( root -> left);
    cout<<(root -> key)<<" ";
    inorder( root -> right);
}

typedef long long ll;
typedef long double ld;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif


    
    

}