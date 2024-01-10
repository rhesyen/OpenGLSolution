#include "pch.h"
#include "macierz.h"

//KONSTRUKTORY
Macierz3::Macierz3() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            elements[i][j] = 0.0f;
}

Macierz3::Macierz3(float scalar) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            elements[i][j] = scalar;
}

Macierz3::Macierz3(float values[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            elements[i][j] = values[i][j];
}

Macierz4::Macierz4() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            elements[i][j] = 0.0f;
}

Macierz4::Macierz4(float scalar) {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            elements[i][j] = scalar;
}

Macierz4::Macierz4(float values[4][4]) {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            elements[i][j] = values[i][j];
}

//**********************************************************

//MACIERZ 3:
// macierz.cpp

// Metoda kopiuj
void Macierz3::kopiuj(const Macierz3& other) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            elements[i][j] = other.elements[i][j];
}

// Metoda dodaj
Macierz3 Macierz3::dodaj(const Macierz3& other) const {
    Macierz3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.elements[i][j] = elements[i][j] + other.elements[i][j];
    return result;
}

// Metoda odejmij
Macierz3 Macierz3::odejmij(const Macierz3& other) const {
    Macierz3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.elements[i][j] = elements[i][j] - other.elements[i][j];
    return result;
}

// Metoda pomnoz przez liczbe calkowita
void Macierz3::pomnoz(int scalar) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            elements[i][j] *= scalar;
}

// Metoda pomnoz przez macierz
Macierz3 Macierz3::pomnoz(const Macierz3& other) const {
    Macierz3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                result.elements[i][j] += elements[i][k] * other.elements[k][j];
    return result;
}

// Metoda wypisz
void Macierz3::wypisz() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            std::cout << elements[i][j] << " ";
        std::cout << std::endl;
    }
}

// Metoda setij
void Macierz3::setij(int i, int j, float value) {
    elements[i][j] = value;
}

// Metoda getij
float Macierz3::getij(int i, int j) const {
    return elements[i][j];
}

// Metoda getDane
float* Macierz3::getDane() {
    return &elements[0][0];
}

// Metoda jednostkowa
void Macierz3::jednostkowa() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            elements[i][j] = (i == j) ? 1.0f : 0.0f;
}

// Metoda transponowana
Macierz3 Macierz3::transponowana() const {
    Macierz3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.elements[i][j] = elements[j][i];
    return result;
}
//*********************************************************

//MACIERZ 4:

// Metoda kopiuj
void Macierz4::kopiuj(const Macierz4& other) {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            elements[i][j] = other.elements[i][j];
}

// Metoda dodaj
Macierz4 Macierz4::dodaj(const Macierz4& other) const {
    Macierz4 result;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            result.elements[i][j] = elements[i][j] + other.elements[i][j];
    return result;
}

// Metoda odejmij
Macierz4 Macierz4::odejmij(const Macierz4& other) const {
    Macierz4 result;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            result.elements[i][j] = elements[i][j] - other.elements[i][j];
    return result;
}

// Metoda pomnoz przez liczbe calkowita
void Macierz4::pomnoz(int scalar) {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            elements[i][j] *= scalar;
}

// Metoda pomnoz przez macierz
Macierz4 Macierz4::pomnoz(const Macierz4& other) const {
    Macierz4 result;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                result.elements[i][j] += elements[i][k] * other.elements[k][j];
    return result;
}

// Metoda wypisz
void Macierz4::wypisz() const {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j)
            std::cout << elements[i][j] << " ";
        std::cout << std::endl;
    }
}

// Metoda setij
void Macierz4::setij(int i, int j, float value) {
    elements[i][j] = value;
}

// Metoda getij
float Macierz4::getij(int i, int j) const {
    return elements[i][j];
}

// Metoda getDane
float* Macierz4::getDane() {
    return &elements[0][0];
}

// Metoda jednostkowa
void Macierz4::jednostkowa() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            elements[i][j] = (i == j) ? 1.0f : 0.0f;
}

// Metoda transponowana
Macierz4 Macierz4::transponowana() const {
    Macierz4 result;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            result.elements[i][j] = elements[j][i];
    return result;
}

