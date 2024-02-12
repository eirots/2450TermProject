#include <cassert>
#include <iostream>
#include "branchzero.h"

// Test case for the BranchZero class
void testBranchZero()
{
  UVSimulator simulator;
  int operand = 5;
  simulator.setAccumulator(0);

  BranchZero branchZero;
  branchZero.execute(simulator, operand);

  assert(simulator.getPC() == operand);
}

int main()
{
  testBranchZero();

  std::cout << "Test passed!" << std::endl;
  return 0;
}
