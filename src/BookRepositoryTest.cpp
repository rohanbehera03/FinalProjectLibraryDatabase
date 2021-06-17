#include <iostream>
#include <fstream>
#include "../header/BookItem.hpp"
#include "../header/BookRepository.hpp"
#include "../header/Book.hpp"
using namespace std;

int main() {
   Book *book1 = new Book();
   book1->setAuthor("Jessica Dunham");
   book1->setTitle("The Open Road: 50 Best Road Trips in the USA");
   book1->setGenre("Travel guides");
   book1->setISBN("9781640499300");
    cout << "Book 1" << endl;
    book1->display();

    Book *book2 = new Book();
    book2->setAuthor("Lenna Stuart");
    book2->setTitle("The Break of Dawn");
    book2->setGenre("Romance");
    book2->setISBN("0000000000001");
    cout << endl;
    cout << "Book 2" << endl;

    book2->display();

Book *book3 = new Book();
    book3->setAuthor("Jostein Gaarder");
    book3->setTitle("Sophie's World");
    book3->setGenre("Romance");
    book3->setISBN("0000000000002");
    cout << endl;
    cout << "Book 3" << endl;
    book3->display();

    Book *book4 = new Book();
    book4->setAuthor("Karl Marx");
    book4->setTitle("Manifesto of the Communist Party");
    book4->setGenre("Philosophy");
    book4->setISBN("0000000000003");
    cout << endl;
    cout << "Book 4" << endl;
    book4->display();

    cout << endl;
    BookRepository bookRepository;
    bookRepository.AddBookByTitle(book1);
    cout << "Add book by title: book 1" << endl;
    bookRepository.AddBookByAuthor(book2);
    cout << "Add book by author: book 2" << endl;
    bookRepository.AddBookByGenre(book3);
    cout << "Add book by genre: book 3" << endl;
    bookRepository.AddBookByIsbn(book4);
    cout << "Add book by isbn: book 4" << endl;

  cout << endl;
  cout << "End of BookRepository Test" << endl;

}
