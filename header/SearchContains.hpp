#pragma once
#include "SearchStrat.hpp"

class SearchContains : public SearchStrat {

  string searchBy;
  string searchQuery;

  public:
    
    SearchContains(const string& searchBy, const string& searchQuery) : SearchStrat() {
	this->searchBy = searchBy;
	this->searchQuery = searchQuery;
    }
    vector<Book*> search(const BookRepository*);
    const string display(){
	
	return " " + searchBy + ": " +  searchQuery; 

    }
};

