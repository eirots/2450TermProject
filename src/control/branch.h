class UVSimulator;  // forward declaration to avoid cyclical declarations

#ifndef branch_h
#define branch_h
#include "../uvsimulator.h"

/*
 * class Branch
 * A class to handle the branch operation in the UVSimulator.
 *
 * This class provides the functionality to change the program counter of the 
   UVSimulator to a specific memory location, effectively causing the program execution to "branch" to that location.
 */

class Branch {
   public:
    void BRANCH();
    void execute(UVSimulator &simulator, int operand);
};

#endif  // branch_h
