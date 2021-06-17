#pragma once
#include "SearchStrat.hpp"
#include "LibraryCatalog.hpp"
#include <stack>
#include "SearchOR.hpp"
#include "SearchAND.hpp"
#include "SearchContains.hpp"
#include <iostream>
using namespace std;
class search_factory{
	public:

	SearchStrat* createField();
	bool isValidField(const int& field);
	bool isValidChoice(const int& choice);
	SearchStrat* makeSearch();

};
