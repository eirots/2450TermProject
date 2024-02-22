class UVSimulator;  // forward declaration to avoid cyclical declarations

#ifndef DIVIDE_H
#define DIVIDE_H


/*
 * class Divide
 * A class to handle the divide operation in the UVSimulator.
 *
 * This class provides the functionality to divide the value in the accumulator of the UVSimulator 
   by a value from a specific memory location.
 */
class Divide {
   public:
    Divide();
    void execute(UVSimulator& sim, int divisor);
};
#endif  // DIVIDE_H
