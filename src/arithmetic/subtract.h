class UVSimulator;  // forward declaration to avoid cyclical declarations

#ifndef SUBTRACT_H
#define SUBTRACT_H

class Subtract {
   public:
    Subtract();
    static void execute(UVSimulator& simulator, int operand);
};

#endif  // SUBTRACT_H