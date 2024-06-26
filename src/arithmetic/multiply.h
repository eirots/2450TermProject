class UVSimulator;  // forward declaration to avoid cyclical declarations
#include "arithmetic.h"
#ifndef MULTIPLY_H
#define MULTIPLY_H

/*
 * class Multiply
 * A class to handle the multiply operation in the UVSimulator.
 * This class provides the functionality to multiply a value from a specific memory location
   with the value in the accumulator.
 */

class Multiply : public Arithmetic {
   public:
    Multiply();

    void execute(UVSimulator& sim, int operand) override;
};
#endif  // MULTIPLY_H
