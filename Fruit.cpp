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
            x = x + x % 2;  //Ha nem valami 2-vel oszthat� sz�m lenne, azz� kell tenni, hogy r�ker�lj�n az oszlopokra, ahol a k�gy� mozog
        y = std::rand() % meret;
        if (x != snake.getBody()[0].getP_x() || y != snake.getBody()[0].getP_y()) { //Megn�zz�k, hogy ne legyen a fruit azonos se a k�gy� fej�vel, se a test�vel
            validPosition = true;
        }
    }
}

void Fruit::generateFruit(int meret, const Snake& snake) {
    bool validPosition = false;
    while (!validPosition) {
        x = std::rand() % meret;
        if (x < meret)
            x = x + x % 2; //Az x tengelyen l�v� kimenet csak minden 2. sorban j�
        y = std::rand() % meret;

        validPosition = true;
        for (int i = 0; i < snake.getHossz(); i++) {
            if (x == snake.getBody()[i].getP_x() && y == snake.getBody()[i].getP_y()) { //Megn�zz�k, hogy ne legyen a fruit azonos se a k�gy� fej�vel, se a test�vel
                validPosition = false;
                break;
            }
        }
    }
}

void Fruit::fruit_kiir() const {
    setConsoleTo(x, y);             //x, y koordin�t�ra �rjuk ki a fruitot
    std::cout << "#";
}

int Fruit::getX() const {
    return x;
}
int Fruit::getY() const {
    return y;
}
