#include "Funcs.h"
#include "Rectangle.h"

Rectangle::Rectangle(int* cornerLU, int* cornerRD) {
    this->cornerLU = cornerLU;
    this->cornerRD = cornerRD;
}

void Rectangle::setCorner(corners corner, int* cords) {
    if (corner == LeftUp) {
        cornerLU = cords;
    }
    else {
        cornerRD = cords;
    }
}

int* Rectangle::getCorner(corners corner) {
    if (corner == LeftUp) {
        return cornerLU;
    }
    return cornerRD;
}

int Rectangle::area() {
    return funcs::area(*cornerRD - *cornerLU, *(cornerRD + 1) - *(cornerLU + 1));
}

int Rectangle::perimeter() {
    return funcs::perimeter(*cornerRD - *cornerLU, *(cornerRD + 1) - *(cornerLU + 1));
}
