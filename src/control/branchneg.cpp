#include "branchneg.h"

void BranchNeg::BRANCHNEG() {
}

/*
 * Executes the branch-if-negative operation.
 * This method changes the program counter to a specific memory location if the value in the accumulator is negative.
 * param: simulator, a reference to the UVSimulator instance on which to perform the branch-if-negative operation, and operand The memory 
   location to which the program counter will be set if the value in the accumulator is negative.
 * pre: The operand must be a valid index within the bounds of the UVSimulator's memory.
 * post: If the value in the accumulator of the UVSimulator is negative, the program counter is set to the specified memory location.
 */
void BranchNeg::execute(UVSimulator& simulator, int operand) {
    if (simulator.getAccumulator() < 0) {
        simulator.setPC(operand);
    } else {
        // do nothing if acc isn't negative.
    }
}
