#include "../header/Book.hpp"


Book::Book(const string& t, const string& a, const string& g, const string& i, const bool& c) : title(t), author(a), genre(g), isbn(i), checkout(c){}

Book::Book(const Book &book) {
    title = book.title;
    author = book.author;
    genre = book.genre;
    isbn = book.isbn;
    checkout = book.checkout;
}

void Book::display() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Genre: " << genre << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Checkout Status: " << (checkout ? "True" : "False") << endl;    
}

void Book::setTitle(const string& aTitle) {
    title = aTitle;
}

void Book::setAuthor(const string& aAuthor) {
    author = aAuthor;
}

void Book::setGenre(const string& aGenre) {
    genre = aGenre;
}

void Book::setISBN(const string& isbnCode) {
    isbn = isbnCode;
}

bool Book::getCheckoutStatus() {
    return checkout;
}

void Book::setCheckoutStatus(const bool& checkout) {
    this->checkout = checkout;
}


const string Book::getTitle() {
    return title;
}

const string Book::getAuthor()  {
    return author;
}

const string Book::getGenre()  {
    return genre;
}

const string Book::getISBN() {
    return isbn;
}

