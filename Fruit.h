#ifndef FRUIT_H
#define FRUIT_H
#include "Snake.h"

void setConsoleTo(int x, int y);

class Fruit {
private:
    int x,y;

public:
    Fruit(int meret, const Snake& snake);
    void generateFruit(int meret, const Snake& snake);
    void fruit_kiir() const;
    int getX() const;
    int getY() const;
};

#endif  // FRUIT_H
