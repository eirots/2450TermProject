#ifndef branchneg_h
#define branchneg_h
#include "../uvsimulator.h"

class UVSimulator;  // forward declaration to avoid cyclical declarations

class BranchNeg {
   public:
    void BRANCHNEG();
    void execute(UVSimulator &simulator, int operand);
};
#endif  // branchneg_h