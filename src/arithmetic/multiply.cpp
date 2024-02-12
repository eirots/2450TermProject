#include "multiply.h"

#include "../uvsimulator.h"
Multiply::Multiply() {}

void Multiply::execute(UVSimulator& sim, int operand) {
    int product = sim.getAccumulator();
    product *= sim.getMemory(operand);
    sim.setAccumulator(product);
}
