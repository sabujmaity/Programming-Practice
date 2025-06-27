#include<bits/stdc++.h>
using namespace std;

void solve(){
    int size;
    cin >> size;
    vector<int> input_array(size);
    for( int i = 0; i < size; i++){
        cin >> input_array[i];
    }
    int red = 0, blue = size-1;
    while( red < blue){
        if( input_array[red] == 1 && input_array[blue] == 0){
            swap(input_array[red], input_array[blue]);
            red++, blue--;
        }
        if(input_array[red] == 0){
            red++;
        }
        if( input_array[blue] == 1){
            blue--;
        }
    }
     for( int i = 0; i < size; i++){
        cout << input_array[i] << " ";
    }
}

int main(){
    solve();
}