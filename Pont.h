#ifndef PONT_H
#define PONT_H

class Pont {
private:
    int x, y;

public:
    Pont(int x = -1, int y = -1);
    void setXY(int uj_x, int uj_y);
    int getP_x() const;
    int getP_y() const;
    void DirW();
    void DirS();
    void DirD();
    void DirA();
    void Draw() const;
};

#endif
