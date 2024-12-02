#include <iostream>
#include <vector>
#include <stdexcept>

// Template function to compute the dot product
template <typename T>
T dotProduct(const std::vector<T>& vec1, const std::vector<T>& vec2) {
    if (vec1.size() != vec2.size()) {
        throw std::invalid_argument("Vectors must be of the same size.");
    }

    T result = 0;
    for (size_t i = 0; i < vec1.size(); ++i) {
        result += vec1[i] * vec2[i];
    }

    return result;
}

int main() {
    try {
        // Define two vectors of integers
        std::vector<int> vec1 = {1, 2, 3};
        std::vector<int> vec2 = {4, 5, 6};

        // Calculate and display the dot product for integers
        std::cout << "Dot product (int): " << dotProduct(vec1, vec2) << std::endl;

        // Define two vectors of doubles
        std::vector<double> vec3 = {1.1, 2.2, 3.3};
        std::vector<double> vec4 = {4.4, 5.5, 6.6};

        // Calculate and display the dot product for doubles
        std::cout << "Dot product (double): " << dotProduct(vec3, vec4) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
