#include "pch.h"

// naRadiany (double)
TEST(Test, naRadianyDouble) {
    EXPECT_DOUBLE_EQ(naRadiany(0.0), 0.0);
    EXPECT_DOUBLE_EQ(naRadiany(90.0), M_PI / 2.0);
    EXPECT_DOUBLE_EQ(naRadiany(180.0), M_PI);
    EXPECT_DOUBLE_EQ(naRadiany(360.0), 2.0 * M_PI);
}

// naRadiany (float)
TEST(Test, naRadianyFloat) {
    EXPECT_FLOAT_EQ(naRadiany(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(naRadiany(90.0f), (M_PI / 2.0));
    EXPECT_FLOAT_EQ(naRadiany(180.0f), (M_PI));
    EXPECT_FLOAT_EQ(naRadiany(360.0f), (2.0 * M_PI));
}

// naStopnie (double)
TEST(Test, naStopnieDouble) {
    EXPECT_DOUBLE_EQ(naStopnie(0.0), 0.0);
    EXPECT_DOUBLE_EQ(naStopnie(M_PI / 2.0), 90.0);
    EXPECT_DOUBLE_EQ(naStopnie(M_PI), 180.0);
    EXPECT_DOUBLE_EQ(naStopnie(2.0 * M_PI), 360.0);
}

// naStopnie (float)
TEST(Test, naStopnieFloat) {
    EXPECT_FLOAT_EQ(naStopnie(0.0f), 0.0f);
    EXPECT_FLOAT_EQ(naStopnie(M_PI / 2.0), 90.0f);
    EXPECT_FLOAT_EQ(naStopnie(M_PI), 180.0f);
    EXPECT_FLOAT_EQ(naStopnie(2.0 * M_PI), 360.0f);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}