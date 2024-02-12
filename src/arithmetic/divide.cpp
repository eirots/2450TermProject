#include "divide.h"

#include "../uvsimulator.h"
// but the sign of a data word may be either plus or minus
Divide::Divide() {}
// Divide the word in the accumulator by a word from a specific location in memory (leave the result in the accumulator).
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