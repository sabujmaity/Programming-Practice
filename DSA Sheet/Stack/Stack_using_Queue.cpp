#include<bits/stdc++.h>
using namespace std;

class Stack_using_Queue{
    public:
        queue<int> Q;
        void push(int x){
            int size = Q.size();
            Q.push(x);
            for( int i = 0; i<size; ++i){
                Q.push(Q.front());
                Q.pop();
            }
        }
        int pop_SQ(){
            int top = Q.front();
            Q.pop();
            return top;
        }
        int top(){
            if(Q.empty()){
                return -1;
            }
            return Q.front();
        }
};

int main(){
    Stack_using_Queue Sq1;
    Sq1.push(2);
    Sq1.push(6);
    Sq1.push(7);
    Sq1.push(3);

    cout << Sq1.pop_SQ() << '\n';
    cout << Sq1.pop_SQ();


}