class UVSimulator;  // forward declaration to avoid cyclical declarations

#ifndef branch_h
#define branch_h
#include "../uvsimulator.h"

class Branch {
   public:
    void BRANCH();
    void execute(UVSimulator &simulator, int operand);
};

#endif  // branch_h