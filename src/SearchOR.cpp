#include "../header/SearchOR.hpp"


vector<Book*> SearchOR::search(const BookRepository* b){
    
    vector<Book*> Ored;
    
    for(auto it : lhs->search(b)){
    
        Ored.emplace_back(it);
                
    }
            
    for(auto jt : rhs->search(b)){
        
        Ored.emplace_back(jt);
    }
    
    return Ored;

}
