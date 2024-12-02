#include <iostream>

class Rectangle {
public:
    int length, width;

    int area() {
        return length * width;
    }
};

int main() {
    Rectangle rect;
    rect.length = 5;
    rect.width = 3;

    std::cout << "Area of rectangle: " << rect.area() << std::endl;
    return 0;
}
