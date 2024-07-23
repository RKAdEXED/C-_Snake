#include <iostream>
#include "time.h"
#include <conio.h>
#include <chrono>
#include <thread>
#include "Palya.h"
#include "gtest_lite.h"
#include "Snake.h"

using namespace std;

int main() {
    //Teszteljük hogy Paraméter nélkül hívható ctor nem rakja e a fruitot a snakere

    TEST(FruitTest, DefaultCTor) {
    do {
        Snake snake(10);
        Fruit fruit(10, snake);
        if (snake.getBody()[0].getP_x() == fruit.getX())
            EXPECT_NE(snake.getBody()[0].getP_y(), fruit.getY());
        else{
            if (snake.getBody()[0].getP_y() == fruit.getY()){
                EXPECT_NE(snake.getBody()[0].getP_x(), fruit.getX());
            }
            else{
                EXPECT_NE(snake.getBody()[0].getP_y(), fruit.getY());
                EXPECT_NE(snake.getBody()[0].getP_x(), fruit.getX());
            }
            }
        } while (false);
    }END;

    //Teszteljük hogy a generált alma a kígyóra került e

    TEST(FruitTest, GenerateFruit) {
        do {
            Snake snake(10);
            snake.getBody()[0].setXY(5, 5);
            Fruit fruit(10, snake);
            fruit.generateFruit(10, snake);

            EXPECT_NE(snake.getBody()[0].getP_x(), fruit.getX());
            EXPECT_NE(snake.getBody()[0].getP_y(), fruit.getY());
        } while (false);
    }END;

    //Teszteljük az irányváltás helyes megoldását

    TEST(Snake_Test, ChangeDir)
        {
        do {
            Snake snake(10);
            EXPECT_STREQ("d", snake.getDir());

            snake.change_dir("w");
            EXPECT_STREQ("w", snake.getDir());

            snake.change_dir("a");
            EXPECT_STREQ("a", snake.getDir());

            snake.change_dir("s");
            EXPECT_STREQ("s", snake.getDir());

            snake.change_dir("d");
            EXPECT_STREQ("d", snake.getDir());
        } while (false);
    } END;

    //Mozgás tesztelése

    TEST(Snake_Test, Move)
    {
        do {
            Snake snake(10);

            // Mozgás Fel
            snake.change_dir("w");
            snake.mozgas();
            EXPECT_EQ(6, snake.getBody()[0].getP_x());
            EXPECT_EQ(4, snake.getBody()[0].getP_y());

            // Mozgás Balra
            snake.change_dir("a");
            snake.mozgas();
            EXPECT_EQ(4, snake.getBody()[0].getP_x());
            EXPECT_EQ(4, snake.getBody()[0].getP_y());

            // Mozgás Le
            snake.change_dir("s");
            snake.mozgas();
            EXPECT_EQ(4, snake.getBody()[0].getP_x());
            EXPECT_EQ(5, snake.getBody()[0].getP_y());

            // Mozgás jobbra
            snake.change_dir("d");
            snake.mozgas();
            EXPECT_EQ(6, snake.getBody()[0].getP_x());
            EXPECT_EQ(5, snake.getBody()[0].getP_y());
        } while (false);
    } END;

    // Jatek logika

    bool game = true;
    while (game)
    {
        system("cls"); //Töröl mindent a konzolról
        cout << "1. Play" << endl;
        cout << "2. Quit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                game = true;
                int mapSize;
                cout << "Enter map size: ";
                cin >> mapSize;
                if (mapSize > 20) {
                    cout << "Map size cannot exceed 20. Setting map size to 20." << endl;
                    mapSize = 20;
                }
                Palya Kigyo_Jatek(mapSize);  //Létrehozzuk a pályát, benne a fruitot és a snaket
                Kigyo_Jatek.Game();          //Elindul a játék
                break;
            }
            case 2:
                return 0;
            default:                        //Ha rossz input, azt nem fogadja el, nem megy tovább
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
                return 0;
        }
    }

    return 0;
}
