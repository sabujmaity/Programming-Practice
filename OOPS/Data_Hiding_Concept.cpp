#include<bits/stdc++.h>
using namespace std;

struct Book{
	private:  // Now to acess the member variable we need to use the member fucntions
		int book_id;
		char book_title[20];
		float book_price;
	
	//In C++ we can declare functions inside the struct also -> "Member Functions"
	public:
		void input_book(){
			cout << "Enter Book details in order of Book_id, Book_title, Book_Price" << '\n';
			cin >> book_id;
			fflush(stdin);
			cin.ignore();
			cin.getline(book_title,20);
			cin >> book_price;
		}
		
		void display_book(){
			cout << book_id << " " << book_title << " " << book_price << '\n';
		}
	
};

int main(){
	Book b1;   // Note : No need to mention the struct keyword again and again
	b1.input_book();
	b1.display_book();
}