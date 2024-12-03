#include <iostream>

// Function prototypes for operations
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int main() {
    int a = 10, b = 5;
    char operation = '*';  // User selects the operation

    // Using an if-else statement
    int result_if;
    if (operation == '+') {
        result_if = a + b;
    } else if (operation == '-') {
        result_if = a - b;
    } else if (operation == '*') {
        result_if = a * b;
    } else if (operation == '/') {
        result_if = a / b;
    } else {
        std::cout << "Invalid operation in if statement." << std::endl;
        return 1;
    }

    std::cout << "Result using if statement: " << result_if << std::endl;

    // Using function pointers
    int (*operationFunc)(int, int);

    // Assign the correct function to the pointer based on the operation
    switch (operation) {
        case '+':
            operationFunc = add;
            break;
        case '-':
            operationFunc = subtract;
            break;
        case '*':
            operationFunc = multiply;
            break;
        case '/':
            operationFunc = divide;
            break;
        default:
            std::cout << "Invalid operation in function pointers." << std::endl;
            return 1;
    }

    // Use the function pointer to call the appropriate function
    int result_funcPtr = operationFunc(a, b);
    std::cout << "Result using function pointer: " << result_funcPtr << std::endl;

    return 0;
}
