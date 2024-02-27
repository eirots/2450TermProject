class UVSimulator;  // forward declaration to avoid cyclical declarations

#ifndef WRITE_H
#define WRITE_H
#include "io.h"

const int MEMORY_SIZE = 100;  // Define the size of the memory array

extern int memory[MEMORY_SIZE];

/*
 * class Write
 * A class to handle the write operation.
 *
 * This class provides the functionality to write the value from the accumulator to a specific memory location 
   and then print it to the console.
 */
class Write : public IO {
   public:
    void execute(UVSimulator& simulator, int operand) override;
};

#endif
