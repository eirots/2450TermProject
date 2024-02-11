#include "branch.h"

void BRANCH() {
}

void Branch::execute(UVSimulator &simulator, int operand) {
    simulator.setPC(operand);
}
