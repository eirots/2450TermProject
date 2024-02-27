#include <cassert>
#include <iostream>
#include "halt.h"

/* 
 * Test case for the Halt class
 * This function tests the Halt class by creating an instance of the class, setting the program counter of an 
   instance to a specific value, calling the execute method with the instance, and asserting that the program counter is set to the memory size after the halt operation.
 */
 
void testHalt()
{
  UVSimulator simulator;
  int memSize = 100;
  simulator.setPC(5);

  Halt halt;
  halt.execute(simulator);

  assert(simulator.getPC() == memSize);
}

/*
 * Main function.
 * This function calls the testHalt function and prints "Test passed!" to the console if no assertions failed.
 * Returns 0 if the program runs successfully.
 */
int main()
{
  testHalt();

  std::cout << "Test passed!" << std::endl;
  return 0;
}
