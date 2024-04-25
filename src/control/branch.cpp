#include "branch.h"

#include "../uvsimulator.h"

void Branch::BRANCH() {}

/*
 * Executes the branch operation.
 * This method changes the program counter of the UVSimulator to a specific
 memory location.

 * param: simulator A reference to the UVSimulator instance on which to perform
 the branch operation, and operand, the memory location to which the program
 counter will be set.
 * pre: The operand must be a valid index within the bounds of the memory.
 * post: The program counter is set to the specified memory location.
 */
void Branch::execute(UVSimulator &simulator, int operand) {
  simulator.setPC(operand);
}
