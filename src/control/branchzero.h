#ifndef branchzero_h
#define branchzero_h

#include "../uvsimulator.h"

class UVSimulator;  // forward declaration to avoid cyclical declarations

class BranchZero {
   public:
    void BRANCHZERO();
    void execute(UVSimulator &simulator, int operand);
};
#endif  // branchzero_h