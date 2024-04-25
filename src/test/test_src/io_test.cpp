#include <iostream>

#include "../../io/read.h"
#include "../../io/write.h"
#include "../../uvsimulator.h"

extern int memory[];

// Written by Nate Young

void test_READ() {
  UVSimulator simulator; // Create an instance of UVSimulator

  // Load the program into memory
  std::vector<int> program = {10,
                              0}; // Assuming the program consists of a single
                                  // READ instruction at memory location 0
  simulator.loadProgram(program);

  std::cout << "Testing READ function:" << std::endl;

  // Execute the program
  simulator.loadProgram(program);

  // Verify if the memory location has been updated correctly
  if (simulator.getMemory(0) != 10) {
    std::cout << "\tRead test failed" << std::endl;
  } else {
    std::cout << "\tRead test passed!" << std::endl;
  }
}

void test_WRITE() {
  UVSimulator sim;
  sim.setAccumulator(20);

  Write write;
  write.execute(sim, 5);

  if (sim.getMemory(5) != 20) {
    std::cout << "\twrite failed!" << std::endl;
  } else {
    std::cout << "\tWrite passed" << std::endl;
  }
}
