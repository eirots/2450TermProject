#ifndef branchneg_h
#define branchneg_h

#include "control.h"

/*
 * class BranchNeg
 * A class to handle the branch if negative operation in the UVSimulator.
 * This class provides the functionality to change the program counter to a
 specific memory location if the value in the accumulator is negative.
 */
class BranchNeg : public Control {

public:
  void BRANCHNEG();
  void execute(UVSimulator &simulator, int operand) override;
};
#endif // branchneg_h
