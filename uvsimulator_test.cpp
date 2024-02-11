#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include "uvsimulator.h"
#include "loadstore/load.h"
#include "loadstore/store.h"
#include "arithmetic/subtract.h"

// Test case for loading a program into memory
void testLoadProgram()
{
  UVSimulator simulator;
  std::vector<int> program = {1007, 2008, 3110, 4300};

  simulator.loadProgram(program);

  assert(simulator.getMemory(0) == 1007);
  assert(simulator.getMemory(1) == 2008);
  assert(simulator.getMemory(2) == 3110);
  assert(simulator.getMemory(3) == 4300);
}

// Test case for building a program
void testBuildProgram()
{
  UVSimulator simulator;

  std::istringstream input("1007\n2008\n3110\ndone\n");
  std::cin.rdbuf(input.rdbuf());

  std::vector<int> program = simulator.buildProgram();

  assert(program.size() == 3);
  assert(program[0] == 1007);
  assert(program[1] == 2008);
  assert(program[2] == 3110);
}

// Test case for executing a program
void testExecuteProgram()
{
  UVSimulator simulator;
  std::vector<int> program = {2002, 2101, 3110, 4300};

  simulator.loadProgram(program);

  simulator.executeProgram();

  assert(simulator.getAccumulator() == 2); // 2 - 1 = 1
  assert(simulator.getMemory(1) == 1);
}

int main()
{
  testLoadProgram();
  testBuildProgram();
  testExecuteProgram();

  std::cout << "All tests passed!" << std::endl;
  return 0;
}