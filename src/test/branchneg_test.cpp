#include <cassert>
#include <iostream>
#include "branchneg.h"

// Test case for the BranchNeg class
void testBranchNeg()
{
  UVSimulator simulator;
  int operand = 5;
  simulator.setAccumulator(-1);

  BranchNeg branchNeg;
  branchNeg.execute(simulator, operand);

  assert(simulator.getPC() == operand);
}

int main()
{
  testBranchNeg();

  std::cout << "Test passed!" << std::endl;
  return 0;
}
