#include "pch.h"
#include "wektor.h"

//KONSTRUKTORY:
Wektor3::Wektor3() : x(0.0f), y(0.0f), z(0.0f) {}

Wektor3::Wektor3(float x, float y, float z) : x(x), y(y), z(z) {}

Wektor3::Wektor3(float values[3]) : x(values[0]), y(values[1]), z(values[2]) {}

Wektor4::Wektor4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}

Wektor4::Wektor4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

Wektor4::Wektor4(float values[4]) : x(values[0]), y(values[1]), z(values[2]), w(values[3]) {}

//****************************************************

//WEKTOR 4:
// Metoda kopiuj
void Wektor4::kopiuj(const Wektor4& other) {
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
}

// Metoda dodaj
Wektor4 Wektor4::dodaj(const Wektor4& other) const {
    return Wektor4(x + other.x, y + other.y, z + other.z, w + other.w);
}

// Metoda odejmij
Wektor4 Wektor4::odejmij(const Wektor4& other) const {
    return Wektor4(x - other.x, y - other.y, z - other.z, w - other.w);
}

// Metoda pomnoz
void Wektor4::pomnoz(int scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
}

// Metoda wypisz
void Wektor4::wypisz() const {
    std::cout << "[" << x << ", " << y << ", " << z << ", " << w << "]" << std::endl;
}

// Metody setters i getters
void Wektor4::setX(float value) {
    x = value;
}

void Wektor4::setY(float value) {
    y = value;
}

void Wektor4::setZ(float value) {
    z = value;
}

void Wektor4::setW(float value) {
    w = value;
}

float Wektor4::getX() const {
    return x;
}

float Wektor4::getY() const {
    return y;
}

float Wektor4::getZ() const {
    return z;
}

float Wektor4::getW() const {
    return w;
}

// Metoda getDane
float* Wektor4::getDane() {
    return &x;
}

// Metoda normalizuj
void Wektor4::normalizuj() {
    float length = sqrt(x * x + y * y + z * z);
    if (length != 0.0f) {
        x /= length;
        y /= length;
        z /= length;
        w /= length;
    }
}

// Metoda skalarny; jezeli 0 to prostopadle do siebie, jezeli dodatni to kat < 90 stopni, jezeli ujemny to kat > 90 stopni
float Wektor4::skalarny(const Wektor4& other) const {
    return x * other.x + y * other.y + z * other.z + w * other.w;
}

// Metoda wektorowy, tutaj nie ma iloczynu wektorowego dla 4! Poniewa¿ nie ma tradycyjnej reprezentacji geometrycznej
Wektor4 Wektor4::wektorowy(const Wektor4& other) const {
    return Wektor4();
}

// Metoda dlugosc
float Wektor4::dlugosc() const {
    return sqrt(x * x + y * y + z * z + w * w);
}

//*********************************************************************************
// 
//WEKTOR 3:
// Metoda kopiuj
void Wektor3::kopiuj(const Wektor3& other) {
    x = other.x;
    y = other.y;
    z = other.z;
}

// Metoda dodaj
Wektor3 Wektor3::dodaj(const Wektor3& other) const {
    return Wektor3(x + other.x, y + other.y, z + other.z);
}

// Metoda odejmij
Wektor3 Wektor3::odejmij(const Wektor3& other) const {
    return Wektor3(x - other.x, y - other.y, z - other.z);
}

// Metoda pomnoz
void Wektor3::pomnoz(int scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
}

// Metoda wypisz
void Wektor3::wypisz() const {
    std::cout << "[" << x << ", " << y << ", " << z << "]" << std::endl;
}

// Metody setters i getters
void Wektor3::setX(float value) {
    x = value;
}

void Wektor3::setY(float value) {
    y = value;
}

void Wektor3::setZ(float value) {
    z = value;
}

float Wektor3::getX() const {
    return x;
}

float Wektor3::getY() const {
    return y;
}

float Wektor3::getZ() const {
    return z;
}

// Metoda getDane
float* Wektor3::getDane() {
    return &x;
}

// Metoda normalizuj
void Wektor3::normalizuj() {
    float length = sqrt(x * x + y * y + z * z);
    if (length != 0.0f) {
        x /= length;
        y /= length;
        z /= length;
    }
}

// Metoda skalarny; jezeli 0 to prostopadle do siebie, jezeli dodatni to kat < 90 stopni, jezeli ujemny to kat > 90 stopni
float Wektor3::skalarny(const Wektor3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

// Metoda wektorowy
Wektor3 Wektor3::wektorowy(const Wektor3& other) const {
    return Wektor3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

// Metoda dlugosc
float Wektor3::dlugosc() const {
    return sqrt(x * x + y * y + z * z);
}
