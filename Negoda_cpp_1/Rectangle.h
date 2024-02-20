#pragma once

enum corners {
    LeftUp,
    RightDown
};

class Rectangle {
    int* cornerLU;
    int* cornerRD;
    
public:
    Rectangle(int* cornerLU, int* cornerRD);
    void setCorner(corners corner, int* cords);
    int* getCorner(corners corner);
    int area();
    int perimeter();
};


