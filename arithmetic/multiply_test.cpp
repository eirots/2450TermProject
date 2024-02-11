#include <cassert>
#include "multiply.h"
#include <iostream>

// Test case for the Multiply class
void testMultiply()
{
  float memory = 5.0f;
  float accum = 2.5f;
  Multiply multiplier;

  float result = multiplier.multiply(memory, accum);

  assert(result == 12.5f);
  assert(memory == 5.0f);
}

int main()
{
  testMultiply();

  std::cout << "Test passed!" << std::endl;
  return 0;
}
