#ifndef halt_h
#define halt_h
#include "../uvsimulator.h"

class UVSimulator;  // forward declaration to avoid cyclical declarations

class Halt {
   public:
    void HALT();
    void execute(UVSimulator &simulator);
};
#endif  // halt_h