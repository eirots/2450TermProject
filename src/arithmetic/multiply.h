#ifndef MULTIPLY_H
#define MULTIPLY_H
#include "../uvsimulator.h"
class Multiply {
   public:
    Multiply();

    void execute(UVSimulator& sim, int operand);
};
#endif  // MULTIPLY_H