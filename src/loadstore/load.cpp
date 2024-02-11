#include "load.h"
#include "../uvsimulator.h"

void Load::execute(UVSimulator& simulator, int operand) {
    simulator.setAccumulator(simulator.getMemory(operand));
}
