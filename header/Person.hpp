#ifndef LIBRARYSYSTEM_PERSON_HPP
#define LIBRARYSYSTEM_PERSON_HPP

#include <iostream>
#include <vector>
#include "Book.hpp"
#include "BookRepository.hpp"

using namespace std;
#pragma once

class Person{

protected:
    string name, pass; 
public:
    virtual ~Person() = default;
    Person() {}
    virtual bool getAdminStatus() = 0;
    virtual vector<Book*> getVec() = 0;
    Person(const string& name, const string& pass) : name(name), pass(pass){}
    string getName() const{ return name;}
    void setName(const string& name){ this->name = name;}
    string getPass() const{ return pass;}
    void setPass(const string& pass){ this->pass = pass;}

    virtual void checkout(Book* bk, const Date& today, BookRepository*& b) {}
    virtual void returnBook(Book* mybook, Date& c, BookRepository*& b) {}
    virtual double getBalance() {}
    virtual void payBalance(double m) {}
    virtual vector<Book*> getMyBooks() {return vector<Book*>();}



};

#endif //LIBRARYSYSTEM_PERSON_HPP
