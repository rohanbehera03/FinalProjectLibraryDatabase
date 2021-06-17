#include "../header/SearchAND.hpp"


vector<Book*> SearchAND::search(const BookRepository* b){
    vector<Book*> l = lhs->search(b);
    vector<Book*> r = rhs->search(b);
 
    vector<Book*> anded; 
   for(auto it : l){
        
       //if(find(rhs->search(b).begin(), rhs->search(b).end(), it) != rhs->search(b).end()){
        for(auto jt : r){
        	
		if(it->getISBN() == jt->getISBN()){
	
            		//cout << "Element found " << it->getTitle() << endl;
			anded.emplace_back(it);
			break;
	
		}
            

                
        }
            
    }


    
    return anded;

}
