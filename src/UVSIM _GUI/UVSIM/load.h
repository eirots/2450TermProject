#ifndef LOAD_H
#define LOAD_H

class UVSimulator;
#include "loadstore.h"

/*
 * class Load
 * A class to handle the load operation in the program.
 *
 * This class provides the functionality to load a value from a specific memory location into the accumulator of the program.
 */
class Load : public LoadStore {
   public:
    void execute(UVSimulator& simulator, int operand) override;
};

#endif  // LOAD_H
