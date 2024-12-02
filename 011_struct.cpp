#include <iostream>

struct Point {
    int x, y;
};

int main() {
    Point p1 = {3, 4};
    std::cout << "Point coordinates: (" << p1.x << ", " << p1.y << ")" << std::endl;
    return 0;
}
