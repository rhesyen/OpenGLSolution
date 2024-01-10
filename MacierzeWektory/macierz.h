// macierz.h
#pragma once

#include <iostream>

class Macierz3 {
private:
    float elements[3][3];
public:
  
    Macierz3();
    Macierz3(float scalar);
    Macierz3(float values[3][3]);

    void kopiuj(const Macierz3& other);
    Macierz3 dodaj(const Macierz3& other) const;
    Macierz3 odejmij(const Macierz3& other) const;
    void pomnoz(int scalar);
    Macierz3 pomnoz(const Macierz3& other) const;
    void wypisz() const;
    void setij(int i, int j, float value);
    float getij(int i, int j) const;
    float* getDane();
    void jednostkowa();
    Macierz3 transponowana() const;
};

class Macierz4 {
private:
    float elements[4][4];
public:

    Macierz4();
    Macierz4(float scalar);
    Macierz4(float values[4][4]);

    void kopiuj(const Macierz4& other);
    Macierz4 dodaj(const Macierz4& other) const;
    Macierz4 odejmij(const Macierz4& other) const;
    void pomnoz(int scalar);
    Macierz4 pomnoz(const Macierz4& other) const;
    void wypisz() const;
    void setij(int i, int j, float value);
    float getij(int i, int j) const;
    float* getDane();
    void jednostkowa();
    Macierz4 transponowana() const;
};
