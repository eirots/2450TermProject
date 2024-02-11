#include "halt.h"

void Halt::HALT() {}

void Halt::execute(UVSimulator &simulator)
{
    int memSize = simulator.getMemSize();
    simulator.setPC(memSize);
}