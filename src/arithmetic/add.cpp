#include "add.h"

#include "../uvsimulator.h"

Add::Add() {}

void Add::execute(UVSimulator& simulator, int operand) {
    int holder = simulator.getAccumulator();
    holder += simulator.getMemory(operand);
    simulator.setAccumulator(holder);
}
