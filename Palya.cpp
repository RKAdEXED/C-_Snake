#include "Palya.h"
#include <conio.h>
#include <cstdlib>
#include <limits>
/*
// Függvény nézi hogy meg volt e nyomva valami billentyű
bool isKeyPressed() {
    return std::cin.peek() != EOF;
}

// Fügvény olvassa a megnyomott billentyűt

char readKeyInput() {
    char keyInput;
    std::cin >> keyInput;
    // Csak a karaktert veszi be
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return keyInput;
}*/


Palya::Palya(int meret)
    : snake(meret), fruit(meret, snake), x_meret(2 * meret), meret(meret) {} //X tengelyen, hogy szép legyen a pálya... és nekem az élet, megduplázzuk az x-et

void Palya::kiir() {
    for (int i = 0; i < meret; i++) {
        for (int j = 0; j < meret; j++) {
            std::cout << ". ";
        }
        std::cout << std::endl;
    }
}

void Palya::Game() {
    using namespace std;
    char direction = 'l';
    bool Megnott_e = false;
    do {/*
        if (isKeyPressed()) {
            // Replace getch() with readKeyInput()
            direction = readKeyInput();
        }*/
        system("cls");      //Törlünk a konzoltól mindent
        if (snake.getBody()[0].getP_x() == fruit.getX() && snake.getBody()[0].getP_y() == fruit.getY()) { //Megnézzük van e ütközés
            Megnott_e = true;
            fruit.generateFruit(meret, snake); //Új Fruitot generálunk
        }
        if (kbhit()) {      //Hallgatózik a program hogy volt e billentyű lenyomva, ha nem akkor nem válltoztat op-n;
            direction = getch();   //Karaktert berakja op-ba
        }
        kiir();                 //kiirjuk a pályát
        fruit.fruit_kiir();     //pályára a gyümölcsöt
        snake.snake_kiir();     //és a kígyót
        switch (direction) {    //Az irányt ebben a switchben adjuk át a kígyónak
            case 'w':
                snake.change_dir("w");
                break;
            case 's':
                snake.change_dir("s");
                break;
            case 'a':
                snake.change_dir("a");
                break;
            case 'd':
                snake.change_dir("d");
                break;
        }
        this_thread::sleep_for(chrono::milliseconds(100)); //Várakoznuk, hogy ne repüljünk le a mapról
        if (Megnott_e) {            //Ha volt ütközés almával
            snake.Megnott(meret);   //Akkor a kígyónk megnõ
            Megnott_e = false;
        } else {
            snake.mozgas();         //Különben csak mozgunk
        }
    } while (!(snake.utkozott(x_meret, meret)));    //Ez addig megy amíg a kígyónk valamivel nem ütközött
}
