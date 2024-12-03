#include <iostream>

// Math operation policies
struct AddOperation {
    static int compute(int a, int b) {
        return a + b;
    }
};

struct MultiplyOperation {
    static int compute(int a, int b) {
        return a * b;
    }
};

// Calculator class using a policy
template <typename OperationPolicy>
class Calculator : public OperationPolicy {
public:
    static int calculate(int a, int b) {
        return OperationPolicy::compute(a, b);
    }
};

int main() {
    // Using AddOperation policy
    int sum = Calculator<AddOperation>::calculate(5, 3);
    std::cout << "Addition result: " << sum << std::endl;

    // Using MultiplyOperation policy
    int product = Calculator<MultiplyOperation>::calculate(5, 3);
    std::cout << "Multiplication result: " << product << std::endl;

    return 0;
}
