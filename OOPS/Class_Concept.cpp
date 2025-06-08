#include<bits/stdc++.h>
using namespace std;

class Complex_Number{
    private:  //Automatically private but it's better to mention
        int a,b;   //Instance member variable or Object variable
        static int m;
    public:
        void setData( int x, int y){  //When will x,y will come in pic when object is created
            a = x;
            b = y;
        }
        static void setData_m(int l){
            m = l;
        }

        void showData_a(){ 
            cout << a << '\n';
        }
        void showData_b(){
            cout << b << '\n';
        }
        static void showData_m(){
            cout << m << '\n';
        }
        static int k; // Memory not allocated for static member variable need to define outside the class using membership variable
};
int Complex_Number :: k;  // Definition of Static member variable
int Complex_Number :: m;
 
int main(){
    Complex_Number :: k = 20;
    cout << Complex_Number :: k << '\n';
    Complex_Number :: setData_m(50);
    Complex_Number :: showData_m();

} 