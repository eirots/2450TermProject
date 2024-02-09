#include "uvsimulator.h"

int main() {

    UVSimulator simulator;
    std::vector<int> program = simulator.buildProgram();
    simulator.loadProgram(program);
    simulator.executeProgram();
    simulator.printMemory();

    return 0;
}