#include <cassert>
#include <iostream>
#include "subtract.h"
#include "../uvsimulator.h"

/* 
 * Test case for the Subtract class method
 * This function creates an instance of the Subtract class, sets the accumulator and a memory location, 
   and checks if the execute method correctly subtracts the value at the memory location from the accumulator.
 */
void testSubtract()
{
  UVSimulator simulator;
  simulator.setAccumulator(10);
  simulator.setMemory(0, 5);
  int operand = 0;

  Subtract subtract;
  subtract.execute(simulator, operand);

  assert(simulator.getAccumulator() == 5);
}


/*
 * The main function.
 * This function calls the testSubtract function and prints a success message if the test passes.
 * Returns 0 if the program runs successfully.
 */
int main()
{
  testSubtract();

  std::cout << "Test passed!" << std::endl;
  return 0;
}
