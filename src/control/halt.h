#ifndef halt_h
#define halt_h
#include "..\uvsimulator.h"

class UVSimulator;  // forward declaration to avoid cyclical declarations


/*
 * class Halt
 * brief A class to handle the halt operation in the UVSimulator.
 *
 * This class provides the functionality to halt the execution of the program.
 */

class Halt {
   public:
    void HALT();
    void execute(UVSimulator &simulator);
};
#endif  // halt_h
