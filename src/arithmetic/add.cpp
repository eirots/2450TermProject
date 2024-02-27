#include "add.h"

#include "../uvsimulator.h"

Add::Add() {}

/*
 * Executes the add operation.
 * This method adds a value from a specific memory location to the accumulator of the UVSimulator.

 * param: simulator, a reference to the UVSimulator instance on which to perform the add operation.
 * param: operand, the memory location from which to get the value to be added.
 * pre: The operand must be a valid index within the bounds of the UVSimulator's memory.
 * post: The value in the accumulator of the UVSimulator is increased by the value at the specified memory location.
 */
void Add::execute(UVSimulator& simulator, int operand) {
    int holder = simulator.getAccumulator();
    holder += simulator.getMemory(operand);
    simulator.setAccumulator(holder);
}
