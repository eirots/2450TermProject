#include <cassert>
#include <iostream>
#include "branchneg.h"

/* 
  * Test case for the BranchNeg class
  * This function tests the BranchNeg class by creating an instance of the class, setting the accumulator of an instance to a negative value, 
    calling the execute method with the instance and an operand, and asserting that the program counter of the UVSimulator instance is as expected.
 */
void testBranchNeg()
{
  UVSimulator simulator;
  int operand = 5;
  simulator.setAccumulator(-1);

  BranchNeg branchNeg;
  branchNeg.execute(simulator, operand);

  assert(simulator.getPC() == operand);
}


/*
 * Main function.
 * This function calls the testBranchNeg function and prints "Test passed!" to the console if no assertions failed.
 * return 0 if the program runs successfully.
 */
int main()
{
  testBranchNeg();

  std::cout << "Test passed!" << std::endl;
  return 0;
}
