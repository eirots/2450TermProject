#include "uvsimulator.h"

class uvsimulator;  // forward declaration to avoid cyclical declarations

class Halt {
   public:
    void HALT();
    void execute(UVSimulator &simulator);
};