#include "branchzero.h"
#include "../uvsimulator.h"

void BranchZero::BRANCHZERO() {}

/*
 * Executes the branch-if-zero operation.
 * This method changes the program counter to a specific memory location if the
 value in the accumulator is zero.
 * param: simulator A reference to the UVSimulator instance on which to perform
 the branch-if-zero operation, and operand, the memory location to which the
 program counter will be set if the value in the accumulator is zero.
 * pre The operand must be a valid index within the bounds of the UVSimulator's
 memory.
 * post: If the value in the accumulator of the UVSimulator is zero, the program
 counter of the UVSimulator is set to the specified memory location.
 */
void BranchZero::execute(UVSimulator &simulator, int operand) {
  if (simulator.getAccumulator() == 0) {
    simulator.setPC(operand);
  } else {
    // do nothing if acc isn't 0.
  }
}
