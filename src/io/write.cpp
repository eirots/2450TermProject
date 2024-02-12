#include "write.h"

#include <iostream>
#include <stdexcept>

int memory[MEMORY_SIZE];  // Define the memory array

void WRITE(int location, int value) {
    if (location >= 0 && location < MEMORY_SIZE) {
        memory[location] = value;
        std::cout << "Value " << value << " written at location " << location << std::endl;
    } else {
        throw std::out_of_range("Memory location out of range");
    }
}