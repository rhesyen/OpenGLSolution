#include "pch.h"
#include "gtest/gtest.h"
#include "macierz.h"
#include "wektor.h"


//WEKTORY:
TEST(Wektor3Test, DodawanieWektorow) {
    Wektor3 v1(1.0f, 2.0f, 3.0f);
    Wektor3 v2(4.0f, 5.0f, 6.0f);

    Wektor3 wynik = v1.dodaj(v2);

    ASSERT_FLOAT_EQ(wynik.getX(), 5.0f);
    ASSERT_FLOAT_EQ(wynik.getY(), 7.0f);
    ASSERT_FLOAT_EQ(wynik.getZ(), 9.0f);
}

TEST(Wektor3Test, IloczynSkalarny) {
    Wektor3 v1(1.0f, 2.0f, 3.0f);
    Wektor3 v2(4.0f, 5.0f, 6.0f);

    float wynik = v1.skalarny(v2);

    //iloczyn skalarny dla v1 i v2 bêdzie równy 32 (1*4 + 2*5 + 3*6)
    ASSERT_FLOAT_EQ(wynik, 32.0f);
}
TEST(Wektor4Test, OdejmowanieWektorow) {
    Wektor4 v1(1.0f, 2.0f, 3.0f, 4.0f);
    Wektor4 v2(0.5f, 1.0f, 1.5f, 2.0f);

    Wektor4 wynik = v1.odejmij(v2);

    ASSERT_FLOAT_EQ(wynik.getX(), 0.5f);
    ASSERT_FLOAT_EQ(wynik.getY(), 1.0f);
    ASSERT_FLOAT_EQ(wynik.getZ(), 1.5f);
    ASSERT_FLOAT_EQ(wynik.getW(), 2.0f);
}

TEST(Wektor4Test, DlugoscWektora) {
    Wektor4 v(3.0f, 4.0f, 0.0f, 0.0f);

    float dlugosc = v.dlugosc();

    ASSERT_FLOAT_EQ(dlugosc, 5.0f);
}

//MACIERZE:
TEST(Macierz3Test, DodawanieMacierzy) {
    Macierz3 m1(5.0f);
    Macierz3 m2(2.0f);

    Macierz3 wynik = m1.dodaj(m2);

    ASSERT_EQ(wynik.getij(0, 0), m1.getij(0, 0) + m2.getij(0, 0));
    ASSERT_EQ(wynik.getij(1, 0), m1.getij(1, 0) + m2.getij(1, 0));
}

TEST(Macierz3Test, PomnozPrzezSkalar) {
    Macierz3 m(1.0f);
    Macierz3 oryginal = m;
    float scalar = 2.0f;
    m.pomnoz(scalar);

    ASSERT_EQ(m.getij(0, 0), oryginal.getij(0, 0) * scalar);
}
TEST(Macierz4Test, PomnozMacierzPrzezMacierz) {
    Macierz4 m1;
    m1.setij(0, 0, 1.0f);
    m1.setij(0, 1, 2.0f);
    m1.setij(0, 2, 3.0f);
    m1.setij(0, 3, 4.0f);

    Macierz4 m2;
    m2.setij(0, 0, 5.0f);
    m2.setij(1, 0, 6.0f);
    m2.setij(2, 0, 7.0f);
    m2.setij(3, 0, 8.0f);

    Macierz4 wynik = m1.pomnoz(m2);
    //ka¿dy element macierzy wynikowej jest sum¹ iloczynów elementów odpowiednich wiersza pierwszej macierzy i kolumny drugiej macierzy
    ASSERT_EQ(wynik.getij(0, 0), m1.getij(0, 0) * m2.getij(0, 0) + m1.getij(0, 1) * m2.getij(1, 0) + m1.getij(0, 2) * m2.getij(2, 0) + m1.getij(0, 3) * m2.getij(3, 0));
    ASSERT_EQ(wynik.getij(0, 1), m1.getij(0, 0) * m2.getij(0, 1) + m1.getij(0, 1) * m2.getij(1, 1) + m1.getij(0, 2) * m2.getij(2, 1) + m1.getij(0, 3) * m2.getij(3, 1));
    ASSERT_EQ(wynik.getij(0, 2), m1.getij(0, 0) * m2.getij(0, 2) + m1.getij(0, 1) * m2.getij(1, 2) + m1.getij(0, 2) * m2.getij(2, 2) + m1.getij(0, 3) * m2.getij(3, 2) );
}

TEST(Macierz4Test, DodawanieMacierzy) {
    Macierz4 m1;
    m1.setij(0, 0, 1.0f);
    m1.setij(0, 1, 2.0f);
    m1.setij(0, 2, 3.0f);
    m1.setij(0, 3, 4.0f);

    Macierz4 m2;
    m2.setij(0, 0, 5.0f);
    m2.setij(1, 0, 6.0f);
    m2.setij(2, 0, 7.0f);
    m2.setij(3, 0, 8.0f);

    Macierz4 wynik = m1.dodaj(m2);

    ASSERT_EQ(wynik.getij(0, 0), m1.getij(0, 0) + m2.getij(0, 0));

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}