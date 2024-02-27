#include "divide.h"

#include "../uvsimulator.h"
#include "arithmetic.h"
// but the sign of a data word may be either plus or minus
Divide::Divide() {}
/*
 * Executes the divide operation.

 * This method divides the value in the accumulator by a value from a specific memory location.
   If the divisor is zero, it throws an exception.
 * param: sim, A reference to the UVSimulator instance on which to perform the divide operation, and operand
   the memory location from which to get the divisor.
 * param: operand The memory location from which to get the divisor.
 * pre: The operand must be a valid index within the bounds of the UVSimulator's memory. The value at the memory location
   must not be zero.
 * post: The value in the accumulator is divided by the value at the specified memory location.
   If the divisor is zero, an exception is thrown.
 */
void Divide::execute(UVSimulator& sim, int operand) {
    int result;
    int divisor = sim.getMemory(operand);
    if (divisor != 0) {
        int holder = sim.getAccumulator();
        holder /= sim.getMemory(operand);
        sim.setAccumulator(holder);
        // return result;
    } else {
        throw("Divide by zero not allowed");
        // need to consider how to handle 0 division issues
    }
}
