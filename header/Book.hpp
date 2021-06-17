#ifndef LIBRARYSYSTEM_BOOK_HPP
#define LIBRARYSYSTEM_BOOK_HPP
#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string title;
    string author;
    string genre;
    string isbn;
    string type;
    bool checkout; 
   
public:
    Book() : title(""), author(""), genre(""), isbn(""), type(""), checkout(false) {}
    Book(const string&, const string&, const string&, const string&, const bool&);
    Book(const Book &book);
    void display();
    void setTitle(const string& nameOfBook);
    void setAuthor(const string& nameOfAuthor);
    void setGenre(const string& nameOfGenre);
    void setISBN(const string& isbnCode);
         
    bool getCheckoutStatus();
    void setCheckoutStatus(const bool& checkout);
    const string getTitle();
    const string getAuthor();
    const string getGenre();
    const string getISBN();

};


#endif //LIBRARYSYSTEM_BOOK_HPP
