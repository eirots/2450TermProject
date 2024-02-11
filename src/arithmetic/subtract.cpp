#include "subtract.h"
#include "../uvsimulator.h"

void Subtract::execute(UVSimulator& simulator, int operand) {
    int accum = simulator.getAccumulator(); // Grab accumulator value
    simulator.setAccumulator((accum -= simulator.getMemory(operand))); // Set accumulator to a value - value in memory
}