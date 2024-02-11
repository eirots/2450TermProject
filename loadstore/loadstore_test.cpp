#include <cassert>
#include "load.h"
#include "store.h"
#include "../uvsimulator.h" // Include any other necessary dependencies
#include <iostream>

// Define a test function for Load
void testLoad()
{
  UVSimulator simulator;
  int operand = 10;

  Load load;
  load.execute(simulator, operand);

  assert(simulator.getAccumulator() == simulator.getMemory(operand));
}

// Define a test function for Store
void testStore()
{
  UVSimulator simulator;
  int operand = 20;
  int accumulatorValue = 50;

  simulator.setAccumulator(accumulatorValue);

  // Create a Store object and call execute method
  Store store;
  store.execute(simulator, operand);

  // Assert or verify the expected behavior
  // For example, you might check if the memory location was set correctly
  assert(simulator.getMemory(operand) == accumulatorValue);
}

// Main function to run the tests
int main()
{
  // Run the tests
  testLoad();
  testStore();

  // If the assertions pass, the tests succeed
  std::cout << "All tests passed!" << std::endl;
  return 0;
}
