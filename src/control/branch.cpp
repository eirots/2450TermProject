#include "branch.h"

void Branch::BRANCH() {
}

void Branch::execute(UVSimulator &simulator, int operand) {
    simulator.setPC(operand);
}
