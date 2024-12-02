#include <iostream>

int main() {
    int i = 1;
    int max_count = 5;

    std::cout << "Max Count: " << max_count << std::endl;
    while (i <= 5) {
        std::cout << "Count: " << i << std::endl;
        ++i;
    }
    return 0;
}
