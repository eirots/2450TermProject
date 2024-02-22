#ifndef branchneg_h
#define branchneg_h
#include "../uvsimulator.h"

class UVSimulator;  // forward declaration to avoid cyclical declarations

/*
 * class BranchNeg
 * A class to handle the branch if negative operation in the UVSimulator.
 * This class provides the functionality to change the program counter to a specific memory location 
   if the value in the accumulator is negative.
 */


class BranchNeg {
   public:
    void BRANCHNEG();
    void execute(UVSimulator &simulator, int operand);
};
#endif  // branchneg_h
