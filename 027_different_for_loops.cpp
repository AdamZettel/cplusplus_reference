#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

// Function to demonstrate traditional for loop with counting
void traditionalFor() {
    std::cout << "Traditional for loop (counting up): ";
    for (int i = 0; i < 10; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Function to demonstrate reverse for loop
void reverseFor() {
    std::cout << "Reverse for loop (counting down): ";
    for (int i = 9; i >= 0; i--) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Function to demonstrate range-based for loop
void rangeBasedFor() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Range-based for loop: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Function to demonstrate range-based for loop with reference
void rangeBasedForReference() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Range-based for loop with reference: ";
    for (int& i : vec) {
        i *= 2;  // Modify the elements in place
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Function to demonstrate for-each loop with const reference
void rangeBasedForConstReference() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Range-based for loop with const reference: ";
    for (const int& i : vec) {
        std::cout << i << " ";  // No modification
    }
    std::cout << std::endl;
}


// Function to demonstrate infinite for loop
void infiniteFor() {
    std::cout << "Infinite for loop (will run forever unless stopped): ";
    for (;;) {
        std::cout << "Looping ";
        break;  // Exit the loop immediately
    }
    std::cout << std::endl;
}

// Function to demonstrate break in for loop
void breakInFor() {
    std::cout << "For loop with break: ";
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            break;  // Exit the loop when i reaches 5
        }
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Function to demonstrate continue in for loop
void continueInFor() {
    std::cout << "For loop with continue (skip even numbers): ";
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            continue;  // Skip even numbers
        }
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Function to demonstrate nested for loops
void nestedFor() {
    std::cout << "Nested for loops: ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "(" << i << ", " << j << ") ";
        }
    }
    std::cout << std::endl;
}


// Function to demonstrate for loop with lambda (C++11+)
void lambdaFor() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "For loop with lambda: ";
    std::for_each(vec.begin(), vec.end(), [](int i) {
        std::cout << i << " ";
    });
    std::cout << std::endl;
}

// Function to demonstrate for loop with iterators
void iteratorBasedFor() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "For loop with iterators: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Function to demonstrate for loop with std::advance (iterator manipulation)

int main() {
    traditionalFor();
    reverseFor();
    rangeBasedFor();
    rangeBasedForReference();
    rangeBasedForConstReference();
    infiniteFor();
    breakInFor();
    continueInFor();
    nestedFor();
    lambdaFor();
    iteratorBasedFor();
    return 0;
}
