#include <iostream>
using namespace std;
class StackUsingArray{
    int * data;
    int nextindex;
    int capacity; 

    public:
    StackUsingArray( int totalsize){
        data = new int [totalsize];
        nextindex = 0;
        capacity = totalsize;
    }
// Return the size of Stack 
    int size (){
        return nextindex;
    }
// To check wether the stack is Empty
    bool isEmpty(){
/*      if(nextindex == 0)
            return true;
        else
            return false; */
// All the above code can be written in short
        return nextindex == 0;
    }
// Push Function
void push( int element ){
// Before pushing check the stack is either full or not    
    if (capacity == nextindex){
        cout << "Stack is Full";
        return ;
    }
    data[nextindex] = element;
    nextindex++;
}
// Pop Function 
int pop(){
    if(isEmpty()){
        cout << "Stack is Empty";
        return ;
    }
    nextindex--;
    return data [nextindex];
}
// Top Element
int top(){
    if(isEmpty()){
        cout << "Stack is Empty";
        return ;
    }
    return data[nextindex - 1];
}
    

};