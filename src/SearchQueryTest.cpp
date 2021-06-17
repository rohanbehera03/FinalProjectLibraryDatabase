#include "../header/SearchAND.hpp"
#include "../header/SearchOR.hpp"
#include "../header/SearchContains.hpp"
#include "../header/SearchStrat.hpp"
#include "../header/BookItem.hpp"
#include "../header/BookRepository.hpp"
#include "../header/Book.hpp"
#include "../header/LibraryCatalog.hpp"
int main(){

	BookRepository* repo = new BookRepository();
	repo->populate("book.txt");
	LibraryCatalog* lib= new LibraryCatalog();
	cout << repo->getBookByISBN("0000000000100")->getTitle() << endl;

	return 0;

}
