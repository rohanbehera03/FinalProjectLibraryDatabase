#include "SearchStrat.hpp"
#pragma once

class SearchAND : public SearchStrat {

  private:
	
  SearchStrat* lhs;
  SearchStrat* rhs;

  public:
    ~SearchAND(){
        delete lhs;
        delete rhs;
    }
    SearchAND(SearchStrat* lhs, SearchStrat* rhs) : SearchStrat(){ 
	this->lhs = lhs;
	this->rhs = rhs;
    }
    vector<Book*> search(const BookRepository*);
    const string display(){

	return  " AND(" + lhs->display() + " ," + rhs->display() + " )"; 
    }
};

