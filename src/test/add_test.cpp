#include "../arithmetic/add.h"

#include <cassert>
#include <iostream>

/*
* Test case for the Add class
* This function tests the Add class by creating an instance of the class, calling the add method with two operands, 
   and asserting that the result is as expected.
*/
void testAdd() {
    int operand = 5;
    int operand1 = 10;
    Add adder;

    int result = adder.add(operand, operand1);

    assert(result == 15);
    assert(operand == 15);
}

/*
 * Main function.
 * This function calls the testAdd function and prints "Test passed!" to the console if no assertions failed.
 * @return 0 if the program runs successfully.
 */
int main() {
    testAdd();

    std::cout << "Test passed!" << std::endl;
    return 0;
}
