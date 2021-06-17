#ifndef LIBRARYSYSTEM_LIBRARYCATALOG_H
#define LIBRARYSYSTEM_LIBRARYCATALOG_H
#include "BookRepository.hpp"
#include "SearchStrat.hpp"
#include <iostream>

class LibraryCatalog {

	SearchStrat* strat;

	public:
		~LibraryCatalog(){	delete this->strat;}
		void print_search(const BookRepository* ,ostream& out);
		void set_search(SearchStrat* strat);
		
};


#endif //LIBRARYSYSTEM_LIBRARYCATALOG_H
