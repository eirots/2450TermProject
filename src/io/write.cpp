#include "write.h"

#include <iostream>
#include <stdexcept>

#include "../uvsimulator.h"

int memory[MEMORY_SIZE];  // Define the memory array

void Write::execute(UVSimulator& simulator, int operand) {
    if (operand >= 0 && operand < MEMORY_SIZE) {
        int value = simulator.getAccumulator();
        simulator.setMemory(operand, value);
        std::cout << "Value " << value << " written at location " << operand << std::endl;
    } else {
        throw std::out_of_range("Memory location out of range");
    }
}
