class UVSimulator;

#ifndef ARITHMETIC_H
#define ARITHMETIC_H

/*Purely virtual class for ensuring that other Arithmetic classes derive from this. */
class Arithmetic {
   public:
    virtual void execute(UVSimulator& sim, int operand) = 0;  // ensuring that there is no base functionalty, purely virtual function
};

#endif  // ARITHMETIC_H