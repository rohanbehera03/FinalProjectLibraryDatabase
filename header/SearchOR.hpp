#include "BookRepository.hpp"
#include "SearchStrat.hpp"
#pragma once

class SearchOR : public SearchStrat{

  SearchStrat* lhs;
  SearchStrat* rhs;

  public:
    ~SearchOR(){
        delete lhs;
        delete rhs;
    }
    SearchOR(SearchStrat* lhs, SearchStrat* rhs) : SearchStrat(){
	this->lhs = lhs;
	this->rhs = rhs;
    }
    vector<Book*> search(const BookRepository*);
    const string display(){
    
	return " OR(" + lhs->display() + " ," + rhs->display() + " )";
    }
};

