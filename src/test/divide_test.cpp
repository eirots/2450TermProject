#include <cassert>
#include <iostream>
#include "divide.h"

/* 
 * Test case for the Divide class
 * This function tests the Divide class by creating an instance of the class, performing a division operation, 
  and asserting that the result is as expected.
 */
void testDivide()
{
  int dividend = 20;
  int divisor = 5;
  Divide divider;

  int result = divider.divide(dividend, divisor);

  assert(result == 4);
  assert(dividend == 20);
}

/* 
 * Test case for handling division by zero
 * This function tests the Divide class by creating an instance of the class, attempting to perform a division by zero operation.
 */
void testDivideByZero()
{
  int dividend = 20;
  int divisor = 0;
  Divide divider;

  try
  {
    divider.divide(dividend, divisor);
    assert(false);
  }
  catch (const char *error)
  {
    assert(std::string(error) == "Divide by zero not allowed");
  }
  assert(dividend == 20);
}

/*
 * Main function.
 * This function calls the testDivide and testDivideByZero functions and prints "Tests passed!" to the console if nothing fails.
 * Returns 0 if the program runs successfully.
 */
int main()
{
  testDivide();
  testDivideByZero();

  std::cout << "Tests passed!" << std::endl;
  return 0;
}
