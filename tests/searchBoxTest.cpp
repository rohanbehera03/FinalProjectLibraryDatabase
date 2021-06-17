#include "gtest/gtest.h"
#include "../header/SearchContains.hpp"
#include "../header/SearchStrat.hpp"
#include "../header/SearchAND.hpp"
#include "../header/SearchOR.hpp"
#include "../header/BookRepository.hpp"
#include "../header/Book.hpp"

TEST(SearchBoxTest, DOUBLEOR){

	SearchStrat* strat = new SearchOR(new SearchOR(new SearchContains("Title", "Hi"), new SearchContains("Author", "Bye")), new SearchContains("Genre", "Hola"));
	EXPECT_EQ(strat->display()," OR( OR( Title: Hi , Author: Bye ) , Genre: Hola )" );
	delete strat;

}

TEST(SearchBoxTest, DOUBLEAND){

	SearchStrat* strat = new SearchAND(new SearchAND(new SearchContains("Title", "Hi"), new SearchContains("Author", "Bye")), new SearchContains("Genre", "Hola"));
	EXPECT_EQ(strat->display() ," AND( AND( Title: Hi , Author: Bye ) , Genre: Hola )" );
 	delete strat;
}

TEST(SearchBoxTest, Contains){

	SearchStrat* strat = new SearchContains("Genre" , "Science");
	EXPECT_EQ(strat->display(), " Genre: Science");
	delete strat;
}

TEST(SearchBoxTest, ORAND){

	SearchStrat* strat = new SearchOR(new SearchAND(new SearchContains("Title", "Hi"), new SearchContains("Author", "Bye")), new SearchContains("Genre", "Hola"));	
	EXPECT_EQ(strat->display()," OR( AND( Title: Hi , Author: Bye ) , Genre: Hola )" );
	delete strat;

}

TEST(SearchBoxTest, ANDContains){

	SearchStrat* strat = new SearchAND(new SearchContains("Title", "Hello"), new SearchContains("Author", "Bye"));
	EXPECT_EQ(strat->display(), " AND( Title: Hello , Author: Bye )");
	delete strat;
}

TEST(GetISBNTEST, MoonRoute66){


	BookRepository* repo = new BookRepository();
	repo->populate("book4.txt");
	EXPECT_EQ(repo->getBookByISBN("143")->getTitle(), "Moon Route 66 Road Trip");
	delete repo;


}


TEST(GetISBNTEST, SophiesWorld){

	BookRepository* repo = new BookRepository();
        repo->populate("book4.txt");
        EXPECT_EQ(repo->getBookByISBN("0153")->getTitle(), "Sophie's World");
        delete repo;

}

TEST(GetISBNTEST, DNE){

	BookRepository* repo = new BookRepository();
        repo->populate("book4.txt");
        EXPECT_EQ(repo->getBookByISBN("0"), nullptr);
        delete repo;


}

TEST(GetISBNTEST, SpaceOdyssey){

	BookRepository* repo = new BookRepository();
        repo->populate("book7.txt");
        EXPECT_EQ(repo->getBookByISBN("344")->getTitle(), "2001: A Space Odyssey");
        delete repo;

}

TEST(GetISBNTEST, ThePlague){

	BookRepository* repo = new BookRepository();
	repo->populate("book7.txt");
	EXPECT_EQ(repo->getBookByISBN("335")->getTitle(), "The Plague");
	delete repo;
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

