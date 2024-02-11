#include "header.h"

Multiply::Multiply() { }

float Multiply::multiply(float &memory, float accum) {
  float product;
  product = memory * accum;
  return product;
}
