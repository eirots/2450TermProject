#ifndef branchzero_h
#define branchzero_h

#include "control.h"

class UVSimulator; // forward declaration to avoid cyclical declarations
/*
 * class BranchZero
 * A class to handle the branch-if-zero operation in the UVSimulator.
 * This class provides the functionality to change the program counter  to a
   specific memory location if the value in the accumulator is zero.
 */
class BranchZero : public Control {

public:
  void BRANCHZERO();
  void execute(UVSimulator &simulator, int operand) override;
};
#endif // branchzero_h
