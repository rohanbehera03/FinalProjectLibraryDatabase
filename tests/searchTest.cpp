#include "../header/BookRepository.hpp"
#include "../header/Book.hpp"
#include "../header/Date.hpp"
#include "../header/BookItem.hpp"
#include "../header/SearchContains.hpp"
#include "../header/SearchStrat.hpp"
#include "../header/SearchAND.hpp"
#include "../header/SearchOR.hpp"
#include "../header/LibraryCatalog.hpp"
#include "../header/search_factory.hpp"
#include <sstream>
#include "gtest/gtest.h"

TEST(GenreTest,mystery){
	BookRepository* repo = new BookRepository();
	repo->populate("book.txt");
	SearchStrat* strat = new SearchContains("Genre", "Mystery");
	EXPECT_EQ(strat->search(repo).size(),9);

	delete repo;
	delete strat;

} 


TEST(GenreTest,nonfiction){
	BookRepository* repo = new BookRepository();
	repo->populate("book.txt");
	SearchStrat* strat = new SearchContains("Genre", "Nonfiction");
	EXPECT_EQ(strat->search(repo).size(),117);
	delete repo;
	delete strat;

}

TEST(GenreTest, Fiction){
	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Fiction");
        EXPECT_EQ(strat->search(repo).size(),120);
        delete repo;
	delete strat;

}

TEST(GenreTest, Romance){

	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Romance");
        EXPECT_EQ(strat->search(repo).size(),8);
	delete repo;
	delete strat;
}

TEST(GenreTest, Literature){


	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Literature");
        EXPECT_EQ(strat->search(repo).size(),12);
        delete repo;
	delete strat;
}


TEST(GenreTest, Manga){


	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Manga");
        EXPECT_EQ(strat->search(repo).size(),12);
        delete repo;
	delete strat;
}

TEST(GenreTest, Horror){

	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Horror");
        EXPECT_EQ(strat->search(repo).size(),12);
        delete repo;
	delete strat;

}

TEST(GenreTest, Science){

	
        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Science");
        EXPECT_EQ(strat->search(repo).size(),10);
        delete repo;
        delete strat;

}

TEST(GenreTest, Biography){

	
        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Biography");
        EXPECT_EQ(strat->search(repo).size(),37);
        delete repo;
        delete strat;


}
TEST(GenreTest, TravelGuides){
	
        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Travel Guides");
        EXPECT_EQ(strat->search(repo).size(),7);
        delete repo;
        delete strat;

}

TEST(GenreTest, Philosophy){

        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Philosophy");
        EXPECT_EQ(strat->search(repo).size(),9);
        delete repo;
        delete strat;

}
TEST(SearchContains, MispelledAuthor){
	stringstream ss;
	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
	repo->display();
        SearchStrat* strat = new SearchContains("Genre", "Tom Bert" );
	LibraryCatalog* cat = new LibraryCatalog();
	cat->set_search(strat);
	cat->print_search(repo, ss);	
	EXPECT_EQ(ss.str(),"No Results!\n");
	delete repo;	
	delete cat;
}

TEST(AND, ScienceANDJKRowling){
	stringstream ss;
	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        repo->display();
	LibraryCatalog* cat = new LibraryCatalog();
        SearchStrat* strat = new SearchAND(new SearchContains("Genre", "Science") , new SearchContains("Author", "J.K. Rowling" ));
	cat->set_search(strat);
	cat->print_search(repo,ss);	
        EXPECT_EQ(ss.str(),"No Results!\n");
        delete repo;
	delete cat;
}

TEST(AND,ScienceANDRomance){
	stringstream ss;
        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        repo->display();
        LibraryCatalog* cat = new LibraryCatalog();
        SearchStrat* strat = new SearchAND(new SearchContains("Genre", "Science") , new SearchContains("Genre", "Romance" ));
        cat->set_search(strat);
        cat->print_search(repo,ss);
        EXPECT_EQ(ss.str(),"No Results!\n");
        delete repo;
        delete cat;

}

