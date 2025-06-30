#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'

signed main(){
    int size;
    cin >> size;
    int* array = new int [size]{}; // All elements initialized to 0


    // Always clear the dynamically created arry memory
    delete[] array; // Raw pointers must be cleaned 
    array = nullptr; // To avoid dangling pointer

    vector <int> input (size);  //// Dynamic array with automatic memory management

    // Using Smart Pointers - Automatic Cleanup happens 
    unique_ptr <int> single = make_unique <int> (42);

    // Array
    unique_ptr <int []> arrays = make_unique <int[]>(10);
    for(auto i = 0; i < 10; ++i){
        arrays[i] = i * 2;
    }
}