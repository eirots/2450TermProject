#include <cassert>
#include <iostream>
#include "subtract.h"
#include "../uvsimulator.h"

// Test case for the Subtract class method
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

int main()
{
  testSubtract();

  std::cout << "Test passed!" << std::endl;
  return 0;
}
