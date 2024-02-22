#include "store.h"
#include "../uvsimulator.h"

/*
 * Executes the store operation.

 * This method stores a value from the accumulator of the UVSimulator into a specific memory location.
 * param: simulator A reference to the UVSimulator instance on which to perform the store operation.
 * param: operand The memory location where the value will be stored.
 * pre: The operand must be a valid index within the bounds of the UVSimulator's memory.
 * post: The value in the accumulator of the UVSimulator is stored at the specified memory location.
 */
void Store::execute(UVSimulator& simulator, int operand) {
    simulator.setMemory(operand, simulator.getAccumulator()); // param1 = location, param2 value
}
