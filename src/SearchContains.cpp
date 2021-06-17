#include "../header/SearchContains.hpp"

vector<Book*> SearchContains::search(const BookRepository* b){ //verifies it's a right searchBy && searchQuery is correct
    
    if(searchBy == "Author" && (b->getMapAuthor().count(searchQuery) != 0))  return b->getMapAuthor().at(searchQuery);
 
	//for(auto it : b->getMapAuthor().find(searchQuery)->second){
	
	//	std::cout <<  "Found!!!! "  << it->getTitle() << " ";

	//}


    
    else if (searchBy == "Title" && (b->getMapTitle().count(searchQuery) != 0)) return b->getMapTitle().at(searchQuery);
    
    else if (searchBy == "Genre"&& (b->getMapGenre().count(searchQuery) != 0)) return b->getMapGenre().at(searchQuery);
    
    return vector<Book*>();
        
    
}

