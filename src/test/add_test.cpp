#include "../arithmetic/add.h"

#include <cassert>
#include <iostream>

// Test case for the Add class
void testAdd() {
    int operand = 5;
    int operand1 = 10;
    Add adder;

    int result = adder.add(operand, operand1);

    assert(result == 15);
    assert(operand == 15);
}

int main() {
    testAdd();

    std::cout << "Test passed!" << std::endl;
    return 0;
}
