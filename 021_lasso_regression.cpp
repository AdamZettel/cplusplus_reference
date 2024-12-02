#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <numeric>

class LassoRegression {
private:
    std::vector<double> W; // Weights
    double b;              // Bias term
    double learning_rate;
    int iterations;
    double l1_penalty;

    size_t m; // Number of training examples
    size_t n; // Number of features

    std::vector<std::vector<double>> X_train;
    std::vector<double> Y_train;

public:
    // Constructor
    LassoRegression(double learning_rate, int iterations, double l1_penalty)
        : learning_rate(learning_rate), iterations(iterations), l1_penalty(l1_penalty), b(0) {}

    // Fit function for training the model
    void fit(const std::vector<std::vector<double>>& X, const std::vector<double>& Y) {
        m = X.size();
        if (m == 0) throw std::invalid_argument("Training data is empty.");
        n = X[0].size();
        W = std::vector<double>(n, 0); // Initialize weights
        b = 0;

        X_train = X;
        Y_train = Y;

        // Gradient descent loop
        for (int i = 0; i < iterations; ++i) {
            updateWeights();
        }
    }

    // Predict function
    std::vector<double> predict(const std::vector<std::vector<double>>& X) {
        std::vector<double> Y_pred(X.size(), 0);
        for (size_t i = 0; i < X.size(); ++i) {
            Y_pred[i] = dotProduct(X[i], W) + b;
        }
        return Y_pred;
    }

private:
    // Update weights using gradient descent
    void updateWeights() {
        std::vector<double> Y_pred = predict(X_train);

        std::vector<double> dW(n, 0);
        for (size_t j = 0; j < n; ++j) {
            double gradient = 0;
            for (size_t i = 0; i < m; ++i) {
                gradient += (Y_train[i] - Y_pred[i]) * X_train[i][j];
            }
            dW[j] = -2 * gradient / m + (W[j] > 0 ? l1_penalty : -l1_penalty);
        }

        double db = 0;
        for (size_t i = 0; i < m; ++i) {
            db += (Y_train[i] - Y_pred[i]);
        }
        db = -2 * db / m;

        // Update weights and bias
        for (size_t j = 0; j < n; ++j) {
            W[j] -= learning_rate * dW[j];
        }
        b -= learning_rate * db;
    }

    // Helper function to calculate dot product of two vectors
    double dotProduct(const std::vector<double>& vec1, const std::vector<double>& vec2) {
        double result = 0;
        for (size_t i = 0; i < vec1.size(); ++i) {
            result += vec1[i] * vec2[i];
        }
        return result;
    }
};

int main() {
    // Example dataset
    std::vector<std::vector<double>> X = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5}
    };
    std::vector<double> Y = {5, 7, 9, 11};

    // Create and train the model
    LassoRegression model(0.01, 1000, 0.1);
    model.fit(X, Y);

    // Predict on training data
    std::vector<double> predictions = model.predict(X);

    // Display predictions
    std::cout << "Predictions:\n";
    for (double pred : predictions) {
        std::cout << pred << " ";
    }
    std::cout << std::endl;

    return 0;
}
