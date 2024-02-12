#ifndef SUBTRACT_H
#define SUBTRACT_H
#include "../uvsimulator.h"

class UVSimulator;

class Subtract {
   public:
    Subtract();
    static void execute(UVSimulator& simulator, int operand);
};

#endif  // SUBTRACT_H