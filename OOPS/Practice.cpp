#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef long double ld;

// Creating a class
class student{
    public:
    int rollnumber;
    int age;
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    // statically creating objects
    student s1;
    s1.rollnumber = 121;
    s1.age = 34;
    cout << s1.age << " " << s1.rollnumber << "\n" ;

    // dynamically creating objects 
    student *s2 = new student;
    (*s2).age = 21;
    (*s2).rollnumber = 122;
    cout << (*s2).age << " " << (*s2).rollnumber << "\n";
    // Other Way to write
    s2 -> age = 21;               // "This pointer"
    s2 -> rollnumber = 123;
    cout << (*s2).age << " " << (*s2).rollnumber ;



    
    

}