#include <iostream>
#include "header.h"

using namespace std;

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	// ewentualny kod
	return RUN_ALL_TESTS();
}

TEST(TestCaseName1, TestName1) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(TestCaseName1, TestName2) {
	EXPECT_EQ(0, 1);
	EXPECT_TRUE(true);
}