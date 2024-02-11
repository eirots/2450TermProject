#include "uvsimulator.h"

class uvsimulator;  // forward declaration to avoid cyclical declarations

class BranchNeg {
   public:
    void BRANCHNEG();
    void execute(UVSimulator &simulator, int operand);
};
