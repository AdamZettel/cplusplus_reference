#include <iostream>
#include <vector>
#include <stdexcept>

// Template function to compute the mean of a vector
template <typename T>
T calculateMean(const std::vector<T>& vec) {
    T sum = 0;
    for (const T& value : vec) {
        sum += value;
    }
    return sum / vec.size();
}

// Template function to compute the covariance of two vectors
template <typename T>
T calculateCovariance(const std::vector<T>& vec1, const std::vector<T>& vec2) {
    if (vec1.size() != vec2.size()) {
        throw std::invalid_argument("Vectors must be of the same size.");
    }

    T mean1 = calculateMean(vec1);
    T mean2 = calculateMean(vec2);

    T covariance = 0;
    for (size_t i = 0; i < vec1.size(); ++i) {
        covariance += (vec1[i] - mean1) * (vec2[i] - mean2);
    }

    return covariance / vec1.size();
}

int main() {
    try {
        // Define two vectors of doubles
        std::vector<double> vec1 = {2.0, 4.0, 6.0, 8.0};
        std::vector<double> vec2 = {1.0, 3.0, 5.0, 7.0};

        // Calculate and display the covariance
        std::cout << "Covariance: " << calculateCovariance(vec1, vec2) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
