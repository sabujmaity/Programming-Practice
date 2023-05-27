class Node{
    public:
    int data;
    Node *next;

    // Creating a constructor so that while creating Node the user has to pass the data also 
    // To avoid creating empty Node
    
    Node ( int data ) {
        this -> data = data;
        next = nullptr;
    }

};