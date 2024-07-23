#include "Pont.h"
#include <iostream>

Pont::Pont(int x, int y) : x(x), y(y) {}

void Pont::setXY(int uj_x, int uj_y) {
    x = uj_x;
    y = uj_y;
}

int Pont::getP_x() const {
    return x;
}

int Pont::getP_y() const {
    return y;
}

void Pont::DirW() {
    y--;
}

void Pont::DirS() {
    y++;
}
//Az x koordinátán kettesével kell mozogni, a sorok szellõssége így lett megoldva
void Pont::DirD() {
    x = x + 2;
}

void Pont::DirA() {
    x = x - 2;
}
//A kígyó testének kiirása
void Pont::Draw() const {
    std::cout << "o";
}
