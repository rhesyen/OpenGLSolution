// wektor.h
#pragma once

#include <iostream>

class Wektor3 {  
public:
    float x, y, z;

    Wektor3();
    Wektor3(float x, float y, float z);
    Wektor3(float values[3]);

    //kopiuj - kopiuj�c� elementy danego wektora do innego
    void kopiuj(const Wektor3& other);
    //dodaj � dodaj�c� do siebie dwa wektory
    Wektor3 dodaj(const Wektor3& other) const;
    //odejmij � odejmuj�c� jeden wektor od drugiego
    Wektor3 odejmij(const Wektor3& other) const;
    //pomnoz � mno��c� wektor przez liczb� ca�kowit�
    void pomnoz(int scalar);
    //wypisz � wypisuj�c� w sformatowany spos�b wektor
    void wypisz() const;
    //ustawianie i zwracanie x, y, z, w (setters, getters)
    void setX(float value);
    void setY(float value);
    void setZ(float value);
    float getX() const;
    float getY() const;
    float getZ() const;
    //getDane � zwraca wska�nik do tablicy (pola klasy)
    float* getDane();
    //normalizuj � normalizuj�c� wektor
    void normalizuj();
    //skalarny � realizuj�c� iloczyn skalarny
    float skalarny(const Wektor3& other) const;
    //wektorowy � realizuj�c� iloczyn wektorowy
    Wektor3 wektorowy(const Wektor3& other) const;
    //dlugosc � zwracaj�c� d�ugo�� wektora
    float dlugosc() const;
};

class Wektor4 {
public:
    float x, y, z, w;

    Wektor4();
    Wektor4(float x, float y, float z, float w);
    Wektor4(float values[4]);

    //kopiuj - kopiuj�c� elementy danego wektora do innego
    void kopiuj(const Wektor4& other);
    //dodaj � dodaj�c� do siebie dwa wektory
    Wektor4 dodaj(const Wektor4& other) const;
    //odejmij � odejmuj�c� jeden wektor od drugiego
    Wektor4 odejmij(const Wektor4& other) const;
    //pomnoz � mno��c� wektor przez liczb� ca�kowit�
    void pomnoz(int scalar);
    //wypisz � wypisuj�c� w sformatowany spos�b wektor
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
    //getDane � zwraca wska�nik do tablicy (pola klasy)
    float* getDane();
    //normalizuj � normalizuj�c� wektor
    void normalizuj();
    //skalarny � realizuj�c� iloczyn skalarny
    float skalarny(const Wektor4& other) const;
    //wektorowy � realizuj�c� iloczyn wektorowy
    Wektor4 wektorowy(const Wektor4& other) const;
    //dlugosc � zwracaj�c� d�ugo�� wektora
    float dlugosc() const;
};
