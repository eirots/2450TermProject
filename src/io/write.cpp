#include "write.h"

#include <iostream>
#include <stdexcept>

#include "../uvsimulator.h"

int memory[MEMORY_SIZE];  // Define the memory array


/*
 * Executes the write operation.
 * This method writes the value from a memory location and prints it to the console. 
   If the memory location is out of range, it throws an exception.
 * param: simulator, A reference to the UVSimulator instance on which to perform the write operation, and operand, The memory location 
   where it get the value to write
 * pre: The operand must be a valid index within the bounds of the memory.
 * post: The value is written from a specified memory location to the console. 
   If the memory location is out of range, an exception is thrown.
 */
void Write::execute(UVSimulator& simulator, int operand) {
    if (operand >= 0 && operand < MEMORY_SIZE) {
        int value = simulator.getMemory(operand);
        std::cout << "Value " << value << " written at location " << operand << std::endl;
    } else {
        throw std::out_of_range("Memory location out of range");
    }
}
