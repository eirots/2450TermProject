#include <cassert>
#include <chrono>
#include <climits>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

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
// g++ -std=c++20 testsuite.cpp ../../control/*.cpp ../../arithmetic/*.cpp
// ../../io/*.cpp ../../loadstore/*.cpp ../../uvsimulator.cpp  -o ../unit_tests\


//  BELOW FUNCTIONALITY WILL BE ADDED NEXT MILESTONE                                             \
//Coverage tested using Gcov Viewer from VS Studio's extension library.                          \
//                                                                                               \
//  Steps to test coverage:                                                                      \
//    1) Compile your code with gcc/g++ (version >= 9) with --coverage and without optimizations.\
//    2) Run your program or tests.                                                              \
//    3) Open a source file in vscode and use ctrl+shift+P to run the GcovViewer: Show command.  \

// boilerplate test functionality and writing to files created by Andrew Storie

// common debug macro included below
#define ASSERT(condition)                                                      \
  {                                                                            \
    if (!(condition)) {                                                        \
      std::cerr << "ASSERT FAILED: " << #condition << " @ " << __FILE__        \
                << " (" << __LINE__ << ")" << std::endl;                       \
    }                                                                          \
  }

// global variable declaration for use later
const std::string METRIC_FILE =
    "test_reports/metrics.txt"; // constant for metric file location
const std::string TEST_RESULT =
    "test_reports/results.txt"; // constant for results file location

// setting up strings for concationation to file
std::string metricsb = "";
std::string outputsb = "";

// small function to print out without using a namespace
void spitline(std::string lineToPrint) {
  std::cout << lineToPrint << std::endl;
  outputsb += lineToPrint + "\n";
}

void updateMetric(std::string str) { metricsb += str + "\n"; }

std::string getTime() {
  auto end = std::chrono::system_clock::now();
  std::time_t returnTime = std::chrono::system_clock::to_time_t(end);

  // Convert time_t to std::tm
  std::tm tmTime = *std::localtime(&returnTime);

  // Create a string stream to format the time
  std::ostringstream oss;
  oss << std::put_time(&tmTime, "%Y-%m-%d %H:%M:%S");

  return oss.str();
}
// used for writing metric data to files
void writeToFile(std::string path, std::string data) {
  // char cwd[1024];
  // std::cout << getcwd(cwd, sizeof(cwd)) << std::endl;
  std::ofstream outputFile(path, std::ios::app); // append mode
  if (outputFile.is_open()) {
    outputFile << data << std::endl;
    outputFile << "Finished at: " << getTime() << std::endl << std::endl;
  } else {
    std::cerr << "Unable to open file located at: " + path << std::endl;
  }
}
// START OF UVSIM TESTS

// tests accessing first and last memory locations
void testMemoryAccessBoundaries() {
  UVSimulator sim;
  sim.setMemory(0, 123);
  sim.setMemory(99, 456);

  assert(sim.getMemory(0) == 123);
  assert(sim.getMemory(99) == 456);
  assert(sim.getMemory(-1) == 0);
  assert(sim.getMemory(100) == 0);

  spitline("\tmemory access boundaries passed");
}

// test setting memory at boundaries
void testMemorySetBoundaries() {
  UVSimulator sim;

  sim.setMemory(0, 1);
  sim.setMemory(99, 100);
  sim.setMemory(-1, 200);
  sim.setMemory(100, 300);

  assert(sim.getMemory(0) == 1);
  assert(sim.getMemory(99) == 100);
  assert(sim.getMemory(-1) == 200);
  assert(sim.getMemory(100) == 0);

  spitline("\tmemory set boundaries passed");
}

// START OF ARITHMETIC TESTS
// Written by Andrew Gallagher and Andrew Storie
// verifies that adding works

void testAddOverflow() {
  UVSimulator sim;
  sim.setAccumulator(INT_MAX);
  sim.setMemory(0, 1);

  Add adder;
  adder.execute(sim, 0);

  spitline("\tadd overflow passed");
}

void testSubtractUnderflow() {
  UVSimulator sim;
  sim.setAccumulator(INT_MIN);
  sim.setMemory(0, 1);

  Subtract sub;
  sub.execute(sim, 0);

  spitline("\tsubtract underflow passed");
}

void testDivideByZeroExtended() {
  UVSimulator sim;

  sim.setAccumulator(20);
  sim.setMemory(0, 0);
  Divide div;

  try {
    div.execute(sim, 0);
    assert(false); // should not hit this
  } catch (const char *mg) {
    assert(std::string(mg) == "Divide by zero not allowed");
  }

  sim.setAccumulator(-20);
  try {
    div.execute(sim, 0);
    assert(false); // should not hit this
  } catch (const char *mg) {
    assert(std::string(mg) == "Divide by zero not allowed");
  }

  spitline("\textended divide by zero passed");
}

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

