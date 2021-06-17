//driver class
#include "../header/SearchAND.hpp"
#include "../header/SearchOR.hpp"
#include "../header/SearchContains.hpp"
#include "../header/SearchStrat.hpp"
#include "../header/BookItem.hpp"
#include "../header/BookRepository.hpp"
#include "../header/Book.hpp"
#include "../header/LibraryCatalog.hpp"
#include <iostream>
#include <fstream>
#include "../header/search_factory.hpp"
#include "../header/Date.hpp"
#include "../header/Person.hpp"
#include "../header/person_factory.hpp"
using namespace std;


int main(int argc, char* argv[]){

  if(argc != 2){
   cerr << "Usage error: expected <executable> <input>" << endl;
   exit(1);
 }

 fstream f(argv[1], ios::in | ios::out | ios::app);

 if(!f){
   cerr << "Input file not found" << endl;
   exit(1);
 }

Date currDate(1, 1, 2000); 

 string filename = argv[1];
 person_factory* pfact;

Person* p = pfact->begin(f,filename);
 
if(p->getAdminStatus()) cout << "Welcome Librarian: " << p->getName() << endl;

 else cout << "Welcome User: " << p->getName() << endl;



string userInput = "";

cout << "Please select what you wish to do" << endl;
BookRepository* repo = new BookRepository();
repo->populate("book.txt");
if(!p->getAdminStatus()){
while(true) {
        cout << "\n   0.) Search For Books \n"
        << "   1.) Checkout Book by ISBN \n"
        << "   2.) Check Balance \n"
        << "   3.) Check Due Dates \n"
        << "   4.) Pay Balance \n"
	<< "   5.) Return Book by ISBN \n"
        << "   6.) Quit"
        << endl;

        cin >> userInput;

	
	if(userInput == "0") {
		LibraryCatalog* lib = new LibraryCatalog();		
		search_factory* fact = new search_factory();
		SearchStrat* search= fact->makeSearch();
		lib->set_search(search);
		lib->print_search(repo, cout);
	        delete lib;
		delete fact;	
        }
        else if(userInput == "1") {
		string isbn;
		cout << "Enter an ISBN Code: " << endl;
		cin >> isbn;
		Book* bk = repo->getBookByISBN(isbn);
		while(!bk){ 
			cout << "No Book for " << isbn  << " found!" << endl;
			cout << "Enter an ISBN Code: " << endl;
			cin >> isbn;
			bk = repo->getBookByISBN(isbn);
		}
		//BookItem* item = repo->getBookList().at(bk);
		p->checkout(bk, currDate, repo);	
		currDate.increment();
		currDate.increment();
	

		//cout << "Book Chosen: " << endl;
		//bk->display();
		 				

        }
        else if(userInput == "2") {
		cout << "Current Balance: " <<  p->getBalance() << endl;
        }
        else if(userInput == "3") {

		vector<Book*> myB = p->getVec();
		if(myB.size() == 0) {
			cout << "You have no books checked out." << endl;
		}
		for(int i = 0;  i < myB.size(); i++) {
			BookItem* biPtr = repo->getBookList().at(myB.at(i));
			
			cout << "Title: " << myB.at(i)->getTitle() << endl;
			cout << "ISBN: " << myB.at(i)->getISBN() << endl;
			biPtr->getDueDate().printDate();
			cout << endl;
		}			
        }
        else if(userInput == "4") {
		double amount = 0.0;
		cout << "How much would you like to pay?" << endl;
		cin >> amount;
			
		p->payBalance(amount); 
		cout << "Current Balance: " << p->getBalance() << endl;
        }
	
	 else if(userInput == "5") {
		string isbn;
                cout << "Enter an ISBN Code: " << endl;
                cin >> isbn;
		
		
		Book* bk = repo->getBookByISBN(isbn);		

                while(!bk){
                        cout << "No Book for " << isbn  << " found!" << endl;
                        cout << "Enter an ISBN Code: " << endl;
                        cin >> isbn;
                        bk = repo->getBookByISBN(isbn);
                }
		
	

		

		p->returnBook(bk, currDate, repo);




        }
		
	
        else if(userInput == "6") {
		delete p;	
		delete repo;
		break;
        }
        else {
          cout << "\n Invalid input \n" << endl;
        }
        

}
}
else{

while(true){
 cout << "\n   0.) Search For Books \n"
        << "   1.) Display All Books\n"
        << "   2.) Remove a Book by ISBN\n"
        << "   3.) Add a Book \n"
        << "   4.) Quit"
        << endl;


	cin >> userInput;
	string new_isbn= "382";
	if(userInput == "0"){

		LibraryCatalog* lib = new LibraryCatalog();
                search_factory* fact = new search_factory();
                SearchStrat* search= fact->makeSearch();
                lib->set_search(search);
                lib->print_search(repo, cout);
                delete lib;
                delete fact;


	}
	else if(userInput == "1"){

		repo->display();

	}
	else if(userInput == "2"){

		string isbn;
                cout << "Enter an ISBN Code: " << endl;
                cin >> isbn;


                Book* bk = repo->getBookByISBN(isbn);

                while(!bk){
                        cout << "No Book for " << isbn  << " found!" << endl;
                        cout << "Enter an ISBN Code: " << endl;
                        cin >> isbn;
                        bk = repo->getBookByISBN(isbn);
                }
	
		repo->RemoveBook(bk);
		

	}
	else if(userInput == "3"){
		string result, Title, author, genre;
		cin.ignore();
		Book* newBook = nullptr;
		cout << "Enter the Title of The Book: " << endl;
		getline(cin, Title);
		cout << "Enter the Author of the Book: " << endl;
		
		getline(cin, author);
		cout << "Enter the genre of the Book: " << endl;
		getline(cin, genre);
                
		string zero = "0000000000000";
		zero.resize(zero.size()-new_isbn.size());
                result = zero + to_string(stoi(new_isbn)+1);
		cout << "ISBN: " << result << endl;
                //Book* bk = repo->getBookByISBN(result);
                //while(bk){
                  //      cout << "ISBN Code Already Exists! " << endl;
                    ///    cout << "Enter an ISBN Code: " << endl;
                       // cin >> isbn;
                      //  bk = repo->getBookByISBN(isbn);
                //}

		newBook = new Book(Title, author, genre, result, false);
		repo->AddBookByGenre(newBook);
		repo->AddBookByAuthor(newBook);
               	repo->AddBookByTitle(newBook);
		repo->AddBookByIsbn(newBook);
		Date dueDate(3, 1, 2021);
		BookItem* temp = new BookItem(currDate,dueDate);
		repo->AddBookList(newBook,temp);	

	}

	else if(userInput == "4"){
		
		delete p;
		delete repo;
		break;

	}
	else{

		cout << "\n Invalid input \n" << endl;

	}

}



}

	cout << "\n Have a nice day!" << endl;

 	return 0;

}


