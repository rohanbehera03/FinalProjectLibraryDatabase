#ifndef BOOKREPOSITORY_HPP
#define BOOKREPOSITORY_HPP
#include <vector>
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>
#include <string>
#include "Book.hpp"
#include "BookItem.hpp"
#include <fstream>
using namespace std;

class BookRepository  {
public:
    ~BookRepository(){

	for(auto& it: this->bookList){

//		cout << "Deleting..." << it.first->getTitle() << " " << it.first->getAuthor() << " " << it.first->getGenre() << " " << it.first->getISBN() << endl;
		delete it.first;
		delete it.second;
		
	}
	bookList.clear();
	bookTitles.clear();
	bookAuthors.clear();
	bookGenres.clear();

    }

    
    BookRepository();
    BookRepository(const BookRepository& bookRepository);
    void display();
    void AddBookByTitle(Book* book);
    void AddBookByAuthor(Book* book);
    void AddBookByGenre(Book* book);
    void AddBookByIsbn(Book* book);
    void RemoveBook(Book* book);
    void populate(const string &s);
    void displayMapTitle();
    void displayMapAuthors();
    Book* getBookByISBN(const string&);
    void displayBookGenres();
    map<Book*, BookItem*> getBookList() const;

    void AddBookList(Book* b, BookItem* d){ bookList[b] = d; }
        



   // Book* GetBookByAuthor(string bookAuthor) const;
    //Book* GetBookByTitle(string bookTitle) const;
   // Book* GetBookByGenre(string bookGenre) const; 
    map<string, vector<Book*>> getMapAuthor() const;
    map<string, vector<Book*>> getMapTitle() const;
    map<string, vector<Book*>> getMapGenre() const;
    map<string, Book*> getMapIsbn() const;
    const int DUE_DATE = 60; //A user can checkout a book for up to 60 days by default.

private:
    map<string, vector<Book*>> bookTitles;
    map<string, vector<Book*>> bookAuthors;
    map<string, vector<Book*>> bookGenres;
    map<string, Book*> bookISBN;
    map<Book*, BookItem*> bookList;

};


#endif //LIBRARYSYSTEM_BOOKREPOSITORY_HPP


