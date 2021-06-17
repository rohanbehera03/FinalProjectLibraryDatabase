#ifndef LIBRARYSYSTEM_USER_HPP
#define LIBRARYSYSTEM_USER_HPP

#pragma once

#include "Person.hpp"
#include "BookItem.hpp"
#include "BookRepository.hpp"


#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

class User: public Person {

protected:
    //string name, pass;
    double balance = 0.0;
    vector<Book*> myBooks;
   

private:
     bool getAdminStatus(){ return false;} 
 
    //user should have private variable bool checkoutstatus
    bool checkoutS = false;
 
    const double lateFee = 0.15;

public:
//    vector<Book*> myBooks;

    User(const string& name, const string& pass) : Person(){
	this->name = name;
	this->pass = pass;
    }

    ~User() {
	myBooks.clear();
    }
    double getBalance() {
        return balance;
    }
    
    vector<Book*> getVec() {
	return myBooks;
    }

    void setBalance(double amount) {
        balance = amount;
    }

    void payBalance(double amount) {
        balance = balance + amount;
    }



   void checkout(Book* bk, const Date& today, BookRepository*& b){
            
           if(!bk->getCheckoutStatus()) {
                myBooks.push_back(bk);
		bk->setCheckoutStatus(true); 
				
		BookItem* biPtr = b->getBookList().at(bk);
		
		biPtr->setCheckoutDate(today);
		Date* dueDate = new Date(today);
		dueDate->increment();
		biPtr->setDueDate(*dueDate);
	
		delete dueDate;
            
	    }
	    else {
		cout << "Book already checked out" << endl;
	    }
             
	
    
    }

void returnBook(Book* mybook, Date& c, BookRepository*& b) {
   // Book* mybook = getBookByISBN(isbn); //iterate through bookLists
    
    if(mybook->getCheckoutStatus() == true) {
      mybook->setCheckoutStatus(false);

      //vector<Book*>::iterator new_end;
      //new_end = remove(myBooks.begin(), myBooks.end(), mybook);

      for(vector<Book*>::iterator it = myBooks.begin(); it != myBooks.end(); it++){

	if((*it)->getISBN() == mybook->getISBN()){
 		myBooks.erase(it);
 		break;

		}



	}
      BookItem* dd = b->getBookList().at(mybook);
      Date* d = new Date(dd->getDueDate());			

      const int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30,
                                31, 31, 30, 31, 30, 31 };
      int daysLate = 0;

      long int numDays1 = 0;
      long int numDays2 = 0; 

      numDays1 = c.getYear() * 365 + c.getDay();
      numDays2 = d->getYear() * 365 + d->getDay(); 

      for (int i = 0; i < c.getMonth() - 1; i++)
        numDays1 += daysPerMonth[i];

      for (int i = 0; i < d->getMonth() - 1; i++)
        numDays2 += daysPerMonth[i];

      int years = c.getYear();
      
      if (c.getMonth() <= 2)
          years--;
      
      numDays1 += (years / 4) - (years / 100) + (years / 400);

      years = d->getYear();
      
      if (d->getMonth() <= 2)
          years--;
      
      numDays2 += (years / 4) - (years / 100) + (years / 400);

      daysLate = numDays1 - numDays2;


      double currBal = this->getBalance();
      double balOwed = daysLate * lateFee;

      this->setBalance(currBal-balOwed);
      delete d;	



    }
    else {
      cout << "Book is not checked out" << endl;
    }

}

    bool getCheckoutStatus() {
        return checkoutS;
    }
    void setCheckoutStatus(bool b) {
        checkoutS = b;
    }


vector<Book*> getMyBooks() {return myBooks;}

};
#endif //LIBRARYSYSTEM_USER_HPP
