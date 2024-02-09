#include "store.h"
#include "../uvsimulator.h"

void Store::execute(UVSimulator& simulator, int operand) {
    simulator.setMemory(operand, simulator.getAccumulator()); // param1 = location, param2 value
}