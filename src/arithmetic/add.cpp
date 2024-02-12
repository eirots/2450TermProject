#include "add.h"

Add::Add() {}

void Add::execute(UVSimulator& simulator, int operand) {
    simulator.accumulator += simulator.memory[operand];
}
