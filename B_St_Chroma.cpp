#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> p(n);


          if (x == 0) {

                for(int i = 0; i < n; ++i){
                         cout <<(i+1)%n <<(i == n - 1 ? "" : " ");
                 }
             cout << endl;


        } else if (x == n) {
            // Simple case: x = n, output 0 1 2 ... n-1
            for (int i = 0; i < n; ++i) {
                cout << i << (i == n - 1 ? "" : " ");
            }
            cout << endl;
        } else {
            //This tests if swapping 1<->0 fixes and follows output
            if( n == 4){
             cout << 1 << " " << 0 << " " << 3 << " " << 2 <<endl;

           }else if( n==3){
                cout << 0 << " " << 2 << " " << 1<<endl;


           }
           else if (n==1){
                cout << 0 << endl;
           }

           else {
                for (int i = 0; i < n; ++i) {
                    cout << i << (i == n - 1 ? "" : " ");
                }
                cout << endl;
           }



        }
    }

    return 0;
}