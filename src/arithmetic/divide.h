#ifndef DIVIDE_H
#define DIVIDE_H
#include "../uvsimulator.h"

class Divide {
   public:
    Divide();
    void execute(UVSimulator& sim, int divisor);
};
#endif  // DIVIDE_H