#include "add.h"
#include "../uvsimulator.h"

Add::Add() {}

void Add::execute(UVSimulator& simulator, int operand) {
    simulator.accumulator += simulator.memory[operand];
}
