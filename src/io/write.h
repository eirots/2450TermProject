class UVSimulator;  // forward declaration to avoid cyclical declarations

#ifndef WRITE_H
#define WRITE_H
#include "io.h"

const int MEMORY_SIZE = 100;  // Define the size of the memory array

extern int memory[MEMORY_SIZE];

class Write : public IO {
   public:
    void execute(UVSimulator& simulator, int operand) override;
};

#endif
