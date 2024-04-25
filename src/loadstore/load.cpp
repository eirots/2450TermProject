#include "load.h"
#include "../uvsimulator.h"


/*
 * Executes the load operation.
 
 * This method loads a value from a specific memory location into the accumulator of the UVSimulator.
 * param: simulator, A reference to the UVSimulator instance where the load operation will be performed,and operand the memory location from which to load the value.
 * pre: The operand must be a valid index within the bounds of the program's memory.
 * post: The accumulator of the program is set to the value at the specified memory location.
 */
void Load::execute(UVSimulator& simulator, int operand) {
    simulator.setAccumulator(std::stoi(simulator.getMemory(operand)));
}
