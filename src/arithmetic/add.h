class UVSimulator;  // forward declaration to avoid cyclical declarations

#include "../uvsimulator.h"
#ifndef ADD_H
#define ADD_H

class Add {
   public:
    Add();
    void execute(UVSimulator& simulator, int operand);
};
#endif  // ADD_H
