#include "../header/Date.hpp"

#include "gtest/gtest.h"

TEST(incrementTest, leapYear) {
	Date currDate(28,2,2004);
	currDate.increment();
	
	Date checkDate(29, 2, 2004);

	EXPECT_EQ(currDate.getDay(), checkDate.getDay());
}

TEST(incrementTest, nonLeapYear) { 
	Date currDate(28, 2, 2003);
	currDate.increment();

	Date checkDate(1, 3, 2003);

	EXPECT_EQ(currDate.getDay(), checkDate.getDay());
}

TEST(incrementTest, multOfHundredNotFourHundred) {
	Date currDate(28, 2, 2500);
	currDate.increment();

	Date checkDate(1, 3, 2500);
	
	EXPECT_EQ(currDate.getDay(), checkDate.getDay());
}

TEST(incrementTest, thirty) {
	Date currDate(30, 6, 2000);
	currDate.increment();

	Date checkDate(1, 7, 2000);
    
	EXPECT_EQ(currDate.getDay(), checkDate.getDay());
}

TEST(incrementTest, thirtyOne) {
	Date currDate(31, 1, 2000);
	currDate.increment();
	
	Date checkDate(1, 2, 2000);
	
	EXPECT_EQ(currDate.getDay(), checkDate.getDay());
}

TEST(incrementTest, endOfYear) {
	Date currDate(31, 12, 2000);
	currDate.increment();

	Date checkDate(1, 1, 2001);

	EXPECT_EQ(currDate.getDay(), checkDate.getDay());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

