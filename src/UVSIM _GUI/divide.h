class UVSimulator;  // forward declaration to avoid cyclical declarations
#include "arithmetic.h"
#ifndef DIVIDE_H
#define DIVIDE_H

/*
 * class Divide
 * A class to handle the divide operation in the UVSimulator.
 *
 * This class provides the functionality to divide the value in the accumulator of the UVSimulator
   by a value from a specific memory location.
 */
class Divide : public Arithmetic {
   public:
    Divide();
    void execute(UVSimulator& sim, int divisor) override;
};
#endif  // DIVIDE_H
