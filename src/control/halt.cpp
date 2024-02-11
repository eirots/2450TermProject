#include "halt.h"

void Halt::HALT() {
}

void Halt::execute(UVSimulator& simulator) {
    int memsize = simulator.getMemSize();
    simulator.setPC(memsize);
}