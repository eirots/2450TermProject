#include "../uvsimulator.h"

class uvsimulator;  // forward declaration to avoid cyclical declarations

class BranchZero {
   public:
    void BRANCHZERO();
    void execute(UVSimulator &simulator, int operand);
};