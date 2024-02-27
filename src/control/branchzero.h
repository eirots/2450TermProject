#ifndef branchzero_h
#define branchzero_h

#include "../uvsimulator.h"
#include "control.h"

class UVSimulator;  // forward declaration to avoid cyclical declarations

class BranchZero : public Control {
   public:
    void BRANCHZERO();
    void execute(UVSimulator &simulator, int operand) override;
};
#endif  // branchzero_h