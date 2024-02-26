#include <cassert>
#include <iostream>
#include "branch.h"

/* 
 * Test case for the Branch class
 * This function tests the Branch class by creating an instance of the class, calling the execute method with a 
   UVSimulator instance and an operand, and asserting that the program counter of the instance is as expected.
 */
void testBranch()
{
  UVSimulator simulator;
  int operand = 5;

  Branch branch;
  branch.execute(simulator, operand);

  assert(simulator.getPC() == operand);
}


/*
 * Main function.
 * This function calls the testBranch function and prints "Test passed!" to the console if no assertions failed.
 * return 0 if the program runs successfully.
 */
int main()
{
  testBranch();

  std::cout << "Test passed!" << std::endl;
  return 0;
}
