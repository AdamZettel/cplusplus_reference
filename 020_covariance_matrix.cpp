#include <iostream>
#include <vector>
#include <iomanip> // For formatting output
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

// Template function to compute the covariance between two vectors
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

// Template function to compute the covariance matrix
template <typename T>
std::vector<std::vector<T>> calculateCovarianceMatrix(const std::vector<std::vector<T>>& data) {
    size_t numVectors = data.size();
    if (numVectors == 0) {
        throw std::invalid_argument("Data set must not be empty.");
    }

    size_t vectorSize = data[0].size();
    for (const auto& vec : data) {
        if (vec.size() != vectorSize) {
            throw std::invalid_argument("All vectors must have the same size.");
        }
    }

    // Initialize the covariance matrix
    std::vector<std::vector<T>> covarianceMatrix(numVectors, std::vector<T>(numVectors, 0));

    // Compute pairwise covariances
    for (size_t i = 0; i < numVectors; ++i) {
        for (size_t j = i; j < numVectors; ++j) {
            T covariance = calculateCovariance(data[i], data[j]);
            covarianceMatrix[i][j] = covariance;
            covarianceMatrix[j][i] = covariance; // Symmetric matrix
        }
    }

    return covarianceMatrix;
}

int main() {
    try {
        // Example data set: Each inner vector represents a variable (column in a dataset)
        std::vector<std::vector<double>> data = {
            {2.0, 4.0, 6.0, 8.0}, // Variable 1
            {1.0, 3.0, 5.0, 7.0}, // Variable 2
            {10.0, 20.0, 30.0, 40.0} // Variable 3
        };

        // Calculate the covariance matrix
        std::vector<std::vector<double>> covarianceMatrix = calculateCovarianceMatrix(data);

        // Display the covariance matrix
        std::cout << "Covariance Matrix:\n";
        for (const auto& row : covarianceMatrix) {
            for (double value : row) {
                std::cout << std::setw(10) << value << " ";
            }
            std::cout << "\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
