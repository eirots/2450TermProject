#include "read.h"

#include <iostream>

#include "../uvsimulator.h"

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
