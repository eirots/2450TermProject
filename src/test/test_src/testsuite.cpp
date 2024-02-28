#include <cassert>
#include <iostream>
#include <string>

#include "../../arithmetic/add.h"
#include "../../arithmetic/divide.h"
#include "../../arithmetic/multiply.h"
#include "../../arithmetic/subtract.h"
#include "../../control/branch.h"
#include "../../control/branchneg.h"
#include "../../control/branchzero.h"
#include "../../control/halt.h"
#include "../../io/read.h"
#include "../../io/write.h"
#include "../../loadstore/load.h"
#include "../../loadstore/store.h"
#include "../../uvsimulator.h"
#include "io_test.cpp"

// COMPILE COMMAND FOR THIS FILE:
// g++ -std=c++11 testsuite.cpp ../../control/*.cpp ../../arithmetic/*.cpp
// ../../io/*.cpp ../../loadstore/*.cpp ../../uvsimulator.cpp  -o ../unit_tests\


//Coverage tested using Gcov Viewer from VS Studio's extension library.                          \
//                                                                                               \
//  Steps to test coverage:                                                                      \
//    1) Compile your code with gcc/g++ (version >= 9) with --coverage and without optimizations.\
//    2) Run your program or tests.                                                              \
//    3) Open a source file in vscode and use ctrl+shift+P to run the GcovViewer: Show command.  \


// common debug macro included below
#define ASSERT(condition)                                                      \
  {                                                                            \
    if (!(condition)) {                                                        \
      std::cerr << "ASSERT FAILED: " << #condition << " @ " << __FILE__        \
                << " (" << __LINE__ << ")" << std::endl;                       \
    }                                                                          \
  }

static std::string METRIC_FILE_LOC = "../test_reports/metrics.txt";
static std::string TEST_RESULT_LOC = "../test_reports/results.txt";

// used for knowing if a test passed
void spitline(std::string lineToPrint) {
  std::cout << lineToPrint << std::endl;
}

// START OF ARITHMETIC TESTS
void testAdd1() {
  Add adder;
  UVSimulator simulator;
  int operand = 0;

  simulator.setAccumulator(5);
  simulator.setMemory(0, 10);
  // std::cout << simulator.getAccumulator() << "accum value " << std::endl;

  adder.execute(simulator, operand);
  // std::cout << simulator.getAccumulator() << "accum value " << std::endl;
  assert(simulator.getAccumulator() == 15);
  spitline("\tadd1 passed");
}

/*
Verifies that adding works at specific locations.
*/
void testAdd2() {
  Add adder;
  UVSimulator simulator;
  int operand = 0;

  simulator.setAccumulator(5);
  simulator.setMemory(1, 10);

  adder.execute(simulator, operand);
  // std::cout << simulator.getAccumulator() << std::endl;

  assert(simulator.getAccumulator() == 5);
  spitline("\tadd2 passed");
}

void testSubtract1() {
  UVSimulator simulator;
  simulator.setAccumulator(10);
  simulator.setMemory(0, 5);
  int operand = 0;

  Subtract subtract;
  subtract.execute(simulator, operand);

  assert(simulator.getAccumulator() == 5);
  spitline("\tsubtract1 passed");
}

// verifies that subtracting works at an exact location
void testSubtract2() {
  UVSimulator simulator;
  simulator.setAccumulator(5);
  simulator.setMemory(1, 5);
  int operand = 0;

  Subtract subtract;
  subtract.execute(simulator, operand);

  assert(simulator.getAccumulator() == 5);
  spitline("\tsubtract2 passed");
}

void testMultiply1() {
  UVSimulator sim;
  Multiply multiplier;

  sim.setAccumulator(5);
  sim.setMemory(0, 5);
  int operand = 0;
  // std::cout << sim.getAccumulator() << "accum value " << std::endl;
  multiplier.execute(sim, operand);

  assert(sim.getAccumulator() == 25);

  spitline("\tmultiply1 passed");
}

// verifies that multiplication works at an exact location
void testMultiply2() {
  UVSimulator sim;
  Multiply multiplier;

  sim.setAccumulator(5);
  sim.setMemory(0, 5);
  int operand = 1;
  // std::cout << sim.getAccumulator() << "accum value " << std::endl;
  multiplier.execute(sim, operand);

  assert(sim.getAccumulator() == 0);

  spitline("\tmultiply2 passed");
}
void testDivide() {
  UVSimulator sim;
  Divide div;

  sim.setAccumulator(20);
  sim.setMemory(0, 5);
  int operand = 0;

  div.execute(sim, operand);
  // std::cout << sim.getAccumulator() << "accum value " << std::endl;
  assert(sim.getAccumulator() == 4);
  spitline("\tdivide passed");
}
void testDivideByZero() {
  UVSimulator sim;
  Divide divider;

  sim.setAccumulator(20);
  sim.setMemory(0, 0);

  int operand = 0;

  try {
    divider.execute(sim, operand);
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
void testLoad1() {
  UVSimulator simulator;
  int operand = 10;

  Load load;
  load.execute(simulator, operand);

  assert(simulator.getAccumulator() == simulator.getMemory(operand));
  spitline("\tload 1 passed");
}
void testLoad2() {
  UVSimulator sim;
  int operand = 0;

  sim.setMemory(0, 5);
  Load load;
  load.execute(sim, operand);

  assert(sim.getAccumulator() == sim.getMemory(0));
  spitline("\tload 2 passed");
}

// Define a test function for Store
void testStore() {
  UVSimulator simulator;
  int operand = 20;
  int accumulatorValue = 50;

  simulator.setAccumulator(accumulatorValue);

  Store store;
  store.execute(simulator, operand);

  assert(simulator.getMemory(operand) == accumulatorValue);
  spitline("\tstore passed");
}
// END OF LOAD/STORE TESTS

int main() {
  spitline("Arithmetic Tests:");
  testAdd1();
  testAdd2();
  testSubtract1();
  testSubtract2();
  testMultiply1();
  testMultiply2();
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
  testLoad1();
  testLoad2();
  testStore();

  spitline("END OF TESTS");
}