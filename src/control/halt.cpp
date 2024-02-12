#include "halt.h"

void Halt::HALT() {}

void Halt::execute(UVSimulator &simulator) {
    simulator.setPC(-1);
}