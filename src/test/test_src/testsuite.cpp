#include <cassert>
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
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


//BELOW FUNCTIONALITY WILL BE ADDED NEXT MILESTONE                                               \
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

std::time_t &getTime() {
  auto time = std::chrono::system_clock::now();

  std::time_t returnTime = std::chrono::system_clock::to_time_t(time);
  return returnTime;
}
// used for writing metric data to files
void writeToFile(std::string path, std::string data) {
  char cwd[1024];
  std::cout << getcwd(cwd, sizeof(cwd)) << std::endl;
  std::ofstream outputFile(path, std::ios::app); // append mode
  if (outputFile.is_open()) {
    outputFile << data << std::endl;
    outputFile << "Finished at: " << std::ctime(&getTime()) << std::endl
               << std::endl;
  } else {
    std::cerr << "Unable to open file located at: " + path << std::endl;
  }
}

// START OF ARITHMETIC TESTS
// Written by Andrew Gallagher and Andrew Storie
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
// Written by Juan Marin
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
// Written by Ryan Jones
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

int main() {
  spitline("RUNNING UNIT TESTS:");

  runArith();
  runControl();
  runIO();
  runLoadStore();

  spitline("END OF TESTS");

  writeToFile(METRIC_FILE, metricsb);
  writeToFile(TEST_RESULT, outputsb);
}