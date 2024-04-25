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
    int holder = simulator.getAccumulator();
    std::string val;
    if (holder >= 0) {
        val = "+" + std::to_string(holder); //Add "+" if value is positive
    }
    else {
        val = std::to_string(holder);   //If value is negative, to_string will keep "-"
    }
    simulator.setMemory(operand, val); // param1 = location, param2 value
}
