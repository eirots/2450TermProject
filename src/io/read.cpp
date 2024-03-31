#include "read.h"

#include <iostream>

#include "../uvsimulator.h"

/*
 * Executes the read operation.
 * This method reads an integer from the user and stores it in a specific memory location. 
   If the memory location is out of range, it throws an exception.
 * param: simulator, A reference to the UVSimulator instance on which to perform the read operation, and operand, 
   The memory location where the user's input will be stored.
 * pre: The operand must be a valid index within the bounds of the memory.
 * post: The user's input is read and stored at the specified memory location. If the memory location 
   is out of range, an exception is thrown.
 */
void Read::execute(UVSimulator& simulator, int operand) {
    if (operand >= 0 && operand < simulator.getMemSize()) {
        int input;
        std::cout << "Enter input value: ";
        std::cin >> input;
        simulator.setMemory(operand, input);
    } else {
        throw std::out_of_range("Memory location out of range");
    }
}
