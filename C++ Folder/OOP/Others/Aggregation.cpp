#include <bits/stdc++.h>
using namespace std;
    
class Book{
    public:
    string books;
    Book(){};
    Book(string book){
        this->books = book;
    }
    void PrintBook(){
        cout<<books<<endl;
    }
};

class Library{
    private:
    Book book1;
    Book book2;
    public:
    Library(string b1, string b2){
        this->book1 = b1;
        this->book2 = b2;
    }

    void printBook(){
        book1.PrintBook();
        book2.PrintBook();
    }
    


};
int main()
{
    string book1 = "Its ends with us";
    string book2 = "To kill a mockingbird";
    Library myLibrary(book1,book2);
    myLibrary.printBook();
return 0;
}