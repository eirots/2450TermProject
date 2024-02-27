#include <cassert>
#include "multiply.h"
#include <iostream>

/* 
 * Test case for the Multiply class
 * This function creates an instance of the Multiply class, multiplies two numbers, and checks the result.
 * It also checks that the original values of the numbers have not changed.
 */

void testMultiply()
{
  float memory = 5.0f;
  float accum = 2.5f;
  Multiply multiplier;

  float result = multiplier.multiply(memory, accum);

  assert(result == 12.5f);
  assert(memory == 5.0f);
}


/*
 * The main function.
 * This function calls the testMultiply function and prints a success message if the test passes.
 * Returns 0 if the program runs successfully.
 */
int main()
{
  testMultiply();

  std::cout << "Test passed!" << std::endl;
  return 0;
}
