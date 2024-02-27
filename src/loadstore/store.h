#ifndef STORE_H
#define STORE_H

class UVSimulator;
#include "loadstore.h"

/**
 * class Store
 * A class to handle the store operation in the UVSimulator.
 *
 * This class provides the functionality to store a value from the accumulator of the UVSimulator into a specific memory location.
 */

class Store : public LoadStore {
   public:
    void execute(UVSimulator& simulator, int operand) override;
};

#endif  // STORE_H
