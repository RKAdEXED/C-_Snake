#include "Snake.h"
#include <windows.h>
Snake::Snake(int meret)
{
    dir = "d";
    elozo_x_poz = (meret / 2) + ((meret / 2) % 2); // Corrected expression with parentheses
    elozo_y_poz = meret / 2;
    body = nullptr;

    body = new Pont[meret * meret];
    body[0] = Pont(((meret / 2) + ((meret / 2) % 2)), meret / 2);
}

void Snake::change_dir(const char* is) {
    dir = is;
}

const char* Snake::getDir() const {
    return dir;
}

void Snake::mozgas() {
    for (int i = hossz; i > 0; i--){
        body[i].setXY(body[i-1].getP_x(),body[i-1].getP_y()); //Hátulról elõre a testrészeknek átadjuk az elöttük lévõ coordinátáját
    }
    switch (dir[0]) {         //itt a legelsõ elemet, a fejet mozgatjuk
        case 'w':
            body[0].DirW();
            break;
        case 'a':
            body[0].DirA();
            break;
        case 's':
            body[0].DirS();
            break;
        case 'd':
            body[0].DirD();
            break;
    }
}

//A konzolt beállítja x, y koordinátákra
void setConsoleTo(int x, int y) {  //Alapból ez volt és egész jól futott, de ehez kell windows.h
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
/*
void setConsoleTo(int x, int y) {
    // Platform-specific commands to set console cursor position
    // For Windows:
    #ifdef _WIN32
        std::string command = "powershell -command \"[Console]::SetCursorPosition(" + std::to_string(x) + "," + std::to_string(y) + ")\"";
        system(command.c_str());
    // For macOS and Linux:
    #else
        std::cout << "\033[" << y << ";" << x << "H" << std::flush;
    #endif
}
*/
void Snake::snake_kiir() {
    for (int i = 0; i < hossz; i++) {
        setConsoleTo(body[i].getP_x(), body[i].getP_y());   //setConsoleTo-val megmondjuk hova kell kiírni a testrészeket
        body[i].Draw();         //itt kirajzoljuk
    }
}

void Snake::Megnott(int meret) {            //elösször eltároljuk az utolsó elem koordinátáit
    elozo_x_poz = body[hossz - 1].getP_x();
    elozo_y_poz = body[hossz - 1].getP_y();
    mozgas();                               //majd mozgatjuk a kígyót
    if (hossz < meret * meret) {            //és hozzáadjuk az új testrészt, az õt megelõzõ régi koordinátáival
        body[hossz] = Pont(elozo_x_poz, elozo_y_poz);
        hossz++;
    }
}

int Snake::getHossz() const{
    return hossz;
}

Pont* Snake::getBody() const {
    return body;
}

bool Snake::utkozott(int meretX, int meretY) const {
    if (body[0].getP_x() < 0 || body[0].getP_x() >= meretX || body[0].getP_y() < 0 || body[0].getP_y() >= meretY) { //megnézzük hogy kiment e a pályáról
        return true;
    }
    for (int i = 1; i < hossz; i++){
        if (body[0].getP_x() == body[i].getP_x() && body[0].getP_y() == body[i].getP_y()) //megnézzük minden testrészre hogy bele ment e önmagába
            return true;
    }
    return false;
}

Snake::~Snake() {
    delete[] body;
}
