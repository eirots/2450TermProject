#include "branchneg.h"

void BranchNeg::BRANCHNEG() {
}

void BranchNeg::execute(UVSimulator& simulator, int operand) {
    if (simulator.getAccumulator() < 0) {
        simulator.setPC(operand);
    } else {
        // do nothing if acc isn't negative.
    }
}
