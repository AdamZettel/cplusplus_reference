#include <iostream>
#include <vector>

// Function prototypes for arithmetic operations
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

// Class to handle operation with function pointers
class OperationManager {
public:
    typedef int (*Operation)(int, int);

    // Method to add an operation to the list
    void addOperation(Operation op) {
        operations.push_back(op);
    }

    // Method to execute an operation based on user choice
    int executeOperation(int a, int b, int index) {
        if (index >= 0 && index < operations.size()) {
            return operations[index](a, b);  // Call function via pointer
        } else {
            std::cout << "Invalid operation index." << std::endl;
            return -1;
        }
    }

private:
    std::vector<Operation> operations;  // List of function pointers
};

int main() {
    int a = 10, b = 5;
    int operationChoice;

    // Using if-else statements
    std::cout << "Using if-else statements:" << std::endl;
    std::cout << "Choose an operation (0: Add, 1: Subtract, 2: Multiply, 3: Divide): ";
    std::cin >> operationChoice;

    int result_if;
    if (operationChoice == 0) {
        result_if = add(a, b);
    } else if (operationChoice == 1) {
        result_if = subtract(a, b);
    } else if (operationChoice == 2) {
        result_if = multiply(a, b);
    } else if (operationChoice == 3) {
        result_if = divide(a, b);
    } else {
        std::cout << "Invalid choice in if-else." << std::endl;
        return 1;
    }

    std::cout << "Result using if-else: " << result_if << std::endl;

    // Using function pointers
    std::cout << "\nUsing function pointers:" << std::endl;
    OperationManager opManager;

    // Adding operations to the operation manager
    opManager.addOperation(add);
    opManager.addOperation(subtract);
    opManager.addOperation(multiply);
    opManager.addOperation(divide);

    std::cout << "Choose an operation (0: Add, 1: Subtract, 2: Multiply, 3: Divide): ";
    std::cin >> operationChoice;

    int result_funcPtr = opManager.executeOperation(a, b, operationChoice);

    if (result_funcPtr != -1) {
        std::cout << "Result using function pointer: " << result_funcPtr << std::endl;
    }

    return 0;
}
