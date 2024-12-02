#include <iostream>

// Redundant functions for different types
int findMax(int a, int b) {
    return (a > b) ? a : b;
}

double findMax(double a, double b) {
    return (a > b) ? a : b;
}

char findMax(char a, char b) {
    return (a > b) ? a : b;
}

// Template function for all types
template <typename T>
T findMaxTemplate(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Using redundant functions
    std::cout << "Redundant Functions:\n";
    std::cout << "Max of 10 and 20 (int): " << findMax(10, 20) << std::endl;
    std::cout << "Max of 15.5 and 12.3 (double): " << findMax(15.5, 12.3) << std::endl;
    std::cout << "Max of 'a' and 'z' (char): " << findMax('a', 'z') << std::endl;

    // Using the template function
    std::cout << "\nTemplate Function:\n";
    std::cout << "Max of 10 and 20 (int): " << findMaxTemplate(10, 20) << std::endl;
    std::cout << "Max of 15.5 and 12.3 (double): " << findMaxTemplate(15.5, 12.3) << std::endl;
    std::cout << "Max of 'a' and 'z' (char): " << findMaxTemplate('a', 'z') << std::endl;

    return 0;
}
