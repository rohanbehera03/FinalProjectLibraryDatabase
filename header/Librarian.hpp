#ifndef LIBRARYSYSTEM_LIBRARIAN_HPP
#define LIBRARYSYSTEM_LIBRARIAN_HPP
#include "Person.hpp"
using namespace std;

class Librarian: public Person {
private:
    double balance;
    double fine = 0.10;
    int days;
public:

     bool getAdminStatus() {return true;} 

    Librarian(const string& name, const string& pass) : Person() { 
	this-> name= name; 
	this->pass = pass;
        
}

    vector<Book*> getVec() {return vector<Book*>();}



};

#endif //LIBRARYSYSTEM_LIBRARIAN_HPP

