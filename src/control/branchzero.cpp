#include "branchzero.h"

void BranchZero::BRANCHZERO() {
}

void BranchZero::execute(UVSimulator& simulator, int operand) {
    if (simulator.getAccumulator() == 0) {
        simulator.setPC(operand);
    } else {
        // do nothing if acc isn't 0.
    }
}
