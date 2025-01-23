#include <iostream>
using namespace std;


struct Node {
    int vertex;
    Node* next;
};


struct Graph {
    int numVertices;      
    Node** adjList;      
};


Node* createNode(int vertex) {
    Node* newNode = new Node;
    newNode->vertex = vertex;
    newNode->next = nullptr;
    return newNode;
}


Graph* createGraph(int n) {
    Graph* graph = new Graph;
    graph->numVertices = n;
    graph->adjList = new Node*[n];
    for (int i = 0; i < n; i++) {
        graph->adjList[i] = nullptr; 
    }
    return graph;
}


void addEdge(Graph* graph, int u, int v) {
    
    Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    
    newNode = createNode(u);
    newNode->next = graph->adjList[v];
    graph->adjList[v] = newNode;
}


void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjList[i];
        cout << i << " -> ";
        while (temp) {
            cout << temp->vertex << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    int vertices = 5; 
    Graph* graph = createGraph(vertices);

    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    

    
    cout << "The adjacency list representation of the graph:" << endl;
    printGraph(graph);

    return 0;
}