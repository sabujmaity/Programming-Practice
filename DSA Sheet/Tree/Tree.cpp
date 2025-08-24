#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;

    Node( int value){
        data = value;
        left = right = NULL;
    }
};
int main(){
    int x;
    cin >> x;
    queue <Node *> q;
    Node *root = new Node(x);
    q.push(root);
}