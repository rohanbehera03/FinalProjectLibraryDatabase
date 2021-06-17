#include "../header/BookRepository.hpp"
#include "../header/User.hpp"
#include "gtest/gtest.h"

TEST(checkOutTest, single) {
	BookRepository* repo = new BookRepository();
	repo->populate("testBooks.txt");
	
	Book* bk = repo->getBookByISBN("1");
	Date currDate(1,1,2000); 
	
	User* me = new User("C", "0");
	me->checkout(bk, currDate, repo);

	EXPECT_EQ(me->getMyBooks().at(0)->getISBN() , bk->getISBN());	

	delete repo;
	delete me;
}
TEST(checkOutTest, status) {
	BookRepository* repo = new BookRepository();
	repo->populate("testBooks.txt");

	Book* bk = repo->getBookByISBN("1");
        Date currDate(1,1,2000);

        User* me = new User("C", "0");
        me->checkout(bk, currDate, repo);

	EXPECT_EQ(bk->getCheckoutStatus(), true);
	
	delete repo;
	delete me;
}
TEST(checkOutTest, mult) {
	BookRepository* repo = new BookRepository();
        repo->populate("testBooks.txt");

        Book* bk = repo->getBookByISBN("2");
        Date currDate(1,1,2000);

        User* me = new User("C", "0");
        me->checkout(bk, currDate, repo);

	bk = repo->getBookByISBN("1");
	me->checkout(bk, currDate, repo);

	EXPECT_EQ(me->getMyBooks().at(1)->getISBN(), bk->getISBN());
	
	delete repo;
	delete me;

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
