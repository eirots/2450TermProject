#include "multiply.h"

#include "../uvsimulator.h"
Multiply::Multiply() {}

/*
 * Executes the multiply operation.
 
 * This method multiplies a value from a specific memory location with the value in the accumulator.
 * param: sim A reference to the UVSimulator instance on which to perform the multiply operation.
 * param: operand The memory location from which to get the value to be multiplied.
 * pre: The operand must be a valid index within the bounds of the memory.
 * post: The value in the accumulator  is multiplied by the value at the specified memory location.
 */
void 
void Multiply::execute(UVSimulator& sim, int operand) {
    int product = sim.getAccumulator();
    product *= sim.getMemory(operand);
    sim.setAccumulator(product);
}