TEST(AND, RomanceANDFiction){
	stringstream ss;
        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        repo->display();
        LibraryCatalog* cat = new LibraryCatalog();
        SearchStrat* strat = new SearchAND(new SearchContains("Genre", "Fiction") , new SearchContains("Genre", "Romance" ));
        cat->set_search(strat);
        cat->print_search(repo,ss);
        EXPECT_EQ(ss.str(),"No Results!\n");
        delete repo;
        delete cat;


}

TEST(GenreTest, Adventure){

        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Adventure");
        EXPECT_EQ(strat->search(repo).size(),5);
        delete repo;
        delete strat;

}

TEST(GenreTest, Thriller){
        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Genre", "Thriller");
        EXPECT_EQ(strat->search(repo).size(),24);
        delete repo;
        delete strat;
}

TEST(SearchTest, JK_Rowling){
	BookRepository* repo = new BookRepository();
	repo->populate("book1.txt");
	SearchStrat* strat = new SearchContains("Author", "J.K. Rowling");
	LibraryCatalog* cat = new LibraryCatalog();
	cat->set_search(strat);
	stringstream ss;
	cat->print_search(repo, ss);
	string ans = "Harry Potter and the Sorceror's Stone J.K. Rowling 0000000000026 Checkout Status: False\nHarry Potter and the Chamber of Secrets J.K. Rowling 0000000000027 Checkout Status: False\nHarry Potter and the Prisoner of Azkaban J.K. Rowling 0000000000028 Checkout Status: False\nHarry Potter and the Goblet of Fire J.K. Rowling 0000000000029 Checkout Status: False\nHarry Potter and the Order of the Pheonix J.K. Rowling 0000000000030 Checkout Status: False\nHarry Potter and the Half-Blood Prince J.K. Rowling 0000000000031 Checkout Status: False\nHarry Potter and the Deathly Hallows J.K. Rowling 0000000000032 Checkout Status: False\nHarry Potter and the Cursed Child J.K. Rowling 0000000000033 Checkout Status: False\n";
	EXPECT_EQ(ss.str(), ans);
	delete repo;
	delete cat;

}

TEST(SearchTest, RachelCarson){
	BookRepository* repo = new BookRepository();
        repo->populate("book5.txt");
        SearchStrat* strat = new SearchContains("Author", "Rachel Carson");
        LibraryCatalog* cat = new LibraryCatalog();
        cat->set_search(strat);
        stringstream ss;
        cat->print_search(repo, ss);
	string ans = "Silent Spring Rachel Carson 0000000000198 Checkout Status: False\n";
	EXPECT_EQ(ss.str(), ans);
	delete repo;
	delete cat;
}

TEST(SearchTest, RomanceBook5){

	BookRepository* repo = new BookRepository();
        repo->populate("book5.txt");
        SearchStrat* strat = new SearchContains("Genre", "Romance");
        LibraryCatalog* cat = new LibraryCatalog();
        cat->set_search(strat);
        stringstream ss;
        cat->print_search(repo, ss);
        string ans = "No Results!\n";
        EXPECT_EQ(ss.str(), ans);
        delete repo;
        delete cat;
	

}

TEST(SearchTest, SecretGarden){

	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Title", "The Secret Garden");
        LibraryCatalog* cat = new LibraryCatalog();
        cat->set_search(strat);
        stringstream ss;
        cat->print_search(repo, ss);
        string ans = "The Secret Garden Frances Hodgson Burnett 0000000000075 Checkout Status: False\n";
        EXPECT_EQ(ss.str(), ans);
        delete repo;
        delete cat;

}

TEST(OR, NightORApology){



	BookRepository* repo = new BookRepository();
        repo->populate("book4.txt");
        SearchStrat* strat = new SearchOR(new SearchContains("Title", "Night"), new SearchContains("Title", "Apology"));
        LibraryCatalog* cat = new LibraryCatalog();
        cat->set_search(strat);
        stringstream ss;
        cat->print_search(repo, ss);
        string ans = "Night Elie Wiesel 0000000000134 Checkout Status: False\nApology Plato 0000000000147 Checkout Status: False\n";
        EXPECT_EQ(ss.str(), ans);
        delete repo;
        delete cat;


}

