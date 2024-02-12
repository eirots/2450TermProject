#include "write.h"
#include "../uvsimulator.h"
#include <iostream>
#include <stdexcept>

int memory[MEMORY_SIZE];  // Define the memory array

void Write::execute(UVSimulator& simulator, int operand) {
    if (location >= 0 && location < MEMORY_SIZE) {
        memory[location] = value;
        std::cout << "Value " << value << " written at location " << location << std::endl;
    } else {
        throw std::out_of_range("Memory location out of range");
    }
}
