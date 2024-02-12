#include <cassert>
#include <iostream>
#include <string>

#include "../arithmetic/add.h"
#include "../arithmetic/divide.h"
#include "../arithmetic/multiply.h"
#include "../arithmetic/subtract.h"
#include "../control/branch.h"
#include "../control/branchneg.h"
#include "../control/branchzero.h"
#include "../control/halt.h"
#include "../io/read.h"
#include "../io/write.h"
#include "../loadstore/load.h"
#include "../loadstore/store.h"
#include "../uvsimulator.h"
#include "io_test.cpp"

// common debug macro included below
#define ASSERT(condition)                                                                                              \
    {                                                                                                                  \
        if (!(condition)) {                                                                                            \
            std::cerr << "ASSERT FAILED: " << #condition << " @ " << __FILE__ << " (" << __LINE__ << ")" << std::endl; \
        }                                                                                                              \
    }

// used for knowing if a test passed
void spitline(std::string lineToPrint) {
    std::cout << lineToPrint << std::endl;
}

// START OF ARITHMETIC TESTS
void testAdd() {
    Add adder;
    UVSimulator simulator;
    int operand = 5;

    simulator.setAccumulator(5);
    simulator.setMemory(0, 5);

    adder.execute(simulator, operand);
    assert(simulator.getAccumulator() == 15);
    spitline("\tadd passed");
}
void testSubtract() {
    UVSimulator simulator;
    simulator.setAccumulator(10);
    simulator.setMemory(0, 5);
    int operand = 0;

    Subtract subtract;
    subtract.execute(simulator, operand);

    assert(simulator.getAccumulator() == 5);
    spitline("\tsubtract passed");
}
void testMultiply() {
    UVSimulator sim;
    Multiply multiplier;

    sim.setAccumulator(5);
    sim.setMemory(0, 5);
    int operand = 2;

    multiplier.execute(sim, operand);

    assert(sim.getAccumulator() == 10);

    spitline("\tmultiply passed");
}
void testDivide() {
    UVSimulator sim;
    Divide div;

    sim.setAccumulator(20);
    sim.setMemory(0, 5);
    int operand = 5;

    div.execute(sim, operand);

    assert(sim.getAccumulator() == 4);
    spitline("\tdivide passed");
}
void testDivideByZero() {
    UVSimulator sim;
    Divide divider;

    sim.setAccumulator(20);
    sim.setMemory(0, 5);

    int divisor = 0;

    try {
        divider.execute(sim, divisor);
        assert(false);
    } catch (const char *error) {
        assert(std::string(error) == "Divide by zero not allowed");
    }
    assert(sim.getAccumulator() == 20);
    spitline("\tdividebyzero passed");
}
// END OF ARITHMATIC TESTS

// CONTROL TESTS

void testBranch() {
    UVSimulator simulator;
    int operand = 5;

    Branch branch;
    branch.execute(simulator, operand);

    assert(simulator.getPC() == operand);
    spitline("\tbranch passed");
}
void testBranchNeg() {
    UVSimulator simulator;
    int operand = 5;
    simulator.setAccumulator(-1);

    BranchNeg branchNeg;
    branchNeg.execute(simulator, operand);

    assert(simulator.getPC() == operand);
    spitline("\tbranch negative passed");
}
void testBranchZero() {
    UVSimulator simulator;
    int operand = 5;
    simulator.setAccumulator(0);

    BranchZero branchZero;
    branchZero.execute(simulator, operand);

    assert(simulator.getPC() == operand);
    spitline("\tbranch zero passed");
}
void testHalt() {
    UVSimulator simulator;
    int memSize = 100;
    simulator.setPC(5);

    Halt halt;
    halt.execute(simulator);
    // std::cout << simulator.getPC() << std::endl;

    assert(simulator.getPC() < 0);
    spitline("\thalt passed");
}

// I/O TESTS ARE IN ANOTHER FILE//

// START OF LOAD/STORE TESTS
//  Define a test function for Load
void testLoad() {
    UVSimulator simulator;
    int operand = 10;

    Load load;
    load.execute(simulator, operand);

    assert(simulator.getAccumulator() == simulator.getMemory(operand));
    spitline("\tload passed");
}

// Define a test function for Store
void testStore() {
    UVSimulator simulator;
    int operand = 20;
    int accumulatorValue = 50;

    simulator.setAccumulator(accumulatorValue);

    // Create a Store object and call execute method
    Store store;
    store.execute(simulator, operand);

    // Assert or verify the expected behavior
    // For example, you might check if the memory location was set correctly
    assert(simulator.getMemory(operand) == accumulatorValue);
    spitline("\tstore passed");
}
// END OF LOAD/STORE TESTS

int main() {
    spitline("Arithmetic Tests:");
    testAdd();
    testSubtract();
    testMultiply();
    testDivide();
    testDivideByZero();

    spitline("Control Tests:");
    testBranch();
    testBranchNeg();
    testBranchZero();
    testHalt();

    spitline("I/O Tests:");
    test_READ();
    test_WRITE();

    spitline("Load/Store Tests:");
    testLoad();
    testStore();

    spitline("END OF TESTS");
}