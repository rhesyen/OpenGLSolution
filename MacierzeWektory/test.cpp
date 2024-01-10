#include "pch.h"
#include "gtest/gtest.h"
#include "macierz.h"
#include "wektor.h"

TEST(WektorTest, DodawanieWektorow) {
    Wektor3 v1(1.0f, 2.0f, 3.0f);
    Wektor3 v2(4.0f, 5.0f, 6.0f);

    Wektor3 wynik = v1.dodaj(v2);

    ASSERT_FLOAT_EQ(wynik.getX(), 5.0f);
    ASSERT_FLOAT_EQ(wynik.getY(), 7.0f);
    ASSERT_FLOAT_EQ(wynik.getZ(), 9.0f);
}

//dodac testy: dodaj, odejmij, dlugosc dla Wektor4 i dodaj, odejmij, pomnoz z macierzy 3 oraz 4

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}