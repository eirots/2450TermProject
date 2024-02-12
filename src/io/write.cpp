#include "write.h"

#include <iostream>

extern int memory[];

void WRITE(int location, int value, int memsize) {
    if (location >= 0 && location < memsize) {
        memory[location] = value;
        std::cout << "Value " << value << "written at location " << location << std::endl;
    } else {
        throw std::out_of_range("Memory location out of range");
    }
};
