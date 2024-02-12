#include <cassert>
#include <iostream>
#include "branch.h"

// Test case for the Branch class
void testBranch()
{
  UVSimulator simulator;
  int operand = 5;

  Branch branch;
  branch.execute(simulator, operand);

  assert(simulator.getPC() == operand);
}

int main()
{
  testBranch();

  std::cout << "Test passed!" << std::endl;
  return 0;
}
