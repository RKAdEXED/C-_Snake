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
        body[i].setXY(body[i-1].getP_x(),body[i-1].getP_y()); //H�tulr�l el�re a testr�szeknek �tadjuk az el�tt�k l�v� coordin�t�j�t
    }
    switch (dir[0]) {         //itt a legels� elemet, a fejet mozgatjuk
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

//A konzolt be�ll�tja x, y koordin�t�kra
void setConsoleTo(int x, int y) {  //Alapb�l ez volt �s eg�sz j�l futott, de ehez kell windows.h
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
        setConsoleTo(body[i].getP_x(), body[i].getP_y());   //setConsoleTo-val megmondjuk hova kell ki�rni a testr�szeket
        body[i].Draw();         //itt kirajzoljuk
    }
}

void Snake::Megnott(int meret) {            //el�ssz�r elt�roljuk az utols� elem koordin�t�it
    elozo_x_poz = body[hossz - 1].getP_x();
    elozo_y_poz = body[hossz - 1].getP_y();
    mozgas();                               //majd mozgatjuk a k�gy�t
    if (hossz < meret * meret) {            //�s hozz�adjuk az �j testr�szt, az �t megel�z� r�gi koordin�t�ival
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
    if (body[0].getP_x() < 0 || body[0].getP_x() >= meretX || body[0].getP_y() < 0 || body[0].getP_y() >= meretY) { //megn�zz�k hogy kiment e a p�ly�r�l
        return true;
    }
    for (int i = 1; i < hossz; i++){
        if (body[0].getP_x() == body[i].getP_x() && body[0].getP_y() == body[i].getP_y()) //megn�zz�k minden testr�szre hogy bele ment e �nmag�ba
            return true;
    }
    return false;
}

Snake::~Snake() {
    delete[] body;
}
