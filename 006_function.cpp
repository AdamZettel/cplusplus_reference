#include <iostream>

int add(int x, int y) {
    return x + y;
}

int main() {
    int a = 5, b = 3;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "Sum: " << add(a, b) << std::endl;
    return 0;
}
