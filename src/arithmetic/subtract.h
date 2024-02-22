class UVSimulator;  // forward declaration to avoid cyclical declarations

#ifndef SUBTRACT_H
#define SUBTRACT_H


/*
 * class Subtract
 * A class to handle the subtract operation in the UVSimulator.
 * This class provides the functionality to subtract a value from a specific memory location 
   from the value in the accumulator.
 */

class Subtract {
   public:
    Subtract();
    static void execute(UVSimulator& simulator, int operand);
};

#endif  // SUBTRACT_H
