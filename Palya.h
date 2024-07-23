#ifndef PALYA_H
#define PALYA_H

#include "Snake.h"
#include "Fruit.h"
#include <chrono>
#include <thread>
#include <iostream>

class Palya {
private:
    Snake snake;
    Fruit fruit;
    int x_meret;
    int meret;

public:
    Palya(int meret = 10);
    void kiir();
    void Game();
};

#endif
