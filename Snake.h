#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include <string.h>
#include <time.h>
#include "Pont.h"

class Snake {
private:
    Pont* body;
    int elozo_x_poz;
    int elozo_y_poz;
    int hossz = 1;
    const char* dir;
    bool utkozott_e = false;
public:
    Snake(int meret = 50);
    bool utkozott(int meretX, int meretY) const;
    const char* getDir() const;
    int getHossz() const;
    void change_dir(const char* is);
    void mozgas();
    void Megnott(int meret);
    void snake_kiir();
    Pont* getBody() const;
    ~Snake();
};

#endif  // SNAKE_H
