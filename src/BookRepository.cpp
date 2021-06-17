#include <fstream>
#include "../header/BookRepository.hpp"

using namespace std;

BookRepository::BookRepository() {

}


map<string, vector<Book*>> BookRepository::getMapAuthor() const{


	return this->bookAuthors;
}

map<string, vector<Book*>> BookRepository::getMapTitle() const{

	return this->bookTitles;

}

map<string, vector<Book*>> BookRepository::getMapGenre() const{

	return this->bookGenres;
}

map<string, Book*> BookRepository::getMapIsbn() const {
    return this->bookISBN;
}

BookRepository::BookRepository(const BookRepository& bookRepository) {
    bookTitles = bookRepository.bookTitles;
    bookAuthors = bookRepository.bookAuthors;
    bookGenres = bookRepository.bookGenres;
    bookList = bookRepository.bookList;
}
void BookRepository::AddBookByTitle(Book* book) {
    bookTitles[book->getTitle()].push_back(book);
}

void BookRepository::AddBookByAuthor(Book* book) {
    bookAuthors[book->getAuthor()].push_back(book);
}

void BookRepository::AddBookByGenre(Book* book){ 
    bookGenres[book->getGenre()].push_back(book);

}

void BookRepository::AddBookByIsbn(Book* book) {
	bookISBN.insert(pair<string,Book*>(book->getISBN(), book));

}

void BookRepository::displayMapTitle(){

	for(map<string, vector<Book*>>::iterator it = bookTitles.begin(); it != bookTitles.end(); it++){		
		for(auto x : it->second){
			cout << x->getTitle() << endl;
		}
	}

}
void BookRepository::displayMapAuthors(){
	for(map<string, vector<Book*>>::iterator it = bookAuthors.begin(); it != bookAuthors.end(); it++){

                for(auto x : it->second){
                        cout << x->getAuthor() << endl;
                }
        
	}

}

void BookRepository::displayBookGenres(){
for(map<string, vector<Book*>>::iterator it = bookGenres.begin(); it != bookGenres.end(); it++){
                for(auto x : it->second){
                        cout << x->getGenre() << endl;
                }
        }

}

void BookRepository::RemoveBook(Book* book) {
   if(!book->getCheckoutStatus()){
   
    for(auto it = bookGenres.at(book->getGenre()).begin(); it != bookGenres.at(book->getGenre()).end(); it++){
	if((*it)->getISBN() == book->getISBN()){
 		bookGenres.at(book->getGenre()).erase(it);
 		break;

	}
    }
   
    for(auto it = bookAuthors.at(book->getAuthor()).begin(); it != bookAuthors.at(book->getAuthor()).end(); it++){
	if((*it)->getISBN() ==  book->getISBN()){
 		bookAuthors.at(book->getAuthor()).erase(it);
 		break;
	}
    }	
    for(auto it = bookTitles.at(book->getTitle()).begin(); it != bookTitles.at(book->getTitle()).end(); it++){
	if((*it)->getISBN() ==  book->getISBN()){
                bookTitles.at(book->getTitle()).erase(it);
                break;
        }

    }
    for(auto it : bookISBN){
	if(it.first == book->getISBN()){
		bookISBN.erase(it.first);
		break;
	}



    } 
    delete bookList.at(book);
    bookList.erase(book);
    
    delete book;
}
else{

	cout << "Cannot Remove a book that's checked out!" << endl;
}
}
void BookRepository::display() {
    std::map<Book *, BookItem*>::iterator it;
    for (it = bookList.begin(); it != bookList.end(); it++) {
        BookItem* bookItem = it->second;
        it->first->display();
       // bookItem->display();
       
    }
    cout << endl;
}
Book* BookRepository::getBookByISBN(const string& isbn){
   	
	string zero = "0000000000000";
	string temp =to_string(stoi(isbn));
	zero.resize(13-temp.size());
	string result = zero + temp;
	//cout << "ISBN " << result << endl;
	return (bookISBN.find(result) != bookISBN.end()) ? bookISBN.at(result) : nullptr;

}
map<Book*, BookItem*> BookRepository::getBookList() const{
	
	return this->bookList;

}
void BookRepository::populate(const string &s) {//Title | Author * Genre / ISBN


    string Title;
    string Author;
    string Genre;
    string ISBN;
    string line;

    ifstream infile(s);

    if(!infile){
	
	cerr << "Invalid Txt file" << endl;
	exit(1);
    }

    
    Book* newBook = nullptr;
    BookItem* bookItem = nullptr;
    while(getline(infile,line, '\n')){

	size_t one = line.find('|');
	size_t two = line.find('*');
	size_t three = line.find('/');
    
	Title = line.substr(0,one);
	Author = line.substr(one+1, two-one-1);
	Genre = line.substr(two+1, three-two-1);
	ISBN = line.substr(three+1);

        newBook = new Book(Title, Author,Genre, ISBN, false);
//com
        Date currDate(1,1,2021);
        Date dueDate(3, 1, 2021);
        bookItem = new BookItem(currDate, dueDate);

        AddBookByGenre(newBook);
        AddBookByAuthor(newBook);
        AddBookByTitle(newBook);
	AddBookByIsbn(newBook);
        bookList[newBook] = bookItem;
	
    }
       
      infile.close();
}
