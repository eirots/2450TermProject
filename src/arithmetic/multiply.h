class UVSimulator;  // forward declaration to avoid cyclical declarations

#ifndef MULTIPLY_H
#define MULTIPLY_H

class Multiply {
   public:
    Multiply();

    void execute(UVSimulator& sim, int operand);
};
#endif  // MULTIPLY_H