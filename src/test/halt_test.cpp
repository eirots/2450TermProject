#include <cassert>
#include <iostream>
#include "halt.h"

// Test case for the Halt class
void testHalt()
{
  UVSimulator simulator;
  int memSize = 100;
  simulator.setPC(5);

  Halt halt;
  halt.execute(simulator);

  assert(simulator.getPC() == memSize);
}

int main()
{
  testHalt();

  std::cout << "Test passed!" << std::endl;
  return 0;
}