TEST(All, ANDOR){

	BookRepository* repo = new BookRepository();
        repo->populate("book4.txt");
        SearchStrat* strat = new SearchAND( new SearchContains("title", "not") ,new SearchOR(new SearchContains("Title", "Night"), new SearchContains("Title", "Apology")));
        LibraryCatalog* cat = new LibraryCatalog();
        cat->set_search(strat);
        stringstream ss;
        cat->print_search(repo, ss);
        string ans = "No Results!\n";
        EXPECT_EQ(ss.str(), ans);
        delete repo;
        delete cat;

}

TEST(All, ORAND){

	BookRepository* repo = new BookRepository();
        repo->populate("book5.txt");
        SearchStrat* strat = new SearchAND( new SearchContains("Author", "Brian Catling") ,new SearchOR(new SearchContains("Title", "Night"), new SearchContains("Title", "Apology")));
        LibraryCatalog* cat = new LibraryCatalog();
        cat->set_search(strat);
        stringstream ss;
        cat->print_search(repo, ss);
        string ans = "No Results!\n";
        EXPECT_EQ(ss.str(), ans);
        delete repo;
        delete cat;

}

TEST(SearchTest, PrideAndPrejudice){
	BookRepository* repo = new BookRepository();
	repo->populate("book.txt");
	SearchStrat* strat = new SearchContains("Title", "Pride and Prejudice");
	LibraryCatalog* cat = new LibraryCatalog();
	cat->set_search(strat);
	stringstream ss;
	cat->print_search(repo,ss);
	string as = "Pride and Prejudice Jane Austen 0000000000036 Checkout Status: False\n";
	EXPECT_EQ(ss.str(), as);
	delete repo;
	delete cat;
}

TEST(SearchTest, TheCast){

	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Title", "The Cast");
        LibraryCatalog* cat = new LibraryCatalog();
        cat->set_search(strat);
        stringstream ss;
        cat->print_search(repo,ss);
        string as = "The Cast Danielle Steel 0000000000230 Checkout Status: False\n";
        EXPECT_EQ(ss.str(), as);
        delete repo;
        delete cat;


}

TEST(SearchTest, TheOutside){


	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Title", "The Outsider");
        LibraryCatalog* cat = new LibraryCatalog();
        cat->set_search(strat);
        stringstream ss;
        cat->print_search(repo,ss);
        string as = "The Outsider Stephen King 0000000000231 Checkout Status: False\n";
        EXPECT_EQ(ss.str(), as);
        delete repo;
        delete cat;


}

TEST(SearchTest, LethalWhite){


	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Title", "Lethal White");
        LibraryCatalog* cat = new LibraryCatalog();
        cat->set_search(strat);
        stringstream ss;
        cat->print_search(repo,ss);
        string as = "Lethal White Robert Galbraith 0000000000237 Checkout Status: False\n";
        EXPECT_EQ(ss.str(), as);
        delete repo;
        delete cat;


}

TEST(SearchTest, CrazyRichAsians){

	
        BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Title", "Crazy Rich Asians");
        LibraryCatalog* cat = new LibraryCatalog();
        cat->set_search(strat);
        stringstream ss;
        cat->print_search(repo,ss);
        string as = "Crazy Rich Asians Kevin Kwan 0000000000235 Checkout Status: False\n";
        EXPECT_EQ(ss.str(), as);
        delete repo;
        delete cat;

}

TEST(SearchTest, AndyMcNab){

	BookRepository* repo = new BookRepository();
        repo->populate("book.txt");
        SearchStrat* strat = new SearchContains("Author", "Andy McNab");
        LibraryCatalog* cat = new LibraryCatalog();
        cat->set_search(strat);
        stringstream ss;
        cat->print_search(repo,ss);
        string as = "Seven Troop Andy McNab 0000000000222 Checkout Status: False\nSpoken From the Front Andy McNab 0000000000224 Checkout Status: False\n";
        EXPECT_EQ(ss.str(), as);
        delete repo;
        delete cat;







}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
