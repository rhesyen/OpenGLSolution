// wektor.h
#pragma once

#include <iostream>

class Wektor3 {  
public:
    float x, y, z;

    Wektor3();
    Wektor3(float x, float y, float z);
    Wektor3(float values[3]);

    //kopiuj - kopiuj¹c¹ elementy danego wektora do innego
    void kopiuj(const Wektor3& other);
    //dodaj – dodaj¹c¹ do siebie dwa wektory
    Wektor3 dodaj(const Wektor3& other) const;
    //odejmij – odejmuj¹c¹ jeden wektor od drugiego
    Wektor3 odejmij(const Wektor3& other) const;
    //pomnoz – mno¿¹c¹ wektor przez liczbê ca³kowit¹
    void pomnoz(int scalar);
    //wypisz – wypisuj¹c¹ w sformatowany sposób wektor
    void wypisz() const;
    //ustawianie i zwracanie x, y, z, w (setters, getters)
    void setX(float value);
    void setY(float value);
    void setZ(float value);
    float getX() const;
    float getY() const;
    float getZ() const;
    //getDane – zwraca wskaŸnik do tablicy (pola klasy)
    float* getDane();
    //normalizuj – normalizuj¹c¹ wektor
    void normalizuj();
    //skalarny – realizuj¹c¹ iloczyn skalarny
    float skalarny(const Wektor3& other) const;
    //wektorowy – realizuj¹c¹ iloczyn wektorowy
    Wektor3 wektorowy(const Wektor3& other) const;
    //dlugosc – zwracaj¹c¹ d³ugoœæ wektora
    float dlugosc() const;
};

class Wektor4 {
public:
    float x, y, z, w;

    Wektor4();
    Wektor4(float x, float y, float z, float w);
    Wektor4(float values[4]);

    //kopiuj - kopiuj¹c¹ elementy danego wektora do innego
    void kopiuj(const Wektor4& other);
    //dodaj – dodaj¹c¹ do siebie dwa wektory
    Wektor4 dodaj(const Wektor4& other) const;
    //odejmij – odejmuj¹c¹ jeden wektor od drugiego
    Wektor4 odejmij(const Wektor4& other) const;
    //pomnoz – mno¿¹c¹ wektor przez liczbê ca³kowit¹
    void pomnoz(int scalar);
    //wypisz – wypisuj¹c¹ w sformatowany sposób wektor
    void wypisz() const;
    //ustawianie i zwracanie x, y, z, w (setters, getters)
    void setX(float value);
    void setY(float value);
    void setZ(float value);
    void setW(float value);
    float getX() const;
    float getY() const;
    float getZ() const;
    float getW() const;
    //getDane – zwraca wskaŸnik do tablicy (pola klasy)
    float* getDane();
    //normalizuj – normalizuj¹c¹ wektor
    void normalizuj();
    //skalarny – realizuj¹c¹ iloczyn skalarny
    float skalarny(const Wektor4& other) const;
    //wektorowy – realizuj¹c¹ iloczyn wektorowy
    Wektor4 wektorowy(const Wektor4& other) const;
    //dlugosc – zwracaj¹c¹ d³ugoœæ wektora
    float dlugosc() const;
};
