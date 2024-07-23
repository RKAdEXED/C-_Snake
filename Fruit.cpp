#include "Fruit.h"
#include "Snake.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Fruit::Fruit(int meret, const Snake& snake) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    bool validPosition = false;
    while (!validPosition) {
        x = std::rand() % meret;
        if (x < meret)
            x = x + x % 2;  //Ha nem valami 2-vel osztható szám lenne, azzá kell tenni, hogy rákerüljön az oszlopokra, ahol a kígyó mozog
        y = std::rand() % meret;
        if (x != snake.getBody()[0].getP_x() || y != snake.getBody()[0].getP_y()) { //Megnézzük, hogy ne legyen a fruit azonos se a kígyó fejével, se a testével
            validPosition = true;
        }
    }
}

void Fruit::generateFruit(int meret, const Snake& snake) {
    bool validPosition = false;
    while (!validPosition) {
        x = std::rand() % meret;
        if (x < meret)
            x = x + x % 2; //Az x tengelyen lévõ kimenet csak minden 2. sorban jó
        y = std::rand() % meret;

        validPosition = true;
        for (int i = 0; i < snake.getHossz(); i++) {
            if (x == snake.getBody()[i].getP_x() && y == snake.getBody()[i].getP_y()) { //Megnézzük, hogy ne legyen a fruit azonos se a kígyó fejével, se a testével
                validPosition = false;
                break;
            }
        }
    }
}

void Fruit::fruit_kiir() const {
    setConsoleTo(x, y);             //x, y koordinátára írjuk ki a fruitot
    std::cout << "#";
}

int Fruit::getX() const {
    return x;
}
int Fruit::getY() const {
    return y;
}
