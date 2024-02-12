#include <cassert>
#include <iostream>
#include "divide.h"

// Test case for the Divide class
void testDivide()
{
  int dividend = 20;
  int divisor = 5;
  Divide divider;

  int result = divider.divide(dividend, divisor);

  assert(result == 4);
  assert(dividend == 20);
}

// Test case for handling division by zero
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

int main()
{
  testDivide();
  testDivideByZero();

  std::cout << "Tests passed!" << std::endl;
  return 0;
}
