#include <cassert>
#include <iostream>
#include "branchzero.h"

/* 
 * Test case for the BranchZero class
 * The function creates an instance of the BranchZero class, sets the accumulator of the program instance to zero, 
   invokes the execute method with the UVSimulator instance and an operand, and then verifies that the program counter of the UVSimulator instance is updated as expected.
 */
void testBranchZero()
{
  UVSimulator simulator;
  int operand = 5;
  simulator.setAccumulator(0);

  BranchZero branchZero;
  branchZero.execute(simulator, operand);

  assert(simulator.getPC() == operand);
}

/*
 * The main function.
 * This function invokes the testBranchZero function and prints "Test passed!" to the console if no assertions failed.
 * Returns 0 if the program executes successfully.
 */

int main()
{
  testBranchZero();

  std::cout << "Test passed!" << std::endl;
  return 0;
}
