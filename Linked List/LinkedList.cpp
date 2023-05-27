#include <iostream>
using namespace std;

// using our Node class which we created
#include "Node.cpp"

int main(){
// Now we need to create Object of our Node class
// Two Methods -> Statically or Dynamically

// 1.Static creation of Object
    Node n1 (1);  // As we have defined our own constructor default constructor won't work

//Creating Head
    Node *head = &n1;

    Node n2 (2);

// We want to connect these two nodes
    n1.next = &n2; 
    cout << n1.data << " " << n2.data << endl;
// Try to print the data values of node using head
    cout << head->data << endl;
    cout << head->next->data << endl;


// 2. Dynamically Creation of Object of Node Class
    Node *head2;
    Node *n3 = new Node (20);  // n3 is pointer to Node type which is pointing to Heap Memory 
    head2 = n3;  // Why didn't we use & ? ask this to yourself
    Node *n4 = new Node (40);

// Connecting n3 & n4
    n3 -> next = n4;

}
