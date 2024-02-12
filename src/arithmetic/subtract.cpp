#include "subtract.h"

#include "../uvsimulator.h"
Subtract::Subtract() {}

void Subtract::execute(UVSimulator &simulator, int operand) {
    int accum = simulator.getAccumulator();
    int result = accum - simulator.getMemory(operand);  // Grab accumulator value
    simulator.setAccumulator(result);                   // Set accumulator to a value - value in memory
}