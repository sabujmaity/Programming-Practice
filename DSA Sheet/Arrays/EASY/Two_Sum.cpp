#include<bits/stdc++.h>
using namespace std;
int main(){
    int size, target; cin >> size >> target;
    vector<int> nums;
    for( int i = 0; i < size; ++i){
        cin >> nums[i];
    }
    map <int, int> mpp;
    for( int i = 0; i < size; ++i){
        int needed = target - nums[i];
        if(mpp.find(needed) != mpp.end()){
            cout << mpp[needed] << " " << i;
        }
        mpp[nums[i]] = i;

    }


}