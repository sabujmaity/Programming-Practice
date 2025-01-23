#include <bits/stdc++.h>
using namespace std;

void takevalues( int input[], int size){
    for ( int i = 0; i < size; i++){
        cin >> input[i];
    }
}
int main(){
    int size1, size2;
    cin >> size1 >> size2;
    int input1[size1], input2[size2];
    takevalues( input1, size1);
    takevalues( input2, size2);
    unordered_set < int > elements;
    for ( int i = 0 ; i < size1; i++){
        elements.insert(input1[i]);
    }
    for( int j = 0; j < size2; j++){
        if(elements.count(input2[j]) == 0){
            cout << "Not Subset" << "\n";
            return 0;
        }
        cout << "Yes Subset";
    }
    
    
    
}