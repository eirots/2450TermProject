#include "subtract.h"

#include "../uvsimulator.h"
Subtract::Subtract() {}


/*
 * Executes the subtract operation.
 *
 * This method subtracts a value from a specific memory location from the value in the accumulator.
 *
 * param: simulator, A reference to the UVSimulator instance on which to perform the subtract operation, and  
   operand, The memory location from which to get the value to be subtracted.
 * pre: The operand must be a valid index within the bounds of the memory.
 * post: The value in the accumulator is decreased by the value at the specified memory location.
 */
void Subtract::execute(UVSimulator &simulator, int operand) {
    int accum = simulator.getAccumulator();
    std::string memVal = simulator.getMemory(operand);
    int result = accum - std::stoi(memVal);  // Grab accumulator value
    simulator.setAccumulator(result);        // Set accumulator to a value - value in memory
}
