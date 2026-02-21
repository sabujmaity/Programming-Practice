#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nline "\n" 
#define int long long
#define NULL nullptr
#define fo(i,n) for(int i = 0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long double ld;
typedef vector<signed> vi;
typedef vector<vector<signed>> vvi;
typedef vector<int> vll;
typedef vector<vector<int>> vvll;
const int mod = 1e9+7;
long double pi = acos(-1.0); const double EPS = 1e-9;

int myceil(int a , int b){return (a+b-1)/b;}
int myround(int a , int b){return (2*a+b)/(2*b);}

class Node{
    public:
    int data;
    Node *left, *right;
    Node ( int value){
        data = value;
        left = right = NULL;
    }
};
Node *BinaryTree(){
    int x;
    cin >> x;
    if(x == -1){
        return NULL;
    }
    Node *root = new Node(x);
    root -> left = BinaryTree();
    root -> right = BinaryTree();

    return root;
}



void level_traversal(Node *head){
    if(head == NULL){
        return;
    }
    queue <Node *> q;
    q.push(head);
    while(!q.empty()){
        int len = q.size();
        for( int i = 0; i < len; ++i){
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}

signed main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    // Building the Binary Tree Level by Level from Left to Right 

    /* queue <Node *> q;
    int root, lchild, rchild;
    cin >> root;
    Node *head = new Node(root);
    q.push(head);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        cin >> lchild;
        if( lchild != -1){
            temp -> left = new Node(lchild);
            q.push(temp->left);
        }
        cin >> rchild;
        if( rchild != -1){
            temp -> right = new Node(rchild);
            q.push(temp->right);
        }
    } */

    Node *head = BinaryTree();
    level_traversal(head);

}

