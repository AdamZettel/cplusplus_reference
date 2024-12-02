#include <iostream>

int main() {
    int x = 10;
    int* ptr = &x;
    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Address of x: " << ptr << std::endl;
    std::cout << "Value at address: " << *ptr << std::endl;
    return 0;
}