// verifies that adding works at a specific location
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

// ensures that base subtraction functionality works correctly
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
// verifies that base multiplication functionaltiy works correctly
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
// ensures functionality of the division operator
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
// ensures dividing by zero throws an exception
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
// Written by Juan Marin

// ensures base branch functionality branches to the correct location by
// updating the PC
void testBranch() {
  UVSimulator simulator;
  int operand = 5;

  Branch branch;
  branch.execute(simulator, operand);

  assert(simulator.getPC() == operand);
  spitline("\tbranch passed");
}
// ensures UVSim branches correctly when branching on a negaive value in
// accumulator
void testBranchNeg() {
  UVSimulator simulator;
  int operand = 5;
  simulator.setAccumulator(-1);

  BranchNeg branchNeg;
  branchNeg.execute(simulator, operand);

  assert(simulator.getPC() == operand);
  spitline("\tbranch negative passed");
}
// ensures UVSim branches correctly when using branch on zero command and
// accumulator is zero
void testBranchZero() {
  UVSimulator simulator;
  int operand = 5;
  simulator.setAccumulator(0);

  BranchZero branchZero;
  branchZero.execute(simulator, operand);

  assert(simulator.getPC() == operand);
  spitline("\tbranch zero passed");
}
// ensures halting stops UVSim
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
// Written by Ryan Jones
// ensures loading to a specific location works correctly
void testLoad1() {
  UVSimulator simulator;
  int operand = 10;

  Load load;
  load.execute(simulator, operand);

  assert(simulator.getAccumulator() == simulator.getMemory(operand));
  spitline("\tload 1 passed");
}
// ensures loading from a specific location after adding to a different one
// produces different results
void testLoad2() {
  UVSimulator sim;
  int operand = 0;

  sim.setMemory(0, 5);
  Load load;
  load.execute(sim, operand);

  assert(sim.getAccumulator() == sim.getMemory(0));
  spitline("\tload 2 passed");
}
// ensures storing to a specific place in memory works correctly
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

// BATCH RUN TEST FUNCTIONS
// Written by Andrew Storie

void runMemoryTests() {
  spitline("Memory Boundary Tests:");

  auto start = std::chrono::high_resolution_clock::now();
  testMemoryAccessBoundaries();
  testMemorySetBoundaries();

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = duration_cast<std::chrono::microseconds>(stop - start);

  std::string spit =
      "\t\tTime to run memory tests: " + std::to_string(duration.count()) +
      " microseconds";
  updateMetric(spit);
  spitline(spit);
}

void runArith() {
  spitline("Arithmetic Tests:");

  auto start = std::chrono::high_resolution_clock::now();
  testAdd1();
  testAdd2();
  testSubtract1();
  testSubtract2();
  testMultiply1();
  testMultiply2();
  testDivide();
  testDivideByZero();
  testDivideByZeroExtended();
  testAddOverflow();
  testSubtractUnderflow();

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = duration_cast<std::chrono::microseconds>(stop - start);

  std::string spit =
      "\t\tTime to run arithmetic tests: " + std::to_string(duration.count()) +
      " microseconds";

  updateMetric(spit);
  spitline(spit);
}
void runControl() {

  spitline("Control Tests:");

  auto start = std::chrono::high_resolution_clock::now();
  testBranch();
  testBranchNeg();
  testBranchZero();
  testHalt();
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = duration_cast<std::chrono::microseconds>(stop - start);

  std::string spit =
      "\t\tTime to run control tests: " + std::to_string(duration.count()) +
      " microseconds";

  updateMetric(spit);
  spitline(spit);
}
void runIO() {
  spitline("I/O Tests:");

  auto start = std::chrono::high_resolution_clock::now();

  test_READ();
  test_WRITE();

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = duration_cast<std::chrono::microseconds>(stop - start);

  std::string spit =
      "\t\tTime to run IO tests: " + std::to_string(duration.count()) +
      " microseconds";

  updateMetric(spit);
  spitline(spit);
}
void runLoadStore() {
  spitline("Load/Store Tests:");

  auto start = std::chrono::high_resolution_clock::now();
  testLoad1();
  testLoad2();
  testStore();

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = duration_cast<std::chrono::microseconds>(stop - start);

  std::string spit =
      "\t\tTime to run LoadStore tests: " + std::to_string(duration.count()) +
      " microseconds";

  updateMetric(spit);
  spitline(spit);
}
// END OF BATCH RUN TEST FUNCTIONS

int main() {
  spitline("RUNNING UNIT TESTS:");

  runArith();
  runControl();
  runIO();
  runLoadStore();
  // runMemoryTests();

  spitline("END OF TESTS");

  writeToFile(METRIC_FILE, metricsb);
  writeToFile(TEST_RESULT, outputsb);
}