#include "../header/search_factory.hpp"

bool search_factory::isValidChoice(const int& choice){	return choice > -1 && choice < 4;}

bool search_factory::isValidField(const int& field){  return field> -1 && field < 5;}

SearchStrat* search_factory::createField(){

	int field;
	string searchQuery;
	cin.ignore();
	cout << "Enter a keyword (Ex: J.K. Rowling): " << endl;
	getline(cin, searchQuery);
	//cout << "TEST!!!!!!!!" << endl;	
	cout << "Searchby: Title(1), Author(2), Genre(3), All fields(4): " << endl;
	
	cin >> field;
	//cout << "SECOND TEST!!!!!" << endl;
	while(!isValidField(field)){

		cout << "Invalid Field!" << endl;
		cout << "Searchby: Title(1), Author(2), Genre(3), All fields(4): " << endl;
 		cin >> field;

	}

	switch(field){

		case 1 :{

			return new SearchContains("Title", searchQuery);

		}

		case 2: {

			return new SearchContains("Author", searchQuery);

		}
	
		case 3: {

			return new SearchContains("Genre", searchQuery);

		}
	
		case 4:{
			
			return new SearchOR(new SearchContains("Title", searchQuery), new SearchOR(new SearchContains("Author", searchQuery), new SearchContains("Genre", searchQuery))); 

		}

	}


}


SearchStrat* search_factory::makeSearch(){
	int choice = -1;
	SearchStrat* root = nullptr;
	string searchQuery;
	stack<SearchStrat*> cont;

	while(choice != 0){

		if(choice == -1){ root = createField();}
		else if(choice == 2) {root = new SearchAND(cont.top(), createField());}
		else {root = new SearchOR(cont.top(), createField());}
		cout << "SearchBox:" << root->display() << endl;
		cout << "Enter another SearchBox (AND(2), OR(3), DONE(0))? :" << endl; 
		 		
		cin >> choice;

		while(!isValidChoice(choice)){

			cout << "Invalid Option!" << endl;
			cout << "Enter another SearchBox (AND(2), OR(3), DONE(0))? :" << endl;
			cin >> choice;

		}
		cont.push(root);

	}


	while(cont.size() > 0) cont.pop();
	return root;

}







